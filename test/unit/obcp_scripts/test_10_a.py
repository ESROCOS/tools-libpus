class ObcpTest(Obcp):
    def main(self):
        print(" - Main body", self.id)
        print(" - Setting parameter for TEST_10B")
        self.obcp_set_onboard_parameter(obcp_OnBoardParam["ONBOARD_PARAM_REAL01"], 1.25)

a = ObcpTest("TEST_10A")
a.run()