class FilterModel(object):
    """
    This class represents the model of a Filter view.
    It defines the type of the packets to be shown, the
    subservice id and the submessage id
    """
    def __init__(self):
        """
        This is the constructor of the class
        """
        self.type = None
        self.subsvc = None
        self.submsg = None

    def set_filter_options(self, type: str, subsvc: int, submsg: int):
        """
        This method sets all the parameters
        :param type: The packet type
        :param subsvc: The packet subservice
        :param submsg: The packet submessage
        """
        self.type = type
        self.subsvc = subsvc
        self.submsg = submsg

    def get_filter_options(self):
        """
        This method gets all the parameters of the filter
        :return: A dictionary with all the teh parameters of tge filter
        """
        if self.type == "" and self.subsvc == 0 and self.submsg == 0:
            return None
        filtr = {"type": self.type, "svc": self.subsvc, "msg": self.submsg}
        print(filtr)
        return filtr
