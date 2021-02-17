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
pusError_t pus_tc_210_1_createSpwRoutingTableSetEntry(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt16 setRoutingEntry, asn1SccPusUInt8 spwTrafficPriority)
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
		pus_tc_210_1_setParamSetRoutingEntry(outTc, setRoutingEntry);
		pus_tc_210_1_setParamSpwTrafficPriority(outTc, spwTrafficPriority);

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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_1_SpwRoutingTableSetEntry)) // TODO
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

asn1SccPusUInt16 pus_tc_210_1_getParamSetRoutingEntry(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_1_SpwRoutingTableSetEntry)) // TODO
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_1.setRoutingEntry; // TODO - check ASN1 names
}

pusError_t pus_tc_210_1_setParamSetRoutingEntry(pusPacket_t* outTC, asn1SccPusUInt16 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_1_SpwRoutingTableSetEntry))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_1.setRoutingEntry = param; // TODO - check ASN1 names
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusUInt8 pus_tc_210_1_getParamSpwTrafficPriority(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_1_SpwRoutingTableSetEntry)) // TODO
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_1.spwTrafficPriority; // TODO - check ASN1 names
}

pusError_t pus_tc_210_1_setParamSpwTrafficPriority(pusPacket_t* outTC, asn1SccPusUInt8 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_1_SpwRoutingTableSetEntry))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_1.spwTrafficPriority = param; // TODO - check ASN1 names
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_210_2_createSpwPnpSetOwnerFields(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt16 setOwner)
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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_2_SpwPnpSetOwnerFields)) // TODO
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

asn1SccPusUInt16 pus_tc_210_2_getParamSetOwner(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_2_SpwPnpSetOwnerFields)) // TODO
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_2.setOwner; // TODO - check ASN1 names
}

pusError_t pus_tc_210_2_setParamSetOwner(pusPacket_t* outTC, asn1SccPusUInt16 param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_2_SpwPnpSetOwnerFields))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_2.setOwner = param; // TODO - check ASN1 names
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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_11_ConfigureTimeEpoch)) // TODO
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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_11_ConfigureTimeEpoch)) // TODO
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_11.secsSinceEpoch; // TODO - check ASN1 names
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
	
	outTC->data.u.tcData.data.u.st_210_11.secsSinceEpoch = param; // TODO - check ASN1 names
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusInt32 pus_tc_210_11_getParamNanosecsSinceEpoch(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_11_ConfigureTimeEpoch)) // TODO
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_11.nanosecsSinceEpoch; // TODO - check ASN1 names
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
	
	outTC->data.u.tcData.data.u.st_210_11.nanosecsSinceEpoch = param; // TODO - check ASN1 names
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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_12_SetLeds)) // TODO
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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_12_SetLeds)) // TODO
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_12.setLeds; // TODO - check ASN1 names
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
	
	outTC->data.u.tcData.data.u.st_210_12.setLeds = param; // TODO - check ASN1 names
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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_81_ModeCommand)) // TODO
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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_81_ModeCommand)) // TODO
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_81.targetMode; // TODO - check ASN1 names
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
	
	outTC->data.u.tcData.data.u.st_210_81.targetMode = param; // TODO - check ASN1 names
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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_82_ComponentsCommand)) // TODO
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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_82_ComponentsCommand)) // TODO
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_82.componentTargetId; // TODO - check ASN1 names
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
	
	outTC->data.u.tcData.data.u.st_210_82.componentTargetId = param; // TODO - check ASN1 names
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusBoolean pus_tc_210_82_getParamComponentTargetStatus(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_82_ComponentsCommand)) // TODO
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_82.componentTargetStatus; // TODO - check ASN1 names
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
	
	outTC->data.u.tcData.data.u.st_210_82.componentTargetStatus = param; // TODO - check ASN1 names
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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_91_SpecificHkRequest)) // TODO
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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_91_SpecificHkRequest)) // TODO
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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_91_SpecificHkRequest)) // TODO
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_91.hkXRequest; // TODO - check ASN1 names
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
	
	outTC->data.u.tcData.data.u.st_210_91.hkXRequest = param; // TODO - check ASN1 names
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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_92_AllHkRequest)) // TODO
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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_92_AllHkRequest)) // TODO
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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_93_CommandSwitch1)) // TODO
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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_93_CommandSwitch1)) // TODO
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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_93_CommandSwitch1)) // TODO
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_93.sw1Cmd; // TODO - check ASN1 names
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
	
	outTC->data.u.tcData.data.u.st_210_93.sw1Cmd = param; // TODO - check ASN1 names
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusBoolean pus_tc_210_93_getParamSw2Cmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_93_CommandSwitch1)) // TODO
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_93.sw2Cmd; // TODO - check ASN1 names
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
	
	outTC->data.u.tcData.data.u.st_210_93.sw2Cmd = param; // TODO - check ASN1 names
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusBoolean pus_tc_210_93_getParamSw3Cmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_93_CommandSwitch1)) // TODO
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_93.sw3Cmd; // TODO - check ASN1 names
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
	
	outTC->data.u.tcData.data.u.st_210_93.sw3Cmd = param; // TODO - check ASN1 names
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusBoolean pus_tc_210_93_getParamSw4Cmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_93_CommandSwitch1)) // TODO
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_93.sw4Cmd; // TODO - check ASN1 names
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
	
	outTC->data.u.tcData.data.u.st_210_93.sw4Cmd = param; // TODO - check ASN1 names
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusBoolean pus_tc_210_93_getParamSw5Cmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_93_CommandSwitch1)) // TODO
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_93.sw5Cmd; // TODO - check ASN1 names
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
	
	outTC->data.u.tcData.data.u.st_210_93.sw5Cmd = param; // TODO - check ASN1 names
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
		pus_setTcSubtype(outTc, pus_TC_210_94_Command24VConverterA);

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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_94_Command24VConverterA)) // TODO
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
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_94_Command24VConverterA))
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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_94_Command24VConverterA))
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
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_94_Command24VConverterA))
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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_94_Command24VConverterA)) // TODO
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
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_94_Command24VConverterA))
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
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_94_Command24VConverterA)) // TODO
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_94.conv24vACmd; // TODO - check ASN1 names
}

pusError_t pus_tc_210_94_setParamConv24vACmd(pusPacket_t* outTC, asn1SccPusBoolean param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_94_Command24VConverterA))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_94.conv24vACmd = param; // TODO - check ASN1 names
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusBoolean pus_tc_210_94_getParamConv24vBCmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_94_Command24VConverterA)) // TODO
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_94.conv24vBCmd; // TODO - check ASN1 names
}

pusError_t pus_tc_210_94_setParamConv24vBCmd(pusPacket_t* outTC, asn1SccPusBoolean param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_94_Command24VConverterA))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_94.conv24vBCmd = param; // TODO - check ASN1 names
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusBoolean pus_tc_210_94_getParamConv12vCmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_94_Command24VConverterA)) // TODO
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_94.conv12vCmd; // TODO - check ASN1 names
}

pusError_t pus_tc_210_94_setParamConv12vCmd(pusPacket_t* outTC, asn1SccPusBoolean param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_94_Command24VConverterA))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_94.conv12vCmd = param; // TODO - check ASN1 names
	return PUS_SET_ERROR(PUS_NO_ERROR);
}
asn1SccPusBoolean pus_tc_210_94_getParamConv19vCmd(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST210TC(inTC, pus_TC_210_94_Command24VConverterA)) // TODO
	{
		return 0;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_210_94.conv19vCmd; // TODO - check ASN1 names
}

pusError_t pus_tc_210_94_setParamConv19vCmd(pusPacket_t* outTC, asn1SccPusBoolean param)
{
	if(NULL == outTC)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if(PUS_NO_ERROR != PUS_EXPECT_ST210TC(outTC, pus_TC_210_94_Command24VConverterA))
	{
		return PUS_GET_ERROR();
	}
	
	outTC->data.u.tcData.data.u.st_210_94.conv19vCmd = param; // TODO - check ASN1 names
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
				subtype != pus_TC_210_81_ModeCommand &&
			    subtype != pus_TC_210_82_ComponentsCommand &&
			    subtype != pus_TC_210_91_SpecificHkRequest &&
			    subtype != pus_TC_210_92_AllHkRequest &&
			    subtype != pus_TC_210_93_CommandSwitch1 &&
			    subtype != pus_TC_210_94_Command24VConverterA
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
			kind != PusTcApplicationData_st_210_81_PRESENT &&
            kind != PusTcApplicationData_st_210_82_PRESENT &&
            kind != PusTcApplicationData_st_210_91_PRESENT &&
            kind != PusTcApplicationData_st_210_92_PRESENT &&
            kind != PusTcApplicationData_st_210_93_PRESENT &&
            kind != PusTcApplicationData_st_210_94_PRESENT &&
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
