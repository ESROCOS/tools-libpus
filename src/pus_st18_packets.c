/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pus_st18_packets.h"
#ifdef PUS_CONFIGURE_ST18_ENABLED


pusError_t pus_tc_18_X_createDefaultRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSubservice_t subtype)
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
		pus_setTcService(outTc, pus_ST18_onBoardControlProcedure);
		pus_setTcSubtype(outTc, subtype);
		pus_setTcSource(outTc, apid);

		return PUS_GET_ERROR();
	}

	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_18_1_createLoadObcpDirectRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusSt18ObcpId_t* obcpId, const pusSt18ObcpCode_t* code)
{
	if ( NULL == outTc || NULL == obcpId || NULL == code )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	pusError_t error = pus_tc_18_X_createDefaultRequest(outTc, apid, sequenceCount, pus_TC_18_1_loadObcpDirect);
	if( PUS_NO_ERROR != error )
	{
		return PUS_GET_ERROR();
	}

	//Set data field
	pus_setTcDataKind(outTc, pus_TC_DATA_ST_18_1);
	pus_tc_18_X_setObcpId(outTc, obcpId);
	pus_tc_18_1_setObcpCode(outTc, code);

	return PUS_GET_ERROR();
}

pusError_t pus_tc_18_2_createUnloadObcpRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusSt18ObcpId_t* obcpId)
{
	if ( NULL == outTc || NULL == obcpId )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	pusError_t error = pus_tc_18_X_createDefaultRequest(outTc, apid, sequenceCount, pus_TC_18_2_unloadObcp);
	if( PUS_NO_ERROR != error )
	{
		return PUS_GET_ERROR();
	}

	//Set data field
	pus_setTcDataKind(outTc, pus_TC_DATA_ST_18_2_6_12);
	pus_tc_18_X_setObcpId(outTc, obcpId);


	return PUS_GET_ERROR();
}

pusError_t pus_tc_18_3_createActivateObcpRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusSt18ObcpId_t* obcpId, pusSt18ObservabilityLevel_t observability)
{
	if ( NULL == outTc || NULL == obcpId )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	pusError_t error = pus_tc_18_X_createDefaultRequest(outTc, apid, sequenceCount, pus_TC_18_3_activateObcp);
	if( PUS_NO_ERROR != error )
	{
		return PUS_GET_ERROR();
	}

	//Set data field
	pus_setTcDataKind(outTc, pus_TC_DATA_ST_18_3);
	pus_tc_18_X_setObcpId(outTc, obcpId);
	pus_tc_18_3_setObservabilityLevel(outTc, observability);

	return PUS_GET_ERROR();
}

pusError_t pus_tc_18_4_createStopObcpRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusSt18ObcpId_t* obcpId, pusSt18ObcpStepId_t step)
{
	if ( NULL == outTc || NULL == obcpId )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	pusError_t error = pus_tc_18_X_createDefaultRequest(outTc, apid, sequenceCount, pus_TC_18_4_stopObcp);
	if( PUS_NO_ERROR != error )
	{
		return PUS_GET_ERROR();
	}

	//Set data field
	pus_setTcDataKind(outTc, pus_TC_DATA_ST_18_4_5);
	pus_tc_18_X_setObcpId(outTc, obcpId);
	pus_tc_18_4_5_setObcpStepId(outTc, step);

	return PUS_GET_ERROR();
}

pusError_t pus_tc_18_5_createSuspendObcpRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusSt18ObcpId_t* obcpId, pusSt18ObcpStepId_t step)
{
	if ( NULL == outTc || NULL == obcpId )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	pusError_t error = pus_tc_18_X_createDefaultRequest(outTc, apid, sequenceCount, pus_TC_18_5_suspendObcp);
	if( PUS_NO_ERROR != error )
	{
		return PUS_GET_ERROR();
	}

	//Set data field
	pus_setTcDataKind(outTc, pus_TC_DATA_ST_18_4_5);
	pus_tc_18_X_setObcpId(outTc, obcpId);
	pus_tc_18_4_5_setObcpStepId(outTc, step);

	return PUS_GET_ERROR();
}

pusError_t pus_tc_18_6_createResumeObcpRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusSt18ObcpId_t* obcpId)
{
	if ( NULL == outTc || NULL == obcpId )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	pusError_t error = pus_tc_18_X_createDefaultRequest(outTc, apid, sequenceCount, pus_TC_18_6_resumeObcp);
	if( PUS_NO_ERROR != error )
	{
		return PUS_GET_ERROR();
	}

	//Set data field
	pus_setTcDataKind(outTc, pus_TC_DATA_ST_18_2_6_12);
	pus_tc_18_X_setObcpId(outTc, obcpId);


	return PUS_GET_ERROR();
}

pusError_t pus_tc_18_12_createAbortObcpRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusSt18ObcpId_t* obcpId)
{
	if ( NULL == outTc || NULL == obcpId )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	pusError_t error = pus_tc_18_X_createDefaultRequest(outTc, apid, sequenceCount, pus_TC_18_12_abortObcp);
	if( PUS_NO_ERROR != error )
	{
		return PUS_GET_ERROR();
	}

	//Set data field
	pus_setTcDataKind(outTc, pus_TC_DATA_ST_18_2_6_12);
	pus_tc_18_X_setObcpId(outTc, obcpId);


	return PUS_GET_ERROR();
}


pusError_t pus_tc_18_13_createLoadObcpReferenceRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const pusSt18ObcpId_t* obcpId, const pusSt23RepositoryPath_t* repository, const pusSt23FileName_t* fileName)
{
	if ( NULL == outTc || NULL == obcpId || NULL == repository || NULL == fileName )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	pusError_t error = pus_tc_18_X_createDefaultRequest(outTc, apid, sequenceCount, pus_TC_18_13_loadObcpByReference);
	if( PUS_NO_ERROR != error )
	{
		return PUS_GET_ERROR();
	}

	//Set data field
	pus_setTcDataKind(outTc, pus_TC_DATA_ST_18_13);
	pus_tc_18_X_setObcpId(outTc, obcpId);
	pus_tc_18_13_setFileName(outTc, fileName);
	pus_tc_18_13_setRepositoryPath(outTc, repository);

	return PUS_GET_ERROR();
}

pusError_t pus_tc_18_21_createStartObcpEngineRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
	if ( NULL == outTc )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	pusError_t error = pus_tc_18_X_createDefaultRequest(outTc, apid, sequenceCount, pus_TC_18_21_startObcpEngine);
	if( PUS_NO_ERROR != error )
	{
		return PUS_GET_ERROR();
	}

	pus_setTcDataKind(outTc, pus_TC_DATA_NONE);
	outTc->data.u.tcData.data.u.st_0_0 = 0;

	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_18_22_createStopObcpEngineRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
	if ( NULL == outTc )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	pusError_t error = pus_tc_18_X_createDefaultRequest(outTc, apid, sequenceCount, pus_TC_18_22_stopObcpEngine);
	if( PUS_NO_ERROR != error )
	{
		return PUS_GET_ERROR();
	}

	pus_setTcDataKind(outTc, pus_TC_DATA_NONE);
	outTc->data.u.tcData.data.u.st_0_0 = 0;

	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_18_X_setObcpId(pusPacket_t* outTc, const pusSt18ObcpId_t* obcpId)
{
	if( NULL == outTc || obcpId == NULL )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST18TC(outTc, pusSubtype_NONE))
	{
		return PUS_GET_ERROR();
	}

	if( pus_TC_DATA_ST_18_1 == pus_getTcDataKind(outTc) )
	{
		outTc->data.u.tcData.data.u.st_18_1.obcpId = *obcpId;
		return PUS_NO_ERROR;
	}
	if( pus_TC_DATA_ST_18_2_6_12 == pus_getTcDataKind(outTc) )
	{
		outTc->data.u.tcData.data.u.st_18_2_6_12.obcpId = *obcpId;
		return PUS_NO_ERROR;
	}
	if( pus_TC_DATA_ST_18_3 == pus_getTcDataKind(outTc) )
	{
		outTc->data.u.tcData.data.u.st_18_3.obcpId = *obcpId;
		return PUS_NO_ERROR;
	}
	if( pus_TC_DATA_ST_18_4_5 == pus_getTcDataKind(outTc) )
	{
		outTc->data.u.tcData.data.u.st_18_4_5.obcpId = *obcpId;
		return PUS_NO_ERROR;
	}
	if( pus_TC_DATA_ST_18_13 == pus_getTcDataKind(outTc) )
	{
		outTc->data.u.tcData.data.u.st_18_13.obcpId = *obcpId;
		return PUS_NO_ERROR;
	}

	return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
}

pusError_t pus_tc_18_X_getObcpId(pusSt18ObcpId_t* obcpId, const pusPacket_t* outTc)
{
	if( NULL == outTc || obcpId == NULL )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST18TC(outTc, pusSubtype_NONE))
	{
		return PUS_GET_ERROR();
	}

	if( pus_TC_DATA_ST_18_1 == pus_getTcDataKind(outTc) )
	{
		*obcpId = outTc->data.u.tcData.data.u.st_18_1.obcpId;
		return PUS_NO_ERROR;
	}
	if( pus_TC_DATA_ST_18_2_6_12 == pus_getTcDataKind(outTc) )
	{
		*obcpId = outTc->data.u.tcData.data.u.st_18_2_6_12.obcpId;
		return PUS_NO_ERROR;
	}
	if( pus_TC_DATA_ST_18_3 == pus_getTcDataKind(outTc) )
	{
		*obcpId = outTc->data.u.tcData.data.u.st_18_3.obcpId;
		return PUS_NO_ERROR;
	}
	if( pus_TC_DATA_ST_18_4_5 == pus_getTcDataKind(outTc) )
	{
		*obcpId = outTc->data.u.tcData.data.u.st_18_4_5.obcpId;
		return PUS_NO_ERROR;
	}
	if( pus_TC_DATA_ST_18_13 == pus_getTcDataKind(outTc) )
	{
		*obcpId = outTc->data.u.tcData.data.u.st_18_13.obcpId;
		return PUS_NO_ERROR;
	}

	return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
}



pusError_t pus_tc_18_1_setObcpCode(pusPacket_t* outTc, const pusSt18ObcpCode_t* code)
{
	if( NULL == outTc || NULL == code )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST18TC(outTc, pus_TC_18_1_loadObcpDirect))
	{
		return PUS_GET_ERROR();
	}
	if( pus_TC_DATA_ST_18_1 != pus_getTcDataKind(outTc) )
	{
		return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
	}

	outTc->data.u.tcData.data.u.st_18_1.obcpCode = *code;
	return PUS_NO_ERROR;
}

pusError_t pus_tc_18_1_getObcpCode(pusSt18ObcpCode_t* code, const pusPacket_t* outTc)
{
	if( NULL == outTc || NULL == code )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST18TC(outTc, pus_TC_18_1_loadObcpDirect))
	{
		return PUS_GET_ERROR();
	}
	if( pus_TC_DATA_ST_18_1 != pus_getTcDataKind(outTc) )
	{
		return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
	}

	*code = outTc->data.u.tcData.data.u.st_18_1.obcpCode;
	return PUS_NO_ERROR;
}

pusError_t pus_tc_18_3_setObservabilityLevel(pusPacket_t* outTc, pusSt18ObservabilityLevel_t observability)
{
	if( NULL == outTc )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST18TC(outTc, pus_TC_18_3_activateObcp))
	{
		return PUS_GET_ERROR();
	}
	if( pus_TC_DATA_ST_18_3 != pus_getTcDataKind(outTc) )
	{
		return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
	}

	outTc->data.u.tcData.data.u.st_18_3.observabilityLevel = observability;
	return PUS_NO_ERROR;
}

pusError_t pus_tc_18_3_getObservabilityLevel(pusSt18ObservabilityLevel_t* observability, const pusPacket_t* outTc)
{
	if( NULL == outTc || NULL == observability )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST18TC(outTc, pus_TC_18_3_activateObcp))
	{
		return PUS_GET_ERROR();
	}
	if( pus_TC_DATA_ST_18_3 != pus_getTcDataKind(outTc) )
	{
		return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
	}

	*observability = outTc->data.u.tcData.data.u.st_18_3.observabilityLevel;
	return PUS_NO_ERROR;
}

pusError_t pus_tc_18_4_5_setObcpStepId(pusPacket_t* outTc, pusSt18ObcpStepId_t step)
{
	if( NULL == outTc )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST18TC(outTc, pusSubtype_NONE))
	{
		return PUS_GET_ERROR();
	}
	if( pus_TC_DATA_ST_18_4_5 != pus_getTcDataKind(outTc) )
	{
		return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
	}

	outTc->data.u.tcData.data.u.st_18_4_5.stepId = step;
	return PUS_NO_ERROR;
}

pusError_t pus_tc_18_4_5_getObcpStepId(pusSt18ObcpStepId_t* step, const pusPacket_t* outTc)
{
	if( NULL == outTc || NULL == step )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST18TC(outTc, pusSubtype_NONE))
	{
		return PUS_GET_ERROR();
	}
	if( pus_TC_DATA_ST_18_4_5 != pus_getTcDataKind(outTc) )
	{
		return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
	}

	*step = outTc->data.u.tcData.data.u.st_18_4_5.stepId;
	return PUS_NO_ERROR;
}


pusError_t pus_tc_18_13_setFileName(pusPacket_t* outTc, const pusSt23FileName_t* fileName)
{
	if( NULL == outTc || NULL == fileName )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST18TC(outTc, pus_TC_18_13_loadObcpByReference))
	{
		return PUS_GET_ERROR();
	}
	if( pus_TC_DATA_ST_18_13 != pus_getTcDataKind(outTc) )
	{
		return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
	}

	outTc->data.u.tcData.data.u.st_18_13.fileName = *fileName;
	return PUS_NO_ERROR;
}

pusError_t pus_tc_18_13_getFileName(pusSt23FileName_t* fileName, const pusPacket_t* outTc)
{
	if( NULL == outTc || NULL == fileName )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST18TC(outTc, pus_TC_18_13_loadObcpByReference))
	{
		return PUS_GET_ERROR();
	}
	if( pus_TC_DATA_ST_18_13 != pus_getTcDataKind(outTc) )
	{
		return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
	}

	*fileName = outTc->data.u.tcData.data.u.st_18_13.fileName;
	return PUS_NO_ERROR;
}

pusError_t pus_tc_18_13_setRepositoryPath(pusPacket_t* outTc, const pusSt23RepositoryPath_t* repository)
{
	if( NULL == outTc || NULL == repository )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST18TC(outTc, pus_TC_18_13_loadObcpByReference))
	{
		return PUS_GET_ERROR();
	}
	if( pus_TC_DATA_ST_18_13 != pus_getTcDataKind(outTc) )
	{
		return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
	}

	outTc->data.u.tcData.data.u.st_18_13.repository = *repository;
	return PUS_NO_ERROR;
}

pusError_t pus_tc_18_13_getRepositoryPath(pusSt23RepositoryPath_t* repository, const pusPacket_t* outTc)
{
	if( NULL == outTc || NULL == repository )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST18TC(outTc, pus_TC_18_13_loadObcpByReference))
	{
		return PUS_GET_ERROR();
	}
	if( pus_TC_DATA_ST_18_13 != pus_getTcDataKind(outTc) )
	{
		return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
	}

	*repository = outTc->data.u.tcData.data.u.st_18_13.repository;
	return PUS_NO_ERROR;
}

pusError_t pus_expectSt18Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTcHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTcService(packet);
		pusSubservice_t subtype = pus_getTcSubtype(packet);

		if (service != pus_ST18_onBoardControlProcedure)
		{
			pus_setError(PUS_ERROR_TC_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TC_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[17]
			if ((subtype != pus_TC_18_1_loadObcpDirect) &&
				(subtype != pus_TC_18_2_unloadObcp) &&
				(subtype != pus_TC_18_3_activateObcp) &&
				(subtype != pus_TC_18_4_stopObcp) &&
				(subtype != pus_TC_18_5_suspendObcp) &&
				(subtype != pus_TC_18_6_resumeObcp) &&
				(subtype != pus_TC_18_12_abortObcp) &&
				(subtype != pus_TC_18_13_loadObcpByReference) &&
				(subtype != pus_TC_18_21_startObcpEngine) &&
				(subtype != pus_TC_18_22_stopObcpEngine))
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
		if (kind != pus_TC_DATA_NONE && kind != pus_TC_DATA_ST_18_1 && kind != pus_TC_DATA_ST_18_2_6_12
			&& kind != pus_TC_DATA_ST_18_3 && kind != pus_TC_DATA_ST_18_4_5 && kind != pus_TC_DATA_ST_18_13 )
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
