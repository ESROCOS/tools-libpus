from PySide import QtCore
from Model import CreateTCModel
from Views.AddTCView import AddTCView
from Utilities import PacketTranslator
from Utilities import MakoTranslate
import os, sys, json
# dir_path = os.path.dirname(os.path.realpath(__file__))
# lib_path = os.path.join(dir_path, '../../../pus/debug/pylib')
# sys.path.append(lib_path)
# import pusbinding as pb


lib_path = os.path.join('/home/esrocos/esrocos-ws-pus/tools-libpus/debug/pylib')
sys.path.append(lib_path)
import pusbinding as pb


class AddTCController(object):
    """
    This class controls AddTCView
    """
    def __init__(self, model: CreateTCModel, view: AddTCView):
        """
        Constructor of the class
        :param model: The model the controller references
        :param view: The view the controller references
        """
        self.model = model
        self.view = view
        self.command = dict()

        self.__add_telecommand()
        self.set_callbacks()
        self.svc_combobox_changed_callback(self.view.window.serviceComboBox.currentIndex())

    def set_callbacks(self):
        """
        This method is used to set the callbacks to every action that the
        user triggers
        """
        self.view.window.serviceComboBox.currentIndexChanged.connect(lambda i: self.svc_combobox_changed_callback(i))
        self.view.window.msgComboBox.currentIndexChanged.connect(lambda i: self.msg_combobox_changed_callback(i))

    def __add_telecommand(self):
        """
        This method fills service id combobox
        """
        for elem in sorted(self.model.telecommand, key=int):
            self.view.add_item_svc_type_combo_box(elem)

    def svc_combobox_changed_callback(self, index):
        """
        This method is triggered when the selected index of the
        service id combobox changes. This method fills the message
        id combobox depending on the service id selected.
        :param index: The new selected index
        """
        excluded = (('19', '1'), ('11', '4'))
        svcComboBox = self.view.window.serviceComboBox
        svc = svcComboBox.itemText(index)
        self.view.window.msgComboBox.addItem("", None)
        self.view.clear_msg_type_combo_box()
        for msg in sorted(self.model.telecommand[svc], key=int):
            if (svc, msg) not in excluded:
                self.view.add_item_msg_type_combo_box(msg)

    def msg_combobox_changed_callback(self, index):
        """
        This method is triggered when the selected index of the
        message id combobox changes. This method creates a default
        packet of type (service id, message id)
        :param index: The new selected index
        """
        svcComboBox = self.view.window.serviceComboBox
        msgComboBox = self.view.window.msgComboBox

        svc_index = svcComboBox.currentIndex()

        svc_type = svcComboBox.itemData(svc_index)
        msg_type = msgComboBox.itemData(index)

        if msg_type is None:
            return

        self.command = self.show_packet_json(svc_type, msg_type)
        self.view.current_json = json.dumps(self.command)

        pck_sec_head = json.dumps(self.command["data"]["pck_sec_head"], indent=2)
        source_data = json.dumps(self.command["data"]["user_data"]["src_data"], indent=2)
        self.view.set_tc_text(pck_sec_head, source_data)

    def show_packet_json(self, svc, msg):
        """
        This method writes the packet with the service id and message id
        specified in json format in the textbox of the window.
        :param svc: Service id of the packet
        :param msg: Message id of the packet
        :return: The packet in json format
        """
        packet = pb.pusPacket_t()
        packet_translator = PacketTranslator()

        apid_info = self.model.apid_info
        apid = pb.pus_getInfoApid(apid_info)
        seq = pb.pus_getNextPacketCount(apid_info)

        if (svc, msg) == (8, 1):
            pb.pus_tc_8_1_createPerformFuctionRequest(packet, apid, seq, 0)
        elif (svc, msg) == (9, 1):
            pb.pus_tc_9_1_createSetTimeReportRate(packet, apid, seq, 0)
        elif svc == 11:
            if msg == 1:
                pb.pus_tc_11_1_createEnableTimeBasedSchedule(packet, apid, seq)
            elif msg == 2:
                pb.pus_tc_11_2_createDisableTimeBasedSchedule(packet, apid, seq)
            elif msg == 3:
                pb.pus_tc_11_3_createResetTimeBasedSchedule(packet, apid, seq)
        elif svc == 12:
            if msg == 1:
                pb.pus_tc_12_1_createEnableParameterMonitoringDefinitions(packet, apid, seq, 0)
            elif msg == 2:
                pb.pus_tc_12_2_createDisableParameterMonitoringDefinitions(packet, apid, seq, 0)
            elif msg == 15:
                pb.pus_tc_12_15_createEnableParameterMonitoring(packet, apid, seq)
            elif msg == 16:
                pb.pus_tc_12_16_createDisableParameterMonitoring(packet, apid, seq)
        elif (svc, msg) == (17, 1):
            pb.pus_tc_17_1_createConnectionTestRequest(packet, apid, seq)
        elif svc == 19:
            if msg == 2:
                pb.pus_tc_19_2_createDeleteEventActionDefinitionsRequest(packet, apid, seq, 0)
            elif msg == 4:
                pb.pus_tc_19_4_createEnableEventActionDefinitions(packet, apid, seq, 0)
            elif msg == 5:
                pb.pus_tc_19_5_createDisableEventActionDefinitions(packet, apid, seq, 0)
        elif svc == 20:
            if msg == 1:
                pb.pus_tc_20_1_createParameterValueRequest(packet, apid, seq, 0)
            elif msg == 3:
                pb.pus_tc_20_3_createSetParameterValueRequest(packet, apid, seq, 0, 0)
        elif svc == 23:
            if msg == 1:
                pb.pus_tc_23_1_createCreateFileRequest(packet, apid, seq, "", "", 0)
            elif msg == 2:
                pb.pus_tc_23_2_createDeleteFileRequest(packet, apid, seq, "", "")
            elif msg == 3:
                pb.pus_tc_23_3_createReportFileAtributesRequest(packet, apid, seq, "", "")
            elif msg == 14:
                pb.pus_tc_23_14_createCopyFileRequest(packet, apid, seq, "", "", "", "")
        else:
            pass
        return packet_translator.packet2json(packet)

    def show(self):
        """
        This method calls the .show() method of the view and returns
        the packet that the user creates in this window
        :return: The created packet
        """
        code = self.view.show()
        packet_translator = PacketTranslator()
        makoTranslate = MakoTranslate()

        pck_sec_header, src_data = self.view.get_tc_text()
        pck_sec_header = json.loads(makoTranslate.replace(pck_sec_header))
        src_data = json.loads(makoTranslate.replace(src_data))
        self.command["data"]["pck_sec_head"] = pck_sec_header
        self.command["data"]["user_data"]["src_data"] = src_data
        if code == 1:
            packet = packet_translator.json2packet(self.command)
            if self.view.is_svc_19():
                extra_val = self.view.get_event_id()
                try:
                    extra_val = int(extra_val)
                except ValueError as e:
                    extra_val = pb.pus_st05_getEventId(extra_val)
            else:
                extra_val = self.view.get_date_time()
            return packet, extra_val
        else:
            return None, None

    def destroy(self):
        self.view.destroy()
