/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pybind11/pybind11.h"
#include "pus_apid.h"
#include "pus_st01_packets.h"
#include "pus_st03_packets.h"
#include "pus_st05_packets.h"
#include "pus_st08_packets.h"
#include "pus_st08_config.h"
#include "pus_st09_packets.h"
#include "pus_st11_packets.h"
#include "pus_st12_packets.h"
#include "pus_st17_packets.h"
#include "pus_st18_packets.h"
#include "pus_st19_packets.h"
#include "pus_st20_packets.h"
#include "pus_st23_packets.h"
#include "pus_housekeeping.h"
#include "pus_stored_param.h"
#include "pus_time.h"
#include "pus_events.h"
#include "pus_notify.h"


#include "pus_bindingfunctions.hpp"

// We had to define this function to make sure st08 works
extern "C" {
	pusError_t example_function()
	{
		return PUS_NO_ERROR;
	}

	pusError_t example_function2()
	{
		return PUS_NO_ERROR;
	}

	pusError_t example_function3()
	{
		return PUS_NO_ERROR;
	}
}

pusError_t getError()
{
	return PUS_GET_ERROR();
}

namespace py = pybind11;

PYBIND11_MODULE(pusbinding, m) {
	m.doc() = "pus_packet binding";
	py::enum_<pusError_t>(m, "pusError_t")
	        .value("PUS_NO_ERROR",pusError_t::PUS_NO_ERROR)
	        .value("PUS_ERROR_NULLPTR",pusError_t::PUS_ERROR_NULLPTR)
	        .value("PUS_ERROR_COUNT_WRAP",pusError_t::PUS_ERROR_COUNT_WRAP)
	        .value("PUS_ERROR_HEADER_MISMATCH",pusError_t::PUS_ERROR_HEADER_MISMATCH)
	        .value("PUS_ERROR_PACKET_TYPE",pusError_t::PUS_ERROR_PACKET_TYPE)
	        .value("PUS_ERROR_NOT_TM",pusError_t::PUS_ERROR_NOT_TM)
	        .value("PUS_ERROR_NOT_TC",pusError_t::PUS_ERROR_NOT_TC)
	        .value("PUS_ERROR_SYSTEM_TIME",pusError_t::PUS_ERROR_SYSTEM_TIME)
	        .value("PUS_ERROR_LIMIT",pusError_t::PUS_ERROR_LIMIT)
	        .value("PUS_ERROR_UNEXPECTED_PACKET_VERSION",pusError_t::PUS_ERROR_UNEXPECTED_PACKET_VERSION)
	        .value("PUS_ERROR_UNEXPECTED_SEQUENCE_FLAGS",pusError_t::PUS_ERROR_UNEXPECTED_SEQUENCE_FLAGS)
	        .value("PUS_ERROR_UNEXPECTED_PUS_VERSION",pusError_t::PUS_ERROR_UNEXPECTED_PUS_VERSION)
	        .value("PUS_ERROR_NOT_IMPLEMENTED",pusError_t::PUS_ERROR_NOT_IMPLEMENTED)
	        .value("PUS_ERROR_TM_KIND",pusError_t::PUS_ERROR_TM_KIND)
	        .value("PUS_ERROR_TM_SERVICE",pusError_t::PUS_ERROR_TM_SERVICE)
	        .value("PUS_ERROR_TM_SUBTYPE",pusError_t::PUS_ERROR_TM_SUBTYPE)
	        .value("PUS_ERROR_TC_KIND",pusError_t::PUS_ERROR_TC_KIND)
	        .value("PUS_ERROR_TC_SERVICE",pusError_t::PUS_ERROR_TC_SERVICE)
	        .value("PUS_ERROR_TC_SUBTYPE",pusError_t::PUS_ERROR_TC_SUBTYPE)
	        .value("PUS_ERROR_SUBTYPE_MISMATCH",pusError_t::PUS_ERROR_SUBTYPE_MISMATCH)
	        .value("PUS_ERROR_THREADS",pusError_t::PUS_ERROR_THREADS)
	        .value("PUS_ERROR_BEFORE",pusError_t::PUS_ERROR_BEFORE)
	        .value("PUS_ERROR_ALREADY_INITIALIZED",pusError_t::PUS_ERROR_ALREADY_INITIALIZED)
	        .value("PUS_ERROR_NOT_INITIALIZED",pusError_t::PUS_ERROR_NOT_INITIALIZED)
	        .value("PUS_ERROR_INITIALIZATION",pusError_t::PUS_ERROR_INITIALIZATION)
	        .value("PUS_ERROR_FINALIZATION",pusError_t::PUS_ERROR_FINALIZATION)
	        .value("PUS_ERROR_INVALID_ID",pusError_t::PUS_ERROR_INVALID_ID)
	        .value("PUS_ERROR_INVALID_TYPE",pusError_t::PUS_ERROR_INVALID_TYPE)
	        .value("PUS_ERROR_THREADS_DISABLED",pusError_t::PUS_ERROR_THREADS_DISABLED)
	        .value("PUS_ERROR_REPORT_ID_UNKNOWN",pusError_t::PUS_ERROR_REPORT_ID_UNKNOWN)
	        .value("PUS_ERROR_REPORT_LENGTH",pusError_t::PUS_ERROR_REPORT_LENGTH)
	        .value("PUS_LAST_ERROR",pusError_t::PUS_LAST_ERROR)
	        .export_values();

	py::enum_<pusParamType_t>(m, "pusParamType_t")
		        .value("PUS_INT32",pusParamType_t::PUS_INT32)
		        .value("PUS_UINT32",pusParamType_t::PUS_UINT32)
		        .value("PUS_REAL64",pusParamType_t::PUS_REAL64)
		        .value("PUS_BYTE",pusParamType_t::PUS_BYTE)
		        .value("PUS_BOOL",pusParamType_t::PUS_BOOL)
		        .export_values();


	m.def("getError", getError, "");
	m.def("ret_packets", ret_packets);
	m.def("pus_notify_readTm", &pus_notify_readTm);
	m.def("pus_notify_writeTm", &pus_notify_writeTm);
	m.def("pus_notify_readTc", &pus_notify_readTc);
	m.def("pus_notify_writeTc", &pus_notify_writeTc);
	m.def("pus_notify_sendPacket", &pus_notify_sendPacket);
	m.def("pus_notify_getNumPackets", &pus_notify_getTmQueueNumPackets);


	//m.def("getint", &getint);

	py::class_<pusMutex_t>(m, "pusMutex_t")
		.def(py::init<>());

	py::class_<pusTime_t>(m, "pusTime_t")
			.def(py::init<>());
	m.def("pus_now", &pus_now, "Binding for pus_now");
	m.def("pus_time2posix", &pus_time2posix_, "Binding for pus_time2posix");
	m.def("pus_posix2time", &pus_posix2time_, "Binding for pus_posix2time");

	py::class_<pusPacketReduced_t>(m, "pusPacketReduced_t")
			.def(py::init<>());

	py::class_<pusPacket_t>(m, "pusPacket_t")
		.def(py::init<>());
	m.def("pus_getPacketVersion", &pus_getPacketVersion_, "Binding for pus_getPacketVersion");
	m.def("pus_setPacketVersion", &pus_setPacketVersion_, "Binding for pus_setPacketVersion");
	m.def("pus_getPacketType", &pus_getPacketType_, "Binding for pus_getPacketType");
	m.def("pus_setPacketType", &pus_setPacketType_, "Binding for pus_setPacketType");
	m.def("pus_getApid", &pus_getApid, "Binding for pus_getApid");
	m.def("pus_setApid", &pus_setApid, "Binding for pus_setApid");
	m.def("pus_getSecondaryHeaderFlag", &pus_getSecondaryHeaderFlag, "Binding for pus_getSecondaryHeaderFlag");
	m.def("pus_setSecondaryHeaderFlag", &pus_setSecondaryHeaderFlag, "Binding for pus_setSecondaryHeaderFlag");
	m.def("pus_getSequenceFlags", &pus_getSequenceFlags_, "Binding for pus_getSequenceFlags");
	m.def("pus_setSequenceFlags", &pus_setSequenceFlags_, "Binding for pus_setSequenceFlags");
	m.def("pus_getSequenceCount", &pus_getSequenceCount, "Binding for pus_getSequenceCount");
	m.def("pus_setSequenceCount", &pus_setSequenceCount, "Binding for pus_setSequenceCount");
	m.def("pus_getPacketDataLength", &pus_getPacketDataLength, "Binding for pus_getPacketDataLength");
	m.def("pus_setPacketDataLength", &pus_setPacketDataLength, "Binding for pus_setPacketDataLength");
	m.def("pus_setPacketDataNone", &pus_setPacketDataNone, "Binding for pus_setPacketDataNone");
	m.def("pus_getTmPusVersion", &pus_getTmPusVersion_, "Binding for pus_getTmPusVersion");
	m.def("pus_setTmPusVersion", &pus_setTmPusVersion_, "Binding for pus_setTmPusVersion");
	m.def("pus_getTcPusVersion", &pus_getTcPusVersion_, "Binding for pus_getTcPusVersion");
	m.def("pus_setTcPusVersion", &pus_setTcPusVersion_, "Binding for pus_setTcPusVersion");
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
	m.def("pus_getTmPacketTime", &pus_getTmPacketTime_, "Binding for pus_getTmPacketTime");
	m.def("pus_setTmPacketTime", &pus_setTmPacketTime_, "Binding for pus_setTmPacketTime");
	//m.def("pus_setTmPacketTimeNow", &pus_setTmPacketTimeNow, "Binding for pus_setTmPacketTimeNow");
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
	//m.def("pus_setPacketTimeNow", &pus_setPacketTimeNow, "Binding for pus_setPacketTimeNow");
	m.def("pus_setPacketDefaults", &pus_setPacketDefaults, "Binding for pus_setPacketDefaults");
	m.def("pus_initTmPacket", &pus_initTmPacket, "Binding for pus_initTmPacket");
	m.def("pus_initTcPacket", &pus_initTcPacket, "Binding for pus_initTcPacket");
	m.def("pus_initTmPacketNoHeader", &pus_initTmPacketNoHeader, "Binding for pus_initTmPacketNoHeader");
	m.def("pus_initTcPacketNoHeader", &pus_initTcPacketNoHeader, "Binding for pus_initTcPacketNoHeader");
	m.def("pus_verifyCcsdsHeaderDefaults", &pus_verifyCcsdsHeaderDefaults, "Binding for pus_verifyCcsdsHeaderDefaults");
	m.def("pus_verifyPacketDataKind", &pus_verifyPacketDataKind, "Binding for pus_verifyPacketDataKind");
	m.def("pus_verifyTmSecondaryHeaderDefaults", &pus_verifyTmSecondaryHeaderDefaults, "Binding for pus_verifyTmSecondaryHeaderDefaults");
	//m.def("pus_checkTcSecondaryHeaderDefaults", &pus_checkTcSecondaryHeaderDefaults, "Binding for pus_checkTcSecondaryHeaderDefaults");
	m.def("pus_verifyTmHeaderDefaults", &pus_verifyTmHeaderDefaults, "Binding for pus_verifyTmHeaderDefaults");
	m.def("pus_verifyTcHeaderDefaults", &pus_verifyTcHeaderDefaults, "Binding for pus_verifyTcHeaderDefaults");
	m.def("pus_expectTm", &pus_expectTm, "Binding for pus_expectTm");
	m.def("pus_expectTmHeader", &pus_expectTmHeader, "Binding for pus_expectTmHeader");
	m.def("pus_expectTmNoHeader", &pus_expectTmNoHeader, "Binding for pus_expectTmNoHeader");
	m.def("pus_expectTc", &pus_expectTc, "Binding for pus_expectTc");
	m.def("pus_expectTcHeader", &pus_expectTcHeader, "Binding for pus_expectTcHeader");
	m.def("pus_expectTcNoHeader", &pus_expectTcNoHeader, "Binding for pus_expectTcNoHeader");

	m.doc() = "pus_apid binding";
	py::class_<pusApidInfo_t>(m, "pusApidInfo_t")
		.def(py::init<>());
	m.def("pus_initApidInfo", &pus_initApidInfo, "Binding for pus_initApidInfo");
	m.def("pus_initApidInfo_null", &pus_initApidInfo_null, "Binding for pus_initApidInfo with null in mutex");
	m.def("pus_getInfoApid", &pus_getInfoApid, "Binding for pus_getInfoApid");
	m.def("pus_getNextPacketCount", &pus_getNextPacketCount, "Binding for pus_getNextPacketCount");

	m.doc() = "pus_st01_packets binding";
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
	m.def("pus_tm_1_X_getReportPacketVersionNumber", &pus_tm_1_X_getPacketVersionNumber_, "Binding for pus_tm_1_X_getPacketVersionNumber"); //Devuelve version pack telecomando al q responde
	m.def("pus_tm_1_X_setPacketType", &pus_tm_1_X_setPacketType, "Binding for pus_tm_1_X_setPacketType");
	m.def("pus_tm_1_X_getReportPacketType", &pus_tm_1_X_getPacketType_, "Binding for pus_tm_1_X_getPacketType");
	m.def("pus_tm_1_X_setSecondaryHeaderFlag", &pus_tm_1_X_setSecondaryHeaderFlag, "Binding for pus_tm_1_X_setSecondaryHeaderFlag");
	m.def("pus_tm_1_X_getReportSecondaryHeaderFlag", &pus_tm_1_X_getSecondaryHeaderFlag, "Binding for pus_tm_1_X_getSecondaryHeaderFlag");
	m.def("pus_tm_1_X_setApid", &pus_tm_1_X_setApid, "Binding for pus_tm_1_X_setApid");
	m.def("pus_tm_1_X_getReportApid", &pus_tm_1_X_getApid, "Binding for pus_tm_1_X_getApid"); // Podria ser interesante mostrarlo
	m.def("pus_tm_1_X_setSequenceFlags", &pus_tm_1_X_setSequenceFlags, "Binding for pus_tm_1_X_setSequenceFlags");
	m.def("pus_tm_1_X_getReportSequenceFlags", &pus_tm_1_X_getSequenceFlags_, "Binding for pus_tm_1_X_getSequenceFlags");
	m.def("pus_tm_1_X_setSequenceCount", &pus_tm_1_X_setSequenceCount, "Binding for pus_tm_1_X_setSequenceCount");
	m.def("pus_tm_1_X_getReportSequenceCount", &pus_tm_1_X_getSequenceCount, "Binding for pus_tm_1_X_getSequenceCount");
	m.def("pus_tm_1_X_setStep", &pus_tm_1_X_setStep, "Binding for pus_tm_1_X_setStep");
	m.def("pus_tm_1_X_getStep", &pus_tm_1_X_getStep, "Binding for pus_tm_1_X_getStep");
	m.def("pus_tm_1_X_initFailureInfo", &pus_tm_1_X_initFailureInfo, "Binding for pus_tm_1_X_initFailureInfo");
	m.def("pus_tm_1_X_getFailureCode", &pus_tm_1_X_getFailureCode_, "Binding for pus_tm_1_X_getFailureInfo");
	m.def("pus_tm_1_X_setFailureInfo", &pus_tm_1_X_setFailureInfo, "Binding for pus_tm_1_X_setFailureInfo");
	m.def("pus_initSt01FailureInfo", &pus_initSt01FailureInfo, "Binding for pus_initSt01FailureInfo");
	m.def("pus_setSt01FailureInfo", &pus_setSt01FailureInfo_, "Binding for pus_setSt01FailureInfo");
	m.def("pus_getSt01FailureSubcode", &pus_getSt01FailureSubcode_, "Binding for pus_getSt01FailureSubcode");
	m.def("pus_getSt01FailureData", &pus_getSt01FailureData_, "Binding for pus_getSt01FailureData");
	m.def("pus_getSt01FailureAddress", &pus_getSt01FailureAddress_, "Binding for pus_getSt01FailureAddress");
	m.def("pus_expectSt01Tm", &pus_expectSt01Tm, "Binding for pus_expectSt01Tm");

	m.doc() = "pus_st03_packets binding";
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
	m.def("pus_tm_3_25_setParameterValue", &pus_tm_3_25_setParameterValue, "Binding for pus_tm_3_25_setParameterValue");
	m.def("pus_tm_3_25_getParameterValue", &pus_tm_3_25_getParameterValue_, "Binding for pus_tm_3_25_getParameterValue");
	m.def("pus_tm_3_25_getNumParameters", &pus_tm_3_25_getNumParameters_, "Binding for pus_tm_3_25_getNumParameters");
	m.def("pus_tm_3_25_setNumParameters", &pus_tm_3_25_setNumParameters, "Binding for pus_tm_3_25_setNumParameters");
	m.def("pus_st03_getHkReportInfoName", &pus_st03_getHkReportInfoName, "Binding for pus_st03_getHkReportInfoName");
	m.def("pus_st03_getHkReportInfoType", &pus_st03_getHkReportInfoType, "Binding for pus_st03_getHkReportInfoType");
	m.def("pus_paramToUint32", &pus_paramToUint32_, "Binding for pus_paramToUint32");
	m.def("pus_paramToInt32", &pus_paramToInt32_, "Binding for pus_paramToInt32");
	m.def("pus_paramToReal64", &pus_paramToReal64_, "Binding for pus_paramToReal64");
	m.def("pus_paramToBool", &pus_paramToBool_, "Binding for pus_paramToBool");
	m.def("pus_paramToByte", &pus_paramToByte_, "Binding for pus_paramToByte");
	m.def("pus_expectSt03Tm", &pus_expectSt03Tm, "Binding for pus_expectSt03Tm");

	py::class_<st05Event>(m, "st05Event")
			.def(py::init<>());
	m.doc() = "pus_st05_packets binding";
	m.def("pus_events_initialize", &pus_events_initialize, "Binding for pus_events_initialize");
	m.def("pus_events_finalize", &pus_events_finalize, "Binding for pus_events_finalize");
	m.def("pus_events_isInitialized", &pus_events_isInitialized, "Binding for pus_events_isInitialized");
	m.def("pus_events_init_struct", &pus_event_init_struct_, "Binding for pus_event_init");
	m.def("pus_tm_5_X_createEventReport", &pus_tm_5_X_createEventReport_, "Binding for pus_tm_5_X_createEventReport");
	m.def("pus_tm_5_1_createInformativeEventReport", &pus_tm_5_1_createInformativeEventReport_, "Binding for pus_tm_5_1_createInformativeEventReport");
	m.def("pus_tm_5_2_createLowSeverityEventReport", &pus_tm_5_2_createLowSeverityEventReport_, "Binding for pus_tm_5_2_createLowSeverityEventReport");
	m.def("pus_tm_5_3_createMediumSeverityEventReport", &pus_tm_5_3_createMediumSeverityEventReport_, "Binding for pus_tm_5_3_createMediumSeverityEventReport");
	m.def("pus_tm_5_4_createHighSeverityEventReport", &pus_tm_5_4_createHighSeverityEventReport_, "Binding for pus_tm_5_4_createHighSeverityEventReport");
	m.def("pus_tm_get_5_X_event_id", &pus_tm_get_5_X_event_id_, "Binding for pus_events_getEventId");
	m.def("pus_tm_get_5_X_event_auxdata1", &pus_tm_get_5_X_event_auxdata1_, "Binding for pus_events_getEventAuxData");
	m.def("pus_tm_get_5_X_event_auxdata2", &pus_tm_get_5_X_event_auxdata2_, "Binding for pus_events_getEventAuxData1");
	m.def("pus_st05_getEventName", &pus_st05_getEventName, "Binding for pus_st05_getEventName");
	m.def("pus_st05_getDataType1", &pus_st05_getDataType1, "Binding for pus_st05_getDataType1");
	m.def("pus_st05_getDataType2", &pus_st05_getDataType2, "Binding for pus_st05_getDataType2");


	m.doc() = "pus_st08_packets binding";
	m.def("pus_st08_initialize", &pus_st08_initialize, "Binding for pus_st08_initialize");
	m.def("pus_st08_isInitialized", &pus_st08_isInitialized, "Binding for pus_st08_isInitialized");
	m.def("pus_tc_8_1_createPerformFuctionRequest", &pus_tc_8_1_createPerformFuctionRequest, "Binding for pus_tc_8_1_createPerformFuctionRequest");
	m.def("pus_tc_8_1_setFunctionId", &pus_tc_8_1_setFunctionId, "Binding for pus_tc_8_1_setFunctionId");
	m.def("pus_tc_8_1_getFunctionId", &pus_tc_8_1_getFunctionId_, "Binding for pus_tc_8_1_getFunctionId");
	m.def("pus_st08_isInFunctionTable", &pus_st08_isInFunctionTable, "Binding for pus_st08_isInFunctionTable");
	m.def("pus_expectSt08", &pus_expectSt08, "Binding for pus_expectSt08");

	m.def("pus_tc_9_1_createSetTimeReportRate", &pus_tc_9_1_createSetTimeReportRate, "Binding for pus_tc_9_1_createSetTimeReportRate");
	m.def("pus_tm_9_2_createCucTimeReport", &pus_tm_9_2_createCucTimeReport, "Binding for pus_tm_9_2_createCucTimeReport");
	m.def("pus_tc_9_1_setExponentialRate", &pus_tc_9_1_setExponentialRate, "Binding for pus_tc_9_1_setExponentialRate");
	m.def("pus_tc_9_1_getExponentialRate", &pus_tc_9_1_getExponentialRate_, "Binding for pus_tc_9_1_getExponentialRate");
	m.def("pus_tm_9_2_setDataField", &pus_tm_9_2_setDataField, "Binding for pus_tm_9_2_setDataField");
	m.def("pus_tm_9_2_getDataField", &pus_tm_9_2_getDataField_, "Binding for pus_tm_9_2_getDataField");
	m.def("pus_time_getReportGenerationExponentialRate", &pus_time_getReportGenerationExponentialRate, "Binding for pus_time_getReportGenerationExponentialRate");
	m.def("pus_time_setReportGenerationExponentialRate", &pus_time_setReportGenerationExponentialRate, "Binding for pus_time_setReportGenerationExponentialRate");
	m.def("pus_time_getReportGenerationRate", &pus_time_getReportGenerationRate, "Binding for pus_time_getReportGenerationRate");
	m.def("pus_expectSt09Tc", &pus_expectSt09Tc, "Binding for pus_expectSt09Tc");
	m.def("pus_expectSt09Tm", &pus_expectSt09Tm, "Binding for pus_expectSt09Tm");

	m.doc() = "pus_st11_packets binding";
	m.def("pus_tc_11_X_createDefaultPacket", &pus_tc_11_X_createDefaultPacket, "Binding for pus_tc_11_X_createDefaultPacket");
	m.def("pus_tc_11_1_createEnableTimeBasedSchedule", &pus_tc_11_1_createEnableTimeBasedSchedule, "Binding for pus_tc_11_1_createEnableTimeBasedSchedule");
	m.def("pus_tc_11_2_createDisableTimeBasedSchedule", &pus_tc_11_2_createDisableTimeBasedSchedule, "Binding for pus_tc_11_2_createDisableTimeBasedSchedule");
	m.def("pus_tc_11_3_createResetTimeBasedSchedule", &pus_tc_11_3_createResetTimeBasedSchedule, "Binding for pus_tc_11_3_createResetTimeBasedSchedule");
	m.def("pus_tc_11_4_createInsertActivityIntoSchedule", &pus_tc_11_4_createInsertActivityIntoSchedule, "Binding for pus_tc_11_4_createInsertActivityIntoSchedule");
	m.def("pus_tc_11_4_getNCount", &pus_tc_11_4_getNCount, "Binding for pus_tc_11_4_getNCount");
	m.def("pus_tc_11_4_setNCount", &pus_tc_11_4_setNCount, "Binding for pus_tc_11_4_setNCount");
	m.def("pus_tc_11_4_setActivity", &pus_tc_11_4_setActivity, "Binding for pus_tc_11_4_setActivity");
	m.def("pus_tc_11_4_getActivities", &pus_tc_11_4_getActivities, "Binding for pus_tc_11_4_getActivities");
	m.def("pus_tc_11_4_get_request", &pus_tc_11_4_get_request, "Binding for pus_tc_11_4_get_request");
	m.def("pus_tc_11_4_get_release_time", &pus_tc_11_4_get_release_time, "Binding for pus_tc_11_4_get_release_time");
	m.def("pus_expectSt11Tc", &pus_expectSt11Tc, "Binding for pus_expectSt11Tc");

	m.doc() = "pus_st12_packets binding";
	m.def("pus_tc_12_X_createDefaultPacket", &pus_tc_12_X_createDefaultPacket, "Binding for pus_tc_12_X_createDefaultPacket");
	m.def("pus_tc_12_1_createEnableParameterMonitoringDefinitions", &pus_tc_12_1_createEnableParameterMonitoringDefinitions, "Binding for pus_tc_12_1_createEnableParameterMonitoringDefinitions");
	m.def("pus_tc_12_2_createDisableParameterMonitoringDefinitions", &pus_tc_12_2_createDisableParameterMonitoringDefinitions, "Binding for pus_tc_12_2_createDisableParameterMonitoringDefinitions");
	m.def("pus_tc_12_15_createEnableParameterMonitoring", &pus_tc_12_15_createEnableParameterMonitoring, "Binding for pus_tc_12_15_createEnableParameterMonitoring");
	m.def("pus_tc_12_16_createDisableParameterMonitoring", &pus_tc_12_16_createDisableParameterMonitoring, "Binding for pus_tc_12_16_createDisableParameterMonitoring");
	m.def("pus_tc_12_1_2_setPmonId", &pus_tc_12_1_2_setPmonId, "Binding for pus_tc_12_1_2_setPmonId");
	m.def("pus_tc_12_1_2_getPmonId", &pus_tc_12_1_2_getPmonId_, "Binding for pus_tc_12_1_2_getPmonId");
	m.def("pus_expectSt12Tc", &pus_expectSt12Tc, "Binding for pus_expectSt12Tc");

	m.doc() = "pus_st17_packets binding";
	m.def("pus_tc_17_1_createConnectionTestRequest", &pus_tc_17_1_createConnectionTestRequest, "Binding for pus_tc_17_1_createConnectionTestRequest");
	m.def("pus_tm_17_2_createConnectionTestReport", &pus_tm_17_2_createConnectionTestReport, "Binding for pus_tm_17_2_createConnectionTestReport");
	m.def("pus_st17_createTestResponse", &pus_st17_createTestResponse, "Binding for pus_st17_createTestResponse");
	m.def("pus_expectSt17Tc", &pus_expectSt17Tc, "Binding for pus_expectSt17Tc");
	m.def("pus_expectSt17Tm", &pus_expectSt17Tm, "Binding for pus_expectSt17Tm");

	m.def("pus_tc_18_X_createDefaultRequest", &pus_tc_18_X_createDefaultRequest, "Binding f	or pus_tc_18_X_createDefaultRequest");
	m.def("pus_tc_18_1_createLoadObcpDirectRequest", &pus_tc_18_1_createLoadObcpDirectRequest_, "Binding for pus_tc_18_1_createLoadObcpDirectRequest");
	m.def("pus_tc_18_2_createUnloadObcpRequest", &pus_tc_18_2_createUnloadObcpRequest_, "Binding for pus_tc_18_2_createUnloadObcpRequest");
	m.def("pus_tc_18_3_createActivateObcpRequest", &pus_tc_18_3_createActivateObcpRequest_, "Binding for pus_tc_18_3_createActivateObcpRequest");
	m.def("pus_tc_18_4_createStopObcpRequest", &pus_tc_18_4_createStopObcpRequest_, "Binding for pus_tc_18_4_createStopObcpRequest");
	m.def("pus_tc_18_5_createSuspendObcpRequest", &pus_tc_18_5_createSuspendObcpRequest_, "Binding for pus_tc_18_5_createSuspendObcpRequest");
	m.def("pus_tc_18_6_createResumeObcpRequest", &pus_tc_18_6_createResumeObcpRequest_, "Binding for pus_tc_18_6_createResumeObcpRequest");
	m.def("pus_tc_18_12_createAbortObcpRequest", &pus_tc_18_12_createAbortObcpRequest_, "Binding for pus_tc_18_12_createAbortObcpRequest");
	m.def("pus_tc_18_13_createLoadObcpReferenceRequest", &pus_tc_18_13_createLoadObcpReferenceRequest_, "Binding for pus_tc_18_13_createLoadObcpReferenceRequest");
	m.def("pus_tc_18_21_createStartObcpEngineRequest", &pus_tc_18_21_createStartObcpEngineRequest, "Binding for pus_tc_18_21_createStartObcpEngineRequest");
	m.def("pus_tc_18_22_createStopObcpEngineRequest", &pus_tc_18_22_createStopObcpEngineRequest, "Binding for pus_tc_18_22_createStopObcpEngineRequest");
	m.def("pus_tc_18_X_setObcpId", &pus_tc_18_X_setObcpId_, "Binding for pus_tc_18_X_setObcpId");
	m.def("pus_tc_18_X_getObcpId", &pus_tc_18_X_getObcpId_, "Binding for pus_tc_18_X_getObcpId");
	m.def("pus_tc_18_1_setObcpCode", &pus_tc_18_1_setObcpCode_, "Binding for pus_tc_18_1_setObcpCode");
	m.def("pus_tc_18_1_getObcpCode", &pus_tc_18_1_getObcpCode_, "Binding for pus_tc_18_1_getObcpCode");
	m.def("pus_tc_18_3_setObservabilityLevel", &pus_tc_18_3_setObservabilityLevel_, "Binding for pus_tc_18_3_setObservabilityLevel");
	m.def("pus_tc_18_3_getObservabilityLevel", &pus_tc_18_3_getObservabilityLevel_, "Binding for pus_tc_18_3_getObservabilityLevel");
	m.def("pus_tc_18_4_5_setObcpStepId", &pus_tc_18_4_5_setObcpStepId, "Binding for pus_tc_18_4_5_setObcpStepId");
	m.def("pus_tc_18_4_5_getObcpStepId", &pus_tc_18_4_5_getObcpStepId_, "Binding for pus_tc_18_4_5_getObcpStepId");
	m.def("pus_tc_18_13_setFileName", &pus_tc_18_13_setFileName_, "Binding for pus_tc_18_13_setFileName");
	m.def("pus_tc_18_13_getFileName", &pus_tc_18_13_getFileName_, "Binding for pus_tc_18_13_getFileName");
	m.def("pus_tc_18_13_setRepositoryPath", &pus_tc_18_13_setRepositoryPath_, "Binding for pus_tc_18_13_setRepositoryPath");
	m.def("pus_tc_18_13_getRepositoryPath", &pus_tc_18_13_getRepositoryPath_, "Binding for pus_tc_18_13_getRepositoryPath");
	m.def("pus_expectSt18Tc", &pus_expectSt18Tc, "Binding for pus_expectSt18Tc");

	m.doc() = "pus_st19_packets binding";
	m.def("pus_tc_19_X_createDefaultEventActionRequest", &pus_tc_19_X_createDefaultEventActionRequest, "Binding for pus_tc_19_X_createDefaultEventActionRequest");
	m.def("pus_tc_19_1_createAddEventActionDefinitionsRequest", &pus_tc_19_1_createAddEventActionDefinitionsRequest, "Binding for pus_tc_19_1_createAddEventActionDefinitionsRequest");
	m.def("pus_tc_19_2_createDeleteEventActionDefinitionsRequest", &pus_tc_19_2_createDeleteEventActionDefinitionsRequest, "Binding for pus_tc_19_2_createDeleteEventActionDefinitionsRequest");
	m.def("pus_tc_19_4_createEnableEventActionDefinitions", &pus_tc_19_4_createEnableEventActionDefinitions, "Binding for pus_tc_19_4_createEnableEventActionDefinitions");
	m.def("pus_tc_19_5_createDisableEventActionDefinitions", &pus_tc_19_5_createDisableEventActionDefinitions, "Binding for pus_tc_19_5_createDisableEventActionDefinitions");
	m.def("pus_packetReduced_createPacketReducedFromPacket", &pus_packetReduced_createPacketReducedFromPacket, "Binding for pus_tc_19_X_createPacketReducedFromPacket");
	//m.def("pus_tc_19_X_setPacketReducedTcData", &pus_tc_19_X_setPacketReducedTcData, "Binding for pus_tc_19_X_setPacketReducedTcData");
	//m.def("pus_tc_19_X_setPacketTcData", &pus_tc_19_X_setPacketTcData, "Binding for pus_tc_19_X_setPacketTcData");
	m.def("pus_packetReduced_createPacketFromPacketReduced", &pus_packetReduced_createPacketFromPacketReduced, "Binding for pus_tc_19_X_createPacketFromPacketReduced");
	m.def("pus_tc_19_X_setEventId", &pus_tc_19_X_setEventId, "Binding for pus_tc_19_X_setEventId");
	m.def("pus_tc_19_X_getEventId", &pus_tc_19_X_getEventId, "Binding for pus_tc_19_X_getEventId");
	m.def("pus_tc_19_1_setAction", &pus_tc_19_1_setAction, "Binding for pus_tc_19_1_setAction");
	m.def("pus_tc_19_1_getAction", &pus_tc_19_1_getAction, "Binding for pus_tc_19_1_getAction");
	m.def("pus_expectSt19Tc", &pus_expectSt19Tc, "Binding for pus_expectSt19Tc");


	m.doc() = "pus_st20_packets binding";
	m.def("pus_tc_20_1_createParameterValueRequest", &pus_tc_20_1_createParameterValueRequest, "Binding for pus_tc_20_1_createParameterValueRequest");
	m.def("pus_tm_20_2_createParameterValueReport", &pus_tm_20_2_createParameterValueReport, "Binding for pus_tm_20_2_createParameterValueReport");
	m.def("pus_tc_20_3_createSetParameterValueRequest", &pus_tc_20_3_createSetParameterValueRequest, "Binding for pus_tc_20_3_createSetParameterValueRequest");
	m.def("pus_tc_20_X_setParamId", &pus_tc_20_X_setParamId, "Binding for pus_tc_20_X_setParamId");
	m.def("pus_tc_20_X_getParamId", &pus_tc_20_X_getParamId, "Binding for pus_tc_20_X_getParamId");
	m.def("pus_tc_20_3_setParamValue", &pus_tc_20_3_setParamValue, "Binding for pus_tc_20_3_setParamValue");
	m.def("pus_tc_20_3_getParamValue", &pus_tc_20_3_getParamValue, "Binding for pus_tc_20_3_getParamValue");
	m.def("pus_tm_20_2_setParamId", &pus_tm_20_2_setParamId, "Binding for pus_tm_20_2_setParamId");
	m.def("pus_tm_20_2_getParamId", &pus_tm_20_2_getParamId, "Binding for pus_tm_20_2_getParamId");
	m.def("pus_tm_20_2_setParamValue", &pus_tm_20_2_setParamValue, "Binding for pus_tm_20_2_setParamValue");
	m.def("pus_tm_20_2_getParamValue", &pus_tm_20_2_getParamValue, "Binding for pus_tm_20_2_getParamValue");
	m.def("pus_expectSt20Tc", &pus_expectSt20Tc, "Binding for pus_expectSt20Tc");
	m.def("pus_expectSt20Tm", &pus_expectSt20Tm, "Binding for pus_expectSt20Tm");

	m.doc() = "pus_st23_packets binding";
	m.def("pus_tc_23_1_createCreateFileRequest", &pus_tc_23_1_createCreateFileRequest_, "Binding for pus_tc_23_1_createCreateFileRequest");
	m.def("pus_tc_23_2_createDeleteFileRequest", &pus_tc_23_2_createDeleteFileRequest_, "Binding for pus_tc_23_2_createDeleteFileRequest");
	m.def("pus_tc_23_3_createReportFileAtributesRequest", &pus_tc_23_3_createReportFileAtributesRequest_, "Binding for pus_tc_23_3_createReportFileAtributesRequest");
	m.def("pus_tc_23_14_createCopyFileRequest", &pus_tc_23_14_createCopyFileRequest_, "Binding for pus_tc_23_3_createReportFileAtributesRequest");
	m.def("pus_tc_tm_23_X_setFileName", &pus_tc_tm_23_X_setFileName_, "Binding for pus_tc_tm_23_X_setFileName");
	m.def("pus_tc_tm_23_X_setRepositoryPath", &pus_tc_tm_23_X_setRepositoryPath_, "Binding for pus_tc_tm_23_X_setRepositoryPath_");
	m.def("pus_tc_23_14_setSourceFileName", &pus_tc_23_14_setSourceFileName_, "Binding for pus_tc_23_14_setSourceFileName");
	m.def("pus_tc_23_14_setTargetFileName", &pus_tc_23_14_setTargetFileName_, "Binding for pus_tc_23_14_setTargetFileName");
	m.def("pus_tc_23_14_setSourceRepositoryPath", &pus_tc_23_14_setSourceRepositoryPath_, "Binding for pus_tc_23_14_setSourceRepositoryPath");
	m.def("pus_tc_23_14_setTargetRepositoryPath", &pus_tc_23_14_setTargetRepositoryPath_, "Binding for pus_tc_23_14_setTargetRepositoryPath");
	m.def("pus_tc_tm_23_1_4_setMaximumSize", &pus_tc_tm_23_1_4_setMaximumSize, "Binding for pus_tc_tm_23_1_4_setMaximumSize");
	m.def("pus_tc_tm_23_X_getFileName", &pus_tc_tm_23_X_getFileName_, "Binding for pus_tc_tm_23_X_getFileName");
	m.def("pus_tc_tm_23_X_getRepositoryPath", &pus_tc_tm_23_X_getRepositoryPath_, "Binding for pus_tc_tm_23_X_getRepositoryPath");
	m.def("pus_tc_23_14_getSourceFileName", &pus_tc_23_14_getSourceFileName_, "Binding for pus_tc_23_14_getSourceFileName");
	m.def("pus_tc_23_14_getTargetFileName", &pus_tc_23_14_getTargetFileName_, "Binding for pus_tc_23_14_getTargetFileName");
	m.def("pus_tc_23_14_getSourceRepositoryPath", &pus_tc_23_14_getSourceRepositoryPath_, "Binding for pus_tc_23_14_getSourceRepositoryPath");
	m.def("pus_tc_23_14_getTargetRepositoryPath", &pus_tc_23_14_getTargetRepositoryPath_, "Binding for pus_tc_23_14_getTargetRepositoryPath");
	m.def("pus_tc_tm_23_1_4_getMaximumSize", &pus_tc_tm_23_1_4_getMaximumSize_, "Binding for pus_tc_tm_23_1_4_getMaximumSize");
}
