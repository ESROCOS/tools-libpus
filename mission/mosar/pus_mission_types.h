/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */
 
#ifndef PUS_MISSION_SERVICES
#define PUS_MISSION_SERVICES

//Headers includes of the ASN1 types
#if(!defined(GENERATED_ASN1SCC_DATAVIEW_UNIQ_H) && !defined(GENERATED_ASN1SCC_dataview_uniq_H))
#include "pus_st200.h"
#endif


#ifdef  __cplusplus
extern "C" {
#endif

// ST200: Timeline control 

typedef asn1SccPusTM_200_2_Data pusSt200_2_Observation; //!< Planner observation ID
 

typedef asn1SccPusTC_200_3_Data pusSt200_3_Goal; //!< Mission goal ID 

typedef asn1SccPusTM_200_4_Data pusSt200_4_Observation; //!< Mission observation ID
 

typedef asn1SccPusTC_200_5_Data pusSt200_5_Goal; //!< Hotdockcmd goal ID 

typedef asn1SccPusTM_200_6_Data pusSt200_6_Observation; //!< Hotdockcmd observation ID
 

typedef asn1SccPusTM_200_8_Data pusSt200_8_Observation; //!< Hotdockstatus observation ID
 

typedef asn1SccPusTC_200_9_Data pusSt200_9_Goal; //!< Wmcmd goal ID 

typedef asn1SccPusTM_200_10_Data pusSt200_10_Observation; //!< Wmcmd observation ID
 

typedef asn1SccPusTC_200_11_Data pusSt200_11_Goal; //!< Basecmd goal ID 

typedef asn1SccPusTM_200_12_Data pusSt200_12_Observation; //!< Basecmd observation ID
 

typedef asn1SccPusTC_200_13_Data pusSt200_13_Goal; //!< Efcmd goal ID 

typedef asn1SccPusTM_200_14_Data pusSt200_14_Observation; //!< Efcmd observation ID
 
#define pus_TM_DATA_ST_200_2		((pusTmDataKind_t) st_200_2_PRESENT)
 
#define pus_TC_DATA_ST_200_3		((pusTcDataKind_t) PusTcApplicationData_st_200_3_PRESENT) 
#define pus_TM_DATA_ST_200_4		((pusTmDataKind_t) st_200_4_PRESENT)
 
#define pus_TC_DATA_ST_200_5		((pusTcDataKind_t) PusTcApplicationData_st_200_5_PRESENT) 
#define pus_TM_DATA_ST_200_6		((pusTmDataKind_t) st_200_6_PRESENT)
 
#define pus_TM_DATA_ST_200_8		((pusTmDataKind_t) st_200_8_PRESENT)
 
#define pus_TC_DATA_ST_200_9		((pusTcDataKind_t) PusTcApplicationData_st_200_9_PRESENT) 
#define pus_TM_DATA_ST_200_10		((pusTmDataKind_t) st_200_10_PRESENT)
 
#define pus_TC_DATA_ST_200_11		((pusTcDataKind_t) PusTcApplicationData_st_200_11_PRESENT) 
#define pus_TM_DATA_ST_200_12		((pusTmDataKind_t) st_200_12_PRESENT)
 
#define pus_TC_DATA_ST_200_13		((pusTcDataKind_t) PusTcApplicationData_st_200_13_PRESENT) 
#define pus_TM_DATA_ST_200_14		((pusTmDataKind_t) st_200_14_PRESENT)


// ST220

typedef asn1SccPus_220_StateId pusSt220_stateID;

#define pus_TC_DATA_ST_220_1		((pusTcDataKind_t) PusTcApplicationData_st_220_1_PRESENT)
#define pus_TM_DATA_ST_220_3		((pusTmDataKind_t) st_220_3_PRESENT)


#ifdef  __cplusplus
}
#endif


#endif