#check the param value#import fun.py 

import micropython, gc

class ObcpTest(Obcp):
    
    def preconditions(self):
        print("- Preconditions body", self.id)
        
        #wait for a param value
        while self.obcp_get_onboard_parameter(obcp_OnBoardParam["ONBOARD_PARAM_REAL01"]) < 2.5:
            pass
        
        #wait for a param value
        while self.self.obcp_get_hk_parameter(obcp_HkParam["HK_PARAM_BYTE01"]) < 0x36:
            pass
        
        return True
    
    def main(self):
        print("- Main body TEST", self.id)
        
        #getter of an onboard parameter value
        param1 = self.obcp_get_onboard_parameter(obcp_OnBoardParam["ONBOARD_PARAM_REAL01"])
        
        #setter of an onboard parameter value 
        self.obcp_set_onboard_parameter(obcp_OnBoardParam["ONBOARD_PARAM_REAL01"], 5.23)
        
        #getter of an HK parameter value
        param2 = self.obcp_get_hk_parameter(obcp_HkParam["HK_PARAM_BYTE01"])
        
        #setter of an HK parameter value 
        self.obcp_set_hk_parameter(obcp_HkParam["HK_PARAM_BYTE01"], 0x23)
        
        #get actual time
        float_time = self.obcp_get_time_now()
        
        
obcp = ObcpTest("OBCP_PARAMS")
obcp.run()


