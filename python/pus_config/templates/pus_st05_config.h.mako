// PUS service ST[05] configuration
// 
// File automatically generated from the pus_st05_config.h.mako template
//
//                     -- DO NOT MODIFY --

#ifndef PUS_ST03_CONFIG_H
#define PUS_ST03_CONFIG_H

#include "pus_error.h"
#include "pus_types.h"
#include "pus_events.h"




//! Destination for ST05 reports
extern const pusApid_t eventDestination;

//! Size of the event buffer
extern const size_t eventBufferLength;

//! Event information list
extern const pusSt05EventInfo_t eventInfoList[];

//! Initialize the configuration of the ST[05] service from the mission database
pusError_t pus_events_configure();






#endif