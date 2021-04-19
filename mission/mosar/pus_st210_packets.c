/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pus_st210_packets.h"
#include <stdio.h>
#include <string.h>
#ifdef PUS_CONFIGURE_ST210_ENABLED

/* R_ICU_SPW_PNP */
pusError_t pus_tc_210_1_createSpwRoutingTableSetEntry(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 routingTableIndex, asn1SccPusUInt8 routingTableDirection, asn1SccPusUInt8 trafficPriority)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_1_SpwRoutingTableSetEntry);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_1);
		pus_tc_210_1_setParamSM_ID(outTc, smId);
		pus_tc_210_1_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_1_setParamRoutingTableIndex(outTc, routingTableIndex);
		pus_tc_210_1_setParamRoutingTableDirection(outTc, routingTableDirection);
		pus_tc_210_1_setParamTrafficPriority(outTc, trafficPriority);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_1_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_1_SpwRoutingTableSetEntry))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_1.smId;
}

pusError_t pus_tc_210_1_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_1_SpwRoutingTableSetEntry))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_1.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_1_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_1_SpwRoutingTableSetEntry))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_1.componentId;
}

pusError_t pus_tc_210_1_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_1_SpwRoutingTableSetEntry))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_1.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_1_getParamRoutingTableIndex(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_1_SpwRoutingTableSetEntry))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_1.routingTableIndex;
}

pusError_t pus_tc_210_1_setParamRoutingTableIndex(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_1_SpwRoutingTableSetEntry))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_1.routingTableIndex = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusUInt8 pus_tc_210_1_getParamRoutingTableDirection(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_1_SpwRoutingTableSetEntry))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_1.routingTableDirection;
}

pusError_t pus_tc_210_1_setParamRoutingTableDirection(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_1_SpwRoutingTableSetEntry))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_1.routingTableDirection = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusUInt8 pus_tc_210_1_getParamTrafficPriority(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_1_SpwRoutingTableSetEntry))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_1.trafficPriority;
}

pusError_t pus_tc_210_1_setParamTrafficPriority(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_1_SpwRoutingTableSetEntry))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_1.trafficPriority = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_2_createSpwPnpSetOwnerFields(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 setOwner)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_2_SpwPnpSetOwnerFields);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_2);
		pus_tc_210_2_setParamSM_ID(outTc, smId);
		pus_tc_210_2_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_2_setParamSetOwner(outTc, setOwner);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_2_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_2_SpwPnpSetOwnerFields))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_2.smId;
}

pusError_t pus_tc_210_2_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_2_SpwPnpSetOwnerFields))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_2.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_2_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_2_SpwPnpSetOwnerFields))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_2.componentId;
}

pusError_t pus_tc_210_2_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_2_SpwPnpSetOwnerFields))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_2.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_2_getParamSetOwner(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_2_SpwPnpSetOwnerFields))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_2.setOwner;
}

pusError_t pus_tc_210_2_setParamSetOwner(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_2_SpwPnpSetOwnerFields))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_2.setOwner = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

/* R_ICU */
pusError_t pus_tc_210_11_createConfigureTimeEpoch(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusInt32 secsSinceEpoch, asn1SccPusInt32 nanosecsSinceEpoch)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_11_ConfigureTimeEpoch);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_11);
		pus_tc_210_11_setParamSM_ID(outTc, smId);
		pus_tc_210_11_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_11_setParamSecsSinceEpoch(outTc, secsSinceEpoch);
		pus_tc_210_11_setParamNanosecsSinceEpoch(outTc, nanosecsSinceEpoch);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_11_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_11_ConfigureTimeEpoch))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_11.smId;
}

pusError_t pus_tc_210_11_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_11_ConfigureTimeEpoch))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_11.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_11_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_11_ConfigureTimeEpoch))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_11.componentId;
}

pusError_t pus_tc_210_11_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_11_ConfigureTimeEpoch))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_11.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusInt32 pus_tc_210_11_getParamSecsSinceEpoch(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_11_ConfigureTimeEpoch))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_11.secsSinceEpoch;
}

pusError_t pus_tc_210_11_setParamSecsSinceEpoch(pusPacket_t* outTC, asn1SccPusInt32 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_11_ConfigureTimeEpoch))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_11.secsSinceEpoch = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusInt32 pus_tc_210_11_getParamNanosecsSinceEpoch(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_11_ConfigureTimeEpoch))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_11.nanosecsSinceEpoch;
}

pusError_t pus_tc_210_11_setParamNanosecsSinceEpoch(pusPacket_t* outTC, asn1SccPusInt32 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_11_ConfigureTimeEpoch))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_11.nanosecsSinceEpoch = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_12_createSetLeds(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 setLeds)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_12_SetLeds);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_12);
		pus_tc_210_12_setParamSM_ID(outTc, smId);
		pus_tc_210_12_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_12_setParamSetLeds(outTc, setLeds);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_12_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_12_SetLeds))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_12.smId;
}

pusError_t pus_tc_210_12_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_12_SetLeds))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_12.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_12_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_12_SetLeds))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_12.componentId;
}

pusError_t pus_tc_210_12_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_12_SetLeds))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_12.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_12_getParamSetLeds(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_12_SetLeds))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_12.setLeds;
}

pusError_t pus_tc_210_12_setParamSetLeds(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_12_SetLeds))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_12.setLeds = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}


/* HOTDOCK */
pusError_t pus_tc_210_21_createSetHouskeepingDataRate(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusUInt8 pollingHkTm)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_21_SetHouskeepingDataRate);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_21);
		pus_tc_210_21_setParamSM_ID(outTc, smId);
		pus_tc_210_21_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_21_setParamSUBCOMP_ID(outTc, subcomponentId);
		pus_tc_210_21_setParamPollingHkTm(outTc, pollingHkTm);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_21_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_21_SetHouskeepingDataRate))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_21.smId;
}

pusError_t pus_tc_210_21_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_21_SetHouskeepingDataRate))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_21.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_21_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_21_SetHouskeepingDataRate))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_21.componentId;
}

pusError_t pus_tc_210_21_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_21_SetHouskeepingDataRate))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_21.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_21_getParamSUBCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_21_SetHouskeepingDataRate))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_21.subcomponentId;
}

pusError_t pus_tc_210_21_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_21_SetHouskeepingDataRate))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_21.subcomponentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_21_getParamPollingHkTm(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_21_SetHouskeepingDataRate))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_21.pollingHkTm;
}

pusError_t pus_tc_210_21_setParamPollingHkTm(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_21_SetHouskeepingDataRate))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_21.pollingHkTm = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_22_createGoToState(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusUInt8 targetState)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_22_GoToState);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_22);
		pus_tc_210_22_setParamSM_ID(outTc, smId);
		pus_tc_210_22_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_22_setParamSUBCOMP_ID(outTc, subcomponentId);
		pus_tc_210_22_setParamTargetState(outTc, targetState);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_22_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_22_GoToState))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_22.smId;
}

pusError_t pus_tc_210_22_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_22_GoToState))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_22.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_22_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_22_GoToState))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_22.componentId;
}

pusError_t pus_tc_210_22_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_22_GoToState))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_22.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_22_getParamSUBCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_22_GoToState))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_22.subcomponentId;
}

pusError_t pus_tc_210_22_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_22_GoToState))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_22.subcomponentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_22_getParamTargetState(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_22_GoToState))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_22.targetState;
}

pusError_t pus_tc_210_22_setParamTargetState(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_22_GoToState))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_22.targetState = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_23_createCommandP15VLine(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusBoolean p15vCmd)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_23_CommandP15vLine);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_23);
		pus_tc_210_23_setParamSM_ID(outTc, smId);
		pus_tc_210_23_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_23_setParamSUBCOMP_ID(outTc, subcomponentId);
		pus_tc_210_23_setParamP15vCmd(outTc, p15vCmd);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_23_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_23_CommandP15vLine))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_23.smId;
}

pusError_t pus_tc_210_23_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_23_CommandP15vLine))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_23.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_23_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_23_CommandP15vLine))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_23.componentId;
}

pusError_t pus_tc_210_23_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_23_CommandP15vLine))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_23.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_23_getParamSUBCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_23_CommandP15vLine))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_23.subcomponentId;
}

pusError_t pus_tc_210_23_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_23_CommandP15vLine))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_23.subcomponentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusBoolean pus_tc_210_23_getParamP15vCmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_23_CommandP15vLine))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_23.p15vCmd;
}

pusError_t pus_tc_210_23_setParamP15vCmd(pusPacket_t* outTC, asn1SccPusBoolean param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_23_CommandP15vLine))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_23.p15vCmd = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_24_createCommandP2V5Line(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusBoolean p2v5Cmd)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_24_CommandP2v5Line);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_24);
		pus_tc_210_24_setParamSM_ID(outTc, smId);
		pus_tc_210_24_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_24_setParamSUBCOMP_ID(outTc, subcomponentId);
		pus_tc_210_24_setParamP2v5Cmd(outTc, p2v5Cmd);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_24_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_24_CommandP2v5Line))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_24.smId;
}

pusError_t pus_tc_210_24_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_24_CommandP2v5Line))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_24.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_24_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_24_CommandP2v5Line))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_24.componentId;
}

pusError_t pus_tc_210_24_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_24_CommandP2v5Line))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_24.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_24_getParamSUBCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_24_CommandP2v5Line))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_24.subcomponentId;
}

pusError_t pus_tc_210_24_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_24_CommandP2v5Line))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_24.subcomponentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusBoolean pus_tc_210_24_getParamP2v5Cmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_24_CommandP2v5Line))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_24.p2v5Cmd;
}

pusError_t pus_tc_210_24_setParamP2v5Cmd(pusPacket_t* outTC, asn1SccPusBoolean param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_24_CommandP2v5Line))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_24.p2v5Cmd = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_25_createCoomdadRelay(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusBoolean relayCmd)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_25_CoomdadRelay);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_25);
		pus_tc_210_25_setParamSM_ID(outTc, smId);
		pus_tc_210_25_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_25_setParamSUBCOMP_ID(outTc, subcomponentId);
		pus_tc_210_25_setParamRelayCmd(outTc, relayCmd);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_25_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_25_CoomdadRelay))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_25.smId;
}

pusError_t pus_tc_210_25_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_25_CoomdadRelay))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_25.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_25_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_25_CoomdadRelay))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_25.componentId;
}

pusError_t pus_tc_210_25_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_25_CoomdadRelay))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_25.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_25_getParamSUBCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_25_CoomdadRelay))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_25.subcomponentId;
}

pusError_t pus_tc_210_25_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_25_CoomdadRelay))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_25.subcomponentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusBoolean pus_tc_210_25_getParamRelayCmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_25_CoomdadRelay))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_25.relayCmd;
}

pusError_t pus_tc_210_25_setParamRelayCmd(pusPacket_t* outTC, asn1SccPusBoolean param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_25_CoomdadRelay))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_25.relayCmd = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_26_createSetLvdsPins(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusUInt8 lvdsACmd, asn1SccPusUInt8 lvdsBCmd)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_26_SetLvdsPins);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_26);
		pus_tc_210_26_setParamSM_ID(outTc, smId);
		pus_tc_210_26_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_26_setParamSUBCOMP_ID(outTc, subcomponentId);
		pus_tc_210_26_setParamLvdsACmd(outTc, lvdsACmd);
		pus_tc_210_26_setParamLvdsBCmd(outTc, lvdsBCmd);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_26_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_26_SetLvdsPins))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_26.smId;
}

pusError_t pus_tc_210_26_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_26_SetLvdsPins))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_26.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_26_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_26_SetLvdsPins))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_26.componentId;
}

pusError_t pus_tc_210_26_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_26_SetLvdsPins))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_26.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_26_getParamSUBCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_26_SetLvdsPins))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_26.subcomponentId;
}

pusError_t pus_tc_210_26_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_26_SetLvdsPins))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_26.subcomponentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_26_getParamLvdsACmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_26_SetLvdsPins))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_26.lvdsACmd;
}

pusError_t pus_tc_210_26_setParamLvdsACmd(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_26_SetLvdsPins))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_26.lvdsACmd = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusUInt8 pus_tc_210_26_getParamLvdsBCmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_26_SetLvdsPins))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_26.lvdsBCmd;
}

pusError_t pus_tc_210_26_setParamLvdsBCmd(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_26_SetLvdsPins))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_26.lvdsBCmd = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_27_createPowerOnOffMotor(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusBoolean motorOnOff)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_27_PowerOnOffMotor);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_27);
		pus_tc_210_27_setParamSM_ID(outTc, smId);
		pus_tc_210_27_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_27_setParamSUBCOMP_ID(outTc, subcomponentId);
		pus_tc_210_27_setParamMotorOnOff(outTc, motorOnOff);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_27_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_27_PowerOnOffMotor))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_27.smId;
}

pusError_t pus_tc_210_27_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_27_PowerOnOffMotor))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_27.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_27_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_27_PowerOnOffMotor))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_27.componentId;
}

pusError_t pus_tc_210_27_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_27_PowerOnOffMotor))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_27.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_27_getParamSUBCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_27_PowerOnOffMotor))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_27.subcomponentId;
}

pusError_t pus_tc_210_27_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_27_PowerOnOffMotor))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_27.subcomponentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusBoolean pus_tc_210_27_getParamMotorOnOff(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_27_PowerOnOffMotor))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_27.motorOnOff;
}

pusError_t pus_tc_210_27_setParamMotorOnOff(pusPacket_t* outTC, asn1SccPusBoolean param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_27_PowerOnOffMotor))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_27.motorOnOff = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_28_createSetMotorSpeed(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusFloat32 motorTargetSpeed)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_28_SetMotorSpeed);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_28);
		pus_tc_210_28_setParamSM_ID(outTc, smId);
		pus_tc_210_28_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_28_setParamSUBCOMP_ID(outTc, subcomponentId);
		pus_tc_210_28_setParamMotorTargetSpeed(outTc, motorTargetSpeed);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_28_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_28_SetMotorSpeed))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_28.smId;
}

pusError_t pus_tc_210_28_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_28_SetMotorSpeed))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_28.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_28_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_28_SetMotorSpeed))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_28.componentId;
}

pusError_t pus_tc_210_28_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_28_SetMotorSpeed))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_28.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_28_getParamSUBCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_28_SetMotorSpeed))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_28.subcomponentId;
}

pusError_t pus_tc_210_28_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_28_SetMotorSpeed))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_28.subcomponentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusFloat32 pus_tc_210_28_getParamMotorTargetSpeed(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_28_SetMotorSpeed))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_28.motorTargetSpeed;
}

pusError_t pus_tc_210_28_setParamMotorTargetSpeed(pusPacket_t* outTC, asn1SccPusFloat32 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_28_SetMotorSpeed))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_28.motorTargetSpeed = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_29_createSetMotorDirection(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusBoolean motorDirectionSpeed)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_29_SetMotorDirection);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_29);
		pus_tc_210_29_setParamSM_ID(outTc, smId);
		pus_tc_210_29_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_29_setParamSUBCOMP_ID(outTc, subcomponentId);
		pus_tc_210_29_setParamMotorDirectionSpeed(outTc, motorDirectionSpeed);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_29_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_29_SetMotorDirection))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_29.smId;
}

pusError_t pus_tc_210_29_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_29_SetMotorDirection))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_29.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_29_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_29_SetMotorDirection))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_29.componentId;
}

pusError_t pus_tc_210_29_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_29_SetMotorDirection))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_29.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_29_getParamSUBCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_29_SetMotorDirection))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_29.subcomponentId;
}

pusError_t pus_tc_210_29_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_29_SetMotorDirection))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_29.subcomponentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusBoolean pus_tc_210_29_getParamMotorDirectionSpeed(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_29_SetMotorDirection))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_29.motorDirectionSpeed;
}

pusError_t pus_tc_210_29_setParamMotorDirectionSpeed(pusPacket_t* outTC, asn1SccPusBoolean param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_29_SetMotorDirection))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_29.motorDirectionSpeed = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_30_createSetMotorCurrentLimit(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusFloat32 motorCurrentLimit)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_30_SetMotorCurrentLimit);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_30);
		pus_tc_210_30_setParamSM_ID(outTc, smId);
		pus_tc_210_30_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_30_setParamSUBCOMP_ID(outTc, subcomponentId);
		pus_tc_210_30_setParamMotorCurrentLimit(outTc, motorCurrentLimit);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_30_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_30_SetMotorCurrentLimit))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_30.smId;
}

pusError_t pus_tc_210_30_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_30_SetMotorCurrentLimit))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_30.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_30_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_30_SetMotorCurrentLimit))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_30.componentId;
}

pusError_t pus_tc_210_30_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_30_SetMotorCurrentLimit))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_30.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_30_getParamSUBCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_30_SetMotorCurrentLimit))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_30.subcomponentId;
}

pusError_t pus_tc_210_30_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_30_SetMotorCurrentLimit))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_30.subcomponentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusFloat32 pus_tc_210_30_getParamMotorCurrentLimit(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_30_SetMotorCurrentLimit))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_30.motorCurrentLimit;
}

pusError_t pus_tc_210_30_setParamMotorCurrentLimit(pusPacket_t* outTC, asn1SccPusFloat32 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_30_SetMotorCurrentLimit))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_30.motorCurrentLimit = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_31_createCalibrateController(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusUInt8 controllerCalib)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_31_CalibrateController);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_31);
		pus_tc_210_31_setParamSM_ID(outTc, smId);
		pus_tc_210_31_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_31_setParamSUBCOMP_ID(outTc, subcomponentId);
		pus_tc_210_31_setParamControllerCalib(outTc, controllerCalib);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_31_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_31_CalibrateController))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_31.smId;
}

pusError_t pus_tc_210_31_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_31_CalibrateController))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_31.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_31_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_31_CalibrateController))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_31.componentId;
}

pusError_t pus_tc_210_31_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_31_CalibrateController))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_31.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_31_getParamSUBCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_31_CalibrateController))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_31.subcomponentId;
}

pusError_t pus_tc_210_31_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_31_CalibrateController))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_31.subcomponentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_31_getParamControllerCalib(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_31_CalibrateController))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_31.controllerCalib;
}

pusError_t pus_tc_210_31_setParamControllerCalib(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_31_CalibrateController))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_31.controllerCalib = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_32_createResetController(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_32_ResetController);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_32);
		pus_tc_210_32_setParamSM_ID(outTc, smId);
		pus_tc_210_32_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_32_setParamSUBCOMP_ID(outTc, subcomponentId);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_32_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_32_ResetController))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_32.smId;
}

pusError_t pus_tc_210_32_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_32_ResetController))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_32.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_32_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_32_ResetController))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_32.componentId;
}

pusError_t pus_tc_210_32_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_32_ResetController))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_32.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_32_getParamSUBCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_32_ResetController))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_32.subcomponentId;
}

pusError_t pus_tc_210_32_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_32_ResetController))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_32.subcomponentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}



/* OSP */
pusError_t pus_tc_210_41_createOspControlCommand(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 command)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_41_OspControlCommand);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_41);
		pus_tc_210_41_setParamSM_ID(outTc, smId);
		pus_tc_210_41_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_41_setParamCommand(outTc, command);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_41_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_41_OspControlCommand))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_41.smId;
}

pusError_t pus_tc_210_41_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_41_OspControlCommand))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_41.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_41_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_41_OspControlCommand))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_41.componentId;
}

pusError_t pus_tc_210_41_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_41_OspControlCommand))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_41.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_41_getParamCommand(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_41_OspControlCommand))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_41.command;
}

pusError_t pus_tc_210_41_setParamCommand(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_41_OspControlCommand))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_41.command = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_42_createCaptureImage(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_42_CaptureImage);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_42);
		pus_tc_210_42_setParamSM_ID(outTc, smId);
		pus_tc_210_42_setParamCOMP_ID(outTc, componentId);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_42_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_42_CaptureImage))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_42.smId;
}

pusError_t pus_tc_210_42_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_42_CaptureImage))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_42.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_42_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_42_CaptureImage))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_42.componentId;
}

pusError_t pus_tc_210_42_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_42_CaptureImage))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_42.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

/* BAT */
pusError_t pus_tc_210_61_createHk1Request(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_61_Hk1Request);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_61);
		pus_tc_210_61_setParamSM_ID(outTc, smId);
		pus_tc_210_61_setParamCOMP_ID(outTc, componentId);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_61_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_61_Hk1Request))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_61.smId;
}

pusError_t pus_tc_210_61_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_61_Hk1Request))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_61.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_61_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_61_Hk1Request))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_61.componentId;
}

pusError_t pus_tc_210_61_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_61_Hk1Request))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_61.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}


pusError_t pus_tc_210_62_createAllHkRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_62_AllHkRequest);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_62);
		pus_tc_210_62_setParamSM_ID(outTc, smId);
		pus_tc_210_62_setParamCOMP_ID(outTc, componentId);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_62_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_62_AllHkRequest))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_62.smId;
}

pusError_t pus_tc_210_62_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_62_AllHkRequest))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_62.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_62_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_62_AllHkRequest))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_62.componentId;
}

pusError_t pus_tc_210_62_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_62_AllHkRequest))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_62.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}


pusError_t pus_tc_210_63_createCommand48VConverter(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusBoolean conv48vCmd)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_63_Command48vConverter);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_63);
		pus_tc_210_63_setParamSM_ID(outTc, smId);
		pus_tc_210_63_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_63_setParamConv48vCmd(outTc, conv48vCmd);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_63_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_63_Command48vConverter))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_63.smId;
}

pusError_t pus_tc_210_63_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_63_Command48vConverter))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_63.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_63_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_63_Command48vConverter))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_63.componentId;
}

pusError_t pus_tc_210_63_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_63_Command48vConverter))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_63.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusBoolean pus_tc_210_63_getParamConv48vCmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_63_Command48vConverter))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_63.conv48vCmd;
}

pusError_t pus_tc_210_63_setParamConv48vCmd(pusPacket_t* outTC, asn1SccPusBoolean param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_63_Command48vConverter))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_63.conv48vCmd = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_64_createCommandBatCharger(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusBoolean batChCmd)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_64_CommandBatCharger);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_64);
		pus_tc_210_64_setParamSM_ID(outTc, smId);
		pus_tc_210_64_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_64_setParamBatChCmd(outTc, batChCmd);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_64_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_64_CommandBatCharger))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_64.smId;
}

pusError_t pus_tc_210_64_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_64_CommandBatCharger))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_64.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_64_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_64_CommandBatCharger))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_64.componentId;
}

pusError_t pus_tc_210_64_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_64_CommandBatCharger))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_64.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusBoolean pus_tc_210_64_getParamBatChCmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_64_CommandBatCharger))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_64.batChCmd;
}

pusError_t pus_tc_210_64_setParamBatChCmd(pusPacket_t* outTC, asn1SccPusBoolean param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_64_CommandBatCharger))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_64.batChCmd = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}


/* WM */
pusError_t pus_tc_210_71_createJointTrajectory(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 nSteps, asn1SccPusTC_210_71_Data_goalValues goalValues)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_71_JointTraj);
		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_71);

		outTc->data.u.tcData.data.u.st_210_71.smId = smId;
		outTc->data.u.tcData.data.u.st_210_71.componentId = componentId;
		outTc->data.u.tcData.data.u.st_210_71.nSteps = nSteps;
		outTc->data.u.tcData.data.u.st_210_71.goalValues = goalValues;

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_71_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_71_JointTraj))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_71.smId;
}

asn1SccPusUInt8 pus_tc_210_71_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_71_JointTraj))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_71.componentId;
}

asn1SccPusUInt8 pus_tc_210_71_getParamN_STEPS(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_71_JointTraj))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_71.nSteps;
}

pusError_t pus_tc_210_71_getParamGoalValues(const pusPacket_t* inTC, asn1SccPusTC_210_71_Data_goalValues *goalValues)
{
	if( (NULL == inTC) || (NULL == goalValues))
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_71_JointTraj))
	{
		return 0;
	}
	else
	{
		*goalValues = inTC->data.u.tcData.data.u.st_210_71.goalValues;
		return PUS_SET_ERROR(PUS_NO_ERROR);
	}
}

pusError_t pus_tc_210_72_createCartGoal(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusTC_210_72_Data_desiredPos desiredPos)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_72_CartGoal);
		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_72);

		outTc->data.u.tcData.data.u.st_210_72.smId = smId;
		outTc->data.u.tcData.data.u.st_210_72.componentId = componentId;
		outTc->data.u.tcData.data.u.st_210_72.desiredPos = desiredPos;

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_72_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_72_CartGoal))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_72.smId;
}

pusError_t pus_tc_210_72_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_72_CartGoal))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_72.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_72_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_72_CartGoal))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_72.componentId;
}

pusError_t pus_tc_210_72_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_72_CartGoal))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_72.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_72_getParamDesiredPos(const pusPacket_t* inTC, asn1SccPusTC_210_72_Data_desiredPos *desiredPos)
{
	if( (NULL == inTC) || (NULL == desiredPos))
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_72_CartGoal))
	{
		return PUS_GET_ERROR();
	}
	else
	{
		*desiredPos = inTC->data.u.tcData.data.u.st_210_72.desiredPos;
		return PUS_SET_ERROR(PUS_NO_ERROR);
	}
}

pusError_t pus_tc_210_72_setParamDesiredPose(pusPacket_t* outTC, asn1SccPusTC_210_72_Data_desiredPos param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_72_CartGoal))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_72.desiredPos = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_73_createInterface(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusInt32 setMode, asn1SccPusInt32 hdId, asn1SccPusInt32 manipulatorBase, asn1SccPusInt32 graspRelease)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_73_Interface);
		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_73);

		outTc->data.u.tcData.data.u.st_210_73.smId = smId;
		outTc->data.u.tcData.data.u.st_210_73.componentId = componentId;
		outTc->data.u.tcData.data.u.st_210_73.setMode = setMode;
		outTc->data.u.tcData.data.u.st_210_73.hdId = hdId;
		outTc->data.u.tcData.data.u.st_210_73.manipulatorBase = manipulatorBase;
		outTc->data.u.tcData.data.u.st_210_73.graspRelease = graspRelease;

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_73_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_73_Interface))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_73.smId;
}

pusError_t pus_tc_210_73_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_73_Interface))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_73.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_73_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_73_Interface))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_73.componentId;
}

pusError_t pus_tc_210_73_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_73_Interface))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_73.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusInt32 pus_tc_210_73_getParamSET_MODE(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_73_Interface))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_73.setMode;
}

pusError_t pus_tc_210_73_setParamMode(pusPacket_t* outTC, asn1SccPusInt32 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_73_Interface))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_73.setMode = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusInt32 pus_tc_210_73_getParamHD_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_73_Interface))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_73.hdId;
}

pusError_t pus_tc_210_73_setParamHdId(pusPacket_t* outTC, asn1SccPusInt32 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_73_Interface))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_73.hdId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusInt32 pus_tc_210_73_getParamMANIPULATOR_BASE(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_73_Interface))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_73.manipulatorBase;
}

pusError_t pus_tc_210_73_setParamManipulatorBase(pusPacket_t* outTC, asn1SccPusInt32 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_73_Interface))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_73.manipulatorBase = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusInt32 pus_tc_210_73_getParamGRASP_RELEASE(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_73_Interface))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_73.graspRelease;
}

pusError_t pus_tc_210_73_setParamGraspRelease(pusPacket_t* outTC, asn1SccPusInt32 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_73_Interface))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_73.graspRelease = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

/* THS */
pusError_t pus_tc_210_81_createModeCommand(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 targetMode)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_81_ModeCommand);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_81);
		pus_tc_210_81_setParamSM_ID(outTc, smId);
		pus_tc_210_81_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_81_setParamTargetMode(outTc, targetMode);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_81_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_81_ModeCommand))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_81.smId;
}

pusError_t pus_tc_210_81_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_81_ModeCommand))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_81.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_81_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_81_ModeCommand))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_81.componentId;
}

pusError_t pus_tc_210_81_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_81_ModeCommand))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_81.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_81_getParamTargetMode(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_81_ModeCommand))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_81.targetMode;
}

pusError_t pus_tc_210_81_setParamTargetMode(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_81_ModeCommand))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_81.targetMode = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_82_createComponentsCommand(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 componentTargetId, asn1SccPusBoolean componentTargetStatus)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_82_ComponentsCommand);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_82);
		pus_tc_210_82_setParamSM_ID(outTc, smId);
		pus_tc_210_82_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_82_setParamComponentTargetId(outTc, componentTargetId);
		pus_tc_210_82_setParamComponentTargetStatus(outTc, componentTargetStatus);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_82_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_82_ComponentsCommand))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_82.smId;
}

pusError_t pus_tc_210_82_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_82_ComponentsCommand))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_82.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_82_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_82_ComponentsCommand))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_82.componentId;
}

pusError_t pus_tc_210_82_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_82_ComponentsCommand))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_82.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_82_getParamComponentTargetId(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_82_ComponentsCommand))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_82.componentTargetId;
}

pusError_t pus_tc_210_82_setParamComponentTargetId(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_82_ComponentsCommand))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_82.componentTargetId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusBoolean pus_tc_210_82_getParamComponentTargetStatus(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_82_ComponentsCommand))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_82.componentTargetStatus;
}

pusError_t pus_tc_210_82_setParamComponentTargetStatus(pusPacket_t* outTC, asn1SccPusBoolean param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_82_ComponentsCommand))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_82.componentTargetStatus = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}


/* CPDU */
pusError_t pus_tc_210_91_createSpecificHkRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusUInt8 hkXRequest)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_91_SpecificHkRequest);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_91);
		pus_tc_210_91_setParamSM_ID(outTc, smId);
		pus_tc_210_91_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_91_setParamSUBCOMP_ID(outTc, subcomponentId);
		pus_tc_210_91_setParamHkXRequest(outTc, hkXRequest);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_91_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_91_SpecificHkRequest))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_91.smId;
}

pusError_t pus_tc_210_91_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_91_SpecificHkRequest))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_91.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_91_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_91_SpecificHkRequest))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_91.componentId;
}

pusError_t pus_tc_210_91_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_91_SpecificHkRequest))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_91.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_91_getParamSUBCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_91_SpecificHkRequest))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_91.subcomponentId;
}

pusError_t pus_tc_210_91_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_91_SpecificHkRequest))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_91.subcomponentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_91_getParamHkXRequest(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_91_SpecificHkRequest))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_91.hkXRequest;
}

pusError_t pus_tc_210_91_setParamHkXRequest(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_91_SpecificHkRequest))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_91.hkXRequest = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_92_createAllHkRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_92_AllHkRequest);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_92);
		pus_tc_210_92_setParamSM_ID(outTc, smId);
		pus_tc_210_92_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_92_setParamSUBCOMP_ID(outTc, subcomponentId);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_92_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_92_AllHkRequest))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_92.smId;
}

pusError_t pus_tc_210_92_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_92_AllHkRequest))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_92.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_92_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_92_AllHkRequest))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_92.componentId;
}

pusError_t pus_tc_210_92_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_92_AllHkRequest))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_92.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_92_getParamSUBCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_92_AllHkRequest))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_92.subcomponentId;
}

pusError_t pus_tc_210_92_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_92_AllHkRequest))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_92.subcomponentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}


pusError_t pus_tc_210_93_createCommandSwitch1(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusBoolean sw1Cmd, asn1SccPusBoolean sw2Cmd, asn1SccPusBoolean sw3Cmd, asn1SccPusBoolean sw4Cmd, asn1SccPusBoolean sw5Cmd)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_93_CommandSwitch1);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_93);
		pus_tc_210_93_setParamSM_ID(outTc, smId);
		pus_tc_210_93_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_93_setParamSUBCOMP_ID(outTc, subcomponentId);
		pus_tc_210_93_setParamSw1Cmd(outTc, sw1Cmd);
		pus_tc_210_93_setParamSw2Cmd(outTc, sw2Cmd);
		pus_tc_210_93_setParamSw3Cmd(outTc, sw3Cmd);
		pus_tc_210_93_setParamSw4Cmd(outTc, sw4Cmd);
		pus_tc_210_93_setParamSw5Cmd(outTc, sw5Cmd);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_93_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_93_CommandSwitch1))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_93.smId;
}

pusError_t pus_tc_210_93_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_93_CommandSwitch1))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_93.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_93_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_93_CommandSwitch1))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_93.componentId;
}

pusError_t pus_tc_210_93_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_93_CommandSwitch1))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_93.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_93_getParamSUBCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_93_CommandSwitch1))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_93.subcomponentId;
}

pusError_t pus_tc_210_93_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_93_CommandSwitch1))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_93.subcomponentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusBoolean pus_tc_210_93_getParamSw1Cmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_93_CommandSwitch1))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_93.sw1Cmd;
}

pusError_t pus_tc_210_93_setParamSw1Cmd(pusPacket_t* outTC, asn1SccPusBoolean param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_93_CommandSwitch1))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_93.sw1Cmd = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusBoolean pus_tc_210_93_getParamSw2Cmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_93_CommandSwitch1))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_93.sw2Cmd;
}

pusError_t pus_tc_210_93_setParamSw2Cmd(pusPacket_t* outTC, asn1SccPusBoolean param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_93_CommandSwitch1))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_93.sw2Cmd = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusBoolean pus_tc_210_93_getParamSw3Cmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_93_CommandSwitch1))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_93.sw3Cmd;
}

pusError_t pus_tc_210_93_setParamSw3Cmd(pusPacket_t* outTC, asn1SccPusBoolean param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_93_CommandSwitch1))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_93.sw3Cmd = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusBoolean pus_tc_210_93_getParamSw4Cmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_93_CommandSwitch1))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_93.sw4Cmd;
}

pusError_t pus_tc_210_93_setParamSw4Cmd(pusPacket_t* outTC, asn1SccPusBoolean param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_93_CommandSwitch1))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_93.sw4Cmd = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusBoolean pus_tc_210_93_getParamSw5Cmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_93_CommandSwitch1))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_93.sw5Cmd;
}

pusError_t pus_tc_210_93_setParamSw5Cmd(pusPacket_t* outTC, asn1SccPusBoolean param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_93_CommandSwitch1))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_93.sw5Cmd = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_94_createCommand24VConverterA(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusBoolean conv24vACmd, asn1SccPusBoolean conv24vBCmd, asn1SccPusBoolean conv12vCmd, asn1SccPusBoolean conv19vCmd)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_94_Command24vConverterA);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_94);
		pus_tc_210_94_setParamSM_ID(outTc, smId);
		pus_tc_210_94_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_94_setParamSUBCOMP_ID(outTc, subcomponentId);
		pus_tc_210_94_setParamConv24vACmd(outTc, conv24vACmd);
		pus_tc_210_94_setParamConv24vBCmd(outTc, conv24vBCmd);
		pus_tc_210_94_setParamConv12vCmd(outTc, conv12vCmd);
		pus_tc_210_94_setParamConv19vCmd(outTc, conv19vCmd);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_94_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_94_Command24vConverterA))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_94.smId;
}

pusError_t pus_tc_210_94_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_94_Command24vConverterA))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_94.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_94_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_94_Command24vConverterA))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_94.componentId;
}

pusError_t pus_tc_210_94_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_94_Command24vConverterA))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_94.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_94_getParamSUBCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_94_Command24vConverterA))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_94.subcomponentId;
}

pusError_t pus_tc_210_94_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_94_Command24vConverterA))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_94.subcomponentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusBoolean pus_tc_210_94_getParamConv24vACmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_94_Command24vConverterA))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_94.conv24vACmd;
}

pusError_t pus_tc_210_94_setParamConv24vACmd(pusPacket_t* outTC, asn1SccPusBoolean param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_94_Command24vConverterA))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_94.conv24vACmd = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusBoolean pus_tc_210_94_getParamConv24vBCmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_94_Command24vConverterA))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_94.conv24vBCmd;
}

pusError_t pus_tc_210_94_setParamConv24vBCmd(pusPacket_t* outTC, asn1SccPusBoolean param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_94_Command24vConverterA))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_94.conv24vBCmd = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusBoolean pus_tc_210_94_getParamConv12vCmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_94_Command24vConverterA))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_94.conv12vCmd;
}

pusError_t pus_tc_210_94_setParamConv12vCmd(pusPacket_t* outTC, asn1SccPusBoolean param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_94_Command24vConverterA))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_94.conv12vCmd = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusBoolean pus_tc_210_94_getParamConv19vCmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_94_Command24vConverterA))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_94.conv19vCmd;
}

pusError_t pus_tc_210_94_setParamConv19vCmd(pusPacket_t* outTC, asn1SccPusBoolean param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_94_Command24vConverterA))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_94.conv19vCmd = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_95_createSmPowerOff(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId)
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
		pus_setTcService(outTc, pus_ST210_rmapManagement);
		pus_setTcSubtype(outTc, pus_TC_210_95_SmPowerOff);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_210_95);
		pus_tc_210_95_setParamSM_ID(outTc, smId);
		pus_tc_210_95_setParamCOMP_ID(outTc, componentId);
		pus_tc_210_95_setParamSUBCOMP_ID(outTc, subcomponentId);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

asn1SccPusUInt8 pus_tc_210_95_getParamSM_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_95_SmPowerOff))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_95.smId;
}

pusError_t pus_tc_210_95_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_95_SmPowerOff))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_95.smId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_95_getParamCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_95_SmPowerOff))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}

	return inTC->data.u.tcData.data.u.st_210_95.componentId;
}

pusError_t pus_tc_210_95_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_95_SmPowerOff))
	{
		return PUS_GET_ERROR();
	}

	outTC->data.u.tcData.data.u.st_210_95.componentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

asn1SccPusUInt8 pus_tc_210_95_getParamSUBCOMP_ID(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_95_SmPowerOff))
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_95.subcomponentId;
}

pusError_t pus_tc_210_95_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_95_SmPowerOff))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_95.subcomponentId = param;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}


pusError_t pus_expectSt210Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTcHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTcService(packet);
		pusSubservice_t subtype = pus_getTcSubtype(packet);
                       
		if (service != pus_ST210_rmapManagement)
		{
			pus_setError(PUS_ERROR_TC_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TC_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[210]
		 	if (
				subtype != pus_TC_210_1_SpwRoutingTableSetEntry &&
			    subtype != pus_TC_210_2_SpwPnpSetOwnerFields &&
			    subtype != pus_TC_210_11_ConfigureTimeEpoch &&
			    subtype != pus_TC_210_12_SetLeds &&
				subtype != pus_TC_210_21_SetHouskeepingDataRate &&
			    subtype != pus_TC_210_22_GoToState &&
			    subtype != pus_TC_210_23_CommandP15vLine &&
			    subtype != pus_TC_210_24_CommandP2v5Line &&
			    subtype != pus_TC_210_25_CoomdadRelay &&
			    subtype != pus_TC_210_26_SetLvdsPins &&
			    subtype != pus_TC_210_27_PowerOnOffMotor &&
			    subtype != pus_TC_210_28_SetMotorSpeed &&
			    subtype != pus_TC_210_29_SetMotorDirection &&
			    subtype != pus_TC_210_30_SetMotorCurrentLimit &&
			    subtype != pus_TC_210_31_CalibrateController &&
			    subtype != pus_TC_210_32_ResetController &&
			    subtype != pus_TC_210_41_OspControlCommand &&
			    subtype != pus_TC_210_42_CaptureImage &&
				subtype != pus_TC_210_61_Hk1Request &&
				subtype != pus_TC_210_62_AllHkRequest &&
				subtype != pus_TC_210_63_Command48vConverter &&
				subtype != pus_TC_210_64_CommandBatCharger &&
				subtype != pus_TC_210_71_JointTraj &&
				subtype != pus_TC_210_72_CartGoal &&
				subtype != pus_TC_210_73_Interface &&
				subtype != pus_TC_210_81_ModeCommand &&
			    subtype != pus_TC_210_82_ComponentsCommand &&
			    subtype != pus_TC_210_91_SpecificHkRequest &&
			    subtype != pus_TC_210_92_AllHkRequest &&
			    subtype != pus_TC_210_93_CommandSwitch1 &&
			    subtype != pus_TC_210_94_Command24vConverterA &&
			    subtype != pus_TC_210_95_SmPowerOff
			  )
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
			kind != PusTcApplicationData_st_210_1_PRESENT &&
            kind != PusTcApplicationData_st_210_2_PRESENT &&
            kind != PusTcApplicationData_st_210_11_PRESENT &&
            kind != PusTcApplicationData_st_210_12_PRESENT &&
            kind != PusTcApplicationData_st_210_21_PRESENT &&
            kind != PusTcApplicationData_st_210_22_PRESENT &&
            kind != PusTcApplicationData_st_210_23_PRESENT &&
            kind != PusTcApplicationData_st_210_24_PRESENT &&
            kind != PusTcApplicationData_st_210_25_PRESENT &&
            kind != PusTcApplicationData_st_210_26_PRESENT &&
            kind != PusTcApplicationData_st_210_27_PRESENT &&
            kind != PusTcApplicationData_st_210_28_PRESENT &&
            kind != PusTcApplicationData_st_210_29_PRESENT &&
            kind != PusTcApplicationData_st_210_30_PRESENT &&
            kind != PusTcApplicationData_st_210_31_PRESENT &&
            kind != PusTcApplicationData_st_210_32_PRESENT &&
            kind != PusTcApplicationData_st_210_41_PRESENT &&
            kind != PusTcApplicationData_st_210_42_PRESENT &&
            kind != PusTcApplicationData_st_210_61_PRESENT &&
			kind != PusTcApplicationData_st_210_62_PRESENT &&
			kind != PusTcApplicationData_st_210_63_PRESENT &&
			kind != PusTcApplicationData_st_210_64_PRESENT &&
			kind != PusTcApplicationData_st_210_71_PRESENT &&
			kind != PusTcApplicationData_st_210_72_PRESENT &&
			kind != PusTcApplicationData_st_210_73_PRESENT &&
			kind != PusTcApplicationData_st_210_81_PRESENT &&
            kind != PusTcApplicationData_st_210_82_PRESENT &&
            kind != PusTcApplicationData_st_210_91_PRESENT &&
            kind != PusTcApplicationData_st_210_92_PRESENT &&
            kind != PusTcApplicationData_st_210_93_PRESENT &&
            kind != PusTcApplicationData_st_210_94_PRESENT &&
			kind != PusTcApplicationData_st_210_95_PRESENT &&
		    kind != pus_TC_DATA_NONE)
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

pusError_t pus_expectSt210Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTmHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTmService(packet);
		pusSubservice_t subtype = pus_getTmSubtype(packet);

		if (service != pus_ST210_rmapManagement)
		{
			pus_setError(PUS_ERROR_TM_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TM_SERVICE;
		}

		// if (expectedSubtype == pusSubtype_NONE)
		// {
		// 	// Check that subtype corresponds to ST[210]
        //     if (subtype != pus_TM_210_3_reportCurrentState)
		// 	{
		// 		pus_setError(PUS_ERROR_TM_SUBTYPE, function, (pusErrorData_t){.integer=subtype});
		// 		return PUS_ERROR_TM_SUBTYPE;
		// 	}
		// }
		// else
		// {
		// 	// Check that subtype is as expected
		// 	if (subtype != expectedSubtype)
		// 	{
		// 		pus_setError(PUS_ERROR_TM_SUBTYPE, function, (pusErrorData_t){.integer=subtype});
		// 		return PUS_ERROR_TM_SUBTYPE;
		// 	}
		// }

		// pusPacketDataKind_t kind = pus_getTmDataKind(packet);
        // if (kind != pus_TM_DATA_ST_210_3)
		// {
		// 	pus_setError(PUS_ERROR_TM_KIND, function, (pusErrorData_t){.integer=kind});
		// 	return PUS_ERROR_TM_KIND;
		// }

		return PUS_NO_ERROR;
	}
	else
	{
		return expectResult;
	}
}

#endif /* PUS_CONFIGURE_ST210_ENABLED */
