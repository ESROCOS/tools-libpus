class ObcpTest(Obcp):
    def preconditions(self):
        print("- Preconditions body", self.id)
        print("- Waitting for TEST_10A")

        #wait for a param value
        while self.obcp_get_onboard_parameter(obcp_OnBoardParam["ONBOARD_PARAM_REAL01"]) < 2.5:
            pass

        return True   

    def main(self):
        print(" - Main body", self.id)
        
        
a = ObcpTest("TEST_10B")
a.run()