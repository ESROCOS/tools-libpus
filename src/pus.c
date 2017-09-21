#include "pus_types.h"


int dummy(int a)
{
    pusPacket_t p;
    p.apid = a;
    return p.apid;
}

