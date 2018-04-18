class ObcpTest(Obcp):
        
    def main(self):
        while True:
            self.obcp_yield()
            self.obcp_wait_interval_time(0.5)
        
             
        
a = ObcpTest("OBCP_HI")
a.run()
