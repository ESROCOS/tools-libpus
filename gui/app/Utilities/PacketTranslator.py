import os, sys, collections, time, datetime, json
lib_path = os.path.join('/home/esrocos/esrocos-ws-pus/tools-libpus/debug/pylib')
sys.path.append(lib_path)
import pusbinding as pb


class PacketTranslator(object):
    """
    This class implements the functionality to parse between
    json and packet.
    """
    def packet2json(self, pack):
        """
        This method creates a json from a packet format
        :param pack: Packet to be parsed
        :return: The packet in json format
        """
        jsn = collections.OrderedDict()
        jsn["primary_header"] = collections.OrderedDict()
        jsn["data"] = collections.OrderedDict()
        jsn["primary_header"]["pck_version"] = pb.pus_getPacketVersion(pack)
        jsn["primary_header"]["pck_id"] = collections.OrderedDict()
        type_ = jsn["primary_header"]["pck_id"]["pck_type"] = pb.pus_getPacketType(pack)
        sec_head_flag = jsn["primary_header"]["pck_id"]["sec_head_flg"] = pb.pus_getSecondaryHeaderFlag(pack)
        jsn["primary_header"]["pck_id"]["apid"] = pb.pus_getApid(pack)
        jsn["primary_header"]["pck_seq_ctrl"] = collections.OrderedDict()
        jsn["primary_header"]["pck_seq_ctrl"]["pck_seq_flg"] = pb.pus_getSequenceFlags(pack)
        jsn["primary_header"]["pck_seq_ctrl"]["pck_seq"] = pb.pus_getSequenceCount(pack)
        jsn["primary_header"]["pck_data_len"] = pb.pus_getPacketDataLength(pack)
        jsn["data"] = collections.OrderedDict()
        if sec_head_flag:
            jsn["data"]["pck_sec_head"] = collections.OrderedDict()
            if type_ == 0:  # TM
                jsn["data"]["pck_sec_head"]["tm_packet_pus_version_number"] = pb.pus_getTmPusVersion(pack)
                jsn["data"]["pck_sec_head"]["spacecraft_time"] = pb.pus_getTmTimeReferenceStatus(pack)
                srvc_type_id = pb.pus_getTmService(pack)
                msg_type_id = pb.pus_getTmSubtype(pack)
                jsn["data"]["pck_sec_head"]["msg_type_counter"] = pb.pus_getTmMessageTypeCounter(pack)
                jsn["data"]["pck_sec_head"]["dst_id"] = pb.pus_getTmDestination(pack)
                jsn["data"]["pck_sec_head"]["time"] = time.strftime("%H:%M:%S", time.gmtime(pb.pus_getTmPacketTime(pack)))
            else:
                jsn["data"]["pck_sec_head"]["tc_packet_pus_version_number"] = pb.pus_getTcPusVersion(pack)
                jsn["data"]["pck_sec_head"]["ack_flags"] = collections.OrderedDict()
                jsn["data"]["pck_sec_head"]["ack_flags"]["ack_flag_acceptance"] = pb.pus_getTcAckFlagAcceptance(pack)
                jsn["data"]["pck_sec_head"]["ack_flags"]["ack_flag_start"] = pb.pus_getTcAckFlagStart(pack)
                jsn["data"]["pck_sec_head"]["ack_flags"]["ack_flag_progress"] = pb.pus_getTcAckFlagProgress(pack)
                jsn["data"]["pck_sec_head"]["ack_flags"]["ack_flag_completion"] = pb.pus_getTcAckFlagCompletion(pack)
                srvc_type_id = pb.pus_getTcService(pack)
                msg_type_id = pb.pus_getTcSubtype(pack)
                jsn["data"]["pck_sec_head"]["src_id"] = pb.pus_getTcSource(pack)

            jsn["data"]["pck_sec_head"]["msg_type_id"] = collections.OrderedDict()
            jsn["data"]["pck_sec_head"]["msg_type_id"]["service_type_id"] = srvc_type_id
            jsn["data"]["pck_sec_head"]["msg_type_id"]["msg_subtype_id"] = msg_type_id
        else:
            srvc_type_id = 9
            msg_type_id = 2

        jsn["data"]["user_data"] = collections.OrderedDict()
        jsn["data"]["user_data"]["src_data"] = collections.OrderedDict()

        if srvc_type_id == 1:  # If it's a request verification packet
            jsn["data"]["user_data"]["src_data"] = self.tm_1_x_get_data(pack)
        elif (srvc_type_id, msg_type_id) == (3, 25):
            jsn["data"]["user_data"]["src_data"] = self.tm_3_25_get_data(pack)
        elif srvc_type_id == 5:
            jsn["data"]["user_data"]["src_data"] = self.tm_5_x_get_data(pack)
        elif (srvc_type_id, msg_type_id) == (8, 1):
            jsn["data"]["user_data"]["src_data"] = self.tc_8_1_get_data(pack)
        elif srvc_type_id == 9:
            if msg_type_id == 1:
                jsn["data"]["user_data"]["src_data"] = self.tc_9_1_get_data(pack)
            elif msg_type_id == 2:
                jsn["data"]["user_data"]["src_data"] = self.tm_9_2_get_data(pack)
        elif srvc_type_id == 11:
            if msg_type_id == 4:
                jsn["data"]["user_data"]["src_data"] = self.tc_11_4_get_data(pack)
        elif srvc_type_id == 12:
            jsn["data"]["user_data"]["src_data"] = self.tc_12_x_get_data(pack, msg_type_id)
        elif srvc_type_id == 18:
            if msg_type_id == 1:
                jsn["data"]["user_data"]["src_data"] = self.tc_18_1_get_data(pack)
            elif msg_type_id == 2 or msg_type_id == 6 or msg_type_id == 12:
                jsn["data"]["user_data"]["src_data"] = self.tc_18_2_6_12_get_data(pack)
            elif msg_type_id == 3:
                jsn["data"]["user_data"]["src_data"] = self.tc_18_3_get_data(pack)
            elif msg_type_id == 4 or msg_type_id == 5:
                jsn["data"]["user_data"]["src_data"] = self.tc_18_4_5_get_data(pack)
            elif msg_type_id == 13:
                jsn["data"]["user_data"]["src_data"] = self.tc_18_13_get_data(pack)
        elif srvc_type_id == 19:
            if msg_type_id == 1:
                jsn["data"]["user_data"]["src_data"] = self.tc_19_1_get_data(pack)
                print("-----------------------------")
                print(jsn["data"]["user_data"]["src_data"])
            else:
                jsn["data"]["user_data"]["src_data"] = self.tc_19_2_4_5_get_data(pack)
        elif srvc_type_id == 20:
            if msg_type_id == 1:
                jsn["data"]["user_data"]["src_data"] = self.tc_20_1_get_data(pack)
            elif msg_type_id == 2:
                jsn["data"]["user_data"]["src_data"] = self.tm_20_2_get_data(pack)
            elif msg_type_id == 3:
                jsn["data"]["user_data"]["src_data"] = self.tc_20_3_get_data(pack)
        elif srvc_type_id == 23:
            if msg_type_id == 1 or msg_type_id == 4:
                jsn["data"]["user_data"]["src_data"] = self.tc_tm_23_1_4_get_data(pack)
            elif msg_type_id == 2 or msg_type_id == 3:
                jsn["data"]["user_data"]["src_data"] = self.tc_23_2_3_get_data(pack)
            elif msg_type_id == 14:
                jsn["data"]["user_data"]["src_data"] = self.tc_23_14_get_data(pack)

        return jsn

    def json2packet(self, jsn):
        """
        This method creates a packet from a json format
        :param jsn: The packet in json format
        :return: A packet object
        """
        pack = self.create_default_packet(jsn)
        version = jsn["primary_header"]["pck_version"]  # Shall be integer
        pb.pus_setPacketVersion(pack, version)
        type_ = jsn["primary_header"]["pck_id"]["pck_type"]  # Shall be integer
        pb.pus_setPacketType(pack, type_)
        sec_head_flag = jsn["primary_header"]["pck_id"]["sec_head_flg"]  # Shall be boolean
        pb.pus_setSecondaryHeaderFlag(pack, sec_head_flag)
        ap_id = jsn["primary_header"]["pck_id"]["apid"]
        pb.pus_setApid(pack, ap_id)
        seq_flags = jsn["primary_header"]["pck_seq_ctrl"]["pck_seq_flg"]
        pb.pus_setSequenceFlags(pack, seq_flags)
        seq_count = jsn["primary_header"]["pck_seq_ctrl"]["pck_seq"]
        pb.pus_setSequenceCount(pack, seq_count)
        data_len = jsn["primary_header"]["pck_data_len"]
        pb.pus_setPacketDataLength(pack, data_len)

        type_ = jsn["primary_header"]["pck_id"]["pck_type"]
        if type_ == 0:  # TM
            tm_version = jsn["data"]["pck_sec_head"]["tm_packet_pus_version_number"]
            pb.pus_setTmPusVersion(pack, tm_version)

            time_ref = jsn["data"]["pck_sec_head"]["spacecraft_time"]
            pb.pus_setTmTimeReferenceStatus(pack, time_ref)

            srvc_type_id = jsn["data"]["pck_sec_head"]["msg_type_id"]["service_type_id"]
            pb.pus_setTmService(pack, srvc_type_id)

            msg_type_id = jsn["data"]["pck_sec_head"]["msg_type_id"]["msg_subtype_id"]
            pb.pus_setTmSubtype(pack, msg_type_id)

            msg_type_counter = jsn["data"]["pck_sec_head"]["msg_type_counter"]
            pb.pus_setTmMessageTypeCounter(pack, msg_type_counter)

            tm_dest = jsn["data"]["pck_sec_head"]["dst_id"]
            pb.pus_setTmDestination(pack, tm_dest)

            time_ = jsn["data"]["pck_sec_head"]["time"]  # Revisar, puede ser que esté en string
            if type(time_) == str:
                time_ = datetime.datetime.strptime(time_, '%H:%M:%S').time()
            pb.pus_setTmPacketTime(pack, time_)
        else:
            srvc_type_id = jsn["data"]["pck_sec_head"]["msg_type_id"]["service_type_id"]
            pb.pus_setTcService(pack, srvc_type_id)
            msg_type_id = jsn["data"]["pck_sec_head"]["msg_type_id"]["msg_subtype_id"]
            pb.pus_setTcSubtype(pack, msg_type_id)

            tc_version = jsn["data"]["pck_sec_head"]["tc_packet_pus_version_number"]
            pb.pus_setTcPusVersion(pack, tc_version)
            ack_f_acceptance = jsn["data"]["pck_sec_head"]["ack_flags"]["ack_flag_acceptance"]
            ack_f_start = jsn["data"]["pck_sec_head"]["ack_flags"]["ack_flag_start"]
            ack_f_progress = jsn["data"]["pck_sec_head"]["ack_flags"]["ack_flag_progress"]
            ack_f_completion = jsn["data"]["pck_sec_head"]["ack_flags"]["ack_flag_completion"]
            pb.pus_setTcAckFlags(pack, ack_f_acceptance, ack_f_start, ack_f_progress, ack_f_completion)
            src_id = jsn["data"]["pck_sec_head"]["src_id"]
            pb.pus_setTcSource(pack, src_id)

        data = jsn["data"]["user_data"]["src_data"]
        if srvc_type_id == 1:  # If it's a request verification packet
            # REVISAR
            #  jsn["data"]["user_data"]["src_data"] = self.tm_1_x_set_data(pack)
            pass
        elif (srvc_type_id, msg_type_id) == (3, 25):
            # REVISAR
            #  jsn["data"]["user_data"]["src_data"] = self.tm_3_25_set_data(pack)
            pass
        elif (srvc_type_id, msg_type_id) == (8, 1):
            self.tc_8_1_set_data(pack, data)
        elif (srvc_type_id, msg_type_id) == (9, 1):
            self.tc_9_1_set_data(pack, data)
        elif (srvc_type_id, msg_type_id) == (11, 4):
            self.tc_11_4_set_data(pack, data)
        elif srvc_type_id == 12:
            self.tc_12_x_set_data(pack, msg_type_id, data)
        elif srvc_type_id == 18:
            if msg_type_id == 1:
                self.tc_18_1_set_data(pack, data)
            elif msg_type_id == 2 or msg_type_id == 6 or msg_type_id == 12:
                self.tc_18_2_6_12_set_data(pack, data)
            elif msg_type_id == 3:
                self.tc_18_3_set_data(pack, data)
            elif msg_type_id == 4 or msg_type_id == 5:
                self.tc_18_4_5_set_data(pack, data)
            elif msg_type_id == 13:
                self.tc_18_13_set_data(pack, data)
        elif srvc_type_id == 19:
            if msg_type_id == 1:
                self.tc_19_1_set_data(pack, data)
            else:
                self.tc_19_2_4_5_set_data(pack, data)
        elif srvc_type_id == 20:
            if msg_type_id == 1:
                self.tc_20_1_set_data(pack, data)
            elif msg_type_id == 3:
                self.tc_20_3_set_data(pack, data)
        elif srvc_type_id == 23:
            if msg_type_id == 1:
                self.tc_23_1_set_data(pack, data)
            elif msg_type_id == 2 or msg_type_id == 3:
                self.tc_23_2_3_set_data(pack, data)
            elif msg_type_id == 14:
                self.tc_23_14_set_data(pack, data)
        return pack

    @staticmethod
    def create_default_packet(jsn):
        """
        This method creates a default packet for the packet specified
        in the json passed as an argument
        :param jsn: The packet in json format
        :return: A packet object
        """
        packet = pb.pusPacket_t()
        svc = jsn["data"]["pck_sec_head"]["msg_type_id"]["service_type_id"]
        msg = jsn["data"]["pck_sec_head"]["msg_type_id"]["msg_subtype_id"]

        if (svc, msg) == (8, 1):
            pb.pus_tc_8_1_createPerformFuctionRequest(packet, 0, 0, 0)
        elif (svc, msg) == (9, 1):
            pb.pus_tc_9_1_createSetTimeReportRate(packet, 0, 0, 0)
        elif (svc, msg) == (11, 1):
            pb.pus_tc_11_1_createEnableTimeBasedSchedule(packet, 0, 0)
        elif (svc, msg) == (11, 2):
            pb.pus_tc_11_2_createDisableTimeBasedSchedule(packet, 0, 0)
        elif (svc, msg) == (11, 3):
            pb.pus_tc_11_3_createResetTimeBasedSchedule(packet, 0, 0)
        elif (svc, msg) == (11, 4):
            pb.pus_tc_11_4_createInsertActivityIntoSchedule(packet, 0, 0)
        elif (svc, msg) == (12, 1):
            pb.pus_tc_12_1_createEnableParameterMonitoringDefinitions(packet, 0, 0, 0)
        elif (svc, msg) == (12, 2):
            pb.pus_tc_12_2_createDisableParameterMonitoringDefinitions(packet, 0, 0, 0)
        elif (svc, msg) == (12, 15):
            pb.pus_tc_12_15_createEnableParameterMonitoring(packet, 0, 0)
        elif (svc, msg) == (12, 16):
            pb.pus_tc_12_16_createDisableParameterMonitoring(packet, 0, 0)
        elif (svc, msg) == (17, 1):
            pb.pus_tc_17_1_createConnectionTestRequest(packet, 0, 0)
        elif (svc, msg) == (18, 1):
            pb.pus_tc_18_1_createLoadObcpDirectRequest(packet, 0, 0, "", [1], 1)
        elif (svc, msg) == (18, 2):
            pb.pus_tc_18_2_createUnloadObcpRequest(packet, 0, 0, "")
        elif (svc, msg) == (18, 3):
            pb.pus_tc_18_3_createActivateObcpRequest(packet, 0, 0, "", 0)
        elif (svc, msg) == (18, 4):
            pb.pus_tc_18_4_createStopObcpRequest(packet, 0, 0, "", 0)
        elif (svc, msg) == (18, 5):
            pb.pus_tc_18_5_createSuspendObcpRequest(packet, 0, 0, "", 0)
        elif (svc, msg) == (18, 6):
            pb.pus_tc_18_6_createResumeObcpRequest(packet, 0, 0, "")
        elif (svc, msg) == (18, 12):
            pb.pus_tc_18_12_createAbortObcpRequest(packet, 0, 0, "")
        elif (svc, msg) == (18, 13):
            pb.pus_tc_18_13_createLoadObcpReferenceRequest(packet, 0, 0, "", "", "")
        elif (svc, msg) == (18, 21):
            pb.pus_tc_18_21_createStartObcpEngineRequest(packet, 0, 0)
        elif (svc, msg) == (18, 22):
            pb.pus_tc_18_22_createStopObcpEngineRequest(packet, 0, 0)
        elif (svc, msg) == (19, 1):
            pb.pus_tc_19_1_createAddEventActionDefinitionsRequest(packet, 0, 0, 0, pb.pusPacket_t())
        elif (svc, msg) == (19, 2):
            pb.pus_tc_19_2_createDeleteEventActionDefinitionsRequest(packet, 0, 0, 0)
        elif (svc, msg) == (19, 4):
            pb.pus_tc_19_4_createEnableEventActionDefinitions(packet, 0, 0, 0)
        elif (svc, msg) == (19, 5):
            pb.pus_tc_19_5_createDisableEventActionDefinitions(packet, 0, 0, 0)
        elif (svc, msg) == (20, 1):
            pb.pus_tc_20_1_createParameterValueRequest(packet, 0, 0, 0)
        elif (svc, msg) == (20, 3):
            pb.pus_tc_20_3_createSetParameterValueRequest(packet, 0, 0, 0, 0)
        elif (svc, msg) == (23, 1):
            pb.pus_tc_23_1_createCreateFileRequest(packet, 0, 0, "", "", 0)
        elif (svc, msg) == (23, 2):
            pb.pus_tc_23_2_createDeleteFileRequest(packet, 0, 0, "", "")
        elif (svc, msg) == (23, 3):
            pb.pus_tc_23_3_createReportFileAtributesRequest(packet, 0, 0, "", "")
        elif (svc, msg) == (23, 14):
            pb.pus_tc_23_14_createCopyFileRequest(packet, 0, 0, "", "", "", "")
        else:
            pass
        """
            REVISAR Haria falta meter el 11 ??? y las telemetrias???
        """
        return packet

    @staticmethod
    def tm_1_x_get_data(packet):
        """
        This function parses the st01 packet data field to json
        :param packet: The packet which data field we want to parse
        :return: A JSON object with all the parsed information
        """
        data = dict()
        data["request"] = dict()
        data["request"]["packet_version"] = pb.pus_tm_1_X_getReportPacketVersionNumber(packet)
        data["request"]["packet_type"] = pb.pus_tm_1_X_getReportPacketType(packet)
        data["request"]["sec_head_flag"] = pb.pus_tm_1_X_getReportSecondaryHeaderFlag(packet)
        data["request"]["apid"] = pb.pus_tm_1_X_getReportApid(packet)
        data["request"]["seq_flags"] = pb.pus_tm_1_X_getReportSequenceFlags(packet)
        data["request"]["seq_count"] = pb.pus_tm_1_X_getReportSequenceCount(packet)

        data["step"] = pb.pus_tm_1_X_getStep(packet)

        data["failure"] = dict()
        data["failure"]["code"] = pb.pus_tm_1_X_getFailureCode(packet)
        data["failure"]["info"] = dict()
        data["failure"]["info"]["subcode"] = pb.pus_getSt01FailureSubcode(packet)
        data["failure"]["info"]["data"] = pb.pus_getSt01FailureData(packet)
        data["failure"]["info"]["address"] = pb.pus_getSt01FailureAddress(packet)

        return data

    @staticmethod
    def tm_3_25_get_data(packet):
        """
        This function parses the st03-25 packet data field to json
        :param packet: The packet which data field we want to parse
        :return: A JSON object with all the parsed information
        """
        data = dict()
        report_id = pb.pus_tm_3_25_getReportId(packet)
        data["hk_param_report"] = dict()
        data["hk_param_report"]["report_id"] = report_id
        data["hk_param_report"]["params"] = dict()
        num_param = pb.pus_tm_3_25_getNumParameters(packet)
        for i in range(num_param):
            j = pb.pus_st03_getHkInfoNameFromReport(report_id, i)
            param = pb.pus_tm_3_25_getParameterValue(packet, i)
            param_name = pb.pus_st03_getHkReportInfoName(j)
            param_type = pb.pus_st03_getHkReportInfoType(j)
            casted_param = "Error"
            if pb.getError() == pb.pusError_t.PUS_NO_ERROR:
                if param_type == pb.pusParamType_t.PUS_INT32:
                    casted_param = pb.pus_paramToInt32(param)
                    error = pb.getError()
                elif param_type == pb.pusParamType_t.PUS_UINT32:
                    casted_param = pb.pus_paramToUint32(param)
                    error = pb.getError()
                elif param_type == pb.pusParamType_t.PUS_REAL64:
                    casted_param = pb.pus_paramToReal64(param)
                    error = pb.getError()
                elif param_type == pb.pusParamType_t.PUS_BYTE:
                    casted_param = "0x"+pb.pus_paramToByte(param)
                    error = pb.getError()
                elif param_type == pb.pusParamType_t.PUS_BOOL:
                    casted_param = pb.pus_paramToBool(param)
                    error = pb.getError()
                else:
                    error = pb.pusError_t.PUS_ERROR_INVALID_TYPE
                if error != pb.pusError_t.PUS_NO_ERROR:
                    casted_param = "Error"
            data["hk_param_report"]["params"][param_name] = casted_param
        return data

    @staticmethod
    def tm_5_x_get_data(packet):
        """
        This function parses the st05 packet data field to json
        :param packet: The packet which data field we want to parse
        :return: A JSON object with all the parsed information
        """
        data = dict()

        event_id = pb.pus_tm_get_5_X_event_id(packet)
        event_name = pb.pus_st05_getEventName(event_id)
        data["event_id"] = event_name if event_name is not None else "Error"
        data_type1 = pb.pus_st05_getDataType1(event_id)
        casted_param = "Error"
        aux1 = pb.pus_tm_get_5_X_event_auxdata1(packet)
        if data_type1 == pb.pusParamType_t.PUS_INT32:
            casted_param = pb.pus_paramToInt32(aux1)
        elif data_type1 == pb.pusParamType_t.PUS_UINT32:
            casted_param = pb.pus_paramToUint32(aux1)

        elif data_type1 == pb.pusParamType_t.PUS_REAL64:
            casted_param = pb.pus_paramToReal64(aux1)
        elif data_type1 == pb.pusParamType_t.PUS_BYTE:
            casted_param = "0x" + pb.pus_paramToByte(aux1)
        elif data_type1 == pb.pusParamType_t.PUS_BOOL:
            casted_param = pb.pus_paramToBool(aux1)
        aux1 = casted_param

        data_type2 = pb.pus_st05_getDataType2(event_id)
        casted_param = "Error"
        aux2 = pb.pus_tm_get_5_X_event_auxdata2(packet)
        if data_type2 == pb.pusParamType_t.PUS_INT32:
            casted_param = pb.pus_paramToInt32(aux2)
        elif data_type2 == pb.pusParamType_t.PUS_UINT32:
            casted_param = pb.pus_paramToUint32(aux2)
        elif data_type2 == pb.pusParamType_t.PUS_REAL64:
            casted_param = pb.pus_paramToReal64(aux2)
        elif data_type2 == pb.pusParamType_t.PUS_BYTE:
            casted_param = "0x" + pb.pus_paramToByte(aux2)
        elif data_type2 == pb.pusParamType_t.PUS_BOOL:
            casted_param = pb.pus_paramToBool(aux2)

        aux2 = casted_param

        data["auxdata"] = {"data1": aux1, "data2": aux2}

        return data

    @staticmethod
    def tc_8_1_get_data(packet):
        """
        This function parses the st08-1 packet data field to json
        :param packet: The packet which data field we want to parse
        :return: A JSON object with all the parsed information
        """
        data = dict()
        function_id = pb.pus_tc_8_1_getFunctionId(packet)
        data["function_id"] = function_id
        return data

    @staticmethod
    def tc_8_1_set_data(packet, data):
        """
        This function fills in a st08-1 packet data field with
        a data dictionary passed as an argument
        :param packet: The packet we want to fill in
        :param data: A data dictionary with all the parameters
        """
        function_id = data["function_id"]  # Shall be integer
        pb.pus_tc_8_1_setFunctionId(packet, function_id)

    @staticmethod
    def tc_9_1_get_data(packet):
        """
        This function parses the st09-1 packet data field to json
        :param packet: The packet which data field we want to parse
        :return: A JSON object with all the parsed information
        """
        data = dict()
        exp_rate = pb.pus_tc_9_1_getExponentialRate(packet)
        data["exp_rate"] = exp_rate
        return data

    @staticmethod
    def tc_9_1_set_data(packet, data):
        """
        This function fills in a st09-1 packet data field with
        a data dictionary passed as an argument
        :param packet: The packet we want to fill in
        :param data: A data dictionary with all the parameters
        """
        exp_rate = data["exp_rate"]
        pb.pus_tc_9_1_setExponentialRate(packet, exp_rate)

    @staticmethod
    def tm_9_2_get_data(packet):
        data = dict()
        ptime = pb.pusTime_t()
        exp_rate = pb.pus_tm_9_2_getDataField(packet, ptime)
        data["exp_rate"] = exp_rate
        data["time"] = pb.pus_time2posix(ptime)
        return data

    def tc_11_4_get_data(self, packet):
        """
        This function parses the st011-4 packet data field to json
        :param packet: The packet which data field we want to parse
        :return: A JSON object with all the parsed information
        """
        data = dict()
        ncount = pb.pus_tc_11_4_getNCount(packet)
        for i in range(ncount):
            data["activity"+str(i+1)] = dict()
            data_packet = pb.pusPacket_t()
            pb.pus_tc_11_4_get_request(i, packet, data_packet, 10)
            t = pb.pus_tc_11_4_get_release_time(i, packet, 10)
            data["activity"+str(i+1)]["packet"] = self.packet2json(data_packet)
            data["activity" + str(i + 1)]["time"] = t  # REVISAR, tiempo
        return data

    def tc_11_4_set_data(self, packet, data: dict):
        for k in sorted(data.keys()):
            t = data[k]["time"]
            time_ = pb.pus_posix2time(t)
            scndpacket = self.json2packet(data[k]["packet"])
            pb.pus_tc_11_4_setActivity(packet, scndpacket, time_)
        return packet

    @staticmethod
    def tc_12_x_get_data(packet, msg_id):
        """
        This function parses the st12 packet data field to json
        :param packet: The packet which data field we want to parse
        :return: A JSON object with all the parsed information
        """
        data = dict()

        if msg_id == 1 or msg_id == 2:
            pmon_id = pb.pus_tc_12_1_2_getPmonId(packet)
            data["pmon_id"] = pmon_id
        return data

    @staticmethod
    def tc_12_x_set_data(packet, msg_id, data):
        """
        This function fills in a st12 packet data field with
        a data dictionary passed as an argument
        :param packet: The packet we want to fill in
        :param data: A data dictionary with all the parameters
        """
        if msg_id == 1 or msg_id == 2:
            pmon_id = data["pmon_id"]  # Shall be integer
            pb.pus_tc_12_1_2_setPmonId(packet, pmon_id)
        return packet

    @staticmethod
    def tc_18_1_get_data(packet):
        data = dict()
        obcpid = str()
        data["obcp_id"] = pb.pus_tc_18_X_getObcpId(obcpid, packet)
        obcpcode = ""
        data["obcpcode"] = pb.pus_tc_18_1_getObcpCode(obcpcode, packet)
        return data

    @staticmethod
    def tc_18_1_set_data(packet, data):
        id = data["obcp_id"]
        code = data["obcpcode"]
        pb.pus_tc_18_X_setObcpId(packet, id)
        pb.pus_tc_18_1_setObcpCode(packet, code, len(code))
        return packet

    @staticmethod
    def tc_18_2_6_12_get_data(packet):
        data = dict()
        obcpid = str()
        data["obcp_id"] = pb.pus_tc_18_X_getObcpId(obcpid, packet)
        return data

    @staticmethod
    def tc_18_2_6_12_set_data(packet, data):
        id = data["obcp_id"]
        pb.pus_tc_18_X_setObcpId(packet, id)
        return packet

    @staticmethod
    def tc_18_3_get_data(packet):
        data = dict()
        obcpid = str()
        data["obcp_id"] = pb.pus_tc_18_X_getObcpId(obcpid, packet)
        data["observability"] = pb.pus_tc_18_3_getObservabilityLevel(packet)
        return data

    @staticmethod
    def tc_18_3_set_data(packet, data):
        id = data["obcp_id"]
        obs = data["observability"]
        pb.pus_tc_18_X_setObcpId(packet, id)
        pb.pus_tc_18_3_setObservabilityLevel(packet, obs)
        return packet

    @staticmethod
    def tc_18_4_5_get_data(packet):
        data = dict()
        obcpid = str()
        data["obcp_id"] = pb.pus_tc_18_X_getObcpId(obcpid, packet)
        data["step_id"] = pb.pus_tc_18_4_5_getObcpStepId(packet)
        return data

    @staticmethod
    def tc_18_4_5_set_data(packet, data):
        id = data["obcp_id"]
        pb.pus_tc_18_X_setObcpId(packet, id)
        step = data["step_id"]
        pb.pus_tc_18_4_5_setObcpStepId(packet, step)
        return packet

    @staticmethod
    def tc_18_13_get_data(packet):
        data = dict()
        obcpid = str()
        repo = str()
        file_ = str()
        data["obcp_id"] = pb.pus_tc_18_X_getObcpId(obcpid, packet)
        data["repository_path"] = pb.pus_tc_18_13_getRepositoryPath(repo, packet)
        data["file_name"] = pb.pus_tc_18_13_getFileName(file_, packet)

        return data

    @staticmethod
    def tc_18_13_set_data(packet, data):
        id = data["obcp_id"]
        pb.pus_tc_18_X_setObcpId(packet, id)
        repo = data["repository_path"]
        pb.pus_tc_18_13_setRepositoryPath(packet, repo)
        filename = data["file_name"]
        pb.pus_tc_18_13_setFileName(packet, filename)
        return packet

    def tc_19_1_get_data(self, packet):
        """
        This function parses the st19 packet data field to json
        :param packet: The packet which data field we want to parse
        :return: A JSON object with all the parsed information
        """
        data = dict()
        packet_reduced = pb.pusPacketReduced_t()
        pb.pus_tc_19_1_getAction(packet_reduced, packet)
        data_packet = pb.pusPacket_t()
        pb.pus_packetReduced_createPacketFromPacketReduced(data_packet, packet_reduced)
        event_id = pb.pus_tc_19_X_getEventId(packet)
        data["event_id"] = event_id
        data["request"] = self.packet2json(data_packet)
        return data

    def tc_19_1_set_data(self, packet, data):
        """
        This function fills in a st19-1 packet data field with
        a data dictionary passed as an argument
        :param packet: The packet we want to fill in
        :param data: A data dictionary with all the parameters
        """
        packet_reduced = pb.pusPacketReduced_t()
        action_packet = self.json2packet(data["request"])
        pb.pus_packetReduced_createPacketReducedFromPacket(packet_reduced, action_packet)
        pb.pus_tc_19_1_setAction(packet, packet_reduced)
        event_id = data["event_id"]
        pb.pus_tc_19_X_setEventId(packet, event_id)
        return packet

    @staticmethod
    def tc_19_2_4_5_get_data(packet):
        """
        This function parses the st19-2-4-5 packet data field to json
        :param packet: The packet which data field we want to parse
        :return: A JSON object with all the parsed information
        """
        data = dict()
        event_id = int()

        data["event_id"] = pb.pus_tc_19_X_getEventId(packet)
        return data

    @staticmethod
    def tc_19_2_4_5_set_data(packet, data):
        """
        This function fills in a st19-2-4-5 packet data field with
        a data dictionary passed as an argument
        :param packet: The packet we want to fill in
        :param data: A data dictionary with all the parameters
        """
        event_id = data["event_id"] # Shall be integer
        pb.pus_tc_19_X_setEventId(packet, event_id)
        return packet

    @staticmethod
    def tc_20_1_get_data(packet):
        """
        This function parses the st20_1 packet data field to json
        :param packet: The packet which data field we want to parse
        :return: A JSON object with all the parsed information
        """
        data = dict()
        data["param_id"] = pb.pus_tc_20_X_getParamId(packet)
        return data

    @staticmethod
    def tc_20_1_set_data(packet, data):
        """
        This function fills in a st20_1 packet data field with
        a data dictionary passed as an argument
        :param packet: The packet we want to fill in
        :param data: A data dictionary with all the parameters
        """
        param_id = data["param_id"]
        pb.pus_tc_20_X_setParamId(packet, param_id)
        return packet

    @staticmethod
    def tm_20_2_get_data(packet):
        """
        This function parses the st20_2 packet data field to json
        :param packet: The packet which data field we want to parse
        :return: A JSON object with all the parsed information
        """
        data = dict()
        paramid = pb.pus_tm_20_2_getParamId(packet)
        data["param_id"] = pb.pus_st20_getOnBoardReportInfoName(paramid)
        param_type = pb.pus_st20_getOnBoardReportInfoType(paramid)
        param = pb.pus_tm_20_2_getParamValue(packet)
        casted_param = "Error"
        if pb.getError() == pb.pusError_t.PUS_NO_ERROR:
            if param_type == pb.pusParamType_t.PUS_INT32:
                casted_param = pb.pus_paramToInt32(param)
                error = pb.getError()
            elif param_type == pb.pusParamType_t.PUS_UINT32:
                casted_param = pb.pus_paramToUint32(param)
                error = pb.getError()
            elif param_type == pb.pusParamType_t.PUS_REAL64:
                casted_param = pb.pus_paramToReal64(param)
                error = pb.getError()
            elif param_type == pb.pusParamType_t.PUS_BYTE:
                casted_param = "0x" + pb.pus_paramToByte(param)
                error = pb.getError()
            elif param_type == pb.pusParamType_t.PUS_BOOL:
                casted_param = pb.pus_paramToBool(param)
                error = pb.getError()
            else:
                error = pb.pusError_t.PUS_ERROR_INVALID_TYPE
            if error != pb.pusError_t.PUS_NO_ERROR:
                casted_param = "Error"

        data["value"] = casted_param
        return data

    @staticmethod
    def tc_20_3_get_data(packet):
        """
        This function parses the st20_3 packet data field to json
        :param packet: The packet which data field we want to parse
        :return: A JSON object with all the parsed information
        """
        data = dict()
        data["param_id"] = pb.pus_tc_20_X_getParamId(packet)
        data["value"] = pb.pus_tc_20_3_getParamValue(packet)
        return data

    @staticmethod
    def tc_20_3_set_data(packet, data):
        """
        This function fills in a st20_3 packet data field with
        a data dictionary passed as an argument
        :param packet: The packet we want to fill in
        :param data: A data dictionary with all the parameters
        """
        param_id = data["param_id"]
        value = data["value"]
        pb.pus_tc_20_X_setParamId(packet, param_id)
        param_type = pb.pus_st20_getOnBoardReportInfoType(param_id)
        error = pb.pusError_t.PUS_NO_ERROR
        casted_param = 0

        if pb.getError() == pb.pusError_t.PUS_NO_ERROR:
            if param_type == pb.pusParamType_t.PUS_INT32:
                casted_param = pb.pus_int32ToParam(value)
                error = pb.getError()
            elif param_type == pb.pusParamType_t.PUS_UINT32:
                casted_param = pb.pus_uint32ToParam(value)
                error = pb.getError()
            elif param_type == pb.pusParamType_t.PUS_REAL64:
                casted_param = pb.pus_real64ToParam(value)
                error = pb.getError()
            elif param_type == pb.pusParamType_t.PUS_BYTE:
                casted_param = pb.pus_byteToParam(value)
                error = pb.getError()
            elif param_type == pb.pusParamType_t.PUS_BOOL:
                casted_param = pb.pus_boolToParam(value)
                error = pb.getError()
            else:
                casted_param = 0
        if error != pb.pusError_t.PUS_NO_ERROR:
            casted_param = 0

        # ERRORESS
        pb.pus_tc_20_3_setParamValue(packet, casted_param)
        return packet

    @staticmethod
    def tc_23_1_set_data(packet, data):
        repo_path = data["repo_path"]
        filename = data["file_name"]
        maxsize = data["max_size"]

        pb.pus_tc_tm_23_X_setFileName(packet, filename)
        pb.pus_tc_tm_23_X_setRepositoryPath(packet, repo_path)
        pb.pus_tc_tm_23_1_4_setMaximumSize(packet, maxsize)
        return packet

    @staticmethod
    def tc_tm_23_1_4_get_data(packet):
        data = dict()
        data["repo_path"] = pb.pus_tc_tm_23_X_getRepositoryPath(str(), packet)
        data["file_name"] = pb.pus_tc_tm_23_X_getFileName(str(), packet)
        maxsize = pb.pus_tc_tm_23_1_4_getMaximumSize(packet)
        data["max_size"] = maxsize
        return data

    @staticmethod
    def tc_23_2_3_set_data(packet, data):
        repo_path = data["repo_path"]
        filename = data["file_name"]

        pb.pus_tc_tm_23_X_setFileName(packet, filename)
        pb.pus_tc_tm_23_X_setRepositoryPath(packet, repo_path)
        return packet

    @staticmethod
    def tc_23_2_3_get_data(packet):
        data = dict()
        data["repo_path"] = pb.pus_tc_tm_23_X_getRepositoryPath(str(), packet)
        data["file_name"] = pb.pus_tc_tm_23_X_getFileName(str(), packet)
        return data

    @staticmethod
    def tc_23_3_set_data(packet, data):
        return packet

    @staticmethod
    def tc_23_3_get_data(packet):
        data = dict()
        return data

    @staticmethod
    def tc_23_4_set_data(packet, data):
        return packet

    @staticmethod
    def tc_23_4_get_data(packet):
        data = dict()
        return data

    @staticmethod
    def tc_23_14_set_data(packet, data):
        src_repo = data["source_repository"]
        src_file = data["source_file"]
        dst_repo = data["target_repository"]
        dst_file = data["target_file"]

        pb.pus_tc_23_14_setSourceFileName(packet, src_file)
        pb.pus_tc_23_14_setTargetFileName(packet, dst_file)
        pb.pus_tc_23_14_setSourceRepositoryPath(packet, src_repo)
        pb.pus_tc_23_14_setTargetRepositoryPath(packet, dst_repo)

        return packet

    @staticmethod
    def tc_23_14_get_data(packet):
        data = dict()
        data["source_repository"] = pb.pus_tc_23_14_getSourceRepositoryPath(packet)
        data["source_file"] = pb.pus_tc_23_14_getSourceFileName(packet)
        data["target_repository"] = pb.pus_tc_23_14_getTargetRepositoryPath(packet)
        data["target_file"] = pb.pus_tc_23_14_getTargetFileName(packet)
        return data
