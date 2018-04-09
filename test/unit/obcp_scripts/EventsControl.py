#check the param value#import fun.py 

import micropython, gc

class ObcpTest(Obcp):
    
    def preconditions(self):
        print("- Preconditions body", self.id)
        
        #wait an event (without timeout)
        event_rcv1 = self.obcp_wait_event(obcp_Event["EVENT_LOW_02"])
        print("Read Event: id:", event_rcv1.id, ", data1:", event_rcv1.data1, ", data2:", event_rcv1.data2)
        
        #wait an event (with timeout 5.5 sec)
        self.event_rcv2 = self.obcp_wait_event(obcp_Event["EVENT_INFO_01"], 5.5)
        if None != self.event_rcv2:
            print("Read Event: id:", self.event_rcv2.id, ", data1:", self.event_rcv2.data1, ", data2:", self.event_rcv2.data2)

        return True
    
    def main(self):
        print("- Main body TEST", self.id)
        
        # chack parameters of events
        if self.event_rcv2.data1 > 25:
            #do something
            pass
        
        #raise a new event
        new_event = pus_Event(obcp_Event["EVENT_MEDIUM_03"], True, 0x06)
        self.obcp_raise_event( new_event )
        
        
        
obcp = ObcpTest("OBCP_EVENTS")
obcp.run()


