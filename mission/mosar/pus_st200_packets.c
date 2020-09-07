/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pus_st200_packets.h"
#include <stdio.h>
#include <string.h>
#ifdef PUS_CONFIGURE_ST200_ENABLED

asn1SccT_String asn1SccT_String_toAsn1(const char* baseObj)
{
	asn1SccT_String result;
	unsigned int len = strlen(baseObj);
	unsigned int maxSize = 255; // maxSize_PROACT_T_String
	if (len+1 > maxSize)
	{
		len = maxSize-1;
		fprintf(stderr, "WARNING: string truncated to %lld characters.\n",maxSize );
	}

	memcpy(result.arr, baseObj, len);
	result.nCount = len;
	result.arr[len]='\0';
	return result;

}
pusError_t pus_tm_200_2_createPlannerReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt200_2_Observation observation)
{
	if (NULL == outTm )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_clearError();
		pus_initTmPacket(outTm);

		// Source information
		pus_setApid(outTm, apid);
		pus_setSequenceCount(outTm, sequenceCount);

		// Data length
		pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

		// Destination
		pus_setTmDestination(outTm, destination);

		// Timestamp
		pus_setTmPacketTimeNow(outTm);

		// Service identification
		pus_setTmService(outTm, pus_ST200_timelineControl);
		pus_setTmSubtype(outTm, pus_TM_200_2_plannerReport);

		//TODO set data
		outTm->data.u.tmData.data.u.st_200_2 = observation;

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusSt200_2_Observation pus_tm_200_2_getPlannerObservation(const pusPacket_t* inTM)
{
	
	if( NULL == inTM  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		//return NULL;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST200TM(inTM, pus_TM_200_2_plannerReport))
	{
		//return NULL;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTM->data.u.tmData.data.u.st_200_2;
	
}
pusError_t pus_tc_200_3_createMissionRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt200_3_Goal goal)
{

	if (NULL == outTc)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_clearError();
		pus_initTcPacket(outTc);

		// Source information
		pus_setApid(outTc, apid);
		pus_setSequenceCount(outTc, sequenceCount);

		// Data length
		pus_setPacketDataLength(outTc, sizeof(pusPacketData_t));

		pus_setTcSource(outTc, apid);

		// Service identification
		pus_setTcService(outTc, pus_ST200_timelineControl);
		pus_setTcSubtype(outTc, pus_TC_200_3_missionRequest);

		//TODO set data
		pus_setTcDataKind(outTc, pus_TC_DATA_ST_200_3);
		outTc->data.u.tcData.data.u.st_200_3 = goal;
		//outTc->data.u.tcData.data.u.st_200_3.agent = asn1SccT_String_toAsn1("agent");

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}


pusSt200_3_Goal pus_tc_200_3_getMissionGoal(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		//return NULL;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST200TC(inTC, pus_TC_200_3_missionRequest))
	{
		//return NULL;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_200_3;
}

pusError_t pus_tc_200_3_setMissionGoal(pusPacket_t* outTc, pusSt200_3_Goal goal)
{
	if( NULL == outTc  )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST200TC(outTc, pus_TC_200_3_missionRequest))
	{
		return PUS_GET_ERROR();
	}
	outTc->data.u.tcData.data.u.st_200_3 = goal;

	return PUS_SET_ERROR(PUS_NO_ERROR);
}
pusError_t pus_tm_200_4_createMissionReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt200_4_Observation observation)
{
	if (NULL == outTm )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_clearError();
		pus_initTmPacket(outTm);

		// Source information
		pus_setApid(outTm, apid);
		pus_setSequenceCount(outTm, sequenceCount);

		// Data length
		pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

		// Destination
		pus_setTmDestination(outTm, destination);

		// Timestamp
		pus_setTmPacketTimeNow(outTm);

		// Service identification
		pus_setTmService(outTm, pus_ST200_timelineControl);
		pus_setTmSubtype(outTm, pus_TM_200_4_missionReport);

		//TODO set data
		outTm->data.u.tmData.data.u.st_200_4 = observation;

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusSt200_4_Observation pus_tm_200_4_getMissionObservation(const pusPacket_t* inTM)
{
	
	if( NULL == inTM  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		//return NULL;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST200TM(inTM, pus_TM_200_4_missionReport))
	{
		//return NULL;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTM->data.u.tmData.data.u.st_200_4;
	
}
pusError_t pus_tc_200_5_createHotdockcmdRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt200_5_Goal goal)
{

	if (NULL == outTc)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_clearError();
		pus_initTcPacket(outTc);

		// Source information
		pus_setApid(outTc, apid);
		pus_setSequenceCount(outTc, sequenceCount);

		// Data length
		pus_setPacketDataLength(outTc, sizeof(pusPacketData_t));

		pus_setTcSource(outTc, apid);

		// Service identification
		pus_setTcService(outTc, pus_ST200_timelineControl);
		pus_setTcSubtype(outTc, pus_TC_200_5_hotdockcmdRequest);

		//TODO set data
		pus_setTcDataKind(outTc, pus_TC_DATA_ST_200_5);
		outTc->data.u.tcData.data.u.st_200_5 = goal;
		//outTc->data.u.tcData.data.u.st_200_5.agent = asn1SccT_String_toAsn1("agent");

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}


pusSt200_5_Goal pus_tc_200_5_getHotdockcmdGoal(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		//return NULL;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST200TC(inTC, pus_TC_200_5_hotdockcmdRequest))
	{
		//return NULL;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_200_5;
}

pusError_t pus_tc_200_5_setHotdockcmdGoal(pusPacket_t* outTc, pusSt200_5_Goal goal)
{
	if( NULL == outTc  )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST200TC(outTc, pus_TC_200_5_hotdockcmdRequest))
	{
		return PUS_GET_ERROR();
	}
	outTc->data.u.tcData.data.u.st_200_5 = goal;

	return PUS_SET_ERROR(PUS_NO_ERROR);
}
pusError_t pus_tm_200_6_createHotdockcmdReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt200_6_Observation observation)
{
	if (NULL == outTm )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_clearError();
		pus_initTmPacket(outTm);

		// Source information
		pus_setApid(outTm, apid);
		pus_setSequenceCount(outTm, sequenceCount);

		// Data length
		pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

		// Destination
		pus_setTmDestination(outTm, destination);

		// Timestamp
		pus_setTmPacketTimeNow(outTm);

		// Service identification
		pus_setTmService(outTm, pus_ST200_timelineControl);
		pus_setTmSubtype(outTm, pus_TM_200_6_hotdockcmdReport);

		//TODO set data
		outTm->data.u.tmData.data.u.st_200_6 = observation;

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusSt200_6_Observation pus_tm_200_6_getHotdockcmdObservation(const pusPacket_t* inTM)
{
	
	if( NULL == inTM  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		//return NULL;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST200TM(inTM, pus_TM_200_6_hotdockcmdReport))
	{
		//return NULL;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTM->data.u.tmData.data.u.st_200_6;
	
}
pusError_t pus_tm_200_8_createHotdockstatusReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt200_8_Observation observation)
{
	if (NULL == outTm )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_clearError();
		pus_initTmPacket(outTm);

		// Source information
		pus_setApid(outTm, apid);
		pus_setSequenceCount(outTm, sequenceCount);

		// Data length
		pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

		// Destination
		pus_setTmDestination(outTm, destination);

		// Timestamp
		pus_setTmPacketTimeNow(outTm);

		// Service identification
		pus_setTmService(outTm, pus_ST200_timelineControl);
		pus_setTmSubtype(outTm, pus_TM_200_8_hotdockstatusReport);

		//TODO set data
		outTm->data.u.tmData.data.u.st_200_8 = observation;

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusSt200_8_Observation pus_tm_200_8_getHotdockstatusObservation(const pusPacket_t* inTM)
{
	
	if( NULL == inTM  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		//return NULL;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST200TM(inTM, pus_TM_200_8_hotdockstatusReport))
	{
		//return NULL;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTM->data.u.tmData.data.u.st_200_8;
	
}
pusError_t pus_tc_200_9_createWmcmdRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt200_9_Goal goal)
{

	if (NULL == outTc)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_clearError();
		pus_initTcPacket(outTc);

		// Source information
		pus_setApid(outTc, apid);
		pus_setSequenceCount(outTc, sequenceCount);

		// Data length
		pus_setPacketDataLength(outTc, sizeof(pusPacketData_t));

		pus_setTcSource(outTc, apid);

		// Service identification
		pus_setTcService(outTc, pus_ST200_timelineControl);
		pus_setTcSubtype(outTc, pus_TC_200_9_wmcmdRequest);

		//TODO set data
		pus_setTcDataKind(outTc, pus_TC_DATA_ST_200_9);
		outTc->data.u.tcData.data.u.st_200_9 = goal;
		//outTc->data.u.tcData.data.u.st_200_9.agent = asn1SccT_String_toAsn1("agent");

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}


pusSt200_9_Goal pus_tc_200_9_getWmcmdGoal(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		//return NULL;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST200TC(inTC, pus_TC_200_9_wmcmdRequest))
	{
		//return NULL;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_200_9;
}

pusError_t pus_tc_200_9_setWmcmdGoal(pusPacket_t* outTc, pusSt200_9_Goal goal)
{
	if( NULL == outTc  )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST200TC(outTc, pus_TC_200_9_wmcmdRequest))
	{
		return PUS_GET_ERROR();
	}
	outTc->data.u.tcData.data.u.st_200_9 = goal;

	return PUS_SET_ERROR(PUS_NO_ERROR);
}
pusError_t pus_tm_200_10_createWmcmdReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt200_10_Observation observation)
{
	if (NULL == outTm )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_clearError();
		pus_initTmPacket(outTm);

		// Source information
		pus_setApid(outTm, apid);
		pus_setSequenceCount(outTm, sequenceCount);

		// Data length
		pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

		// Destination
		pus_setTmDestination(outTm, destination);

		// Timestamp
		pus_setTmPacketTimeNow(outTm);

		// Service identification
		pus_setTmService(outTm, pus_ST200_timelineControl);
		pus_setTmSubtype(outTm, pus_TM_200_10_wmcmdReport);

		//TODO set data
		outTm->data.u.tmData.data.u.st_200_10 = observation;

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusSt200_10_Observation pus_tm_200_10_getWmcmdObservation(const pusPacket_t* inTM)
{
	
	if( NULL == inTM  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		//return NULL;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST200TM(inTM, pus_TM_200_10_wmcmdReport))
	{
		//return NULL;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTM->data.u.tmData.data.u.st_200_10;
	
}
pusError_t pus_tc_200_11_createBasecmdRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt200_11_Goal goal)
{

	if (NULL == outTc)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_clearError();
		pus_initTcPacket(outTc);

		// Source information
		pus_setApid(outTc, apid);
		pus_setSequenceCount(outTc, sequenceCount);

		// Data length
		pus_setPacketDataLength(outTc, sizeof(pusPacketData_t));

		pus_setTcSource(outTc, apid);

		// Service identification
		pus_setTcService(outTc, pus_ST200_timelineControl);
		pus_setTcSubtype(outTc, pus_TC_200_11_basecmdRequest);

		//TODO set data
		pus_setTcDataKind(outTc, pus_TC_DATA_ST_200_11);
		outTc->data.u.tcData.data.u.st_200_11 = goal;
		//outTc->data.u.tcData.data.u.st_200_11.agent = asn1SccT_String_toAsn1("agent");

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}


pusSt200_11_Goal pus_tc_200_11_getBasecmdGoal(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		//return NULL;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST200TC(inTC, pus_TC_200_11_basecmdRequest))
	{
		//return NULL;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_200_11;
}

pusError_t pus_tc_200_11_setBasecmdGoal(pusPacket_t* outTc, pusSt200_11_Goal goal)
{
	if( NULL == outTc  )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST200TC(outTc, pus_TC_200_11_basecmdRequest))
	{
		return PUS_GET_ERROR();
	}
	outTc->data.u.tcData.data.u.st_200_11 = goal;

	return PUS_SET_ERROR(PUS_NO_ERROR);
}
pusError_t pus_tm_200_12_createBasecmdReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt200_12_Observation observation)
{
	if (NULL == outTm )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_clearError();
		pus_initTmPacket(outTm);

		// Source information
		pus_setApid(outTm, apid);
		pus_setSequenceCount(outTm, sequenceCount);

		// Data length
		pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

		// Destination
		pus_setTmDestination(outTm, destination);

		// Timestamp
		pus_setTmPacketTimeNow(outTm);

		// Service identification
		pus_setTmService(outTm, pus_ST200_timelineControl);
		pus_setTmSubtype(outTm, pus_TM_200_12_basecmdReport);

		//TODO set data
		outTm->data.u.tmData.data.u.st_200_12 = observation;

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusSt200_12_Observation pus_tm_200_12_getBasecmdObservation(const pusPacket_t* inTM)
{
	
	if( NULL == inTM  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		//return NULL;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST200TM(inTM, pus_TM_200_12_basecmdReport))
	{
		//return NULL;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTM->data.u.tmData.data.u.st_200_12;
	
}
pusError_t pus_tc_200_13_createEfcmdRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt200_13_Goal goal)
{

	if (NULL == outTc)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_clearError();
		pus_initTcPacket(outTc);

		// Source information
		pus_setApid(outTc, apid);
		pus_setSequenceCount(outTc, sequenceCount);

		// Data length
		pus_setPacketDataLength(outTc, sizeof(pusPacketData_t));

		pus_setTcSource(outTc, apid);

		// Service identification
		pus_setTcService(outTc, pus_ST200_timelineControl);
		pus_setTcSubtype(outTc, pus_TC_200_13_efcmdRequest);

		//TODO set data
		pus_setTcDataKind(outTc, pus_TC_DATA_ST_200_13);
		outTc->data.u.tcData.data.u.st_200_13 = goal;
		//outTc->data.u.tcData.data.u.st_200_13.agent = asn1SccT_String_toAsn1("agent");

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}


pusSt200_13_Goal pus_tc_200_13_getEfcmdGoal(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		//return NULL;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST200TC(inTC, pus_TC_200_13_efcmdRequest))
	{
		//return NULL;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_200_13;
}

pusError_t pus_tc_200_13_setEfcmdGoal(pusPacket_t* outTc, pusSt200_13_Goal goal)
{
	if( NULL == outTc  )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST200TC(outTc, pus_TC_200_13_efcmdRequest))
	{
		return PUS_GET_ERROR();
	}
	outTc->data.u.tcData.data.u.st_200_13 = goal;

	return PUS_SET_ERROR(PUS_NO_ERROR);
}
pusError_t pus_tm_200_14_createEfcmdReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt200_14_Observation observation)
{
	if (NULL == outTm )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_clearError();
		pus_initTmPacket(outTm);

		// Source information
		pus_setApid(outTm, apid);
		pus_setSequenceCount(outTm, sequenceCount);

		// Data length
		pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

		// Destination
		pus_setTmDestination(outTm, destination);

		// Timestamp
		pus_setTmPacketTimeNow(outTm);

		// Service identification
		pus_setTmService(outTm, pus_ST200_timelineControl);
		pus_setTmSubtype(outTm, pus_TM_200_14_efcmdReport);

		//TODO set data
		outTm->data.u.tmData.data.u.st_200_14 = observation;

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusSt200_14_Observation pus_tm_200_14_getEfcmdObservation(const pusPacket_t* inTM)
{
	
	if( NULL == inTM  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		//return NULL;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST200TM(inTM, pus_TM_200_14_efcmdReport))
	{
		//return NULL;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTM->data.u.tmData.data.u.st_200_14;
	
}


pusError_t pus_expectSt200Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTcHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTcService(packet);
		pusSubservice_t subtype = pus_getTcSubtype(packet);

		if (service != pus_ST200_timelineControl)
		{
			pus_setError(PUS_ERROR_TC_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TC_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[200]
			if ( 
                subtype != pus_TC_200_3_missionRequest &&  
                subtype != pus_TC_200_5_hotdockcmdRequest &&  
                subtype != pus_TC_200_9_wmcmdRequest &&  
                subtype != pus_TC_200_11_basecmdRequest &&  
                subtype != pus_TC_200_13_efcmdRequest )
			{
				pus_setError(PUS_ERROR_TC_SUBTYPE, function, (pusErrorData_t){.integer=subtype});
				return PUS_ERROR_TC_SUBTYPE;
			}
		}
		else
		{
			// Check that subtype is as expected
			if (subtype != expectedSubtype)
			{
				pus_setError(PUS_ERROR_TC_SUBTYPE, function, (pusErrorData_t){.integer=subtype});
				return PUS_ERROR_TC_SUBTYPE;
			}
		}

		pusPacketDataKind_t kind = pus_getTcDataKind(packet);
        if ( 
            kind != pus_TC_DATA_ST_200_3 &&  
            kind != pus_TC_DATA_ST_200_5 &&  
            kind != pus_TC_DATA_ST_200_9 &&  
            kind != pus_TC_DATA_ST_200_11 &&  
            kind != pus_TC_DATA_ST_200_13 )
		{
			pus_setError(PUS_ERROR_TC_KIND, function, (pusErrorData_t){.integer=kind});
			return PUS_ERROR_TC_KIND;
		}
		
		return PUS_NO_ERROR;
	}
	else
	{
		return expectResult;
	}
}

pusError_t pus_expectSt200Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTmHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTmService(packet);
		pusSubservice_t subtype = pus_getTmSubtype(packet);

		if (service != pus_ST200_timelineControl)
		{
			pus_setError(PUS_ERROR_TM_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TM_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[200]
            if (subtype != pus_TM_200_2_plannerReport && 
                subtype != pus_TM_200_4_missionReport && 
                subtype != pus_TM_200_6_hotdockcmdReport && 
                subtype != pus_TM_200_8_hotdockstatusReport && 
                subtype != pus_TM_200_10_wmcmdReport && 
                subtype != pus_TM_200_12_basecmdReport && 
                subtype != pus_TM_200_14_efcmdReport 
                )
			{
				pus_setError(PUS_ERROR_TM_SUBTYPE, function, (pusErrorData_t){.integer=subtype});
				return PUS_ERROR_TM_SUBTYPE;
			}
		}
		else
		{
			// Check that subtype is as expected
			if (subtype != expectedSubtype)
			{
				pus_setError(PUS_ERROR_TM_SUBTYPE, function, (pusErrorData_t){.integer=subtype});
				return PUS_ERROR_TM_SUBTYPE;
			}
		}

		pusPacketDataKind_t kind = pus_getTmDataKind(packet);
        if (kind != pus_TM_DATA_ST_200_2 && 
            kind != pus_TM_DATA_ST_200_4 && 
            kind != pus_TM_DATA_ST_200_6 && 
            kind != pus_TM_DATA_ST_200_8 && 
            kind != pus_TM_DATA_ST_200_10 && 
            kind != pus_TM_DATA_ST_200_12 && 
            kind != pus_TM_DATA_ST_200_14 
            )
		{
			pus_setError(PUS_ERROR_TM_KIND, function, (pusErrorData_t){.integer=kind});
			return PUS_ERROR_TM_KIND;
		}

		return PUS_NO_ERROR;
	}
	else
	{
		return expectResult;
	}
}

#endif