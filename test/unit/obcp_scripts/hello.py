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
        print("HELLO 2")
        self.obcp_wait_interval_time(0.5)
        print("HELLO 3")
        self.obcp_wait_interval_time(0.5)    

        user.exampleFunction(1)
        
a = ObcpTest("OBCP_HI")
a.run()
