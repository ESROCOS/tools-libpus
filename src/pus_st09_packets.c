
#include "pus_st09_packets.h"
#include <math.h>


pusError_t pus_tc_9_1_createSetTimeReportRate(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt09ExponentialRate_t expRate)
{
	if (NULL == outTc )
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

		// Service identification
		pus_setTcService(outTc, pus_ST09_timeManagement);
		pus_setTcSubtype(outTc, pus_TC_9_1_setTimeReportRate);

		pus_setTcDataKind(outTc, pus_TC_DATA_ST_9_1);
		pus_tc_9_1_setExponentialRate(outTc, expRate);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusError_t pus_tm_9_2_createCucTimeReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount/*, pusApid_t destination*/)
{
	if ( NULL == outTm )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		//create package
		pus_initTmPacketNoHeader(outTm);

		// Source information
		pus_setApid(outTm, apid);
		pus_setSequenceCount(outTm, sequenceCount);

		// Data length
		pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

		// Service identification
		//pus_setTmService(outTm, pus_ST09_timeManagement);
		//pus_setTmSubtype(outTm, pus_TM_9_2_cucTimeReport);

		// Timestamp
		//pus_setTmPacketTimeNow(outTm);

		// Destination
		//pus_setTmDestination(outTm, destination);

		pus_setTmNoHeaderDataKind(outTm, pus_TM_DATA_ST_9_2);
		pus_tm_9_2_setDataField(outTm);


		return PUS_GET_ERROR();
	}
}


pusError_t pus_tc_9_1_setExponentialRate(pusPacket_t* tc, pusSt09ExponentialRate_t expRate)
{
	if ( NULL == tc )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if ( PUS_NO_ERROR != PUS_EXPECT_ST09TC(tc, pus_TC_9_1_setTimeReportRate))
	{
		return PUS_GET_ERROR();
	}

	if ( expRate > 8 )
	{
		return PUS_SET_ERROR(PUS_ERROR_OUT_OF_RANGE);
	}

	tc->data.u.tcData.data.u.st_9_1.exponentialRate = expRate;
	return PUS_NO_ERROR;
}

pusError_t pus_tc_9_1_getExponentialRate(pusSt09ExponentialRate_t* expRate, pusPacket_t* tc)
{
	if ( NULL == tc )
	{
		return PUS_ERROR_NULLPTR;
	}

	if ( PUS_NO_ERROR != PUS_EXPECT_ST09TC(tc, pus_TC_9_1_setTimeReportRate))
	{
		return PUS_GET_ERROR();
	}

	*expRate = tc->data.u.tcData.data.u.st_9_1.exponentialRate;
	return PUS_NO_ERROR;
}

pusError_t pus_tm_9_2_setDataField(pusPacket_t* tm)
{
	if ( NULL == tm )
	{
		return PUS_ERROR_NULLPTR;
	}

	if ( PUS_NO_ERROR != PUS_EXPECT_ST09TM(tm))
	{
		return PUS_GET_ERROR();
	}

	pus_time_getReportGenerationExponentialRate( &tm->data.u.tmDataNoHeader.u.st_9_2.exponentialRate );
	pus_now( &tm->data.u.tmDataNoHeader.u.st_9_2.time );

	return PUS_NO_ERROR;
}


pusError_t pus_time_getReportGenerationExponentialRate(pusSt09ExponentialRate_t* expRate)
{
	//Initialize?
	if( NULL == expRate )
	{
		return PUS_ERROR_NULLPTR;
	}

	*expRate = pus_time_reportGenerationExponentialRate;
	return PUS_NO_ERROR;
}

pusError_t pus_time_setRerportGenerationExponentialRate(pusSt09ExponentialRate_t expRate)
{
	if ( expRate > 8 )
	{
		return PUS_ERROR_OUT_OF_RANGE;
	}

	pus_time_reportGenerationExponentialRate = expRate;
	return PUS_NO_ERROR;
}

pusError_t pus_time_getReportGenerationRate(uint64_t* expRate)
{
	//Initialize?
	if( NULL == expRate )
	{
		return PUS_ERROR_NULLPTR;
	}
	//*expRate = pow(2, pus_time_reportGenerationExponentialRate); //todo math -lm

	*expRate= 1;
	for (size_t i = 0; i < pus_time_reportGenerationExponentialRate; i++)
		*expRate *= 2;


	return PUS_NO_ERROR;
}


pusError_t pus_expectSt09Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTcHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTcService(packet);
		pusSubservice_t subtype = pus_getTcSubtype(packet);

		if (service != pus_ST09_timeManagement)
		{
			pus_setError(PUS_ERROR_TC_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TC_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[09]
			if (subtype != pus_TC_9_1_setTimeReportRate)
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
		if (kind != pus_TC_DATA_ST_9_1)
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

pusError_t pus_expectSt09Tm(const pusPacket_t* packet, const char* function)
{
	pusError_t expectResult = pus_expectTmNoHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		//pusService_t service = pus_getTmService(packet);
		//pusSubservice_t subtype = pus_getTmSubtype(packet);

		/*if (service != pus_ST17_test)
		{
			pus_setError(PUS_ERROR_TM_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TM_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[17]
			if (subtype != pus_TM_17_2_connectionTest)
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
		}*/

		/*pusPacketDataKind_t kind = pus_getTmDataKind(packet);
		if (kind != pus_TM_DATA_ST_5_X)
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


