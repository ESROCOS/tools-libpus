#include "pus_threads.h"
#include "pus_error.h"
#include "pus_packet.h"
#include <string.h>

#include "pus_st23_packets.h"



pusError_t pus_tc_23_X_createDefaultRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSubservice_t subtype)
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
		pus_setTcService(outTc, pus_ST23_fileManagement);
		pus_setTcSubtype(outTc, subtype);
		pus_setTcSource(outTc, apid);

		return PUS_GET_ERROR();
	}

	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_23_1_createCreateFileRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const pusSt23RepositoryPath_t* repository, const pusSt23FileName_t* fileName, pusSt23MaximumSize_t maxSize)
{
	if ( NULL == outTc || NULL == repository || NULL == fileName )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	pusError_t error = pus_tc_23_X_createDefaultRequest(outTc, apid, sequenceCount, pus_TC_23_1_createFile);
	if( PUS_NO_ERROR != error )
	{
		return PUS_GET_ERROR();
	}

	//Set data field
	pus_setTcDataKind(outTc, pus_TC_DATA_ST_23_1);
	pus_tc_tm_23_X_setRepositoryPath(outTc, repository);
	pus_tc_tm_23_X_setFileName(outTc, fileName);
	pus_tc_tm_23_1_4_setMaximumSize(outTc, maxSize);

	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_23_2_createDeleteFileRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const pusSt23RepositoryPath_t* repository, const pusSt23FileName_t* fileName)
{
	if ( NULL == outTc || NULL == repository || NULL == fileName )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	pusError_t error = pus_tc_23_X_createDefaultRequest(outTc, apid, sequenceCount, pus_TC_23_2_deleteFile);
	if( PUS_NO_ERROR != error )
	{
		return PUS_GET_ERROR();
	}

	//Set data field
	pus_setTcDataKind(outTc, pus_TC_DATA_ST_23_2_3);
	pus_tc_tm_23_X_setRepositoryPath(outTc, repository);
	pus_tc_tm_23_X_setFileName(outTc, fileName);

	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_23_3_createReportFileAtributesRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const pusSt23RepositoryPath_t* repository, const pusSt23FileName_t* fileName)
{
	if ( NULL == outTc || NULL == repository || NULL == fileName )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	pusError_t error = pus_tc_23_X_createDefaultRequest(outTc, apid, sequenceCount, pus_TC_23_3_reportFileAttributes);
	if( PUS_NO_ERROR != error )
	{
		return PUS_GET_ERROR();
	}

	//Set data field
	pus_setTcDataKind(outTc, pus_TC_DATA_ST_23_2_3);
	pus_tc_tm_23_X_setRepositoryPath(outTc, repository);
	pus_tc_tm_23_X_setFileName(outTc, fileName);

	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tm_23_4_createReportFileAtributesReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination,
		const pusSt23RepositoryPath_t* repository, const pusSt23FileName_t* fileName, pusSt23MaximumSize_t maxSize)
{
	if ( NULL == outTm || NULL == repository || NULL == fileName )
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
		pus_setTmService(outTm, pus_ST23_fileManagement);
		pus_setTmSubtype(outTm, pus_TM_23_4_reportFileAttributes);
		pus_setTmDestination(outTm, destination);

		// Timestamp
		pus_setTmPacketTimeNow(outTm);

		// Set data field
		pus_setTmDataKind(outTm, pus_TM_DATA_ST_23_4);
		pus_tc_tm_23_1_4_setMaximumSize(outTm, maxSize);
		pus_tc_tm_23_X_setRepositoryPath(outTm, repository);
		pus_tc_tm_23_X_setFileName(outTm, fileName);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusError_t pus_tc_23_14_createCopyFileRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const pusSt23RepositoryPath_t* sourceRepository, const pusSt23FileName_t* sourceFileName,
		const pusSt23RepositoryPath_t* targetRepository, const pusSt23FileName_t* targetFileName)
{
	if ( NULL == outTc || NULL == sourceRepository || NULL == sourceFileName || NULL == targetRepository || NULL == targetFileName )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	pusError_t error = pus_tc_23_X_createDefaultRequest(outTc, apid, sequenceCount, pus_TC_23_14_copyFile);
	if( PUS_NO_ERROR != error )
	{
		return PUS_GET_ERROR();
	}

	//Set data field
	pus_setTcDataKind(outTc, pus_TC_DATA_ST_23_14);
	pus_tc_23_14_setSourceRepositoryPath(outTc, sourceRepository);
	pus_tc_23_14_setTargetRepositoryPath(outTc, targetRepository);
	pus_tc_23_14_setSourceFileName(outTc, sourceFileName);
	pus_tc_23_14_setTargetFileName(outTc, targetFileName);

	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_tm_23_X_setFileName(pusPacket_t* outTc, const pusSt23FileName_t* file)
{
	if( NULL == outTc || file == NULL )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR == PUS_EXPECT_ST23TM(outTc, pus_TM_1_4_failedStart))
	{
		//TM
		outTc->data.u.tmData.data.u.st_23_4.fileName = *file;
		return PUS_NO_ERROR;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST23TC(outTc, pusSubtype_NONE))
	{
		return PUS_GET_ERROR();
	}

	if( pus_TC_DATA_ST_23_1 == pus_getTcDataKind(outTc) )
	{
		outTc->data.u.tcData.data.u.st_23_1.fileName = *file;
		return PUS_NO_ERROR;
	}
	if( pus_TC_DATA_ST_23_2_3 == pus_getTcDataKind(outTc) )
	{
		outTc->data.u.tcData.data.u.st_23_2_3.fileName = *file;
		return PUS_NO_ERROR;
	}

	return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
}

pusError_t pus_tc_tm_23_X_getFileName(pusSt23FileName_t* file, const pusPacket_t* outTc)
{
	if( NULL == outTc || file == NULL )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR == PUS_EXPECT_ST23TM(outTc, pus_TM_1_4_failedStart))
	{
		*file = outTc->data.u.tmData.data.u.st_23_4.fileName;
		return PUS_NO_ERROR;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST23TC(outTc, pusSubtype_NONE))
	{
		return PUS_GET_ERROR();
	}

	if( pus_TC_DATA_ST_23_1 == pus_getTcDataKind(outTc) )
	{
		*file = outTc->data.u.tcData.data.u.st_23_1.fileName;
		return PUS_NO_ERROR;
	}
	if( pus_TC_DATA_ST_23_2_3 == pus_getTcDataKind(outTc) )
	{
		*file = outTc->data.u.tcData.data.u.st_23_2_3.fileName;
		return PUS_NO_ERROR;
	}


	return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
}

pusError_t pus_tc_tm_23_X_setRepositoryPath(pusPacket_t* outTc, const pusSt23RepositoryPath_t* repository)
{
	if( NULL == outTc || NULL == repository )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR == PUS_EXPECT_ST23TM(outTc, pus_TM_1_4_failedStart))
	{
		outTc->data.u.tmData.data.u.st_23_4.repository = *repository;
		return PUS_NO_ERROR;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST23TC(outTc, pusSubtype_NONE))
	{
		return PUS_GET_ERROR();
	}

	if( pus_TC_DATA_ST_23_1 == pus_getTcDataKind(outTc) )
	{
		outTc->data.u.tcData.data.u.st_23_1.repository = *repository;
		return PUS_NO_ERROR;
	}
	if( pus_TC_DATA_ST_23_2_3 == pus_getTcDataKind(outTc) )
	{
		outTc->data.u.tcData.data.u.st_23_2_3.repository = *repository;
		return PUS_NO_ERROR;
	}

	return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
}

pusError_t pus_tc_tm_23_X_getRepositoryPath(pusSt23RepositoryPath_t* repository, const pusPacket_t* outTc)
{
	if( NULL == outTc || NULL == repository )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR == PUS_EXPECT_ST23TM(outTc, pus_TM_1_4_failedStart))
	{
		//TM
		*repository = outTc->data.u.tmData.data.u.st_23_4.repository;
		return PUS_NO_ERROR;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST23TC(outTc, pusSubtype_NONE))
	{
		return PUS_GET_ERROR();
	}

	if( pus_TC_DATA_ST_23_1 == pus_getTcDataKind(outTc) )
	{
		*repository = outTc->data.u.tcData.data.u.st_23_1.repository;
		return PUS_NO_ERROR;
	}
	if( pus_TC_DATA_ST_23_2_3 == pus_getTcDataKind(outTc) )
	{
		*repository = outTc->data.u.tcData.data.u.st_23_2_3.repository;
		return PUS_NO_ERROR;
	}

	return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
}

pusError_t pus_tc_tm_23_1_4_setMaximumSize(pusPacket_t* outTc, pusSt23MaximumSize_t size)
{
	if( NULL == outTc )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR == PUS_EXPECT_ST23TM(outTc, pus_TM_23_4_reportFileAttributes))
	{
		outTc->data.u.tmData.data.u.st_23_4.maxSize = size;
		return PUS_NO_ERROR;
	}
	else if( PUS_NO_ERROR != PUS_EXPECT_ST23TC(outTc, pus_TC_23_1_createFile))
	{
		return PUS_GET_ERROR();
	}
	if( pus_TC_DATA_ST_23_1 != pus_getTcDataKind(outTc) )
	{
		return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
	}

	outTc->data.u.tcData.data.u.st_23_1.maxSize = size;
	return PUS_NO_ERROR;
}

pusError_t pus_tc_tm_23_1_4_getMaximumSize(pusSt23MaximumSize_t* size, const pusPacket_t* outTc)
{
	if( NULL == outTc || NULL == size)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR == PUS_EXPECT_ST23TM(outTc, pus_TM_23_4_reportFileAttributes))
	{
		*size = outTc->data.u.tmData.data.u.st_23_4.maxSize;
		return PUS_NO_ERROR;
	}
	else if( PUS_NO_ERROR != PUS_EXPECT_ST23TC(outTc, pus_TC_23_1_createFile))
	{
		return PUS_GET_ERROR();
	}
	if( pus_TC_DATA_ST_23_1 != pus_getTcDataKind(outTc) )
	{
		return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
	}

	*size = outTc->data.u.tcData.data.u.st_23_1.maxSize;
	return PUS_NO_ERROR;
}

pusError_t pus_tc_23_14_setSourceFileName(pusPacket_t* outTc, const pusSt23FileName_t* fileName)
{
	if( NULL == outTc || NULL == fileName )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST23TC(outTc, pus_TC_23_14_copyFile))
	{
		return PUS_GET_ERROR();
	}
	if( pus_TC_DATA_ST_23_14 != pus_getTcDataKind(outTc) )
	{
		return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
	}

	outTc->data.u.tcData.data.u.st_23_14.sourceFileName = *fileName;
	return PUS_NO_ERROR;
}

pusError_t pus_tc_23_14_getSourceFileName(pusSt23FileName_t* fileName, const pusPacket_t* outTc)
{
	if( NULL == outTc || NULL == fileName)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST23TC(outTc, pus_TC_23_14_copyFile))
	{
		return PUS_GET_ERROR();
	}
	if( pus_TC_DATA_ST_23_14 != pus_getTcDataKind(outTc) )
	{
		return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
	}

	*fileName = outTc->data.u.tcData.data.u.st_23_14.sourceFileName;
	return PUS_NO_ERROR;
}

pusError_t pus_tc_23_14_setTargetFileName(pusPacket_t* outTc, const pusSt23FileName_t* fileName)
{
	if( NULL == outTc || NULL == fileName )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST23TC(outTc, pus_TC_23_14_copyFile))
	{
		return PUS_GET_ERROR();
	}
	if( pus_TC_DATA_ST_23_14 != pus_getTcDataKind(outTc) )
	{
		return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
	}

	outTc->data.u.tcData.data.u.st_23_14.targetFileName = *fileName;
	return PUS_NO_ERROR;
}

pusError_t pus_tc_23_14_getTargetFileName(pusSt23FileName_t* fileName, const pusPacket_t* outTc)
{
	if( NULL == outTc || NULL == fileName )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST23TC(outTc, pus_TC_23_14_copyFile))
	{
		return PUS_GET_ERROR();
	}
	if( pus_TC_DATA_ST_23_14 != pus_getTcDataKind(outTc) )
	{
		return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
	}

	*fileName = outTc->data.u.tcData.data.u.st_23_14.targetFileName;
	return PUS_NO_ERROR;
}


pusError_t pus_tc_23_14_setSourceRepositoryPath(pusPacket_t* outTc, const pusSt23RepositoryPath_t* repository)
{
	if( NULL == outTc || NULL == repository )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST23TC(outTc, pus_TC_23_14_copyFile))
	{
		return PUS_GET_ERROR();
	}
	if( pus_TC_DATA_ST_23_14 != pus_getTcDataKind(outTc) )
	{
		return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
	}

	outTc->data.u.tcData.data.u.st_23_14.sourceRepository = *repository;
	return PUS_NO_ERROR;
}

pusError_t pus_tc_23_14_getSourceRepositoryPath(pusSt23RepositoryPath_t* repository, const pusPacket_t* outTc)
{
	if( NULL == outTc || NULL == repository )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST23TC(outTc, pus_TC_23_14_copyFile))
	{
		return PUS_GET_ERROR();
	}
	if( pus_TC_DATA_ST_23_14 != pus_getTcDataKind(outTc) )
	{
		return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
	}

	*repository = outTc->data.u.tcData.data.u.st_23_14.sourceRepository;
	return PUS_NO_ERROR;
}

pusError_t pus_tc_23_14_setTargetRepositoryPath(pusPacket_t* outTc, const pusSt23RepositoryPath_t* repository)
{
	if( NULL == outTc || NULL == repository )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST23TC(outTc, pus_TC_23_14_copyFile))
	{
		return PUS_GET_ERROR();
	}
	if( pus_TC_DATA_ST_23_14 != pus_getTcDataKind(outTc) )
	{
		return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
	}

	outTc->data.u.tcData.data.u.st_23_14.targetRepository = *repository;
	return PUS_NO_ERROR;
}

pusError_t pus_tc_23_14_getTargetRepositoryPath(pusSt23RepositoryPath_t* repository, const pusPacket_t* outTc)
{
	if( NULL == outTc || NULL == repository)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST23TC(outTc, pus_TC_23_14_copyFile))
	{
		return PUS_GET_ERROR();
	}
	if( pus_TC_DATA_ST_23_14 != pus_getTcDataKind(outTc) )
	{
		return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
	}

	*repository = outTc->data.u.tcData.data.u.st_23_14.targetRepository;
	return PUS_NO_ERROR;
}

//
// Parameter checking
//

pusError_t pus_expectSt23Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTmHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTmService(packet);
		pusSubservice_t subtype = pus_getTmSubtype(packet);

		if (service != pus_ST23_fileManagement)
		{
			pus_setError(PUS_ERROR_TM_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TM_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[23]
			if ((subtype != pus_TM_23_4_reportFileAttributes))
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
		if (kind != pus_TM_DATA_ST_23_4)
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

pusError_t pus_expectSt23Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTcHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTcService(packet);
		pusSubservice_t subtype = pus_getTcSubtype(packet);

		if (service != pus_ST23_fileManagement)
		{
			pus_setError(PUS_ERROR_TC_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TC_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[23]
			if ((subtype != pus_TC_23_1_createFile) &&
				(subtype != pus_TC_23_2_deleteFile) &&
				(subtype != pus_TC_23_3_reportFileAttributes) &&
				(subtype != pus_TC_23_14_copyFile))
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
		if ((kind != pus_TC_DATA_ST_23_1) && (kind != pus_TC_DATA_ST_23_14)
				&& (kind != pus_TC_DATA_ST_23_2_3))
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

