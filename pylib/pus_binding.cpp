#include "pybind11/pybind11.h"
#include "pus_packet.h"
#include "pus_apid.h"
#include "pus_st01_packets.h"
#include "pus_st03_packets.h"
#include "pus_st05_packets.h"
#include "pus_st08_packets.h"
#include "pus_st17_packets.h"
#include "pus_st19_packets.h"

namespace py = pybind11;

PYBIND11_MODULE(pusbinding, m) {
	m.doc() = "pus_packet binding"
	py::class_<pusPacket_t>(m, "pusPacket_t")
		.def(py::init<>());
	m.def("pus_getPacketVersion", &pus_getPacketVersion, "Binding for pus_getPacketVersion");
	m.def("pus_setPacketVersion", &pus_setPacketVersion, "Binding for pus_setPacketVersion");
	m.def("pus_getPacketType", &pus_getPacketType, "Binding for pus_getPacketType");
	m.def("pus_setPacketType", &pus_setPacketType, "Binding for pus_setPacketType");
	m.def("pus_getApid", &pus_getApid, "Binding for pus_getApid");
	m.def("pus_setApid", &pus_setApid, "Binding for pus_setApid");
	m.def("pus_getSecondaryHeaderFlag", &pus_getSecondaryHeaderFlag, "Binding for pus_getSecondaryHeaderFlag");
	m.def("pus_setSecondaryHeaderFlag", &pus_setSecondaryHeaderFlag, "Binding for pus_setSecondaryHeaderFlag");
	m.def("pus_getSequenceFlags", &pus_getSequenceFlags, "Binding for pus_getSequenceFlags");
	m.def("pus_setSequenceFlags", &pus_setSequenceFlags, "Binding for pus_setSequenceFlags");
	m.def("pus_getSequenceCount", &pus_getSequenceCount, "Binding for pus_getSequenceCount");
	m.def("pus_setSequenceCount", &pus_setSequenceCount, "Binding for pus_setSequenceCount");
	m.def("pus_getPacketDataLength", &pus_getPacketDataLength, "Binding for pus_getPacketDataLength");
	m.def("pus_setPacketDataLength", &pus_setPacketDataLength, "Binding for pus_setPacketDataLength");
	m.def("pus_setPacketDataNone", &pus_setPacketDataNone, "Binding for pus_setPacketDataNone");
	m.def("pus_getTmPusVersion", &pus_getTmPusVersion, "Binding for pus_getTmPusVersion");
	m.def("pus_setTmPusVersion", &pus_setTmPusVersion, "Binding for pus_setTmPusVersion");
	m.def("pus_getTcPusVersion", &pus_getTcPusVersion, "Binding for pus_getTcPusVersion");
	m.def("pus_setTcPusVersion", &pus_setTcPusVersion, "Binding for pus_setTcPusVersion");
	m.def("pus_getTmService", &pus_getTmService, "Binding for pus_getTmService");
	m.def("pus_setTmService", &pus_setTmService, "Binding for pus_setTmService");
	m.def("pus_getTmSubtype", &pus_getTmSubtype, "Binding for pus_getTmSubtype");
	m.def("pus_setTmSubtype", &pus_setTmSubtype, "Binding for pus_setTmSubtype");
	m.def("pus_getTcService", &pus_getTcService, "Binding for pus_getTcService");
	m.def("pus_setTcService", &pus_setTcService, "Binding for pus_setTcService");
	m.def("pus_getTcSubtype", &pus_getTcSubtype, "Binding for pus_getTcSubtype");
	m.def("pus_setTcSubtype", &pus_setTcSubtype, "Binding for pus_setTcSubtype");
	m.def("pus_getTmTimeReferenceStatus", &pus_getTmTimeReferenceStatus, "Binding for pus_getTmTimeReferenceStatus");
	m.def("pus_setTmTimeReferenceStatus", &pus_setTmTimeReferenceStatus, "Binding for pus_setTmTimeReferenceStatus");
	m.def("pus_getTmMessageTypeCounter", &pus_getTmMessageTypeCounter, "Binding for pus_getTmMessageTypeCounter");
	m.def("pus_setTmMessageTypeCounter", &pus_setTmMessageTypeCounter, "Binding for pus_setTmMessageTypeCounter");
	m.def("pus_getTmDestination", &pus_getTmDestination, "Binding for pus_getTmDestination");
	m.def("pus_setTmDestination", &pus_setTmDestination, "Binding for pus_setTmDestination");
	m.def("pus_getTcSource", &pus_getTcSource, "Binding for pus_getTcSource");
	m.def("pus_setTcSource", &pus_setTcSource, "Binding for pus_setTcSource");
	m.def("pus_getTmPacketTime", &pus_getTmPacketTime, "Binding for pus_getTmPacketTime");
	m.def("pus_setTmPacketTime", &pus_setTmPacketTime, "Binding for pus_setTmPacketTime");
	m.def("pus_setTmPacketTimeNow", &pus_setTmPacketTimeNow, "Binding for pus_setTmPacketTimeNow");
	m.def("pus_getTcAckFlagAcceptance", &pus_getTcAckFlagAcceptance, "Binding for pus_getTcAckFlagAcceptance");
	m.def("pus_getTcAckFlagStart", &pus_getTcAckFlagStart, "Binding for pus_getTcAckFlagStart");
	m.def("pus_getTcAckFlagProgress", &pus_getTcAckFlagProgress, "Binding for pus_getTcAckFlagProgress");
	m.def("pus_getTcAckFlagCompletion", &pus_getTcAckFlagCompletion, "Binding for pus_getTcAckFlagCompletion");
	m.def("pus_setTcAckFlags", &pus_setTcAckFlags, "Binding for pus_setTcAckFlags");
	m.def("pus_getPacketDataKind", &pus_getPacketDataKind, "Binding for pus_getPacketDataKind");
	m.def("pus_setPacketDataKind", &pus_setPacketDataKind, "Binding for pus_setPacketDataKind");
	m.def("pus_getTmDataKind", &pus_getTmDataKind, "Binding for pus_getTmDataKind");
	m.def("pus_setTmDataKind", &pus_setTmDataKind, "Binding for pus_setTmDataKind");
	m.def("pus_getTmNoHeaderDataKind", &pus_getTmNoHeaderDataKind, "Binding for pus_getTmNoHeaderDataKind");
	m.def("pus_setTmNoHeaderDataKind", &pus_setTmNoHeaderDataKind, "Binding for pus_setTmNoHeaderDataKind");
	m.def("pus_getTcDataKind", &pus_getTcDataKind, "Binding for pus_getTcDataKind");
	m.def("pus_setTcDataKind", &pus_setTcDataKind, "Binding for pus_setTcDataKind");
	m.def("pus_getTcNoHeaderDataKind", &pus_getTcNoHeaderDataKind, "Binding for pus_getTcNoHeaderDataKind");
	m.def("pus_setTcNoHeaderDataKind", &pus_setTcNoHeaderDataKind, "Binding for pus_setTcNoHeaderDataKind");
	m.def("pus_incrementSequenceCount", &pus_incrementSequenceCount, "Binding for pus_incrementSequenceCount");
	m.def("pus_setPacketTimeNow", &pus_setPacketTimeNow, "Binding for pus_setPacketTimeNow");
	m.def("pus_setPacketDefaults", &pus_setPacketDefaults, "Binding for pus_setPacketDefaults");
	m.def("pus_initTmPacket", &pus_initTmPacket, "Binding for pus_initTmPacket");
	m.def("pus_initTcPacket", &pus_initTcPacket, "Binding for pus_initTcPacket");
	m.def("pus_initTmPacketNoHeader", &pus_initTmPacketNoHeader, "Binding for pus_initTmPacketNoHeader");
	m.def("pus_initTcPacketNoHeader", &pus_initTcPacketNoHeader, "Binding for pus_initTcPacketNoHeader");
	m.def("pus_verifyCcsdsHeaderDefaults", &pus_verifyCcsdsHeaderDefaults, "Binding for pus_verifyCcsdsHeaderDefaults");
	m.def("pus_verifyPacketDataKind", &pus_verifyPacketDataKind, "Binding for pus_verifyPacketDataKind");
	m.def("pus_verifyTmSecondaryHeaderDefaults", &pus_verifyTmSecondaryHeaderDefaults, "Binding for pus_verifyTmSecondaryHeaderDefaults");
	m.def("pus_checkTcSecondaryHeaderDefaults", &pus_checkTcSecondaryHeaderDefaults, "Binding for pus_checkTcSecondaryHeaderDefaults");
	m.def("pus_verifyTmHeaderDefaults", &pus_verifyTmHeaderDefaults, "Binding for pus_verifyTmHeaderDefaults");
	m.def("pus_verifyTcHeaderDefaults", &pus_verifyTcHeaderDefaults, "Binding for pus_verifyTcHeaderDefaults");
	m.def("pus_expectTm", &pus_expectTm, "Binding for pus_expectTm");
	m.def("pus_expectTmHeader", &pus_expectTmHeader, "Binding for pus_expectTmHeader");
	m.def("pus_expectTmNoHeader", &pus_expectTmNoHeader, "Binding for pus_expectTmNoHeader");
	m.def("pus_expectTc", &pus_expectTc, "Binding for pus_expectTc");
	m.def("pus_expectTcHeader", &pus_expectTcHeader, "Binding for pus_expectTcHeader");
	m.def("pus_expectTcNoHeader", &pus_expectTcNoHeader, "Binding for pus_expectTcNoHeader");

	m.doc() = "pus_apid binding"
	py::class_<pusApid_t>(m, "pusApid_t")
		.def(py::init<>());
	m.def("pus_initApidInfo", &pus_initApidInfo, "Binding for pus_initApidInfo");
	m.def("pus_getInfoApid", &pus_getInfoApid, "Binding for pus_getInfoApid");
	m.def("pus_getNextPacketCount", &pus_getNextPacketCount, "Binding for pus_getNextPacketCount");

	m.doc() = "pus_st01_packets binding"
	m.def("pus_tm_1_X_createReport", &pus_tm_1_X_createReport, "Binding for pus_tm_1_X_createReport");
	m.def("pus_tm_1_1_createAcceptanceReportSuccess", &pus_tm_1_1_createAcceptanceReportSuccess, "Binding for pus_tm_1_1_createAcceptanceReportSuccess");
	m.def("pus_tm_1_2_createAcceptanceReportFailure", &pus_tm_1_2_createAcceptanceReportFailure, "Binding for pus_tm_1_2_createAcceptanceReportFailure");
	m.def("pus_tm_1_3_createStartReportSuccess", &pus_tm_1_3_createStartReportSuccess, "Binding for pus_tm_1_3_createStartReportSuccess");
	m.def("pus_tm_1_4_createStartReportFailure", &pus_tm_1_4_createStartReportFailure, "Binding for pus_tm_1_4_createStartReportFailure");
	m.def("pus_tm_1_5_createProgressReportSuccess", &pus_tm_1_5_createProgressReportSuccess, "Binding for pus_tm_1_5_createProgressReportSuccess");
	m.def("pus_tm_1_6_createProgressReportFailure", &pus_tm_1_6_createProgressReportFailure, "Binding for pus_tm_1_6_createProgressReportFailure");
	m.def("pus_tm_1_7_createCompletionReportSuccess", &pus_tm_1_7_createCompletionReportSuccess, "Binding for pus_tm_1_7_createCompletionReportSuccess");
	m.def("pus_tm_1_8_createCompletionReportFailure", &pus_tm_1_8_createCompletionReportFailure, "Binding for pus_tm_1_8_createCompletionReportFailure");
	m.def("pus_tm_1_X_setPacketVersionNumber", &pus_tm_1_X_setPacketVersionNumber, "Binding for pus_tm_1_X_setPacketVersionNumber");
	m.def("pus_tm_1_X_getPacketVersionNumber", &pus_tm_1_X_getPacketVersionNumber, "Binding for pus_tm_1_X_getPacketVersionNumber");
	m.def("pus_tm_1_X_setPacketType", &pus_tm_1_X_setPacketType, "Binding for pus_tm_1_X_setPacketType");
	m.def("pus_tm_1_X_getPacketType", &pus_tm_1_X_getPacketType, "Binding for pus_tm_1_X_getPacketType");
	m.def("pus_tm_1_X_setSecondaryHeaderFlag", &pus_tm_1_X_setSecondaryHeaderFlag, "Binding for pus_tm_1_X_setSecondaryHeaderFlag");
	m.def("pus_tm_1_X_getSecondaryHeaderFlag", &pus_tm_1_X_getSecondaryHeaderFlag, "Binding for pus_tm_1_X_getSecondaryHeaderFlag");
	m.def("pus_tm_1_X_setApid", &pus_tm_1_X_setApid, "Binding for pus_tm_1_X_setApid");
	m.def("pus_tm_1_X_getApid", &pus_tm_1_X_getApid, "Binding for pus_tm_1_X_getApid");
	m.def("pus_tm_1_X_setSequenceFlags", &pus_tm_1_X_setSequenceFlags, "Binding for pus_tm_1_X_setSequenceFlags");
	m.def("pus_tm_1_X_getSequenceFlags", &pus_tm_1_X_getSequenceFlags, "Binding for pus_tm_1_X_getSequenceFlags");
	m.def("pus_tm_1_X_setSequenceCount", &pus_tm_1_X_setSequenceCount, "Binding for pus_tm_1_X_setSequenceCount");
	m.def("pus_tm_1_X_getSequenceCount", &pus_tm_1_X_getSequenceCount, "Binding for pus_tm_1_X_getSequenceCount");
	m.def("pus_tm_1_X_setStep", &pus_tm_1_X_setStep, "Binding for pus_tm_1_X_setStep");
	m.def("pus_tm_1_X_getStep", &pus_tm_1_X_getStep, "Binding for pus_tm_1_X_getStep");
	m.def("pus_tm_1_X_initFailureInfo", &pus_tm_1_X_initFailureInfo, "Binding for pus_tm_1_X_initFailureInfo");
	m.def("pus_tm_1_X_getFailureInfo", &pus_tm_1_X_getFailureInfo, "Binding for pus_tm_1_X_getFailureInfo");
	m.def("pus_tm_1_X_setFailureInfo", &pus_tm_1_X_setFailureInfo, "Binding for pus_tm_1_X_setFailureInfo");
	m.def("pus_initSt01FailureInfo", &pus_initSt01FailureInfo, "Binding for pus_initSt01FailureInfo");
	m.def("pus_setSt01FailureInfo", &pus_setSt01FailureInfo, "Binding for pus_setSt01FailureInfo");
	m.def("pus_getSt01FailureSubcode", &pus_getSt01FailureSubcode, "Binding for pus_getSt01FailureSubcode");
	m.def("pus_getSt01FailureData", &pus_getSt01FailureData, "Binding for pus_getSt01FailureData");
	m.def("pus_getSt01FailureAddress", &pus_getSt01FailureAddress, "Binding for pus_getSt01FailureAddress");
	m.def("pus_expectSt01Tm", &pus_expectSt01Tm, "Binding for pus_expectSt01Tm");

	m.doc() = "pus_st03_packets binding"
	m.def("pus_hk_initialize", &pus_hk_initialize, "Binding for pus_hk_initialize");
	m.def("pus_hk_finalize", &pus_hk_finalize, "Binding for pus_hk_finalize");
	m.def("pus_hk_isInitialized", &pus_hk_isInitialized, "Binding for pus_hk_isInitialized");
	m.def("pus_tm_3_25_createHousekeepingReportDefault", &pus_tm_3_25_createHousekeepingReportDefault, "Binding for pus_tm_3_25_createHousekeepingReportDefault");
	m.def("pus_tm_3_25_createHousekeepingReport", &pus_tm_3_25_createHousekeepingReport, "Binding for pus_tm_3_25_createHousekeepingReport");
	m.def("pus_hk_getUInt32Param", &pus_hk_getUInt32Param, "Binding for pus_hk_getUInt32Param");
	m.def("pus_hk_setUInt32Param", &pus_hk_setUInt32Param, "Binding for pus_hk_setUInt32Param");
	m.def("pus_hk_getInt32Param", &pus_hk_getInt32Param, "Binding for pus_hk_getInt32Param");
	m.def("pus_hk_setInt32Param", &pus_hk_setInt32Param, "Binding for pus_hk_setInt32Param");
	m.def("pus_hk_getReal64Param", &pus_hk_getReal64Param, "Binding for pus_hk_getReal64Param");
	m.def("pus_hk_setReal64Param", &pus_hk_setReal64Param, "Binding for pus_hk_setReal64Param");
	m.def("pus_hk_getBoolParam", &pus_hk_getBoolParam, "Binding for pus_hk_getBoolParam");
	m.def("pus_hk_setBoolParam", &pus_hk_setBoolParam, "Binding for pus_hk_setBoolParam");
	m.def("pus_hk_getByteParam", &pus_hk_getByteParam, "Binding for pus_hk_getByteParam");
	m.def("pus_hk_setByteParam", &pus_hk_setByteParam, "Binding for pus_hk_setByteParam");
	m.def("pus_tm_3_25_getReportId", &pus_tm_3_25_getReportId, "Binding for pus_tm_3_25_getReportId");
	m.def("pus_tm_3_25_setReportId", &pus_tm_3_25_setReportId, "Binding for pus_tm_3_25_setReportId");
	m.def("pus_tm_3_25_setParameterValues", &pus_tm_3_25_setParameterValues, "Binding for pus_tm_3_25_setParameterValues");
	m.def("pus_tm_3_25_getParameterValue", &pus_tm_3_25_getParameterValue, "Binding for pus_tm_3_25_getParameterValue");
	m.def("pus_tm_3_25_getNumParameters", &pus_tm_3_25_getNumParameters, "Binding for pus_tm_3_25_getNumParameters");
	m.def("pus_expectSt03Tm", &pus_expectSt03Tm, "Binding for pus_expectSt03Tm");

	m.doc() = "pus_st05_packets binding"
	py::class_<pusSt05packets_t>(m, "pusSt05packets_t")
		.def(py::init<>());
	m.def("pus_tm_5_X_createEventReport", &pus_tm_5_X_createEventReport, "Binding for pus_tm_5_X_createEventReport");
	m.def("pus_tm_5_1_createInformativeEventReport", &pus_tm_5_1_createInformativeEventReport, "Binding for pus_tm_5_1_createInformativeEventReport");
	m.def("pus_tm_5_2_createLowSeverityEventReport", &pus_tm_5_2_createLowSeverityEventReport, "Binding for pus_tm_5_2_createLowSeverityEventReport");
	m.def("pus_tm_5_3_createMediumSeverityEventReport", &pus_tm_5_3_createMediumSeverityEventReport, "Binding for pus_tm_5_3_createMediumSeverityEventReport");
	m.def("pus_tm_5_4_createHighSeverityEventReport", &pus_tm_5_4_createHighSeverityEventReport, "Binding for pus_tm_5_4_createHighSeverityEventReport");
	m.def("pus_tm_5_X_setTmEventReportData", &pus_tm_5_X_setTmEventReportData, "Binding for pus_tm_5_X_setTmEventReportData");
	m.def("pus_tm_5_X_getTmEventReportData", &pus_tm_5_X_getTmEventReportData, "Binding for pus_tm_5_X_getTmEventReportData");
	m.def("pus_tm_5_X_getEventId", &pus_tm_5_X_getEventId, "Binding for pus_tm_5_X_getEventId");
	m.def("pus_tm_5_X_setEventId", &pus_tm_5_X_setEventId, "Binding for pus_tm_5_X_setEventId");
	m.def("pus_tm_5_X_getEventAuxData", &pus_tm_5_X_getEventAuxData, "Binding for pus_tm_5_X_getEventAuxData");
	m.def("pus_tm_5_X_setEventAuxData", &pus_tm_5_X_setEventAuxData, "Binding for pus_tm_5_X_setEventAuxData");
	m.def("pus_tm_5_X_getEventAuxData1", &pus_tm_5_X_getEventAuxData1, "Binding for pus_tm_5_X_getEventAuxData1");
	m.def("pus_tm_5_X_setEventAuxData1", &pus_tm_5_X_setEventAuxData1, "Binding for pus_tm_5_X_setEventAuxData1");
	m.def("pus_tm_5_X_getEventAuxData2", &pus_tm_5_X_getEventAuxData2, "Binding for pus_tm_5_X_getEventAuxData2");
	m.def("pus_tm_5_X_setEventAuxData2", &pus_tm_5_X_setEventAuxData2, "Binding for pus_tm_5_X_setEventAuxData2");
	m.def("pus_expectSt05Tm", &pus_expectSt05Tm, "Binding for pus_expectSt05Tm");

	m.doc() = "pus_st08_packets binding"
	m.def("pus_st08_initialize", &pus_st08_initialize, "Binding for pus_st08_initialize");
	m.def("pus_st08_isInitialized", &pus_st08_isInitialized, "Binding for pus_st08_isInitialized");
	m.def("pus_tc_8_1_createPerformFuctionRequest", &pus_tc_8_1_createPerformFuctionRequest, "Binding for pus_tc_8_1_createPerformFuctionRequest");
	m.def("pus_tc_8_1_setFunctionId", &pus_tc_8_1_setFunctionId, "Binding for pus_tc_8_1_setFunctionId");
	m.def("pus_tc_8_1_getFunctionId", &pus_tc_8_1_getFunctionId, "Binding for pus_tc_8_1_getFunctionId");
	m.def("pus_st08_isInFunctionTable", &pus_st08_isInFunctionTable, "Binding for pus_st08_isInFunctionTable");
	m.def("pus_expectSt08", &pus_expectSt08, "Binding for pus_expectSt08");

	m.doc() = "pus_st17_packets binding"
	m.def("pus_tc_17_1_createConnectionTestRequest", &pus_tc_17_1_createConnectionTestRequest, "Binding for pus_tc_17_1_createConnectionTestRequest");
	m.def("pus_tm_17_2_createConnectionTestReport", &pus_tm_17_2_createConnectionTestReport, "Binding for pus_tm_17_2_createConnectionTestReport");
	m.def("pus_st17_createTestResponse", &pus_st17_createTestResponse, "Binding for pus_st17_createTestResponse");
	m.def("pus_expectSt17Tc", &pus_expectSt17Tc, "Binding for pus_expectSt17Tc");
	m.def("pus_expectSt17Tm", &pus_expectSt17Tm, "Binding for pus_expectSt17Tm");

	m.doc() = "pus_st19_packets binding"
	m.def("pus_tc_19_X_createDefaultEventActionRequest", &pus_tc_19_X_createDefaultEventActionRequest, "Binding for pus_tc_19_X_createDefaultEventActionRequest");
	m.def("pus_tc_19_1_createAddEventActionDefinitionsRequest", &pus_tc_19_1_createAddEventActionDefinitionsRequest, "Binding for pus_tc_19_1_createAddEventActionDefinitionsRequest");
	m.def("pus_tc_19_2_createDeleteEventActionDefinitionsRequest", &pus_tc_19_2_createDeleteEventActionDefinitionsRequest, "Binding for pus_tc_19_2_createDeleteEventActionDefinitionsRequest");
	m.def("pus_tc_19_4_createEnableEventActionDefinitions", &pus_tc_19_4_createEnableEventActionDefinitions, "Binding for pus_tc_19_4_createEnableEventActionDefinitions");
	m.def("pus_tc_19_5_createDisableEventActionDefinitions", &pus_tc_19_5_createDisableEventActionDefinitions, "Binding for pus_tc_19_5_createDisableEventActionDefinitions");

}

