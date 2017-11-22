
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


// PUS service ST[05] configuration
// 
// File automatically generated from the pus_st05_config.h.mako template
//
//                     -- DO NOT MODIFY --

#include "pus_st05_config.h"

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
    <%
    tempvars['eventCount'] = tempvars['eventCount'] + 1 
	%>
	% endfor
	
	return PUS_NO_ERROR;
}
