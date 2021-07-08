/* Body file for function Ground
 * Generated by TASTE on 2021-07-05 17:17:23
 * You can edit this file, it will not be overwritten
 * Provided interfaces : newTm, triggerTmGUI
 * Required interfaces : newTc
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 79368 65667 105509 89131
 * Timers              : 
 */
#include <stdlib.h>
#ifdef __unix__
   #include <stdio.h>
   #include "PrintTypesAsASN1.h"
   #include "timeInMS.h"
#endif
#include "C_ASN1_Types.h"
#include "dataview-uniq.h"

// reference to flag preventing calls to RIs during the startup transition
extern unsigned ground_initialized;
// in case that happens, use system's abort function to crash the application
extern void abort (void);

void ground_RI_newTc
      (const asn1SccPusPacket *IN_tcpacket)

{
   // Check that we are not in the startup transition
   if (2 != ground_initialized) {
      #ifdef __unix__
         puts("A call to ground_RI_newTc was made during system startup.");
         puts("This is not allowed because the system is not yet fully initialized. Please fix your code/models");
      #endif
      // crash the application
      abort();
   }

   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1PusPacket ("INNERDATA: newtc::PusPacket::tcpacket", IN_tcpacket);
         puts(""); // add newline
         // Log message to PusServices (corresponding PI: newTc)
         printf ("INNER: ground,pusservices,newtc,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter tcPacket
   static asn1SccPusPacket IN_buf_tcpacket;
   int size_IN_buf_tcpacket =
      Encode_NATIVE_PusPacket
        ((void *)&IN_buf_tcpacket,
          sizeof(asn1SccPusPacket),
          (asn1SccPusPacket *)IN_tcpacket);
   if (-1 == size_IN_buf_tcpacket) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in ground_RI_newTc, parameter tcPacket");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_ground_newtc
     (void *, size_t);

   vm_ground_newtc
     ((void *)&IN_buf_tcpacket, (size_t)size_IN_buf_tcpacket);


}

