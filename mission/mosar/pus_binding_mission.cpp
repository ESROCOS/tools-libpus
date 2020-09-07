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

#include "pus_st200_packets.h"

#include "pus_time.h"
#include "pus_events.h"
#include "pus_notify.h"

namespace py = pybind11;

//Wrapper functions 
pusError_t pus_tc_200_3_createMissionRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
    pusSt200_3_Goal goal{};
    goal.goal.predicate = asn1Sccmission_place;
    return pus_tc_200_3_createMissionRequest(outTc, apid, sequenceCount, goal);
} 
pusError_t pus_tc_200_5_createHotdockcmdRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
    pusSt200_5_Goal goal{};
    goal.goal.predicate = asn1Scchotdockcmd_sendState;
    return pus_tc_200_5_createHotdockcmdRequest(outTc, apid, sequenceCount, goal);
} 
pusError_t pus_tc_200_9_createWmcmdRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
    pusSt200_9_Goal goal{};
    goal.goal.predicate = asn1Sccwmcmd_movetohd;
    return pus_tc_200_9_createWmcmdRequest(outTc, apid, sequenceCount, goal);
} 
pusError_t pus_tc_200_11_createBasecmdRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
    pusSt200_11_Goal goal{};
    goal.goal.predicate = asn1Sccbasecmd_switchBase;
    return pus_tc_200_11_createBasecmdRequest(outTc, apid, sequenceCount, goal);
} 
pusError_t pus_tc_200_13_createEfcmdRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
    pusSt200_13_Goal goal{};
    goal.goal.predicate = asn1Sccefcmd_pick;
    return pus_tc_200_13_createEfcmdRequest(outTc, apid, sequenceCount, goal);
}

void init_mission_module(py::module &m)
{
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
    
    py::class_<asn1SccSlotid>(m, "asn1SccSlotid")
        .def(py::init<>())
        .def_readwrite("x", &asn1SccSlotid::x)
        .def_readwrite("y", &asn1SccSlotid::y)
        .def_readwrite("z", &asn1SccSlotid::z)
        .def_readwrite("svc", &asn1SccSlotid::svc);
    
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

    py::class_<asn1SccEnumDomain>(m, "asn1SccEnumDomain")
        .def(py::init<>())
        .def_readwrite("key", &asn1SccEnumDomain::key)
        .def_readwrite("value", &asn1SccEnumDomain::value);

    py::enum_<asn1SccHotdockcmdPred>(m, "asn1SccHotdockcmdPred")
        .value("idle", asn1SccHotdockcmdPred::asn1Scchotdockcmd_idle)
        .value("sendState", asn1SccHotdockcmdPred::asn1Scchotdockcmd_sendState)
        .value("cancel", asn1SccHotdockcmdPred::asn1Scchotdockcmd_cancel)
        .export_values();

    py::enum_<asn1SccHotdockstatusPred>(m, "asn1SccHotdockstatusPred")
        .value("status", asn1SccHotdockstatusPred::asn1Scchotdockstatus_status)
        .value("cancel", asn1SccHotdockstatusPred::asn1Scchotdockstatus_cancel)
        .export_values();

    py::enum_<asn1SccWmcmdPred>(m, "asn1SccWmcmdPred")
        .value("idle", asn1SccWmcmdPred::asn1Sccwmcmd_idle)
        .value("movetohd", asn1SccWmcmdPred::asn1Sccwmcmd_movetohd)
        .value("movetoslot", asn1SccWmcmdPred::asn1Sccwmcmd_movetoslot)
        .value("cancel", asn1SccWmcmdPred::asn1Sccwmcmd_cancel)
        .export_values();

    py::enum_<asn1SccBasecmdPred>(m, "asn1SccBasecmdPred")
        .value("baseAt", asn1SccBasecmdPred::asn1Sccbasecmd_baseAt)
        .value("switchBase", asn1SccBasecmdPred::asn1Sccbasecmd_switchBase)
        .value("error", asn1SccBasecmdPred::asn1Sccbasecmd_error)
        .value("cancel", asn1SccBasecmdPred::asn1Sccbasecmd_cancel)
        .export_values();

    py::enum_<asn1SccEfcmdPred>(m, "asn1SccEfcmdPred")
        .value("idle", asn1SccEfcmdPred::asn1Sccefcmd_idle)
        .value("pick", asn1SccEfcmdPred::asn1Sccefcmd_pick)
        .value("drop", asn1SccEfcmdPred::asn1Sccefcmd_drop)
        .value("cancel", asn1SccEfcmdPred::asn1Sccefcmd_cancel)
        .export_values();

    py::enum_<asn1SccPlannerPred>(m, "asn1SccPlannerPred")
        .value("idle", asn1SccPlannerPred::asn1Sccplanner_idle)
        .value("planning", asn1SccPlannerPred::asn1Sccplanner_planning)
        .value("fault", asn1SccPlannerPred::asn1Sccplanner_fault)
        .value("cancel", asn1SccPlannerPred::asn1Sccplanner_cancel)
        .export_values();

    py::enum_<asn1SccMissionPred>(m, "asn1SccMissionPred")
        .value("idle", asn1SccMissionPred::asn1Sccmission_idle)
        .value("place", asn1SccMissionPred::asn1Sccmission_place)
        .value("loadinge3plan", asn1SccMissionPred::asn1Sccmission_loadinge3plan)
        .value("cancel", asn1SccMissionPred::asn1Sccmission_cancel)
        .export_values();
    

    py::class_<asn1SccPlannerstatus>(m, "asn1SccPlannerstatus")
        .def(py::init<>())
        .def_readwrite("goals", &asn1SccPlannerstatus::goals)
        .def_readwrite("predicate", &asn1SccPlannerstatus::predicate)
        .def_readwrite("inittime", &asn1SccPlannerstatus::inittime)
        .def_readwrite("endtime", &asn1SccPlannerstatus::endtime);

    

    py::class_<pusSt200_2_Observation>(m, "pusSt200_2_Observation")
        .def(py::init<>())
        .def_readwrite("observation", &pusSt200_2_Observation::observation)
        .def_readwrite("agent", &pusSt200_2_Observation::agent);

    
    

    py::class_<asn1SccMissionstatus>(m, "asn1SccMissionstatus")
        .def(py::init<>())
        .def_readwrite("sm", &asn1SccMissionstatus::sm)
        .def_readwrite("slot", &asn1SccMissionstatus::slot)
        .def_readwrite("orientation", &asn1SccMissionstatus::orientation)
        .def_readwrite("file", &asn1SccMissionstatus::file)
        .def_readwrite("predicate", &asn1SccMissionstatus::predicate)
        .def_readwrite("inittime", &asn1SccMissionstatus::inittime)
        .def_readwrite("endtime", &asn1SccMissionstatus::endtime);

    
    py::class_<pusSt200_3_Goal>(m, "pusSt200_3_Goal")
        .def(py::init<>())
        .def_readwrite("goal", &pusSt200_3_Goal::goal)
        .def_readwrite("agent", &pusSt200_3_Goal::agent);

    py::class_<pusSt200_4_Observation>(m, "pusSt200_4_Observation")
        .def(py::init<>())
        .def_readwrite("observation", &pusSt200_4_Observation::observation)
        .def_readwrite("agent", &pusSt200_4_Observation::agent);

    
    

    py::class_<asn1SccHotdockcmdstatus>(m, "asn1SccHotdockcmdstatus")
        .def(py::init<>())
        .def_readwrite("status", &asn1SccHotdockcmdstatus::status)
        .def_readwrite("sm", &asn1SccHotdockcmdstatus::sm)
        .def_readwrite("hotdock", &asn1SccHotdockcmdstatus::hotdock)
        .def_readwrite("statehd", &asn1SccHotdockcmdstatus::statehd)
        .def_readwrite("predicate", &asn1SccHotdockcmdstatus::predicate)
        .def_readwrite("inittime", &asn1SccHotdockcmdstatus::inittime)
        .def_readwrite("endtime", &asn1SccHotdockcmdstatus::endtime);

    
    py::class_<pusSt200_5_Goal>(m, "pusSt200_5_Goal")
        .def(py::init<>())
        .def_readwrite("goal", &pusSt200_5_Goal::goal)
        .def_readwrite("agent", &pusSt200_5_Goal::agent);

    py::class_<pusSt200_6_Observation>(m, "pusSt200_6_Observation")
        .def(py::init<>())
        .def_readwrite("observation", &pusSt200_6_Observation::observation)
        .def_readwrite("agent", &pusSt200_6_Observation::agent);

    
    

    py::class_<asn1SccHotdockstatusstatus>(m, "asn1SccHotdockstatusstatus")
        .def(py::init<>())
        .def_readwrite("pathfile", &asn1SccHotdockstatusstatus::pathfile)
        .def_readwrite("predicate", &asn1SccHotdockstatusstatus::predicate)
        .def_readwrite("inittime", &asn1SccHotdockstatusstatus::inittime)
        .def_readwrite("endtime", &asn1SccHotdockstatusstatus::endtime);

    

    py::class_<pusSt200_8_Observation>(m, "pusSt200_8_Observation")
        .def(py::init<>())
        .def_readwrite("observation", &pusSt200_8_Observation::observation)
        .def_readwrite("agent", &pusSt200_8_Observation::agent);

    
    

    py::class_<asn1SccWmcmdstatus>(m, "asn1SccWmcmdstatus")
        .def(py::init<>())
        .def_readwrite("status", &asn1SccWmcmdstatus::status)
        .def_readwrite("hotdock", &asn1SccWmcmdstatus::hotdock)
        .def_readwrite("slot", &asn1SccWmcmdstatus::slot)
        .def_readwrite("face", &asn1SccWmcmdstatus::face)
        .def_readwrite("yaw", &asn1SccWmcmdstatus::yaw)
        .def_readwrite("predicate", &asn1SccWmcmdstatus::predicate)
        .def_readwrite("inittime", &asn1SccWmcmdstatus::inittime)
        .def_readwrite("endtime", &asn1SccWmcmdstatus::endtime);

    
    py::class_<pusSt200_9_Goal>(m, "pusSt200_9_Goal")
        .def(py::init<>())
        .def_readwrite("goal", &pusSt200_9_Goal::goal)
        .def_readwrite("agent", &pusSt200_9_Goal::agent);

    py::class_<pusSt200_10_Observation>(m, "pusSt200_10_Observation")
        .def(py::init<>())
        .def_readwrite("observation", &pusSt200_10_Observation::observation)
        .def_readwrite("agent", &pusSt200_10_Observation::agent);

    
    

    py::class_<asn1SccBasecmdstatus>(m, "asn1SccBasecmdstatus")
        .def(py::init<>())
        .def_readwrite("hotdock", &asn1SccBasecmdstatus::hotdock)
        .def_readwrite("predicate", &asn1SccBasecmdstatus::predicate)
        .def_readwrite("inittime", &asn1SccBasecmdstatus::inittime)
        .def_readwrite("endtime", &asn1SccBasecmdstatus::endtime);

    
    py::class_<pusSt200_11_Goal>(m, "pusSt200_11_Goal")
        .def(py::init<>())
        .def_readwrite("goal", &pusSt200_11_Goal::goal)
        .def_readwrite("agent", &pusSt200_11_Goal::agent);

    py::class_<pusSt200_12_Observation>(m, "pusSt200_12_Observation")
        .def(py::init<>())
        .def_readwrite("observation", &pusSt200_12_Observation::observation)
        .def_readwrite("agent", &pusSt200_12_Observation::agent);

    
    

    py::class_<asn1SccEfcmdstatus>(m, "asn1SccEfcmdstatus")
        .def(py::init<>())
        .def_readwrite("status", &asn1SccEfcmdstatus::status)
        .def_readwrite("hotdock", &asn1SccEfcmdstatus::hotdock)
        .def_readwrite("predicate", &asn1SccEfcmdstatus::predicate)
        .def_readwrite("inittime", &asn1SccEfcmdstatus::inittime)
        .def_readwrite("endtime", &asn1SccEfcmdstatus::endtime);

    
    py::class_<pusSt200_13_Goal>(m, "pusSt200_13_Goal")
        .def(py::init<>())
        .def_readwrite("goal", &pusSt200_13_Goal::goal)
        .def_readwrite("agent", &pusSt200_13_Goal::agent);

    py::class_<pusSt200_14_Observation>(m, "pusSt200_14_Observation")
        .def(py::init<>())
        .def_readwrite("observation", &pusSt200_14_Observation::observation)
        .def_readwrite("agent", &pusSt200_14_Observation::agent);

    

     
    m.def("pus_tm_200_2_createPlannerReport", &pus_tm_200_2_createPlannerReport, "pus_tm_200_2_createPlannerReport");
    m.def("pus_tm_200_2_getPlannerObservation", &pus_tm_200_2_getPlannerObservation, "pus_tm_200_2_getPlannerObservation");
     
    m.def("pus_tc_200_3_createMissionRequest_", &pus_tc_200_3_createMissionRequest_, "pus_tc_200_3_createMissionRequest_");
    m.def("pus_tc_200_3_getMissionGoal", &pus_tc_200_3_getMissionGoal, "pus_tc_200_3_getMissionGoal");
    m.def("pus_tc_200_3_setMissionGoal", &pus_tc_200_3_setMissionGoal, "pus_tc_200_3_setMissionGoal"); 
    m.def("pus_tm_200_4_createMissionReport", &pus_tm_200_4_createMissionReport, "pus_tm_200_4_createMissionReport");
    m.def("pus_tm_200_4_getMissionObservation", &pus_tm_200_4_getMissionObservation, "pus_tm_200_4_getMissionObservation");
     
    m.def("pus_tc_200_5_createHotdockcmdRequest_", &pus_tc_200_5_createHotdockcmdRequest_, "pus_tc_200_5_createHotdockcmdRequest_");
    m.def("pus_tc_200_5_getHotdockcmdGoal", &pus_tc_200_5_getHotdockcmdGoal, "pus_tc_200_5_getHotdockcmdGoal");
    m.def("pus_tc_200_5_setHotdockcmdGoal", &pus_tc_200_5_setHotdockcmdGoal, "pus_tc_200_5_setHotdockcmdGoal"); 
    m.def("pus_tm_200_6_createHotdockcmdReport", &pus_tm_200_6_createHotdockcmdReport, "pus_tm_200_6_createHotdockcmdReport");
    m.def("pus_tm_200_6_getHotdockcmdObservation", &pus_tm_200_6_getHotdockcmdObservation, "pus_tm_200_6_getHotdockcmdObservation");
     
    m.def("pus_tm_200_8_createHotdockstatusReport", &pus_tm_200_8_createHotdockstatusReport, "pus_tm_200_8_createHotdockstatusReport");
    m.def("pus_tm_200_8_getHotdockstatusObservation", &pus_tm_200_8_getHotdockstatusObservation, "pus_tm_200_8_getHotdockstatusObservation");
     
    m.def("pus_tc_200_9_createWmcmdRequest_", &pus_tc_200_9_createWmcmdRequest_, "pus_tc_200_9_createWmcmdRequest_");
    m.def("pus_tc_200_9_getWmcmdGoal", &pus_tc_200_9_getWmcmdGoal, "pus_tc_200_9_getWmcmdGoal");
    m.def("pus_tc_200_9_setWmcmdGoal", &pus_tc_200_9_setWmcmdGoal, "pus_tc_200_9_setWmcmdGoal"); 
    m.def("pus_tm_200_10_createWmcmdReport", &pus_tm_200_10_createWmcmdReport, "pus_tm_200_10_createWmcmdReport");
    m.def("pus_tm_200_10_getWmcmdObservation", &pus_tm_200_10_getWmcmdObservation, "pus_tm_200_10_getWmcmdObservation");
     
    m.def("pus_tc_200_11_createBasecmdRequest_", &pus_tc_200_11_createBasecmdRequest_, "pus_tc_200_11_createBasecmdRequest_");
    m.def("pus_tc_200_11_getBasecmdGoal", &pus_tc_200_11_getBasecmdGoal, "pus_tc_200_11_getBasecmdGoal");
    m.def("pus_tc_200_11_setBasecmdGoal", &pus_tc_200_11_setBasecmdGoal, "pus_tc_200_11_setBasecmdGoal"); 
    m.def("pus_tm_200_12_createBasecmdReport", &pus_tm_200_12_createBasecmdReport, "pus_tm_200_12_createBasecmdReport");
    m.def("pus_tm_200_12_getBasecmdObservation", &pus_tm_200_12_getBasecmdObservation, "pus_tm_200_12_getBasecmdObservation");
     
    m.def("pus_tc_200_13_createEfcmdRequest_", &pus_tc_200_13_createEfcmdRequest_, "pus_tc_200_13_createEfcmdRequest_");
    m.def("pus_tc_200_13_getEfcmdGoal", &pus_tc_200_13_getEfcmdGoal, "pus_tc_200_13_getEfcmdGoal");
    m.def("pus_tc_200_13_setEfcmdGoal", &pus_tc_200_13_setEfcmdGoal, "pus_tc_200_13_setEfcmdGoal"); 
    m.def("pus_tm_200_14_createEfcmdReport", &pus_tm_200_14_createEfcmdReport, "pus_tm_200_14_createEfcmdReport");
    m.def("pus_tm_200_14_getEfcmdObservation", &pus_tm_200_14_getEfcmdObservation, "pus_tm_200_14_getEfcmdObservation");
    
}

