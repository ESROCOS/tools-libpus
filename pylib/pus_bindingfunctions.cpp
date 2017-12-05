#include "pus_bindingfunctions.hpp"

pusError_t pus_initApidInfo_(pusApidInfo_t *obj, pusApid_t apid)
{
	return pus_initApidInfo(obj, apid, NULL);
}

uint pus_getPacketVersion_(const pusPacket_t *packet)
{
	return (uint) pus_getPacketVersion(packet);
}

uint pus_getPacketType_(const pusPacket_t *packet)
{
	return (uint) pus_getPacketType(packet);
}

uint pus_getSequenceFlags_(const pusPacket_t *packet)
{
	return (uint) pus_getSequenceFlags(packet);
}

uint pus_getTmPusVersion_(const pusPacket_t *packet)
{
	return (uint) pus_getTmPusVersion(packet);
}

uint pus_getTcPusVersion_(const pusPacket_t *packet)
{
	return (uint) pus_getTcPusVersion(packet);
}

time_t pus_getTmPacketTime_(const pusPacket_t *packet)
{
	pusTime_t time;
	pus_getTmPacketTime(&time, packet);
	return (time_t) time.tv_sec;
}

uint pus_tm_1_X_getPacketVersionNumber_(pusPacket_t *tm)
{
	return (uint) pus_tm_1_X_getPacketVersionNumber(tm);
}

uint pus_tm_1_X_getPacketType_(pusPacket_t* tm)
{
	return (uint) pus_tm_1_X_getPacketType(tm);
}

uint pus_tm_1_X_getSequenceFlags_(pusPacket_t* tm)
{
	return (uint) pus_tm_1_X_getSequenceFlags(tm);
}

ll pus_tm_1_X_getFailureCode_(const pusPacket_t *tm)
{
	return pus_tm_1_X_getFailureInfo(tm, NULL);
}

ll pus_getSt01FailureSubcode_(const pusPacket_t *tm)
{
	const pusSt01FailureInfo_t failureInfo = tm->data.u.tmData.data.u.st_1_X.failure.info;
	return pus_getSt01FailureSubcode(&failureInfo);
}

ll pus_getSt01FailureData_(const pusPacket_t *tm)
{
	const pusSt01FailureInfo_t failureInfo = tm->data.u.tmData.data.u.st_1_X.failure.info;
	return pus_getSt01FailureData(&failureInfo);
}

ull pus_getSt01FailureAddress_(const pusPacket_t *tm)
{
	const pusSt01FailureInfo_t failureInfo = tm->data.u.tmData.data.u.st_1_X.failure.info;
	return pus_getSt01FailureAddress(&failureInfo);
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
