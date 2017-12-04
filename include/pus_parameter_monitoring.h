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


typedef struct{
	bool checking_status;
		// LIMIT: unchecked, invalid, within limits, below low limit, above high limit
		// EXPECT: unchecked, invalid, expected value, unexpected value
	int repetition; //repetition number
	int check_type; //limit, expect, delta //TODO ENUM?

	//limit:
	int low_limit;
	int max_limit;

	//expect:
	int expected;
	int mask;

	//delta:

}pusSt12CheckDefinition;

typedef struct{
	// pmon id -> array index;
	// param id -> array index (1 pmon per param)
	bool status; //conditional checking; TODO defines ASN1?
	pusSt12CheckDefinition check;
}pusSt12PmonDefinition;


bool pus_pmon_functionStatus = false;


//from config
extern pusSt12PmonDefinition pus_pmon_definitionList[];



#ifdef  __cplusplus
}
#endif

#endif
