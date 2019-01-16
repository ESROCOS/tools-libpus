# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

class ObcpTest(Obcp):
        
    def main(self):
        #while True:
        #   self.obcp_yield()
        #    self.obcp_wait_interval_time(0.5)
        print("HELLO 1")
        self.obcp_wait_interval_time(0.5)

        new_event = pus_Event(obcp_Event["EVENT_MEDIUM_03"], True, 0x06)
        self.obcp_raise_event( new_event )

        
        #setter of an onboard parameter value 
        self.obcp_set_onboard_parameter(obcp_OnBoardParam["ONBOARD_PARAM_REAL01"], 5.23)

        #getter of an onboard parameter value
        param1 = self.obcp_get_onboard_parameter(obcp_OnBoardParam["ONBOARD_PARAM_REAL01"])
        print("ONBOARD_PARAM_REAL01" + str(param1) )

        user.exampleFunction(1)
        
a = ObcpTest("TEST_09")
a.run()
