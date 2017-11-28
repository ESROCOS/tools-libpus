#include "pybind11/pybind11.h"
#include "../include/pus_packet.h"
#include "../include/pus_error.h"
#include "../include/pus_types.h"

namespace py = pybind11;

PYBIND11_MODULE(pusbinding, m) {
	m.doc() = "pus binding";
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

	py::class_<pusPacket_t> packet(m, "pusPacket_t");
    m.def("pus_getPacketVersion", &pus_getPacketVersion, "Binding for pus_getPacketVersion");
}
