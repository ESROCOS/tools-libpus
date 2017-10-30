#include "pus_st01.h"

#include <stddef.h>
#include <assert.h>

#include "pus_packet.h"


//
// Report field getters and setters
//

void pus_tm_1_X_setPacketVersionNumber(pusPacket_t* tm, pusPacketVersion_t version)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pusSubtype_NONE))
	{
		tm->data.u.tmData.data.u.st_1_X.request.packetVersion = version;
	}
}

pusPacketVersion_t pus_tm_1_X_getPacketVersionNumber(pusPacket_t* tm)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pusSubtype_NONE))
	{
		return tm->data.u.tmData.data.u.st_1_X.request.packetVersion;
	}
	else
	{
		return pus_PACKET_VERSION_CURRENT;
	}
}

void pus_tm_1_X_setPacketType(pusPacket_t* tm, pusPacketType_t type)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pusSubtype_NONE))
	{
		tm->data.u.tmData.data.u.st_1_X.request.packetType = type;
	}
}

pusPacketType_t pus_tm_1_X_getPacketType(pusPacket_t* tm)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pusSubtype_NONE))
	{
		return tm->data.u.tmData.data.u.st_1_X.request.packetType;
	}
	else
	{
		return pus_TM;
	}
}

void pus_tm_1_X_setSecondaryHeaderFlag(pusPacket_t* tm, bool flag)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pusSubtype_NONE))
	{
		tm->data.u.tmData.data.u.st_1_X.request.secondaryHeaderFlag = flag;
	}
}

bool pus_tm_1_X_getSecondaryHeaderFlag(pusPacket_t* tm)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pusSubtype_NONE))
	{
		return tm->data.u.tmData.data.u.st_1_X.request.secondaryHeaderFlag;
	}
	else
	{
		return false;
	}
}

void pus_tm_1_X_setApid(pusPacket_t* tm, pusApid_t apid)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pusSubtype_NONE))
	{
		tm->data.u.tmData.data.u.st_1_X.request.apid = apid;
	}
}

pusApid_t pus_tm_1_X_getApid(pusPacket_t* tm)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pusSubtype_NONE))
	{
		return tm->data.u.tmData.data.u.st_1_X.request.apid;
	}
	else
	{
		return pus_APID_IDLE;
	}
}

void pus_tm_1_X_setSequenceFlags(pusPacket_t* tm, pusSequenceFlags_t flags)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pusSubtype_NONE))
	{
		tm->data.u.tmData.data.u.st_1_X.request.sequenceFlags = flags;
	}
}

pusSequenceFlags_t pus_tm_1_X_getSequenceFlags(pusPacket_t* tm)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pusSubtype_NONE))
	{
		return tm->data.u.tmData.data.u.st_1_X.request.sequenceFlags;
	}
	else
	{
		return pus_STANDALONE_PACKET;
	}
}

void pus_tm_1_X_setSequenceCount(pusPacket_t* tm, pusSequenceCount_t count)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pusSubtype_NONE))
	{
		tm->data.u.tmData.data.u.st_1_X.request.sequenceCount = count;
	}
}

pusSequenceCount_t pus_tm_1_X_getSequenceCount(pusPacket_t* tm)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pusSubtype_NONE))
	{
		return tm->data.u.tmData.data.u.st_1_X.request.sequenceCount;
	}
	else
	{
		return 0;
	}
}

void pus_tm_1_X_setStep(pusPacket_t* tm, pusStepId_t step)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pusSubtype_NONE))
	{
		tm->data.u.tmData.data.u.st_1_X.step = step;
	}
}

pusStepId_t pus_tm_1_X_getStep(pusPacket_t* tm)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pusSubtype_NONE))
	{
		return tm->data.u.tmData.data.u.st_1_X.step;
	}
	else
	{
		return 0;
	}
}

void pus_initSt01FailureInfo(pusSt01FailureInfo_t* info)
{
	pus_setSt01FailureInfo(info, pus_ST01_NO_ERROR, 0, 0);
}

void pus_setSt01FailureInfo(pusSt01FailureInfo_t* info, pusInt32_t subcode, pusInt32_t data, pusMemAddr_t address)
{
	if (NULL == info)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return;
	}
	else
	{
		info->subcode = subcode;
		info->data = (uint64_t)data;
		info->address = (uint64_t)address;
	}
}

pusInt32_t pus_getSt01FailureSubcode(const pusSt01FailureInfo_t* info)
{
	if (NULL == info)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	else
	{
		return info->subcode;
	}
}

pusInt32_t pus_getSt01FailureData(const pusSt01FailureInfo_t* info)
{
	if (NULL == info)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	else
	{
		return info->data;
	}
}

pusMemAddr_t pus_getSt01FailureAddress(const pusSt01FailureInfo_t* info)
{
	if (NULL == info)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	else
	{
		return info->address;
	}
}

void pus_tm_1_X_initFailureInfo(pusPacket_t* tm)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pusSubtype_NONE))
	{
		tm->data.u.tmData.data.u.st_1_X.failure.code = pus_ST01_NO_ERROR;
		pus_initSt01FailureInfo(&tm->data.u.tmData.data.u.st_1_X.failure.info);
	}
}

pusSt01FailureCode_t pus_tm_1_X_getFailureInfo(const pusPacket_t* tm, pusSt01FailureInfo_t* outInfo)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pusSubtype_NONE))
	{
		if (NULL != outInfo)
		{
			outInfo->subcode = tm->data.u.tmData.data.u.st_1_X.failure.info.subcode;
			outInfo->data = tm->data.u.tmData.data.u.st_1_X.failure.info.data;
			outInfo->address = tm->data.u.tmData.data.u.st_1_X.failure.info.address;
		}
		return tm->data.u.tmData.data.u.st_1_X.failure.code;
	}
	else
	{
		return pus_ST01_NO_ERROR;
	}
}

void pus_tm_1_X_setFailureInfo(pusPacket_t* tm, pusSt01FailureCode_t code, const pusSt01FailureInfo_t* info)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pusSubtype_NONE))
	{
		tm->data.u.tmData.data.u.st_1_X.failure.code = code;

		if (NULL != info)
		{
			tm->data.u.tmData.data.u.st_1_X.failure.info.subcode = info->subcode;
			tm->data.u.tmData.data.u.st_1_X.failure.info.data = info->data;
			tm->data.u.tmData.data.u.st_1_X.failure.info.address = info->address;
		}
	}
}


//
// Creation of TC acceptance report
//

pusError_t pus_tm_1_X_createReport(pusPacket_t* outTm, pusApidInfo_t* apid, const pusPacket_t* receivedTc, pusSubservice_t subtype)
{
	if (NULL == outTm || NULL == receivedTc || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_initTmPacket(outTm);
		pus_setTmDataKind(outTm, pus_TM_DATA_ST_1_X);

		// Source information
		pus_setApid(outTm, pus_getInfoApid(apid));
		pus_setSequenceCount(outTm, pus_getNextTmCount(apid));

		// Data length
		pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

		// Service identification
		pus_setTmService(outTm, pus_ST01_requestVerification);
		pus_setTmSubtype(outTm, subtype);

		// Destination = source of request (if has secondary header)
		bool tcHasSecondaryHeader = pus_getSecondaryHeaderFlag(receivedTc);
		if (tcHasSecondaryHeader)
		{
			pus_setTmDestination(outTm, pus_getTcSource(receivedTc));
		}
		else
		{
			pus_setTmDestination(outTm, pus_APID_IDLE);
		}

		// Timestamp
		pus_setTmPacketTimeNow(outTm);

		// TC information
		pus_tm_1_X_setPacketVersionNumber(outTm, pus_getPacketVersion(receivedTc));
		pus_tm_1_X_setPacketType(outTm, pus_getPacketType(receivedTc));
		pus_tm_1_X_setSecondaryHeaderFlag(outTm, tcHasSecondaryHeader);
		pus_tm_1_X_setApid(outTm, pus_getApid(receivedTc));
		pus_tm_1_X_setSequenceFlags(outTm, pus_getSequenceFlags(receivedTc));
		pus_tm_1_X_setSequenceCount(outTm, pus_getSequenceCount(receivedTc));

		// Failure and step are not used
		pus_tm_1_X_setStep(outTm, pus_STEP_NONE);
		pus_tm_1_X_initFailureInfo(outTm);

		return PUS_GET_ERROR();
	}
}

pusError_t pus_tm_1_1_createAcceptanceReportSuccess(pusPacket_t* outTm, pusApidInfo_t* apid, const pusPacket_t* receivedTc)
{
	if (NULL == outTm || NULL == receivedTc || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_IS_ERROR())
	{
		return PUS_ERROR_BEFORE;
	}
	else
	{
		return pus_tm_1_X_createReport(outTm, apid, receivedTc, pus_TM_1_1_successfulAcceptance);
	}
}

pusError_t pus_tm_1_2_createAcceptanceReportFailure(pusPacket_t* outTm, pusApidInfo_t* apid, const pusPacket_t* receivedTc,
		pusSt01FailureCode_t code, const pusSt01FailureInfo_t* info)
{
	if (NULL == outTm || NULL == receivedTc || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_IS_ERROR())
	{
		return PUS_ERROR_BEFORE;
	}
	else
	{
		pusError_t result = pus_tm_1_X_createReport(outTm, apid, receivedTc, pus_TM_1_2_failedAcceptance);
		if (PUS_NO_ERROR != result)
		{
			return result;
		}
		else
		{
			pus_tm_1_X_setFailureInfo(outTm, code, info);
			return PUS_GET_ERROR();
		}
	}
}

pusError_t pus_tm_1_3_createStartReportSuccess(pusPacket_t* outTm, pusApidInfo_t* apid, const pusPacket_t* receivedTc)
{
	if (NULL == outTm || NULL == receivedTc || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_IS_ERROR())
	{
		return PUS_ERROR_BEFORE;
	}
	else
	{
		return pus_tm_1_X_createReport(outTm, apid, receivedTc, pus_TM_1_3_successfulStart);
	}
}

pusError_t pus_tm_1_4_createStartReportFailure(pusPacket_t* outTm, pusApidInfo_t* apid, const pusPacket_t* receivedTc,
		pusSt01FailureCode_t code, const pusSt01FailureInfo_t* info)
{
	if (NULL == outTm || NULL == receivedTc || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_IS_ERROR())
	{
		return PUS_ERROR_BEFORE;
	}
	else
	{
		pusError_t result = pus_tm_1_X_createReport(outTm, apid, receivedTc, pus_TM_1_4_failedStart);
		if (PUS_NO_ERROR != result)
		{
			return result;
		}
		else
		{
			pus_tm_1_X_setFailureInfo(outTm, code, info);
			return PUS_GET_ERROR();
		}
	}
}

pusError_t pus_tm_1_5_createProgressReportSuccess(pusPacket_t* outTm, pusApidInfo_t* apid, const pusPacket_t* receivedTc, pusStepId_t step)
{
	if (NULL == outTm || NULL == receivedTc || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_IS_ERROR())
	{
		return PUS_ERROR_BEFORE;
	}
	else
	{
		pusError_t result = pus_tm_1_X_createReport(outTm, apid, receivedTc, pus_TM_1_5_successfulProgress);
		if (PUS_NO_ERROR != result)
		{
			return result;
		}
		else
		{
			pus_tm_1_X_setStep(outTm, step);
			return PUS_GET_ERROR();
		}
	}
}

pusError_t pus_tm_1_6_createProgressReportFailure(pusPacket_t* outTm, pusApidInfo_t* apid, const pusPacket_t* receivedTc,
		pusStepId_t step, pusSt01FailureCode_t code, const pusSt01FailureInfo_t* info)
{
	if (NULL == outTm || NULL == receivedTc || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_IS_ERROR())
	{
		return PUS_ERROR_BEFORE;
	}
	else
	{
		pusError_t result = pus_tm_1_X_createReport(outTm, apid, receivedTc, pus_TM_1_6_failedProgress);
		if (PUS_NO_ERROR != result)
		{
			return result;
		}
		else
		{
			pus_tm_1_X_setFailureInfo(outTm, code, info);
			pus_tm_1_X_setStep(outTm, step);
			return PUS_GET_ERROR();
		}
	}
}

pusError_t pus_tm_1_7_createCompletionReportSuccess(pusPacket_t* outTm, pusApidInfo_t* apid, const pusPacket_t* receivedTc)
{
	if (NULL == outTm || NULL == receivedTc || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_IS_ERROR())
	{
		return PUS_ERROR_BEFORE;
	}
	else
	{
		return pus_tm_1_X_createReport(outTm, apid, receivedTc, pus_TM_1_7_successfulCompletion);
	}
}

pusError_t pus_tm_1_8_createCompletionReportFailure(pusPacket_t* outTm, pusApidInfo_t* apid, const pusPacket_t* receivedTc,
		pusSt01FailureCode_t code, const pusSt01FailureInfo_t* info)
{
	if (NULL == outTm || NULL == receivedTc || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_IS_ERROR())
	{
		return PUS_ERROR_BEFORE;
	}
	else
	{
		pusError_t result = pus_tm_1_X_createReport(outTm, apid, receivedTc, pus_TM_1_8_failedCompletion);
		if (PUS_NO_ERROR != result)
		{
			return result;
		}
		else
		{
			pus_tm_1_X_setFailureInfo(outTm, code, info);
			return PUS_GET_ERROR();
		}
	}
}


//
// Parameter checking
//

pusError_t pus_expectSt01Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTmHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTmService(packet);
		pusSubservice_t subtype = pus_getTmSubtype(packet);

		if (service != pus_ST01_requestVerification)
		{
			pus_setError(PUS_ERROR_TM_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TM_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[01]
			if ((subtype != pus_TM_1_1_successfulAcceptance) &&
				(subtype != pus_TM_1_2_failedAcceptance) &&
				(subtype != pus_TM_1_3_successfulStart) &&
				(subtype != pus_TM_1_4_failedStart) &&
				(subtype != pus_TM_1_5_successfulProgress) &&
				(subtype != pus_TM_1_6_failedProgress) &&
				(subtype != pus_TM_1_7_successfulCompletion) &&
				(subtype != pus_TM_1_8_failedCompletion))
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
		if (kind != pus_TM_DATA_ST_1_X)
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


