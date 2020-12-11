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
			    subtype != pus_TC_210_12_SetLeds
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
