from mako.template import Template
from . import Macros
import json, os, sys, time
lib_path = os.path.join('/home/esrocos/esrocos-ws-pus/tools-libpus/debug/pylib')
sys.path.append(lib_path)
import pusbinding as pb


class MakoTranslate(object):
    def __init__(self):
        self.version = {"V0": 0, "V1": 1, "INVALID_VERSION": 15}
        self.st3_12_params = dict()
        self.st20_params = dict()
        self.st5_events = dict()
        param_id = 0
        read_value = " "
        while read_value is not None:
            read_value = pb.pus_st20_getOnBoardReportInfoName(param_id)
            if read_value is not None:
                self.st20_params[read_value] = param_id
            param_id += 1

        #  In the future library there can be more than one report id
        param_id = 0
        read_value = " "
        while read_value is not None:
            read_value = pb.pus_st03_getHkReportInfoName(param_id)
            if read_value is not None:
                self.st3_12_params[read_value] = param_id
            param_id += 1


        param_id = 0
        read_value = " "
        while read_value is not None:
            read_value = pb.pus_st05_getEventName(param_id)
            if read_value is not None:
                self.st5_events[read_value] = param_id
            param_id += 1

        self.values = [self.version, self.st3_12_params, self.st20_params, self.st5_events]

        self.template_values = ""
        self.__create_value_string__()

    def __create_value_string__(self):
        for elem in self.values:
            for k, v in elem.items():

                self.template_values += "<%{} = {}%>".format(k, v)

    def replace(self, json_data):

        if type(json_data) is dict:
            data = json.dumps(json_data)
        else:
            data = json_data
        res = Template(self.template_values + data).render(macros=Macros.Macros())
        return res
