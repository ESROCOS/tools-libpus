# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

#check the param value#import fun.py 

import micropython, gc

class ObcpTest(Obcp):
    
    def main(self):
        print("- Main body TEST", self.id)
            
        # wait an interfal of time in secs
        interval = 5.23 
        self.obcp_wait_interval_time( interval )
        
        #wait until an absolute time (Epoch time in sec with linux clock)
        abs_time = 1523262166.7459543
        self.obcp_wait_absolute_time( abs_time )
        
        #wait an event (without timeout)
        event_rcv1 = self.obcp_wait_event(obcp_Event["EVENT_LOW_02"])
        print("Read Event: id:", event_rcv1.id, ", data1:", event_rcv1.data1, ", data2:", event_rcv1.data2)
        
        #wait an event (with timeout 5.5 sec)
        self.event_rcv2 = self.obcp_wait_event(obcp_Event["EVENT_INFO_01"], 5.5)
        print("Read Event: id:", self.event_rcv2.id, ", data1:", self.event_rcv2.data1, ", data2:", self.event_rcv2.data2)

        
obcp = ObcpTest("OBCP_COND")
obcp.run()


