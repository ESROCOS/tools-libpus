
#include "py/nlr.h"
#include "py/obj.h"
#include "py/runtime.h"
#include "py/binary.h"

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

// PUS INCLUDES
#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_stored_param.h"

#include "pus_st08_packets.h"

//#include "pus_st03_config.h"
#include "pus_housekeeping.h"

#include "pus_parameter_management.h"
#include "pus_events.h"


//TODO where¿
bool double_to_pusTime(pusTime_t* time, double time_d)
{
    int seconds = (int)time_d;
    int nanoseconds = (int)((time_d - seconds) * 1000000000) ;
    
    time->tv_sec = seconds;
    time->tv_nsec = nanoseconds;
    
    return true;
}

bool pusTime_to_double(double* time_d, pusTime_t* time)
{
    *time_d = time->tv_nsec / 1000000000.0;
    *time_d = *time_d + time->tv_sec;
    
    return true;
}

/*STATIC mp_obj_t createObj(mp_obj_t what)
{
    printf("Creating INT: %ld\n", mp_obj_get_int(what));
    int* p_obj = (int*) malloc(sizeof(int));
    *p_obj = mp_obj_get_int(what);
    return MP_OBJ_FROM_PTR(p_obj);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(mymodule_createObj_obj, createObj);


STATIC mp_obj_t incrObj(mp_obj_t what)
{
    int* p2 = (int*)MP_OBJ_TO_PTR(what);
    printf("Pre INCR: %d\n", *p2);
    *p2 = *p2 + 1;
    printf("Post INCR: %d\n", *p2);
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(mymodule_incrObj_obj, incrObj);


STATIC mp_obj_t delObj(mp_obj_t what)
{
    printf("Deleting INT\n");
    free((int*)MP_OBJ_TO_PTR(what));
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(mymodule_delObj_obj, delObj);

STATIC mp_obj_t mymodule_wait(void) {
    return mp_obj_new_bool(wait());
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(mymodule_wait_obj, mymodule_wait);

STATIC mp_obj_t mymodule_produce(void) {
    return mp_obj_new_bool(producing());
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(mymodule_produce_obj, mymodule_produce);
*/

// get Time now FLOAT
STATIC mp_obj_t mymodule_getTimeNowFloat() {
    
    pusTime_t time;
    pus_now(&time);
        
    //TODO problem with float (now double)
    double timeFloat = time.tv_nsec / 1000000000.0;
    timeFloat = timeFloat + time.tv_sec;
    
    return mp_obj_new_float(timeFloat);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(mymodule_getTimeNowFloat_obj, mymodule_getTimeNowFloat);

// get Time now LIST
STATIC mp_obj_t mymodule_getTimeNowList() {
    pusTime_t time;
    pus_now(&time);
    
    mp_obj_t list[2];
    list[0] = mp_obj_new_int(time.tv_sec);
    list[1] = mp_obj_new_int(time.tv_nsec);
    return mp_obj_new_list(2, list); 
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(mymodule_getTimeNowList_obj, mymodule_getTimeNowList);

// get Time now
STATIC mp_obj_t mymodule_timeoutReached(mp_obj_t py_time_seconds, mp_obj_t py_time_nseconds, mp_obj_t py_timeout) {
    
    double timeout = mp_obj_get_float(py_timeout);
    int seconds = mp_obj_get_int(py_time_seconds);
    int nanoseconds = mp_obj_get_int(py_time_nseconds);
    
    pusTime_t time;
    pus_now(&time);
    
    int timeout_nsec_tot = (int)(nanoseconds + (int)((timeout - (int)timeout) * 1000000000));
    
    int timeout_sec = seconds + (int)timeout + (timeout_nsec_tot / 1000000000);
    int timeout_nsec = timeout_nsec_tot % 1000000000;
        
    //printf("seconds %lld, ns: %lld, timeout_sec: %d, timeout_nsec: %d\n", time.tv_sec, time.tv_nsec, timeout_sec, timeout_nsec);
    if(time.tv_sec > timeout_sec)
    {
        return mp_const_true;
    }
    else
    {
        if(timeout_sec == time.tv_sec)
        {
            if( time.tv_nsec >= timeout_nsec )
            {
                return mp_const_true;
            }
        }
    }

    return mp_const_false;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_3(mymodule_timeoutReached_obj, mymodule_timeoutReached);


// SLEEP sec, nanosec
STATIC mp_obj_t mymodule_sleepInterval(mp_obj_t py_sec_float) {
    
    struct timespec tim;
    //tim.tv_sec = mp_obj_get_int(sec);
    //tim.tv_nsec = mp_obj_get_int(nsec);
    
    double sec_float = mp_obj_get_float(py_sec_float);
    
    int seconds = (int)sec_float;
    int nanoseconds = (int)((sec_float - seconds) * 1000000000) ;
    
    tim.tv_sec = seconds;
    tim.tv_nsec = nanoseconds;
    
    if(0 == nanosleep(&tim , NULL))
        return mp_const_true;
    else
        return mp_const_false;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(mymodule_sleepInterval_obj, mymodule_sleepInterval);


// Get LABEL hk param
STATIC mp_obj_t mymodule_getDictHkParams( void ) {
    if (!pus_hk_isInitialized())
	{
		return mp_obj_new_dict(0);
	}
    
    extern pusSt03ParamInfo_t pus_st03_paramInfo[];
    //extern pusStoredParam_t pus_st03_params[];
    extern const pusSt03ParamId_t pus_ST03_PARAM_LIMIT;
    
    mp_obj_t label;
    mp_obj_t id;
    mp_obj_t dict = mp_obj_new_dict(0);
    for(size_t i = 0; i < pus_ST03_PARAM_LIMIT; i++)
    {
        label = mp_obj_new_str(pus_st03_paramInfo[i].label, strlen(pus_st03_paramInfo[i].label), false);
        id = mp_obj_new_int(i);
        mp_obj_dict_store(dict, label, id);
    }
    
    return dict;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(mymodule_getDictHkParams_obj, mymodule_getDictHkParams);

// Get LABEL ST20 param
STATIC mp_obj_t mymodule_getDictOnBoardParams( void ) {
    if (!pus_parameters_isInitialized())
	{
		return mp_obj_new_dict(0);
	}
    
    extern pusSt20ParamInfo_t pus_st20_paramInfo[];
    extern const pusSt20OnBoardParamId_t pus_ST20_PARAM_LIMIT;
    
    mp_obj_t label;
    mp_obj_t id;
    mp_obj_t dict = mp_obj_new_dict(0);
    for(size_t i = 0; i < pus_ST20_PARAM_LIMIT; i++)
    {
        label = mp_obj_new_str(pus_st20_paramInfo[i].label, strlen(pus_st20_paramInfo[i].label), false);
        id = mp_obj_new_int(i);
        mp_obj_dict_store(dict, label, id);
    }
    return dict;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(mymodule_getDictOnBoardParams_obj, mymodule_getDictOnBoardParams);

// Get LABEL events
STATIC mp_obj_t mymodule_getDictEvents( void ) {
    if (!pus_events_isInitialized())
	{
		return mp_obj_new_dict(0);
	}
    
    extern pusSt05EventInfo_t pus_st05_eventInfoList[];
    extern const size_t pus_st05_eventInfoListLength;
    
    mp_obj_t label;
    mp_obj_t id;
    mp_obj_t dict = mp_obj_new_dict(0);
    for(size_t i = 0; i < pus_st05_eventInfoListLength; i++)
    {
        label = mp_obj_new_str(pus_st05_eventInfoList[i].label, strlen(pus_st05_eventInfoList[i].label), false);
        id = mp_obj_new_int(i);
        mp_obj_dict_store(dict, label, id);
    }
    return dict;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(mymodule_getDictEvents_obj, mymodule_getDictEvents);


// Get LABEL functions
STATIC mp_obj_t mymodule_getDictFunctions( void ) {
    if (!pus_st08_isInitialized())
	{
		return mp_obj_new_dict(0);
	}
    
    extern pusSt08FunctionInfo_t pus_st08_functionInfoList[];
    extern const size_t pus_st08_limitFunctions;
    
    mp_obj_t label;
    mp_obj_t id;
    mp_obj_t dict = mp_obj_new_dict(0);
    for(size_t i = 0; i < pus_st08_limitFunctions; i++)
    {
        label = mp_obj_new_str(pus_st08_functionInfoList[i].label, strlen(pus_st08_functionInfoList[i].label), false);
        id = mp_obj_new_int(i);
        mp_obj_dict_store(dict, label, id);
    }
    return dict;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(mymodule_getDictFunctions_obj, mymodule_getDictFunctions);

// Get Hk param value
STATIC mp_obj_t mymodule_getHkParamValue( mp_obj_t py_paramId ) {
    size_t paramId = mp_obj_get_int(py_paramId);
    
    if (!pus_hk_isInitialized())
	{
		return mp_const_none;
	}
    
    pusParamType_t type;
    if( PUS_NO_ERROR != pus_hk_getParamType(paramId, &type))
        return mp_const_none;
    
    if( PUS_INT32 == type )
    {
        int32_t value;
        if( PUS_NO_ERROR != pus_hk_getInt32Param(paramId, &value))
        {
            return mp_const_none;
        }
        return mp_obj_new_int(value);
    }
    else if( PUS_UINT32 == type )
    {
        uint32_t value;
        if( PUS_NO_ERROR != pus_hk_getUInt32Param(paramId, &value))
            return mp_const_none;
        return mp_obj_new_int_from_uint(value);
    }
    else if( PUS_REAL64 == type )
    {
        double value;
        if( PUS_NO_ERROR != pus_hk_getReal64Param(paramId, &value))
            return mp_const_none;
        return mp_obj_new_float(value);
    }
    else if( PUS_BYTE == type )
    {
        uint8_t value;
        if( PUS_NO_ERROR != pus_hk_getByteParam(paramId, &value))
            return mp_const_none;
        return mp_obj_new_bytes(&value,1);
    }
    else if( PUS_BOOL == type )
    {
        bool value;
        if( PUS_NO_ERROR != pus_hk_getBoolParam(paramId, &value))
            return mp_const_none;
        return mp_obj_new_bool(value);
    }
        
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(mymodule_getHkParamValue_obj, mymodule_getHkParamValue);

// Get OnBoard param value
STATIC mp_obj_t mymodule_getOnBoardParamValue( mp_obj_t py_paramId ) {
    size_t paramId = mp_obj_get_int(py_paramId);
    
    if (!pus_parameters_isInitialized())
	{
		return mp_const_none;
	}
    
    pusParamType_t type;
    if( PUS_NO_ERROR != pus_parameters_getParamType(paramId, &type))
        return mp_const_none;
    
    
    if( PUS_INT32 == type )
    {
        int32_t value;
        if( PUS_NO_ERROR != pus_parameters_getInt32Param(paramId, &value))
            return mp_const_none;
        return mp_obj_new_int(value);
    }
    else if( PUS_UINT32 == type )
    {
        uint32_t value;
        if( PUS_NO_ERROR != pus_parameters_getUInt32Param(paramId, &value))
            return mp_const_none;
        return mp_obj_new_int_from_uint(value);
    }
    else if( PUS_REAL64 == type )
    {
        double value;
        if( PUS_NO_ERROR != pus_parameters_getReal64Param(paramId, &value))
            return mp_const_none;
        return mp_obj_new_float(value);
    }
    else if( PUS_BYTE == type )
    {
        uint8_t value;
        if( PUS_NO_ERROR != pus_parameters_getByteParam(paramId, &value))
            return mp_const_none;
        return mp_obj_new_bytes(&value,1);
    }
    else if( PUS_BOOL == type )
    {
        bool value;
        if( PUS_NO_ERROR != pus_parameters_getBoolParam(paramId, &value))
            return mp_const_none;
        return mp_obj_new_bool(value);
    }
        
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(mymodule_getOnBoardParamValue_obj, mymodule_getOnBoardParamValue);


// Set Hk param value
STATIC mp_obj_t mymodule_setHkParamValue( mp_obj_t py_paramId, mp_obj_t py_value ) {
    size_t paramId = mp_obj_get_int(py_paramId);
    
    if (!pus_hk_isInitialized())
	{
		return mp_const_false;
	}
    
    pusParamType_t type;
    if( PUS_NO_ERROR != pus_hk_getParamType(paramId, &type))
        return mp_const_false;
    
    if( PUS_INT32 == type && MP_OBJ_IS_INT(py_value) )
    {
        int32_t value = mp_obj_get_int(py_value);
        if( PUS_NO_ERROR != pus_hk_setInt32Param(paramId, value))
            return mp_const_false;
        return mp_const_true;
    }
    else if( PUS_UINT32 == type && true == MP_OBJ_IS_INT(py_value) )
    {
        if(mp_obj_get_int(py_value) < 0)
            return mp_const_false;
        uint32_t value = mp_obj_get_int(py_value);
        if( PUS_NO_ERROR != pus_hk_setUInt32Param(paramId, value))
            return mp_const_false;
        return mp_const_true;
    }
    else if( PUS_REAL64 == type && true == mp_obj_is_float(py_value))
    {
        double value = mp_obj_get_float(py_value);
        if( PUS_NO_ERROR != pus_hk_setReal64Param(paramId, value))
            return mp_const_false;
        return mp_const_true;
    }
    else if( PUS_BYTE == type && true == MP_OBJ_IS_INT(py_value))
    {
        uint8_t value = mp_obj_get_int(py_value);
        if( PUS_NO_ERROR != pus_hk_setByteParam(paramId, value))
            return mp_const_false;
        return mp_const_true;
    }
    else if( PUS_BOOL == type && MP_OBJ_IS_TYPE(py_value, &mp_type_bool))
    {
        bool value = mp_obj_get_int(py_value);
        if( PUS_NO_ERROR != pus_hk_setBoolParam(paramId, value))
            return mp_const_false;
        return mp_const_true;
    }
        
    return mp_const_false;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(mymodule_setHkParamValue_obj, mymodule_setHkParamValue);

// Set Onboard param value
STATIC mp_obj_t mymodule_setOnBoardParamValue( mp_obj_t py_paramId , mp_obj_t py_value) {
    size_t paramId = mp_obj_get_int(py_paramId);
    
    if (!pus_parameters_isInitialized())
	{
		return mp_const_false;
	}
    
    pusParamType_t type;
    if( PUS_NO_ERROR != pus_parameters_getParamType(paramId, &type))
        return mp_const_false;
    
    if( PUS_INT32 == type && MP_OBJ_IS_INT(py_value) )
    {
        int32_t value = mp_obj_get_int(py_value);
        if( PUS_NO_ERROR != pus_parameters_setInt32Param(paramId, value))
            return mp_const_false;
        return mp_const_true;
    }
    else if( PUS_UINT32 == type && true == MP_OBJ_IS_INT(py_value) )
    {
        if(mp_obj_get_int(py_value) < 0)
            return mp_const_false;
        uint32_t value = mp_obj_get_int(py_value);
        if( PUS_NO_ERROR != pus_parameters_setUInt32Param(paramId, value))
            return mp_const_false;
        return mp_const_true;
    }
    else if( PUS_REAL64 == type && true == mp_obj_is_float(py_value))
    {
        double value = mp_obj_get_float(py_value);
        if( PUS_NO_ERROR != pus_parameters_setReal64Param(paramId, value))
            return mp_const_false;
        return mp_const_true;
    }
    else if( PUS_BYTE == type && true == MP_OBJ_IS_INT(py_value))
    {
        uint8_t value = mp_obj_get_int(py_value);
        if( PUS_NO_ERROR != pus_parameters_setByteParam(paramId, value))
            return mp_const_false;
        return mp_const_true;
    }
    else if( PUS_BOOL == type && MP_OBJ_IS_TYPE(py_value, &mp_type_bool))
    {
        bool value = mp_obj_get_int(py_value);
        if( PUS_NO_ERROR != pus_parameters_setBoolParam(paramId, value))
            return mp_const_false;
        return mp_const_true;
    }
        
    return mp_const_false;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(mymodule_setOnBoardParamValue_obj, mymodule_setOnBoardParamValue);


bool auxFunction_getParamFromObj(pusStoredParam_t * param, pusParamType_t type, mp_obj_t py_obj)
{
    if( PUS_INT32 == type && MP_OBJ_IS_INT(py_obj) )
    {
        int32_t value = mp_obj_get_int(py_obj);
        if( PUS_NO_ERROR != pus_int32ToParam(param, value))
            return false;
        return true;
    }
    else if( PUS_UINT32 == type && true == MP_OBJ_IS_INT(py_obj) )
    {
        if(mp_obj_get_int(py_obj) < 0)
            return false;
        uint32_t value = mp_obj_get_int(py_obj);
        if( PUS_NO_ERROR != pus_uint32ToParam(param, value))
            return false;
        return true;
    }
    else if( PUS_REAL64 == type && true == mp_obj_is_float(py_obj))
    {
        double value = mp_obj_get_float(py_obj);
        if( PUS_NO_ERROR != pus_real64ToParam(param, value))
            return false;
        return true;
    }
    else if( PUS_BYTE == type && true == MP_OBJ_IS_INT(py_obj))
    {
        uint8_t value = mp_obj_get_int(py_obj);
        if( PUS_NO_ERROR != pus_byteToParam(param, value))
            return false;
        return true;
    }
    else if( PUS_BOOL == type && MP_OBJ_IS_TYPE(py_obj, &mp_type_bool))
    {
        bool value = mp_obj_get_int(py_obj);
        if( PUS_NO_ERROR != pus_boolToParam(param, value))
            return false;
        return true;
    }
    
    return false;
}



// Raise event
STATIC mp_obj_t mymodule_raiseEvent( mp_obj_t py_eventId , mp_obj_t py_data1, mp_obj_t py_data2) {
    pusSt05EventId_t eventId = mp_obj_get_int(py_eventId);
    
    pusSt05Event_t event;
    event.eventId = eventId;
    
    if (!pus_events_isInitialized())
	{
        return mp_const_false;
	}
    if( ! pus_events_isInInfoList(&event))
    {
        return mp_const_false;
    }
    
    extern pusSt05EventInfo_t pus_st05_eventInfoList[];
    
    // Get storedParam data1
    pusParamType_t type = pus_st05_eventInfoList[eventId].data.dataType1;
    pusStoredParam_t data1;
    if( ! auxFunction_getParamFromObj(&data1, type, py_data1))
    {
        return mp_const_false;
    }
    
    // Get storedParam data2
    type = pus_st05_eventInfoList[eventId].data.dataType2;
    pusStoredParam_t data2;
    if( ! auxFunction_getParamFromObj(&data2, type, py_data2))
    {
        return mp_const_false;
    }
    
    event.data.data1 = data1;
    event.data.data2 = data2;
    
    if(PUS_NO_ERROR == pus_st05_pushBufferEvent(&event))
    {
        return mp_const_true;
    }
    else
    {
        return mp_const_false; 
    } 
}
STATIC MP_DEFINE_CONST_FUN_OBJ_3(mymodule_raiseEvent_obj, mymodule_raiseEvent);


mp_obj_t auxFunction_getObjFromParam(pusStoredParam_t param, pusParamType_t type)
{
     if( PUS_INT32 == type )
    {
        int32_t value;
        if( PUS_NO_ERROR != pus_paramToInt32(&value, param))
            return mp_const_none;
        return mp_obj_new_int(value);
    }
    else if( PUS_UINT32 == type )
    {
        uint32_t value;
        if( PUS_NO_ERROR != pus_paramToUint32(&value, param))
            return mp_const_none;
        return mp_obj_new_int_from_uint(value);
    }
    else if( PUS_REAL64 == type )
    {
        double value;
        if( PUS_NO_ERROR != pus_paramToReal64(&value, param))
            return mp_const_none;
        return mp_obj_new_float(value);
    }
    else if( PUS_BYTE == type )
    {
        uint8_t value;
        if( PUS_NO_ERROR != pus_paramToByte(&value, param))
            return mp_const_none;
        return mp_obj_new_bytes(&value,1);
    }
    else if( PUS_BOOL == type )
    {
        bool value;
        if( PUS_NO_ERROR != pus_paramToBool(&value, param))
            return mp_const_none;
        return mp_obj_new_bool(value);
    }
    
    return mp_const_none;
}

//GET NEXT EVENT
STATIC mp_obj_t mymodule_getNextEvent( mp_obj_t py_counter) {
    size_t counter = mp_obj_get_int(py_counter);
    
    pusSt05Event_t event;
    
    mp_obj_t list[2];
    list[0] = mp_const_none;
    list[1] = mp_const_none;    
    
    if (!pus_events_isInitialized())
	{
        return mp_obj_new_list(2, list);
	}
    
    size_t counter2 = counter;
    
    if(PUS_NO_ERROR != pus_st05_getNextBufferEvent(&event, &counter))
        return mp_obj_new_list(2, list);
        
    if( counter != counter2 ) //has changed
    {
        
        mp_obj_t dict = mp_obj_new_dict(3);
       
        mp_obj_dict_store(dict, mp_obj_new_str("id", 2, false) ,  mp_obj_new_int(event.eventId));
        
        extern pusSt05EventInfo_t pus_st05_eventInfoList[];
    
        pusParamType_t type1 = pus_st05_eventInfoList[event.eventId].data.dataType1;
        mp_obj_t data1 = auxFunction_getObjFromParam(event.data.data1, type1);
        mp_obj_dict_store(dict, mp_obj_new_str("data1", 5, false) ,  data1);
        
        pusParamType_t type2 = pus_st05_eventInfoList[event.eventId].data.dataType2;
        mp_obj_t data2 = auxFunction_getObjFromParam(event.data.data2, type2);
        mp_obj_dict_store(dict, mp_obj_new_str("data2", 5, false) ,  data2);
        
        
        list[0] = dict;
        list[1] = mp_obj_new_int(counter);
    }
    
    return mp_obj_new_list(2, list);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(mymodule_getNextEvent_obj, mymodule_getNextEvent);



//GET NEXT EVENT
STATIC mp_obj_t mymodule_getNextEventBlocking( mp_obj_t py_eventId, mp_obj_t py_counter, mp_obj_t py_timeout) {
    size_t counter = mp_obj_get_int(py_counter);
    size_t eventId = mp_obj_get_int(py_eventId);
    double timeout_d = mp_obj_get_float(py_timeout);
    
    pusSt05Event_t event;
    
    mp_obj_t list[2];
    list[0] = mp_const_none;
    list[1] = mp_const_none;    
    
    if (!pus_events_isInitialized())
	{
        return mp_obj_new_list(2, list);
	}
    
    pusTime_t time;
    double time_start, time_now;

    pus_now(&time);
    pusTime_to_double(&time_start, &time);
    
    printf("Now2 %f, +tim %f\n", time_start, time_start+timeout_d);
    
    while(1)
    {
        while(PUS_NO_ERROR != pus_st05_getNextBufferEvent(&event, &counter))
        {
            if( 0 != timeout_d )
            {
                pus_now(&time);
                pusTime_to_double(&time_now, &time);
                if( time_now >= (time_start + timeout_d) )
                {
                    //printf("Timeout reached: Now %f, +tim %f\n", time_now, time_start+timeout_d);
                    return mp_obj_new_list(2, list); //NONE
                }
            }
            //sleep 10ms = 0.01s
            mymodule_sleepInterval(mp_obj_new_float(0.01));            
        }
        
        if( event.eventId == eventId )
        {
            break;
        }
    }
    
    mp_obj_t dict = mp_obj_new_dict(3);
   
    mp_obj_dict_store(dict, mp_obj_new_str("id", 2, false) ,  mp_obj_new_int(event.eventId));
    
    extern pusSt05EventInfo_t pus_st05_eventInfoList[];

    pusParamType_t type1 = pus_st05_eventInfoList[event.eventId].data.dataType1;
    mp_obj_t data1 = auxFunction_getObjFromParam(event.data.data1, type1);
    mp_obj_dict_store(dict, mp_obj_new_str("data1", 5, false) ,  data1);
    
    pusParamType_t type2 = pus_st05_eventInfoList[event.eventId].data.dataType2;
    mp_obj_t data2 = auxFunction_getObjFromParam(event.data.data2, type2);
    mp_obj_dict_store(dict, mp_obj_new_str("data2", 5, false) ,  data2);
    
    
    list[0] = dict;
    list[1] = mp_obj_new_int(counter);
    return mp_obj_new_list(2, list);

}
STATIC MP_DEFINE_CONST_FUN_OBJ_3(mymodule_getNextEventBlocking_obj, mymodule_getNextEventBlocking);


// Execute ST08 Function
STATIC mp_obj_t mymodule_executeSt08Function( mp_obj_t py_functionId ) {
    pusSt08FunctiontId_t functionId = mp_obj_get_int(py_functionId);
        
    if (!pus_st08_isInitialized())
	{
		return mp_const_false;
	}
    
    if( PUS_NO_ERROR == pus_st08_performAFunction(functionId))
    {
        return mp_const_true;
    }
    
    return mp_const_false;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(mymodule_executeSt08Function_obj, mymodule_executeSt08Function);


STATIC const mp_map_elem_t obcpModule_globals_table[] = {
    { MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_mymodule) },
    /*{ MP_OBJ_NEW_QSTR(MP_QSTR_createObj), (mp_obj_t)&mymodule_createObj_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_incrObj), (mp_obj_t)&mymodule_incrObj_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_delObj), (mp_obj_t)&mymodule_delObj_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_wait), (mp_obj_t)&mymodule_wait_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_produce), (mp_obj_t)&mymodule_produce_obj },*/
    { MP_OBJ_NEW_QSTR(MP_QSTR_sleepInterval), (mp_obj_t)&mymodule_sleepInterval_obj },
   // { MP_OBJ_NEW_QSTR(MP_QSTR_testfun), (mp_obj_t)&mymodule_testfun_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_getDictHkParams), (mp_obj_t)&mymodule_getDictHkParams_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_getDictOnBoardParams), (mp_obj_t)&mymodule_getDictOnBoardParams_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_getDictEvents), (mp_obj_t)&mymodule_getDictEvents_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_getDictFunctions), (mp_obj_t)&mymodule_getDictFunctions_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_getHkParamValue), (mp_obj_t)&mymodule_getHkParamValue_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_getOnBoardParamValue), (mp_obj_t)&mymodule_getOnBoardParamValue_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_setHkParamValue), (mp_obj_t)&mymodule_setHkParamValue_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_setOnBoardParamValue), (mp_obj_t)&mymodule_setOnBoardParamValue_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_getTimeNowFloat), (mp_obj_t)&mymodule_getTimeNowFloat_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_getTimeNowList), (mp_obj_t)&mymodule_getTimeNowList_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_timeoutReached), (mp_obj_t)&mymodule_timeoutReached_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_raiseEvent), (mp_obj_t)&mymodule_raiseEvent_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_getNextEvent), (mp_obj_t)&mymodule_getNextEvent_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_getNextEventBlocking), (mp_obj_t)&mymodule_getNextEventBlocking_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_executeSt08Function), (mp_obj_t)&mymodule_executeSt08Function_obj },
};

STATIC MP_DEFINE_CONST_DICT (
    mp_module_obcpModule_globals,
	obcpModule_globals_table
);

const mp_obj_module_t mp_module_obcpModule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&mp_module_obcpModule_globals,
};
