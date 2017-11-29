#include "pus_bindingfunctions.hpp"



pusError_t pus_initApidInfo_(pusApidInfo_t* obj, pusApid_t apid)
{
	return pus_initApidInfo(obj, apid, NULL);
}

uint pus_getPacketVersion_(const pusPacket_t* packet)
{
	return (uint) pus_getPacketVersion(packet);
}

uint pus_getPacketType_(const pusPacket_t* packet)
{
	return (uint) pus_getPacketType(packet);
}

uint pus_getSequenceFlags_(const pusPacket_t* packet)
{
	return (uint) pus_getSequenceFlags(packet);
}

uint pus_getTmPusVersion_(const pusPacket_t* packet)
{
	return (uint) pus_getTmPusVersion(packet);
}

uint pus_getTcPusVersion_(const pusPacket_t* packet)
{
	return (uint) pus_getTcPusVersion(packet);
}

struct timespec pus_getTmPacketTime_(const pusPacket_t* packet)
{
	pusTime_t time;
	struct timespec ts;
	pus_getTmPacketTime(&time, packet);
	ts.tv_sec = (time_t) time.tv_sec;
	ts.tv_nsec = time.tv_nsec;

	return ts;
}

