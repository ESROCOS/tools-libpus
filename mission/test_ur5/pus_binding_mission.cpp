/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "../pylib/pybind11/pybind11.h"
#include "../pylib/pybind11/stl.h"

//#include "pus_types.h"

#include "pus_apid.h"

#include "pus_st200_packets.h"

#include "pus_time.h"
#include "pus_events.h"
#include "pus_notify.h"

namespace py = pybind11;

void init_mission_module(py::module &m)
{
	m.doc() = "pus_st200_camera_conrtol";
	m.def("pus_tc_200_1_createControlCameraRequest", &pus_tc_200_1_createControlCameraRequest, "pus_tc_200_1_createControlCameraRequest");
	m.def("pus_tm_200_2_createControlCameraReport", &pus_tm_200_2_createControlCameraReport, "pus_tc_200_1_createControlCameraRequest");
	m.def("pus_tc_200_1_setControlId", &pus_tc_200_1_setControlId, "pus_tc_200_1_setControlId");
	m.def("pus_tc_200_1_getControlId", &pus_tc_200_1_getControlId, "pus_tc_200_1_getControlId");
	m.def("pus_tm_200_2_setObservation", &pus_tm_200_2_setObservation, "pus_tm_200_2_setObservation");
	m.def("pus_tm_200_2_getObservation", &pus_tm_200_2_getObservation, "pus_tm_200_2_getObservation");
}


