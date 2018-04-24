from PySide import QtCore, QtGui
from Views import FilterView
from Model import FilterModel


class FilterController(object):
    """
    This class controls the filter functionality
    """
    def __init__(self, model: FilterModel, view: FilterView):
        """
        Constructor of FilterCotroller class
        :param model: The model referenced by the class
        :param view: The view referenced by the class
        """
        self.model = model
        self.view = view
        self.set_callbacks()

    def set_callbacks(self):
        """
        This method is used to set the callbacks to every action that the
        user triggers
        """
        self.view.window.okButton.clicked.connect(self.accept_callback)
        self.view.window.cancelButton.clicked.connect(self.reject_callback)

    def accept_callback(self):
        """
        This method is triggered when the user hits the accept button of
        the window once the filter is already defined. The filter is saved
        and lately applied
        """
        SPLIT_CHRS = ", "
        type_combo_box = self.view.window.typeComboBox
        type = type_combo_box.itemData(type_combo_box.currentIndex())

        try:
            svc_text = self.view.window.serviceIdLineEdit.text()
            if svc_text == "":
                svc = 0
            else:
                svc = list(map(int, svc_text.split(SPLIT_CHRS)))

            msg_text = self.view.window.msgIdLineEdit.text()
            if msg_text == "":
                msg = 0
            else:
                msg = list(map(int, msg_text.split(SPLIT_CHRS)))

            self.model.set_filter_options(type, svc, msg)
            self.view.view.accept()
        except ValueError as ve:
            msg_box = QtGui.QMessageBox()
            msg_box.setText('Some fields may be incorrect {}'.format(ve))
            msg_box.setStandardButtons(QtGui.QMessageBox.Ok | QtGui.QMessageBox.Cancel)
            msg_box.exec_()

    def reject_callback(self):
        """
        This method is called when the user hits the cancel button of the view
        """
        self.view.view.reject()

    def show(self):
        """
        This method calls the .show() method of the view
        and returns the options defined in the filter.
        :return: Options of the filter
        """
        code = self.view.show()
        if code == 1:
            return self.model.get_filter_options()
        else:
            return None

    def destroy(self):
        self.view.destroy()