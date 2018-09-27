/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pus_st12_packets.h"
#ifdef PUS_CONFIGURE_ST12_ENABLED


pusError_t pus_tc_12_X_createDefaultPacket(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSubservice_t subtype)
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

		pus_setTcService(outTc, pus_ST12_onBoardMonitoring);
		pus_setTcSubtype(outTc, subtype);
		pus_setTcSource(outTc, apid);


		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusError_t pus_tc_12_1_createEnableParameterMonitoringDefinitions(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt12PmonId_t pmon)
{
	if( NULL == outTc)
	{
		return PUS_ERROR_NULLPTR;
	}

	if( PUS_NO_ERROR != pus_tc_12_X_createDefaultPacket(outTc, apid, sequenceCount, pus_TC_12_1_enableParameterMonitoringDefinitions) )
	{
		return PUS_GET_ERROR();
	}

	pus_setTcDataKind(outTc, pus_TC_DATA_ST_12_1_2);
	pus_tc_12_1_2_setPmonId(outTc, pmon);

	return PUS_NO_ERROR;
}

pusError_t pus_tc_12_2_createDisableParameterMonitoringDefinitions(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt12PmonId_t pmon)
{
	if( NULL == outTc)
	{
		return PUS_ERROR_NULLPTR;
	}
	if( PUS_NO_ERROR != pus_tc_12_X_createDefaultPacket(outTc, apid, sequenceCount, pus_TC_12_2_disableParameterMonitoringDefinitions) )
	{
		return PUS_GET_ERROR();
	}

	pus_setTcDataKind(outTc, pus_TC_DATA_ST_12_1_2);
	pus_tc_12_1_2_setPmonId(outTc, pmon);

	return PUS_NO_ERROR;
}


pusError_t pus_tc_12_15_createEnableParameterMonitoring(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
	if( NULL == outTc)
	{
		return PUS_ERROR_NULLPTR;
	}
	if( PUS_NO_ERROR != pus_tc_12_X_createDefaultPacket(outTc, apid, sequenceCount, pus_TC_12_15_enableParameterMonitoring) )
	{
		return PUS_GET_ERROR();
	}
	pus_setTcDataKind(outTc, pus_TC_DATA_NONE);
	outTc->data.u.tcData.data.u.st_0_0 = 0;

	return PUS_NO_ERROR;
}

pusError_t pus_tc_12_16_createDisableParameterMonitoring(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
	if( NULL == outTc)
	{
		return PUS_ERROR_NULLPTR;
	}
	if( PUS_NO_ERROR != pus_tc_12_X_createDefaultPacket(outTc, apid, sequenceCount, pus_TC_12_16_disableParameterMonitoring) )
	{
		return PUS_GET_ERROR();
	}
	pus_setTcDataKind(outTc, pus_TC_DATA_NONE);
	outTc->data.u.tcData.data.u.st_0_0 = 0;

	return PUS_NO_ERROR;
}


pusError_t pus_tc_12_1_2_setPmonId(pusPacket_t* outTc, pusSt12PmonId_t pmon)
{
	if( NULL == outTc )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if( PUS_NO_ERROR != PUS_EXPECT_ST12TC(outTc, pusSubtype_NONE) )
	{
		return PUS_GET_ERROR();
	}

	outTc->data.u.tcData.data.u.st_12_1_2.pmonId = pmon;
	return PUS_NO_ERROR;
}

pusError_t pus_tc_12_1_2_getPmonId(pusSt12PmonId_t* pmon, const pusPacket_t* tcPacket)
{
	if( NULL == tcPacket || NULL == pmon )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if( PUS_NO_ERROR != PUS_EXPECT_ST12TC(tcPacket, pusSubtype_NONE) )
	{
		return PUS_GET_ERROR();
	}

	*pmon = tcPacket->data.u.tcData.data.u.st_12_1_2.pmonId;
	return PUS_NO_ERROR;
}


//
// Parameter checking
//
pusError_t pus_expectSt12Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTcHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTcService(packet);
		pusSubservice_t subtype = pus_getTcSubtype(packet);

		if (service != pus_ST12_onBoardMonitoring)
		{
			pus_setError(PUS_ERROR_TC_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TC_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[12]
			if ((subtype != pus_TC_12_1_enableParameterMonitoringDefinitions) &&
				(subtype != pus_TC_12_2_disableParameterMonitoringDefinitions) &&
				(subtype != pus_TC_12_15_enableParameterMonitoring) &&
				(subtype != pus_TC_12_16_disableParameterMonitoring))
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

		pusPacketDataKind_t kind = pus_getTcDataKind(packet);
		if (kind != pus_TC_DATA_ST_12_1_2 && kind != pus_TC_DATA_NONE)
		{
			pus_setError(PUS_ERROR_TC_KIND, function, (pusErrorData_t){.integer=kind});
			return PUS_ERROR_TC_KIND;
		}

		return PUS_NO_ERROR;
	}
	else
	{
		return expectResult;
	}
}

#endif
