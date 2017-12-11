
#include "pus_st09_packets.h"


pusError_t pus_tc_9_1_createSetTimeReportRate(pusPacket_t* outTc, pusApidInfo_t* apid)
{
	if (NULL == outTc || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_initTcPacket(outTc);

		// Source information
		pus_setApid(outTc, pus_getInfoApid(apid));
		pus_setSequenceCount(outTc, pus_getNextPacketCount(apid));

		// Data length
		pus_setPacketDataLength(outTc, sizeof(pusPacketData_t));

		// Service identification
		pus_setTcService(outTc, pus_ST09_timeManagement);
		pus_setTcSubtype(outTc, pus_TC_9_1_setTimeReportRate);

		//TODO data
		pus_setTcDataKind(outTc, pus_TC_DATA_ST_9_1);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusError_t pus_tm_9_2_createCucTimeReport(pusPacket_t* outTm, pusApidInfo_t* apid, pusApid_t destination)
{

	if ( NULL == outTm || NULL == apid )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		//create package
		pus_initTmPacketNoHeader(outTm);


		// Source information
		pus_setApid(outTm, pus_getInfoApid(apid));
		pus_setSequenceCount(outTm, pus_getNextPacketCount(apid));

		// Data length
		pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

		// Service identification
		pus_setTmService(outTm, pus_ST09_timeManagement); //todo
		pus_setTmSubtype(outTm, pus_TM_9_2_cucTimeReport);

		// Timestamp
		pus_setTmPacketTimeNow(outTm);

		// Destination
		pus_setTmDestination(outTm, destination);

		//TODO data
		pus_setTmNoHeaderDataKind(outTm, pus_TM_DATA_ST_9_2);



		return PUS_GET_ERROR();
	}
}





