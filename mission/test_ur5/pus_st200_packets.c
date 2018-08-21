/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pus_st200_packets.h"
#ifdef PUS_CONFIGURE_ST200_ENABLED


pusError_t pus_tc_200_1_createControlCameraRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt200ControlId operation)
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
		pus_setTcService(outTc, pus_ST200_cameraControl);
		pus_setTcSubtype(outTc, pus_TC_200_1_controlRequest);

		//TODO set data
		pus_setTcDataKind(outTc, pus_TC_DATA_ST_200_1);
		pus_tc_200_1_setControlId(outTc, operation);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusError_t pus_tm_200_2_createControlCameraReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt200Observation observation)
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
		pus_setTmService(outTm, pus_ST200_cameraControl);
		pus_setTmSubtype(outTm, pus_TM_200_2_controlReport);

		//TODO set data
		pus_tm_200_2_setObservation(outTm, observation);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}


pusError_t pus_tc_200_1_setControlId(pusPacket_t* outTc, pusSt200ControlId operation)
{
	if( NULL == outTc  )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST200TC(outTc, pus_TC_200_1_controlRequest))
	{
		return PUS_GET_ERROR();
	}
	outTc->data.u.tcData.data.u.st_200_1.controlId = operation;

	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusSt200ControlId pus_tc_200_1_getControlId(const pusPacket_t* inTc)
{
	if( NULL == inTc  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return -1;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST200TC(inTc, pus_TC_200_1_controlRequest))
	{
		return -1;
	}

	PUS_SET_ERROR(PUS_NO_ERROR);
	return inTc->data.u.tcData.data.u.st_200_1.controlId;
}


pusError_t pus_tm_200_2_setObservation(pusPacket_t* outTm, pusSt200Observation observation)
{
	if( NULL == outTm  )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST200TM(outTm, pus_TM_200_2_controlReport))
	{
		return PUS_GET_ERROR();
	}
	outTm->data.u.tmData.data.u.st_200_2.observation = observation;

	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusSt200Observation pus_tm_200_2_getObservation(const pusPacket_t* inTM)
{
	if( NULL == inTM  )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return -1;
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST200TM(inTM, pus_TM_200_2_controlReport))
	{
		return -1;
	}

	PUS_SET_ERROR(PUS_NO_ERROR);
	return inTM->data.u.tmData.data.u.st_200_2.observation;
}

pusError_t pus_expectSt200Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTcHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTcService(packet);
		pusSubservice_t subtype = pus_getTcSubtype(packet);

		if (service != pus_ST200_cameraControl)
		{
			pus_setError(PUS_ERROR_TC_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TC_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[200]
			if (subtype != pus_TC_200_1_controlRequest)
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
		if (kind != pus_TC_DATA_ST_200_1 )
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

		if (service != pus_ST200_cameraControl)
		{
			pus_setError(PUS_ERROR_TM_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TM_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[200]
			if (subtype != pus_TM_200_2_controlReport)
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
		if (kind != pus_TM_DATA_ST_200_2)
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
