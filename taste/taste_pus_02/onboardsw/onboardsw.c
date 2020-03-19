/* User code: This file will not be overwritten by TASTE. */

#include "onboardsw.h"

void onboardsw_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void onboardsw_PI_trigger()
{
    /* Write your code here! */
    //static asn1SccPusSt05Event myEvent;
    //myEvent.eventId = 1;
    //onboardsw_RI_pushNewEvent(&myEvent);

    
    static asn1SccPusSt03ParameterId paramId = 0;
    static asn1SccPusSt03StoredParam paramValue = 70;
    onboardsw_RI_setParamValue(&paramId,
                               &paramValue);

    static asn1SccPusSt03ParameterId paramId2 = 0;
    static asn1SccPusSt03StoredParam paramValue2;
    static asn1SccPusSt01FailureCode failureCode;
	onboardsw_RI_getParamValue(&paramId2,
                               &paramValue2,
                               &failureCode);

	static asn1SccPusSt20OnBoardParameterId paramId3 = 1;
	static asn1SccPusSt20StoredParam paramValue3 = 1;
	onboardsw_RI_setOnBoardParam(&paramId3,
                                 &paramValue3);

	static asn1SccPusSt20OnBoardParameterId paramId4 = 1;
	static asn1SccPusSt20StoredParam paramValue4 = 1;
	static asn1SccPusSt01FailureCode failureCode2 = 2;
	onboardsw_RI_getOnBoardParam(&paramId4,
                                 &paramValue4,
                                 &failureCode2);
}

