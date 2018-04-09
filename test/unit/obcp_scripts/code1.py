#import fun.py 

import micropython, gc

class ObcpTest(Obcp):
    
    def preconditions(self):
        print("- Preconditions body", self.id)
        return True
    
    def main(self):
        print("- Main body TEST", self.id)
        
        self.obcp_wait_interval_time(0.3)
        print("OBCP_1: waitting for event with id=3 (timeout 3 sec)")
        ev2 = self.obcp_wait_event(3, 3.0)
        if None != ev2:
            print("OBCP_1: event read: id:", ev2.id, ", data1:", ev2.data1, ", data2:", ev2.data2)
            
    def confirmation(self):
        print("- Preconditions body", self.id)
        return True    
        
a = ObcpTest("OBCP_1")
a.run()


