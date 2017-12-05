#include "pus_st12_packets.h"


pusError_t pus_tc_12_X_createDefaultPacket(pusPacket_t* outTc, pusApidInfo_t* apid, pusSubservice_t subtype)
{
	if (NULL == outTc || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_initTcPacket(outTc);
		//pus_setTmDataKind(outTm, pus_TM_DATA_ST_1_X);

		// Source information
		pus_setApid(outTc, pus_getInfoApid(apid));
		pus_setSequenceCount(outTc, pus_getNextPacketCount(apid));

		// Data length
		pus_setPacketDataLength(outTc, sizeof(pusPacketData_t));

		pus_setTcService(outTc, pus_ST12_onBoardMonitoring);
		pus_setTcSubtype(outTc, subtype);


		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusError_t pus_tc_12_1_createEnableParameterMonitoringDefinitions(pusPacket_t* outTc, pusApidInfo_t* apid)
{
	if( NULL == outTc || NULL == apid )
	{
		return PUS_ERROR_NULLPTR;
	}

	if( PUS_NO_ERROR != pus_tc_12_X_createDefaultPacket(outTc, apid, pus_TC_12_1_enableParameterMonitoringDefinitions) )
	{
		return PUS_GET_ERROR();
	}


	return PUS_NO_ERROR;
}

pusError_t pus_tc_12_2_createDisableParameterMonitoringDefinitions(pusPacket_t* outTc, pusApidInfo_t* apid)
{
	if( NULL == outTc || NULL == apid )
	{
		return PUS_ERROR_NULLPTR;
	}
	if( PUS_NO_ERROR != pus_tc_12_X_createDefaultPacket(outTc, apid, pus_TC_12_2_disableParameterMonitoringDefinitions) )
	{
		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

/*pusError_t pus_tm_12_12_createCheckTransitionReport(pusPacket_t* outTm, pusApidInfo_t* apid)
{
	if( NULL == outTm || NULL == apid )
	{
		return PUS_ERROR_NULLPTR;
	}

	pus_initTmPacket(outTm);
	// pus_setTmDataKind(outTm, pus_TM_DATA_ST_1_X); //TODO datakind st12

	// Source information
	pus_setApid(outTm, pus_getInfoApid(apid));
	pus_setSequenceCount(outTm, pus_getNextPacketCount(apid));

	// Data length
	pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

	// Service identification
	pus_setTmService(outTm, pus_ST12_onBoardMonitoring);
	pus_setTmSubtype(outTm, pus_TM_12_12_checkTransitionReport);

	return PUS_NO_ERROR;
}*/

pusError_t pus_tc_12_15_createEnableParameterMonitoring(pusPacket_t* outTc, pusApidInfo_t* apid)
{
	if( NULL == outTc || NULL == apid )
	{
		return PUS_ERROR_NULLPTR;
	}
	if( PUS_NO_ERROR != pus_tc_12_X_createDefaultPacket(outTc, apid, pus_TC_12_15_enableParameterMonitoring) )
	{
		return PUS_GET_ERROR();
	}

	//no data kind, default nodata

	return PUS_NO_ERROR;
}

pusError_t pus_tc_12_16_createDisableParameterMonitoring(pusPacket_t* outTc, pusApidInfo_t* apid)
{
	if( NULL == outTc || NULL == apid )
	{
		return PUS_ERROR_NULLPTR;
	}
	if( PUS_NO_ERROR != pus_tc_12_X_createDefaultPacket(outTc, apid, pus_TC_12_16_disableParameterMonitoring) )
	{
		return PUS_GET_ERROR();
	}
	//no data kind, default nodata

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
			// Check that subtype corresponds to ST[01]
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
