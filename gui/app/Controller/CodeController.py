from Views.CodeView import CodeView


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

    def show(self):
        """
        This method calls the .show() method of the view and returns
        the packet that the user creates in this window
        :return: The created packet
        """
        accepted = self.view.show()
        if accepted == 1:
            return self.view.get_id(), self.view.get_code()
        else:
            return None, None

    def destroy(self):
        self.view.destroy()
