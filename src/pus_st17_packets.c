
//#include "pus_threads.h"
#include "pus_error.h"
#include "pus_packet.h"
//#include "pus_stored_param.h"



#include "pus_st17_packets.h"


pusError_t pus_tc_17_1_createConnectionTestRequest(pusPacket_t* outTm, pusApidInfo_t* apid)
{

	if (NULL == outTm || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_initTcPacket(outTm);
		//pus_setTmDataKind(outTm, pus_TM_DATA_ST_1_X);

		// Source information
		pus_setApid(outTm, pus_getInfoApid(apid));
		pus_setSequenceCount(outTm, pus_getNextTmCount(apid));

		// Data length
		pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

		// Service identification
		pus_setTcService(outTm, pus_ST17_test);
		pus_setTcSubtype(outTm, pus_TC_17_1_connectionTest);

		//pus_setTmDestination(outTm, pus_APID_IDLE);

		// Timestamp
		pus_setTmPacketTimeNow(outTm);


		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusError_t pus_tm_17_2_createConnectionTestReport(pusPacket_t* outTm, pusApidInfo_t* apid)
{
	if (NULL == outTm || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_initTmPacket(outTm);
		//pus_setTMDataKind(outTm, pus_TM_DATA_ST_1_X);

		// Source information
		pus_setApid(outTm, pus_getInfoApid(apid));
		pus_setSequenceCount(outTm, pus_getNextTmCount(apid));

		// Data length
		pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

		// Service identification
		pus_setTcService(outTm, pus_ST17_test);
		pus_setTcSubtype(outTm, pus_TM_17_2_connectionTest);

		//pus_setTmDestination(outTm, pus_APID_IDLE);

		// Timestamp
		pus_setTmPacketTimeNow(outTm);


		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}
