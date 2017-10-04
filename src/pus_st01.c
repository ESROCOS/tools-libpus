#include "pus_st01.h"

#include <stddef.h>
#include <assert.h>

#include "pus_packet.h"


//
// Report field getters and setters
//

//! Set the packet version number field for a TM(1,1) report
void pus_tm_1_1_setPacketVersionNumber(pusPacket_t* tm, pusPacketVersion_t version)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pus_TM_1_1_successfulAcceptance))
	{
		tm->data.u.tmData.data.u.st_1_1.packetVersion = version;
	}
}

//! Get the packet version number field for a TM(1,1) report
pusPacketVersion_t pus_tm_1_1_getPacketVersionNumber(pusPacket_t* tm)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pus_TM_1_1_successfulAcceptance))
	{
		return tm->data.u.tmData.data.u.st_1_1.packetVersion;
	}
	else
	{
		return pus_PACKET_VERSION_CURRENT;
	}
}

//! Set the packet type field for a TM(1,1) report
void pus_tm_1_1_setPacketType(pusPacket_t* tm, pusPacketType_t type)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pus_TM_1_1_successfulAcceptance))
	{
		tm->data.u.tmData.data.u.st_1_1.packetType = type;
	}
}

//! Get the packet type field for a TM(1,1) report
pusPacketType_t pus_tm_1_1_getPacketType(pusPacket_t* tm)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pus_TM_1_1_successfulAcceptance))
	{
		return tm->data.u.tmData.data.u.st_1_1.packetType;
	}
	else
	{
		return pus_TM;
	}
}

//! Set the secondary header field for a TM(1,1) report
void pus_tm_1_1_setSecondaryHeaderFlag(pusPacket_t* tm, bool flag)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pus_TM_1_1_successfulAcceptance))
	{
		tm->data.u.tmData.data.u.st_1_1.secondaryHeaderFlag = flag;
	}
}

//! Get the secondary header field for a TM(1,1) report
bool pus_tm_1_1_getSecondaryHeaderFlag(pusPacket_t* tm)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pus_TM_1_1_successfulAcceptance))
	{
		return tm->data.u.tmData.data.u.st_1_1.secondaryHeaderFlag;
	}
	else
	{
		return false;
	}
}

//! Set the APID field for a TM(1,1) report
void pus_tm_1_1_setApid(pusPacket_t* tm, pusApid_t apid)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pus_TM_1_1_successfulAcceptance))
	{
		tm->data.u.tmData.data.u.st_1_1.apid = apid;
	}
}

//! Get the APID field for a TM(1,1) report
pusApid_t pus_tm_1_1_getApid(pusPacket_t* tm)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pus_TM_1_1_successfulAcceptance))
	{
		return tm->data.u.tmData.data.u.st_1_1.apid;
	}
	else
	{
		return pus_APID_IDLE;
	}
}

//! Set the packet sequence flags field for a TM(1,1) report
void pus_tm_1_1_setSequenceFlags(pusPacket_t* tm, pusSequenceFlags_t flags)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pus_TM_1_1_successfulAcceptance))
	{
		tm->data.u.tmData.data.u.st_1_1.sequenceFlags = flags;
	}
}

//! Get the packet sequence flags field for a TM(1,1) report
pusSequenceFlags_t pus_tm_1_1_getSequenceFlags(pusPacket_t* tm)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pus_TM_1_1_successfulAcceptance))
	{
		return tm->data.u.tmData.data.u.st_1_1.sequenceFlags;
	}
	else
	{
		return pus_STANDALONE_PACKET;
	}
}

//! Set the packet sequence count field for a TM(1,1) report
void pus_tm_1_1_setSequenceCount(pusPacket_t* tm, pusSequenceCount_t count)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pus_TM_1_1_successfulAcceptance))
	{
		tm->data.u.tmData.data.u.st_1_1.sequenceCount = count;
	}
}

//! Get the packet sequence count field for a TM(1,1) report
pusSequenceCount_t pus_tm_1_1_getSequenceCount(pusPacket_t* tm)
{
	if (PUS_NO_ERROR == PUS_EXPECT_ST01(tm, pus_TM_1_1_successfulAcceptance))
	{
		return tm->data.u.tmData.data.u.st_1_1.sequenceCount;
	}
	else
	{
		return 0;
	}
}


//
// Creation of TC acceptance report
//

pusError_t pus_tm_1_1_createAcceptanceReportSuccess(pusPacket_t* outTm, pusApidInfo_t* apid, const pusPacket_t* receivedTc)
{
	if (NULL == outTm || NULL == receivedTc)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return PUS_ERROR_NULLPTR;
	}
	else if (PUS_IS_ERROR())
	{
		return PUS_ERROR_BEFORE;
	}
	else
	{
		pus_initTmPacket(outTm);

		// Source information
		pus_setApid(outTm, pus_getInfoApid(apid));
		pus_setSequenceCount(outTm, pus_getNextTmCount(apid));

		// Data length
		pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

		// Service identification
		pus_setTmService(outTm, pus_ST01_requestVerification);
		pus_setTmSubtype(outTm, pus_TM_1_1_successfulAcceptance);

		// Destination = source of request (if has secondary header)
		bool tcHasSecondaryHeader = pus_getSecondaryHeaderFlag(receivedTc);
		if (tcHasSecondaryHeader)
		{
			pus_setTmDestination(outTm, pus_getTcSource(receivedTc));
		}
		else
		{
			pus_setTmDestination(outTm, pus_APID_IDLE);
		}

		pus_setTmDataKind(outTm, pus_TM_DATA_ST_1_1);

		// TC information
		pus_tm_1_1_setPacketVersionNumber(outTm, pus_getPacketVersion(receivedTc));
		pus_tm_1_1_setPacketType(outTm, pus_getPacketType(receivedTc));
		pus_tm_1_1_setSecondaryHeaderFlag(outTm, tcHasSecondaryHeader);
		pus_tm_1_1_setApid(outTm, pus_getApid(receivedTc));
		pus_tm_1_1_setSequenceFlags(outTm, pus_getSequenceFlags(receivedTc));
		pus_tm_1_1_setSequenceCount(outTm, pus_getSequenceCount(receivedTc));

		return PUS_GET_ERROR();
	}
}


//
// Parameter checking
//

//! Check that a packet is of a PUS ST[01] kind
pusError_t pus_expectSt01(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTmHeader(packet, function, 0);
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTmService(packet);
		pusSubservice_t subtype = pus_getTmSubtype(packet);
		pusTmDataKind_t expectedKind = pus_TM_DATA_NONE;

		if (service != pus_ST01_requestVerification)
		{
			pus_setError(PUS_ERROR_TM_SERVICE, function, service);
			return PUS_ERROR_TM_SERVICE;
		}

		if (subtype != expectedSubtype)
		{
			pus_setError(PUS_ERROR_TM_SUBTYPE, function, subtype);
			return PUS_ERROR_TM_SUBTYPE;
		}

		if (subtype == pus_TM_1_1_successfulAcceptance)
		{
			expectedKind = pus_TM_DATA_ST_1_1;
		}
		else
		{
			pus_setError(PUS_ERROR_SUBTYPE_MISMATCH, function, subtype);
			return PUS_ERROR_SUBTYPE_MISMATCH;
		}

		pusPacketDataKind_t kind = pus_getTmDataKind(packet);
		if (kind != expectedKind)
		{
			pus_setError(PUS_ERROR_TM_KIND, function, expectedKind);
			return PUS_ERROR_TM_KIND;
		}

		return PUS_NO_ERROR;
	}
	else
	{
		return expectResult;
	}
}


