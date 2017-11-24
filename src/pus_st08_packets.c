

#include "pus_st08_packets.h"

extern const size_t pus_st08_limitFunctions;


pusError_t pus_tc_8_2_createPerformFuctionRequest(pusPacket_t* outTc, pusApidInfo_t* apid,/* pusApid_t destination, */pusSt08FunctiontId_t functionId)
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
		pus_setSequenceCount(outTc, pus_getNextTmCount(apid));

		// Data length
		pus_setPacketDataLength(outTc, sizeof(pusPacketData_t));

		// Service identification
		pus_setTcService(outTc, pus_ST08_functionManagement);
		pus_setTcSubtype(outTc, pus_TC_8_1_performFunction);

		pus_setPacketDataKind(outTc, st_8_1_PRESENT);

		//pus_setTmDestination(outTm, pus_APID_IDLE);

		// Timestamp
		//pus_setTmPacketTimeNow(outTm);

		pus_tc_8_2_setFunctionId(outTc, functionId);


		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

bool pus_st08_inInFunctionTable(pusSt08FunctiontId_t functionId)
{
	if( functionId < pus_st08_limitFunctions)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void pus_tc_8_2_setFunctionId(pusPacket_t* outTc, pusSt08FunctiontId_t functionId)
{
	if (NULL == outTc)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return;
	}
	else if (PUS_NO_ERROR == PUS_EXPECT_ST08(outTc, pus_TC_8_1_performFunction))
	{
		//outTm->data.u.tmData.data.u.st_3_25.reportId = reportId;
		outTc->data.u.tcData.data.u.st_8_1.functionId = functionId;
	}
}

pusError_t pus_expectSt08(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTcHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTcService(packet);
		pusSubservice_t subtype = pus_getTcSubtype(packet);

		if (service != pus_ST08_functionManagement)
		{
			pus_setError(PUS_ERROR_TC_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TC_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[17]
			if (subtype != pus_TC_8_1_performFunction)
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
