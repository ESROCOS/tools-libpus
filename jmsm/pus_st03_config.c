
//
// H2020 ESROCOS Project
// Company: GMV Aerospace & Defence S.A.U.
// Licence: GPLv2
//
// PUS service ST[03] configuration
// 
// File automatically generated from the pus_st30_config.h.mako template
//


#include "pus_st03_config.h"
#ifdef PUS_CONFIGURE_HK_PARAMS_TABLE

#include <string.h> //memcpy

// ST[03] arrays
pusSt03ParamInfo_t pus_st03_paramInfo[14];
pusStoredParam_t pus_st03_params[14];

// reports
pusSt03ParamId_t pus_st03_HkReportsIDs_NAME1[PUS_HK_NUMBER_REPORTS];
pusSt03ParamId_t pus_st03_HkReportsIDs_NAME2[PUS_HK_NUMBER_REPORTS];
pusSt03ReportInfo_t pus_st03_HkReportInfos[PUS_HK_NUMBER_REPORTS];

// ST[03] constants
const pusSt03ParamId_t pus_ST03_PARAM_LIMIT = PUS_ST03_PARAM_LIMIT;


pusError_t pus_hk_configure()
{
    // HK reports
    pus_st03_HkReportsIDs_NAME1[0] = HK_PARAM_INT01; 
    pus_st03_HkReportsIDs_NAME1[1] = OBCP_ACTIVES;
	pus_st03_HkReportInfos[PUS_HK_REP_NAME1].numParams = 2;
    pus_st03_HkReportInfos[PUS_HK_REP_NAME1].paramIds = &pus_st03_HkReportsIDs_NAME1[0];

    pus_st03_HkReportsIDs_NAME2[0] = HK_PARAM_REAL01; 
    pus_st03_HkReportsIDs_NAME2[1] = HK_PARAM_INT02;
    pus_st03_HkReportInfos[PUS_HK_REP_NAME2].numParams = 2;
    pus_st03_HkReportInfos[PUS_HK_REP_NAME2].paramIds = &pus_st03_HkReportsIDs_NAME2[0];

	// Store parameters info

    pus_st03_params[HK_PARAM_INT01] = 0;
    pus_st03_paramInfo[HK_PARAM_INT01].label = "HK_PARAM_INT01";
    pus_st03_paramInfo[HK_PARAM_INT01].type = PUS_INT32;

    
    pus_st03_params[OBCP_ACTIVES] = 0;
    pus_st03_paramInfo[OBCP_ACTIVES].label = "OBCP_ACTIVES";
    pus_st03_paramInfo[OBCP_ACTIVES].type = PUS_UINT32;

    
    pus_st03_params[HK_PARAM_REAL01] = 0;
    pus_st03_paramInfo[HK_PARAM_REAL01].label = "HK_PARAM_REAL01";
    pus_st03_paramInfo[HK_PARAM_REAL01].type = PUS_REAL64;

    
    pus_st03_params[HK_PARAM_INT02] = 0;
    pus_st03_paramInfo[HK_PARAM_INT02].label = "HK_PARAM_INT02";
    pus_st03_paramInfo[HK_PARAM_INT02].type = PUS_INT32;

    
    pus_st03_params[HK_PARAM_UINT01] = 0;
    pus_st03_paramInfo[HK_PARAM_UINT01].label = "HK_PARAM_UINT01";
    pus_st03_paramInfo[HK_PARAM_UINT01].type = PUS_UINT32;

    
    pus_st03_params[HK_PARAM_BYTE01] = 0;
    pus_st03_paramInfo[HK_PARAM_BYTE01].label = "HK_PARAM_BYTE01";
    pus_st03_paramInfo[HK_PARAM_BYTE01].type = PUS_BYTE;

    
    pus_st03_params[HK_PARAM_BOOL01] = 0;
    pus_st03_paramInfo[HK_PARAM_BOOL01].label = "HK_PARAM_BOOL01";
    pus_st03_paramInfo[HK_PARAM_BOOL01].type = PUS_BOOL;

    
    pus_st03_params[UR5_JOINT_0] = 0;
    pus_st03_paramInfo[UR5_JOINT_0].label = "UR5_JOINT_0";
    pus_st03_paramInfo[UR5_JOINT_0].type = PUS_REAL64;

    
    pus_st03_params[UR5_JOINT_1] = 0;
    pus_st03_paramInfo[UR5_JOINT_1].label = "UR5_JOINT_1";
    pus_st03_paramInfo[UR5_JOINT_1].type = PUS_REAL64;

    
    pus_st03_params[UR5_JOINT_2] = 0;
    pus_st03_paramInfo[UR5_JOINT_2].label = "UR5_JOINT_2";
    pus_st03_paramInfo[UR5_JOINT_2].type = PUS_REAL64;

    
    pus_st03_params[UR5_JOINT_3] = 0;
    pus_st03_paramInfo[UR5_JOINT_3].label = "UR5_JOINT_3";
    pus_st03_paramInfo[UR5_JOINT_3].type = PUS_REAL64;

    
    pus_st03_params[UR5_JOINT_4] = 0;
    pus_st03_paramInfo[UR5_JOINT_4].label = "UR5_JOINT_4";
    pus_st03_paramInfo[UR5_JOINT_4].type = PUS_REAL64;

    
    pus_st03_params[UR5_JOINT_5] = 0;
    pus_st03_paramInfo[UR5_JOINT_5].label = "UR5_JOINT_5";
    pus_st03_paramInfo[UR5_JOINT_5].type = PUS_REAL64;

    
    pus_st03_params[ROBOT_STATE] = 0;
    pus_st03_paramInfo[ROBOT_STATE].label = "ROBOT_STATE";
    pus_st03_paramInfo[ROBOT_STATE].type = PUS_UINT32;

    return PUS_NO_ERROR;
}


pusError_t pus_hk_getReportParams(pusSt03HousekeepingReportId_t reportId, size_t *numParams, pusSt03ParamId_t* paramIds)
{
    if((numParams == NULL) || (paramIds == NULL))
    {
        return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    }

    if(reportId >= PUS_HK_NUMBER_REPORTS)
    {
        return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
    }
    else
    {
        *numParams = pus_st03_HkReportInfos[reportId].numParams;
        paramIds = pus_st03_HkReportInfos[reportId].paramIds;
        
        return PUS_SET_ERROR(PUS_NO_ERROR);
    }
}

pusError_t pus_hk_setHK_PARAM_INT01(INT32 value)
{
	return pus_hk_setInt32Param(HK_PARAM_INT01, value);
}

pusError_t pus_hk_getHK_PARAM_INT01(INT32* value)
{
	return pus_hk_getInt32Param(HK_PARAM_INT01, value);
}

pusError_t pus_hk_setOBCP_ACTIVES(UINT32 value)
{
	return pus_hk_setUInt32Param(OBCP_ACTIVES, value);
}

pusError_t pus_hk_getOBCP_ACTIVES(UINT32* value)
{
	return pus_hk_getUInt32Param(OBCP_ACTIVES, value);
}

pusError_t pus_hk_setHK_PARAM_REAL01(REAL64 value)
{
	return pus_hk_setReal64Param(HK_PARAM_REAL01, value);
}

pusError_t pus_hk_getHK_PARAM_REAL01(REAL64* value)
{
	return pus_hk_getReal64Param(HK_PARAM_REAL01, value);
}

pusError_t pus_hk_setHK_PARAM_INT02(INT32 value)
{
	return pus_hk_setInt32Param(HK_PARAM_INT02, value);
}

pusError_t pus_hk_getHK_PARAM_INT02(INT32* value)
{
	return pus_hk_getInt32Param(HK_PARAM_INT02, value);
}

pusError_t pus_hk_setHK_PARAM_UINT01(UINT32 value)
{
	return pus_hk_setUInt32Param(HK_PARAM_UINT01, value);
}

pusError_t pus_hk_getHK_PARAM_UINT01(UINT32* value)
{
	return pus_hk_getUInt32Param(HK_PARAM_UINT01, value);
}

pusError_t pus_hk_setHK_PARAM_BYTE01(BYTE value)
{
	return pus_hk_setByteParam(HK_PARAM_BYTE01, value);
}

pusError_t pus_hk_getHK_PARAM_BYTE01(BYTE* value)
{
	return pus_hk_getByteParam(HK_PARAM_BYTE01, value);
}

pusError_t pus_hk_setHK_PARAM_BOOL01(BOOL value)
{
	return pus_hk_setBoolParam(HK_PARAM_BOOL01, value);
}

pusError_t pus_hk_getHK_PARAM_BOOL01(BOOL* value)
{
	return pus_hk_getBoolParam(HK_PARAM_BOOL01, value);
}

pusError_t pus_hk_setUR5_JOINT_0(REAL64 value)
{
	return pus_hk_setReal64Param(UR5_JOINT_0, value);
}

pusError_t pus_hk_getUR5_JOINT_0(REAL64* value)
{
	return pus_hk_getReal64Param(UR5_JOINT_0, value);
}

pusError_t pus_hk_setUR5_JOINT_1(REAL64 value)
{
	return pus_hk_setReal64Param(UR5_JOINT_1, value);
}

pusError_t pus_hk_getUR5_JOINT_1(REAL64* value)
{
	return pus_hk_getReal64Param(UR5_JOINT_1, value);
}

pusError_t pus_hk_setUR5_JOINT_2(REAL64 value)
{
	return pus_hk_setReal64Param(UR5_JOINT_2, value);
}

pusError_t pus_hk_getUR5_JOINT_2(REAL64* value)
{
	return pus_hk_getReal64Param(UR5_JOINT_2, value);
}

pusError_t pus_hk_setUR5_JOINT_3(REAL64 value)
{
	return pus_hk_setReal64Param(UR5_JOINT_3, value);
}

pusError_t pus_hk_getUR5_JOINT_3(REAL64* value)
{
	return pus_hk_getReal64Param(UR5_JOINT_3, value);
}

pusError_t pus_hk_setUR5_JOINT_4(REAL64 value)
{
	return pus_hk_setReal64Param(UR5_JOINT_4, value);
}

pusError_t pus_hk_getUR5_JOINT_4(REAL64* value)
{
	return pus_hk_getReal64Param(UR5_JOINT_4, value);
}

pusError_t pus_hk_setUR5_JOINT_5(REAL64 value)
{
	return pus_hk_setReal64Param(UR5_JOINT_5, value);
}

pusError_t pus_hk_getUR5_JOINT_5(REAL64* value)
{
	return pus_hk_getReal64Param(UR5_JOINT_5, value);
}

pusError_t pus_hk_setROBOT_STATE(UINT32 value)
{
	return pus_hk_setUInt32Param(ROBOT_STATE, value);
}

pusError_t pus_hk_getROBOT_STATE(UINT32* value)
{
	return pus_hk_getUInt32Param(ROBOT_STATE, value);
}


#endif

