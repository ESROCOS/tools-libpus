#ifndef PUS_ST01_H
#define PUS_ST01_H

#include "pus_types.h"
#include "pus_error.h"

//
// Creation of TC acceptance report
//

//! Build an acceptance report for a TC
pusError_t pus_tm_1_1_createAcceptanceReportSuccess(pusPacket_t* tm, const pusPacket_t* receivedTc);


//
// Report field (of the verified TC) getters and setters
//

//! Set the packet version number field (of the verified TC) for a TM(1,1) report
void pus_tm_1_1_setPacketVersionNumber(pusPacket_t* tm, pusPacketVersion_t version);

//! Get the packet version number field (of the verified TC) for a TM(1,1) report
pusPacketVersion_t pus_tm_1_1_getPacketVersionNumber(pusPacket_t* tm);

//! Set the packet type field (of the verified TC) for a TM(1,1) report
void pus_tm_1_1_setPacketType(pusPacket_t* tm, pusPacketType_t type);

//! Get the packet type field (of the verified TC) for a TM(1,1) report
pusPacketType_t pus_tm_1_1_getPacketType(pusPacket_t* tm);

//! Set the secondary header field (of the verified TC) for a TM(1,1) report
void pus_tm_1_1_setSecondaryHeaderFlag(pusPacket_t* tm, bool flag);

//! Get the secondary header field (of the verified TC) for a TM(1,1) report
bool pus_tm_1_1_getSecondaryHeaderFlag(pusPacket_t* tm);

//! Set the APID field (of the verified TC) for a TM(1,1) report
void pus_tm_1_1_setApid(pusPacket_t* tm, pusApid_t apid);

//! Get the APID field (of the verified TC) for a TM(1,1) report
pusApid_t pus_tm_1_1_getApid(pusPacket_t* tm);

//! Set the packet sequence flags field (of the verified TC) for a TM(1,1) report
void pus_tm_1_1_setSequenceFlags(pusPacket_t* tm, pusSequenceFlags_t flags);

//! Get the packet sequence flags field (of the verified TC) for a TM(1,1) report
pusSequenceFlags_t pus_tm_1_1_getSequenceFlags(pusPacket_t* tm);

//! Set the packet sequence count field (of the verified TC) for a TM(1,1) report
void pus_tm_1_1_setSequenceCount(pusPacket_t* tm, pusSequenceCount_t count);

//! Get the packet sequence count field (of the verified TC) for a TM(1,1) report
pusSequenceCount_t pus_tm_1_1_getSequenceCount(pusPacket_t* tm);





//
// Parameter checking
//

//! Check that a packet is of a PUS ST[01] kind
pusError_t pus_expectSt01(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);

//! Helper macro for pus_expectSt01; adds function name
#define PUS_EXPECT_ST01(packet, subtype) pus_expectSt01((packet), (subtype), __func__)


#endif // PUS_ST01_H
