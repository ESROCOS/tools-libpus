
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


// PUS service ST[03] configuration
// 
// File automatically generated from the pus_st30_config.h.mako template
//
//                     -- DO NOT MODIFY --

#include "pus_st05_config.h"

const pusApid_t pus_st05_eventReportDestination = ${tempvars['reportsDestination']};

size_t pus_st05_eventBufferLength = ${tempvars['eventBufferLength']};

pusSt05EventInfo_t pus_st05_eventInfoList[${tempvars['eventListLength']}];


pusError_t pus_events_configure()
{
	% for event in tempvars['eventList']:
    pus_st05_eventInfoList[${tempvars['eventCount']}].label = "${event['label']}";
    pus_st05_eventInfoList[${tempvars['eventCount']}].defaultSeverity = PUS_ST05_SEVERITY_${event['defaultSeverity']};
    pus_st05_eventInfoList[${tempvars['eventCount']}].data.dataType1 = PUS_${event['data'][0]};
    pus_st05_eventInfoList[${tempvars['eventCount']}].data.dataType2 = PUS_${event['data'][1]};
    <%
    tempvars['eventCount'] = tempvars['eventCount'] + 1 
	%>
	% endfor
	
	return PUS_NO_ERROR;
}
