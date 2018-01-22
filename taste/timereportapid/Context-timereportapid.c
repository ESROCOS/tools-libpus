/*
Code automatically generated by asn1scc tool
*/
#include <limits.h>
#include <string.h>
#include <math.h>
#include "Context-timereportapid.h"

#if !defined(_MSC_VER) || _MSC_VER >= 1800
void asn1SccContext_timereportapid_Initialize(asn1SccContext_timereportapid* pVal)
{
    *pVal = (asn1SccContext_timereportapid) {
    .apid = 0
};
}
#endif

 
flag asn1SccContext_timereportapid_IsConstraintValid(const asn1SccContext_timereportapid* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = asn1SccPusApid_IsConstraintValid(&pVal->apid, pErrCode);


	return ret;
}

const asn1SccContext_timereportapid timereportapid_ctxt = {
    .apid = 2
};