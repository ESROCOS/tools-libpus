import jsonschema
from jsonschema.exceptions import ValidationError
import json


class ValidateJson(object):
    """
    This class uses jsonschema to validate every packet in json format
    """
    def check(self, packet: dict):
        """
        This method checks if a packet in json format is correct
        :param packet: The packet to be checked
        :except: This method raises an exception when the packet is not correct
        """
        dir = "Schemas/"
        svc = packet["data"]["pck_sec_head"]["msg_type_id"]["service_type_id"]
        msg = packet["data"]["pck_sec_head"]["msg_type_id"]["msg_subtype_id"]

        try:
            if (svc, msg) == (8, 1):
                self.__validate__(packet, dir + "st08_1_schema.json")
            elif (svc, msg) == (9, 1):
                self.__validate__(packet, dir + "st09_1_schema.json")
            elif svc == 11:
                if msg == 4:
                    pass
                else:
                    self.__validate__(packet, dir + "st11_1_2_3_schema.json")
            elif svc == 12:
                if msg == 1 or msg == 2:
                    self.__validate__(packet, dir + "st12_1_2_schema.json")
                else:
                    self.__validate__(packet, dir + "st12_15_16_schema.json")
            elif svc == 17:
                self.__validate__(packet, dir + "st17_1_schema.json")
            elif svc == 18:
                if msg == 2 or msg == 6 or msg == 12:
                    self.__validate__(packet, dir + "st18_2_6_12_schema.json")
                elif msg == 4 or msg == 5:
                    self.__validate__(packet, dir + "st18_4_5_schema.json")
                elif msg == 21 or msg == 22:
                    self.__validate__(packet, dir + "st18_21_22_schema.json")
                elif msg == 1:
                    self.__validate__(packet, dir + "st18_1_schema.json")
                elif msg == 3:
                    self.__validate__(packet, dir + "st18_3_schema.json")
                elif msg == 13:
                    self.__validate__(packet, dir + "st18_13_schema.json")
            elif svc == 19:
                if msg == 1:
                    pass
                else:
                    self.__validate__(packet, dir + "st19_2_4_5_schema.json")
            elif svc == 20:
                if msg == 1:
                    self.__validate__(packet, dir + "st20_1_schema.json")
                elif msg == 3:
                    self.__validate__(packet, dir + "st20_3_schema.json")
            elif svc == 23:
                if msg == 1:
                    self.__validate__(packet, dir + "st23_1_schema.json")
                elif msg == 2 or msg == 3:
                    self.__validate__(packet, dir + "st23_2_3_schema.json")
                else:
                    self.__validate__(packet, dir + "st23_14_schema.json")
        except ValidationError:
            raise

    @staticmethod
    def __validate__(packet: dict, schema: str):
        """
        This method validates the packet in json format according to the jsonschema
        defined in the Schemas file
        :param packet: The packet to be validated
        :param schema: The jsonschema of the packet
        :except: This method raises an exception when the packet
        in json format does not satisfy the corresponding jsonschema
        """
        with open(schema, "r") as sch_file:
            schema = json.load(sch_file)
        try:
            jsonschema.validate(packet, schema)
        except ValidationError:
            raise
