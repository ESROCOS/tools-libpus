#ifndef PUS_MISSION_SERVICES
#define PUS_MISSION_SERVICES

//Headers includes of the ASN1 types
#if(!defined(GENERATED_ASN1SCC_DATAVIEW_UNIQ_H) && !defined(GENERATED_ASN1SCC_dataview_uniq_H))
#include "pus_st200.h"
#include "pus_st201.h"
#endif


#ifdef  __cplusplus
extern "C" {
#endif

// ST200: Camera control

typedef asn1SccPusSt200ControlId pusSt200ControlId; //!< Camera control operation ID
typedef asn1SccPusSt200Observation pusSt200Observation; //!< Camera observation ID

#define pus_TC_DATA_ST_200_1		((pusTcDataKind_t) PusTcApplicationData_st_200_1_PRESENT)
#define pus_TM_DATA_ST_200_2		((pusTmDataKind_t) st_201_4_PRESENT)

// ST201: Robot move control
typedef asn1SccPusSt201Point pusSt201Point; //!< ST201 Point
typedef asn1SccPusSt201PlanObservation pusSt201PlanObservation; //!< Plan observation

typedef asn1SccPusTC_201_1_3_Data_position pusSt201Position;
typedef asn1SccPusTC_201_1_3_Data_orientation pusSt201Orientation;

#define pus_TC_DATA_ST_201_1_3		((pusTcDataKind_t) PusTcApplicationData_st_201_1_3_PRESENT)
#define pus_TM_DATA_ST_201_4		((pusTmDataKind_t) st_201_4_PRESENT)

#ifdef  __cplusplus
}
#endif


#endif
