// Test program

#include <stdio.h>

#include "pus_types.h"


int main()
{
    pusPacket_t p;
    printf("size of CCSDS packet is %ld bytes \n", sizeof(p));
    
    return 0;
}
