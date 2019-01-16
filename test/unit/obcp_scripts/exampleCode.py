# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

#import fun.py 

import micropython

class ObcpTest(Obcp):
    
    def preconditions(self):
        print("- Preconditions body", self.id)
        return True
    
    def main(self):
        print("- Main body TEST", self.id)
        #print("HkParam:", obcp_HkParam)
        #print("OnBoardParam:", obcp_OnBoardParam)
        #print("Events:", obcp_Event)
        #print("Functions", obcp_Function)
        
        #getter
        #print("self.get_hk_parameter(HK_PARAM_BYTE01)", obcp_self.get_hk_parameter(HkParam["asdfsdaf"]))
        #print("self.get_onboard_parameter(ONBOARD_PARAM_INT01)", self.obcp_get_onboard_parameter(OnBoardParam["ONBOARD_PARAM_INT01"]))
        
        #setter
        #self.obcp_set_hk_parameter(obcp_HkParam["HK_PARAM_INT01"], 0x80)
        #print("self.get_hk_parameter(HK_PARAM_INT01)", self.obcp_get_hk_parameter(obcp_HkParam["HK_PARAM_BYTE01"]))
        
        #self.set_onboard_parameter(obcp_OnBoardParam["ONBOARD_PARAM_INT01"], -465)
        #print("self.get_onboard_parameter(ONBOARD_PARAM_INT01)", self.obcp_get_onboard_parameter(OnBoardParam["ONBOARD_PARAM_INT01"]))
        
        # wait time
        #self.obcp_wait_interval_time(0.002)

        # get time
        #print("Time:", self.obcp_get_time_now())

        
        #Raise event
        print("obcp_raise_event", self.obcp_raise_event(pus_Event(3, True, 0x06)))
        
        
        ev2 = self.obcp_get_next_event()
        #ev2 = self.obcp_wait_event(3, 17.0)
        if None != ev2:
            print("Read: Event: id:", ev2.id, ", data1:", ev2.data1, ", data2:", ev2.data2)
        #while True:
        #    print(micropython.mem_info(1))
        #self.obcp_set_onboard_parameter(obcp_OnBoardParam["ONBOARD_PARAM_REAL01"], 2)
        
        #while self.obcp_get_onboard_parameter(obcp_OnBoardParam["ONBOARD_PARAM_REAL01"]) < 2.5:
        
        #print("obcp_raise_event", self.obcp_raise_event(pus_Event(3, True, 0x06)))
        #ev2 = self.obcp_wait_event(1, 5.5)
        #print("Event:", ev2)
        #print("Read: Event: id:", ev2.id, ", data1:", ev2.data1, ", data2:", ev2.data2)
        
        """
        import gc
        a = 1.1
        while True:
            a = a + 1.2
            module.sleepInterval(0.5)
            print(gc.mem_free())
        """
        
        
        a = 0
        while a < 2:
            print("func:", self.obcp_perform_ST08_function(obcp_Function["EXAMPLE_FUNCTION_03"]))
            a += 1
            self.obcp_wait_interval_time(0.5)
        
        
        
        """
        self.obcp_set_onboard_parameter(obcp_OnBoardParam["ONBOARD_PARAM_UINT01"], 2)
        
        cont = 0
        var = 1.0
        while True:
            cont = cont + 1
            try:
                self.obcp_wait_interval_time(0.00005)
                #print("value:",self.obcp_get_onboard_parameter(obcp_OnBoardParam["ONBOARD_PARAM_UINT01"]))
                var = var +1.1
                print(micropython.mem_info(2))
            except Exception as err:
                print("Exception", err.args)
                return
        """ 
        
a = ObcpTest("ID_OBCP")
a.run()


