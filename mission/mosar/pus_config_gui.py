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

 #ST 210
    elif (svc, msg) == (210, 1):
        pb.pus_tc_210_1_createSpwRoutingTableSetEntry(packet, apid, seq, 0, 0, 0, 0)
    elif (svc, msg) == (210, 2):
        pb.pus_tc_210_2_createSpwPnpSetOwnerFields(packet, apid, seq, 0, 0, 0)
    elif (svc, msg) == (210, 11):
        pb.pus_tc_210_11_createConfigureTimeEpoch(packet, apid, seq, 0, 0, 0, 0)
    elif (svc, msg) == (210, 12):
        pb.pus_tc_210_12_createSetLeds(packet, apid, seq, 0, 0, 0)
    elif (svc, msg) == (210, 21):
        pb.pus_tc_210_21_createSetHouskeepingDataRate(packet, apid, seq, 0, 0, 0, 0)
    elif (svc, msg) == (210, 22):
        pb.pus_tc_210_22_createGoToState(packet, apid, seq, 0, 0, 0, 0)
    elif (svc, msg) == (210, 23):
        pb.pus_tc_210_23_createCommandP15VLine(packet, apid, seq, 0, 0, 0, 0)
    elif (svc, msg) == (210, 24):
        pb.pus_tc_210_24_createCommandP2V5Line(packet, apid, seq, 0, 0, 0, 0)
    elif (svc, msg) == (210, 25):
        pb.pus_tc_210_25_createCoomdadRelay(packet, apid, seq, 0, 0, 0, 0)
    elif (svc, msg) == (210, 26):
        pb.pus_tc_210_26_createSetLvdsPins(packet, apid, seq, 0, 0, 0, 0, 0)
    elif (svc, msg) == (210, 27):
        pb.pus_tc_210_27_createPowerOnOffMotor(packet, apid, seq, 0, 0, 0, 0)
    elif (svc, msg) == (210, 28):
        pb.pus_tc_210_28_createSetMotorSpeed(packet, apid, seq, 0, 0, 0, 0)
    elif (svc, msg) == (210, 29):
        pb.pus_tc_210_29_createSetMotorDirection(packet, apid, seq, 0, 0, 0, 0)
    elif (svc, msg) == (210, 30):
        pb.pus_tc_210_30_createSetMotorCurrentLimit(packet, apid, seq, 0, 0, 0, 0)
    elif (svc, msg) == (210, 31):
        pb.pus_tc_210_31_createCalibrateController(packet, apid, seq, 0, 0, 0, 0)
    elif (svc, msg) == (210, 32):
        pb.pus_tc_210_32_createResetController(packet, apid, seq, 0, 0, 0)
    elif (svc, msg) == (210, 41):
        pb.pus_tc_210_41_createOspControlCommand(packet, apid, seq, 0, 0, 0)
    elif (svc, msg) == (210, 42):
        pb.pus_tc_210_42_createCaptureImage(packet, apid, seq, 0, 0)
    elif (svc, msg) == (210, 61):
        pb.pus_tc_210_61_createHk1Request(packet, apid, seq, 0, 0)
    elif (svc, msg) == (210, 62):
        pb.pus_tc_210_62_createAllHkRequest(packet, apid, seq, 0, 0)
    elif (svc, msg) == (210, 63):
        pb.pus_tc_210_63_createCommand48VConverter(packet, apid, seq, 0, 0, 0)
    elif (svc, msg) == (210, 64):
        pb.pus_tc_210_64_createCommandBatCharger(packet, apid, seq, 0, 0, 0)
    elif (svc, msg) == (210, 72):
        pb.pus_tc_210_72_createCartesianGoal(packet, apid, seq, 0, 0)
    elif (svc, msg) == (210, 73):
        pb.pus_tc_210_73_createInterfaceCommand(packet, apid, seq, 0, 0, 0, 0, 0, 0)
    elif (svc, msg) == (210, 81):
        pb.pus_tc_210_81_createModeCommand(packet, apid, seq, 0, 0, 0)
    elif (svc, msg) == (210, 82):
        pb.pus_tc_210_82_createComponentsCommand(packet, apid, seq, 0, 0, 0, 0)
    elif (svc, msg) == (210, 91):
        pb.pus_tc_210_91_createSpecificHkRequest(packet, apid, seq, 0, 0, 0, 0)
    elif (svc, msg) == (210, 92):
        pb.pus_tc_210_92_createAllHkRequest(packet, apid, seq, 0, 0, 0)
    elif (svc, msg) == (210, 93):
        pb.pus_tc_210_93_createCommandSwitch1(packet, apid, seq, 0, 0, 0, 0, 0, 0, 0, 0)
    elif (svc, msg) == (210, 94):
        pb.pus_tc_210_94_createCommand24VConverterA(packet, apid, seq, 0, 0, 0, 0, 0, 0, 0)


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
    elif (svc, msg) == (200, 16):
        data = tc_200_16_get_data(packet)          
    #ST 210
    elif (svc, msg) == (210, 1):
        data = pus_tc_210_1_get_data(packet)
    elif (svc, msg) == (210, 2):
        data = pus_tc_210_2_get_data(packet)
    elif (svc, msg) == (210, 11):
        data = pus_tc_210_11_get_data(packet)
    elif (svc, msg) == (210, 12):
        data = pus_tc_210_12_get_data(packet)
    elif (svc, msg) == (210, 21):
        data = pus_tc_210_21_get_data(packet)
    elif (svc, msg) == (210, 22):
        data = pus_tc_210_22_get_data(packet)
    elif (svc, msg) == (210, 23):
        data = pus_tc_210_23_get_data(packet)
    elif (svc, msg) == (210, 24):
        data = pus_tc_210_24_get_data(packet)
    elif (svc, msg) == (210, 25):
        data = pus_tc_210_25_get_data(packet)
    elif (svc, msg) == (210, 26):
        data = pus_tc_210_26_get_data(packet)
    elif (svc, msg) == (210, 27):
        data = pus_tc_210_27_get_data(packet)
    elif (svc, msg) == (210, 28):
        data = pus_tc_210_28_get_data(packet)
    elif (svc, msg) == (210, 29):
        data = pus_tc_210_29_get_data(packet)
    elif (svc, msg) == (210, 30):
        data = pus_tc_210_30_get_data(packet)
    elif (svc, msg) == (210, 31):
        data = pus_tc_210_31_get_data(packet)
    elif (svc, msg) == (210, 32):
        data = pus_tc_210_32_get_data(packet)
    elif (svc, msg) == (210, 41):
        data = pus_tc_210_41_get_data(packet)
    elif (svc, msg) == (210, 42):
        data = pus_tc_210_42_get_data(packet) 
    elif (svc, msg) == (210, 61):
        data = pus_tc_210_61_get_data(packet)
    elif (svc, msg) == (210, 62):
        data = pus_tc_210_62_get_data(packet)
    elif (svc, msg) == (210, 63):
        data = pus_tc_210_63_get_data(packet)
    elif (svc, msg) == (210, 64):
        data = pus_tc_210_64_get_data(packet)  
    elif (svc, msg) == (210, 72):
        data = pus_tc_210_72_get_data(packet)
    elif (svc, msg) == (210, 73):
        data = pus_tc_210_73_get_data(packet)
    elif (svc, msg) == (210, 81):
        data = pus_tc_210_81_get_data(packet)
    elif (svc, msg) == (210, 82):
        data = pus_tc_210_82_get_data(packet)
    elif (svc, msg) == (210, 91):
        data = pus_tc_210_91_get_data(packet)
    elif (svc, msg) == (210, 92):
        data = pus_tc_210_92_get_data(packet)
    elif (svc, msg) == (210, 93):
        data = pus_tc_210_93_get_data(packet)
    elif (svc, msg) == (210, 94):
        data = pus_tc_210_94_get_data(packet)
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
    if (svc, msg) == (200, 19):
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
    
    # ST 210
    elif (svc, msg) == (210, 1):
        packet = pus_tc_210_1_set_data(packet, data)
    elif (svc, msg) == (210, 2):
        packet = pus_tc_210_2_set_data(packet, data)
    elif (svc, msg) == (210, 11):
        packet = pus_tc_210_11_set_data(packet, data)
    elif (svc, msg) == (210, 12):
        packet = pus_tc_210_12_set_data(packet, data)
    elif (svc, msg) == (210, 21):
        packet = pus_tc_210_21_set_data(packet, data)
    elif (svc, msg) == (210, 22):
        packet = pus_tc_210_22_set_data(packet, data)
    elif (svc, msg) == (210, 23):
        packet = pus_tc_210_23_set_data(packet, data)
    elif (svc, msg) == (210, 24):
        packet = pus_tc_210_24_set_data(packet, data)
    elif (svc, msg) == (210, 25):
        packet = pus_tc_210_25_set_data(packet, data)
    elif (svc, msg) == (210, 26):
        packet = pus_tc_210_26_set_data(packet, data)
    elif (svc, msg) == (210, 27):
        packet = pus_tc_210_27_set_data(packet, data)
    elif (svc, msg) == (210, 28):
        packet = pus_tc_210_28_set_data(packet, data)
    elif (svc, msg) == (210, 29):
        packet = pus_tc_210_29_set_data(packet, data)
    elif (svc, msg) == (210, 30):
        packet = pus_tc_210_30_set_data(packet, data)
    elif (svc, msg) == (210, 31):
        packet = pus_tc_210_31_set_data(packet, data)
    elif (svc, msg) == (210, 32):
        packet = pus_tc_210_32_set_data(packet, data)
    elif (svc, msg) == (210, 41):
        packet = pus_tc_210_41_set_data(packet, data)
    elif (svc, msg) == (210, 42):
        packet = pus_tc_210_42_set_data(packet, data)
    elif (svc, msg) == (210, 61):
        packet = pus_tc_210_61_set_data(packet, data)
    elif (svc, msg) == (210, 62):
        packet = pus_tc_210_62_set_data(packet, data)
    elif (svc, msg) == (210, 63):
        packet = pus_tc_210_63_set_data(packet, data)
    elif (svc, msg) == (210, 64):
        packet = pus_tc_210_64_set_data(packet, data)
    elif (svc, msg) == (210, 72):
        packet = pus_tc_210_72_set_data(packet, data)
    elif (svc, msg) == (210, 73):
        packet = pus_tc_210_73_set_data(packet, data)
    elif (svc, msg) == (210, 81):
        packet = pus_tc_210_81_set_data(packet, data)
    elif (svc, msg) == (210, 82):
        packet = pus_tc_210_82_set_data(packet, data)
    elif (svc, msg) == (210, 91):
        packet = pus_tc_210_91_set_data(packet, data)
    elif (svc, msg) == (210, 92):
        packet = pus_tc_210_92_set_data(packet, data)
    elif (svc, msg) == (210, 93):
        packet = pus_tc_210_93_set_data(packet, data)
    elif (svc, msg) == (210, 94):
        packet = pus_tc_210_94_set_data(packet, data)

    # ST 220
    elif (svc, msg) == (220, 1):
        packet = tc_220_1_set_data(packet, data) 

# Specific get and set functions ST 210
def pus_tc_210_1_set_data(packet, data):
    smId = int(data["smId"])
    componentId = int(data["componentId"])
    routingEntry = int(data["setRoutingEntry"])
    spwTrafficPriority = int(data["spwTrafficPriority"])

    pb.pus_tc_210_1_setParamSM_ID(packet, smId)
    pb.pus_tc_210_1_setParamCOMP_ID(packet, componentId)
    pb.pus_tc_210_1_setParamSetRoutingEntry(packet, routingEntry)
    pb.pus_tc_210_1_setParamSpwTrafficPriority(packet, spwTrafficPriority)
    return packet

def pus_tc_210_1_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_1_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_1_getParamCOMP_ID(packet)
    data["setRoutingEntry"] = pb.pus_tc_210_1_getParamSetRoutingEntry(packet)
    data["spwTrafficPriority"] = pb.pus_tc_210_1_getParamSpwTrafficPriority(packet)
    return data

def pus_tc_210_2_set_data(packet, data):
    pb.pus_tc_210_2_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_2_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_2_setParamSetOwner(packet, int(data["setOwner"]))
    return packet

def pus_tc_210_2_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_2_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_2_getParamCOMP_ID(packet)
    data["setOwner"] = pb.pus_tc_210_2_getParamSetOwner(packet)
    return data


def pus_tc_210_11_set_data(packet, data):
    pb.pus_tc_210_11_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_11_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_11_setParamSecsSinceEpoch(packet, int(data["secsSinceEpoch"]))
    pb.pus_tc_210_11_setParamNanosecsSinceEpoch(packet, int(data["nanosecsSinceEpoch"]))
    return packet

def pus_tc_210_11_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_11_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_11_getParamCOMP_ID(packet)
    data["secsSinceEpoch"] = pb.pus_tc_210_11_getParamSecsSinceEpoch(packet)
    data["nanosecsSinceEpoch"] = pb.pus_tc_210_11_getParamNanosecsSinceEpoch(packet)
    return data

def pus_tc_210_12_set_data(packet, data):
    pb.pus_tc_210_12_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_12_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_12_setParamSetLeds(packet, int(data["setLeds"]))
    return packet

def pus_tc_210_12_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_12_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_12_getParamCOMP_ID(packet)
    data["setLeds"] = pb.pus_tc_210_12_getParamSetLeds(packet)
    return data

def pus_tc_210_21_set_data(packet, data):
    pb.pus_tc_210_21_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_21_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_21_setParamSUBCOMP_ID(packet, int(data["subcomponentId"]))
    pb.pus_tc_210_21_setParamPollingHkTm(packet, int(data["pollingHkTm"]))
    return packet

def pus_tc_210_21_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_21_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_21_getParamCOMP_ID(packet)
    data["subcomponentId"] = pb.pus_tc_210_21_getParamSUBCOMP_ID(packet)
    data["pollingHkTm"] = pb.pus_tc_210_21_getParamPollingHkTm(packet)
    return data

def pus_tc_210_22_set_data(packet, data):
    pb.pus_tc_210_22_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_22_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_22_setParamSUBCOMP_ID(packet, int(data["subcomponentId"]))
    pb.pus_tc_210_22_setParamTargetState(packet, int(data["targetState"]))
    return packet

def pus_tc_210_22_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_22_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_22_getParamCOMP_ID(packet)
    data["subcomponentId"] = pb.pus_tc_210_22_getParamSUBCOMP_ID(packet)
    data["targetState"] = pb.pus_tc_210_22_getParamTargetState(packet)
    return data

def pus_tc_210_23_set_data(packet, data):
    pb.pus_tc_210_23_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_23_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_23_setParamSUBCOMP_ID(packet, int(data["subcomponentId"]))
    pb.pus_tc_210_23_setParamP15vCmd(packet, int(data["p15vCmd"]))
    return packet

def pus_tc_210_23_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_23_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_23_getParamCOMP_ID(packet)
    data["subcomponentId"] = pb.pus_tc_210_23_getParamSUBCOMP_ID(packet)
    data["p15vCmd"] = pb.pus_tc_210_23_getParamP15vCmd(packet)
    return data

def pus_tc_210_24_set_data(packet, data):
    pb.pus_tc_210_24_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_24_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_24_setParamSUBCOMP_ID(packet, int(data["subcomponentId"]))
    pb.pus_tc_210_24_setParamP2v5Cmd(packet, int(data["p2v5Cmd"]))
    return packet

def pus_tc_210_24_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_24_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_24_getParamCOMP_ID(packet)
    data["subcomponentId"] = pb.pus_tc_210_24_getParamSUBCOMP_ID(packet)
    data["p2v5Cmd"] = pb.pus_tc_210_24_getParamP2v5Cmd(packet)
    return data

def pus_tc_210_25_set_data(packet, data):
    pb.pus_tc_210_25_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_25_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_25_setParamSUBCOMP_ID(packet, int(data["subcomponentId"]))
    pb.pus_tc_210_25_setParamRelayCmd(packet, int(data["relayCmd"]))
    return packet

def pus_tc_210_25_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_25_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_25_getParamCOMP_ID(packet)
    data["subcomponentId"] = pb.pus_tc_210_25_getParamSUBCOMP_ID(packet)
    data["relayCmd"] = pb.pus_tc_210_25_getParamRelayCmd(packet)
    return data

def pus_tc_210_26_set_data(packet, data):
    pb.pus_tc_210_26_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_26_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_26_setParamSUBCOMP_ID(packet, int(data["subcomponentId"]))
    pb.pus_tc_210_26_setParamLvdsACmd(packet, int(data["lvdsACmd"]))
    pb.pus_tc_210_26_setParamLvdsBCmd(packet, int(data["lvdsBCmd"]))
    return packet

def pus_tc_210_26_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_26_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_26_getParamCOMP_ID(packet)
    data["subcomponentId"] = pb.pus_tc_210_26_getParamSUBCOMP_ID(packet)
    data["lvdsACmd"] = pb.pus_tc_210_26_getParamLvdsACmd(packet)
    data["lvdsBCmd"] = pb.pus_tc_210_26_getParamLvdsBCmd(packet)
    return data

def pus_tc_210_27_set_data(packet, data):
    pb.pus_tc_210_27_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_27_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_27_setParamSUBCOMP_ID(packet, int(data["subcomponentId"]))
    pb.pus_tc_210_27_setParamMotorOnOff(packet, int(data["motorOnOff"]))
    return packet

def pus_tc_210_27_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_27_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_27_getParamCOMP_ID(packet)
    data["subcomponentId"] = pb.pus_tc_210_27_getParamSUBCOMP_ID(packet)
    data["motorOnOff"] = pb.pus_tc_210_27_getParamMotorOnOff(packet)
    return data

def pus_tc_210_28_set_data(packet, data):
    pb.pus_tc_210_28_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_28_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_28_setParamSUBCOMP_ID(packet, int(data["subcomponentId"]))
    pb.pus_tc_210_28_setParamMotorTargetSpeed(packet, float(data["motorTargetSpeed"]))
    return packet

def pus_tc_210_28_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_28_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_28_getParamCOMP_ID(packet)
    data["subcomponentId"] = pb.pus_tc_210_28_getParamSUBCOMP_ID(packet)
    data["motorTargetSpeed"] = pb.pus_tc_210_28_getParamMotorTargetSpeed(packet)
    return data

def pus_tc_210_29_set_data(packet, data):
    pb.pus_tc_210_29_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_29_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_29_setParamSUBCOMP_ID(packet, int(data["subcomponentId"]))
    pb.pus_tc_210_29_setParamMotorDirectionSpeed(packet, int(data["motorDirectionSpeed"]))
    return packet

def pus_tc_210_29_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_29_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_29_getParamCOMP_ID(packet)
    data["subcomponentId"] = pb.pus_tc_210_29_getParamSUBCOMP_ID(packet)
    data["motorDirectionSpeed"] = pb.pus_tc_210_29_getParamMotorDirectionSpeed(packet)
    return data

def pus_tc_210_30_set_data(packet, data):
    pb.pus_tc_210_30_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_30_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_30_setParamSUBCOMP_ID(packet, int(data["subcomponentId"]))
    pb.pus_tc_210_30_setParamMotorCurrentLimit(packet, float(data["motorCurrentLimit"]))
    return packet

def pus_tc_210_30_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_30_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_30_getParamCOMP_ID(packet)
    data["subcomponentId"] = pb.pus_tc_210_30_getParamSUBCOMP_ID(packet)
    data["motorCurrentLimit"] = pb.pus_tc_210_30_getParamMotorCurrentLimit(packet)
    return data

def pus_tc_210_31_set_data(packet, data):
    pb.pus_tc_210_31_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_31_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_31_setParamSUBCOMP_ID(packet, int(data["subcomponentId"]))
    pb.pus_tc_210_31_setParamControllerCalib(packet, int(data["controllerCalib"]))
    return packet

def pus_tc_210_31_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_31_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_31_getParamCOMP_ID(packet)
    data["subcomponentId"] = pb.pus_tc_210_31_getParamSUBCOMP_ID(packet)
    data["controllerCalib"] = pb.pus_tc_210_31_getParamControllerCalib(packet)
    return data

def pus_tc_210_32_set_data(packet, data):
    pb.pus_tc_210_32_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_32_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_32_setParamSUBCOMP_ID(packet, int(data["subcomponentId"]))
    return packet

def pus_tc_210_32_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_32_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_32_getParamCOMP_ID(packet)
    data["subcomponentId"] = pb.pus_tc_210_32_getParamSUBCOMP_ID(packet)
    return data

def pus_tc_210_41_set_data(packet, data):
    pb.pus_tc_210_41_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_41_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_41_setParamCommand(packet, int(data["command"]))
    return packet

def pus_tc_210_41_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_41_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_41_getParamCOMP_ID(packet)
    data["command"] = pb.pus_tc_210_41_getParamCommand(packet)
    return data

def pus_tc_210_42_set_data(packet, data):
    pb.pus_tc_210_42_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_42_setParamCOMP_ID(packet, int(data["componentId"]))
    return packet

def pus_tc_210_42_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_42_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_42_getParamCOMP_ID(packet)
    return data

def pus_tc_210_61_set_data(packet, data):
    pb.pus_tc_210_61_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_61_setParamCOMP_ID(packet, int(data["componentId"]))
    return packet

def pus_tc_210_61_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_61_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_61_getParamCOMP_ID(packet)
    return data

def pus_tc_210_62_set_data(packet, data):
    pb.pus_tc_210_62_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_62_setParamCOMP_ID(packet, int(data["componentId"]))
    return packet

def pus_tc_210_62_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_62_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_62_getParamCOMP_ID(packet)
    return data

def pus_tc_210_63_set_data(packet, data):
    pb.pus_tc_210_63_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_63_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_63_setParamConv48vCmd(packet, int(data["conv48vCmd"]))
    return packet

def pus_tc_210_63_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_63_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_63_getParamCOMP_ID(packet)
    data["conv48vCmd"] = pb.pus_tc_210_63_getParamConv48vCmd(packet)
    return data

def pus_tc_210_64_set_data(packet, data):
    pb.pus_tc_210_64_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_64_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_64_setParamBatChCmd(packet, int(data["batChCmd"]))
    return packet

def pus_tc_210_64_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_64_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_64_getParamCOMP_ID(packet)
    data["batChCmd"] = pb.pus_tc_210_64_getParamBatChCmd(packet)
    return data

def pus_tc_210_72_set_data(packet, data):
    pb.pus_tc_210_72_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_72_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_72_setParamDesiredPose(packet, data["desiredPose"])
    return packet

def pus_tc_210_72_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_72_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_72_getParamCOMP_ID(packet)
    data["desiredPose"] = pb.pus_tc_210_72_getParamDesiredPose(packet)
    print(data)
    return data

def pus_tc_210_73_set_data(packet, data):
    pb.pus_tc_210_73_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_73_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_73_setParamMode(packet, int(data["mode"]))
    pb.pus_tc_210_73_setParamHdId(packet, int(data["hdId"]))
    pb.pus_tc_210_73_setParamManipulatorBase(packet, int(data["manipulatorBase"]))
    pb.pus_tc_210_73_setParamGraspRelease(packet, int(data["graspRelease"]))
    return packet

def pus_tc_210_73_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_73_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_73_getParamCOMP_ID(packet)
    data["mode"] = pb.pus_tc_210_73_getParamMode(packet)
    data["hdId"] = pb.pus_tc_210_73_getParamHdId(packet)
    data["manipulatorBase"] = pb.pus_tc_210_73_getParamManipulatorBase(packet)
    data["graspRelease"] = pb.pus_tc_210_73_getParamGraspRelease(packet)
    return data

def pus_tc_210_81_set_data(packet, data):
    pb.pus_tc_210_81_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_81_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_81_setParamTargetMode(packet, int(data["targetMode"]))
    return packet

def pus_tc_210_81_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_81_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_81_getParamCOMP_ID(packet)
    data["targetMode"] = pb.pus_tc_210_81_getParamTargetMode(packet)
    return data

def pus_tc_210_82_set_data(packet, data):
    pb.pus_tc_210_82_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_82_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_82_setParamComponentTargetId(packet, int(data["componentTargetId"]))
    pb.pus_tc_210_82_setParamComponentTargetStatus(packet, int(data["componentTargetStatus"]))
    return packet

def pus_tc_210_82_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_82_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_82_getParamCOMP_ID(packet)
    data["componentTargetId"] = pb.pus_tc_210_82_getParamComponentTargetId(packet)
    data["componentTargetStatus"] = pb.pus_tc_210_82_getParamComponentTargetStatus(packet)
    return data

def pus_tc_210_91_set_data(packet, data):
    pb.pus_tc_210_91_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_91_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_91_setParamSUBCOMP_ID(packet, int(data["subcomponentId"]))
    pb.pus_tc_210_91_setParamHkXRequest(packet, int(data["hkXRequest"]))
    return packet

def pus_tc_210_91_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_91_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_91_getParamCOMP_ID(packet)
    data["subcomponentId"] = pb.pus_tc_210_91_getParamSUBCOMP_ID(packet)
    data["hkXRequest"] = pb.pus_tc_210_91_getParamHkXRequest(packet)
    return data

def pus_tc_210_92_set_data(packet, data):
    pb.pus_tc_210_92_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_92_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_92_setParamSUBCOMP_ID(packet, int(data["subcomponentId"]))
    return packet

def pus_tc_210_92_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_92_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_92_getParamCOMP_ID(packet)
    data["subcomponentId"] = pb.pus_tc_210_92_getParamSUBCOMP_ID(packet)
    return data

def pus_tc_210_93_set_data(packet, data):
    pb.pus_tc_210_93_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_93_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_93_setParamSUBCOMP_ID(packet, int(data["subcomponentId"]))
    pb.pus_tc_210_93_setParamSw1Cmd(packet, int(data["sw1Cmd"]))
    pb.pus_tc_210_93_setParamSw2Cmd(packet, int(data["sw2Cmd"]))
    pb.pus_tc_210_93_setParamSw3Cmd(packet, int(data["sw3Cmd"]))
    pb.pus_tc_210_93_setParamSw4Cmd(packet, int(data["sw4Cmd"]))
    pb.pus_tc_210_93_setParamSw5Cmd(packet, int(data["sw5Cmd"]))
    return packet

def pus_tc_210_93_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_93_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_93_getParamCOMP_ID(packet)
    data["subcomponentId"] = pb.pus_tc_210_93_getParamSUBCOMP_ID(packet)
    data["sw1Cmd"] = pb.pus_tc_210_93_getParamSw1Cmd(packet)
    data["sw2Cmd"] = pb.pus_tc_210_93_getParamSw2Cmd(packet)
    data["sw3Cmd"] = pb.pus_tc_210_93_getParamSw3Cmd(packet)
    data["sw4Cmd"] = pb.pus_tc_210_93_getParamSw4Cmd(packet)
    data["sw5Cmd"] = pb.pus_tc_210_93_getParamSw5Cmd(packet)
    return data

def pus_tc_210_94_set_data(packet, data):
    pb.pus_tc_210_94_setParamSM_ID(packet, int(data["smId"]))
    pb.pus_tc_210_94_setParamCOMP_ID(packet, int(data["componentId"]))
    pb.pus_tc_210_94_setParamSUBCOMP_ID(packet, int(data["subcomponentId"]))
    pb.pus_tc_210_94_setParamConv24vACmd(packet, int(data["conv24vACmd"]))
    pb.pus_tc_210_94_setParamConv24vBCmd(packet, int(data["conv24vBCmd"]))
    pb.pus_tc_210_94_setParamConv12vCmd(packet, int(data["conv12vCmd"]))
    pb.pus_tc_210_94_setParamConv19vCmd(packet, int(data["conv19vCmd"]))
    return packet

def pus_tc_210_94_get_data(packet):
    data = dict()
    data["smId"] = pb.pus_tc_210_94_getParamSM_ID(packet)
    data["componentId"] = pb.pus_tc_210_94_getParamCOMP_ID(packet)
    data["subcomponentId"] = pb.pus_tc_210_94_getParamSUBCOMP_ID(packet)
    data["conv24vACmd"] = pb.pus_tc_210_94_getParamConv24vACmd(packet)
    data["conv24vBCmd"] = pb.pus_tc_210_94_getParamConv24vBCmd(packet)
    data["conv12vCmd"] = pb.pus_tc_210_94_getParamConv12vCmd(packet)
    data["conv19vCmd"] = pb.pus_tc_210_94_getParamConv19vCmd(packet)
    return data




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

def getSodplannerDict(inData):
    data = dict()
    data["timeline"] = "sodplanner"
    data["predicate"] = str(inData.predicate).split(".",1)[1]
    data["inittime"] = getIntervalDict(inData.inittime)
    data["endtime"] = getIntervalDict(inData.endtime)

    attributes = dict()
    
    if len(attributes) > 0:
        data["attributes"] = attributes

    return data
def tc_200_16_get_data(packet):
    try:
        data = dict()
        obs = pb.pus_tm_200_16_getSodplannerObservation(packet)
        
        observation = dict()
        observation["timeline"] = "sodplanner"
        observation["predicate"] = str(obs.observation.predicate).split(".",1)[1]

        attributes = dict()
        
        
        
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
    value = pb.asn1SccT_String(bytes(param, 'utf-8'))
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

def getCommandstateFromDict(value):
    
    if value == "offline":
        return pb.asn1SccCommandstateEnum.offline
    if value == "idle":
        return pb.asn1SccCommandstateEnum.idle
    if value == "latched":
        return pb.asn1SccCommandstateEnum.latched
    if value == "connected":
        return pb.asn1SccCommandstateEnum.connected
    else:
        return pb.asn1SccCommandstateEnum.unknown

def getYawidFromDict(value):
    
    if value == "yaw0":
        return pb.asn1SccYawidEnum.yaw0
    if value == "yaw90":
        return pb.asn1SccYawidEnum.yaw90
    if value == "yaw180":
        return pb.asn1SccYawidEnum.yaw180
    if value == "yaw270":
        return pb.asn1SccYawidEnum.yaw270
    else:
        return pb.asn1SccYawidEnum.unknown
