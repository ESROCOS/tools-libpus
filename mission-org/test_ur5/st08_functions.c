/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */
 
#include <stdio.h>
#include "pus_types.h"
#include "pus_error.h"
#include "pus_mission_types.h"


pusError_t example_function()
{
    printf("  - Hello world! -  (Function0)\n");
    return PUS_NO_ERROR;
}

void (*ptr_st201_RI_planHomeRequest)(void) = NULL;
pusError_t ur5_planHome()
{
    printf(" -ST08: ur5_planHome\n");
    if(NULL == ptr_st201_RI_planHomeRequest)
    {
        return PUS_ERROR_NULLPTR;
    } 

    ptr_st201_RI_planHomeRequest();
    return PUS_NO_ERROR;
}

void (*ptr_st201_RI_setHome)(const asn1SccPusTC_201_1_3_Data *) = NULL;
pusError_t ur5_setHome()
{
    printf(" -ST08: ur5_setHome\n");
    if(NULL == ptr_st201_RI_setHome)
    {
        return PUS_ERROR_NULLPTR;
    } 
    asn1SccPusTC_201_1_3_Data data;

    pus_parameters_getUR5_HOME_POS_1(&data.position.arr[0]);
    pus_parameters_getUR5_HOME_POS_2(&data.position.arr[1]);
    pus_parameters_getUR5_HOME_POS_3(&data.position.arr[2]);
    pus_parameters_getUR5_HOME_ORI_1(&data.orientation.arr[0]);
    pus_parameters_getUR5_HOME_ORI_2(&data.orientation.arr[1]);
    pus_parameters_getUR5_HOME_ORI_3(&data.orientation.arr[2]);
    pus_parameters_getUR5_HOME_ORI_RE(&data.orientation.arr[3]);

    ptr_st201_RI_setHome(&data);

    return PUS_NO_ERROR;
}

void (*ptr_st201_RI_planMoveRequest)(const asn1SccPusTC_201_1_3_Data *) = NULL;
pusError_t ur5_planMove()
{
    printf(" -ST08: ur5_planMove\n");
    if(NULL == ptr_st201_RI_planMoveRequest)
    {
        return PUS_ERROR_NULLPTR;
    } 

    asn1SccPusTC_201_1_3_Data data;

    pus_parameters_getUR5_MOVE_POS_1(&data.position.arr[0]);
    pus_parameters_getUR5_MOVE_POS_2(&data.position.arr[1]);
    pus_parameters_getUR5_MOVE_POS_3(&data.position.arr[2]);
    pus_parameters_getUR5_MOVE_ORI_1(&data.orientation.arr[0]);
    pus_parameters_getUR5_MOVE_ORI_2(&data.orientation.arr[1]);
    pus_parameters_getUR5_MOVE_ORI_3(&data.orientation.arr[2]);
    pus_parameters_getUR5_MOVE_ORI_RE(&data.orientation.arr[3]);

    ptr_st201_RI_planMoveRequest(&data);

    return PUS_NO_ERROR;
}

void (*ptr_st200_RI_operationRequest)(const asn1SccPusSt200ControlId *) = NULL;
pusError_t camera_frameRequest()
{
    printf(" -ST08: camera_frameRequest\n");
    if(NULL == ptr_st200_RI_operationRequest)
    {
        return PUS_ERROR_NULLPTR;
    } 

    pusSt200ControlId aux = 1;
    ptr_st200_RI_operationRequest(&aux);
    return PUS_NO_ERROR;
}
