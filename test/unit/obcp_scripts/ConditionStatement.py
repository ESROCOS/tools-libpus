#check the param value#import fun.py 

import micropython, gc

class ObcpTest(Obcp):
    
    def preconditions(self):
        print("- Preconditions body", self.id)
        
        #wait for a param value
        while self.obcp_get_onboard_parameter(obcp_OnBoardParam["ONBOARD_PARAM_REAL01"]) < 2.5:
            pass
        
        return True
    
    def main(self):
        print("- Main body TEST", self.id)
        
        #check the param value
        if self.obcp_get_onboard_parameter(obcp_OnBoardParam["ONBOARD_PARAM_REAL01"]) > 50:
            #do something (execute function, raise even, etc)
            pass
        elif self.obcp_get_onboard_parameter(obcp_OnBoardParam["ONBOARD_PARAM_REAL01"]) > 30.5:
            #do something (execute function, raise even, etc)
            pass
        else:
            #do something (execute function, raise even, etc)
            pass
        
obcp = ObcpTest("OBCP_COND")
obcp.run()


