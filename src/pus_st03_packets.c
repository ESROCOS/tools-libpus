#include "pus_threads.h"
#include "pus_error.h"
#include "pus_packet.h"
#include <string.h>
#include "pus_st03_packets.h"

// Mutex defined in pus_housekeeping.c
extern pusMutex_t* pus_hk_mutex;

// Array for parameters values (all stored in 64 bits)
extern pusStoredParam_t pus_st03_params[];

// Structure of the default HK report
extern pusSt03ReportInfo_t pus_st03_defaultHkReportInfo;


//
// Packet creation
//

pusError_t pus_tm_3_25_createHousekeepingReportDefault(pusPacket_t* outTm, pusApidInfo_t* apid, pusApid_t destination)
{
	return pus_tm_3_25_createHousekeepingReport(outTm, apid, pus_ST03_DEFAULT_HK_REPORT, destination);
}

pusError_t pus_tm_3_25_createHousekeepingReport(pusPacket_t* outTm, pusApidInfo_t* apid, pusSt03HousekeepingReportId_t reportId, pusApid_t destination)
{
	size_t numParams = 0;
	pusSt03ParamId_t* paramIds;

	if (NULL == outTm || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if (PUS_IS_ERROR())
	{
		return PUS_ERROR_BEFORE;
	}

	if (!pus_hk_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}

	// Get the array defining the report contents
	if (pus_ST03_DEFAULT_HK_REPORT == reportId)
	{
		numParams = pus_st03_defaultHkReportInfo.numParams;
		paramIds = pus_st03_defaultHkReportInfo.paramIds;
	}
	// handle here user-defined HK reports (not yet implemented)
	else
	{
		return PUS_SET_ERROR(PUS_ERROR_REPORT_ID_UNKNOWN);
	}

	if (numParams > pus_ST03_MAX_REPORT_LENGTH)
	{
		return PUS_SET_ERROR(PUS_ERROR_REPORT_LENGTH);
	}

	// Build the TM packet

	pus_initTmPacket(outTm);
	pus_setTmDataKind(outTm, pus_TM_DATA_ST_3_25);

	// Source information
	pus_setApid(outTm, pus_getInfoApid(apid));
	pus_setSequenceCount(outTm, pus_getNextPacketCount(apid));

	// Data length
	pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

	// Service identification
	pus_setTmService(outTm, pus_ST03_housekeeping);
	pus_setTmSubtype(outTm, pus_TM_3_25_housekeepingReport);

	// Destination
	pus_setTmDestination(outTm, destination);

	// Timestamp
	pus_setTmPacketTimeNow(outTm);

	// Report contents
	pus_tm_3_25_setReportId(outTm, reportId);
	return (pus_tm_3_25_setParameterValues(outTm, paramIds, numParams));
}


//
// Packet field getters and setters
//

pusSt03HousekeepingReportId_t pus_tm_3_25_getReportId(const pusPacket_t* tm)
{
	if (NULL == tm)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	else if (PUS_NO_ERROR != PUS_EXPECT_ST03(tm, pus_TM_3_25_housekeepingReport))
	{
		return 0;
	}
	else
	{
		return tm->data.u.tmData.data.u.st_3_25.reportId;
	}
}

void pus_tm_3_25_setReportId(pusPacket_t* outTm, pusSt03HousekeepingReportId_t reportId)
{
	if (NULL == outTm)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return;
	}
	else if (PUS_NO_ERROR == PUS_EXPECT_ST03(outTm, pus_TM_3_25_housekeepingReport))
	{
		outTm->data.u.tmData.data.u.st_3_25.reportId = reportId;
	}
}

pusError_t pus_tm_3_25_setParameterValues(pusPacket_t* outTm, const pusSt03ParamId_t* paramIds, size_t numParams)
{
	if (NULL == outTm || NULL == paramIds)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if (numParams > pus_ST03_MAX_REPORT_LENGTH)
	{
		return PUS_SET_ERROR(PUS_ERROR_REPORT_LENGTH);
	}

	if (PUS_NO_ERROR != PUS_EXPECT_ST03(outTm, pus_TM_3_25_housekeepingReport))
	{
		return PUS_GET_ERROR();
	}

	// Lock access parameters array
	if (NULL != pus_hk_mutex && !pus_mutexLockOk(pus_hk_mutex))
	{
		return PUS_ERROR_THREADS;
	}

	// Copy parameter values to the packet
	for (uint32_t i = 0; i < numParams; i++)
	{
		outTm->data.u.tmData.data.u.st_3_25.parameters.arr[i] = pus_st03_params[paramIds[i]];
	}

	// Set number of parameters in packet
	outTm->data.u.tmData.data.u.st_3_25.parameters.nCount = numParams;

	// Unlock access to parameters array
	if (NULL != pus_hk_mutex && !pus_mutexUnlockOk(pus_hk_mutex))
	{
		return PUS_ERROR_THREADS;
	}

	return PUS_NO_ERROR;
}

pusError_t pus_tm_3_25_getParameterValue(const pusPacket_t* tm, size_t index, pusStoredParam_t* outValue)
{
	if (NULL == tm || NULL == outValue)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if (PUS_NO_ERROR != PUS_EXPECT_ST03(tm, pus_TM_3_25_housekeepingReport))
	{
		return PUS_GET_ERROR();
	}

	// Check against maximum and actual size of the packet
	if (index > (size_t)pus_ST03_MAX_REPORT_LENGTH || index > (size_t)tm->data.u.tmData.data.u.st_3_25.parameters.nCount)
	{
		return PUS_SET_ERROR(PUS_ERROR_REPORT_LENGTH);
	}

	*outValue = tm->data.u.tmData.data.u.st_3_25.parameters.arr[index];

	return PUS_NO_ERROR;
}

pusError_t pus_tm_3_25_getNumParameters(const pusPacket_t* tm, size_t* outNumParams)
{
	if (NULL == tm || NULL == outNumParams)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if (PUS_NO_ERROR != PUS_EXPECT_ST03(tm, pus_TM_3_25_housekeepingReport))
	{
		return PUS_GET_ERROR();
	}

	*outNumParams = (size_t)tm->data.u.tmData.data.u.st_3_25.parameters.nCount;

	return PUS_NO_ERROR;
}


//
// Parameter checking
//

pusError_t pus_expectSt03Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTmHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTmService(packet);
		pusSubservice_t subtype = pus_getTmSubtype(packet);

		if (service != pus_ST03_housekeeping)
		{
			pus_setError(PUS_ERROR_TM_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TM_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[01]
			if ((subtype != pus_TM_3_25_housekeepingReport))
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
		if (kind != pus_TM_DATA_ST_3_25)
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

