#import fun.py 

import micropython, gc

class ObcpTest(Obcp):
    
    def preconditions(self):
        print("- Preconditions body", self.id)
        return True
    
    def main(self):
        print("- Main body TEST", self.id)

        self.obcp_wait_interval_time(1)
        print("OBCP_2: obcp_raise_event", self.obcp_raise_event(pus_Event(obcp_Event["EVENT_MEDIUM_03"], True, 0x06)))
        
a = ObcpTest("OBCP_2")
a.run()

