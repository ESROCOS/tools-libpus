// PUS service ST[05] configuration
// 
// File automatically generated from the pus_st05_config.h.mako template
//
//                     -- DO NOT MODIFY --

#ifndef PUS_ST05_CONFIG_H
#define PUS_ST05_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif



#include "pus_error.h"
#include "pus_types.h"
#include "pus_events.h"

#include "pus_st03_config.h" //TODO cambiar tipos
#include "pus_stored_param.h" 

<% count = 0 %>
% for event in config['events']:
#define ${event['label']} ((pusSt05EventId_t) ${count}) \
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


% for event in config['events']:
//! Function that create a ${event['label']} event
pusError_t pus_events_create${event['label']}(pusSt05Event_t* event, ${event['data'][0]} data1, ${event['data'][1]} data2);

% endfor

#ifdef __cplusplus
}
#endif



#endif