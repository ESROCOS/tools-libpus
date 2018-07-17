import obcpModule as module
import userFunctions as user

import micropython, gc

class obcp_AbortException(Exception):
    pass
    
class obcp_StopException(Exception):
    pass

class PreconditionsFailure(Exception):
    pass
    
class TimeoutFailure(Exception):
    pass
    
class ConfirmationFailure(Exception):
    pass
    
class ErrorGetHkParameter(Exception):
    pass
    
class ErrorGetOnBoardParameter(Exception):
    pass
    
class ErrorSetHkParameter(Exception):
    pass
    
class ErrorSetOnBoardParameter(Exception):
    pass 
    
class ErrorRaisingEvent(Exception):
    pass 

class pus_Event():
    def __init__(self, id_, data1_, data2_ ):
        self.id = id_
        self.data1 = data1_
        self.data2 = data2_
    
    def getId(self):
        return self.id
    
    def setId(self, x):
        self.id = x
        
    def getData1(self):
        return self.data1
    
    def setData1(self, x):
        self.data1 = x
        
    def getData2(self):
        return self.data2
    
    def setData2(self, x):
        self.data2 = x    
    
#init dict events, params
obcp_HkParam = module.getDictHkParams()
obcp_OnBoardParam = module.getDictOnBoardParams()
obcp_Event = module.getDictEvents()
obcp_Function = module.getDictFunctions()
obcp_Status = {'NOT_COMPLETED': 0, 'SUCCESS': 1, 'STOPPED': 2, 'ABORTED': 3}


class Obcp:
    #initiation time, start time, termination time or completion time of the last execution of an activity
    def __init__(self, id_):
        self.id = id_
        self.executionStatus = "ACTIVE_PRECONDITIONS"
        #if running
        self.stepExecuting = 0
        #if suspended
        self.nextStep = 1
        self.eventCounter = module.getLastEventCounter()
        

    def declarations(self):
        print("- Declaration body", self.id)

    def preconditions(self):
        print("- Preconditions body", self.id)
        return True

    def main(self):
        print("- Main body", self.id)

    def confirmation(self):
        print("- Confirmation body", self.id)
        self.obcp_set_confirmation_status(obcp_Status['SUCCESS'])
        return True

    def contingency(self, exception):
        print("- Contingency body", self.id)

    def set_results(self):
        print("- Setting results", self.id)

    def run(self):
        try:
            self.obcp_yield()
            
            self.declarations()
            
            self.obcp_yield()
            
            if True != self.preconditions():
                raise PreconditionsFailure()
                
            self.obcp_yield()
                
            self.main()
            
            self.obcp_yield()
            
            if True != self.confirmation():
                raise ConfirmationFailure()
            
            self.obcp_yield()
                
            self.set_results()
            
        #Unknown exception catched
        except Exception as err:
            if not isinstance(err, obcp_AbortException) and not isinstance(err, obcp_StopException):
                print("Exception catched while running OBCP,", err.args)
                self.contingency(err)
            elif isinstance(err, obcp_AbortException):
                print(self.id, "ABORTED")
                self.obcp_set_confirmation_status(obcp_Status["ABORTED"])
            elif isinstance(err, obcp_StopException):
                print(self.id, "STOPPED")
                self.obcp_set_confirmation_status(obcp_Status["STOPPED"])

################### functions API ####################

    #### parameters
    
    def obcp_get_time_now(self) -> float:
        return module.getTimeNowFloat()


    def obcp_get_hk_parameter( self, paramId: int ):
        """
        This method get the value of a parameter as argument
        :param paramId: Parameter Id
        :return: The value of the HK parameter requested or False if error
        """ 
        if int == type(paramId):
            return module.getHkParamValue(paramId)
        else:
            raise ErrorGetHkParameter


    def obcp_get_onboard_parameter( self, paramId ):
        """
        This method get the value of a parameter as argument
        :param paramId: Parameter Id
        :return: The value of the on board parameter requested or False if error
        """ 
        if int == type(paramId):
            return module.getOnBoardParamValue(paramId)
        else:
            raise ErrorGetOnBoardParameter


    def obcp_set_hk_parameter( self, paramId, value ):
        """
        This method set the value of a parameter as argument
        :param paramId: Parameter Id
        :param value: Value that is going to be set
        :return: True success or false if error
        """ 
        if int == type(paramId):
            return module.setHkParamValue(paramId, value)
        else:
            raise ErrorSetHkParameter

        
    def obcp_set_onboard_parameter( self, paramId, value ):
        """
        This method set the value of a parameter as argument
        :param paramId: Parameter Id
        :param value: Value that is going to be set
        :return: True success or false if error
        """ 
        if int == type(paramId):
            return module.setOnBoardParamValue(paramId, value)
        else:
            raise ErrorSetOnBoardParameter

#### waits

    def obcp_wait_interval_time( self, interval: float ) -> bool:
        """
        This method wait for a given interval of time to elapse
        :param interval: Interval of time to elapse
        :return: True success or false if error
        """        
        return module.sleepInterval( interval )
    
    
    def obcp_wait_absolute_time( self, abs_time: float ) -> bool:
        """
        This method wait until a given absolute time
        :param time: Absolute time
        :return: True success or false if error
        """ 
        return self.obcp_wait_interval_time(abs_time - self.obcp_get_time_now())

            
    def obcp_wait_event( self, eventId, timeout = 0 ):
        """
        This method wait until any event from a specified list of events occurs
        :param eventId: Event Id
        :return: Event if success or None if error
        """
        (event_dict, counter) = module.getNextEventBlocking(eventId, self.eventCounter, timeout)
        
        if None != event_dict: #Res == event class(id, data1, data2)
            self.eventCounter = counter
            return pus_Event(event_dict["id"], event_dict["data1"], event_dict["data2"])
        else:
				return None
            
            
    #### events
        
    def obcp_get_next_event( self ):
        """
        This method get the next event from the events table
        :return: The next event (class{id, data1, data2}) in table or false if no events or error
        """
        (event_dict, counter) = modulimporte.getNextEvent(self.eventCounter)

        if None == event_dict or None == counter:
            return None
        else:
            self.eventCounter = counter
            event = pus_Event(event_dict["id"], event_dict["data1"], event_dict["data2"])
            return event

    def obcp_raise_event( self, event ) -> bool:
        """
        This method insert a new event into the events table
        :param event: event
        :return: True success or false if error
        """ 
        if not isinstance(event, pus_Event):
            raise ErrorRaisingEvent #TODO
        
        return module.raiseEvent(event.getId(), event.getData1(), event.getData2())

    #### Activities    

    def obcp_create_send_TC( self ):
        """
        This method create and send to the queue a PUS Telecommand
        :param TBD: to be defined
        :return: True success or false if error
        """
        pass
    
    def obcp_perform_ST08_function( self, functionId: int) -> bool:
        """
        This method perform a ST08 function
        :param TBD: to be defined
        :return: True success or false if error
        """
        return module.executeSt08Function(functionId)
        
        
################### Auxiliar functions ###############

    def obcp_yield(self):
        #print("yield, checking for abort ..")
        abort = module.checkAbortRequest(self.id) #true / false
        if abort == True:
            raise obcp_AbortException()
        
        #print("yield, checking for stop ..")
        stop = module.checkStopRequest(self.id) #true / false
        if abort == True:
            raise obcp_StopException()
        
        #print("yield, checking for suspension ..")
        module.checkSuspendRequest(self.id) #blocking if suspend request received
        return False
        
        
    def obcp_set_confirmation_status(self, status):
        module.setConfirmationValue(self.id, status)
        
        obcp_thread = module.getThreadFromId(self.id)
        if obcp_thread != None:
            module.raiseEvent(obcp_Event["EVENT_OBCP_FINISHED"], obcp_thread, status)
        

    def obcp_activate_obcp(self, obcpId: str) -> bool: 
        return module.activateObcp(obcpId)
    
    
    def obcp_wait_obcp_finish(self, obcpId: str, attempt=20) -> bool:
        threadId = module.getThreadFromId(obcpId)
        if threadId == None:
            return False
        for i in range(attempt):
            event_rcv1 = self.obcp_wait_event(obcp_Event["EVENT_OBCP_FINISHED"])
            
            print("Read Event: id:", event_rcv1.id, ", data1:", event_rcv1.data1, ", data2:", event_rcv1.data2)
            if event_rcv1.data1 == threadId:
                return event_rcv1.data2 #return state


################### END fun.py #######################

