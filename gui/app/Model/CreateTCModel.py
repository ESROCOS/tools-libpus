class CreateTCModel(object):
    """
    This class represents the model of a createTC view
    """
    def __init__(self, app_model):
        """
        This is the constructor of the class
        :param app_model: The model of the upper class, in this
        case this is the model of the application
        """
        self.app_model = app_model
        self.apid_info = self.app_model.tc_apid
        self.telecommand = {}
        with open("services.txt", "r") as services:
            for line in services:
                line = line.strip('\n').split("|")
                if len(line) == 4 and line[3] == "tc":
                    if line[0] not in self.telecommand:
                        self.telecommand[line[0]] = [line[1]]
                    else:
                        self.telecommand[line[0]].append(line[1])

    def add_to_table(self, packet):
        """
        This method adds a packet in json and packet format to the
        table model of the app
        :param json_data: The packet in json format
        :param packet: The packet
        """
        self.app_model.add(packet)
