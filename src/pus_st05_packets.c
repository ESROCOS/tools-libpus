/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */


#include "pus_st05_packets.h"
#ifdef PUS_CONFIGURE_ST05_ENABLED



pusError_t pus_tm_5_X_createEventReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusSt05Event_t* event, pusApid_t destination, pusSubservice_t subtype)
{

	if (NULL == outTm || NULL == event)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (!pus_events_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else
	{
		pus_clearError();
		//create package
		pus_initTmPacket(outTm);

		// Source information
		pus_setApid(outTm, apid);
		pus_setSequenceCount(outTm, sequenceCount);

		// Data length
		pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

		// Service identification
		pus_setTmService(outTm, pus_ST05_eventReporting);
		pus_setTmSubtype(outTm, subtype);

		// Timestamp
		pus_setTmPacketTimeNow(outTm);

		// Destination
		pus_setTmDestination(outTm, destination);

		//data field
		pus_setTmDataKind(outTm, pus_TM_DATA_ST_5_X);
		pus_tm_5_X_setTmEventReportData(outTm, event);


		return PUS_GET_ERROR();
	}
}


pusError_t pus_tm_5_1_createInformativeEventReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusSt05Event_t* event, pusApid_t destination)
{
	if (NULL == outTm || NULL == event)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_IS_ERROR())
	{
		return PUS_ERROR_BEFORE;
	}
	else
	{
		return pus_tm_5_X_createEventReport(outTm, apid, sequenceCount, event, destination, pus_TM_5_1_eventInformative);
	}
}

pusError_t pus_tm_5_2_createLowSeverityEventReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusSt05Event_t* event, pusApid_t destination)
{
	if (NULL == outTm || NULL == event)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_IS_ERROR())
	{
		return PUS_ERROR_BEFORE;
	}
	else
	{
		return pus_tm_5_X_createEventReport(outTm, apid, sequenceCount, event, destination, pus_TM_5_2_anomalyLowSeverity);
	}
}


pusError_t pus_tm_5_3_createMediumSeverityEventReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusSt05Event_t* event, pusApid_t destination)
{
	if (NULL == outTm || NULL == event)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_IS_ERROR())
	{
		return PUS_ERROR_BEFORE;
	}
	else
	{
		return pus_tm_5_X_createEventReport(outTm, apid, sequenceCount, event, destination, pus_TM_5_3_anomalyMediumSeverity);
	}
}

pusError_t pus_tm_5_4_createHighSeverityEventReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusSt05Event_t* event, pusApid_t destination)
{
	if (NULL == outTm || NULL == event)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_IS_ERROR())
	{
		return PUS_ERROR_BEFORE;
	}
	else
	{
		return pus_tm_5_X_createEventReport(outTm, apid, sequenceCount, event, destination, pus_TM_5_4_anomalyHighSeverity);
	}
}




pusError_t pus_tm_5_X_setTmEventReportData(pusPacket_t* outTm, const pusSt05Event_t* event)
{
	if (NULL == outTm|| NULL == event)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if( PUS_NO_ERROR != PUS_EXPECT_ST05(outTm, pusSubtype_NONE))
	{
		return PUS_GET_ERROR();
	}
	{
		outTm->data.u.tmData.data.u.st_5_X.eventId = event->eventId;
		outTm->data.u.tmData.data.u.st_5_X.data = event->data;
		return PUS_NO_ERROR;
	}
}

pusError_t pus_tm_5_X_getTmEventReportData(const pusPacket_t* outTm, pusSt05Event_t* event)
{

	if (NULL == outTm|| NULL == event)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if( PUS_NO_ERROR != PUS_EXPECT_ST05(outTm, pusSubtype_NONE))
	{
		return PUS_GET_ERROR();
	}
	else
	{
		event->eventId = outTm->data.u.tmData.data.u.st_5_X.eventId;
		event->data = outTm->data.u.tmData.data.u.st_5_X.data;
		return PUS_NO_ERROR;
	}
}

//
// Parameter checking
//

pusError_t pus_expectSt05Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTmHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTmService(packet);
		pusSubservice_t subtype = pus_getTmSubtype(packet);

		if (service != pus_ST05_eventReporting)
		{
			pus_setError(PUS_ERROR_TM_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TM_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[05]
			if ((subtype != pus_TM_5_1_eventInformative) &&
				(subtype != pus_TM_5_2_anomalyLowSeverity) &&
				(subtype != pus_TM_5_3_anomalyMediumSeverity) &&
				(subtype != pus_TM_5_4_anomalyHighSeverity))
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
		if (kind != pus_TM_DATA_ST_5_X)
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
