#include "pus_threads.h"
#include "pus_error.h"
#include "pus_packet.h"
#include <string.h>

#include "pus_st20_packets.h"



pusError_t pus_tc_20_1_createParameterValueRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt20OnBoardParamId_t param)
{

	if (NULL == outTc)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_initTcPacket(outTc);

		// Source information
		pus_setApid(outTc, apid);
		pus_setSequenceCount(outTc, sequenceCount);

		// Data length
		pus_setPacketDataLength(outTc, sizeof(pusPacketData_t));

		// Service identification
		pus_setTcService(outTc, pus_ST20_parameterManagement);
		pus_setTcSubtype(outTc, pus_TC_20_1_reportParameterValues);
		pus_setTcDataKind(outTc, pus_TC_DATA_ST_20_X);
		pus_setTcSource(outTc, apid);

		//set paramId
		pus_tc_20_X_setParamId(outTc, param);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusError_t pus_tm_20_2_createParameterValueReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt20OnBoardParamId_t param, pusStoredParam_t value)
{
	if (NULL == outTm )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_initTmPacket(outTm);

		// Source information
		pus_setApid(outTm, apid);
		pus_setSequenceCount(outTm, sequenceCount);

		// Data length
		pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

		// Service identification
		pus_setTmService(outTm, pus_ST20_parameterManagement);
		pus_setTmSubtype(outTm, pus_TM_20_2_reportParameterValues);
		pus_setTmDataKind(outTm, pus_TM_DATA_ST_20_2);

		pus_setTmDestination(outTm, destination);

		// Timestamp
		pus_setTmPacketTimeNow(outTm);

		//set paramId and value
		pus_tm_20_2_setParamId(outTm, param);
		pus_tm_20_2_setParamValue(outTm, value);


		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusError_t pus_tc_20_3_createSetParameterValueRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt20OnBoardParamId_t param, pusStoredParam_t value)
{

	if (NULL == outTc)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_initTcPacket(outTc);

		// Source information
		pus_setApid(outTc, apid);
		pus_setSequenceCount(outTc, sequenceCount);

		// Data length
		pus_setPacketDataLength(outTc, sizeof(pusPacketData_t));

		// Service identification
		pus_setTcService(outTc, pus_ST20_parameterManagement);
		pus_setTcSubtype(outTc, pus_TC_20_3_setParameterValues);
		pus_setTcDataKind(outTc, pus_TC_DATA_ST_20_X);
		pus_setTcSource(outTc, apid);

		//set paramId and value
		pus_tc_20_X_setParamId(outTc, param);
		pus_tc_20_3_setParamValue(outTc, value);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusError_t pus_tc_20_X_setParamId(pusPacket_t* outTc, pusSt20OnBoardParamId_t param)
{
	if( PUS_NO_ERROR != PUS_EXPECT_ST20TC(outTc, pusSubtype_NONE))
	{
		return PUS_GET_ERROR();
	}
	if( param >= pus_ST20_PARAM_LIMIT )
	{
		return PUS_ERROR_INVALID_ID;
	}
	outTc->data.u.tcData.data.u.st_20_X.paramId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusSt20OnBoardParamId_t pus_tc_20_X_getParamId(const pusPacket_t* outTc)
{
	if( PUS_NO_ERROR != PUS_EXPECT_ST20TC(outTc, pusSubtype_NONE))
	{
		//return PUS_GET_ERROR();
		return 0;
	}
	PUS_SET_ERROR(PUS_NO_ERROR);
	return outTc->data.u.tcData.data.u.st_20_X.paramId;
}

pusError_t pus_tc_20_3_setParamValue(pusPacket_t* outTc, pusStoredParam_t value)
{
	if( PUS_NO_ERROR != PUS_EXPECT_ST20TC(outTc, pus_TC_20_3_setParameterValues))
	{
		return PUS_GET_ERROR();
	}
	outTc->data.u.tcData.data.u.st_20_X.value = value;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusStoredParam_t pus_tc_20_3_getParamValue(pusPacket_t* outTc)
{
	if( PUS_NO_ERROR != PUS_EXPECT_ST20TC(outTc, pus_TC_20_3_setParameterValues))
	{
		//PUS_GET_ERROR();
		return 0;
	}
	PUS_SET_ERROR(PUS_NO_ERROR);
	return outTc->data.u.tcData.data.u.st_20_X.value;
}

pusError_t pus_tm_20_2_setParamId(pusPacket_t* outTc, pusSt20OnBoardParamId_t param)
{
	if( PUS_NO_ERROR != PUS_EXPECT_ST20TM(outTc, pus_TM_20_2_reportParameterValues))
	{
		return PUS_GET_ERROR();
	}
	if( param >= pus_ST20_PARAM_LIMIT )
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	outTc->data.u.tmData.data.u.st_20_2.paramId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusSt20OnBoardParamId_t pus_tm_20_2_getParamId(const pusPacket_t* outTc)
{
	if( PUS_NO_ERROR != PUS_EXPECT_ST20TM(outTc, pus_TM_20_2_reportParameterValues))
	{
		return 0;
	}
	PUS_SET_ERROR(PUS_NO_ERROR);
	return outTc->data.u.tmData.data.u.st_20_2.paramId;
}

pusError_t pus_tm_20_2_setParamValue(pusPacket_t* outTc, pusStoredParam_t value)
{
	if( PUS_NO_ERROR != PUS_EXPECT_ST20TM(outTc, pus_TM_20_2_reportParameterValues))
	{
		return PUS_GET_ERROR();
	}
	outTc->data.u.tmData.data.u.st_20_2.value = value;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusStoredParam_t pus_tm_20_2_getParamValue(pusPacket_t* outTc)
{
	if( PUS_NO_ERROR != PUS_EXPECT_ST20TM(outTc, pus_TM_20_2_reportParameterValues))
	{
		return 0;
	}
	PUS_SET_ERROR(PUS_NO_ERROR);
	return outTc->data.u.tmData.data.u.st_20_2.value;
}

//
// Parameter checking
//

pusError_t pus_expectSt20Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTmHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTmService(packet);
		pusSubservice_t subtype = pus_getTmSubtype(packet);

		if (service != pus_ST20_parameterManagement)
		{
			pus_setError(PUS_ERROR_TM_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TM_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[01]
			if ((subtype != pus_TM_20_2_reportParameterValues))
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

		pusPacketDataKind_t kind = pus_getTmDataKind(packet);
		if (kind != pus_TM_DATA_ST_20_2)
		{
			pus_setError(PUS_ERROR_TM_KIND, function, (pusErrorData_t){.integer=kind});
			return PUS_ERROR_TM_KIND;
		}

		return PUS_NO_ERROR;
	}
	else
	{
		return expectResult;
	}
}

pusError_t pus_expectSt20Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTcHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTcService(packet);
		pusSubservice_t subtype = pus_getTcSubtype(packet);

		if (service != pus_ST20_parameterManagement)
		{
			pus_setError(PUS_ERROR_TC_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TC_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[01]
			if ((subtype != pus_TC_20_1_reportParameterValues) &&
				(subtype != pus_TC_20_3_setParameterValues))
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
		if (kind != pus_TC_DATA_ST_20_X)
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

