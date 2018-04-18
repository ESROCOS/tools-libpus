/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pus_bindingfunctions.hpp"

time_t pus_time2posix_(pusTime_t* time) {
	struct timespec t;
	pus_time2posix(&t, time);
	return t.tv_sec;
}

pusTime_t pus_posix2time_(time_t time) {
	struct timespec t;
	pusTime_t pusTime;
	t.tv_sec = time;
	pus_posix2time(&pusTime, &t);
	return pusTime;
}

pusError_t pus_initApidInfo_null(pusApidInfo_t *obj, pusApid_t apid)
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

pusStoredParam_t pus_tm_3_25_getParameterValue_(const pusPacket_t* tm, size_t index)
{
	pusStoredParam_t v;
	pus_tm_3_25_getParameterValue(tm, index, &v);
	return v;
}

size_t pus_tm_3_25_getNumParameters_(const pusPacket_t* tm)
{
	size_t n_p;
	pus_tm_3_25_getNumParameters(tm, &n_p);
	return n_p;
}

char *pus_st03_getHkReportInfoName(pusSt03HousekeepingReportId_t reportId, pusSt03ParamId_t reportIndex) {
	if (reportIndex < pus_ST03_PARAM_LIMIT) {
		 return strdup(pus_st03_paramInfo[pus_st03_defaultHkReportInfo.paramIds[reportIndex]].label);
	}
	return NULL;
}

pusParamType_t pus_st03_getHkReportInfoType(pusSt03HousekeepingReportId_t reportId, pusSt03ParamId_t reportIndex) {
	if (reportIndex < pus_ST03_PARAM_LIMIT) {
		PUS_SET_ERROR(pusError_t::PUS_NO_ERROR);
		return pus_st03_paramInfo[pus_st03_defaultHkReportInfo.paramIds[reportIndex]].type;
	}
	PUS_SET_ERROR(pusError_t::PUS_ERROR_LIMIT);
	return pusParamType_t::PUS_BOOL;
}

uint32_t pus_paramToUint32_(pusStoredParam_t paramValue) {
	uint32_t outValue = 0;
	pusError_t error;
	error = pus_paramToUint32(&outValue, paramValue);
	PUS_SET_ERROR(error);
	return outValue;
}

int32_t pus_paramToInt32_(pusStoredParam_t paramValue) {
	int32_t outValue = 0;
	pusError_t error;
	error = pus_paramToInt32(&outValue, paramValue);
	PUS_SET_ERROR(error);
	return outValue;
}

double pus_paramToReal64_(pusStoredParam_t paramValue) {
	double outValue = 0;
	pusError_t error;
	error = pus_paramToReal64(&outValue, paramValue);
	PUS_SET_ERROR(error);
	return outValue;
}


bool pus_paramToBool_(pusStoredParam_t paramValue) {
	bool outValue = false;
	pusError_t error;
	error = pus_paramToBool(&outValue, paramValue);
	PUS_SET_ERROR(error);
	return outValue;
}


std::string pus_paramToByte_(pusStoredParam_t paramValue) {
	uint8_t outValue = 0;
	std::string byte;
	char byteAux[4];
	pusError_t error;
	error = pus_paramToByte(&outValue, paramValue);
	sprintf(byteAux, "%x", outValue);
	byte = std::string(byteAux);
	PUS_SET_ERROR(error);
	return byte;
}

pusStoredParam_t pus_uint32ToParam_(uint32_t inValue) {
	pusError_t error;
	pusStoredParam_t param;
	error = pus_uint32ToParam(&param, inValue);
	PUS_SET_ERROR(error);
	return param;
}

pusStoredParam_t pus_int32ToParam_(int32_t inValue) {
	pusError_t error;
	pusStoredParam_t param;
	error = pus_int32ToParam(&param, inValue);
	PUS_SET_ERROR(error);
	return param;
}

pusStoredParam_t pus_real64ToParam_(double inValue) {
	pusError_t error;
	pusStoredParam_t param;
	error = pus_real64ToParam(&param, inValue);
	PUS_SET_ERROR(error);
	return param;
}

pusStoredParam_t pus_boolToParam_(bool inValue) {
	pusError_t error;
	pusStoredParam_t param;
	error = pus_boolToParam(&param, inValue);
	PUS_SET_ERROR(error);
	return param;
}

pusStoredParam_t pus_byteToParam_(uint8_t inValue) {
	pusError_t error;
	pusStoredParam_t param;
	error = pus_boolToParam(&param, inValue);
	PUS_SET_ERROR(error);
	return param;
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

pusError_t pus_tm_5_X_createEventReport_(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const st05Event* event, pusApid_t destination, pusSubservice_t subtype)
{
	pusSt05Event_t pusEvent = parse_pusSt05EventStruct_(*event);
	return pus_tm_5_X_createEventReport(outTm, apid, sequenceCount, &pusEvent, destination, subtype);
}

pusError_t pus_tm_5_1_createInformativeEventReport_(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const st05Event* event, pusApid_t destination)
{
	pusSt05Event_t pusEvent = parse_pusSt05EventStruct_(*event);
	return pus_tm_5_1_createInformativeEventReport(outTm, apid, sequenceCount, &pusEvent, destination);
}

pusError_t pus_tm_5_2_createLowSeverityEventReport_(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const st05Event* event, pusApid_t destination)
{
	pusSt05Event_t pusEvent = parse_pusSt05EventStruct_(*event);
	return pus_tm_5_2_createLowSeverityEventReport(outTm, apid, sequenceCount, &pusEvent, destination);
}

pusError_t pus_tm_5_3_createMediumSeverityEventReport_(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const st05Event* event, pusApid_t destination)
{
	pusSt05Event_t pusEvent = parse_pusSt05EventStruct_(*event);
	return pus_tm_5_3_createMediumSeverityEventReport(outTm, apid, sequenceCount, &pusEvent, destination);
}

pusError_t pus_tm_5_4_createHighSeverityEventReport_(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const st05Event* event, pusApid_t destination)
{
	pusSt05Event_t pusEvent = parse_pusSt05EventStruct_(*event);
	return pus_tm_5_4_createHighSeverityEventReport(outTm, apid, sequenceCount, &pusEvent, destination);
}

ull pus_tm_get_5_X_event_id_(const pusPacket_t *packet)
{
	pusSt05Event_t event;
	pus_tm_5_X_getTmEventReportData(packet, &event);
	return pus_events_getEventId((const pusSt05Event_t *)&event);
}

ull pus_tm_get_5_X_event_auxdata1_(const pusPacket_t *packet)
{

	pusSt05Event_t event;
	pusSt05EventAuxData_t auxdata;

	pus_tm_5_X_getTmEventReportData(packet, &event);
	auxdata =  pus_events_getEventAuxData((const pusSt05Event_t *)&event);
	return pus_events_getEventAuxData1((const pusSt05EventAuxData_t *)&auxdata);
}

ull pus_tm_get_5_X_event_auxdata2_(const pusPacket_t *packet)
{

	pusSt05Event_t event;
	pusSt05EventAuxData_t auxdata;

	pus_tm_5_X_getTmEventReportData(packet, &event);
	auxdata =  pus_events_getEventAuxData((const pusSt05Event_t *)&event);
	return pus_events_getEventAuxData2((const pusSt05EventAuxData_t *)&auxdata);
}

char *pus_st05_getEventName(pusSt05EventId_t eventIndex)
{
	if (eventIndex < PUS_ST05_EVENT_BUFFER_LIMIT)
	{
		PUS_SET_ERROR(pusError_t::PUS_NO_ERROR);
		return strdup(pus_st05_eventInfoList[eventIndex].label);
	}
	PUS_SET_ERROR(pusError_t::PUS_ERROR_LIMIT);
	return 	NULL;
}

pusSt05EventId_t pus_st05_getEventId(char *eventName)
{
	pusSt05EventId_t i;
	PUS_SET_ERROR(pusError_t::PUS_NO_ERROR);

	if (eventName == NULL)
	{
		PUS_SET_ERROR(pusError_t::PUS_ERROR_NULLPTR);
		return -1;
	}

	for (i = 0; i < PUS_ST05_EVENT_BUFFER_LIMIT; i++)
		if (strcmp(pus_st05_eventInfoList[i].label, eventName)==0)
			return i;

	PUS_SET_ERROR(pusError_t::PUS_ERROR_DEFINITION_NOT_FOUND);
	return -1;
}

int pus_st05_getDataType1(pusSt05EventId_t eventIndex)
{
	if (eventIndex < PUS_ST05_EVENT_BUFFER_LIMIT)
	{
		PUS_SET_ERROR(pusError_t::PUS_NO_ERROR);
		return pus_st05_eventInfoList[eventIndex].data.dataType1;
	}
	PUS_SET_ERROR(pusError_t::PUS_ERROR_LIMIT);
	return -1;
}

int pus_st05_getDataType2(pusSt05EventId_t eventIndex)
{
	if (eventIndex < PUS_ST05_EVENT_BUFFER_LIMIT)
	{
		PUS_SET_ERROR(pusError_t::PUS_NO_ERROR);
		return pus_st05_eventInfoList[eventIndex].data.dataType2;
	}
	PUS_SET_ERROR(pusError_t::PUS_ERROR_LIMIT);
	return -1;
}

pusSt08FunctiontId_t pus_tc_8_1_getFunctionId_(pusPacket_t *packet)
{
	pusSt08FunctiontId_t functionId;
	pus_tc_8_1_getFunctionId(&functionId, packet);
	return functionId;
}

pusSt09ExponentialRate_t pus_tc_9_1_getExponentialRate_(pusPacket_t* tcPacket)
{
	pusSt09ExponentialRate_t tExp;
	pusError_t error = pus_tc_9_1_getExponentialRate(&tExp, tcPacket);
	PUS_SET_ERROR(error);
	return tExp;
}

pusSt09ExponentialRate_t pus_tm_9_2_getDataField_(const pusPacket_t* tm, pusTime_t* time) {
	pusSt09ExponentialRate_t rate;
	pus_tm_9_2_getDataField(tm, time, &rate);
	return rate;
}

void pus_tc_11_4_get_request(long index, const pusPacket_t* inTc, pusPacket_t *outTc, long max)
{
	pusSt11ScheduledActivity_t activities[10];
	pusPacketReduced_t pack;
	int32_t nCount;
	pus_tc_11_4_getActivities(&nCount, activities, inTc, max);
	pack = activities[index].packetReduced;
	pus_packetReduced_createPacketFromPacketReduced(outTc, &pack);
}

time_t pus_tc_11_4_get_release_time(long index, const pusPacket_t* inTc, long max)
{
	pusSt11ScheduledActivity_t activities[10];
	pusTime_t time_;
	struct timespec time_struct;
	int32_t nCount;
	pus_tc_11_4_getActivities(&nCount, activities, inTc, max);
	time_ = activities[index].time;
	pus_time2posix(&time_struct, &time_);
	return time_struct.tv_sec;
}

pusSt12PmonId_t  pus_tc_12_1_2_getPmonId_(pusPacket_t* tcPacket)
{
	pusSt12PmonId_t pmon;
	pusError_t error = pus_tc_12_1_2_getPmonId(&pmon, tcPacket);
	PUS_SET_ERROR(error);
	return pmon;
}

pusError_t pus_tc_18_1_createLoadObcpDirectRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const char* obcpId, const std::vector<uint8_t> code, const size_t codelength) {
	pusSt18ObcpId_t id;
	pusSt18ObcpCode_t obcpCode;
	size_t len = (strlen(obcpId) < pus_ST18_SIZE_OBCP_ID) ? strlen(obcpId)+1 : pus_ST18_SIZE_OBCP_ID;
	memcpy(id.arr, obcpId, len);
	len = (codelength < pus_ST18_MAX_SIZE_OBCP_CODE) ? codelength : pus_ST18_MAX_SIZE_OBCP_CODE;
	memcpy(obcpCode.arr, (uint8_t *)&code[0], len);
	obcpCode.nCount = len;

	return pus_tc_18_1_createLoadObcpDirectRequest(outTc, apid, sequenceCount, &id, &obcpCode);
}


pusError_t pus_tc_18_2_createUnloadObcpRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const char* id) {
	pusSt18ObcpId_t obcpId;
	size_t len = (strlen(id) < pus_ST18_SIZE_OBCP_ID) ? strlen(id)+1 : pus_ST18_SIZE_OBCP_ID;
	memcpy(obcpId.arr, id, len);

	return pus_tc_18_2_createUnloadObcpRequest(outTc, apid, sequenceCount, &obcpId);
}

pusError_t pus_tc_18_3_createActivateObcpRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const char *id, int observability) {
	pusSt18ObcpId_t obcpId;
	size_t len = (strlen(id) < pus_ST18_SIZE_OBCP_ID) ? strlen(id)+1 : pus_ST18_SIZE_OBCP_ID;
	memcpy(obcpId.arr, id, len);

	return pus_tc_18_3_createActivateObcpRequest(outTc, apid, sequenceCount, &obcpId, (pusSt18ObservabilityLevel_t) observability);
}

pusError_t pus_tc_18_4_createStopObcpRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const char* id, pusSt18ObcpStepId_t step) {
	pusSt18ObcpId_t obcpId;
	size_t len = (strlen(id) < pus_ST18_SIZE_OBCP_ID) ? strlen(id)+1 : pus_ST18_SIZE_OBCP_ID;
	memcpy(obcpId.arr, id, len);
	return pus_tc_18_4_createStopObcpRequest(outTc, apid, sequenceCount, &obcpId, step);
}

pusError_t pus_tc_18_5_createSuspendObcpRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const char* id, pusSt18ObcpStepId_t step) {
	pusSt18ObcpId_t obcpId;
	size_t len = (strlen(id) < pus_ST18_SIZE_OBCP_ID) ? strlen(id)+1 : pus_ST18_SIZE_OBCP_ID;
	memcpy(obcpId.arr, id, len);
	return pus_tc_18_5_createSuspendObcpRequest(outTc, apid, sequenceCount, &obcpId, step);
}

pusError_t pus_tc_18_6_createResumeObcpRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const char* id) {
	pusSt18ObcpId_t obcpId;
	size_t len = (strlen(id) < pus_ST18_SIZE_OBCP_ID) ? strlen(id)+1 : pus_ST18_SIZE_OBCP_ID;
	memcpy(obcpId.arr, id, len);

	return pus_tc_18_6_createResumeObcpRequest(outTc, apid, sequenceCount, &obcpId);
}

pusError_t pus_tc_18_12_createAbortObcpRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const char* id) {
	pusSt18ObcpId_t obcpId;
	memcpy(obcpId.arr, id, strlen(id)+1);

	return pus_tc_18_12_createAbortObcpRequest(outTc, apid, sequenceCount, &obcpId);
}

pusError_t pus_tc_18_13_createLoadObcpReferenceRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const char* id, const char* repository, const char* fileName) {
	pusSt18ObcpId_t obcpId;
	pusSt23RepositoryPath_t repo;
	pusSt23FileName_t fName;
	size_t len;
	len = (strlen(id) < pus_ST18_SIZE_OBCP_ID) ? strlen(id)+1 : pus_ST18_SIZE_OBCP_ID;
	memcpy(obcpId.arr, id, len);
	len = (strlen(repository) < pus_ST23_MAX_SIZE_REPOSITORY_PATH) ? strlen(repository) +1 : pus_ST23_MAX_SIZE_REPOSITORY_PATH;
	memcpy(repo.arr, repository, len);
	repo.nCount = len-1;
	len = (strlen(fileName) < pus_ST23_MAX_SIZE_FILE_PATH) ? strlen(fileName)+1 : pus_ST23_MAX_SIZE_FILE_PATH;
	memcpy(fName.arr, fileName, len);
	fName.nCount = len-1;

	return pus_tc_18_13_createLoadObcpReferenceRequest(outTc, apid, sequenceCount, &obcpId, &repo, &fName);
}

pusError_t pus_tc_18_X_setObcpId_(pusPacket_t* outTc, const char *obcpId) {
	pusSt18ObcpId_t id;
	size_t len = (strlen(obcpId) < pus_ST18_SIZE_OBCP_ID) ? strlen(obcpId)+1 : pus_ST18_SIZE_OBCP_ID;
	memcpy(id.arr, obcpId, len);
	return pus_tc_18_X_setObcpId(outTc, &id);
}

char *pus_tc_18_X_getObcpId_(char* id, const pusPacket_t* outTc) {
	pusError_t error;
	pusSt18ObcpId_t obcpId;

	error = pus_tc_18_X_getObcpId(&obcpId, outTc);
	if (pusError_t::PUS_NO_ERROR == error) {
		id = strdup((char *) obcpId.arr);
		return id;
	}

	PUS_SET_ERROR(error);
	return NULL;
}

pusError_t pus_tc_18_1_setObcpCode_(pusPacket_t* outTc, const std::vector<uint8_t> code, const size_t codelength) {
	pusSt18ObcpCode_t obcpCode;
	size_t len = (codelength < pus_ST18_MAX_SIZE_OBCP_CODE) ? codelength : pus_ST18_MAX_SIZE_OBCP_CODE;
	memcpy(obcpCode.arr, (uint8_t *)&code[0], len);
	obcpCode.nCount = len;
	return pus_tc_18_1_setObcpCode(outTc, &obcpCode);
}

std::vector<uint8_t> pus_tc_18_1_getObcpCode_(char* code, const pusPacket_t* outTc) {
	pusSt18ObcpCode_t obcpCode;
	pusError_t error;
	std::vector<uint8_t> code_;
	error = pus_tc_18_1_getObcpCode(&obcpCode, outTc);
	if (pusError_t::PUS_NO_ERROR == error) {
		code_ = std::vector<uint8_t>(obcpCode.arr, obcpCode.arr+obcpCode.nCount);
		return code_;
	}

	PUS_SET_ERROR(error);
	return std::vector<uint8_t>();
}

pusError_t pus_tc_18_3_setObservabilityLevel_(pusPacket_t* outTc, int observability) {
	pusSt18ObservabilityLevel_t obs = (pusSt18ObservabilityLevel_t) observability;
	return pus_tc_18_3_setObservabilityLevel(outTc, obs);
}

int pus_tc_18_3_getObservabilityLevel_(const pusPacket_t* outTc) {
	pusSt18ObservabilityLevel_t obs;
	pusError_t error;
	error = pus_tc_18_3_getObservabilityLevel(&obs, outTc);
	if (pusError_t::PUS_NO_ERROR ==  error)
		return (int) obs;
	PUS_SET_ERROR(error);
	return 0;
}

pusSt18ObcpStepId_t pus_tc_18_4_5_getObcpStepId_(const pusPacket_t* outTc) {
	pusSt18ObcpStepId_t obcpStep;
	pusError_t error;

	error = pus_tc_18_4_5_getObcpStepId(&obcpStep, outTc);
	if (pusError_t::PUS_NO_ERROR == error)
		return obcpStep;
	PUS_SET_ERROR(error);
	return 0;
}

pusError_t pus_tc_18_13_setFileName_(pusPacket_t* outTc, const char* fileName) {
	pusSt23FileName_t fName;
	size_t len = (strlen(fileName) < pus_ST23_MAX_SIZE_FILE_PATH) ? strlen(fileName)+1 : pus_ST23_MAX_SIZE_FILE_PATH;
	memcpy(fName.arr, fileName, len);
	fName.nCount = len-1;
	return pus_tc_18_13_setFileName(outTc, &fName);
}

char *pus_tc_18_13_getFileName_(char* fileName, const pusPacket_t* outTc) {
	pusError_t error;
	pusSt23FileName_t fName;

	error = pus_tc_18_13_getFileName(&fName, outTc);
	if (pusError_t::PUS_NO_ERROR == error) {
		fileName = strdup((char *) fName.arr);
		return fileName;
	}
	PUS_SET_ERROR(error);
	return NULL;
}

pusError_t pus_tc_18_13_setRepositoryPath_(pusPacket_t* outTc, const char* repository) {
	pusSt23RepositoryPath_t repo;
	size_t len = (strlen(repository) < pus_ST23_MAX_SIZE_REPOSITORY_PATH) ? strlen(repository) +1 : pus_ST23_MAX_SIZE_REPOSITORY_PATH;
	memcpy(repo.arr, repository, len);
	repo.nCount = len-1;
	return pus_tc_18_13_setRepositoryPath(outTc, &repo);
}

char *pus_tc_18_13_getRepositoryPath_(char* repository, const pusPacket_t* outTc) {
	pusError_t error;
	pusSt23RepositoryPath_t repo;

	error = pus_tc_18_13_getRepositoryPath(&repo, outTc);
	if (pusError_t::PUS_NO_ERROR == error) {
		repository = strdup((char *) repo.arr);
		return repository;
	}
	PUS_SET_ERROR(error);
	return NULL;
}

pusSt05EventId_t pus_tc_19_X_getEventId_(const pusPacket_t* outTc) {
	pusSt05EventId_t eventId = 0;
	pusError_t error = pusError_t::PUS_NO_ERROR;
	error = pus_tc_19_X_getEventId(&eventId, outTc);
	if (error != pusError_t::PUS_NO_ERROR) {
		PUS_SET_ERROR(error);
		return -1;
	}
	return eventId;
}

char *pus_st20_getOnBoardReportInfoName(pusSt20OnBoardParamId_t paramId) {
	if (paramId < pus_ST20_PARAM_LIMIT) {
		 return strdup(pus_st20_paramInfo[paramId].label);
	}
	return NULL;
}

pusParamType_t pus_st20_getOnBoardReportInfoType(pusSt20OnBoardParamId_t paramId) {
	if (paramId < pus_ST20_PARAM_LIMIT) {
		return pus_st20_paramInfo[paramId].type;
	}
	PUS_SET_ERROR(pusError_t::PUS_ERROR_LIMIT);
	return pusParamType_t::PUS_BOOL;
}



pusError_t pus_tc_23_1_createCreateFileRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const char* repository, const char* fileName, pusSt23MaximumSize_t maxSize) {
	pusSt23FileName_t file;
	pusSt23RepositoryPath_t repo;
	size_t len;

	len = (strlen(fileName) < pus_ST23_MAX_SIZE_FILE_PATH) ? strlen(fileName)+1 : pus_ST23_MAX_SIZE_FILE_PATH;
	memcpy(file.arr, fileName, len);
	file.nCount = len -1;

	len = (strlen(repository) < pus_ST23_MAX_SIZE_REPOSITORY_PATH) ? strlen(repository) +1 : pus_ST23_MAX_SIZE_REPOSITORY_PATH;
	memcpy(repo.arr, repository, len);
	repo.nCount = len -1;

	return pus_tc_23_1_createCreateFileRequest(outTc, apid, sequenceCount, &repo, &file, maxSize);
}

pusError_t pus_tc_23_2_createDeleteFileRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const char* repository, const char* fileName) {
	pusSt23FileName_t file;
	pusSt23RepositoryPath_t repo;
	size_t len;

	len = (strlen(fileName) < pus_ST23_MAX_SIZE_FILE_PATH) ? strlen(fileName)+1 : pus_ST23_MAX_SIZE_FILE_PATH;
	memcpy(file.arr, fileName, len);
	file.nCount = len -1;

	len = (strlen(repository) < pus_ST23_MAX_SIZE_REPOSITORY_PATH) ? strlen(repository) +1 : pus_ST23_MAX_SIZE_REPOSITORY_PATH;
	memcpy(repo.arr, repository, len);
	repo.nCount = len -1;

	return pus_tc_23_2_createDeleteFileRequest(outTc, apid, sequenceCount, &repo, &file);
}

pusError_t pus_tc_23_3_createReportFileAtributesRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const char* repository, const char* fileName) {
	pusSt23FileName_t file;
	pusSt23RepositoryPath_t repo;
	size_t len;

	len = (strlen(fileName) < pus_ST23_MAX_SIZE_FILE_PATH) ? strlen(fileName)+1 : pus_ST23_MAX_SIZE_FILE_PATH;
	memcpy(file.arr, fileName, len);
	file.nCount = len -1;

	len = (strlen(repository) < pus_ST23_MAX_SIZE_REPOSITORY_PATH) ? strlen(repository) +1 : pus_ST23_MAX_SIZE_REPOSITORY_PATH;
	memcpy(repo.arr, repository, len);
	repo.nCount = len -1;

	return pus_tc_23_3_createReportFileAtributesRequest(outTc, apid, sequenceCount, &repo, &file);
}

pusError_t pus_tc_23_14_createCopyFileRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const char* sourceRepository, const char* sourceFileName, const char* targetRepository, const char* targetFileName) {

	pusSt23FileName_t srcFile, dstFile;
	pusSt23RepositoryPath_t srcRepo, dstRepo;
	size_t len;
	if (NULL == sourceRepository || NULL == sourceFileName || NULL == targetFileName || NULL == targetRepository)
		return pusError_t::PUS_ERROR_NULLPTR;

	len = (strlen(sourceFileName) < pus_ST23_MAX_SIZE_FILE_PATH) ? strlen(sourceFileName)+1 : pus_ST23_MAX_SIZE_FILE_PATH;
	memcpy(srcFile.arr, sourceFileName, len);
	srcFile.nCount = len -1;

	len = (strlen(sourceRepository) < pus_ST23_MAX_SIZE_REPOSITORY_PATH) ? strlen(sourceRepository) +1 : pus_ST23_MAX_SIZE_REPOSITORY_PATH;
	memcpy(srcRepo.arr, sourceRepository, pus_ST23_MAX_SIZE_REPOSITORY_PATH - 1);
	srcRepo.nCount = len -1;

	len = (strlen(targetFileName) < pus_ST23_MAX_SIZE_FILE_PATH) ? strlen(targetFileName)+1 : pus_ST23_MAX_SIZE_FILE_PATH;
	memcpy(dstFile.arr, targetFileName, len);
	dstFile.nCount = len -1;

	len = (strlen(targetRepository) < pus_ST23_MAX_SIZE_REPOSITORY_PATH) ? strlen(targetRepository) +1 : pus_ST23_MAX_SIZE_REPOSITORY_PATH;
	memcpy(dstRepo.arr, targetRepository, pus_ST23_MAX_SIZE_REPOSITORY_PATH - 1);
	dstRepo.nCount = len -1;

	return pus_tc_23_14_createCopyFileRequest(outTc, apid, sequenceCount, &srcRepo, &srcFile, &dstRepo, &dstFile);
}

pusError_t pus_tc_tm_23_X_setFileName_(pusPacket_t* outTc, const char* file) {
	pusSt23FileName_t fileName;
	size_t len = (strlen(file) < pus_ST23_MAX_SIZE_FILE_PATH) ? strlen(file)+1 : pus_ST23_MAX_SIZE_FILE_PATH;
	memcpy(fileName.arr, file, len);
	fileName.nCount = len -1;

	return pus_tc_tm_23_X_setFileName(outTc, &fileName);
}

char *pus_tc_tm_23_X_getFileName_(char *file, const pusPacket_t* outTc) {
	pusSt23FileName_t fileName;
	if (NULL == file) {
		return NULL;
	}
	pus_tc_tm_23_X_getFileName(&fileName, outTc);
	strcpy(file, (char *)fileName.arr);
	return file;
}

pusError_t pus_tc_tm_23_X_setRepositoryPath_(pusPacket_t* outTc, const char* repository) {
	pusSt23RepositoryPath_t repo;
	size_t len = (strlen(repository) < pus_ST23_MAX_SIZE_REPOSITORY_PATH) ? strlen(repository) +1 : pus_ST23_MAX_SIZE_REPOSITORY_PATH;
	memcpy(repo.arr, repository, len);
	repo.nCount = len -1;

	return pus_tc_tm_23_X_setRepositoryPath(outTc, &repo);
}

char *pus_tc_tm_23_X_getRepositoryPath_(char *repository, const pusPacket_t* outTc) {
	pusSt23RepositoryPath_t repo;
	if (NULL == repository) {
		return NULL;
	}
	pus_tc_tm_23_X_getRepositoryPath(&repo, outTc);
	strcpy(repository, (char *)repo.arr);
	return repository;
}

pusSt23MaximumSize_t pus_tc_tm_23_1_4_getMaximumSize_(const pusPacket_t* outTc) {
	pusSt23MaximumSize_t max;

	PUS_SET_ERROR(pus_tc_tm_23_1_4_getMaximumSize(&max, outTc));
	return max;
}

//! Setter for the source file name of a TC[23,14] packet
pusError_t pus_tc_23_14_setSourceFileName_(pusPacket_t* outTc, const char* file) {
	pusSt23FileName_t fileName;
	size_t len = (strlen(file) < pus_ST23_MAX_SIZE_FILE_PATH) ? strlen(file)+1 : pus_ST23_MAX_SIZE_FILE_PATH;
	memcpy(fileName.arr, file, len);
	fileName.nCount = len -1;

	return pus_tc_23_14_setSourceFileName(outTc, &fileName);
}

//! Getter for the source file name of a TC[23,14] packet
char *pus_tc_23_14_getSourceFileName_(const pusPacket_t* outTc) {
	pusSt23FileName_t fileName;
	char *srcFile;

	if (pusError_t::PUS_NO_ERROR == pus_tc_23_14_getSourceFileName(&fileName, outTc)) {
		srcFile = strdup((char *)fileName.arr);
		return srcFile;
	}
	return NULL;
}

//! Setter for the target file name of a TC[23,14] packet
pusError_t pus_tc_23_14_setTargetFileName_(pusPacket_t* outTc, const char* file) {
	pusSt23FileName_t fileName;
	size_t len = (strlen(file) < pus_ST23_MAX_SIZE_FILE_PATH) ? strlen(file) +1 : pus_ST23_MAX_SIZE_FILE_PATH;
	memcpy(fileName.arr, file, len);
	fileName.nCount = len -1;

	return pus_tc_tm_23_X_setFileName(outTc, &fileName);
}

//! Getter for the target file name of a TC[23,14] packet
char *pus_tc_23_14_getTargetFileName_(const pusPacket_t* outTc) {
	pusSt23FileName_t fileName;
	char *dstFile;

	if (pusError_t::PUS_NO_ERROR == pus_tc_23_14_getTargetFileName(&fileName, outTc)) {
		dstFile = strdup((char *)fileName.arr);
		return dstFile;
	}
	return NULL;
}

//! Setter for the source repository path of a TC[23,14] packet
pusError_t pus_tc_23_14_setSourceRepositoryPath_(pusPacket_t* outTc, const char* repository) {
	pusSt23RepositoryPath_t repo;
	size_t len = (strlen(repository) < pus_ST23_MAX_SIZE_REPOSITORY_PATH) ? strlen(repository) +1 : pus_ST23_MAX_SIZE_REPOSITORY_PATH;
	memcpy(repo.arr, repository, len);
	repo.nCount = len -1;

	return pus_tc_23_14_setSourceRepositoryPath(outTc, &repo);
}

//! Getter for the source repository path of a TC[23,14] packet
char *pus_tc_23_14_getSourceRepositoryPath_(const pusPacket_t* outTc) {
	pusSt23RepositoryPath_t repoName;
	char *srcRepo;

	if (pusError_t::PUS_NO_ERROR == pus_tc_23_14_getSourceRepositoryPath(&repoName, outTc)) {
		srcRepo = strdup((char *)repoName.arr);
		return srcRepo;
	}
	return NULL;
}

//! Setter for the target repository path of a TC[23,14] packet
pusError_t pus_tc_23_14_setTargetRepositoryPath_(pusPacket_t* outTc, const char* repository) {
	pusSt23RepositoryPath_t repo;
	size_t len = (strlen(repository) < pus_ST23_MAX_SIZE_REPOSITORY_PATH) ? strlen(repository) +1 : pus_ST23_MAX_SIZE_REPOSITORY_PATH;
	memcpy(repo.arr, repository, len);
	repo.nCount = len -1;

	return pus_tc_23_14_setTargetRepositoryPath(outTc, &repo);
}

//! Getter for the target repository path of a TC[23,14] packet
char *pus_tc_23_14_getTargetRepositoryPath_(const pusPacket_t* outTc) {
	pusSt23RepositoryPath_t repoName;
	char *dstRepo;

	if (pusError_t::PUS_NO_ERROR == pus_tc_23_14_getTargetRepositoryPath(&repoName, outTc)) {
		dstRepo = strdup((char *)repoName.arr);
		return dstRepo;
	}
	return NULL;
}


