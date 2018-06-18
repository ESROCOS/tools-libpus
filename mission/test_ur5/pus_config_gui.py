from PusGui import pb
# Only telecommands needed
def mission_create_packets(packet, svc, msg, apid=0, seq=0):
    if (svc, msg) == (200, 1):
        pb.pus_tc_200_1_createControlCameraRequest(packet, apid, seq, 0)
    elif (svc, msg) == (201, 1):
        pass
        #pb.pus_tc_201_1_createSetHomeRequest(packet, apid, seq)
    else:
        pass
        
# Generic get data function for tms and tcs
def mission_get_data(packet, svc, msg):
    if (svc, msg) == (200, 1):
        data = tc_200_1_get_data(packet)
    elif (svc, msg) == (200, 2):
        data = tc_200_2_get_data(packet)
    else:
        data = dict()
        
    return data   

# Generic set data funcition fot tcs
def mission_set_data(packet, svc, msg, data):
    if (svc, msg) == (200, 1):
        packet = tc_200_1_set_data(packet, data)      
        

# Specific get and set functions
def tc_200_1_set_data(packet, data):
    obs = data["operation"]
    pb.pus_tc_200_1_setControlId(packet, obs)
    return packet

def tc_200_1_get_data(packet):
    data = dict()
    data["operation"] = pb.pus_tc_200_1_getControlId(packet)
    return data

def tc_200_2_get_data(packet):
    data = dict()
    data["observation"] = pb.pus_tm_200_2_getObservation(packet)
    return data