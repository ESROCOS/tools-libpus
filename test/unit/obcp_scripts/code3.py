try:
    import superClass
except:
    pass


import micropython, gc

class ObcpTest(Obcp):
    
    def preconditions(self):
        print("- Preconditions body", self.id)
        return True
    
    def main(self):
        print("- Main body TEST", self.id)
        
        #setter of an onboard parameter value 
        self.obcp_set_onboard_parameter(obcp_OnBoardParam["ONBOARD_PARAM_REAL01"], 5.23)
        
        #getter of an onboard parameter value
        param1 = self.obcp_get_onboard_parameter(obcp_OnBoardParam["ONBOARD_PARAM_REAL01"])
               
            
    def confirmation(self):
        print("- Preconditions body", self.id)
        print("SETTING CONF:", module.setConfirmationValue(self.id, obcp_Status["FAILURE"]))
        return True    
        
a = ObcpTest("OBCP_TEST")
a.run()