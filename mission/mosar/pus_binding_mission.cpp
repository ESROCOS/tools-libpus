/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "../pylib/pybind11/pybind11.h"
#include "../pylib/pybind11/stl.h"

//#include "pus_types.h"

#include "pus_apid.h"
#include "pus_mission_types.h"

#include "pus_time.h"
#include "pus_events.h"
#include "pus_notify.h"

#include "pus_st200_packets.h"
#include "pus_st210_packets.h"
#include "pus_st220_packets.h"

#include <vector>
namespace py = pybind11;

//Wrapper functions 
pusError_t pus_tc_200_19_createMissionRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
    pusSt200_19_Goal goal{};
    goal.goal.predicate = asn1Sccmission_place;
    return pus_tc_200_19_createMissionRequest(outTc, apid, sequenceCount, goal);
} 
pusError_t pus_tc_200_13_createSodmissionRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
    pusSt200_13_Goal goal{};
    goal.goal.predicate = asn1Sccsodmission_pick;
    return pus_tc_200_13_createSodmissionRequest(outTc, apid, sequenceCount, goal);
} 
pusError_t pus_tc_200_1_createHotdockcmdRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
    pusSt200_1_Goal goal{};
    goal.goal.predicate = asn1Scchotdockcmd_sendstate;
    return pus_tc_200_1_createHotdockcmdRequest(outTc, apid, sequenceCount, goal);
} 
pusError_t pus_tc_200_5_createWmcmdRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
    pusSt200_5_Goal goal{};
    goal.goal.predicate = asn1Sccwmcmd_movetohd;
    return pus_tc_200_5_createWmcmdRequest(outTc, apid, sequenceCount, goal);
} 
pusError_t pus_tc_200_9_createBasecmdRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
    pusSt200_9_Goal goal{};
    goal.goal.predicate = asn1Sccbasecmd_switchbase;
    return pus_tc_200_9_createBasecmdRequest(outTc, apid, sequenceCount, goal);
} 
pusError_t pus_tc_200_11_createEfcmdRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
    pusSt200_11_Goal goal{};
    goal.goal.predicate = asn1Sccefcmd_pick;
    return pus_tc_200_11_createEfcmdRequest(outTc, apid, sequenceCount, goal);
}

// ST 210
pusError_t  pus_tc_210_72_createCartGoal_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId)
{
    asn1SccPusTC_210_72_Data_desiredPos pos = {0};
    return pus_tc_210_72_createCartGoal(outTc, apid, sequenceCount, smId, componentId, pos);
}

std::vector<double> pus_tc_210_72_getParamDesiredPose_(const pusPacket_t* inTC)
{
    asn1SccPusTC_210_72_Data_desiredPos pos;
    std::vector<double> vec;
    (void) pus_tc_210_72_getParamDesiredPos(inTC, &pos);

    for(int i = 0; i < 12; i++)
    {
        vec.push_back(pos.arr[i]);
    }
    return vec;
}

pusError_t pus_tc_210_72_setParamDesiredPose_(pusPacket_t* inTC, std::vector<double> arr)
{
    for(int i = 0; i < 12; i++)
    {
        inTC->data.u.tcData.data.u.st_210_72.desiredPos.arr[i] = arr[i];
    }

    return PUS_NO_ERROR;
}

// ST220

pusError_t pus_tc_220_1_createNewTargetState_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
    pusSt220_stateID state = asn1Sccidle;
    return pus_tc_220_1_createNewTargetState(outTc, apid, sequenceCount, state);
}

asn1SccPusUInt32 pus_tc_220_1_getTargetState_(pusPacket_t* inTc)
{
    return (asn1SccPusUInt32) pus_tc_220_1_getTargetState(inTc);
}
void pus_tc_220_1_setTargetState_(pusPacket_t* inTc, asn1SccPusUInt32 state)
{
    (void) pus_tc_220_1_setTargetState(inTc, (pusSt220_stateID)state);
}
asn1SccPusUInt32 pus_tm_220_3_getCurrentState_(pusPacket_t* inTc)
{
    return (asn1SccPusUInt32) pus_tm_220_3_getCurrentState(inTc);
}

void init_mission_module(py::module &m)
{
    // ST 220
    m.doc() = "pus_st200_timelineControl";

    
    py::class_<asn1SccBoold>(m, "asn1SccBoold")
        .def(py::init<>())
        .def_readwrite("value", &asn1SccBoold::value);
    
    py::class_<asn1SccIntd>(m, "asn1SccIntd")
        .def(py::init<>())
        .def_readwrite("value", &asn1SccIntd::value);
    
    py::class_<asn1SccFloatd>(m, "asn1SccFloatd")
        .def(py::init<>())
        .def_readwrite("value", &asn1SccFloatd::value);
    
    py::class_<asn1SccStringd>(m, "asn1SccStringd")
        .def(py::init<>())
        .def_readwrite("value", &asn1SccStringd::value);
    
    py::class_<asn1SccInt2d>(m, "asn1SccInt2d")
        .def(py::init<>())
        .def_readwrite("x", &asn1SccInt2d::x)
        .def_readwrite("y", &asn1SccInt2d::y);
    
    py::class_<asn1SccInt3d>(m, "asn1SccInt3d")
        .def(py::init<>())
        .def_readwrite("x", &asn1SccInt3d::x)
        .def_readwrite("y", &asn1SccInt3d::y)
        .def_readwrite("z", &asn1SccInt3d::z);
    
    py::class_<asn1SccPosition3D>(m, "asn1SccPosition3D")
        .def(py::init<>())
        .def_readwrite("x", &asn1SccPosition3D::x)
        .def_readwrite("y", &asn1SccPosition3D::y);
    
    py::class_<asn1SccQuaterniond>(m, "asn1SccQuaterniond")
        .def(py::init<>())
        .def_readwrite("x", &asn1SccQuaterniond::x)
        .def_readwrite("y", &asn1SccQuaterniond::y);
    

    py::class_<asn1SccIntegerIntervalDomain>(m, "asn1SccIntegerIntervalDomain")
        .def(py::init<>())
        .def_readwrite("min", &asn1SccIntegerIntervalDomain::min)
        .def_readwrite("max", &asn1SccIntegerIntervalDomain::max);
    
    py::class_<asn1SccT_String>(m, "asn1SccT_String", py::buffer_protocol())
    .def(py::init([](py::buffer b) {
        py::buffer_info info = b.request();

        asn1SccT_String* newStr = new asn1SccT_String;
        int i = 0;
        for(i = 0; i < info.shape[0]; i++)
        {
            newStr->arr[i] = (static_cast<byte*>(info.ptr))[i];
        }
        newStr->arr[i] = '\0';
        newStr->nCount = info.shape[0] + 1;
        return newStr;
    }))
    .def_buffer([](asn1SccT_String &s) -> py::buffer_info {
            return py::buffer_info(
                s.arr,                               /* Pointer to buffer */
                sizeof(byte),                          /* Size of one scalar */
                py::format_descriptor<unsigned char>::format(), /* Python struct-style format descriptor */
                1,                                      /* Number of dimensions */
                { s.nCount },                 /* Buffer dimensions */
                { sizeof(byte) }
            );
    });
    py::enum_<asn1SccActionstatusEnum>(m, "asn1SccActionstatusEnum")
        .value("success", asn1SccActionstatusEnum::asn1Sccactionstatus_success)
        .value("failed", asn1SccActionstatusEnum::asn1Sccactionstatus_failed)
        .value("notachievable", asn1SccActionstatusEnum::asn1Sccactionstatus_notachievable)
        .value("notenoughtime", asn1SccActionstatusEnum::asn1Sccactionstatus_notenoughtime)
        .value("unknown", asn1SccActionstatusEnum::asn1Sccactionstatus_unknown)
        .export_values();
    
    py::enum_<asn1SccStateidEnum>(m, "asn1SccStateidEnum")
        .value("offline", asn1SccStateidEnum::asn1Sccstateid_offline)
        .value("idle", asn1SccStateidEnum::asn1Sccstateid_idle)
        .value("latched", asn1SccStateidEnum::asn1Sccstateid_latched)
        .value("locked", asn1SccStateidEnum::asn1Sccstateid_locked)
        .value("connected", asn1SccStateidEnum::asn1Sccstateid_connected)
        .value("unknown", asn1SccStateidEnum::asn1Sccstateid_unknown)
        .export_values();
    
    py::enum_<asn1SccCommandstateEnum>(m, "asn1SccCommandstateEnum")
        .value("offline", asn1SccCommandstateEnum::asn1Scccommandstate_offline)
        .value("idle", asn1SccCommandstateEnum::asn1Scccommandstate_idle)
        .value("latched", asn1SccCommandstateEnum::asn1Scccommandstate_latched)
        .value("connected", asn1SccCommandstateEnum::asn1Scccommandstate_connected)
        .value("unknown", asn1SccCommandstateEnum::asn1Scccommandstate_unknown)
        .export_values();
    
    py::enum_<asn1SccYawidEnum>(m, "asn1SccYawidEnum")
        .value("yaw0", asn1SccYawidEnum::asn1Sccyawid_yaw0)
        .value("yaw90", asn1SccYawidEnum::asn1Sccyawid_yaw90)
        .value("yaw180", asn1SccYawidEnum::asn1Sccyawid_yaw180)
        .value("yaw270", asn1SccYawidEnum::asn1Sccyawid_yaw270)
        .value("unknown", asn1SccYawidEnum::asn1Sccyawid_unknown)
        .export_values();
    

    py::enum_<asn1SccHotdockcmdPred>(m, "asn1SccHotdockcmdPred")
        .value("idle", asn1SccHotdockcmdPred::asn1Scchotdockcmd_idle)
        .value("sendstate", asn1SccHotdockcmdPred::asn1Scchotdockcmd_sendstate)
        .value("cancel", asn1SccHotdockcmdPred::asn1Scchotdockcmd_cancel)
        .value("unknown", asn1SccHotdockcmdPred::asn1Scchotdockcmd_unknown)
        .export_values();

    py::enum_<asn1SccHotdockstatusPred>(m, "asn1SccHotdockstatusPred")
        .value("status", asn1SccHotdockstatusPred::asn1Scchotdockstatus_status)
        .value("cancel", asn1SccHotdockstatusPred::asn1Scchotdockstatus_cancel)
        .value("unknown", asn1SccHotdockstatusPred::asn1Scchotdockstatus_unknown)
        .export_values();

    py::enum_<asn1SccWmcmdPred>(m, "asn1SccWmcmdPred")
        .value("idle", asn1SccWmcmdPred::asn1Sccwmcmd_idle)
        .value("movetohd", asn1SccWmcmdPred::asn1Sccwmcmd_movetohd)
        .value("movetoslot", asn1SccWmcmdPred::asn1Sccwmcmd_movetoslot)
        .value("error", asn1SccWmcmdPred::asn1Sccwmcmd_error)
        .value("cancel", asn1SccWmcmdPred::asn1Sccwmcmd_cancel)
        .value("unknown", asn1SccWmcmdPred::asn1Sccwmcmd_unknown)
        .export_values();

    py::enum_<asn1SccWmstatusPred>(m, "asn1SccWmstatusPred")
        .value("status", asn1SccWmstatusPred::asn1Sccwmstatus_status)
        .value("cancel", asn1SccWmstatusPred::asn1Sccwmstatus_cancel)
        .value("unknown", asn1SccWmstatusPred::asn1Sccwmstatus_unknown)
        .export_values();

    py::enum_<asn1SccBasecmdPred>(m, "asn1SccBasecmdPred")
        .value("baseat", asn1SccBasecmdPred::asn1Sccbasecmd_baseat)
        .value("switchbase", asn1SccBasecmdPred::asn1Sccbasecmd_switchbase)
        .value("error", asn1SccBasecmdPred::asn1Sccbasecmd_error)
        .value("cancel", asn1SccBasecmdPred::asn1Sccbasecmd_cancel)
        .value("unknown", asn1SccBasecmdPred::asn1Sccbasecmd_unknown)
        .export_values();

    py::enum_<asn1SccEfcmdPred>(m, "asn1SccEfcmdPred")
        .value("idle", asn1SccEfcmdPred::asn1Sccefcmd_idle)
        .value("picked", asn1SccEfcmdPred::asn1Sccefcmd_picked)
        .value("error", asn1SccEfcmdPred::asn1Sccefcmd_error)
        .value("pick", asn1SccEfcmdPred::asn1Sccefcmd_pick)
        .value("drop", asn1SccEfcmdPred::asn1Sccefcmd_drop)
        .value("cancel", asn1SccEfcmdPred::asn1Sccefcmd_cancel)
        .value("unknown", asn1SccEfcmdPred::asn1Sccefcmd_unknown)
        .export_values();

    py::enum_<asn1SccSodmissionPred>(m, "asn1SccSodmissionPred")
        .value("picked", asn1SccSodmissionPred::asn1Sccsodmission_picked)
        .value("idle", asn1SccSodmissionPred::asn1Sccsodmission_idle)
        .value("pick", asn1SccSodmissionPred::asn1Sccsodmission_pick)
        .value("dropsm", asn1SccSodmissionPred::asn1Sccsodmission_dropsm)
        .value("changebase", asn1SccSodmissionPred::asn1Sccsodmission_changebase)
        .value("executefromfile", asn1SccSodmissionPred::asn1Sccsodmission_executefromfile)
        .value("cancel", asn1SccSodmissionPred::asn1Sccsodmission_cancel)
        .value("unknown", asn1SccSodmissionPred::asn1Sccsodmission_unknown)
        .export_values();

    py::enum_<asn1SccSodplannerPred>(m, "asn1SccSodplannerPred")
        .value("idle", asn1SccSodplannerPred::asn1Sccsodplanner_idle)
        .value("failed", asn1SccSodplannerPred::asn1Sccsodplanner_failed)
        .value("planning", asn1SccSodplannerPred::asn1Sccsodplanner_planning)
        .value("fault", asn1SccSodplannerPred::asn1Sccsodplanner_fault)
        .value("cancel", asn1SccSodplannerPred::asn1Sccsodplanner_cancel)
        .value("unknown", asn1SccSodplannerPred::asn1Sccsodplanner_unknown)
        .export_values();

    py::enum_<asn1SccPlannerPred>(m, "asn1SccPlannerPred")
        .value("idle", asn1SccPlannerPred::asn1Sccplanner_idle)
        .value("planning", asn1SccPlannerPred::asn1Sccplanner_planning)
        .value("fault", asn1SccPlannerPred::asn1Sccplanner_fault)
        .value("cancel", asn1SccPlannerPred::asn1Sccplanner_cancel)
        .value("unknown", asn1SccPlannerPred::asn1Sccplanner_unknown)
        .export_values();

    py::enum_<asn1SccMissionPred>(m, "asn1SccMissionPred")
        .value("idle", asn1SccMissionPred::asn1Sccmission_idle)
        .value("place", asn1SccMissionPred::asn1Sccmission_place)
        .value("loadinge3plan", asn1SccMissionPred::asn1Sccmission_loadinge3plan)
        .value("cancel", asn1SccMissionPred::asn1Sccmission_cancel)
        .value("unknown", asn1SccMissionPred::asn1Sccmission_unknown)
        .export_values();
    
    
    

    py::class_<asn1SccPlannerstatus>(m, "asn1SccPlannerstatus")
        .def(py::init<>())
        .def_readwrite("predicate", &asn1SccPlannerstatus::predicate)
        .def_readwrite("inittime", &asn1SccPlannerstatus::inittime)
        .def_readwrite("endtime", &asn1SccPlannerstatus::endtime);

    

    py::class_<pusSt200_18_Observation>(m, "pusSt200_18_Observation")
        .def(py::init<>())
        .def_readwrite("observation", &pusSt200_18_Observation::observation)
        .def_readwrite("agent", &pusSt200_18_Observation::agent);

    
    

    py::class_<asn1SccMissionstatus>(m, "asn1SccMissionstatus")
        .def(py::init<>())
        .def_readwrite("sm", &asn1SccMissionstatus::sm)
        .def_readwrite("slot", &asn1SccMissionstatus::slot)
        .def_readwrite("orientation", &asn1SccMissionstatus::orientation)
        .def_readwrite("file", &asn1SccMissionstatus::file)
        .def_readwrite("predicate", &asn1SccMissionstatus::predicate)
        .def_readwrite("inittime", &asn1SccMissionstatus::inittime)
        .def_readwrite("endtime", &asn1SccMissionstatus::endtime);

    
    py::class_<pusSt200_19_Goal>(m, "pusSt200_19_Goal")
        .def(py::init<>())
        .def_readwrite("goal", &pusSt200_19_Goal::goal)
        .def_readwrite("agent", &pusSt200_19_Goal::agent);

    py::class_<pusSt200_20_Observation>(m, "pusSt200_20_Observation")
        .def(py::init<>())
        .def_readwrite("observation", &pusSt200_20_Observation::observation)
        .def_readwrite("agent", &pusSt200_20_Observation::agent);

    
    

    py::class_<asn1SccSodmissionstatus>(m, "asn1SccSodmissionstatus")
        .def(py::init<>())
        .def_readwrite("face", &asn1SccSodmissionstatus::face)
        .def_readwrite("sm", &asn1SccSodmissionstatus::sm)
        .def_readwrite("status", &asn1SccSodmissionstatus::status)
        .def_readwrite("slot", &asn1SccSodmissionstatus::slot)
        .def_readwrite("orientation", &asn1SccSodmissionstatus::orientation)
        .def_readwrite("filename", &asn1SccSodmissionstatus::filename)
        .def_readwrite("predicate", &asn1SccSodmissionstatus::predicate)
        .def_readwrite("inittime", &asn1SccSodmissionstatus::inittime)
        .def_readwrite("endtime", &asn1SccSodmissionstatus::endtime);

    
    py::class_<pusSt200_13_Goal>(m, "pusSt200_13_Goal")
        .def(py::init<>())
        .def_readwrite("goal", &pusSt200_13_Goal::goal)
        .def_readwrite("agent", &pusSt200_13_Goal::agent);

    py::class_<pusSt200_14_Observation>(m, "pusSt200_14_Observation")
        .def(py::init<>())
        .def_readwrite("observation", &pusSt200_14_Observation::observation)
        .def_readwrite("agent", &pusSt200_14_Observation::agent);

    
    

    py::class_<asn1SccHotdockcmdstatus>(m, "asn1SccHotdockcmdstatus")
        .def(py::init<>())
        .def_readwrite("status", &asn1SccHotdockcmdstatus::status)
        .def_readwrite("sm", &asn1SccHotdockcmdstatus::sm)
        .def_readwrite("hotdock", &asn1SccHotdockcmdstatus::hotdock)
        .def_readwrite("hdstate", &asn1SccHotdockcmdstatus::hdstate)
        .def_readwrite("predicate", &asn1SccHotdockcmdstatus::predicate)
        .def_readwrite("inittime", &asn1SccHotdockcmdstatus::inittime)
        .def_readwrite("endtime", &asn1SccHotdockcmdstatus::endtime);

    
    py::class_<pusSt200_1_Goal>(m, "pusSt200_1_Goal")
        .def(py::init<>())
        .def_readwrite("goal", &pusSt200_1_Goal::goal)
        .def_readwrite("agent", &pusSt200_1_Goal::agent);

    py::class_<pusSt200_2_Observation>(m, "pusSt200_2_Observation")
        .def(py::init<>())
        .def_readwrite("observation", &pusSt200_2_Observation::observation)
        .def_readwrite("agent", &pusSt200_2_Observation::agent);

    
    

    py::class_<asn1SccHotdockstatusstatus>(m, "asn1SccHotdockstatusstatus")
        .def(py::init<>())
        .def_readwrite("pathfile", &asn1SccHotdockstatusstatus::pathfile)
        .def_readwrite("predicate", &asn1SccHotdockstatusstatus::predicate)
        .def_readwrite("inittime", &asn1SccHotdockstatusstatus::inittime)
        .def_readwrite("endtime", &asn1SccHotdockstatusstatus::endtime);

    

    py::class_<pusSt200_4_Observation>(m, "pusSt200_4_Observation")
        .def(py::init<>())
        .def_readwrite("observation", &pusSt200_4_Observation::observation)
        .def_readwrite("agent", &pusSt200_4_Observation::agent);

    
    

    py::class_<asn1SccWmcmdstatus>(m, "asn1SccWmcmdstatus")
        .def(py::init<>())
        .def_readwrite("status", &asn1SccWmcmdstatus::status)
        .def_readwrite("hdid", &asn1SccWmcmdstatus::hdid)
        .def_readwrite("slot", &asn1SccWmcmdstatus::slot)
        .def_readwrite("face", &asn1SccWmcmdstatus::face)
        .def_readwrite("yaw", &asn1SccWmcmdstatus::yaw)
        .def_readwrite("predicate", &asn1SccWmcmdstatus::predicate)
        .def_readwrite("inittime", &asn1SccWmcmdstatus::inittime)
        .def_readwrite("endtime", &asn1SccWmcmdstatus::endtime);

    
    py::class_<pusSt200_5_Goal>(m, "pusSt200_5_Goal")
        .def(py::init<>())
        .def_readwrite("goal", &pusSt200_5_Goal::goal)
        .def_readwrite("agent", &pusSt200_5_Goal::agent);

    py::class_<pusSt200_6_Observation>(m, "pusSt200_6_Observation")
        .def(py::init<>())
        .def_readwrite("observation", &pusSt200_6_Observation::observation)
        .def_readwrite("agent", &pusSt200_6_Observation::agent);

    
    

    py::class_<asn1SccBasecmdstatus>(m, "asn1SccBasecmdstatus")
        .def(py::init<>())
        .def_readwrite("hdid", &asn1SccBasecmdstatus::hdid)
        .def_readwrite("status", &asn1SccBasecmdstatus::status)
        .def_readwrite("predicate", &asn1SccBasecmdstatus::predicate)
        .def_readwrite("inittime", &asn1SccBasecmdstatus::inittime)
        .def_readwrite("endtime", &asn1SccBasecmdstatus::endtime);

    
    py::class_<pusSt200_9_Goal>(m, "pusSt200_9_Goal")
        .def(py::init<>())
        .def_readwrite("goal", &pusSt200_9_Goal::goal)
        .def_readwrite("agent", &pusSt200_9_Goal::agent);

    py::class_<pusSt200_10_Observation>(m, "pusSt200_10_Observation")
        .def(py::init<>())
        .def_readwrite("observation", &pusSt200_10_Observation::observation)
        .def_readwrite("agent", &pusSt200_10_Observation::agent);

    
    

    py::class_<asn1SccEfcmdstatus>(m, "asn1SccEfcmdstatus")
        .def(py::init<>())
        .def_readwrite("status", &asn1SccEfcmdstatus::status)
        .def_readwrite("hdid", &asn1SccEfcmdstatus::hdid)
        .def_readwrite("predicate", &asn1SccEfcmdstatus::predicate)
        .def_readwrite("inittime", &asn1SccEfcmdstatus::inittime)
        .def_readwrite("endtime", &asn1SccEfcmdstatus::endtime);

    
    py::class_<pusSt200_11_Goal>(m, "pusSt200_11_Goal")
        .def(py::init<>())
        .def_readwrite("goal", &pusSt200_11_Goal::goal)
        .def_readwrite("agent", &pusSt200_11_Goal::agent);

    py::class_<pusSt200_12_Observation>(m, "pusSt200_12_Observation")
        .def(py::init<>())
        .def_readwrite("observation", &pusSt200_12_Observation::observation)
        .def_readwrite("agent", &pusSt200_12_Observation::agent);

    
    

    py::class_<asn1SccWmstatusstatus>(m, "asn1SccWmstatusstatus")
        .def(py::init<>())
        .def_readwrite("pathfile", &asn1SccWmstatusstatus::pathfile)
        .def_readwrite("predicate", &asn1SccWmstatusstatus::predicate)
        .def_readwrite("inittime", &asn1SccWmstatusstatus::inittime)
        .def_readwrite("endtime", &asn1SccWmstatusstatus::endtime);

    

    py::class_<pusSt200_8_Observation>(m, "pusSt200_8_Observation")
        .def(py::init<>())
        .def_readwrite("observation", &pusSt200_8_Observation::observation)
        .def_readwrite("agent", &pusSt200_8_Observation::agent);

    
    

    py::class_<asn1SccSodplannerstatus>(m, "asn1SccSodplannerstatus")
        .def(py::init<>())
        .def_readwrite("predicate", &asn1SccSodplannerstatus::predicate)
        .def_readwrite("inittime", &asn1SccSodplannerstatus::inittime)
        .def_readwrite("endtime", &asn1SccSodplannerstatus::endtime);

    

    py::class_<pusSt200_16_Observation>(m, "pusSt200_16_Observation")
        .def(py::init<>())
        .def_readwrite("observation", &pusSt200_16_Observation::observation)
        .def_readwrite("agent", &pusSt200_16_Observation::agent);

    

     
    m.def("pus_tm_200_18_createPlannerReport", &pus_tm_200_18_createPlannerReport, "pus_tm_200_18_createPlannerReport");
    m.def("pus_tm_200_18_getPlannerObservation", &pus_tm_200_18_getPlannerObservation, "pus_tm_200_18_getPlannerObservation");
     
    m.def("pus_tc_200_19_createMissionRequest_", &pus_tc_200_19_createMissionRequest_, "pus_tc_200_19_createMissionRequest_");
    m.def("pus_tc_200_19_getMissionGoal", &pus_tc_200_19_getMissionGoal, "pus_tc_200_19_getMissionGoal");
    m.def("pus_tc_200_19_setMissionGoal", &pus_tc_200_19_setMissionGoal, "pus_tc_200_19_setMissionGoal"); 
    m.def("pus_tm_200_20_createMissionReport", &pus_tm_200_20_createMissionReport, "pus_tm_200_20_createMissionReport");
    m.def("pus_tm_200_20_getMissionObservation", &pus_tm_200_20_getMissionObservation, "pus_tm_200_20_getMissionObservation");
     
    m.def("pus_tc_200_13_createSodmissionRequest_", &pus_tc_200_13_createSodmissionRequest_, "pus_tc_200_13_createSodmissionRequest_");
    m.def("pus_tc_200_13_getSodmissionGoal", &pus_tc_200_13_getSodmissionGoal, "pus_tc_200_13_getSodmissionGoal");
    m.def("pus_tc_200_13_setSodmissionGoal", &pus_tc_200_13_setSodmissionGoal, "pus_tc_200_13_setSodmissionGoal"); 
    m.def("pus_tm_200_14_createSodmissionReport", &pus_tm_200_14_createSodmissionReport, "pus_tm_200_14_createSodmissionReport");
    m.def("pus_tm_200_14_getSodmissionObservation", &pus_tm_200_14_getSodmissionObservation, "pus_tm_200_14_getSodmissionObservation");
     
    m.def("pus_tc_200_1_createHotdockcmdRequest_", &pus_tc_200_1_createHotdockcmdRequest_, "pus_tc_200_1_createHotdockcmdRequest_");
    m.def("pus_tc_200_1_getHotdockcmdGoal", &pus_tc_200_1_getHotdockcmdGoal, "pus_tc_200_1_getHotdockcmdGoal");
    m.def("pus_tc_200_1_setHotdockcmdGoal", &pus_tc_200_1_setHotdockcmdGoal, "pus_tc_200_1_setHotdockcmdGoal"); 
    m.def("pus_tm_200_2_createHotdockcmdReport", &pus_tm_200_2_createHotdockcmdReport, "pus_tm_200_2_createHotdockcmdReport");
    m.def("pus_tm_200_2_getHotdockcmdObservation", &pus_tm_200_2_getHotdockcmdObservation, "pus_tm_200_2_getHotdockcmdObservation");
     
    m.def("pus_tm_200_4_createHotdockstatusReport", &pus_tm_200_4_createHotdockstatusReport, "pus_tm_200_4_createHotdockstatusReport");
    m.def("pus_tm_200_4_getHotdockstatusObservation", &pus_tm_200_4_getHotdockstatusObservation, "pus_tm_200_4_getHotdockstatusObservation");
     
    m.def("pus_tc_200_5_createWmcmdRequest_", &pus_tc_200_5_createWmcmdRequest_, "pus_tc_200_5_createWmcmdRequest_");
    m.def("pus_tc_200_5_getWmcmdGoal", &pus_tc_200_5_getWmcmdGoal, "pus_tc_200_5_getWmcmdGoal");
    m.def("pus_tc_200_5_setWmcmdGoal", &pus_tc_200_5_setWmcmdGoal, "pus_tc_200_5_setWmcmdGoal"); 
    m.def("pus_tm_200_6_createWmcmdReport", &pus_tm_200_6_createWmcmdReport, "pus_tm_200_6_createWmcmdReport");
    m.def("pus_tm_200_6_getWmcmdObservation", &pus_tm_200_6_getWmcmdObservation, "pus_tm_200_6_getWmcmdObservation");
     
    m.def("pus_tc_200_9_createBasecmdRequest_", &pus_tc_200_9_createBasecmdRequest_, "pus_tc_200_9_createBasecmdRequest_");
    m.def("pus_tc_200_9_getBasecmdGoal", &pus_tc_200_9_getBasecmdGoal, "pus_tc_200_9_getBasecmdGoal");
    m.def("pus_tc_200_9_setBasecmdGoal", &pus_tc_200_9_setBasecmdGoal, "pus_tc_200_9_setBasecmdGoal"); 
    m.def("pus_tm_200_10_createBasecmdReport", &pus_tm_200_10_createBasecmdReport, "pus_tm_200_10_createBasecmdReport");
    m.def("pus_tm_200_10_getBasecmdObservation", &pus_tm_200_10_getBasecmdObservation, "pus_tm_200_10_getBasecmdObservation");
     
    m.def("pus_tc_200_11_createEfcmdRequest_", &pus_tc_200_11_createEfcmdRequest_, "pus_tc_200_11_createEfcmdRequest_");
    m.def("pus_tc_200_11_getEfcmdGoal", &pus_tc_200_11_getEfcmdGoal, "pus_tc_200_11_getEfcmdGoal");
    m.def("pus_tc_200_11_setEfcmdGoal", &pus_tc_200_11_setEfcmdGoal, "pus_tc_200_11_setEfcmdGoal"); 
    m.def("pus_tm_200_12_createEfcmdReport", &pus_tm_200_12_createEfcmdReport, "pus_tm_200_12_createEfcmdReport");
    m.def("pus_tm_200_12_getEfcmdObservation", &pus_tm_200_12_getEfcmdObservation, "pus_tm_200_12_getEfcmdObservation");
     
    m.def("pus_tm_200_8_createWmstatusReport", &pus_tm_200_8_createWmstatusReport, "pus_tm_200_8_createWmstatusReport");
    m.def("pus_tm_200_8_getWmstatusObservation", &pus_tm_200_8_getWmstatusObservation, "pus_tm_200_8_getWmstatusObservation");
     
    m.def("pus_tm_200_16_createSodplannerReport", &pus_tm_200_16_createSodplannerReport, "pus_tm_200_16_createSodplannerReport");
    m.def("pus_tm_200_16_getSodplannerObservation", &pus_tm_200_16_getSodplannerObservation, "pus_tm_200_16_getSodplannerObservation");
    // ST 210


    /* R_ICU_SPW_PNP */
    m.def("pus_tc_210_1_createSpwRoutingTableSetEntry", &pus_tc_210_1_createSpwRoutingTableSetEntry,"pus_tc_210_1_createSpwRoutingTableSetEntry");
    m.def("pus_tc_210_1_getParamSM_ID", &pus_tc_210_1_getParamSM_ID, "pus_tc_210_1_getParamSM_ID");
    m.def("pus_tc_210_1_setParamSM_ID", &pus_tc_210_1_setParamSM_ID, "pus_tc_210_1_setParamSM_ID");
    m.def("pus_tc_210_1_getParamCOMP_ID", &pus_tc_210_1_getParamCOMP_ID, "pus_tc_210_1_getParamCOMP_ID");
    m.def("pus_tc_210_1_setParamCOMP_ID", &pus_tc_210_1_setParamCOMP_ID, "pus_tc_210_1_setParamCOMP_ID");
    m.def("pus_tc_210_1_getParamRoutingTableIndex", &pus_tc_210_1_getParamRoutingTableIndex, "pus_tc_210_1_getParamRoutingTableIndex");
    m.def("pus_tc_210_1_setParamRoutingTableIndex", &pus_tc_210_1_setParamRoutingTableIndex, "pus_tc_210_1_setParamRoutingTableIndex");
    m.def("pus_tc_210_1_getParamRoutingTableDirection", &pus_tc_210_1_getParamRoutingTableDirection, "pus_tc_210_1_getParamRoutingTableDirection");
    m.def("pus_tc_210_1_setParamRoutingTableDirection", &pus_tc_210_1_setParamRoutingTableDirection, "pus_tc_210_1_setParamRoutingTableDirection");
    m.def("pus_tc_210_1_getParamTrafficPriority", &pus_tc_210_1_getParamTrafficPriority, "pus_tc_210_1_getParamTrafficPriority");
    m.def("pus_tc_210_1_setParamTrafficPriority", &pus_tc_210_1_setParamTrafficPriority, "pus_tc_210_1_setParamTrafficPriority");

    m.def("pus_tc_210_2_createSpwPnpSetOwnerFields", &pus_tc_210_2_createSpwPnpSetOwnerFields,"pus_tc_210_2_createSpwPnpSetOwnerFields");
    m.def("pus_tc_210_2_getParamSM_ID", &pus_tc_210_2_getParamSM_ID, "pus_tc_210_2_getParamSM_ID");
    m.def("pus_tc_210_2_setParamSM_ID", &pus_tc_210_2_setParamSM_ID, "pus_tc_210_2_setParamSM_ID");
    m.def("pus_tc_210_2_getParamCOMP_ID", &pus_tc_210_2_getParamCOMP_ID, "pus_tc_210_2_getParamCOMP_ID");
    m.def("pus_tc_210_2_setParamCOMP_ID", &pus_tc_210_2_setParamCOMP_ID, "pus_tc_210_2_setParamCOMP_ID");
    m.def("pus_tc_210_2_getParamSetOwner", &pus_tc_210_2_getParamSetOwner, "pus_tc_210_2_getParamSetOwner");
    m.def("pus_tc_210_2_setParamSetOwner", &pus_tc_210_2_setParamSetOwner, "pus_tc_210_2_setParamSetOwner");


    /* R_ICU */
    m.def("pus_tc_210_11_createConfigureTimeEpoch", &pus_tc_210_11_createConfigureTimeEpoch,"pus_tc_210_11_createConfigureTimeEpoch");
    m.def("pus_tc_210_11_getParamSM_ID", &pus_tc_210_11_getParamSM_ID, "pus_tc_210_11_getParamSM_ID");
    m.def("pus_tc_210_11_setParamSM_ID", &pus_tc_210_11_setParamSM_ID, "pus_tc_210_11_setParamSM_ID");
    m.def("pus_tc_210_11_getParamCOMP_ID", &pus_tc_210_11_getParamCOMP_ID, "pus_tc_210_11_getParamCOMP_ID");
    m.def("pus_tc_210_11_setParamCOMP_ID", &pus_tc_210_11_setParamCOMP_ID, "pus_tc_210_11_setParamCOMP_ID");
    m.def("pus_tc_210_11_getParamSecsSinceEpoch", &pus_tc_210_11_getParamSecsSinceEpoch, "pus_tc_210_11_getParamSecsSinceEpoch");
    m.def("pus_tc_210_11_setParamSecsSinceEpoch", &pus_tc_210_11_setParamSecsSinceEpoch, "pus_tc_210_11_setParamSecsSinceEpoch");
    m.def("pus_tc_210_11_getParamNanosecsSinceEpoch", &pus_tc_210_11_getParamNanosecsSinceEpoch, "pus_tc_210_11_getParamNanosecsSinceEpoch");
    m.def("pus_tc_210_11_setParamNanosecsSinceEpoch", &pus_tc_210_11_setParamNanosecsSinceEpoch, "pus_tc_210_11_setParamNanosecsSinceEpoch");

    m.def("pus_tc_210_12_createSetLeds", &pus_tc_210_12_createSetLeds,"pus_tc_210_12_createSetLeds");
    m.def("pus_tc_210_12_getParamSM_ID", &pus_tc_210_12_getParamSM_ID, "pus_tc_210_12_getParamSM_ID");
    m.def("pus_tc_210_12_setParamSM_ID", &pus_tc_210_12_setParamSM_ID, "pus_tc_210_12_setParamSM_ID");
    m.def("pus_tc_210_12_getParamCOMP_ID", &pus_tc_210_12_getParamCOMP_ID, "pus_tc_210_12_getParamCOMP_ID");
    m.def("pus_tc_210_12_setParamCOMP_ID", &pus_tc_210_12_setParamCOMP_ID, "pus_tc_210_12_setParamCOMP_ID");
    m.def("pus_tc_210_12_getParamSetLeds", &pus_tc_210_12_getParamSetLeds, "pus_tc_210_12_getParamSetLeds");
    m.def("pus_tc_210_12_setParamSetLeds", &pus_tc_210_12_setParamSetLeds, "pus_tc_210_12_setParamSetLeds");

    /* HOTDOCK */
    m.def("pus_tc_210_21_createSetHouskeepingDataRate", &pus_tc_210_21_createSetHouskeepingDataRate,"pus_tc_210_21_createSetHouskeepingDataRate");
    m.def("pus_tc_210_21_getParamSM_ID", &pus_tc_210_21_getParamSM_ID, "pus_tc_210_21_getParamSM_ID");
    m.def("pus_tc_210_21_setParamSM_ID", &pus_tc_210_21_setParamSM_ID, "pus_tc_210_21_setParamSM_ID");
    m.def("pus_tc_210_21_getParamCOMP_ID", &pus_tc_210_21_getParamCOMP_ID, "pus_tc_210_21_getParamCOMP_ID");
    m.def("pus_tc_210_21_setParamCOMP_ID", &pus_tc_210_21_setParamCOMP_ID, "pus_tc_210_21_setParamCOMP_ID");
    m.def("pus_tc_210_21_getParamSUBCOMP_ID", &pus_tc_210_21_getParamSUBCOMP_ID, "pus_tc_210_21_getParamSUBCOMP_ID");
    m.def("pus_tc_210_21_setParamSUBCOMP_ID", &pus_tc_210_21_setParamSUBCOMP_ID, "pus_tc_210_21_setParamSUBCOMP_ID");
    m.def("pus_tc_210_21_getParamPollingHkTm", &pus_tc_210_21_getParamPollingHkTm, "pus_tc_210_21_getParamPollingHkTm");
    m.def("pus_tc_210_21_setParamPollingHkTm", &pus_tc_210_21_setParamPollingHkTm, "pus_tc_210_21_setParamPollingHkTm");

    m.def("pus_tc_210_22_createGoToState", &pus_tc_210_22_createGoToState,"pus_tc_210_22_createGoToState");
    m.def("pus_tc_210_22_getParamSM_ID", &pus_tc_210_22_getParamSM_ID, "pus_tc_210_22_getParamSM_ID");
    m.def("pus_tc_210_22_setParamSM_ID", &pus_tc_210_22_setParamSM_ID, "pus_tc_210_22_setParamSM_ID");
    m.def("pus_tc_210_22_getParamCOMP_ID", &pus_tc_210_22_getParamCOMP_ID, "pus_tc_210_22_getParamCOMP_ID");
    m.def("pus_tc_210_22_setParamCOMP_ID", &pus_tc_210_22_setParamCOMP_ID, "pus_tc_210_22_setParamCOMP_ID");
    m.def("pus_tc_210_22_getParamSUBCOMP_ID", &pus_tc_210_22_getParamSUBCOMP_ID, "pus_tc_210_22_getParamSUBCOMP_ID");
    m.def("pus_tc_210_22_setParamSUBCOMP_ID", &pus_tc_210_22_setParamSUBCOMP_ID, "pus_tc_210_22_setParamSUBCOMP_ID");
    m.def("pus_tc_210_22_getParamTargetState", &pus_tc_210_22_getParamTargetState, "pus_tc_210_22_getParamTargetState");
    m.def("pus_tc_210_22_setParamTargetState", &pus_tc_210_22_setParamTargetState, "pus_tc_210_22_setParamTargetState");

    m.def("pus_tc_210_23_createCommandP15VLine", &pus_tc_210_23_createCommandP15VLine,"pus_tc_210_23_createCommandP15VLine");
    m.def("pus_tc_210_23_getParamSM_ID", &pus_tc_210_23_getParamSM_ID, "pus_tc_210_23_getParamSM_ID");
    m.def("pus_tc_210_23_setParamSM_ID", &pus_tc_210_23_setParamSM_ID, "pus_tc_210_23_setParamSM_ID");
    m.def("pus_tc_210_23_getParamCOMP_ID", &pus_tc_210_23_getParamCOMP_ID, "pus_tc_210_23_getParamCOMP_ID");
    m.def("pus_tc_210_23_setParamCOMP_ID", &pus_tc_210_23_setParamCOMP_ID, "pus_tc_210_23_setParamCOMP_ID");
    m.def("pus_tc_210_23_getParamSUBCOMP_ID", &pus_tc_210_23_getParamSUBCOMP_ID, "pus_tc_210_23_getParamSUBCOMP_ID");
    m.def("pus_tc_210_23_setParamSUBCOMP_ID", &pus_tc_210_23_setParamSUBCOMP_ID, "pus_tc_210_23_setParamSUBCOMP_ID");
    m.def("pus_tc_210_23_getParamP15vCmd", &pus_tc_210_23_getParamP15vCmd, "pus_tc_210_23_getParamP15vCmd");
    m.def("pus_tc_210_23_setParamP15vCmd", &pus_tc_210_23_setParamP15vCmd, "pus_tc_210_23_setParamP15vCmd");

    m.def("pus_tc_210_24_createCommandP2V5Line", &pus_tc_210_24_createCommandP2V5Line,"pus_tc_210_24_createCommandP2V5Line");
    m.def("pus_tc_210_24_getParamSM_ID", &pus_tc_210_24_getParamSM_ID, "pus_tc_210_24_getParamSM_ID");
    m.def("pus_tc_210_24_setParamSM_ID", &pus_tc_210_24_setParamSM_ID, "pus_tc_210_24_setParamSM_ID");
    m.def("pus_tc_210_24_getParamCOMP_ID", &pus_tc_210_24_getParamCOMP_ID, "pus_tc_210_24_getParamCOMP_ID");
    m.def("pus_tc_210_24_setParamCOMP_ID", &pus_tc_210_24_setParamCOMP_ID, "pus_tc_210_24_setParamCOMP_ID");
    m.def("pus_tc_210_24_getParamSUBCOMP_ID", &pus_tc_210_24_getParamSUBCOMP_ID, "pus_tc_210_24_getParamSUBCOMP_ID");
    m.def("pus_tc_210_24_setParamSUBCOMP_ID", &pus_tc_210_24_setParamSUBCOMP_ID, "pus_tc_210_24_setParamSUBCOMP_ID");
    m.def("pus_tc_210_24_getParamP2v5Cmd", &pus_tc_210_24_getParamP2v5Cmd, "pus_tc_210_24_getParamP2v5Cmd");
    m.def("pus_tc_210_24_setParamP2v5Cmd", &pus_tc_210_24_setParamP2v5Cmd, "pus_tc_210_24_setParamP2v5Cmd");

    m.def("pus_tc_210_25_createCoomdadRelay", &pus_tc_210_25_createCoomdadRelay,"pus_tc_210_25_createCoomdadRelay");
    m.def("pus_tc_210_25_getParamSM_ID", &pus_tc_210_25_getParamSM_ID, "pus_tc_210_25_getParamSM_ID");
    m.def("pus_tc_210_25_setParamSM_ID", &pus_tc_210_25_setParamSM_ID, "pus_tc_210_25_setParamSM_ID");
    m.def("pus_tc_210_25_getParamCOMP_ID", &pus_tc_210_25_getParamCOMP_ID, "pus_tc_210_25_getParamCOMP_ID");
    m.def("pus_tc_210_25_setParamCOMP_ID", &pus_tc_210_25_setParamCOMP_ID, "pus_tc_210_25_setParamCOMP_ID");
    m.def("pus_tc_210_25_getParamSUBCOMP_ID", &pus_tc_210_25_getParamSUBCOMP_ID, "pus_tc_210_25_getParamSUBCOMP_ID");
    m.def("pus_tc_210_25_setParamSUBCOMP_ID", &pus_tc_210_25_setParamSUBCOMP_ID, "pus_tc_210_25_setParamSUBCOMP_ID");
    m.def("pus_tc_210_25_getParamRelayCmd", &pus_tc_210_25_getParamRelayCmd, "pus_tc_210_25_getParamRelayCmd");
    m.def("pus_tc_210_25_setParamRelayCmd", &pus_tc_210_25_setParamRelayCmd, "pus_tc_210_25_setParamRelayCmd");

    m.def("pus_tc_210_26_createSetLvdsPins", &pus_tc_210_26_createSetLvdsPins,"pus_tc_210_26_createSetLvdsPins");
    m.def("pus_tc_210_26_getParamSM_ID", &pus_tc_210_26_getParamSM_ID, "pus_tc_210_26_getParamSM_ID");
    m.def("pus_tc_210_26_setParamSM_ID", &pus_tc_210_26_setParamSM_ID, "pus_tc_210_26_setParamSM_ID");
    m.def("pus_tc_210_26_getParamCOMP_ID", &pus_tc_210_26_getParamCOMP_ID, "pus_tc_210_26_getParamCOMP_ID");
    m.def("pus_tc_210_26_setParamCOMP_ID", &pus_tc_210_26_setParamCOMP_ID, "pus_tc_210_26_setParamCOMP_ID");
    m.def("pus_tc_210_26_getParamSUBCOMP_ID", &pus_tc_210_26_getParamSUBCOMP_ID, "pus_tc_210_26_getParamSUBCOMP_ID");
    m.def("pus_tc_210_26_setParamSUBCOMP_ID", &pus_tc_210_26_setParamSUBCOMP_ID, "pus_tc_210_26_setParamSUBCOMP_ID");
    m.def("pus_tc_210_26_getParamLvdsACmd", &pus_tc_210_26_getParamLvdsACmd, "pus_tc_210_26_getParamLvdsACmd");
    m.def("pus_tc_210_26_setParamLvdsACmd", &pus_tc_210_26_setParamLvdsACmd, "pus_tc_210_26_setParamLvdsACmd");
    m.def("pus_tc_210_26_getParamLvdsBCmd", &pus_tc_210_26_getParamLvdsBCmd, "pus_tc_210_26_getParamLvdsBCmd");
    m.def("pus_tc_210_26_setParamLvdsBCmd", &pus_tc_210_26_setParamLvdsBCmd, "pus_tc_210_26_setParamLvdsBCmd");

    m.def("pus_tc_210_27_createPowerOnOffMotor", &pus_tc_210_27_createPowerOnOffMotor,"pus_tc_210_27_createPowerOnOffMotor");
    m.def("pus_tc_210_27_getParamSM_ID", &pus_tc_210_27_getParamSM_ID, "pus_tc_210_27_getParamSM_ID");
    m.def("pus_tc_210_27_setParamSM_ID", &pus_tc_210_27_setParamSM_ID, "pus_tc_210_27_setParamSM_ID");
    m.def("pus_tc_210_27_getParamCOMP_ID", &pus_tc_210_27_getParamCOMP_ID, "pus_tc_210_27_getParamCOMP_ID");
    m.def("pus_tc_210_27_setParamCOMP_ID", &pus_tc_210_27_setParamCOMP_ID, "pus_tc_210_27_setParamCOMP_ID");
    m.def("pus_tc_210_27_getParamSUBCOMP_ID", &pus_tc_210_27_getParamSUBCOMP_ID, "pus_tc_210_27_getParamSUBCOMP_ID");
    m.def("pus_tc_210_27_setParamSUBCOMP_ID", &pus_tc_210_27_setParamSUBCOMP_ID, "pus_tc_210_27_setParamSUBCOMP_ID");
    m.def("pus_tc_210_27_getParamMotorOnOff", &pus_tc_210_27_getParamMotorOnOff, "pus_tc_210_27_getParamMotorOnOff");
    m.def("pus_tc_210_27_setParamMotorOnOff", &pus_tc_210_27_setParamMotorOnOff, "pus_tc_210_27_setParamMotorOnOff");

    m.def("pus_tc_210_28_createSetMotorSpeed", &pus_tc_210_28_createSetMotorSpeed,"pus_tc_210_28_createSetMotorSpeed");
    m.def("pus_tc_210_28_getParamSM_ID", &pus_tc_210_28_getParamSM_ID, "pus_tc_210_28_getParamSM_ID");
    m.def("pus_tc_210_28_setParamSM_ID", &pus_tc_210_28_setParamSM_ID, "pus_tc_210_28_setParamSM_ID");
    m.def("pus_tc_210_28_getParamCOMP_ID", &pus_tc_210_28_getParamCOMP_ID, "pus_tc_210_28_getParamCOMP_ID");
    m.def("pus_tc_210_28_setParamCOMP_ID", &pus_tc_210_28_setParamCOMP_ID, "pus_tc_210_28_setParamCOMP_ID");
    m.def("pus_tc_210_28_getParamSUBCOMP_ID", &pus_tc_210_28_getParamSUBCOMP_ID, "pus_tc_210_28_getParamSUBCOMP_ID");
    m.def("pus_tc_210_28_setParamSUBCOMP_ID", &pus_tc_210_28_setParamSUBCOMP_ID, "pus_tc_210_28_setParamSUBCOMP_ID");
    m.def("pus_tc_210_28_getParamMotorTargetSpeed", &pus_tc_210_28_getParamMotorTargetSpeed, "pus_tc_210_28_getParamMotorTargetSpeed");
    m.def("pus_tc_210_28_setParamMotorTargetSpeed", &pus_tc_210_28_setParamMotorTargetSpeed, "pus_tc_210_28_setParamMotorTargetSpeed");

    m.def("pus_tc_210_29_createSetMotorDirection", &pus_tc_210_29_createSetMotorDirection,"pus_tc_210_29_createSetMotorDirection");
    m.def("pus_tc_210_29_getParamSM_ID", &pus_tc_210_29_getParamSM_ID, "pus_tc_210_29_getParamSM_ID");
    m.def("pus_tc_210_29_setParamSM_ID", &pus_tc_210_29_setParamSM_ID, "pus_tc_210_29_setParamSM_ID");
    m.def("pus_tc_210_29_getParamCOMP_ID", &pus_tc_210_29_getParamCOMP_ID, "pus_tc_210_29_getParamCOMP_ID");
    m.def("pus_tc_210_29_setParamCOMP_ID", &pus_tc_210_29_setParamCOMP_ID, "pus_tc_210_29_setParamCOMP_ID");
    m.def("pus_tc_210_29_getParamSUBCOMP_ID", &pus_tc_210_29_getParamSUBCOMP_ID, "pus_tc_210_29_getParamSUBCOMP_ID");
    m.def("pus_tc_210_29_setParamSUBCOMP_ID", &pus_tc_210_29_setParamSUBCOMP_ID, "pus_tc_210_29_setParamSUBCOMP_ID");
    m.def("pus_tc_210_29_getParamMotorDirectionSpeed", &pus_tc_210_29_getParamMotorDirectionSpeed, "pus_tc_210_29_getParamMotorDirectionSpeed");
    m.def("pus_tc_210_29_setParamMotorDirectionSpeed", &pus_tc_210_29_setParamMotorDirectionSpeed, "pus_tc_210_29_setParamMotorDirectionSpeed");

    m.def("pus_tc_210_30_createSetMotorCurrentLimit", &pus_tc_210_30_createSetMotorCurrentLimit,"pus_tc_210_30_createSetMotorCurrentLimit");
    m.def("pus_tc_210_30_getParamSM_ID", &pus_tc_210_30_getParamSM_ID, "pus_tc_210_30_getParamSM_ID");
    m.def("pus_tc_210_30_setParamSM_ID", &pus_tc_210_30_setParamSM_ID, "pus_tc_210_30_setParamSM_ID");
    m.def("pus_tc_210_30_getParamCOMP_ID", &pus_tc_210_30_getParamCOMP_ID, "pus_tc_210_30_getParamCOMP_ID");
    m.def("pus_tc_210_30_setParamCOMP_ID", &pus_tc_210_30_setParamCOMP_ID, "pus_tc_210_30_setParamCOMP_ID");
    m.def("pus_tc_210_30_getParamSUBCOMP_ID", &pus_tc_210_30_getParamSUBCOMP_ID, "pus_tc_210_30_getParamSUBCOMP_ID");
    m.def("pus_tc_210_30_setParamSUBCOMP_ID", &pus_tc_210_30_setParamSUBCOMP_ID, "pus_tc_210_30_setParamSUBCOMP_ID");
    m.def("pus_tc_210_30_getParamMotorCurrentLimit", &pus_tc_210_30_getParamMotorCurrentLimit, "pus_tc_210_30_getParamMotorCurrentLimit");
    m.def("pus_tc_210_30_setParamMotorCurrentLimit", &pus_tc_210_30_setParamMotorCurrentLimit, "pus_tc_210_30_setParamMotorCurrentLimit");

    m.def("pus_tc_210_31_createCalibrateController", &pus_tc_210_31_createCalibrateController,"pus_tc_210_31_createCalibrateController");
    m.def("pus_tc_210_31_getParamSM_ID", &pus_tc_210_31_getParamSM_ID, "pus_tc_210_31_getParamSM_ID");
    m.def("pus_tc_210_31_setParamSM_ID", &pus_tc_210_31_setParamSM_ID, "pus_tc_210_31_setParamSM_ID");
    m.def("pus_tc_210_31_getParamCOMP_ID", &pus_tc_210_31_getParamCOMP_ID, "pus_tc_210_31_getParamCOMP_ID");
    m.def("pus_tc_210_31_setParamCOMP_ID", &pus_tc_210_31_setParamCOMP_ID, "pus_tc_210_31_setParamCOMP_ID");
    m.def("pus_tc_210_31_getParamSUBCOMP_ID", &pus_tc_210_31_getParamSUBCOMP_ID, "pus_tc_210_31_getParamSUBCOMP_ID");
    m.def("pus_tc_210_31_setParamSUBCOMP_ID", &pus_tc_210_31_setParamSUBCOMP_ID, "pus_tc_210_31_setParamSUBCOMP_ID");
    m.def("pus_tc_210_31_getParamControllerCalib", &pus_tc_210_31_getParamControllerCalib, "pus_tc_210_31_getParamControllerCalib");
    m.def("pus_tc_210_31_setParamControllerCalib", &pus_tc_210_31_setParamControllerCalib, "pus_tc_210_31_setParamControllerCalib");

    m.def("pus_tc_210_32_createResetController", &pus_tc_210_32_createResetController,"pus_tc_210_32_createResetController");
    m.def("pus_tc_210_32_getParamSM_ID", &pus_tc_210_32_getParamSM_ID, "pus_tc_210_32_getParamSM_ID");
    m.def("pus_tc_210_32_setParamSM_ID", &pus_tc_210_32_setParamSM_ID, "pus_tc_210_32_setParamSM_ID");
    m.def("pus_tc_210_32_getParamCOMP_ID", &pus_tc_210_32_getParamCOMP_ID, "pus_tc_210_32_getParamCOMP_ID");
    m.def("pus_tc_210_32_setParamCOMP_ID", &pus_tc_210_32_setParamCOMP_ID, "pus_tc_210_32_setParamCOMP_ID");
    m.def("pus_tc_210_32_getParamSUBCOMP_ID", &pus_tc_210_32_getParamSUBCOMP_ID, "pus_tc_210_32_getParamSUBCOMP_ID");
    m.def("pus_tc_210_32_setParamSUBCOMP_ID", &pus_tc_210_32_setParamSUBCOMP_ID, "pus_tc_210_32_setParamSUBCOMP_ID");


    /* OSP */
    m.def("pus_tc_210_41_createOspControlCommand", &pus_tc_210_41_createOspControlCommand,"pus_tc_210_41_createOspControlCommand");
    m.def("pus_tc_210_41_getParamSM_ID", &pus_tc_210_41_getParamSM_ID, "pus_tc_210_41_getParamSM_ID");
    m.def("pus_tc_210_41_setParamSM_ID", &pus_tc_210_41_setParamSM_ID, "pus_tc_210_41_setParamSM_ID");
    m.def("pus_tc_210_41_getParamCOMP_ID", &pus_tc_210_41_getParamCOMP_ID, "pus_tc_210_41_getParamCOMP_ID");
    m.def("pus_tc_210_41_setParamCOMP_ID", &pus_tc_210_41_setParamCOMP_ID, "pus_tc_210_41_setParamCOMP_ID");
    m.def("pus_tc_210_41_getParamCommand", &pus_tc_210_41_getParamCommand, "pus_tc_210_41_getParamCommand");
    m.def("pus_tc_210_41_setParamCommand", &pus_tc_210_41_setParamCommand, "pus_tc_210_41_setParamCommand");

    m.def("pus_tc_210_42_createCaptureImage", &pus_tc_210_42_createCaptureImage,"pus_tc_210_42_createCaptureImage");
    m.def("pus_tc_210_42_getParamSM_ID", &pus_tc_210_42_getParamSM_ID, "pus_tc_210_42_getParamSM_ID");
    m.def("pus_tc_210_42_setParamSM_ID", &pus_tc_210_42_setParamSM_ID, "pus_tc_210_42_setParamSM_ID");
    m.def("pus_tc_210_42_getParamCOMP_ID", &pus_tc_210_42_getParamCOMP_ID, "pus_tc_210_42_getParamCOMP_ID");
    m.def("pus_tc_210_42_setParamCOMP_ID", &pus_tc_210_42_setParamCOMP_ID, "pus_tc_210_42_setParamCOMP_ID");
    
    /* BAT */
    m.def("pus_tc_210_61_createHk1Request", &pus_tc_210_61_createHk1Request,"pus_tc_210_61_createHk1Request");
    m.def("pus_tc_210_61_getParamSM_ID", &pus_tc_210_61_getParamSM_ID, "pus_tc_210_61_getParamSM_ID");
    m.def("pus_tc_210_61_setParamSM_ID", &pus_tc_210_61_setParamSM_ID, "pus_tc_210_61_setParamSM_ID");
    m.def("pus_tc_210_61_getParamCOMP_ID", &pus_tc_210_61_getParamCOMP_ID, "pus_tc_210_61_getParamCOMP_ID");
    m.def("pus_tc_210_61_setParamCOMP_ID", &pus_tc_210_61_setParamCOMP_ID, "pus_tc_210_61_setParamCOMP_ID");

    m.def("pus_tc_210_62_createAllHkRequest", &pus_tc_210_62_createAllHkRequest,"pus_tc_210_62_createAllHkRequest");
    m.def("pus_tc_210_62_getParamSM_ID", &pus_tc_210_62_getParamSM_ID, "pus_tc_210_62_getParamSM_ID");
    m.def("pus_tc_210_62_setParamSM_ID", &pus_tc_210_62_setParamSM_ID, "pus_tc_210_62_setParamSM_ID");
    m.def("pus_tc_210_62_getParamCOMP_ID", &pus_tc_210_62_getParamCOMP_ID, "pus_tc_210_62_getParamCOMP_ID");
    m.def("pus_tc_210_62_setParamCOMP_ID", &pus_tc_210_62_setParamCOMP_ID, "pus_tc_210_62_setParamCOMP_ID");

    m.def("pus_tc_210_63_createCommand48VConverter", &pus_tc_210_63_createCommand48VConverter,"pus_tc_210_63_createCommand48VConverter");
    m.def("pus_tc_210_63_getParamSM_ID", &pus_tc_210_63_getParamSM_ID, "pus_tc_210_63_getParamSM_ID");
    m.def("pus_tc_210_63_setParamSM_ID", &pus_tc_210_63_setParamSM_ID, "pus_tc_210_63_setParamSM_ID");
    m.def("pus_tc_210_63_getParamCOMP_ID", &pus_tc_210_63_getParamCOMP_ID, "pus_tc_210_63_getParamCOMP_ID");
    m.def("pus_tc_210_63_setParamCOMP_ID", &pus_tc_210_63_setParamCOMP_ID, "pus_tc_210_63_setParamCOMP_ID");
    m.def("pus_tc_210_63_getParamConv48vCmd", &pus_tc_210_63_getParamConv48vCmd, "pus_tc_210_63_getParamConv48vCmd");
    m.def("pus_tc_210_63_setParamConv48vCmd", &pus_tc_210_63_setParamConv48vCmd, "pus_tc_210_63_setParamConv48vCmd");

    m.def("pus_tc_210_64_createCommandBatCharger", &pus_tc_210_64_createCommandBatCharger,"pus_tc_210_64_createCommandBatCharger");
    m.def("pus_tc_210_64_getParamSM_ID", &pus_tc_210_64_getParamSM_ID, "pus_tc_210_64_getParamSM_ID");
    m.def("pus_tc_210_64_setParamSM_ID", &pus_tc_210_64_setParamSM_ID, "pus_tc_210_64_setParamSM_ID");
    m.def("pus_tc_210_64_getParamCOMP_ID", &pus_tc_210_64_getParamCOMP_ID, "pus_tc_210_64_getParamCOMP_ID");
    m.def("pus_tc_210_64_setParamCOMP_ID", &pus_tc_210_64_setParamCOMP_ID, "pus_tc_210_64_setParamCOMP_ID");
    m.def("pus_tc_210_64_getParamBatChCmd", &pus_tc_210_64_getParamBatChCmd, "pus_tc_210_64_getParamBatChCmd");
    m.def("pus_tc_210_64_setParamBatChCmd", &pus_tc_210_64_setParamBatChCmd, "pus_tc_210_64_setParamBatChCmd");

    /* WM */
    m.def("pus_tc_210_72_createCartesianGoal", &pus_tc_210_72_createCartGoal_,"pus_tc_210_72_createCartesianGoal");
    m.def("pus_tc_210_72_getParamSM_ID", &pus_tc_210_72_getParamSM_ID, "pus_tc_210_72_getParamSM_ID");
    m.def("pus_tc_210_72_setParamSM_ID", &pus_tc_210_72_setParamSM_ID, "pus_tc_210_72_setParamSM_ID");
    m.def("pus_tc_210_72_getParamCOMP_ID", &pus_tc_210_72_getParamCOMP_ID, "pus_tc_210_72_getParamCOMP_ID");
    m.def("pus_tc_210_72_setParamCOMP_ID", &pus_tc_210_72_setParamCOMP_ID, "pus_tc_210_72_setParamCOMP_ID");
    m.def("pus_tc_210_72_getParamDesiredPose", &pus_tc_210_72_getParamDesiredPose_, "pus_tc_210_72_getParamDesiredPose");
    m.def("pus_tc_210_72_setParamDesiredPose", &pus_tc_210_72_setParamDesiredPose_, "pus_tc_210_72_setParamDesiredPose");

    m.def("pus_tc_210_73_createInterfaceCommand", &pus_tc_210_73_createInterface,"pus_tc_210_73_createInterfaceCommand");
    m.def("pus_tc_210_73_getParamSM_ID", &pus_tc_210_73_getParamSM_ID, "pus_tc_210_73_getParamSM_ID");
    m.def("pus_tc_210_73_setParamSM_ID", &pus_tc_210_73_setParamSM_ID, "pus_tc_210_73_setParamSM_ID");
    m.def("pus_tc_210_73_getParamCOMP_ID", &pus_tc_210_73_getParamCOMP_ID, "pus_tc_210_73_getParamCOMP_ID");
    m.def("pus_tc_210_73_setParamCOMP_ID", &pus_tc_210_73_setParamCOMP_ID, "pus_tc_210_73_setParamCOMP_ID");
    m.def("pus_tc_210_73_getParamMode", &pus_tc_210_73_getParamSET_MODE, "pus_tc_210_73_getParamMode");
    m.def("pus_tc_210_73_setParamMode", &pus_tc_210_73_setParamMode, "pus_tc_210_73_setParamMode");
    m.def("pus_tc_210_73_getParamHdId", &pus_tc_210_73_getParamHD_ID, "pus_tc_210_73_getParamHdId");
    m.def("pus_tc_210_73_setParamHdId", &pus_tc_210_73_setParamHdId, "pus_tc_210_73_setParamHdId");
    m.def("pus_tc_210_73_getParamManipulatorBase", &pus_tc_210_73_getParamMANIPULATOR_BASE, "pus_tc_210_73_getParamManipulatorBase");
    m.def("pus_tc_210_73_setParamManipulatorBase", &pus_tc_210_73_setParamManipulatorBase, "pus_tc_210_73_setParamManipulatorBase");
    m.def("pus_tc_210_73_getParamGraspRelease", &pus_tc_210_73_getParamGRASP_RELEASE, "pus_tc_210_73_getParamGraspRelease");
    m.def("pus_tc_210_73_setParamGraspRelease", &pus_tc_210_73_setParamGraspRelease, "pus_tc_210_73_setParamGraspRelease");

    /* THS */
    m.def("pus_tc_210_81_createModeCommand", &pus_tc_210_81_createModeCommand,"pus_tc_210_81_createModeCommand");
    m.def("pus_tc_210_81_getParamSM_ID", &pus_tc_210_81_getParamSM_ID, "pus_tc_210_81_getParamSM_ID");
    m.def("pus_tc_210_81_setParamSM_ID", &pus_tc_210_81_setParamSM_ID, "pus_tc_210_81_setParamSM_ID");
    m.def("pus_tc_210_81_getParamCOMP_ID", &pus_tc_210_81_getParamCOMP_ID, "pus_tc_210_81_getParamCOMP_ID");
    m.def("pus_tc_210_81_setParamCOMP_ID", &pus_tc_210_81_setParamCOMP_ID, "pus_tc_210_81_setParamCOMP_ID");
    m.def("pus_tc_210_81_getParamTargetMode", &pus_tc_210_81_getParamTargetMode, "pus_tc_210_81_getParamTargetMode");
    m.def("pus_tc_210_81_setParamTargetMode", &pus_tc_210_81_setParamTargetMode, "pus_tc_210_81_setParamTargetMode");

    m.def("pus_tc_210_82_createComponentsCommand", &pus_tc_210_82_createComponentsCommand,"pus_tc_210_82_createComponentsCommand");
    m.def("pus_tc_210_82_getParamSM_ID", &pus_tc_210_82_getParamSM_ID, "pus_tc_210_82_getParamSM_ID");
    m.def("pus_tc_210_82_setParamSM_ID", &pus_tc_210_82_setParamSM_ID, "pus_tc_210_82_setParamSM_ID");
    m.def("pus_tc_210_82_getParamCOMP_ID", &pus_tc_210_82_getParamCOMP_ID, "pus_tc_210_82_getParamCOMP_ID");
    m.def("pus_tc_210_82_setParamCOMP_ID", &pus_tc_210_82_setParamCOMP_ID, "pus_tc_210_82_setParamCOMP_ID");
    m.def("pus_tc_210_82_getParamComponentTargetId", &pus_tc_210_82_getParamComponentTargetId, "pus_tc_210_82_getParamComponentTargetId");
    m.def("pus_tc_210_82_setParamComponentTargetId", &pus_tc_210_82_setParamComponentTargetId, "pus_tc_210_82_setParamComponentTargetId");
    m.def("pus_tc_210_82_getParamComponentTargetStatus", &pus_tc_210_82_getParamComponentTargetStatus, "pus_tc_210_82_getParamComponentTargetStatus");
    m.def("pus_tc_210_82_setParamComponentTargetStatus", &pus_tc_210_82_setParamComponentTargetStatus, "pus_tc_210_82_setParamComponentTargetStatus");


    /* CPDU */
    m.def("pus_tc_210_91_createSpecificHkRequest", &pus_tc_210_91_createSpecificHkRequest,"pus_tc_210_91_createSpecificHkRequest");
    m.def("pus_tc_210_91_getParamSM_ID", &pus_tc_210_91_getParamSM_ID, "pus_tc_210_91_getParamSM_ID");
    m.def("pus_tc_210_91_setParamSM_ID", &pus_tc_210_91_setParamSM_ID, "pus_tc_210_91_setParamSM_ID");
    m.def("pus_tc_210_91_getParamCOMP_ID", &pus_tc_210_91_getParamCOMP_ID, "pus_tc_210_91_getParamCOMP_ID");
    m.def("pus_tc_210_91_setParamCOMP_ID", &pus_tc_210_91_setParamCOMP_ID, "pus_tc_210_91_setParamCOMP_ID");
    m.def("pus_tc_210_91_getParamSUBCOMP_ID", &pus_tc_210_91_getParamSUBCOMP_ID, "pus_tc_210_91_getParamSUBCOMP_ID");
    m.def("pus_tc_210_91_setParamSUBCOMP_ID", &pus_tc_210_91_setParamSUBCOMP_ID, "pus_tc_210_91_setParamSUBCOMP_ID");
    m.def("pus_tc_210_91_getParamHkXRequest", &pus_tc_210_91_getParamHkXRequest, "pus_tc_210_91_getParamHkXRequest");
    m.def("pus_tc_210_91_setParamHkXRequest", &pus_tc_210_91_setParamHkXRequest, "pus_tc_210_91_setParamHkXRequest");

    m.def("pus_tc_210_92_createAllHkRequest", &pus_tc_210_92_createAllHkRequest,"pus_tc_210_92_createAllHkRequest");
    m.def("pus_tc_210_92_getParamSM_ID", &pus_tc_210_92_getParamSM_ID, "pus_tc_210_92_getParamSM_ID");
    m.def("pus_tc_210_92_setParamSM_ID", &pus_tc_210_92_setParamSM_ID, "pus_tc_210_92_setParamSM_ID");
    m.def("pus_tc_210_92_getParamCOMP_ID", &pus_tc_210_92_getParamCOMP_ID, "pus_tc_210_92_getParamCOMP_ID");
    m.def("pus_tc_210_92_setParamCOMP_ID", &pus_tc_210_92_setParamCOMP_ID, "pus_tc_210_92_setParamCOMP_ID");
    m.def("pus_tc_210_92_getParamSUBCOMP_ID", &pus_tc_210_92_getParamSUBCOMP_ID, "pus_tc_210_92_getParamSUBCOMP_ID");
    m.def("pus_tc_210_92_setParamSUBCOMP_ID", &pus_tc_210_92_setParamSUBCOMP_ID, "pus_tc_210_92_setParamSUBCOMP_ID");

    m.def("pus_tc_210_93_createCommandSwitch1", &pus_tc_210_93_createCommandSwitch1,"pus_tc_210_93_createCommandSwitch1");
    m.def("pus_tc_210_93_getParamSM_ID", &pus_tc_210_93_getParamSM_ID, "pus_tc_210_93_getParamSM_ID");
    m.def("pus_tc_210_93_setParamSM_ID", &pus_tc_210_93_setParamSM_ID, "pus_tc_210_93_setParamSM_ID");
    m.def("pus_tc_210_93_getParamCOMP_ID", &pus_tc_210_93_getParamCOMP_ID, "pus_tc_210_93_getParamCOMP_ID");
    m.def("pus_tc_210_93_setParamCOMP_ID", &pus_tc_210_93_setParamCOMP_ID, "pus_tc_210_93_setParamCOMP_ID");
    m.def("pus_tc_210_93_getParamSUBCOMP_ID", &pus_tc_210_93_getParamSUBCOMP_ID, "pus_tc_210_93_getParamSUBCOMP_ID");
    m.def("pus_tc_210_93_setParamSUBCOMP_ID", &pus_tc_210_93_setParamSUBCOMP_ID, "pus_tc_210_93_setParamSUBCOMP_ID");
    m.def("pus_tc_210_93_getParamSw1Cmd", &pus_tc_210_93_getParamSw1Cmd, "pus_tc_210_93_getParamSw1Cmd");
    m.def("pus_tc_210_93_setParamSw1Cmd", &pus_tc_210_93_setParamSw1Cmd, "pus_tc_210_93_setParamSw1Cmd");
    m.def("pus_tc_210_93_getParamSw2Cmd", &pus_tc_210_93_getParamSw2Cmd, "pus_tc_210_93_getParamSw2Cmd");
    m.def("pus_tc_210_93_setParamSw2Cmd", &pus_tc_210_93_setParamSw2Cmd, "pus_tc_210_93_setParamSw2Cmd");
    m.def("pus_tc_210_93_getParamSw3Cmd", &pus_tc_210_93_getParamSw3Cmd, "pus_tc_210_93_getParamSw3Cmd");
    m.def("pus_tc_210_93_setParamSw3Cmd", &pus_tc_210_93_setParamSw3Cmd, "pus_tc_210_93_setParamSw3Cmd");
    m.def("pus_tc_210_93_getParamSw4Cmd", &pus_tc_210_93_getParamSw4Cmd, "pus_tc_210_93_getParamSw4Cmd");
    m.def("pus_tc_210_93_setParamSw4Cmd", &pus_tc_210_93_setParamSw4Cmd, "pus_tc_210_93_setParamSw4Cmd");
    m.def("pus_tc_210_93_getParamSw5Cmd", &pus_tc_210_93_getParamSw5Cmd, "pus_tc_210_93_getParamSw5Cmd");
    m.def("pus_tc_210_93_setParamSw5Cmd", &pus_tc_210_93_setParamSw5Cmd, "pus_tc_210_93_setParamSw5Cmd");

    m.def("pus_tc_210_94_createCommand24VConverterA", &pus_tc_210_94_createCommand24VConverterA,"pus_tc_210_94_createCommand24VConverterA");
    m.def("pus_tc_210_94_getParamSM_ID", &pus_tc_210_94_getParamSM_ID, "pus_tc_210_94_getParamSM_ID");
    m.def("pus_tc_210_94_setParamSM_ID", &pus_tc_210_94_setParamSM_ID, "pus_tc_210_94_setParamSM_ID");
    m.def("pus_tc_210_94_getParamCOMP_ID", &pus_tc_210_94_getParamCOMP_ID, "pus_tc_210_94_getParamCOMP_ID");
    m.def("pus_tc_210_94_setParamCOMP_ID", &pus_tc_210_94_setParamCOMP_ID, "pus_tc_210_94_setParamCOMP_ID");
    m.def("pus_tc_210_94_getParamSUBCOMP_ID", &pus_tc_210_94_getParamSUBCOMP_ID, "pus_tc_210_94_getParamSUBCOMP_ID");
    m.def("pus_tc_210_94_setParamSUBCOMP_ID", &pus_tc_210_94_setParamSUBCOMP_ID, "pus_tc_210_94_setParamSUBCOMP_ID");
    m.def("pus_tc_210_94_getParamConv24vACmd", &pus_tc_210_94_getParamConv24vACmd, "pus_tc_210_94_getParamConv24vACmd");
    m.def("pus_tc_210_94_setParamConv24vACmd", &pus_tc_210_94_setParamConv24vACmd, "pus_tc_210_94_setParamConv24vACmd");
    m.def("pus_tc_210_94_getParamConv24vBCmd", &pus_tc_210_94_getParamConv24vBCmd, "pus_tc_210_94_getParamConv24vBCmd");
    m.def("pus_tc_210_94_setParamConv24vBCmd", &pus_tc_210_94_setParamConv24vBCmd, "pus_tc_210_94_setParamConv24vBCmd");
    m.def("pus_tc_210_94_getParamConv12vCmd", &pus_tc_210_94_getParamConv12vCmd, "pus_tc_210_94_getParamConv12vCmd");
    m.def("pus_tc_210_94_setParamConv12vCmd", &pus_tc_210_94_setParamConv12vCmd, "pus_tc_210_94_setParamConv12vCmd");
    m.def("pus_tc_210_94_getParamConv19vCmd", &pus_tc_210_94_getParamConv19vCmd, "pus_tc_210_94_getParamConv19vCmd");
    m.def("pus_tc_210_94_setParamConv19vCmd", &pus_tc_210_94_setParamConv19vCmd, "pus_tc_210_94_setParamConv19vCmd");

    m.def("pus_tc_210_95_createSmPowerOff", &pus_tc_210_95_createSmPowerOff,"pus_tc_210_95_createSmPowerOff");
    m.def("pus_tc_210_95_getParamSM_ID", &pus_tc_210_95_getParamSM_ID, "pus_tc_210_95_getParamSM_ID");
    m.def("pus_tc_210_95_setParamSM_ID", &pus_tc_210_95_setParamSM_ID, "pus_tc_210_95_setParamSM_ID");
    m.def("pus_tc_210_95_getParamCOMP_ID", &pus_tc_210_95_getParamCOMP_ID, "pus_tc_210_95_getParamCOMP_ID");
    m.def("pus_tc_210_95_setParamCOMP_ID", &pus_tc_210_95_setParamCOMP_ID, "pus_tc_210_95_setParamCOMP_ID");
    m.def("pus_tc_210_95_getParamSUBCOMP_ID", &pus_tc_210_95_getParamSUBCOMP_ID, "pus_tc_210_95_getParamSUBCOMP_ID");
    m.def("pus_tc_210_95_setParamSUBCOMP_ID", &pus_tc_210_95_setParamSUBCOMP_ID, "pus_tc_210_95_setParamSUBCOMP_ID");

    // ST 220
	m.def("pus_tc_220_1_createNewTargetState_", &pus_tc_220_1_createNewTargetState_, "pus_tc_220_1_createNewTargetState_");
	m.def("pus_tc_200_2_createGetCurrentState", &pus_tc_200_2_createGetCurrentState, "pus_tc_200_2_createGetCurrentState");
	m.def("pus_tc_220_1_setTargetState_", &pus_tc_220_1_setTargetState_, "pus_tc_220_1_setTargetState_");
	m.def("pus_tc_220_1_getTargetState_", &pus_tc_220_1_getTargetState_, "pus_tc_220_1_getTargetState_");
	m.def("pus_tm_220_3_getCurrentState_", &pus_tm_220_3_getCurrentState_, "pus_tm_220_3_getCurrentState_");
    
}

