#include "pus_st11_packets.h"


pusError_t pus_tc_11_X_createDefaultPacket(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSubservice_t subtype)
{
	if (NULL == outTc)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_initTcPacket(outTc);

		// Source information
		pus_setApid(outTc, apid);
		pus_setSequenceCount(outTc, sequenceCount);

		// Data length
		pus_setPacketDataLength(outTc, sizeof(pusPacketData_t));

		pus_setTcService(outTc, pus_ST11_timeBasedScheduling);
		pus_setTcSubtype(outTc, subtype);
		pus_setTcSource(outTc, apid);


		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusError_t pus_tc_11_1_createEnableTimeBasedSchedule(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
	if( NULL == outTc)
	{
		return PUS_ERROR_NULLPTR;
	}

	if( PUS_NO_ERROR != pus_tc_11_X_createDefaultPacket(outTc, apid, sequenceCount, pus_TC_11_1_enableTimeBasedScheduling) )
	{
		return PUS_GET_ERROR();
	}
	pus_setTcDataKind(outTc, pus_TC_DATA_NONE);

	return PUS_NO_ERROR;
}

pusError_t pus_tc_11_2_createDisableTimeBasedSchedule(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
	if( NULL == outTc)
	{
		return PUS_ERROR_NULLPTR;
	}
	if( PUS_NO_ERROR != pus_tc_11_X_createDefaultPacket(outTc, apid, sequenceCount, pus_TC_11_2_disableTimeBasedScheduling) )
	{
		return PUS_GET_ERROR();
	}

	pus_setTcDataKind(outTc, pus_TC_DATA_NONE);

	return PUS_NO_ERROR;
}


pusError_t pus_tc_11_3_createResetTimeBasedSchedule(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
	if( NULL == outTc)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != pus_tc_11_X_createDefaultPacket(outTc, apid, sequenceCount, pus_TC_11_3_resetTimeBasedSchedule) )
	{
		return PUS_GET_ERROR();
	}
	pus_setTcDataKind(outTc, pus_TC_DATA_NONE);

	return PUS_NO_ERROR;
}

pusError_t pus_tc_11_4_createInsertActivityIntoSchedule(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, uint32_t nCount, const pusSt11ScheduledActivity_t* activities)
{
	if( NULL == outTc || NULL == activities)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR != pus_tc_11_X_createDefaultPacket(outTc, apid, sequenceCount, pus_TC_11_4_insertActivity) )
	{
		return PUS_GET_ERROR();
	}

	//TODO Data field
	// n_packets
	// pusPacketReduced_t* array;
	pus_setTcDataKind(outTc, pus_TC_DATA_ST_11_4);
	pus_tc_11_4_setActivities(outTc, nCount, activities);

	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_11_4_setActivities(pusPacket_t* outTc, int32_t nCount, const pusSt11ScheduledActivity_t* activities)
{
	if( NULL == outTc || NULL == activities)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR == PUS_EXPECT_ST11TC(outTc, pus_TC_DATA_ST_11_4))
	{
		return PUS_GET_ERROR();
	}

	outTc->data.u.tcData.data.u.st_11_4.nCount = nCount;
	for(int32_t i = 0; i<nCount; i++)
	{
		outTc->data.u.tcData.data.u.st_11_4.arr[0].packetReduced = activities[0].packetReduced;
		outTc->data.u.tcData.data.u.st_11_4.arr[0].time = activities[0].time;
	}
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_tc_11_4_getActivities(int32_t* nCount, pusSt11ScheduledActivity_t* activities, const pusPacket_t* outTc, int32_t max)
{
	if( NULL == outTc || NULL == activities)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR == PUS_EXPECT_ST11TC(outTc, pus_TC_DATA_ST_11_4))
	{
		return PUS_GET_ERROR();
	}

	*nCount = outTc->data.u.tcData.data.u.st_11_4.nCount;

	if( *nCount > max)
	{
		return PUS_SET_ERROR(PUS_ERROR_OUT_OF_RANGE);
	}

	for(int32_t i = 0; i < *nCount; i++)
	{
		activities[0].packetReduced = outTc->data.u.tcData.data.u.st_11_4.arr[0].packetReduced ;
		activities[0].time = outTc->data.u.tcData.data.u.st_11_4.arr[0].time;
	}
	return PUS_SET_ERROR(PUS_NO_ERROR);
}


//
// Parameter checking
//
pusError_t pus_expectSt11Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTcHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTcService(packet);
		pusSubservice_t subtype = pus_getTcSubtype(packet);

		if (service != pus_ST11_timeBasedScheduling)
		{
			pus_setError(PUS_ERROR_TC_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TC_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[11]
			if ((subtype != pus_TC_11_1_enableTimeBasedScheduling) &&
				(subtype != pus_TC_11_2_disableTimeBasedScheduling) &&
				(subtype != pus_TC_11_3_resetTimeBasedSchedule) &&
				(subtype != pus_TC_11_4_insertActivity))
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

		/* TODO
		 * pusPacketDataKind_t kind = pus_getTcDataKind(packet);
		if (kind != pus_TC_DATA_ST_12_1_2 && kind != pus_TC_DATA_NONE)
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
