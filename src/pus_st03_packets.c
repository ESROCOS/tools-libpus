/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */


#include "pus_st03_packets.h"

#ifdef PUS_CONFIGURE_ST03_ENABLED

// Mutex defined in pus_housekeeping.c
extern pusMutex_t* pus_hk_mutex;

// Array for parameters values (all stored in 64 bits)
extern pusStoredParam_t pus_st03_params[];

extern pusError_t pus_hk_getReportParams(pusSt03HousekeepingReportId_t reportId, size_t *numParams, pusSt03ParamId_t* paramIds);

//
// Packet creation
//

/*! Builds a TC[3,5] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] sequenceCount sequence number
 *  \param[in] reportId HK report ID
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_3_5_createEnableHousekeepingGeneration(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt03HousekeepingReportId_t reportId)
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
		pus_setTcService(outTc, pus_ST03_housekeeping);
		pus_setTcSubtype(outTc, pus_TC_3_5_enablePeriodicHousekeeping);
		pus_setTcSource(outTc, apid);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_3_5);
		outTc->data.u.tcData.data.u.st_3_5.reportId = reportId;

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusError_t pus_tc_3_5_setReportId(pusPacket_t* outTc, pusSt03HousekeepingReportId_t reportId)
{
	if (NULL == outTc)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_NO_ERROR == PUS_EXPECT_ST03TC(outTc, pus_TC_3_5_enablePeriodicHousekeeping))
	{
		outTc->data.u.tcData.data.u.st_3_5.reportId = reportId;
		return PUS_NO_ERROR;
	}

	return PUS_GET_ERROR();
}

pusSt03HousekeepingReportId_t pus_tc_3_5_getReportId(const pusPacket_t* outTc)
{
	if (NULL == outTc)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_NO_ERROR == PUS_EXPECT_ST03TC(outTc, pus_TC_3_5_enablePeriodicHousekeeping))
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
		return outTc->data.u.tcData.data.u.st_3_5.reportId;
	}

	return 0;
}

/*! Builds a TC[3,6] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] sequenceCount sequence number
 *  \param[in] reportId HK report ID
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_3_6_createDisableHousekeepingGeneration(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt03HousekeepingReportId_t reportId)
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
		pus_setTcService(outTc, pus_ST03_housekeeping);
		pus_setTcSubtype(outTc, pus_TC_3_6_disablePeridodicHousekeeping);
		pus_setTcSource(outTc, apid);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_3_6);
		outTc->data.u.tcData.data.u.st_3_6.reportId = reportId;

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusError_t pus_tc_3_6_setReportId(pusPacket_t* outTc, pusSt03HousekeepingReportId_t reportId)
{
	if (NULL == outTc)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_NO_ERROR == PUS_EXPECT_ST03TC(outTc, pus_TC_3_6_disablePeridodicHousekeeping))
	{
		outTc->data.u.tcData.data.u.st_3_6.reportId = reportId;
		return PUS_NO_ERROR;
	}
	return PUS_GET_ERROR();
}

pusSt03HousekeepingReportId_t pus_tc_3_6_getReportId(const pusPacket_t* outTc)
{
	if (NULL == outTc)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_NO_ERROR == PUS_EXPECT_ST03TC(outTc, pus_TC_3_6_disablePeridodicHousekeeping))
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
		return outTc->data.u.tcData.data.u.st_3_6.reportId;
	}

	return 0;
}

pusError_t pus_tm_3_25_createHousekeepingReportDefault(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination)
{
	return pus_tm_3_25_createHousekeepingReport(outTm, apid, sequenceCount, pus_ST03_DEFAULT_HK_REPORT, destination);
}

pusError_t pus_tm_3_25_createHousekeepingReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt03HousekeepingReportId_t reportId, pusApid_t destination)
{
	if (NULL == outTm)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	// Build the TM packet
	pus_clearError();
	pus_initTmPacket(outTm);
	pus_setTmDataKind(outTm, pus_TM_DATA_ST_3_25);

	// Source information
	pus_setApid(outTm, apid);
	pus_setSequenceCount(outTm, sequenceCount);

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
	size_t numParams = 0;
	pusSt03ParamId_t paramIds[20] = {0};
	if (pus_hk_getReportParams(reportId, &numParams, paramIds) == PUS_NO_ERROR)
	{
		pus_tm_3_25_setReportId(outTm, reportId);
		pus_tm_3_25_setNumParameters(outTm, numParams);
	}
	else
	{
		return PUS_SET_ERROR(PUS_ERROR_REPORT_ID_UNKNOWN);
	}

	return PUS_GET_ERROR();
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

pusError_t pus_tm_3_25_setParameterValues(pusPacket_t* outTm, pusSt03HousekeepingReportId_t reportId)
{
	if (NULL == outTm )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if (PUS_NO_ERROR != PUS_EXPECT_ST03(outTm, pus_TM_3_25_housekeepingReport))
	{
		return PUS_GET_ERROR();
	}

	// Get the array defining the report contents
	size_t numParams = 0;
	pusSt03ParamId_t paramIds[20] = {0};
	if (pus_hk_getReportParams(reportId, &numParams, paramIds) != PUS_NO_ERROR)
	{
		return PUS_SET_ERROR(PUS_ERROR_REPORT_ID_UNKNOWN);
	}

	if (numParams > pus_ST03_MAX_REPORT_LENGTH)
	{
		return PUS_SET_ERROR(PUS_ERROR_REPORT_LENGTH);
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

pusError_t pus_tm_3_25_setParameterValue(pusPacket_t* tm, size_t index, pusStoredParam_t inValue)
{
	if ( NULL == tm )
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

	tm->data.u.tmData.data.u.st_3_25.parameters.arr[index] = inValue;

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

pusError_t pus_tm_3_25_setNumParameters(pusPacket_t* tm, size_t inNumParams)
{
	if (NULL == tm)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if (PUS_NO_ERROR != PUS_EXPECT_ST03(tm, pus_TM_3_25_housekeepingReport))
	{
		return PUS_GET_ERROR();
	}

	tm->data.u.tmData.data.u.st_3_25.parameters.nCount = inNumParams;

	return PUS_NO_ERROR;
}

//
// Parameter checking
//

pusError_t pus_expectSt03Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTcHeader(packet, function, (pusErrorData_t){.integer=0});

	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTcService(packet);
		pusSubservice_t subtype = pus_getTcSubtype(packet);

		if (service != pus_ST03_housekeeping)
		{
			pus_setError(PUS_ERROR_TC_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TC_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			if ((subtype != pus_TC_3_5_enablePeriodicHousekeeping) && 
				(subtype != pus_TC_3_6_disablePeridodicHousekeeping))
			{
				pus_setError(PUS_ERROR_TC_SUBTYPE, function, (pusErrorData_t){.integer=subtype});
				return PUS_ERROR_TC_SUBTYPE;
			}
		}
		else
		{
			if (subtype != expectedSubtype)
			{
				pus_setError(PUS_ERROR_TC_SUBTYPE, function, (pusErrorData_t){.integer=subtype});
				return PUS_ERROR_TC_SUBTYPE;

			}
		}

		pusPacketDataKind_t kind = pus_getTcDataKind(packet);
		if((kind != pus_TC_DATA_ST_3_5) &&
			(kind != pus_TC_DATA_ST_3_6))
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

#endif
