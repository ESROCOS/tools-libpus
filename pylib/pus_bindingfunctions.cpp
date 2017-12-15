#include "pus_bindingfunctions.hpp"

pusError_t pus_initApidInfo_(pusApidInfo_t *obj, pusApid_t apid)
{
	return pus_initApidInfo(obj, apid, NULL);
}

uint pus_getPacketVersion_(const pusPacket_t *packet)
{
	return (uint) pus_getPacketVersion(packet);
}

void pus_setPacketVersion_(pusPacket_t *packet, uint version)
{
	pusVersion_t vers = static_cast<pusVersion_t>(version);
	pus_setTcPusVersion(packet, vers);
}

uint pus_getPacketType_(const pusPacket_t *packet)
{
	return (uint) pus_getPacketType(packet);
}

void pus_setPacketType_(pusPacket_t *packet, uint type_)
{
	pusPacketType_t type = static_cast<pusPacketType_t>(type_);
	pus_setPacketType(packet, type);
}

uint pus_getSequenceFlags_(const pusPacket_t *packet)
{
	return (uint) pus_getSequenceFlags(packet);
}

void pus_setSequenceFlags_(pusPacket_t *packet, uint seqflags)
{
	pusSequenceFlags_t flags = static_cast<pusSequenceFlags_t>(seqflags);
	pus_setSequenceFlags(packet, flags);
}

uint pus_getTmPusVersion_(const pusPacket_t *packet)
{
	return (uint) pus_getTmPusVersion(packet);
}

void pus_setTmPusVersion_(pusPacket_t *packet, uint version)
{
	pusVersion_t vers = static_cast<pusVersion_t>(version);
	pus_setTmPusVersion(packet, vers);
}

uint pus_getTcPusVersion_(const pusPacket_t *packet)
{
	return (uint) pus_getTcPusVersion(packet);
}

void pus_setTcPusVersion_(pusPacket_t *packet, uint version)
{
	pusVersion_t vers = static_cast<pusVersion_t>(version);
	pus_setTcPusVersion(packet, vers);
}

time_t pus_getTmPacketTime_(const pusPacket_t *packet)
{
	pusTime_t time;
	pus_getTmPacketTime(&time, packet);
	return (time_t) time.tv_sec;
}

void pus_setTmPacketTime_(pusPacket_t *packet, time_t time_)
{
	pusTime_t time;
	struct timespec time_struct = {time_, 0};

	pus_posix2time(&time, &time_struct);
	pus_setTmPacketTime(packet, &time);
}


uint pus_tm_1_X_getPacketVersionNumber_(pusPacket_t *tm)
{
	return (uint) pus_tm_1_X_getPacketVersionNumber(tm);
}

void pus_tm_1_X_setPacketVersionNumber_(pusPacket_t *tm, uint version)
{
	pusPacketVersion_t vers = static_cast<pusPacketVersion_t>(version);
	pus_tm_1_X_setPacketVersionNumber(tm, vers);
}

uint pus_tm_1_X_getPacketType_(pusPacket_t* tm)
{
	return (uint) pus_tm_1_X_getPacketType(tm);
}

void pus_tm_1_X_setPacketType_(pusPacket_t* tm, uint type)
{
	pusPacketType_t typ = static_cast<pusPacketType_t>(type);
	pus_tm_1_X_setPacketType(tm, typ);
}

uint pus_tm_1_X_getSequenceFlags_(pusPacket_t* tm)
{
	return (uint) pus_tm_1_X_getSequenceFlags(tm);
}

void pus_tm_1_X_setSequenceFlags_(pusPacket_t* tm, uint seq_flags)
{
	pusSequenceFlags_t flags = static_cast<pusSequenceFlags_t>(seq_flags);
	pus_tm_1_X_setSequenceFlags(tm, flags);
}

ull pus_tm_1_X_getFailureCode_(const pusPacket_t *tm)
{
	return pus_tm_1_X_getFailureInfo(tm, NULL);
}

ll pus_getSt01FailureSubcode_(const pusPacket_t *tm)
{
	pusSt01FailureInfo_t failureInfo;
	pus_tm_1_X_getFailureInfo(tm, &failureInfo);
	return pus_getSt01FailureSubcode(&failureInfo);
}

ll pus_getSt01FailureData_(const pusPacket_t *tm)
{
	pusSt01FailureInfo_t failureInfo;
	pus_tm_1_X_getFailureInfo(tm, &failureInfo);
	return pus_getSt01FailureData(&failureInfo);
}

ull pus_getSt01FailureAddress_(const pusPacket_t *tm)
{
	pusSt01FailureInfo_t failureInfo;
	pus_tm_1_X_getFailureInfo(tm, &failureInfo);
	return pus_getSt01FailureAddress(&failureInfo);
}

void pus_setSt01FailureInfo_(pusPacket_t *tm, ull code, ll subcode, ll data, ull address)
{
	pusSt01FailureInfo_t failureInfo;
	pus_setSt01FailureInfo(&failureInfo, subcode, data, address);
	pus_tm_1_X_setFailureInfo(tm, code, &failureInfo);
}

pusError_t pus_hk_initialize_null_()
{
	return pus_hk_initialize(NULL);
}


st05Event pus_event_init_struct_(ull event_id, ull auxdata1, ull auxdata2)
{
	st05Event event;
	event.event_id = event_id;
	event.auxdata.data1 = auxdata1;
	event.auxdata.data2 = auxdata2;

	return event;
}

pusSt05Event_t parse_pusSt05EventStruct_(st05Event event)
{
	pusSt05Event_t pusEvent;
	pusSt05EventAuxData_t data;

	pus_events_setEventId(&pusEvent, event.event_id);
	pus_events_setEventAuxData1(&data, event.auxdata.data1);
	pus_events_setEventAuxData2(&data, event.auxdata.data2);
	pus_events_setEventAuxData(&pusEvent, data);

	return pusEvent;
}

pusError_t pus_tm_5_X_createEventReport_(pusPacket_t* outTm, pusApidInfo_t* apid, const st05Event* event, pusApid_t destination, pusSubservice_t subtype)
{
	pusSt05Event_t pusEvent = parse_pusSt05EventStruct_(*event);
	return pus_tm_5_X_createEventReport(outTm, apid, &pusEvent, destination, subtype);
}

pusError_t pus_tm_5_1_createInformativeEventReport_(pusPacket_t* outTm, pusApidInfo_t* apid, const st05Event* event, pusApid_t destination)
{
	pusSt05Event_t pusEvent = parse_pusSt05EventStruct_(*event);
	return pus_tm_5_1_createInformativeEventReport(outTm, apid, &pusEvent, destination);
}

pusError_t pus_tm_5_2_createLowSeverityEventReport_(pusPacket_t* outTm, pusApidInfo_t* apid, const st05Event* event, pusApid_t destination)
{
	pusSt05Event_t pusEvent = parse_pusSt05EventStruct_(*event);
	return pus_tm_5_2_createLowSeverityEventReport(outTm, apid, &pusEvent, destination);
}

pusError_t pus_tm_5_3_createMediumSeverityEventReport_(pusPacket_t* outTm, pusApidInfo_t* apid, const st05Event* event, pusApid_t destination)
{
	pusSt05Event_t pusEvent = parse_pusSt05EventStruct_(*event);
	return pus_tm_5_3_createMediumSeverityEventReport(outTm, apid, &pusEvent, destination);
}

pusError_t pus_tm_5_4_createHighSeverityEventReport_(pusPacket_t* outTm, pusApidInfo_t* apid, const st05Event* event, pusApid_t destination)
{
	pusSt05Event_t pusEvent = parse_pusSt05EventStruct_(*event);
	return pus_tm_5_4_createHighSeverityEventReport(outTm, apid, &pusEvent, destination);
}

pusError_t pus_tm_get_5_X_event_id_(const pusPacket_t *packet, ull *eventId)
{
	pusSt05Event_t event;
	pusError_t error = pus_tm_5_X_getTmEventReportData(packet, &event);
	if (pusError_t::PUS_NO_ERROR != error) return error;
	*eventId = pus_events_getEventId((const pusSt05Event_t *)&event);
	return pusError_t::PUS_NO_ERROR;
}

pusError_t pus_tm_get_5_X_event_auxdata1_(const pusPacket_t *packet, ull *auxdata1)
{

	pusSt05Event_t event;
	pusSt05EventAuxData_t auxdata;

	pusError_t error = pus_tm_5_X_getTmEventReportData(packet, &event);
	if (pusError_t::PUS_NO_ERROR != error) return error;
	auxdata =  pus_events_getEventAuxData((const pusSt05Event_t *)&event);
	*auxdata1 = pus_events_getEventAuxData1((const pusSt05EventAuxData_t *)&auxdata);

	return pusError_t::PUS_NO_ERROR;
}

pusError_t pus_tm_get_5_X_event_auxdata2_(const pusPacket_t *packet, ull *auxdata2)
{

	pusSt05Event_t event;
	pusSt05EventAuxData_t auxdata;

	pusError_t error = pus_tm_5_X_getTmEventReportData(packet, &event);
	if (pusError_t::PUS_NO_ERROR != error) return error;
	auxdata =  pus_events_getEventAuxData((const pusSt05Event_t *)&event);
	*auxdata2 = pus_events_getEventAuxData2((const pusSt05EventAuxData_t *)&auxdata);

	return pusError_t::PUS_NO_ERROR;
}

pusError_t pus_events_initialize_null_()
{
	return pus_events_initialize(NULL);
}
