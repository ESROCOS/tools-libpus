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

typedef asn1SccPusTM_200_18_Data pusSt200_18_Observation; //!< Planner observation ID
 

typedef asn1SccPusTC_200_19_Data pusSt200_19_Goal; //!< Mission goal ID 

typedef asn1SccPusTM_200_20_Data pusSt200_20_Observation; //!< Mission observation ID
 

typedef asn1SccPusTC_200_13_Data pusSt200_13_Goal; //!< Sodmission goal ID 

typedef asn1SccPusTM_200_14_Data pusSt200_14_Observation; //!< Sodmission observation ID
 

typedef asn1SccPusTC_200_1_Data pusSt200_1_Goal; //!< Hotdockcmd goal ID 

typedef asn1SccPusTM_200_2_Data pusSt200_2_Observation; //!< Hotdockcmd observation ID
 

typedef asn1SccPusTM_200_4_Data pusSt200_4_Observation; //!< Hotdockstatus observation ID
 

typedef asn1SccPusTC_200_5_Data pusSt200_5_Goal; //!< Wmcmd goal ID 

typedef asn1SccPusTM_200_6_Data pusSt200_6_Observation; //!< Wmcmd observation ID
 

typedef asn1SccPusTC_200_9_Data pusSt200_9_Goal; //!< Basecmd goal ID 

typedef asn1SccPusTM_200_10_Data pusSt200_10_Observation; //!< Basecmd observation ID
 

typedef asn1SccPusTC_200_11_Data pusSt200_11_Goal; //!< Efcmd goal ID 

typedef asn1SccPusTM_200_12_Data pusSt200_12_Observation; //!< Efcmd observation ID
 

typedef asn1SccPusTM_200_8_Data pusSt200_8_Observation; //!< Wmstatus observation ID
 
#define pus_TM_DATA_ST_200_18		((pusTmDataKind_t) st_200_18_PRESENT)
 
#define pus_TC_DATA_ST_200_19		((pusTcDataKind_t) PusTcApplicationData_st_200_19_PRESENT) 
#define pus_TM_DATA_ST_200_20		((pusTmDataKind_t) st_200_20_PRESENT)
 
#define pus_TC_DATA_ST_200_13		((pusTcDataKind_t) PusTcApplicationData_st_200_13_PRESENT) 
#define pus_TM_DATA_ST_200_14		((pusTmDataKind_t) st_200_14_PRESENT)
 
#define pus_TC_DATA_ST_200_1		((pusTcDataKind_t) PusTcApplicationData_st_200_1_PRESENT) 
#define pus_TM_DATA_ST_200_2		((pusTmDataKind_t) st_200_2_PRESENT)
 
#define pus_TM_DATA_ST_200_4		((pusTmDataKind_t) st_200_4_PRESENT)
 
#define pus_TC_DATA_ST_200_5		((pusTcDataKind_t) PusTcApplicationData_st_200_5_PRESENT) 
#define pus_TM_DATA_ST_200_6		((pusTmDataKind_t) st_200_6_PRESENT)
 
#define pus_TC_DATA_ST_200_9		((pusTcDataKind_t) PusTcApplicationData_st_200_9_PRESENT) 
#define pus_TM_DATA_ST_200_10		((pusTmDataKind_t) st_200_10_PRESENT)
 
#define pus_TC_DATA_ST_200_11		((pusTcDataKind_t) PusTcApplicationData_st_200_11_PRESENT) 
#define pus_TM_DATA_ST_200_12		((pusTmDataKind_t) st_200_12_PRESENT)
 
#define pus_TM_DATA_ST_200_8		((pusTmDataKind_t) st_200_8_PRESENT)

// ST 210

// typedef ....

/* R_ICU_SPW_PNP */
#define pus_TC_DATA_ST_210_1   ((pusTcDataKind_t) PusTcApplicationData_st_210_1_PRESENT)
#define pus_TC_DATA_ST_210_2   ((pusTcDataKind_t) PusTcApplicationData_st_210_2_PRESENT)

/* R_ICU */
#define pus_TC_DATA_ST_210_11   ((pusTcDataKind_t) PusTcApplicationData_st_210_11_PRESENT)
#define pus_TC_DATA_ST_210_12   ((pusTcDataKind_t) PusTcApplicationData_st_210_12_PRESENT)

/* THS */
#define pus_TC_DATA_ST_210_81   ((pusTcDataKind_t) PusTcApplicationData_st_210_81_PRESENT)
#define pus_TC_DATA_ST_210_82   ((pusTcDataKind_t) PusTcApplicationData_st_210_82_PRESENT)

/* CPDU */
#define pus_TC_DATA_ST_210_91   ((pusTcDataKind_t) PusTcApplicationData_st_210_91_PRESENT)
#define pus_TC_DATA_ST_210_92   ((pusTcDataKind_t) PusTcApplicationData_st_210_92_PRESENT)
#define pus_TC_DATA_ST_210_93   ((pusTcDataKind_t) PusTcApplicationData_st_210_93_PRESENT)
#define pus_TC_DATA_ST_210_94   ((pusTcDataKind_t) PusTcApplicationData_st_210_94_PRESENT)

// ST220

typedef asn1SccPus_220_StateId pusSt220_stateID;

#define pus_TC_DATA_ST_220_1		((pusTcDataKind_t) PusTcApplicationData_st_220_1_PRESENT)
#define pus_TM_DATA_ST_220_3		((pusTmDataKind_t) st_220_3_PRESENT)


#ifdef  __cplusplus
}
#endif


#endif
