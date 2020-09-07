# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2
from PusGui import pb
import numpy as np

def getIntdDict(param):
    value = dict()
    value["value"] = getIntDict(param.value)
    return value

def getFloatdDict(param):
    value = dict()
    value["value"] = getFloatDict(param.value)
    return value

def getPose2dDict(param):
    value = dict()
    value["x"] = getFloatDict(param.x)
    value["y"] = getFloatDict(param.y)
    value["yaw"] = getFloatDict(param.yaw)
    return value

def getPoint2dDict(param):
    value = dict()
    value["x"] = getFloatDict(param.x)
    value["y"] = getFloatDict(param.y)
    return value

def getPoint3dDict(param):
    value = dict()
    value["x"] = getFloatDict(param.x)
    value["y"] = getFloatDict(param.y)
    value["z"] = getFloatDict(param.z)
    return value

def getPolygon4pDict(param):
    value = dict()
    value["p1"] = getPoint2dDict(param.p1)
    value["p2"] = getPoint2dDict(param.p2)
    value["p3"] = getPoint2dDict(param.p3)
    value["p4"] = getPoint2dDict(param.p4)
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


def getIntdFromDict(param):
    value = pb.asn1SccIntd()
    value.value = getIntFromDict(param["value"])
    return value

def getFloatdFromDict(param):
    value = pb.asn1SccFloatd()
    value.value = getFloatFromDict(param["value"])
    return value

def getPose2dFromDict(param):
    value = pb.asn1SccPose2d()
    value.x = getFloatFromDict(param["x"])
    value.y = getFloatFromDict(param["y"])
    value.yaw = getFloatFromDict(param["yaw"])
    return value

def getPoint2dFromDict(param):
    value = pb.asn1SccPoint2d()
    value.x = getFloatFromDict(param["x"])
    value.y = getFloatFromDict(param["y"])
    return value

def getPoint3dFromDict(param):
    value = pb.asn1SccPoint3d()
    value.x = getFloatFromDict(param["x"])
    value.y = getFloatFromDict(param["y"])
    value.z = getFloatFromDict(param["z"])
    return value

def getPolygon4pFromDict(param):
    value = pb.asn1SccPolygon4p()
    value.p1 = getPoint2dFromDict(param["p1"])
    value.p2 = getPoint2dFromDict(param["p2"])
    value.p3 = getPoint2dFromDict(param["p3"])
    value.p4 = getPoint2dFromDict(param["p4"])
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
    value.key = getIntFromDict(param["key"])
    value.value = getStringFromDict(param["value"])
    return value