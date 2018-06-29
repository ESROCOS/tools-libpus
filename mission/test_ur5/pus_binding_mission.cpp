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
#include "pus_st201_packets.h"

#include "pus_time.h"
#include "pus_events.h"
#include "pus_notify.h"

namespace py = pybind11;

//Wrapper functions
pusError_t pus_tc_201_1_createSetHomeRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		std::vector<pusSt201Point> position, std::vector<pusSt201Point> orientation) {
	pusSt201Position stPos;
	pusSt201Orientation stOri;

	std::copy(position.begin(), position.end(), stPos.arr);
	std::copy(orientation.begin(), orientation.end(), stOri.arr);

	return pus_tc_201_1_createSetHomeRequest(outTc, apid, sequenceCount, &stPos, &stOri);
}

pusError_t pus_tc_201_3_createPlanMoveRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		std::vector<pusSt201Point> position, std::vector<pusSt201Point> orientation) {
	pusSt201Position stPos;
	pusSt201Orientation stOri;

	std::copy(position.begin(), position.end(), stPos.arr);
	std::copy(orientation.begin(), orientation.end(), stOri.arr);

	return pus_tc_201_3_createPlanMoveRequest(outTc, apid, sequenceCount, &stPos, &stOri);
}

std::vector<pusSt201Point> pus_tc_201_1_3_getOrientationPoints_(const pusPacket_t* inTc) {
	pusSt201Point x = 0, y = 0, z = 0;
	pusError_t error = pus_tc_201_1_3_getOrientationPoints(&x, &y, &z, inTc);
	PUS_SET_ERROR(error);
	std::vector<pusSt201Point> orientation;
	if (error == PUS_NO_ERROR) {
		orientation.push_back(x);
		orientation.push_back(y);
		orientation.push_back(z);
	}
	else {
		orientation.push_back(0);
		orientation.push_back(0);
		orientation.push_back(0);
	}

	return orientation;
}

std::vector<pusSt201Point> pus_tc_201_1_3_getPositionPoints_(const pusPacket_t* inTc) {
	pusSt201Point x = 0, y = 0, z = 0;
	pusError_t error = pus_tc_201_1_3_getPositionPoints(&x, &y, &z, inTc);
	PUS_SET_ERROR(error);
	std::vector<pusSt201Point> position;
	if (error == PUS_NO_ERROR) {
		position.push_back(x);
		position.push_back(y);
		position.push_back(z);
	}
	else {
		position.push_back(0);
		position.push_back(0);
		position.push_back(0);
	}

	return position;
}

pusSt201PlanObservation pus_tm_201_4_getPlanObservation_(const pusPacket_t* inTM) {
	pusSt201PlanObservation observation, obs2;
	obs2.id = 0;
	obs2.code = 0;
	pusError_t error = pus_tm_201_4_getPlanObservation(&observation, inTM);
	PUS_SET_ERROR(error);
	if (error == PUS_NO_ERROR)
		return observation;
	else
		return obs2;
}



void init_mission_module(py::module &m)
{
	m.doc() = "pus_st200_camera_conrtol";
	m.def("pus_tc_200_1_createControlCameraRequest", &pus_tc_200_1_createControlCameraRequest, "pus_tc_200_1_createControlCameraRequest");
	m.def("pus_tm_200_2_createControlCameraReport", &pus_tm_200_2_createControlCameraReport, "pus_tm_200_2_createControlCameraReport");
	m.def("pus_tc_200_1_setControlId", &pus_tc_200_1_setControlId, "pus_tc_200_1_setControlId");
	m.def("pus_tc_200_1_getControlId", &pus_tc_200_1_getControlId, "pus_tc_200_1_getControlId");
	m.def("pus_tm_200_2_setObservation", &pus_tm_200_2_setObservation, "pus_tm_200_2_setObservation");
	m.def("pus_tm_200_2_getObservation", &pus_tm_200_2_getObservation, "pus_tm_200_2_getObservation");


	m.def("pus_tc_201_1_createSetHomeRequest", &pus_tc_201_1_createSetHomeRequest_, "pus_tc_201_1_createSetHomeRequest");
	m.def("pus_tc_201_2_createPlanHomeRequest", &pus_tc_201_2_createPlanHomeRequest, "pus_tc_201_2_createPlanHomeRequest");
	m.def("pus_tc_201_3_createPlanMoveRequest", &pus_tc_201_3_createPlanMoveRequest_, "pus_tc_201_3_createPlanMoveRequest");
	m.def("pus_tm_201_4_createPlanReport", &pus_tm_201_4_createPlanReport, "pus_tm_201_4_createPlanReport");
	m.def("pus_tc_201_1_3_setOrientationPoints", &pus_tc_201_1_3_setOrientationPoints, "pus_tc_201_1_3_setOrientationPoints");
	m.def("pus_tc_201_1_3_getOrientationPoints", &pus_tc_201_1_3_getOrientationPoints_, "pus_tc_201_1_3_getOrientationPoints");
	m.def("pus_tc_201_1_3_setPositionPoints", &pus_tc_201_1_3_setPositionPoints, "pus_tc_201_1_3_setPositionPoints");
	m.def("pus_tc_201_1_3_getPositionPoints", &pus_tc_201_1_3_getPositionPoints_, "pus_tc_201_1_3_getPositionPoints");
	m.def("pus_tm_201_4_getPlanObservation", &pus_tm_201_4_getPlanObservation, "pus_tm_201_4_getPlanObservation");
}


