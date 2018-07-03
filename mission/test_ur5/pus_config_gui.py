from PusGui import pb
# Only telecommands needed
def mission_create_packets(packet, svc, msg, apid=0, seq=0):
    if (svc, msg) == (200, 1):
        pb.pus_tc_200_1_createControlCameraRequest(packet, apid, seq, 0)
    elif (svc, msg) == (201, 1):
        pb.pus_tc_201_1_createSetHomeRequest(packet, apid, seq, [0.0, 0.0, 0.0], [0.0, 0.0, 0.0, 0.0])
    elif (svc, msg) == (201, 2):
        pb.pus_tc_201_2_createPlanHomeRequest(packet, apid, seq)
    elif (svc, msg) == (201, 3):
        pb.pus_tc_201_3_createPlanMoveRequest(packet, apid, seq, [0.0, 0.0, 0.0], [0.0, 0.0, 0.0, 0.0])
    elif (svc, msg) == (201, 4):
        pb.pus_tm_201_4_createPlanReport(packet, apid, seq, 0)
    else:
        pass
        
# Generic get data function for tms and tcs
def mission_get_data(packet, svc, msg):
    if (svc, msg) == (200, 1):
        data = tc_200_1_get_data(packet)
    elif (svc, msg) == (200, 2):
        data = tc_200_2_get_data(packet)
    elif (svc, msg) == (201, 1) or (svc, msg) == (201, 3):
        data = tc_201_1_3_get_data(packet)
    elif (svc, msg) == (201, 2):
        data = tc_201_2_get_data(packet)
    elif (svc, msg) == (201, 4):
        data = tc_201_4_get_data(packet)        
    else:
        data = dict()  
    return data   

# Generic set data funcition fot tcs
def mission_set_data(packet, svc, msg, data):
    if (svc, msg) == (200, 1):
        packet = tc_200_1_set_data(packet, data)
    elif (svc, msg) == (201, 1) or (svc, msg) == (201, 3):
        packet = tc_201_1_3_set_data(packet, data)
    elif (svc, msg) == (201, 2):
        packet = tc_202_2_set_data(packet, data) 

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

def tc_201_1_3_set_data(packet, data):
    pos = list(map(float, data["position"]))
    ori = list(map(float, data["orientation"]))
    pb.pus_tc_201_1_3_setOrientationPoints(packet, ori[0], ori[1], ori[2], ori[4])
    pb.pus_tc_201_1_3_setPositionPoints(packet, pos[0], pos[1], pos[2])
    return packet

def tc_201_1_3_get_data(packet):
    data = dict()
    data["position"] = pb.pus_tc_201_1_3_getPositionPoints(packet)
    data["orientation"] = pb.pus_tc_201_1_3_getOrientationPoints(packet)
    return data

def tc_201_2_set_data(packet, data):
    return packet

def tc_201_2_get_data(packet):
    data = dict()
    return data

def tc_201_4_get_data(packet):
    data = dict()
    observation = pb.pus_tm_201_4_getPlanObservation(packet)
    data["id"] = observation.id
    data["code"] = observation.code 
    return data
