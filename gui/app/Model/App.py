from Utilities import Table
from Utilities import PacketTranslator
from PySide.QtCore import Slot
import os, json, sys, time
lib_path = os.path.join('/home/esrocos/esrocos-ws-pus/tools-libpus/debug/pylib')
sys.path.append(lib_path)
import pusbinding as pb


class App(object):
    """
    This class represents the model of the application. It saves an
    instance of the packet table, the current filter and the apid of the
    app.
    """
    def __init__(self):
        """
        Constructor of the class
        """
        self.table = Table()
        self.parameters_report_values = {"spacecraftTime": None}
        self.st3_param_numbers = list()
        self.tc_apid = pb.pusApidInfo_t()
        self.currentFilter = None
        self.elem_count = 0

        with open('apid.json', 'r') as json_apid:
            apid_value = json.load(json_apid)['apid']
            pb.pus_initApidInfo_null(self.tc_apid, apid_value)

    @Slot(pb.pusPacket_t)
    def add(self, packet: pb.pusPacket_t):
        """
        This method adds a packet in its packet representation and json representation
        to the app packet table
        :param packet: packet
        """
        pt = PacketTranslator()
        elem = pt.packet2json(packet)
        # print(elem)
        self.update_params(elem)
        from datetime import datetime
        list_ = []
        type_ = int(elem["primary_header"]["pck_id"]["pck_type"])
        if elem["primary_header"]["pck_id"]["sec_head_flg"]:
            svc_type_id = int(elem["data"]["pck_sec_head"]["msg_type_id"]["service_type_id"])
            msg_subtype_id = int(elem["data"]["pck_sec_head"]["msg_type_id"]["msg_subtype_id"])
            if type_ == 0:
                src = None
                dst = int(elem["data"]["pck_sec_head"]["dst_id"])
            else:
                src = int(elem["data"]["pck_sec_head"]["src_id"])
                dst = None
        else:
            svc_type_id = 9
            msg_subtype_id = 2
            src = None
            dst = None

        time_ = str(datetime.now().time().strftime("%H:%M:%S"))

        pck_seq_ctrl = int(elem["primary_header"]["pck_seq_ctrl"]["pck_seq"])
        status = "OK" # Mirar
        information = self.__create_info_string__(elem)

        list_.append(self.elem_count)
        self.elem_count+=1
        list_.append("TM" if type_ == 0 else "TC")
        list_.append(svc_type_id)
        list_.append(msg_subtype_id)
        list_.append(time_)
        list_.append(src)
        list_.append(dst)
        list_.append(pck_seq_ctrl)
        list_.append(status)
        list_.append(information)
        list_.append(json.dumps(elem))
        list_.append(packet)
        self.table.append(list_)  # QtTable is updated here

    def get_params(self):
        return self.parameters_report_values

    def update_params(self, packet):
        if packet["primary_header"]["pck_id"]["sec_head_flg"]:
            svc = int(packet["data"]["pck_sec_head"]["msg_type_id"]["service_type_id"])
            msg = int(packet["data"]["pck_sec_head"]["msg_type_id"]["msg_subtype_id"])
        else:
            svc = 9
            msg = 2
        if (svc, msg) == (9, 2):
            time_ = int(packet["data"]["user_data"]["src_data"]["time"])
            self.parameters_report_values["spacecraftTime"] = time_
        elif svc == 3:
            report = packet["data"]["user_data"]["src_data"]["hk_param_report"]["params"]
            for k, v in report.items():
                self.parameters_report_values[k] = v

    def set_filter(self, filter_: dict):
        """
        This method sets a filter and applies it to the table
        :param filter_: The filter to be applied
        """
        print(filter_)
        self.currentFilter = filter_
        return self.apply_filter()

    def apply_filter(self):
        """
        This method applies a filter to the table
        :return: A matrix with all the elements to be shown
        """
        if self.currentFilter is None:
            return [e[0] for e in self.table]

        table = []
        type_ = self.currentFilter["type"]
        svc = self.currentFilter["svc"]
        msg = self.currentFilter["msg"]
        for e in self.table:
            if self.check_filter(e):
                table.append(e[0])
        return table

    def check_filter(self, e):
        """
        This method checks if an element passed as an argument
        satisfies the current filter
        :param e: The element to be checked
        :return: True if the element satisfies the filter
        and false in other case
        """
        if self.currentFilter is not None:
            type_ = self.currentFilter["type"]
            svc = self.currentFilter["svc"]
            msg = self.currentFilter["msg"]

            aux = e
            if type_ != "":
                aux = e if e[1] == type_ else None
            if svc != 0 and aux is not None:
                aux = aux if aux[2] in svc else None
            if msg != 0 and aux is not None:
                aux = aux if aux[3] in msg else None
            return aux is not None
        return True

    def active_filter(self):
        return self.currentFilter is not None

    @staticmethod
    def __create_info_string__(elem):
        """
        This static method creates the information string for each
        telemetry or telecommand in the table
        :param elem: The telemetry or telecommand packet
        :return: The information string
        """
        info = ""
        if elem["primary_header"]["pck_id"]["sec_head_flg"]:
            svc = elem["data"]["pck_sec_head"]["msg_type_id"]["service_type_id"]
            msg = elem["data"]["pck_sec_head"]["msg_type_id"]["msg_subtype_id"]
        else:
            svc = 9
            msg = 2
        data = elem["data"]
        src_data = data["user_data"]["src_data"]
        # ack_flags = data["pck_sec_head"]["ack_flags"]

        info = "-"
        if svc == 1:
            failure = src_data["failure"]
            request = src_data["request"]
            info = "Req. Apid = {}. ".format(request["apid"])
            if msg == 5 or msg == 6:
                info += "Step = {}. ".format(src_data["step"])
            if msg == 1 or msg == 4 or msg == 6 or msg == 8:
                info += "Failure = {}".format(failure["code"])
                # info += "Failure = {}, Address = {}, Data = {}, Subcode = {}. ".format(failure["code"],
                #                                                                      failure["info"]["address"],
                #                                                                      failure["info"]["data"],
                #                                                                      failure["info"]["subcode"])
        elif (svc, msg) == (3, 25):
            info = "Report id: {}".format(src_data["hk_param_report"]["report_id"])
            params = []
        elif svc == 5:
            info = "Event id: {}. ({}, {})".format(src_data["event_id"], src_data["auxdata"]["data1"],
                                                               src_data["auxdata"]["data2"])
        elif (svc, msg) == (8, 1):
            info = "Function id = {}.".format(src_data["function_id"])
        elif (svc, msg) == (9, 1):
            info = "Rate = 2^{}".format(src_data["exp_rate"])
        elif (svc, msg) == (9, 2):
            time_ = time.strftime('%H:%M:%S', time.localtime(src_data["time"]))
            info = "Rate = 2^{}. Time = {}".format(src_data["exp_rate"], time_)
        elif (svc, msg) == (11, 4):
            info = ""
            for i, k in enumerate(sorted(src_data.keys())):
                activity_i_packet = src_data[k]["packet"]["data"]["pck_sec_head"]["msg_type_id"]
                time_i = src_data[k]["time"]
                src = activity_i_packet["service_type_id"]
                msg = activity_i_packet["msg_subtype_id"]
                info += "Act{}: Time: {}, Packet: ({}, {}). ".format(i+1, time_i, src, msg)

        elif svc == 12:
            if msg == 1 or msg == 2:
                info = "Pmon id = {}".format(src_data["pmon_id"])
        elif (svc, msg) == (17, 1):
            info = "Are you alive?"
        elif (svc, msg) == (17, 2):
            info = "Yes. I am alive."
        elif svc == 18:
            info = ""
            if msg != 21 and msg != 22:
                info += "Obcp id: {} ".format(src_data["obcp_id"])
            else:
                info = "-"
            if msg == 4 or msg == 5:
                info += "Step id: {} ".format(src_data["step_id"])
            if msg == 3:
                info += "Observability: {} ".format(src_data["observability"])
            if msg == 13:
                slash = "" if src_data["repository_path"][-1] == "/" else "/"
                info += "File: {}{}{}".format(src_data["repository_path"], slash, src_data["file_name"])
        elif svc == 19:
            info = "Event id = {}. ".format(src_data["event_id"])
            if msg == 1:
                request_data = data["user_data"]["src_data"]["request"]["data"]
                sub_svc = request_data["pck_sec_head"]["msg_type_id"]["service_type_id"]
                sub_msg = request_data["pck_sec_head"]["msg_type_id"]["msg_subtype_id"]
                info += "Packet request: ({}, {}).".format(sub_svc, sub_msg)
        elif svc == 20:
            if msg == 2:
                info = "{}".format(src_data["param_id"])
                info += " = {}".format(src_data["value"])
            elif msg == 3:
                info = "Set " + pb.pus_st20_getOnBoardReportInfoName(src_data["param_id"])
                info += " to {}".format(src_data["value"])
            else:
                info = pb.pus_st20_getOnBoardReportInfoName(src_data["param_id"])
                info += " request."
        elif svc == 23:
            if msg == 14:
                src_repo = src_data["source_repository"]
                src_file = src_data["source_file"]
                tgt_repo = src_data["target_repository"]
                tgt_file = src_data["target_file"]
                slash1 = ""
                slash2 = ""
                if len(src_repo) > 0:
                    slash1 = "/" if src_repo[-1] != "/" else ""
                if len(tgt_repo) > 0:
                    slash2 = "/" if tgt_repo[-1] != "/" else ""

                info = "Source  file: {}{}{}. Target file: {}{}{}.".format(src_repo, slash1, src_file, tgt_repo, slash2,
                                                                           tgt_file)
            else:
                repo = src_data["repo_path"]
                slash = ""
                if len(repo) > 0:
                    slash = "/" if repo[-1] != "/" else ""
                info = "File: {}{}{}. ".format(src_data["repo_path"], slash, src_data["file_name"])
                if msg == 1:
                    info += " Max size: {}".format(src_data["max_size"])

        # add st12 infostring
        return info
