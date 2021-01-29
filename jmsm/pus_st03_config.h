//
// H2020 ESROCOS Project
// Company: GMV Aerospace & Defence S.A.U.
// Licence: GPLv2
//
// PUS service ST[03] configuration
// 
// File automatically generated from the pus_st30_config.h.mako template
//
//                     -- DO NOT MODIFY --


#ifndef PUS_ST03_CONFIG_H
#define PUS_ST03_CONFIG_H

#include "pus_types.h"
#ifdef PUS_CONFIGURE_HK_PARAMS_TABLE

#ifdef __cplusplus
extern "C" {
#endif


#include "pus_error.h"
#include "pus_types.h"
#include "pus_housekeeping.h"


// Parameter identifiers

#define HK_PARAM_INT01 ((pusSt03ParamId_t) 0) 
#define OBCP_ACTIVES ((pusSt03ParamId_t) 1) 
#define HK_PARAM_REAL01 ((pusSt03ParamId_t) 2) 
#define HK_PARAM_INT02 ((pusSt03ParamId_t) 3) 
#define HK_PARAM_UINT01 ((pusSt03ParamId_t) 4) 
#define HK_PARAM_BYTE01 ((pusSt03ParamId_t) 5) 
#define HK_PARAM_BOOL01 ((pusSt03ParamId_t) 6) 
#define UR5_JOINT_0 ((pusSt03ParamId_t) 7) 
#define UR5_JOINT_1 ((pusSt03ParamId_t) 8) 
#define UR5_JOINT_2 ((pusSt03ParamId_t) 9) 
#define UR5_JOINT_3 ((pusSt03ParamId_t) 10) 
#define UR5_JOINT_4 ((pusSt03ParamId_t) 11) 
#define UR5_JOINT_5 ((pusSt03ParamId_t) 12) 
#define ROBOT_STATE ((pusSt03ParamId_t) 13) 
#define PUS_ST03_PARAM_LIMIT ((pusSt03ParamId_t) 14)

// JMSM
#define PUS_HK_REP_NAME1 0
#define PUS_HK_REP_NAME2 1
#define PUS_HK_NUMBER_REPORTS 2

//! Array with parameter information (length = number of parameters)
extern pusSt03ParamInfo_t pus_st03_paramInfo[];

//! Array for parameters values (all stored in 64 bits)
extern pusStoredParam_t pus_st03_params[];

//! Structure of the default HK report
extern pusSt03ReportInfo_t pus_st03_defaultHkReportInfo;

//! First invalid parameter ID
extern const pusSt03ParamId_t pus_ST03_PARAM_LIMIT;

//! Initialize the configuration of the ST[03] service from the mission database
extern pusError_t pus_hk_configure();


//! Get parameters from a HK report ID.
extern pusError_t pus_hk_getReportParams(pusSt03HousekeepingReportId_t reportId, size_t *numParams, pusSt03ParamId_t* paramIds);


//Param types
typedef uint16_t UINT16;
typedef int32_t INT32;
typedef uint32_t UINT32;
typedef float REAL32;
typedef double REAL64;
typedef uint8_t BYTE;
typedef bool BOOL;

//Param getters/setters
pusError_t pus_hk_setHK_PARAM_INT01(INT32 value);
pusError_t pus_hk_getHK_PARAM_INT01(INT32* value);

pusError_t pus_hk_setOBCP_ACTIVES(UINT32 value);
pusError_t pus_hk_getOBCP_ACTIVES(UINT32* value);

pusError_t pus_hk_setHK_PARAM_REAL01(REAL64 value);
pusError_t pus_hk_getHK_PARAM_REAL01(REAL64* value);

pusError_t pus_hk_setHK_PARAM_INT02(INT32 value);
pusError_t pus_hk_getHK_PARAM_INT02(INT32* value);

pusError_t pus_hk_setHK_PARAM_UINT01(UINT32 value);
pusError_t pus_hk_getHK_PARAM_UINT01(UINT32* value);

pusError_t pus_hk_setHK_PARAM_BYTE01(BYTE value);
pusError_t pus_hk_getHK_PARAM_BYTE01(BYTE* value);

pusError_t pus_hk_setHK_PARAM_BOOL01(BOOL value);
pusError_t pus_hk_getHK_PARAM_BOOL01(BOOL* value);

pusError_t pus_hk_setUR5_JOINT_0(REAL64 value);
pusError_t pus_hk_getUR5_JOINT_0(REAL64* value);

pusError_t pus_hk_setUR5_JOINT_1(REAL64 value);
pusError_t pus_hk_getUR5_JOINT_1(REAL64* value);

pusError_t pus_hk_setUR5_JOINT_2(REAL64 value);
pusError_t pus_hk_getUR5_JOINT_2(REAL64* value);

pusError_t pus_hk_setUR5_JOINT_3(REAL64 value);
pusError_t pus_hk_getUR5_JOINT_3(REAL64* value);

pusError_t pus_hk_setUR5_JOINT_4(REAL64 value);
pusError_t pus_hk_getUR5_JOINT_4(REAL64* value);

pusError_t pus_hk_setUR5_JOINT_5(REAL64 value);
pusError_t pus_hk_getUR5_JOINT_5(REAL64* value);

pusError_t pus_hk_setROBOT_STATE(UINT32 value);
pusError_t pus_hk_getROBOT_STATE(UINT32* value);

 

#ifdef __cplusplus
}
#endif

#endif

#endif // PUS_ST03_CONFIG_H
