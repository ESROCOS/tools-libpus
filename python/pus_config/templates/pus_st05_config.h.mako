// PUS service ST[05] configuration
// 
// File automatically generated from the pus_st05_config.h.mako template
//
//                     -- DO NOT MODIFY --

#ifndef PUS_ST05_CONFIG_H
#define PUS_ST05_CONFIG_H

#include "pus_error.h"
#include "pus_types.h"
#include "pus_events.h"

<% count = 0 %>
% for param in config['events']:
#define ${param['label']} ((pusSt05EventId_t) ${count}) \
<% count = count + 1 %>
% endfor
#define PUS_ST05_EVENT_BUFFER_LIMIT ((pusSt05EventId_t) ${count})


//! Destination for ST05 reports
extern const pusApid_t pus_st05_eventReportDestination;

//! Event information list
extern pusSt05EventInfo_t pus_st05_eventInfoList[];

//! Size of the event information list
extern const size_t pus_st05_eventInfoListLength;

//! Event circular buffer
extern pusSt05EventInBuffer_t pus_st05_eventBuffer[];

//! Size of the event circular buffer
extern const size_t pus_st05_eventBufferLength;

//! Initialize the configuration of the ST[05] service from the mission database
pusError_t pus_events_configure();






#endif