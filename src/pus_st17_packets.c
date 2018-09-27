/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pus_st17_packets.h"
#ifdef PUS_CONFIGURE_ST17_ENABLED


pusError_t pus_tc_17_1_createConnectionTestRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
{

	if (NULL == outTc)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_clearError();
		pus_initTcPacket(outTc);

		// Source information
		pus_setApid(outTc, apid);
		pus_setSequenceCount(outTc, sequenceCount);

		// Data length
		pus_setPacketDataLength(outTc, sizeof(pusPacketData_t));

		// Service identification
		pus_setTcService(outTc, pus_ST17_test);
		pus_setTcSubtype(outTc, pus_TC_17_1_connectionTest);
		pus_setTcSource(outTc, apid);

		pus_setTcDataKind(outTc, pus_TC_DATA_NONE);
		outTc->data.u.tcData.data.u.st_0_0 = 0;

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusError_t pus_tm_17_2_createConnectionTestReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination)
{
	if (NULL == outTm )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_clearError();
		pus_initTmPacket(outTm);

		// Source information
		pus_setApid(outTm, apid);
		pus_setSequenceCount(outTm, sequenceCount);

		// Data length
		pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

		// Service identification
		pus_setTmService(outTm, pus_ST17_test);
		pus_setTmSubtype(outTm, pus_TM_17_2_connectionTest);

		pus_setTmDestination(outTm, destination);
		pus_setTmDataKind(outTm, pus_TM_DATA_NONE);
		outTm->data.u.tmData.data.u.st_0_0 = 0;

		// Timestamp
		pus_setTmPacketTimeNow(outTm);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusError_t pus_st17_createTestResponse(pusPacket_t* outTm, pusApidInfo_t* apid, const pusPacket_t* inTc)
{
	if( NULL == outTm || NULL == apid || NULL == inTc )
	{
		return PUS_ERROR_NULLPTR;
	}
	else
	{
		if( PUS_NO_ERROR != PUS_EXPECT_ST17TC( inTc, pusSubtype_NONE))
		{
			return PUS_GET_ERROR();
		}
		else
		{
			pus_tm_17_2_createConnectionTestReport(outTm, apid->apid, pus_getNextPacketCount(apid), inTc->apid);
			return PUS_NO_ERROR;
		}
	}
}


pusError_t pus_expectSt17Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTcHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTcService(packet);
		pusSubservice_t subtype = pus_getTcSubtype(packet);

		if (service != pus_ST17_test)
		{
			pus_setError(PUS_ERROR_TC_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TC_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[17]
			if (subtype != pus_TC_17_1_connectionTest)
			{
				pus_setError(PUS_ERROR_TC_SUBTYPE, function, (pusErrorData_t){.integer=subtype});
				return PUS_ERROR_TC_SUBTYPE;
			}
		}
		else
		{
			// Check that subtype is as expected
			if (subtype != expectedSubtype)
			{
				pus_setError(PUS_ERROR_TC_SUBTYPE, function, (pusErrorData_t){.integer=subtype});
				return PUS_ERROR_TC_SUBTYPE;
			}
		}

		return PUS_NO_ERROR;
	}
	else
	{
		return expectResult;
	}
}

pusError_t pus_expectSt17Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTmHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTmService(packet);
		pusSubservice_t subtype = pus_getTmSubtype(packet);

		if (service != pus_ST17_test)
		{
			pus_setError(PUS_ERROR_TM_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TM_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[17]
			if (subtype != pus_TM_17_2_connectionTest)
			{
				pus_setError(PUS_ERROR_TM_SUBTYPE, function, (pusErrorData_t){.integer=subtype});
				return PUS_ERROR_TM_SUBTYPE;
			}
		}
		else
		{
			// Check that subtype is as expected
			if (subtype != expectedSubtype)
			{
				pus_setError(PUS_ERROR_TM_SUBTYPE, function, (pusErrorData_t){.integer=subtype});
				return PUS_ERROR_TM_SUBTYPE;
			}
		}

		/*pusPacketDataKind_t kind = pus_getTmDataKind(packet);
		if (kind != pus_TM_DATA_ST_5_X)
		{
			pus_setError(PUS_ERROR_TM_KIND, function, (pusErrorData_t){.integer=kind});
			return PUS_ERROR_TM_KIND;
		}*/

		return PUS_NO_ERROR;
	}
	else
	{
		return expectResult;
	}
}

#endif
