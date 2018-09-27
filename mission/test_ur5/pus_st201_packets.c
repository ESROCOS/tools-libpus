/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pus_st201_packets.h"
#ifdef PUS_CONFIGURE_ST201_ENABLED


pusError_t pus_tc_201_1_createSetHomeRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt201Position* position, pusSt201Orientation* orientation)
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
		pus_setTcService(outTc, pus_ST201_robotMoveControl);
		pus_setTcSubtype(outTc, pus_TC_201_1_setHomeRequest);

		// set data
		pus_setTcDataKind(outTc, pus_TC_DATA_ST_201_1_3);
		pus_tc_201_1_3_setOrientationPoints(outTc, orientation->arr[0], orientation->arr[1], orientation->arr[2], orientation->arr[3]);
		pus_tc_201_1_3_setPositionPoints(outTc, position->arr[0], position->arr[1], position->arr[2]);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusError_t pus_tc_201_2_createPlanHomeRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
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
		pus_setTcService(outTc, pus_ST201_robotMoveControl);
		pus_setTcSubtype(outTc, pus_TC_201_2_planHomeRequest);

		pus_setTcDataKind(outTc, pus_TC_DATA_NONE);
		outTc->data.u.tcData.data.u.st_0_0 = 0;

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusError_t pus_tc_201_3_createPlanMoveRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt201Position* position, pusSt201Orientation* orientation)
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
		pus_setTcService(outTc, pus_ST201_robotMoveControl);
		pus_setTcSubtype(outTc, pus_TC_201_3_planMoveRequest);

		// Set data
		pus_setTcDataKind(outTc, pus_TC_DATA_ST_201_1_3);
		pus_tc_201_1_3_setOrientationPoints(outTc, orientation->arr[0], orientation->arr[1], orientation->arr[2], orientation->arr[3]);
		pus_tc_201_1_3_setPositionPoints(outTc, position->arr[0], position->arr[1], position->arr[2]);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusError_t pus_tm_201_4_createPlanReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, const pusSt201PlanObservation* observation)
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
		pus_setTmService(outTm, pus_ST201_robotMoveControl);
		pus_setTmSubtype(outTm, pus_TM_201_4_planReport);


		//TODO set data
		pus_setTmDataKind(outTm, pus_TM_DATA_ST_201_4);
		pus_tm_201_4_setPlanObservation(outTm, observation);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}


pusError_t pus_tc_201_1_3_setOrientationPoints(pusPacket_t* outTc, pusSt201Point point1, pusSt201Point point2, pusSt201Point point3, pusSt201Point point4)
{
	if( NULL == outTc  )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST201TC(outTc, pusSubtype_NONE))
	{
		return PUS_GET_ERROR();
	}

	if( pus_TC_DATA_ST_201_1_3 == pus_getTcDataKind(outTc) )
	{
		outTc->data.u.tcData.data.u.st_201_1_3.orientation.arr[0] = point1;
		outTc->data.u.tcData.data.u.st_201_1_3.orientation.arr[1] = point2;
		outTc->data.u.tcData.data.u.st_201_1_3.orientation.arr[2] = point3;
		outTc->data.u.tcData.data.u.st_201_1_3.orientation.arr[3] = point4;
		return PUS_NO_ERROR;
	}
	else
	{
		return PUS_SET_ERROR(PUS_ERROR_SUBTYPE_MISMATCH);
	}
}

pusError_t pus_tc_201_1_3_getOrientationPoints(pusSt201Point* point1, pusSt201Point* point2, pusSt201Point* point3, pusSt201Point* point4, const pusPacket_t* inTc)
{
	if( NULL == inTc  )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST201TC(inTc, pusSubtype_NONE))
	{
		return PUS_GET_ERROR();
	}

	if( pus_TC_DATA_ST_201_1_3 == pus_getTcDataKind(inTc) )
	{
		*point1 = inTc->data.u.tcData.data.u.st_201_1_3.orientation.arr[0];
		*point2 = inTc->data.u.tcData.data.u.st_201_1_3.orientation.arr[1];
		*point3 = inTc->data.u.tcData.data.u.st_201_1_3.orientation.arr[2];
		*point4 = inTc->data.u.tcData.data.u.st_201_1_3.orientation.arr[3];
		return PUS_NO_ERROR;
	}
	else
	{
		return PUS_SET_ERROR(PUS_ERROR_SUBTYPE_MISMATCH);
	}
}

pusError_t pus_tc_201_1_3_setPositionPoints(pusPacket_t* outTc, pusSt201Point point1, pusSt201Point point2, pusSt201Point point3)
{
	if( NULL == outTc  )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST201TC(outTc, pusSubtype_NONE))
	{
		return PUS_GET_ERROR();
	}

	if( pus_TC_DATA_ST_201_1_3 == pus_getTcDataKind(outTc) )
	{
		outTc->data.u.tcData.data.u.st_201_1_3.position.arr[0] = point1;
		outTc->data.u.tcData.data.u.st_201_1_3.position.arr[1] = point2;
		outTc->data.u.tcData.data.u.st_201_1_3.position.arr[2] = point3;
		return PUS_NO_ERROR;
	}
	else
	{
		return PUS_SET_ERROR(PUS_ERROR_SUBTYPE_MISMATCH);
	}
}

pusError_t pus_tc_201_1_3_getPositionPoints(pusSt201Point* point1, pusSt201Point* point2, pusSt201Point* point3, const pusPacket_t* inTc)
{
	if( NULL == inTc  )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST201TC(inTc, pusSubtype_NONE))
	{
		return PUS_GET_ERROR();
	}

	if( pus_TC_DATA_ST_201_1_3 == pus_getTcDataKind(inTc) )
	{
		*point1 = inTc->data.u.tcData.data.u.st_201_1_3.position.arr[0];
		*point2 = inTc->data.u.tcData.data.u.st_201_1_3.position.arr[1];
		*point3 = inTc->data.u.tcData.data.u.st_201_1_3.position.arr[2];
		return PUS_NO_ERROR;
	}
	else
	{
		return PUS_SET_ERROR(PUS_ERROR_SUBTYPE_MISMATCH);
	}
}

pusError_t pus_tm_201_4_setPlanObservation(pusPacket_t* outTm, const pusSt201PlanObservation* observation)
{
	if( NULL == outTm  )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST201TM(outTm, pus_TM_201_4_planReport))
	{
		return PUS_GET_ERROR();
	}
	outTm->data.u.tmData.data.u.st_201_4.observation.id = observation->id;
	outTm->data.u.tmData.data.u.st_201_4.observation.code = observation->code;

	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tm_201_4_getPlanObservation(pusSt201PlanObservation* observation, const pusPacket_t* inTM)
{
	if( NULL == inTM  )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != PUS_EXPECT_ST201TM(inTM, pus_TM_201_4_planReport))
	{
		return PUS_GET_ERROR();
	}
	observation->id = inTM->data.u.tmData.data.u.st_201_4.observation.id;
	observation->code = inTM->data.u.tmData.data.u.st_201_4.observation.code;

	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_expectSt201Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTcHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTcService(packet);
		pusSubservice_t subtype = pus_getTcSubtype(packet);

		if (service != pus_ST201_robotMoveControl)
		{
			pus_setError(PUS_ERROR_TC_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TC_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[200]
			if ((subtype != pus_TC_201_1_setHomeRequest) && (subtype != pus_TC_201_2_planHomeRequest) && (subtype != pus_TC_201_3_planMoveRequest))
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

		/*pusPacketDataKind_t kind = pus_getTcDataKind(packet);
		if ((kind != pus_TC_DATA_ST_200_1) && (kind != pus_TC_DATA_NONE ))
		{
			pus_setError(PUS_ERROR_TC_KIND, function, (pusErrorData_t){.integer=kind});
			return PUS_ERROR_TC_KIND;
		}*/

		return PUS_NO_ERROR;
	}
	else
	{
		return expectResult;
	}
}

pusError_t pus_expectSt201Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTmHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTmService(packet);
		pusSubservice_t subtype = pus_getTmSubtype(packet);

		if (service != pus_ST201_robotMoveControl)
		{
			pus_setError(PUS_ERROR_TM_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TM_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[200]
			if (subtype != pus_TM_201_4_planReport)
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

		/*pusPacketDataKind_t kind = pus_getTmDataKind(packet);
		if (kind != pus_TM_DATA_ST_201)
		{
			pus_setError(PUS_ERROR_TM_KIND, function, (pusErrorData_t){.integer=kind});
			return PUS_ERROR_TM_KIND;
		}*/

		return PUS_NO_ERROR;
	}
	else
	{
		return expectResult;
	}
}

#endif
