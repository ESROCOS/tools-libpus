#include "pus_st17_packets.h"
//#include "pus_threads.h"
#include "pus_error.h"
#include "pus_packet.h"
//#include "pus_stored_param.h"


pusError_t pus_tc_17_1_createConnectionTestRequest(pusPacket_t* outTm, pusApidInfo_t* apid)
{

	if (NULL == outTm || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_initTcPacket(outTm);
		//pus_setTmDataKind(outTm, pus_TM_DATA_ST_1_X);

		// Source information
		pus_setApid(outTm, pus_getInfoApid(apid));
		pus_setSequenceCount(outTm, pus_getNextTmCount(apid));

		// Data length
		pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

		// Service identification
		pus_setTcService(outTm, pus_ST17_test);
		pus_setTcSubtype(outTm, pus_TC_17_1_connectionTest);

		//pus_setTmDestination(outTm, pus_APID_IDLE);

		// Timestamp
		//pus_setTmPacketTimeNow(outTm);


		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusError_t pus_tm_17_2_createConnectionTestReport(pusPacket_t* outTm, pusApidInfo_t* apid)
{
	if (NULL == outTm || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_initTmPacket(outTm);
		//pus_setTMDataKind(outTm, pus_TM_DATA_ST_1_X);

		// Source information
		pus_setApid(outTm, pus_getInfoApid(apid));
		pus_setSequenceCount(outTm, pus_getNextTmCount(apid));

		// Data length
		pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

		// Service identification
		pus_setTmService(outTm, pus_ST17_test);
		pus_setTmSubtype(outTm, pus_TM_17_2_connectionTest);

		//pus_setTmDestination(outTm, pus_APID_IDLE);

		// Timestamp
		pus_setTmPacketTimeNow(outTm);


		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
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

