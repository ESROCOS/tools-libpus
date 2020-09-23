/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pus_st220_packets.h"
#include <stdio.h>
#include <string.h>
#ifdef PUS_CONFIGURE_ST220_ENABLED

pusError_t pus_tc_220_1_createNewTargetState(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt220_stateID state)
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
		pus_setTcService(outTc, pus_ST220_reconfigurationControl);
		pus_setTcSubtype(outTc, pus_TC_220_1_setTargetState);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_220_1);
		pus_tc_220_1_setTargetState(outTc, state);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusSt220_stateID pus_tc_220_1_getTargetState(const pusPacket_t* inTC)
{
	if( NULL == inTC  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return asn1Sccidle;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST220TC(inTC, pus_TC_220_1_setTargetState))
	{
		return asn1Sccidle;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTC->data.u.tcData.data.u.st_220_1.targetState;
}

pusError_t pus_tc_220_1_setTargetState(pusPacket_t* inTC, pusSt220_stateID state)
{
	if( NULL == inTC  )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST220TC(inTC, pus_TC_220_1_setTargetState))
	{
		return 0;
	}
	
	inTC->data.u.tcData.data.u.st_220_1.targetState = state;
	
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_200_2_createGetCurrentState(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
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
		pus_setTcService(outTc, pus_ST220_reconfigurationControl);
		pus_setTcSubtype(outTc, pus_TC_220_2_getCurrentState);

		pus_setTcDataKind(outTc, pus_TC_DATA_NONE);
		outTc->data.u.tcData.data.u.st_0_0 = 0;

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}


pusError_t pus_tm_220_3_createActualStatusReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt220_stateID state)
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
		pus_setTmService(outTm, pus_ST220_reconfigurationControl);
		pus_setTmSubtype(outTm, pus_TM_220_3_reportCurrentState);

		// Set data
		pus_setTmDataKind(outTm, pus_TM_DATA_ST_220_3);
		pus_tm_220_3_setCurrentState(outTm, state);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusSt220_stateID pus_tm_220_3_getCurrentState(const pusPacket_t* inTm)
{
	if( NULL == inTm  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return asn1Sccidle;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST220TM(inTm, pus_TM_220_3_reportCurrentState))
	{
		return asn1Sccidle;
	}
	else
	{
		PUS_SET_ERROR(PUS_NO_ERROR);
	}
	
	return inTm->data.u.tmData.data.u.st_220_3.actual;
}

pusError_t pus_tm_220_3_setCurrentState(pusPacket_t* inTm, pusSt220_stateID state)
{
	if( NULL == inTm  )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST220TM(inTm, pus_TM_220_3_reportCurrentState))
	{
		return 0;
	}
	
	inTm->data.u.tmData.data.u.st_220_3.actual = state;
	
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_expectSt220Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
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
			if (subtype != pus_TC_220_1_setTargetState &&  
                subtype != pus_TC_220_2_getCurrentState)
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
        if (kind != pus_TC_DATA_ST_220_1 &&
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

pusError_t pus_expectSt220Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
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
			// Check that subtype corresponds to ST[220]
            if (subtype != pus_TM_220_3_reportCurrentState)
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
        if (kind != pus_TM_DATA_ST_220_3)
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