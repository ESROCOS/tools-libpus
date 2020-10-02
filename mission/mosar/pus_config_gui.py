# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

from PusGui import pb
import numpy as np

# Only telecommands needed (default packets)
def mission_create_packets(packet, svc, msg, apid=0, seq=0):
    #ST 200
    if (svc, msg) == (200, 3):
        pb.pus_tc_200_3_createMissionRequest_(packet, apid, seq)
    elif (svc, msg) == (200, 5):
        pb.pus_tc_200_5_createHotdockcmdRequest_(packet, apid, seq)
    elif (svc, msg) == (200, 9):
        pb.pus_tc_200_9_createWmcmdRequest_(packet, apid, seq)
    elif (svc, msg) == (200, 11):
        pb.pus_tc_200_11_createBasecmdRequest_(packet, apid, seq)
    elif (svc, msg) == (200, 13):
        pb.pus_tc_200_13_createEfcmdRequest_(packet, apid, seq)
    #ST 220
    elif (svc, msg) == (220, 1):
        pb.pus_tc_220_1_createNewTargetState_(packet, apid, seq)
    elif (svc, msg) == (220, 2):
        pb.pus_tc_200_2_createGetCurrentState(packet, apid, seq)

    else:
        pass
        
# Generic get data function for BOTH tms and tcs
def mission_get_data(packet, svc, msg):
    #St 200
    if (svc, msg) == (200, 2):
        data = tc_200_2_get_data(packet)
    elif (svc, msg) == (200, 4):
        data = tc_200_4_get_data(packet)
    elif (svc, msg) == (200, 3):
        data = tc_200_3_get_data(packet)
    elif (svc, msg) == (200, 6):
        data = tc_200_6_get_data(packet)
    elif (svc, msg) == (200, 5):
        data = tc_200_5_get_data(packet)
    elif (svc, msg) == (200, 8):
        data = tc_200_8_get_data(packet)
    elif (svc, msg) == (200, 10):
        data = tc_200_10_get_data(packet)
    elif (svc, msg) == (200, 9):
        data = tc_200_9_get_data(packet)
    elif (svc, msg) == (200, 12):
        data = tc_200_12_get_data(packet)
    elif (svc, msg) == (200, 11):
        data = tc_200_11_get_data(packet)
    elif (svc, msg) == (200, 14):
        data = tc_200_14_get_data(packet)
    elif (svc, msg) == (200, 13):
        data = tc_200_13_get_data(packet)
    #ST 220
    elif (svc, msg) == (220, 1):
        data = tc_220_1_get_data(packet)
    elif (svc, msg) == (220, 3):
        data = tm_220_3_get_data(packet)
    else:
        data = dict()  
    return data   

# Generic set data funcition for tcs
def mission_set_data(packet, svc, msg, data):
    # ST 200
    if (svc, msg) == (200, 3):
        packet = tc_200_3_set_data(packet, data)
    elif (svc, msg) == (200, 5):
        packet = tc_200_5_set_data(packet, data)
    elif (svc, msg) == (200, 9):
        packet = tc_200_9_set_data(packet, data)
    elif (svc, msg) == (200, 11):
        packet = tc_200_11_set_data(packet, data)
    elif (svc, msg) == (200, 13):
        packet = tc_200_13_set_data(packet, data)
    # ST 220
    elif (svc, msg) == (220, 1):
        packet = tc_220_1_set_data(packet, data) 

# Specific get and set functions ST 220
def tc_220_1_set_data(packet, data):
    state = int(data["state"])
    pb.pus_tc_220_1_setTargetState_(packet, state)
    return packet

def tc_220_1_get_data(packet):
    data = dict()
    data["state"] = pb.pus_tc_220_1_getTargetState_(packet)    
    return data

def tm_220_3_get_data(packet):
    data = dict()
    data["state"] = pb.pus_tm_220_3_getCurrentState_(packet)
    return data


# Specific get and set functions ST 200
def tc_200_3_set_data(packet, data):
    goal = data["goal"]
    goalData = pb.pusSt200_3_Goal()
    goalData.agent = getStringFromDict(data["agent"])
    goalData.goal.inittime = getIntervalFromDict(goal["inittime"])
    goalData.goal.endtime = getIntervalFromDict(goal["endtime"])
    if goal["predicate"] == "idle":
        goalData.goal.predicate = pb.asn1SccMissionPred.idle
    elif goal["predicate"] == "place":
        goalData.goal.predicate = pb.asn1SccMissionPred.place 
        goalData.goal.sm = getStringdFromDict(goal["attributes"]["sm"])
        goalData.goal.slot = getStringdFromDict(goal["attributes"]["slot"])
        goalData.goal.orientation = getStringdFromDict(goal["attributes"]["orientation"])
        
    elif goal["predicate"] == "loadinge3plan":
        goalData.goal.predicate = pb.asn1SccMissionPred.loadinge3plan 
        goalData.goal.file = getStringdFromDict(goal["attributes"]["file"])
        
    
    else:
        print("Invalid predicate " + goal["predicate"] + ". Valid options are: idle place loadinge3plan ")
    
    pb.pus_tc_200_3_setMissionGoal(packet, goalData)
    #pb.pus_tc_200_3_setMissionGoal(packet, goal)
    return packet
    

def tc_200_5_set_data(packet, data):
    goal = data["goal"]
    goalData = pb.pusSt200_5_Goal()
    goalData.agent = getStringFromDict(data["agent"])
    goalData.goal.inittime = getIntervalFromDict(goal["inittime"])
    goalData.goal.endtime = getIntervalFromDict(goal["endtime"])
    if goal["predicate"] == "idle":
        goalData.goal.predicate = pb.asn1SccHotdockcmdPred.idle 
        goalData.goal.status = getEnumDomainFromDict(goal["attributes"]["status"])
        
    elif goal["predicate"] == "sendState":
        goalData.goal.predicate = pb.asn1SccHotdockcmdPred.sendState 
        goalData.goal.sm = getEnumDomainFromDict(goal["attributes"]["sm"])
        goalData.goal.hotdock = getStringdFromDict(goal["attributes"]["hotdock"])
        goalData.goal.statehd = getEnumDomainFromDict(goal["attributes"]["statehd"])
        
    
    else:
        print("Invalid predicate " + goal["predicate"] + ". Valid options are: idle sendState ")
    
    pb.pus_tc_200_5_setHotdockcmdGoal(packet, goalData)
    #pb.pus_tc_200_5_setHotdockcmdGoal(packet, goal)
    return packet
    

def tc_200_9_set_data(packet, data):
    goal = data["goal"]
    goalData = pb.pusSt200_9_Goal()
    goalData.agent = getStringFromDict(data["agent"])
    goalData.goal.inittime = getIntervalFromDict(goal["inittime"])
    goalData.goal.endtime = getIntervalFromDict(goal["endtime"])
    if goal["predicate"] == "idle":
        goalData.goal.predicate = pb.asn1SccWmcmdPred.idle 
        goalData.goal.status = getEnumDomainFromDict(goal["attributes"]["status"])
        
    elif goal["predicate"] == "movetohd":
        goalData.goal.predicate = pb.asn1SccWmcmdPred.movetohd 
        goalData.goal.hotdock = getStringdFromDict(goal["attributes"]["hotdock"])
        
    elif goal["predicate"] == "movetoslot":
        goalData.goal.predicate = pb.asn1SccWmcmdPred.movetoslot 
        goalData.goal.slot = getSlotidFromDict(goal["attributes"]["slot"])
        goalData.goal.face = getStringdFromDict(goal["attributes"]["face"])
        goalData.goal.yaw = getEnumDomainFromDict(goal["attributes"]["yaw"])
        
    
    else:
        print("Invalid predicate " + goal["predicate"] + ". Valid options are: idle movetohd movetoslot ")
    
    pb.pus_tc_200_9_setWmcmdGoal(packet, goalData)
    #pb.pus_tc_200_9_setWmcmdGoal(packet, goal)
    return packet
    

def tc_200_11_set_data(packet, data):
    goal = data["goal"]
    goalData = pb.pusSt200_11_Goal()
    goalData.agent = getStringFromDict(data["agent"])
    goalData.goal.inittime = getIntervalFromDict(goal["inittime"])
    goalData.goal.endtime = getIntervalFromDict(goal["endtime"])
    if goal["predicate"] == "baseAt":
        goalData.goal.predicate = pb.asn1SccBasecmdPred.baseAt 
        goalData.goal.hotdock = getStringdFromDict(goal["attributes"]["hotdock"])
        
    elif goal["predicate"] == "switchBase":
        goalData.goal.predicate = pb.asn1SccBasecmdPred.switchBase 
        goalData.goal.hotdock = getStringdFromDict(goal["attributes"]["hotdock"])
        
    elif goal["predicate"] == "error":
        goalData.goal.predicate = pb.asn1SccBasecmdPred.error
    
    else:
        print("Invalid predicate " + goal["predicate"] + ". Valid options are: baseAt switchBase error ")
    
    pb.pus_tc_200_11_setBasecmdGoal(packet, goalData)
    #pb.pus_tc_200_11_setBasecmdGoal(packet, goal)
    return packet
    

def tc_200_13_set_data(packet, data):
    goal = data["goal"]
    goalData = pb.pusSt200_13_Goal()
    goalData.agent = getStringFromDict(data["agent"])
    goalData.goal.inittime = getIntervalFromDict(goal["inittime"])
    goalData.goal.endtime = getIntervalFromDict(goal["endtime"])
    if goal["predicate"] == "idle":
        goalData.goal.predicate = pb.asn1SccEfcmdPred.idle 
        goalData.goal.status = getEnumDomainFromDict(goal["attributes"]["status"])
        
    elif goal["predicate"] == "pick":
        goalData.goal.predicate = pb.asn1SccEfcmdPred.pick 
        goalData.goal.hotdock = getStringdFromDict(goal["attributes"]["hotdock"])
        
    elif goal["predicate"] == "drop":
        goalData.goal.predicate = pb.asn1SccEfcmdPred.drop
    
    else:
        print("Invalid predicate " + goal["predicate"] + ". Valid options are: idle pick drop ")
    
    pb.pus_tc_200_13_setEfcmdGoal(packet, goalData)
    #pb.pus_tc_200_13_setEfcmdGoal(packet, goal)
    return packet
    



def getPlannerDict(inData):
    data = dict()
    data["timeline"] = "planner"
    data["predicate"] = str(inData.predicate).split(".",1)[1]
    data["inittime"] = getIntervalDict(inData.inittime)
    data["endtime"] = getIntervalDict(inData.endtime)

    attributes = dict()
    attributes["goals"] = getIntdDict(inData.goals)
    
    if len(attributes) > 0:
        data["attributes"] = attributes

    return data
def tc_200_2_get_data(packet):
    try:
        data = dict()
        obs = pb.pus_tm_200_2_getPlannerObservation(packet)
        
        observation = dict()
        observation["timeline"] = "planner"
        observation["predicate"] = str(obs.observation.predicate).split(".",1)[1]

        attributes = dict()
         
        if observation["predicate"] == "planning":
            attributes["goals"] = getIntdDict(obs.observation.goals)
        
        if len(attributes) > 0:
            observation["attributes"] = attributes
        
        data["observation"] = observation
        data["agent"] = getStringDict(obs.agent)
    except Exception as e:
        print(str(e))
    
    return data

def getMissionDict(inData):
    data = dict()
    data["timeline"] = "mission"
    data["predicate"] = str(inData.predicate).split(".",1)[1]
    data["inittime"] = getIntervalDict(inData.inittime)
    data["endtime"] = getIntervalDict(inData.endtime)

    attributes = dict()
    attributes["sm"] = getStringdDict(inData.sm)
    attributes["slot"] = getStringdDict(inData.slot)
    attributes["orientation"] = getStringdDict(inData.orientation)
    attributes["file"] = getStringdDict(inData.file)
    
    if len(attributes) > 0:
        data["attributes"] = attributes

    return data
def tc_200_3_get_data(packet):
    try:
        data = dict()
        goal = pb.pus_tc_200_3_getMissionGoal(packet)
        data["goal"] = getMissionDict(goal.goal)
        data["agent"] = getStringDict(goal.agent)
    except Exception as e:
        print(str(e))
    
    return data
def tc_200_4_get_data(packet):
    try:
        data = dict()
        obs = pb.pus_tm_200_4_getMissionObservation(packet)
        
        observation = dict()
        observation["timeline"] = "mission"
        observation["predicate"] = str(obs.observation.predicate).split(".",1)[1]

        attributes = dict()
         
        if observation["predicate"] == "place":
            attributes["sm"] = getStringdDict(obs.observation.sm)
            attributes["slot"] = getStringdDict(obs.observation.slot)
            attributes["orientation"] = getStringdDict(obs.observation.orientation)
         
        if observation["predicate"] == "loadinge3plan":
            attributes["file"] = getStringdDict(obs.observation.file)
        if len(attributes) > 0:
            observation["attributes"] = attributes
        
        data["observation"] = observation
        data["agent"] = getStringDict(obs.agent)
    except Exception as e:
        print(str(e))
    
    return data

def getHotdockcmdDict(inData):
    data = dict()
    data["timeline"] = "hotdockcmd"
    data["predicate"] = str(inData.predicate).split(".",1)[1]
    data["inittime"] = getIntervalDict(inData.inittime)
    data["endtime"] = getIntervalDict(inData.endtime)

    attributes = dict()
    attributes["status"] = getEnumDomainDict(inData.status)
    attributes["sm"] = getEnumDomainDict(inData.sm)
    attributes["hotdock"] = getStringdDict(inData.hotdock)
    attributes["statehd"] = getEnumDomainDict(inData.statehd)
    
    if len(attributes) > 0:
        data["attributes"] = attributes

    return data
def tc_200_5_get_data(packet):
    try:
        data = dict()
        goal = pb.pus_tc_200_5_getHotdockcmdGoal(packet)
        data["goal"] = getHotdockcmdDict(goal.goal)
        data["agent"] = getStringDict(goal.agent)
    except Exception as e:
        print(str(e))
    
    return data
def tc_200_6_get_data(packet):
    try:
        data = dict()
        obs = pb.pus_tm_200_6_getHotdockcmdObservation(packet)
        
        observation = dict()
        observation["timeline"] = "hotdockcmd"
        observation["predicate"] = str(obs.observation.predicate).split(".",1)[1]

        attributes = dict() 
        if observation["predicate"] == "idle":
            attributes["status"] = getEnumDomainDict(obs.observation.status)
         
        if observation["predicate"] == "sendState":
            attributes["sm"] = getEnumDomainDict(obs.observation.sm)
            attributes["hotdock"] = getStringdDict(obs.observation.hotdock)
            attributes["statehd"] = getEnumDomainDict(obs.observation.statehd)
        if len(attributes) > 0:
            observation["attributes"] = attributes
        
        data["observation"] = observation
        data["agent"] = getStringDict(obs.agent)
    except Exception as e:
        print(str(e))
    
    return data

def getHotdockstatusDict(inData):
    data = dict()
    data["timeline"] = "hotdockstatus"
    data["predicate"] = str(inData.predicate).split(".",1)[1]
    data["inittime"] = getIntervalDict(inData.inittime)
    data["endtime"] = getIntervalDict(inData.endtime)

    attributes = dict()
    attributes["pathfile"] = getStringdDict(inData.pathfile)
    
    if len(attributes) > 0:
        data["attributes"] = attributes

    return data
def tc_200_8_get_data(packet):
    try:
        data = dict()
        obs = pb.pus_tm_200_8_getHotdockstatusObservation(packet)
        
        observation = dict()
        observation["timeline"] = "hotdockstatus"
        observation["predicate"] = str(obs.observation.predicate).split(".",1)[1]

        attributes = dict() 
        if observation["predicate"] == "status":
            attributes["pathfile"] = getStringdDict(obs.observation.pathfile)
        if len(attributes) > 0:
            observation["attributes"] = attributes
        
        data["observation"] = observation
        data["agent"] = getStringDict(obs.agent)
    except Exception as e:
        print(str(e))
    
    return data

def getWmcmdDict(inData):
    data = dict()
    data["timeline"] = "wmcmd"
    data["predicate"] = str(inData.predicate).split(".",1)[1]
    data["inittime"] = getIntervalDict(inData.inittime)
    data["endtime"] = getIntervalDict(inData.endtime)

    attributes = dict()
    attributes["status"] = getEnumDomainDict(inData.status)
    attributes["hotdock"] = getStringdDict(inData.hotdock)
    attributes["slot"] = getSlotidDict(inData.slot)
    attributes["face"] = getStringdDict(inData.face)
    attributes["yaw"] = getEnumDomainDict(inData.yaw)
    
    if len(attributes) > 0:
        data["attributes"] = attributes

    return data
def tc_200_9_get_data(packet):
    try:
        data = dict()
        goal = pb.pus_tc_200_9_getWmcmdGoal(packet)
        data["goal"] = getWmcmdDict(goal.goal)
        data["agent"] = getStringDict(goal.agent)
    except Exception as e:
        print(str(e))
    
    return data
def tc_200_10_get_data(packet):
    try:
        data = dict()
        obs = pb.pus_tm_200_10_getWmcmdObservation(packet)
        
        observation = dict()
        observation["timeline"] = "wmcmd"
        observation["predicate"] = str(obs.observation.predicate).split(".",1)[1]

        attributes = dict() 
        if observation["predicate"] == "idle":
            attributes["status"] = getEnumDomainDict(obs.observation.status)
         
        if observation["predicate"] == "movetohd":
            attributes["hotdock"] = getStringdDict(obs.observation.hotdock)
         
        if observation["predicate"] == "movetoslot":
            attributes["slot"] = getSlotidDict(obs.observation.slot)
            attributes["face"] = getStringdDict(obs.observation.face)
            attributes["yaw"] = getEnumDomainDict(obs.observation.yaw)
        if len(attributes) > 0:
            observation["attributes"] = attributes
        
        data["observation"] = observation
        data["agent"] = getStringDict(obs.agent)
    except Exception as e:
        print(str(e))
    
    return data

def getBasecmdDict(inData):
    data = dict()
    data["timeline"] = "basecmd"
    data["predicate"] = str(inData.predicate).split(".",1)[1]
    data["inittime"] = getIntervalDict(inData.inittime)
    data["endtime"] = getIntervalDict(inData.endtime)

    attributes = dict()
    attributes["hotdock"] = getStringdDict(inData.hotdock)
    
    if len(attributes) > 0:
        data["attributes"] = attributes

    return data
def tc_200_11_get_data(packet):
    try:
        data = dict()
        goal = pb.pus_tc_200_11_getBasecmdGoal(packet)
        data["goal"] = getBasecmdDict(goal.goal)
        data["agent"] = getStringDict(goal.agent)
    except Exception as e:
        print(str(e))
    
    return data
def tc_200_12_get_data(packet):
    try:
        data = dict()
        obs = pb.pus_tm_200_12_getBasecmdObservation(packet)
        
        observation = dict()
        observation["timeline"] = "basecmd"
        observation["predicate"] = str(obs.observation.predicate).split(".",1)[1]

        attributes = dict() 
        if observation["predicate"] == "baseAt":
            attributes["hotdock"] = getStringdDict(obs.observation.hotdock)
         
        if observation["predicate"] == "switchBase":
            attributes["hotdock"] = getStringdDict(obs.observation.hotdock)
        
        if len(attributes) > 0:
            observation["attributes"] = attributes
        
        data["observation"] = observation
        data["agent"] = getStringDict(obs.agent)
    except Exception as e:
        print(str(e))
    
    return data

def getEfcmdDict(inData):
    data = dict()
    data["timeline"] = "efcmd"
    data["predicate"] = str(inData.predicate).split(".",1)[1]
    data["inittime"] = getIntervalDict(inData.inittime)
    data["endtime"] = getIntervalDict(inData.endtime)

    attributes = dict()
    attributes["status"] = getEnumDomainDict(inData.status)
    attributes["hotdock"] = getStringdDict(inData.hotdock)
    
    if len(attributes) > 0:
        data["attributes"] = attributes

    return data
def tc_200_13_get_data(packet):
    try:
        data = dict()
        goal = pb.pus_tc_200_13_getEfcmdGoal(packet)
        data["goal"] = getEfcmdDict(goal.goal)
        data["agent"] = getStringDict(goal.agent)
    except Exception as e:
        print(str(e))
    
    return data
def tc_200_14_get_data(packet):
    try:
        data = dict()
        obs = pb.pus_tm_200_14_getEfcmdObservation(packet)
        
        observation = dict()
        observation["timeline"] = "efcmd"
        observation["predicate"] = str(obs.observation.predicate).split(".",1)[1]

        attributes = dict() 
        if observation["predicate"] == "idle":
            attributes["status"] = getEnumDomainDict(obs.observation.status)
         
        if observation["predicate"] == "pick":
            attributes["hotdock"] = getStringdDict(obs.observation.hotdock)
        
        if len(attributes) > 0:
            observation["attributes"] = attributes
        
        data["observation"] = observation
        data["agent"] = getStringDict(obs.agent)
    except Exception as e:
        print(str(e))
    
    return data
 


def getBooldDict(param):
    value = dict()
    value["value"] = getIntDict(param.value)
    return value

def getIntdDict(param):
    value = dict()
    value["value"] = getIntDict(param.value)
    return value

def getFloatdDict(param):
    value = dict()
    value["value"] = getFloatDict(param.value)
    return value

def getStringdDict(param):
    value = dict()
    value["value"] = getStringDict(param.value)
    return value

def getInt2dDict(param):
    value = dict()
    value["x"] = getIntDict(param.x)
    value["y"] = getIntDict(param.y)
    return value

def getSlotidDict(param):
    value = dict()
    value["x"] = getIntDict(param.x)
    value["y"] = getIntDict(param.y)
    value["z"] = getIntDict(param.z)
    value["svc"] = getIntDict(param.svc)
    return value

def getPosition3DDict(param):
    value = dict()
    value["x"] = getFloatDict(param.x)
    value["y"] = getFloatDict(param.y)
    return value

def getQuaterniondDict(param):
    value = dict()
    value["x"] = getFloatDict(param.x)
    value["y"] = getFloatDict(param.y)
    return value


def getIntervalDict(param):
    value = dict()
    value["min"] = param.min
    value["max"] = param.max
    return value

def getFloatDict(param):
    value = param
    return value

def getIntDict(param):
    value = param
    return value

def getStringDict(param):
    return_str = np.array2string(np.array(param, copy=False))
    alternative_string = ""
    a = np.array(param, copy=False)
    if not a.size == 0:
        for x in np.nditer(a):
            #print(x)
            alternative_string = alternative_string + str(chr(x))
    else:
        alternative_string = "default"

    #print(alternative_string)

    return alternative_string

def getEnumDomainDict(param):
    value = dict()
    value["key"] = getStringDict(param.key)
    value["value"] = getIntDict(param.value)
    return value


def getBooldFromDict(param):
    value = pb.asn1SccBoold()
    value.value = getIntFromDict(param["value"])
    return value

def getIntdFromDict(param):
    value = pb.asn1SccIntd()
    value.value = getIntFromDict(param["value"])
    return value

def getFloatdFromDict(param):
    value = pb.asn1SccFloatd()
    value.value = getFloatFromDict(param["value"])
    return value

def getStringdFromDict(param):
    value = pb.asn1SccStringd()
    value.value = getStringFromDict(param["value"])
    return value

def getInt2dFromDict(param):
    value = pb.asn1SccInt2d()
    value.x = getIntFromDict(param["x"])
    value.y = getIntFromDict(param["y"])
    return value

def getSlotidFromDict(param):
    value = pb.asn1SccSlotid()
    value.x = getIntFromDict(param["x"])
    value.y = getIntFromDict(param["y"])
    value.z = getIntFromDict(param["z"])
    value.svc = getIntFromDict(param["svc"])
    return value

def getPosition3DFromDict(param):
    value = pb.asn1SccPosition3D()
    value.x = getFloatFromDict(param["x"])
    value.y = getFloatFromDict(param["y"])
    return value

def getQuaterniondFromDict(param):
    value = pb.asn1SccQuaterniond()
    value.x = getFloatFromDict(param["x"])
    value.y = getFloatFromDict(param["y"])
    return value


def getIntervalFromDict(param):
    value = pb.asn1SccIntegerIntervalDomain()
    value.min = param["min"]
    value.max = param["max"]
    return value

def getFloatFromDict(param):
    value = float(param)
    return value

def getIntFromDict(param):
    value = int(param)
    return value

def getStringFromDict(param):
    value = pb.asn1SccA_String(bytes(param, 'utf-8'))
    return value

def getEnumDomainFromDict(param):
    value = pb.asn1SccEnumDomain()
    value.key = getStringFromDict(param["key"])
    value.value = getIntFromDict(param["value"])
    return value