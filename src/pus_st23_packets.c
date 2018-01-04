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

pusError_t pus_tc_23_1_createCreateFileRequest(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
	if ( NULL == outTm )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	pusError_t error = pus_tc_23_X_createDefaultRequest(outTm, apid, sequenceCount, pus_TC_23_1_createFile);
	if( PUS_NO_ERROR != error )
	{
		return PUS_GET_ERROR();
	}

	//Set data field
	//pus_setTcDataKind(outTm, kind);

	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_23_2_createDeleteFileRequest(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
	if ( NULL == outTm )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	pusError_t error = pus_tc_23_X_createDefaultRequest(outTm, apid, sequenceCount, pus_TC_23_2_deleteFile);
	if( PUS_NO_ERROR != error )
	{
		return PUS_GET_ERROR();
	}

	//Set data field
	//pus_setTcDataKind(outTm, kind);

	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_23_3_createReportFileAtributesRequest(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
	if ( NULL == outTm )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	pusError_t error = pus_tc_23_X_createDefaultRequest(outTm, apid, sequenceCount, pus_TC_23_3_reportFileAttributes);
	if( PUS_NO_ERROR != error )
	{
		return PUS_GET_ERROR();
	}

	//Set data field
	//pus_setTcDataKind(outTm, kind);

	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tm_23_4_createReportFileAtributesReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination)
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
		pus_setTmService(outTm, pus_ST23_fileManagement);
		pus_setTmSubtype(outTm, pus_TM_23_4_reportFileAttributes);
		pus_setTmDestination(outTm, destination);

		// Timestamp
		pus_setTmPacketTimeNow(outTm);

		// Set data field
		//pus_setTmDataKind(outTm, kind);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusError_t pus_tc_23_14_createCopyFileRequest(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
	if ( NULL == outTm )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	pusError_t error = pus_tc_23_X_createDefaultRequest(outTm, apid, sequenceCount, pus_TC_23_14_copyFile);
	if( PUS_NO_ERROR != error )
	{
		return PUS_GET_ERROR();
	}

	//Set data field
	//pus_setTcDataKind(outTm, kind);

	return PUS_SET_ERROR(PUS_NO_ERROR);
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

		/*pusPacketDataKind_t kind = pus_getTmDataKind(packet);
		if (kind != pus_TM_DATA_ST_20_2)
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

		/*pusPacketDataKind_t kind = pus_getTcDataKind(packet);
		if (kind != pus_TC_DATA_ST_20_X)
		{
			pus_setError(PUS_ERROR_TC_KIND, function, (pusErrorData_t){.integer=kind});
			return PUS_ERROR_TC_KIND;
		}*/

		return PUS_NO_ERROR;
	}
	else
	{
		return expectResult;
	}
}

