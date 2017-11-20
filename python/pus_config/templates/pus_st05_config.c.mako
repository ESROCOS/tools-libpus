
<%

# Reports' destination
tempvars['reportsDestination'] = config['eventReportDestination']

# Event buffer length
tempvars['eventBufferLength'] = config['eventBufferLength']

# Counters for adding to arrays
tempvars['eventCount'] = len(config['events'])
tempvars['eventList'] = config['events']

%>


// PUS service ST[03] configuration
// 
// File automatically generated from the pus_st30_config.h.mako template
//
//                     -- DO NOT MODIFY --

#include "pus_st05_config.h"

const pusApid_t eventReportDestination = ${tempvars['reportsDestination']};

const size_t eventBufferLength = ${tempvars['eventBufferLength']};

// countEvent: ${tempvars['eventCount']},  

pusError_t pus_events_configure()
{


	return PUS_NO_ERROR;
}
