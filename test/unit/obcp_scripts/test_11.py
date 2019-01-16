# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

class ObcpTest(Obcp):
    def main(self):
        print(" - Main body", self.id)
        print(" - Loop in yield, waitting for suspend & resume, then abort")
        while True:
            self.obcp_yield()
        

a = ObcpTest("TEST_11")
a.run()
