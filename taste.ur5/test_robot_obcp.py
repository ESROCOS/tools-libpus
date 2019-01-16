# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

class ObcpTest(Obcp):      
    def main(self):
        print("- Main body OBCP: Robot control", self.id)

        # Set home  
        self.obcp_set_onboard_parameter(obcp_OnBoardParam["UR5_HOME_POS_1"], 0.3)
        self.obcp_set_onboard_parameter(obcp_OnBoardParam["UR5_HOME_POS_2"], 0.12)
        self.obcp_set_onboard_parameter(obcp_OnBoardParam["UR5_HOME_POS_3"], 0.71)
        self.obcp_set_onboard_parameter(obcp_OnBoardParam["UR5_HOME_ORI_1"], 0.58)
        self.obcp_set_onboard_parameter(obcp_OnBoardParam["UR5_HOME_ORI_2"], 0.45)
        self.obcp_set_onboard_parameter(obcp_OnBoardParam["UR5_HOME_ORI_3"], 0.54)
        self.obcp_set_onboard_parameter(obcp_OnBoardParam["UR5_HOME_ORI_RE"], 0.4)

        self.obcp_wait_interval_time( 2 )
        self.obcp_perform_ST08_function(obcp_Function["UR5_SETHOME"])

        # Plan Move 
        self.obcp_set_onboard_parameter(obcp_OnBoardParam["UR5_MOVE_POS_1"], 0.3)
        self.obcp_set_onboard_parameter(obcp_OnBoardParam["UR5_MOVE_POS_2"], 0.11)
        self.obcp_set_onboard_parameter(obcp_OnBoardParam["UR5_MOVE_POS_3"], 0.71)
        self.obcp_set_onboard_parameter(obcp_OnBoardParam["UR5_MOVE_ORI_1"], 0.58)
        self.obcp_set_onboard_parameter(obcp_OnBoardParam["UR5_MOVE_ORI_2"], 0.46)
        self.obcp_set_onboard_parameter(obcp_OnBoardParam["UR5_MOVE_ORI_3"], 0.53)
        self.obcp_set_onboard_parameter(obcp_OnBoardParam["UR5_MOVE_ORI_RE"], 0.46)

        self.obcp_perform_ST08_function(obcp_Function["UR5_PLANMOVE"])


        # Wait 5 seconds 
        self.obcp_wait_interval_time( 2 )
        self.obcp_perform_ST08_function(obcp_Function["UR5_PLANHOME"]) 

        self.obcp_wait_interval_time( 2 )
        self.obcp_perform_ST08_function(obcp_Function["CAMERA_FRAMEREQUEST"]) 

 
a = ObcpTest("ROBOT")
a.run()
