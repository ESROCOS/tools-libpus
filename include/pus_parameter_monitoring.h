//TODO header

#ifndef PUS_PARAMETER_MONITORING_H
#define PUS_PARAMETER_MONITORING_H

#ifdef  __cplusplus
extern "C" {
#endif

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_threads.h"
#include "pus_types.h"
#include "pus_packet.h"
#include "pus_stored_param.h"


typedef struct{
	//bool checking_status;
	//int repetition; //repetition number
	//int check_type; //limit, expect, delta //TODO ENUM?
	union u2
	{
		int32_t INT32;
		uint32_t UINT32;
		double REAL64;
		bool BOOL;
		byte BYTE;
	}low_limit;
	union u
	{
		int32_t INT32;
		uint32_t UINT32;
		double REAL64;
		bool BOOL;
		byte BYTE;
	}high_limit;
	//int expected;
	//int mask;
}pusSt12CheckDefinition;

typedef struct{
	// pmon id -> array index;
	// param id -> array index (1 pmon per param)
	bool status;
	pusSt12CheckDefinition check;
}pusSt12PmonDefinition;


bool pus_pmon_functionStatus = false;


//from config
extern pusSt12PmonDefinition pus_pmon_definitionList[];



#ifdef  __cplusplus
}
#endif

#endif
