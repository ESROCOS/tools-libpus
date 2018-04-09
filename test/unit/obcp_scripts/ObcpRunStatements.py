#check the param value#import fun.py 

import micropython, gc


#new User Exception with 1 parameter
class UserException(Exception):
    def __init__(self, param1):
        self.param = param1

class ObcpTest(Obcp):
    
    def declarations(self):
        print("- Declaration body", self.id)     
        #local variable for this block
        local_varible = 5
        
        #global variable for all blocks
        self.global_variable = 6
        

    def preconditions(self):
        print("- Preconditions body", self.id)
        
        #wait a condition (event with timeout)
        self.event_rcv = self.obcp_wait_event(obcp_Event["EVENT_INFO_01"], 5.5)
        if None != self.event_rcv:
            return True
        else:
            return False #raise PreconditionsFailure()
        

    def main(self):
        print("- Main body", self.id)
        
        #use of global variable
        self.global_variable += 1
        
        #raise a new Exception
        raise UserException( self.global_variable )
        

    def confirmation(self):
        print("- Confirmation body", self.id)
        return True


    def contingency(self, exception):
        print("- Contingency body", self.id)
        
        if isinstance(exception, UserException):
            #handle this exception
            pass
        elif isinstance(exception, PreconditionsFailure):
            #handle
            pass
            


    def set_results(self):
        print("- Setting results", self.id)
        
        
        
obcp = ObcpTest("OBCP_RUN")
obcp.run()


