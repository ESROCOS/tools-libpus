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
 

    // ST 210

    /* R_ICU_SPW_PNP */
    m.def("pus_tc_210_1_createSpwRoutingTableSetEntry", &pus_tc_210_1_createSpwRoutingTableSetEntry,"pus_tc_210_1_createSpwRoutingTableSetEntry");
    m.def("pus_tc_210_1_getParamSM_ID", &pus_tc_210_1_getParamSM_ID, "pus_tc_210_1_getParamSM_ID");
    m.def("pus_tc_210_1_setParamSM_ID", &pus_tc_210_1_setParamSM_ID, "pus_tc_210_1_setParamSM_ID");
    m.def("pus_tc_210_1_getParamCOMP_ID", &pus_tc_210_1_getParamCOMP_ID, "pus_tc_210_1_getParamCOMP_ID");
    m.def("pus_tc_210_1_setParamCOMP_ID", &pus_tc_210_1_setParamCOMP_ID, "pus_tc_210_1_setParamCOMP_ID");
    m.def("pus_tc_210_1_getParamSetRoutingEntry", &pus_tc_210_1_getParamSetRoutingEntry, "pus_tc_210_1_getParamSetRoutingEntry");
    m.def("pus_tc_210_1_setParamSetRoutingEntry", &pus_tc_210_1_setParamSetRoutingEntry, "pus_tc_210_1_setParamSetRoutingEntry");
    m.def("pus_tc_210_1_getParamSpwTrafficPriority", &pus_tc_210_1_getParamSpwTrafficPriority, "pus_tc_210_1_getParamSpwTrafficPriority");
    m.def("pus_tc_210_1_setParamSpwTrafficPriority", &pus_tc_210_1_setParamSpwTrafficPriority, "pus_tc_210_1_setParamSpwTrafficPriority");

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

    // ST 220
	m.def("pus_tc_220_1_createNewTargetState_", &pus_tc_220_1_createNewTargetState_, "pus_tc_220_1_createNewTargetState_");
	m.def("pus_tc_200_2_createGetCurrentState", &pus_tc_200_2_createGetCurrentState, "pus_tc_200_2_createGetCurrentState");
	m.def("pus_tc_220_1_setTargetState_", &pus_tc_220_1_setTargetState_, "pus_tc_220_1_setTargetState_");
	m.def("pus_tc_220_1_getTargetState_", &pus_tc_220_1_getTargetState_, "pus_tc_220_1_getTargetState_");
	m.def("pus_tm_220_3_getCurrentState_", &pus_tm_220_3_getCurrentState_, "pus_tm_220_3_getCurrentState_");
    
}

