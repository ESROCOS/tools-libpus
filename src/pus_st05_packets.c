#include "pus_threads.h"
#include "pus_error.h"
#include "pus_packet.h"
//#include "pus_types.h"
#include "pus_stored_param.h"
//#include <string.h>
#include "pus_st05_packets.h"


//idk
#include "pus_events.h"


pusError_t pus_tm_5_X_createEventReport(pusPacket_t* outTm, pusApidInfo_t* apid, pusSt05Event_t* event, pusApid_t destination, pusSubservice_t subtype)
{

	if (NULL == outTm || NULL == apid || NULL == event)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (!pus_events_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else
	{
		//create package
		pus_initTmPacket(outTm);
		pus_setTmDataKind(outTm, pus_TM_DATA_ST_5_X);

		// Source information
		pus_setApid(outTm, pus_getInfoApid(apid));
		pus_setSequenceCount(outTm, pus_getNextTmCount(apid));

		// Data length
		pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

		// Service identification
		pus_setTmService(outTm, pus_ST05_eventReporting);
		pus_setTmSubtype(outTm, subtype);

		// Timestamp
		pus_setTmPacketTimeNow(outTm);

		// Destination
		pus_setTmDestination(outTm, destination);
		/* The destination of the event reports generated by the event reporting subservice shall be declared when specifying that subservice.
			NOTE All the event reports generated by an event reporting subservice have the same destination.
		*/

		pus_tm_5_X_setTmEventReportData(outTm, event);


		return PUS_GET_ERROR();
	}
}


pusError_t pus_tm_5_1_createInformativeEventReport(pusPacket_t* outTm, pusApidInfo_t* apid, pusSt05Event_t* event, pusApid_t destination)
{
	if (NULL == outTm || NULL == apid || NULL == event)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_IS_ERROR())
	{
		return PUS_ERROR_BEFORE;
	}
	else
	{
		return pus_tm_5_X_createEventReport(outTm, apid, event, destination, pus_TM_5_1_eventInformative);
	}
}

pusError_t pus_tm_5_2_createLowSeverityEventReport(pusPacket_t* outTm, pusApidInfo_t* apid, pusSt05Event_t* event, pusApid_t destination)
{
	if (NULL == outTm || NULL == apid || NULL == event)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_IS_ERROR())
	{
		return PUS_ERROR_BEFORE;
	}
	else
	{
		return pus_tm_5_X_createEventReport(outTm, apid, event, destination, pus_TM_5_2_anomalyLowSeverity);
	}
}


pusError_t pus_tm_5_3_createMediumSeverityEventReport(pusPacket_t* outTm, pusApidInfo_t* apid, pusSt05Event_t* event, pusApid_t destination)
{
	if (NULL == outTm || NULL == apid || NULL == event)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_IS_ERROR())
	{
		return PUS_ERROR_BEFORE;
	}
	else
	{
		return pus_tm_5_X_createEventReport(outTm, apid, event, destination, pus_TM_5_3_anomalyMediumSeverity);
	}
}

pusError_t pus_tm_5_4_createHighSeverityEventReport(pusPacket_t* outTm, pusApidInfo_t* apid, pusSt05Event_t* event, pusApid_t destination)
{
	if (NULL == outTm || NULL == apid || NULL == event)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_IS_ERROR())
	{
		return PUS_ERROR_BEFORE;
	}
	else
	{
		return pus_tm_5_X_createEventReport(outTm, apid, event, destination, pus_TM_5_4_anomalyHighSeverity);
	}
}

// Getters/Setters pusSt05Event_t
pusSt05EventId_t pus_tm_5_X_getEventId(const pusSt05Event_t* event)
{
	if (NULL == event)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return pus_EVENT_ID_NONE;
	}
	else
	{
		return event->eventId;
	}
}

void pus_tm_5_X_setEventId(pusSt05Event_t* event, pusSt05EventId_t eventId)
{
	if (NULL == event)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return;
	}
	else
	{
		event->eventId = eventId;
	}
}


pusSt05EventAuxData_t pus_tm_5_X_getEventAuxData(const pusSt05Event_t* event)
{
	if (NULL == event)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return pus_EVENT_AUXDATA_NONE;
	}
	else
	{
		return event->data;
	}
}

void pus_tm_5_X_setEventAuxData(pusSt05Event_t* event, pusSt05EventAuxData_t data)
{
	if (NULL == event)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return;
	}
	else
	{
		event->data = data;
	}
}


pusStoredParam_t pus_tm_5_X_getEventAuxData1(const pusSt05EventAuxData_t* data)
{
	if (NULL == data)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return pus_EVENT_DATASTORED_NONE;
	}
	else
	{
		return data->data1;
	}
}

void pus_tm_5_X_setEventAuxData1(pusSt05EventAuxData_t* data, pusStoredParam_t data1)
{
	if (NULL == data)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return;
	}
	else
	{
		data->data1 = data1;
	}
}

pusStoredParam_t pus_tm_5_X_getEventAuxData2(const pusSt05EventAuxData_t* data)
{
	if (NULL == data)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return pus_EVENT_DATASTORED_NONE;
	}
	else
	{
		return data->data2;
	}
}

void pus_tm_5_X_setEventAuxData2(pusSt05EventAuxData_t* data, pusStoredParam_t data2)
{
	if (NULL == data)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return;
	}
	data->data2 = data2;
}


pusError_t pus_tm_5_X_setTmEventReportData(pusPacket_t* outTm, pusSt05Event_t* event)
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
