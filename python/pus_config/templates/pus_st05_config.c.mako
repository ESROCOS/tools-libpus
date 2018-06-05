<%
# Reports' destination
tempvars['reportsDestination'] = config['eventReportDestination']

# Event buffer length
tempvars['eventBufferLength'] = config['eventBufferLength']

# Counters for adding to arrays
tempvars['eventListLength'] = len(config['events'])
tempvars['eventList'] = config['events']

tempvars['eventCount'] = 0


%>
//
// H2020 ESROCOS Project
// Company: GMV Aerospace & Defence S.A.U.
// Licence: GPLv2
//
// PUS service ST[05] configuration
// 
// File automatically generated from the pus_st05_config.h.mako template
//
//                     -- DO NOT MODIFY --


#include "pus_st05_config.h"
#ifdef PUS_CONFIGURE_EVENTS_TABLE

#include "pus_stored_param.h" 



const pusApid_t pus_st05_eventReportDestination = ${tempvars['reportsDestination']};


pusSt05EventInfo_t pus_st05_eventInfoList[${tempvars['eventListLength']}];

const size_t pus_st05_eventInfoListLength = PUS_ST05_EVENT_BUFFER_LIMIT;


pusSt05EventInBuffer_t pus_st05_eventBuffer[${tempvars['eventBufferLength']}];

const size_t pus_st05_eventBufferLength = ${tempvars['eventBufferLength']};


pusError_t pus_events_configure()
{
	% for event in tempvars['eventList']:
    pus_st05_eventInfoList[${event['label']}].label = "${event['label']}";
    pus_st05_eventInfoList[${event['label']}].defaultSeverity = PUS_ST05_SEVERITY_${event['defaultSeverity']};
    pus_st05_eventInfoList[${event['label']}].data.dataType1 = PUS_${event['data'][0]};
    pus_st05_eventInfoList[${event['label']}].data.dataType2 = PUS_${event['data'][1]};
    
	% endfor
	
	return PUS_NO_ERROR;
}

% for event in config['events']:
pusError_t pus_events_create${event['label']}(pusSt05Event_t* event, ${event['data'][0]} data1, ${event['data'][1]} data2)
{
	event->eventId = ${event['label']};
	//memcpy(&event->data.data1, &data1, sizeof(${event['data'][0]}));
	//memcpy(&event->data.data2, &data2, sizeof(${event['data'][1]}));
	
	%if str(event['data'][0]) == str("INT32"):
	pus_int32ToParam(&event->data.data1, data1);
	%elif str(event['data'][0]) == str("UINT32"):
	pus_uint32ToParam(&event->data.data1, data1);
	%elif str(event['data'][0]) == str("REAL64"):
	pus_real64ToParam(&event->data.data1, data1);
	%elif str(event['data'][0]) == str("BYTE"):
	pus_byteToParam(&event->data.data1, data1);
	%elif str(event['data'][0]) == str("BOOL"):
	pus_boolToParam(&event->data.data1, data1);
	%else:
	return PUS_ERROR_NOT_IMPLEMENTED;
	%endif
	
	%if str(event['data'][1]) == str("INT32"):
	pus_int32ToParam(&event->data.data2, data2);
	%elif str(event['data'][1]) == str("UINT32"):
	pus_uint32ToParam(&event->data.data2, data2);
	%elif str(event['data'][1]) == str("REAL64"):
	pus_real64ToParam(&event->data.data2, data2);
	%elif str(event['data'][1]) == str("BYTE"):
	pus_byteToParam(&event->data.data2, data2);
	%elif str(event['data'][1]) == str("BOOL"):
	pus_boolToParam(&event->data.data2, data2);
	%else:
	return PUS_ERROR_NOT_IMPLEMENTED;
	%endif
	
	
	return PUS_NO_ERROR;
}

% endfor


#endif
