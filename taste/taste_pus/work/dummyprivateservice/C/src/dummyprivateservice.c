/* Body file for function DummyPrivateService
 * Generated by TASTE on 2020-05-21 12:14:37
 * You can edit this file, it will not be overwritten
 * Provided interfaces : addTc
 * Required interfaces : ack, addTm
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 134437 32417 177819 47196
 * Timers              : 
 */

#include "dummyprivateservice.h"
//#include <stdio.h>


void dummyprivateservice_startup(void)
{
   // Write your initialisation code, but DO NOT CALL REQUIRED INTERFACES
   // puts ("[DummyPrivateService] Startup");
}

void dummyprivateservice_PI_forwardTc
      (const asn1SccPusPacket *IN_tcpacket)

{
   // Write your code here
   printf("[DUMMY privates] packet received: ");
   PrintPusPacket("[DUMMY privates]", IN_tcpacket);
}


