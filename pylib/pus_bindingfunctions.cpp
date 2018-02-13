/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pus_bindingfunctions.hpp"

int ret_packets(pusPacket_t *tm, int i)
{
	pusPacket_t tc;
	//pusTime_t tv, now;
	pusApidInfo_t apid;

	pus_initApidInfo(&apid, 33, NULL);

	// Test TC
	pus_initTcPacket(&tc);
	pus_setTcSource(&tc, 11);
	pus_setSequenceCount(&tc, 22);

	// Test failures
	pusSt01FailureInfo_t info1/*, info2*/;
	pus_setSt01FailureInfo(&info1, 101, 102, 103);

	// TM[1,1]
	if (i==0) pus_tm_1_1_createAcceptanceReportSuccess(tm, apid.apid, i, &tc);


	// TM[1,2]
	else if (i==1) pus_tm_1_2_createAcceptanceReportFailure(tm, apid.apid, i, &tc, pus_ST01_ERROR_SERVICE_UNAVAILABLE, &info1);


	// TM[1,3]
	else if (i==2) pus_tm_1_3_createStartReportSuccess(tm, apid.apid, i, &tc);

	// TM[1,4]
	else if (i==3) pus_tm_1_4_createStartReportFailure(tm, apid.apid, i, &tc, pus_ST01_ERROR_WRONG_FORMAT, NULL);


	// TM[1,5]
	else if (i==4) pus_tm_1_5_createProgressReportSuccess(tm, apid.apid, i, &tc, 71);

	// TM[1,6]
	else if (i==5) pus_tm_1_6_createProgressReportFailure(tm, apid.apid, i, &tc, 72, pus_ST01_ERROR_SUBTYPE_UNAVAILABLE, NULL);


	// TM[1,7]
	else if (i==6) pus_tm_1_7_createCompletionReportSuccess(tm, apid.apid, i, &tc);


	// TM[1,8]
	else if (i==7) pus_tm_1_8_createCompletionReportFailure(tm, apid.apid, i, &tc, pus_ST01_ERROR_WRONG_FORMAT, NULL);

	else if (i==8)
	{
		pus_hk_initialize(NULL);
		pus_tm_3_25_createHousekeepingReportDefault(tm, apid.apid, i, 55);
		pus_tm_3_25_setNumParameters(tm, 3);
		pus_tm_3_25_setParameterValue(tm, 0, 1);
		pus_tm_3_25_setParameterValue(tm, 1, 2);
		pus_tm_3_25_setParameterValue(tm, 2, 3);
		pus_hk_finalize();
	}
	else if (i == 9)
	{
		pus_tc_11_1_createEnableTimeBasedSchedule(tm, apid.apid, i);
	}
	else if (i == 10)
	{
		pusSt05Event_t event = parse_pusSt05EventStruct_(pus_event_init_struct_(1, 2, 3));
		pus_events_initialize(NULL);
		pus_tm_5_1_createInformativeEventReport(tm, apid.apid, i, &event, 1);
		pus_events_finalize();
	}
	else if (i == 11)
	{
		pus_tm_20_2_createParameterValueReport(tm, apid.apid, i, apid.apid, 1, 2);
	}
	else if (i == 12)
	{
		pusSt23RepositoryPath_t repo;
		pusSt23FileName_t file;
		pusSt23MaximumSize_t size;
		memcpy(repo.arr, "987654321\0", 10);
		memcpy(file.arr, "987654321\0", 10);
		size = 9;
		pus_tm_23_4_createReportFileAtributesReport(tm, 1, 1, 1, &repo, &file, size);
	}
	else if (i==9) {
		pus_tm_9_2_createCucTimeReport(tm, apid.apid, 27);
	}
	return 0;


	// TC without header
	//CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_initTcPacketNoHeader(&tc));
	//pus_tm_1_1_createAcceptanceReportSuccess(&tm, apid.apid, pus_getNextPacketCount(&apid), &tc);
	//CU_ASSERT_FALSE(pus_tm_1_X_getSecondaryHeaderFlag(&tm));

}

void pus_posix2time_(pusTime_t* outPusTime, time_t posixTime)
{
	struct timespec tmspc;
	tmspc.tv_nsec = 0;
	tmspc.tv_sec = posixTime;
	pus_posix2time(outPusTime, &tmspc);
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

pusError_t pus_events_initialize_null_()
{
	return pus_events_initialize(NULL);
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

pusError_t pus_tc_23_1_createCreateFileRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const char* repository, const char* fileName, pusSt23MaximumSize_t maxSize) {
	pusSt23FileName_t file;
	pusSt23RepositoryPath_t repo;

	memcpy(file.arr, fileName, pus_ST23_MAX_SIZE_FILE_PATH - 1);
	file.nCount = strlen((char*)file.arr) + 1;

	memcpy(repo.arr, repository, pus_ST23_MAX_SIZE_REPOSITORY_PATH - 1);
	repo.nCount = strlen((char*)repo.arr) + 1;

	return pus_tc_23_1_createCreateFileRequest(outTc, apid, sequenceCount, &repo, &file, maxSize);
}

pusError_t pus_tc_23_2_createDeleteFileRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const char* repository, const char* fileName) {
	pusSt23FileName_t file;
	pusSt23RepositoryPath_t repo;

	memcpy(file.arr, fileName, pus_ST23_MAX_SIZE_FILE_PATH - 1);
	file.nCount = strlen((char*)file.arr) + 1;

	memcpy(repo.arr, repository, pus_ST23_MAX_SIZE_REPOSITORY_PATH - 1);
	repo.nCount = strlen((char*)repo.arr) + 1;

	return pus_tc_23_2_createDeleteFileRequest(outTc, apid, sequenceCount, &repo, &file);
}

pusError_t pus_tc_23_3_createReportFileAtributesRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const char* repository, const char* fileName) {
	pusSt23FileName_t file;
	pusSt23RepositoryPath_t repo;

	memcpy(file.arr, fileName, pus_ST23_MAX_SIZE_FILE_PATH - 1);
	file.nCount = strlen((char*)file.arr) + 1;

	memcpy(repo.arr, repository, pus_ST23_MAX_SIZE_REPOSITORY_PATH - 1);
	repo.nCount = strlen((char*)repo.arr) + 1;

	return pus_tc_23_3_createReportFileAtributesRequest(outTc, apid, sequenceCount, &repo, &file);
}

pusError_t pus_tc_23_14_createCopyFileRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const char* sourceRepository, const char* sourceFileName, const char* targetRepository, const char* targetFileName) {

	pusSt23FileName_t srcFile, dstFile;
	pusSt23RepositoryPath_t srcRepo, dstRepo;

	if (NULL == sourceRepository || NULL == sourceFileName || NULL == targetFileName || NULL == targetRepository)
		return pusError_t::PUS_ERROR_NULLPTR;

	memcpy(srcFile.arr, sourceFileName, pus_ST23_MAX_SIZE_FILE_PATH - 1);
	srcFile.nCount = strlen((char*)srcFile.arr) + 1;

	memcpy(srcRepo.arr, sourceRepository, pus_ST23_MAX_SIZE_REPOSITORY_PATH - 1);
	srcRepo.nCount = strlen((char*)srcRepo.arr) + 1;

	memcpy(dstFile.arr, targetFileName, pus_ST23_MAX_SIZE_FILE_PATH - 1);
	dstFile.nCount = strlen((char*)dstFile.arr) + 1;

	memcpy(dstRepo.arr, targetRepository, pus_ST23_MAX_SIZE_REPOSITORY_PATH - 1);
	dstRepo.nCount = strlen((char*)dstRepo.arr) + 1;

	return pus_tc_23_14_createCopyFileRequest(outTc, apid, sequenceCount, &srcRepo, &srcFile, &dstRepo, &dstFile);
}

pusError_t pus_tc_tm_23_X_setFileName_(pusPacket_t* outTc, const char* file) {
	pusSt23FileName_t fileName;
	memcpy(fileName.arr, file, pus_ST23_MAX_SIZE_FILE_PATH - 1);
	fileName.nCount = strlen((char*)fileName.arr) + 1;

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
	memcpy(repo.arr, repository, pus_ST23_MAX_SIZE_FILE_PATH - 1);
	repo.nCount = strlen((char*)repo.arr) + 1;

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
	memcpy(fileName.arr, file, pus_ST23_MAX_SIZE_FILE_PATH - 1);
	fileName.nCount = strlen((char*)fileName.arr) + 1;

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
	memcpy(fileName.arr, file, pus_ST23_MAX_SIZE_FILE_PATH - 1);
	fileName.nCount = strlen((char*)fileName.arr) + 1;

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
	memcpy(repo.arr, repository, pus_ST23_MAX_SIZE_FILE_PATH - 1);
	repo.nCount = strlen((char*)repo.arr) + 1;

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
	memcpy(repo.arr, repository, pus_ST23_MAX_SIZE_FILE_PATH - 1);
	repo.nCount = strlen((char*)repo.arr) + 1;

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


