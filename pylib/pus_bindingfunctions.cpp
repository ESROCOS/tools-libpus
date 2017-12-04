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

pusError_t pus_hk_initialize_null()
{
	return pus_hk_initialize(NULL);
}
