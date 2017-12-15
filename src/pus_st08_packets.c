

#include "pus_st08_packets.h"

extern const size_t pus_st08_limitFunctions;

pusMutex_t* pus_st08_mutex;

bool pus_st08_initializedFlag = false;

pusError_t pus_st08_initialize(pusMutex_t* mutex)
{
	if (pus_st08_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_ALREADY_INITIALIZED);
	}

	pus_st08_mutex = mutex;

	if (NULL != pus_st08_mutex && !pus_mutexLockOk(pus_st08_mutex))
	{
		return PUS_ERROR_INITIALIZATION;
	}

	if (PUS_NO_ERROR != pus_st08_configure())
	{
		if (NULL != pus_st08_mutex)
		{
			(void) pus_mutexUnlockOk(pus_st08_mutex);
		}
		return PUS_SET_ERROR(PUS_ERROR_INITIALIZATION);
	}

	if (NULL != pus_st08_mutex && !pus_mutexUnlockOk(pus_st08_mutex))
	{
		return PUS_ERROR_INITIALIZATION;
	}

	pus_st08_initializedFlag = true;
	return PUS_NO_ERROR;
}

bool pus_st08_isInitialized()
{
	return pus_st08_initializedFlag;
}

pusError_t pus_tc_8_1_createPerformFuctionRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt08FunctiontId_t functionId)
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
		pus_setTcService(outTc, pus_ST08_functionManagement);
		pus_setTcSubtype(outTc, pus_TC_8_1_performFunction);
		pus_setTcDataKind(outTc, pus_TC_DATA_ST_8_1);

		// Data field
		pus_tc_8_1_setFunctionId(outTc, functionId);

		return PUS_GET_ERROR();
	}
}

bool pus_st08_isInFunctionTable(pusSt08FunctiontId_t functionId)
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

void pus_tc_8_1_setFunctionId(pusPacket_t* outTc, pusSt08FunctiontId_t functionId)
{
	if (NULL == outTc)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if( !pus_st08_isInFunctionTable(functionId))
	{
		PUS_SET_ERROR(PUS_ERROR_UNEXPECTED_FUNCTION_ID);
	}

	if (PUS_NO_ERROR == PUS_EXPECT_ST08(outTc, pus_TC_8_1_performFunction))
	{
		outTc->data.u.tcData.data.u.st_8_1.functionId = functionId;
	}
}


void pus_tc_8_1_getFunctionId(pusSt08FunctiontId_t* functionId, pusPacket_t* outTc)
{
	if (NULL == outTc)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_NO_ERROR == PUS_EXPECT_ST08(outTc, pus_TC_8_1_performFunction))
	{
		*functionId = outTc->data.u.tcData.data.u.st_8_1.functionId;
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
			// Check that subtype corresponds to ST[8]
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
