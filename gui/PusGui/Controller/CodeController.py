# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

from PusGui.Views import CodeView


class CodeController(object):
    """
    This class controls st18 window to add code
    """
    def __init__(self, model: None, view: CodeView):
        """
        Constructor of the class
        :param model: The model the controller references
        :param view: The view the controller references
        """
        self.model = model
        self.view = view
        self.set_callbacks()

    def set_callbacks(self):
        """
        This method is used to set the callbacks to every action that the
        user triggers
        """
        self.view.window.loadObcpFile.clicked.connect(self.load_obcp_callback)
        self.view.set_close_event(self.close_event_callback)

    def load_obcp_callback(self):
        filename = QtGui.QFileDialog.getOpenFileName()[0]
        with open(filename) as filedata:
            self.view.set_code(filedata.read())

    def close_event_callback(self, event):
        try:
            self.view.window.close()
        except Exception as e:
            pass
        event.accept()

    def show(self):
        """
        This method calls the .show() method of the view and returns
        the packet that the user creates in this window
        :return: The created packet
        """
        accepted = self.view.show()
        if accepted == 1:
            length, obcpcode = convert_py_to_hex(self.view.get_code())
            return self.view.get_id(), length, obcpcode
        else:
            return None, None, None

    def set_close_event(self, fun):
        self.view.closeEvent = fun

    def destroy(self):
        self.view.destroy()
