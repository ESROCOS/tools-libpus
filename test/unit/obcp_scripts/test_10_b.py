# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

class ObcpTest(Obcp):
    def preconditions(self):
        print("- Preconditions body", self.id)
        print("- Waitting for TEST_10A.")

        #wait for a param value

        self.obcp_set_onboard_parameter(obcp_OnBoardParam["ONBOARD_PARAM_REAL01"], 5.0)
        print("- Param value: ", self.obcp_get_onboard_parameter(obcp_OnBoardParam["ONBOARD_PARAM_REAL01"]))
        while self.obcp_get_onboard_parameter(obcp_OnBoardParam["ONBOARD_PARAM_REAL01"]) > 2.5:
            pass

        print("- Param value PRE RETURN: ", self.obcp_get_onboard_parameter(obcp_OnBoardParam["ONBOARD_PARAM_REAL01"]))
        return True   

    def main(self):
        print(" - Main body", self.id)
        
        
a = ObcpTest("TEST_10B")
a.run()
