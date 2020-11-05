# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

from PusGui import pb
import numpy as np

# Only telecommands needed (default packets)
def mission_create_packets(packet, svc, msg, apid=0, seq=0):
    #ST 200
    if (svc, msg) == (200, 19):
        pb.pus_tc_200_19_createMissionRequest_(packet, apid, seq)
    
    elif (svc, msg) == (200, 13):
        pb.pus_tc_200_13_createSodmissionRequest_(packet, apid, seq)
    
    elif (svc, msg) == (200, 1):
        pb.pus_tc_200_1_createHotdockcmdRequest_(packet, apid, seq)
    
    elif (svc, msg) == (200, 5):
        pb.pus_tc_200_5_createWmcmdRequest_(packet, apid, seq)
    
    elif (svc, msg) == (200, 9):
        pb.pus_tc_200_9_createBasecmdRequest_(packet, apid, seq)
    
    elif (svc, msg) == (200, 11):
        pb.pus_tc_200_11_createEfcmdRequest_(packet, apid, seq)
        
 #ST 220
    elif (svc, msg) == (220, 1):
        pb.pus_tc_220_1_createNewTargetState_(packet, apid, seq)
    elif (svc, msg) == (220, 2):
        pb.pus_tc_200_2_createGetCurrentState(packet, apid, seq)

    else:
        pass
        
# Generic get data function for BOTH tms and tcs
def mission_get_data(packet, svc, msg):
    if (svc, msg) == (200, 18):
        data = tc_200_18_get_data(packet)
    elif (svc, msg) == (200, 20):
        data = tc_200_20_get_data(packet)
    elif (svc, msg) == (200, 19):
        data = tc_200_19_get_data(packet)
    elif (svc, msg) == (200, 14):
        data = tc_200_14_get_data(packet)
    elif (svc, msg) == (200, 13):
        data = tc_200_13_get_data(packet)
    elif (svc, msg) == (200, 2):
        data = tc_200_2_get_data(packet)
    elif (svc, msg) == (200, 1):
        data = tc_200_1_get_data(packet)
    elif (svc, msg) == (200, 4):
        data = tc_200_4_get_data(packet)
    elif (svc, msg) == (200, 6):
        data = tc_200_6_get_data(packet)
    elif (svc, msg) == (200, 5):
        data = tc_200_5_get_data(packet)
    elif (svc, msg) == (200, 10):
        data = tc_200_10_get_data(packet)
    elif (svc, msg) == (200, 9):
        data = tc_200_9_get_data(packet)
    elif (svc, msg) == (200, 12):
        data = tc_200_12_get_data(packet)
    elif (svc, msg) == (200, 11):
        data = tc_200_11_get_data(packet)
    elif (svc, msg) == (200, 8):
        data = tc_200_8_get_data(packet)
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
    elif (svc, msg) == (200, 19):
        packet = tc_200_19_set_data(packet, data)
    elif (svc, msg) == (200, 13):
        packet = tc_200_13_set_data(packet, data)
    elif (svc, msg) == (200, 1):
        packet = tc_200_1_set_data(packet, data)
    elif (svc, msg) == (200, 5):
        packet = tc_200_5_set_data(packet, data)
    elif (svc, msg) == (200, 9):
        packet = tc_200_9_set_data(packet, data)
    elif (svc, msg) == (200, 11):
        packet = tc_200_11_set_data(packet, data)
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
def tc_200_19_set_data(packet, data):
    goal = data["goal"]
    goalData = pb.pusSt200_19_Goal()
    goalData.agent = getStringFromDict(data["agent"])
    goalData.goal.inittime = getIntervalFromDict(goal["inittime"])
    goalData.goal.endtime = getIntervalFromDict(goal["endtime"])
    if goal["predicate"] == "idle":
        goalData.goal.predicate = pb.asn1SccMissionPred.idle
    elif goal["predicate"] == "place":
        goalData.goal.predicate = pb.asn1SccMissionPred.place
    elif goal["predicate"] == "loadinge3plan":
        goalData.goal.predicate = pb.asn1SccMissionPred.loadinge3plan
    else:
        print("Invalid predicate " + goal["predicate"] + ". Valid options are: idle, place, loadinge3plan, ")
    
    goalData.goal.sm = getStringdFromDict(goal["attributes"]["sm"])
    goalData.goal.slot = getStringdFromDict(goal["attributes"]["slot"])
    goalData.goal.orientation = getStringdFromDict(goal["attributes"]["orientation"])
    goalData.goal.file = getStringdFromDict(goal["attributes"]["file"])
    
    pb.pus_tc_200_19_setMissionGoal(packet, goalData)
    #pb.pus_tc_200_19_setMissionGoal(packet, goal)
    return packet
    

def tc_200_13_set_data(packet, data):
    goal = data["goal"]
    goalData = pb.pusSt200_13_Goal()
    goalData.agent = getStringFromDict(data["agent"])
    goalData.goal.inittime = getIntervalFromDict(goal["inittime"])
    goalData.goal.endtime = getIntervalFromDict(goal["endtime"])
    if goal["predicate"] == "picked":
        goalData.goal.predicate = pb.asn1SccSodmissionPred.picked
    elif goal["predicate"] == "idle":
        goalData.goal.predicate = pb.asn1SccSodmissionPred.idle
    elif goal["predicate"] == "pick":
        goalData.goal.predicate = pb.asn1SccSodmissionPred.pick
    elif goal["predicate"] == "dropsm":
        goalData.goal.predicate = pb.asn1SccSodmissionPred.dropsm
    elif goal["predicate"] == "changebase":
        goalData.goal.predicate = pb.asn1SccSodmissionPred.changebase
    elif goal["predicate"] == "executefromfile":
        goalData.goal.predicate = pb.asn1SccSodmissionPred.executefromfile
    else:
        print("Invalid predicate " + goal["predicate"] + ". Valid options are: picked, idle, pick, dropsm, changebase, executefromfile, ")
    
    goalData.goal.face = getStringdFromDict(goal["attributes"]["face"])
    goalData.goal.sm = getStringdFromDict(goal["attributes"]["sm"])
    goalData.goal.status = getActionstatusFromDict(goal["attributes"]["status"])
    goalData.goal.slot = getStringdFromDict(goal["attributes"]["slot"])
    goalData.goal.orientation = getStringdFromDict(goal["attributes"]["orientation"])
    goalData.goal.filename = getStringdFromDict(goal["attributes"]["filename"])
    
    pb.pus_tc_200_13_setSodmissionGoal(packet, goalData)
    #pb.pus_tc_200_13_setSodmissionGoal(packet, goal)
    return packet
    

def tc_200_1_set_data(packet, data):
    goal = data["goal"]
    goalData = pb.pusSt200_1_Goal()
    goalData.agent = getStringFromDict(data["agent"])
    goalData.goal.inittime = getIntervalFromDict(goal["inittime"])
    goalData.goal.endtime = getIntervalFromDict(goal["endtime"])
    if goal["predicate"] == "idle":
        goalData.goal.predicate = pb.asn1SccHotdockcmdPred.idle
    elif goal["predicate"] == "sendstate":
        goalData.goal.predicate = pb.asn1SccHotdockcmdPred.sendstate
    else:
        print("Invalid predicate " + goal["predicate"] + ". Valid options are: idle, sendstate, ")
    
    goalData.goal.status = getActionstatusFromDict(goal["attributes"]["status"])
    goalData.goal.sm = getStringdFromDict(goal["attributes"]["sm"])
    goalData.goal.hotdock = getStringdFromDict(goal["attributes"]["hotdock"])
    goalData.goal.hdstate = getStateidFromDict(goal["attributes"]["hdstate"])
    
    pb.pus_tc_200_1_setHotdockcmdGoal(packet, goalData)
    #pb.pus_tc_200_1_setHotdockcmdGoal(packet, goal)
    return packet
    

def tc_200_5_set_data(packet, data):
    goal = data["goal"]
    goalData = pb.pusSt200_5_Goal()
    goalData.agent = getStringFromDict(data["agent"])
    goalData.goal.inittime = getIntervalFromDict(goal["inittime"])
    goalData.goal.endtime = getIntervalFromDict(goal["endtime"])
    if goal["predicate"] == "idle":
        goalData.goal.predicate = pb.asn1SccWmcmdPred.idle
    elif goal["predicate"] == "movetohd":
        goalData.goal.predicate = pb.asn1SccWmcmdPred.movetohd
    elif goal["predicate"] == "movetoslot":
        goalData.goal.predicate = pb.asn1SccWmcmdPred.movetoslot
    elif goal["predicate"] == "error":
        goalData.goal.predicate = pb.asn1SccWmcmdPred.error
    else:
        print("Invalid predicate " + goal["predicate"] + ". Valid options are: idle, movetohd, movetoslot, error, ")
    
    goalData.goal.status = getActionstatusFromDict(goal["attributes"]["status"])
    goalData.goal.hdid = getStringdFromDict(goal["attributes"]["hdid"])
    goalData.goal.slot = getInt3dFromDict(goal["attributes"]["slot"])
    goalData.goal.face = getStringdFromDict(goal["attributes"]["face"])
    goalData.goal.yaw = getStringdFromDict(goal["attributes"]["yaw"])
    
    pb.pus_tc_200_5_setWmcmdGoal(packet, goalData)
    #pb.pus_tc_200_5_setWmcmdGoal(packet, goal)
    return packet
    

def tc_200_9_set_data(packet, data):
    goal = data["goal"]
    goalData = pb.pusSt200_9_Goal()
    goalData.agent = getStringFromDict(data["agent"])
    goalData.goal.inittime = getIntervalFromDict(goal["inittime"])
    goalData.goal.endtime = getIntervalFromDict(goal["endtime"])
    if goal["predicate"] == "baseat":
        goalData.goal.predicate = pb.asn1SccBasecmdPred.baseat
    elif goal["predicate"] == "switchbase":
        goalData.goal.predicate = pb.asn1SccBasecmdPred.switchbase
    elif goal["predicate"] == "error":
        goalData.goal.predicate = pb.asn1SccBasecmdPred.error
    
    else:
        print("Invalid predicate " + goal["predicate"] + ". Valid options are: baseat, switchbase, error, ")
    
    goalData.goal.hdid = getStringdFromDict(goal["attributes"]["hdid"])
    goalData.goal.status = getActionstatusFromDict(goal["attributes"]["status"])
    
    pb.pus_tc_200_9_setBasecmdGoal(packet, goalData)
    #pb.pus_tc_200_9_setBasecmdGoal(packet, goal)
    return packet
    

def tc_200_11_set_data(packet, data):
    goal = data["goal"]
    goalData = pb.pusSt200_11_Goal()
    goalData.agent = getStringFromDict(data["agent"])
    goalData.goal.inittime = getIntervalFromDict(goal["inittime"])
    goalData.goal.endtime = getIntervalFromDict(goal["endtime"])
    if goal["predicate"] == "idle":
        goalData.goal.predicate = pb.asn1SccEfcmdPred.idle
    elif goal["predicate"] == "picked":
        goalData.goal.predicate = pb.asn1SccEfcmdPred.picked
    elif goal["predicate"] == "error":
        goalData.goal.predicate = pb.asn1SccEfcmdPred.error
    elif goal["predicate"] == "pick":
        goalData.goal.predicate = pb.asn1SccEfcmdPred.pick
    elif goal["predicate"] == "drop":
        goalData.goal.predicate = pb.asn1SccEfcmdPred.drop
    
    else:
        print("Invalid predicate " + goal["predicate"] + ". Valid options are: idle, picked, error, pick, drop, ")
    
    goalData.goal.status = getActionstatusFromDict(goal["attributes"]["status"])
    goalData.goal.hdid = getStringdFromDict(goal["attributes"]["hdid"])
    
    pb.pus_tc_200_11_setEfcmdGoal(packet, goalData)
    #pb.pus_tc_200_11_setEfcmdGoal(packet, goal)
    return packet
    



def getPlannerDict(inData):
    data = dict()
    data["timeline"] = "planner"
    data["predicate"] = str(inData.predicate).split(".",1)[1]
    data["inittime"] = getIntervalDict(inData.inittime)
    data["endtime"] = getIntervalDict(inData.endtime)

    attributes = dict()
    
    if len(attributes) > 0:
        data["attributes"] = attributes

    return data
def tc_200_18_get_data(packet):
    try:
        data = dict()
        obs = pb.pus_tm_200_18_getPlannerObservation(packet)
        
        observation = dict()
        observation["timeline"] = "planner"
        observation["predicate"] = str(obs.observation.predicate).split(".",1)[1]

        attributes = dict()
        
        
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
    
    attributes["sm"] =getStringdDict(inData.sm)
    attributes["slot"] =getStringdDict(inData.slot)
    attributes["orientation"] =getStringdDict(inData.orientation)
    attributes["file"] =getStringdDict(inData.file)
    if len(attributes) > 0:
        data["attributes"] = attributes

    return data
def tc_200_19_get_data(packet):
    try:
        data = dict()
        goal = pb.pus_tc_200_19_getMissionGoal(packet)
        data["goal"] = getMissionDict(goal.goal)
        data["agent"] = getStringDict(goal.agent)
    except Exception as e:
        print(str(e))
    
    return data
def tc_200_20_get_data(packet):
    try:
        data = dict()
        obs = pb.pus_tm_200_20_getMissionObservation(packet)
        
        observation = dict()
        observation["timeline"] = "mission"
        observation["predicate"] = str(obs.observation.predicate).split(".",1)[1]

        attributes = dict()
         
        if observation["predicate"] == "place":
            attributes["sm"] =attributes["sm"] = getStringdDict(obs.observation.sm)
            attributes["slot"] =attributes["slot"] = getStringdDict(obs.observation.slot)
            attributes["orientation"] =attributes["orientation"] = getStringdDict(obs.observation.orientation)
         
        if observation["predicate"] == "loadinge3plan":
            attributes["file"] =attributes["file"] = getStringdDict(obs.observation.file)
        if len(attributes) > 0:
            observation["attributes"] = attributes
        
        data["observation"] = observation
        data["agent"] = getStringDict(obs.agent)
    except Exception as e:
        print(str(e))
    
    return data

def getSodmissionDict(inData):
    data = dict()
    data["timeline"] = "sodmission"
    data["predicate"] = str(inData.predicate).split(".",1)[1]
    data["inittime"] = getIntervalDict(inData.inittime)
    data["endtime"] = getIntervalDict(inData.endtime)

    attributes = dict()
    
    attributes["face"] =getStringdDict(inData.face)
    attributes["sm"] =getStringdDict(inData.sm)
    attributes["status"] =str(inData.status).split(".",1)[1]
    attributes["slot"] =getStringdDict(inData.slot)
    attributes["orientation"] =getStringdDict(inData.orientation)
    attributes["filename"] =getStringdDict(inData.filename)
    if len(attributes) > 0:
        data["attributes"] = attributes

    return data
def tc_200_13_get_data(packet):
    try:
        data = dict()
        goal = pb.pus_tc_200_13_getSodmissionGoal(packet)
        data["goal"] = getSodmissionDict(goal.goal)
        data["agent"] = getStringDict(goal.agent)
    except Exception as e:
        print(str(e))
    
    return data
def tc_200_14_get_data(packet):
    try:
        data = dict()
        obs = pb.pus_tm_200_14_getSodmissionObservation(packet)
        
        observation = dict()
        observation["timeline"] = "sodmission"
        observation["predicate"] = str(obs.observation.predicate).split(".",1)[1]

        attributes = dict() 
        if observation["predicate"] == "picked":
            attributes["face"] =attributes["face"] = getStringdDict(obs.observation.face)
            attributes["sm"] =attributes["sm"] = getStringdDict(obs.observation.sm)
         
        if observation["predicate"] == "idle":
            attributes["status"] =str(obs.observation.status).split(".",1)[1]
         
        if observation["predicate"] == "pick":
            attributes["face"] =attributes["face"] = getStringdDict(obs.observation.face)
            attributes["sm"] =attributes["sm"] = getStringdDict(obs.observation.sm)
         
        if observation["predicate"] == "dropsm":
            attributes["slot"] =attributes["slot"] = getStringdDict(obs.observation.slot)
            attributes["orientation"] =attributes["orientation"] = getStringdDict(obs.observation.orientation)
         
        if observation["predicate"] == "changebase":
            attributes["slot"] =attributes["slot"] = getStringdDict(obs.observation.slot)
         
        if observation["predicate"] == "executefromfile":
            attributes["filename"] =attributes["filename"] = getStringdDict(obs.observation.filename)
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
    
    attributes["status"] =str(inData.status).split(".",1)[1]
    attributes["sm"] =getStringdDict(inData.sm)
    attributes["hotdock"] =getStringdDict(inData.hotdock)
    attributes["hdstate"] =str(inData.hdstate).split(".",1)[1]
    if len(attributes) > 0:
        data["attributes"] = attributes

    return data
def tc_200_1_get_data(packet):
    try:
        data = dict()
        goal = pb.pus_tc_200_1_getHotdockcmdGoal(packet)
        data["goal"] = getHotdockcmdDict(goal.goal)
        data["agent"] = getStringDict(goal.agent)
    except Exception as e:
        print(str(e))
    
    return data
def tc_200_2_get_data(packet):
    try:
        data = dict()
        obs = pb.pus_tm_200_2_getHotdockcmdObservation(packet)
        
        observation = dict()
        observation["timeline"] = "hotdockcmd"
        observation["predicate"] = str(obs.observation.predicate).split(".",1)[1]

        attributes = dict() 
        if observation["predicate"] == "idle":
            attributes["status"] =str(obs.observation.status).split(".",1)[1]
         
        if observation["predicate"] == "sendstate":
            attributes["sm"] =attributes["sm"] = getStringdDict(obs.observation.sm)
            attributes["hotdock"] =attributes["hotdock"] = getStringdDict(obs.observation.hotdock)
            attributes["hdstate"] =str(obs.observation.hdstate).split(".",1)[1]
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
    
    attributes["pathfile"] =getStringdDict(inData.pathfile)
    if len(attributes) > 0:
        data["attributes"] = attributes

    return data
def tc_200_4_get_data(packet):
    try:
        data = dict()
        obs = pb.pus_tm_200_4_getHotdockstatusObservation(packet)
        
        observation = dict()
        observation["timeline"] = "hotdockstatus"
        observation["predicate"] = str(obs.observation.predicate).split(".",1)[1]

        attributes = dict() 
        if observation["predicate"] == "status":
            attributes["pathfile"] =attributes["pathfile"] = getStringdDict(obs.observation.pathfile)
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
    
    attributes["status"] =str(inData.status).split(".",1)[1]
    attributes["hdid"] =getStringdDict(inData.hdid)
    attributes["slot"] =getInt3dDict(inData.slot)
    attributes["face"] =getStringdDict(inData.face)
    attributes["yaw"] =getStringdDict(inData.yaw)
    if len(attributes) > 0:
        data["attributes"] = attributes

    return data
def tc_200_5_get_data(packet):
    try:
        data = dict()
        goal = pb.pus_tc_200_5_getWmcmdGoal(packet)
        data["goal"] = getWmcmdDict(goal.goal)
        data["agent"] = getStringDict(goal.agent)
    except Exception as e:
        print(str(e))
    
    return data
def tc_200_6_get_data(packet):
    try:
        data = dict()
        obs = pb.pus_tm_200_6_getWmcmdObservation(packet)
        
        observation = dict()
        observation["timeline"] = "wmcmd"
        observation["predicate"] = str(obs.observation.predicate).split(".",1)[1]

        attributes = dict() 
        if observation["predicate"] == "idle":
            attributes["status"] =str(obs.observation.status).split(".",1)[1]
         
        if observation["predicate"] == "movetohd":
            attributes["hdid"] =attributes["hdid"] = getStringdDict(obs.observation.hdid)
         
        if observation["predicate"] == "movetoslot":
            attributes["slot"] =attributes["slot"] = getInt3dDict(obs.observation.slot)
            attributes["face"] =attributes["face"] = getStringdDict(obs.observation.face)
            attributes["yaw"] =attributes["yaw"] = getStringdDict(obs.observation.yaw)
        
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
    
    attributes["hdid"] =getStringdDict(inData.hdid)
    attributes["status"] =str(inData.status).split(".",1)[1]
    if len(attributes) > 0:
        data["attributes"] = attributes

    return data
def tc_200_9_get_data(packet):
    try:
        data = dict()
        goal = pb.pus_tc_200_9_getBasecmdGoal(packet)
        data["goal"] = getBasecmdDict(goal.goal)
        data["agent"] = getStringDict(goal.agent)
    except Exception as e:
        print(str(e))
    
    return data
def tc_200_10_get_data(packet):
    try:
        data = dict()
        obs = pb.pus_tm_200_10_getBasecmdObservation(packet)
        
        observation = dict()
        observation["timeline"] = "basecmd"
        observation["predicate"] = str(obs.observation.predicate).split(".",1)[1]

        attributes = dict() 
        if observation["predicate"] == "baseat":
            attributes["hdid"] =attributes["hdid"] = getStringdDict(obs.observation.hdid)
            attributes["status"] =str(obs.observation.status).split(".",1)[1]
         
        if observation["predicate"] == "switchbase":
            attributes["hdid"] =attributes["hdid"] = getStringdDict(obs.observation.hdid)
        
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
    
    attributes["status"] =str(inData.status).split(".",1)[1]
    attributes["hdid"] =getStringdDict(inData.hdid)
    if len(attributes) > 0:
        data["attributes"] = attributes

    return data
def tc_200_11_get_data(packet):
    try:
        data = dict()
        goal = pb.pus_tc_200_11_getEfcmdGoal(packet)
        data["goal"] = getEfcmdDict(goal.goal)
        data["agent"] = getStringDict(goal.agent)
    except Exception as e:
        print(str(e))
    
    return data
def tc_200_12_get_data(packet):
    try:
        data = dict()
        obs = pb.pus_tm_200_12_getEfcmdObservation(packet)
        
        observation = dict()
        observation["timeline"] = "efcmd"
        observation["predicate"] = str(obs.observation.predicate).split(".",1)[1]

        attributes = dict() 
        if observation["predicate"] == "idle":
            attributes["status"] =str(obs.observation.status).split(".",1)[1]
         
        if observation["predicate"] == "picked":
            attributes["hdid"] =attributes["hdid"] = getStringdDict(obs.observation.hdid)
        
         
        if observation["predicate"] == "pick":
            attributes["hdid"] =attributes["hdid"] = getStringdDict(obs.observation.hdid)
        
        if len(attributes) > 0:
            observation["attributes"] = attributes
        
        data["observation"] = observation
        data["agent"] = getStringDict(obs.agent)
    except Exception as e:
        print(str(e))
    
    return data

def getWmstatusDict(inData):
    data = dict()
    data["timeline"] = "wmstatus"
    data["predicate"] = str(inData.predicate).split(".",1)[1]
    data["inittime"] = getIntervalDict(inData.inittime)
    data["endtime"] = getIntervalDict(inData.endtime)

    attributes = dict()
    
    attributes["pathfile"] =getStringdDict(inData.pathfile)
    if len(attributes) > 0:
        data["attributes"] = attributes

    return data
def tc_200_8_get_data(packet):
    try:
        data = dict()
        obs = pb.pus_tm_200_8_getWmstatusObservation(packet)
        
        observation = dict()
        observation["timeline"] = "wmstatus"
        observation["predicate"] = str(obs.observation.predicate).split(".",1)[1]

        attributes = dict() 
        if observation["predicate"] == "status":
            attributes["pathfile"] =attributes["pathfile"] = getStringdDict(obs.observation.pathfile)
        if len(attributes) > 0:
            observation["attributes"] = attributes
        
        data["observation"] = observation
        data["agent"] = getStringDict(obs.agent)
    except Exception as e:
        print(str(e))
    
    return data
 


def getBooldDict(param):
    value = dict()
    value["value"] =getIntDict(param.value)
    return value

def getIntdDict(param):
    value = dict()
    value["value"] =getIntDict(param.value)
    return value

def getFloatdDict(param):
    value = dict()
    value["value"] =getFloatDict(param.value)
    return value

def getStringdDict(param):
    value = dict()
    value["value"] =getStringDict(param.value)
    return value

def getInt2dDict(param):
    value = dict()
    value["x"] =getIntDict(param.x)
    value["y"] =getIntDict(param.y)
    return value

def getInt3dDict(param):
    value = dict()
    value["x"] =getIntDict(param.x)
    value["y"] =getIntDict(param.y)
    value["z"] =getIntDict(param.z)
    return value

def getPosition3DDict(param):
    value = dict()
    value["x"] =getFloatDict(param.x)
    value["y"] =getFloatDict(param.y)
    return value

def getQuaterniondDict(param):
    value = dict()
    value["x"] =getFloatDict(param.x)
    value["y"] =getFloatDict(param.y)
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

def getInt3dFromDict(param):
    value = pb.asn1SccInt3d()
    value.x = getIntFromDict(param["x"])
    value.y = getIntFromDict(param["y"])
    value.z = getIntFromDict(param["z"])
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


def getActionstatusFromDict(value):
    
    if value == "success":
        return pb.asn1SccActionstatusEnum.success
    if value == "failed":
        return pb.asn1SccActionstatusEnum.failed
    if value == "notachievable":
        return pb.asn1SccActionstatusEnum.notachievable
    if value == "notenoughtime":
        return pb.asn1SccActionstatusEnum.notenoughtime
    else:
        return pb.asn1SccActionstatusEnum.unknown

def getStateidFromDict(value):
    
    if value == "offline":
        return pb.asn1SccStateidEnum.offline
    if value == "idle":
        return pb.asn1SccStateidEnum.idle
    if value == "latched":
        return pb.asn1SccStateidEnum.latched
    if value == "locked":
        return pb.asn1SccStateidEnum.locked
    if value == "connected":
        return pb.asn1SccStateidEnum.connected
    else:
        return pb.asn1SccStateidEnum.unknown
