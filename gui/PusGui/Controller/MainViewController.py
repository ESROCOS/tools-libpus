# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

import os, sys, json, collections, time
from PySide2 import QtGui, QtCore, QtWidgets
from PySide2.QtCore import Slot

from PusGui.Views import MainView
from PusGui.Views import CreateTCView
from PusGui.Views import DetailsView
from PusGui.Views import FilterView
from PusGui.Utilities.Database import Database
from PusGui.Utilities import PacketTranslator
from PusGui.Model.CreateTCModel import CreateTCModel
from PusGui.Model import App
from PusGui.Model.FilterModel import FilterModel
from PusGui.Controller.CreateTCController import CreateTCController
from PusGui.Controller.FilterController import FilterController
from PusGui.Utilities import PusThread

from PusGui import pb


class MainViewController(object):
    """Controller of MainView view"""

    def __init__(self, model: App, view: MainView):
        """
        The constructor instantiates a MainViewController object

        :param model: The model of the application
        :param view: The view that will be controlled by this class.
                     In this case it will be an instance of the MainView
                     class
        """
        self.model = model
        self.view = view
        self.thread = PusThread(self, self.model)
        self.thread.start()
        self.opened_windows = []
        self.set_callbacks()

    def set_callbacks(self):
        """
        This method connects all the callbacks defined in this class with
        every event in the Main View
        """
        self.view.window.actionCreate_TC.triggered.connect(self.open_create_tc_callback)
        self.view.window.actionAbout_GMV.triggered.connect(self.open_about_callback)
        self.view.window.packagesTable.clicked.connect(self.open_more_details_window_callback)
        self.view.window.actionCreate_filter.triggered.connect(self.open_filter_callback)
        self.view.window.actionDelete_filter.triggered.connect(self.deactivate_filter_callback)
        self.view.window.actionSave_as.triggered.connect(self.open_savefile_window_callback)
        self.view.window.actionLoad.triggered.connect(self.open_openfile_window_callback)
        self.view.window.actionLoad_TCs.triggered.connect(self.load_tcs_callback)
        self.view.set_close_event(self.close_event_callback)
        self.model.table.onClear = self.clear_qtable_callback
        self.model.table.onChange = self.add_elem

    def open_create_tc_callback(self):
        """
        This method opens the Create Telecommand Window
        """
        self.__is_not_used__()
        create_tc_view = CreateTCView()
        create_tc_model = CreateTCModel(self.model)
        create_tc_controller = CreateTCController(create_tc_model, create_tc_view)
        self.opened_windows.append(create_tc_controller)
        create_tc_controller.show()

    @Slot(list)
    def open_filter_callback(self, filter_index=None):
        """
        This method opens the Create Telecommand Window
        """
        if filter_index is None:
            self.__is_not_used__()
            filter_view = FilterView()
            filter_model = FilterModel()
            filter_controller = FilterController(filter_model, filter_view)
            filtered_index = self.model.set_filter(filter_controller.show())
        else:
            filtered_index = filter_index

        qtable = self.view.window.packagesTable

        for i in range(qtable.rowCount()):
            qtable.setRowHidden(i, False)
        for i in range(qtable.rowCount()):
            id_ = int(qtable.item(i, 0).text())
            if id_ not in [filtered_index]:
                qtable.setRowHidden(i, True)

    def deactivate_filter_callback(self):
        self.model.set_filter(None)
        qtable = self.view.window.packagesTable
        for i in range(qtable.rowCount()):
            qtable.setRowHidden(i, False)

    def open_about_callback(self):
        """
        This method opens the GMV's about website
        """
        import webbrowser
        self.__is_not_used__()
        webbrowser.open("https://www.gmv.com/en/Company/AboutGMV/")

    def open_more_details_window_callback(self, clicked_index):
        """
        This method opens and writes all the information
        of the package selected in the window
        """
        row = clicked_index.row()
        pt = PacketTranslator()
        index = int(self.view.window.packagesTable.item(row, 0).text())
        details_view = DetailsView()
        details_view.write_information(json.dumps(json.loads(self.model.table[index][-2]), indent=8))
        self.opened_windows.append(details_view)
        details_view.show()

    def open_savefile_window_callback(self):
        """
        This method makes an insert query to the database
        """
        file = QtWidgets.QFileDialog.getSaveFileName()
        d = Database(file[0])
        d.create_dump_table()
        packages = [tuple(e[1:-1]) for e in self.model.table]

        d.insert_db("INSERT INTO packages VALUES(?,?,?,?,?,?,?,?,?,?)", packages)

        self.__is_not_used__()

    def open_openfile_window_callback(self):
        """
        This method is triggered when the user hits the button to load a
        dump from file. This method makes a query to the database and adds each
        result to the table
        """
        file = QtWidgets.QFileDialog.getOpenFileName()
        d = Database(file[0])
        d.create_dump_table()

        elems = d.query_db("SELECT * FROM packages")
        self.model.table.clear()
        for i, elem in enumerate(elems):
            self.model.table.append([i]+list(elem)+[None]) # Revisar

        self.__is_not_used__()

    def load_tcs_callback(self):
        file = QtWidgets.QFileDialog.getOpenFileName()
        file = file[0]
        if file is None or file is "":
            return

        
        if not file.endswith(".json.mako"):
            msg_box = QtWidgets.QMessageBox()
            msg_box.setText('Please select a .json.mako file')
            msg_box.exec_()
        else:
            self.thread.load_test(file)

    def close_event_callback(self, event):
        try:
            for window in self.opened_windows:
                window.destroy()
        except Exception as e:
            pass

        self.thread.quit()
        event.accept()

    def __convert_dict(self, elem: collections.OrderedDict, tab_count: int = 0):
        """
        Private method to convert a dictionary to str
        :param elem: The dictionary to convert
        :param tab_count: Number of tab for indenting elements of dict
        :return: A string representing the dict
        """
        result = ""
        boolean = True if tab_count == 0 else False
        for k in sorted(elem.keys(), reverse=boolean):
            result += "\t" * tab_count + str(k) + ": "
            if type(elem[k]) == dict:
                result += "\n" + self.__convert_dict(elem[k], tab_count + 1) + "\n"
            else:
                result += str(elem[k]) + "\n"

        return result

    def add_elem(self, row, elem: list):
        """
        This method is called whenever a new package arrives or is sent
        :param row: place where the new package will be shown
        :param elem: json of the package to add to the table
        """
        self.view.window.packagesTable.setSortingEnabled(False)

        while (self.view.window.packagesTable.rowCount() > 100):
            a = int(self.view.window.packagesTable.item(0, 0).text())
            b = int(self.view.window.packagesTable.item(self.view.window.packagesTable.rowCount() - 1, 0).text())
            if(a > b):
                self.view.window.packagesTable.removeRow(self.view.window.packagesTable.rowCount() - 1)
            else:
                self.view.window.packagesTable.removeRow(0)

        column_type = [IntegerTableWidgetItem, QtWidgets.QTableWidgetItem, IntegerTableWidgetItem,
                       IntegerTableWidgetItem, TimeTableWidgetItem, QtWidgets.QTableWidgetItem,
                       QtWidgets.QTableWidgetItem, IntegerTableWidgetItem, QtWidgets.QTableWidgetItem,
                       QtWidgets.QTableWidgetItem]

        row_count = self.view.window.packagesTable.rowCount()
        self.view.window.packagesTable.insertRow(row_count)

        for i, e in enumerate(elem[:-2]):
            itm = column_type[i](str(e))
            self.view.window.packagesTable.setItem(row_count, i, itm)

            if i != len(elem[:-2])-1:
                self.view.window.packagesTable.item(row_count, i).setTextAlignment(QtCore.Qt.AlignCenter |
                                                                             QtCore.Qt.AlignVCenter)

        if self.model.active_filter():
            pass

        if not self.model.check_filter(elem):
            row_count = self.view.window.packagesTable.rowCount()
            self.view.window.packagesTable.setRowHidden(row_count, True)

        # elem[6] = APID // elem[2] == svc
        self.update_params_table(elem[6], elem[9].split()[-1], elem[2], elem[3])  # at this point system_params have already been updated from model
        self.view.window.packagesTable.setSortingEnabled(True)

    def update_params_table(self, apid, reportId, svc, subtype):
        """
        This method update parameters of system status tab
        :param svc: The service of the packet arrived
        """
        params = self.model.get_params(apid)
        for k, v in params.items():
            if k == "spacecraftTime" and svc == 9:
                time_ = time.strftime('%H:%M:%S', time.localtime(v))
                self.view.update_space_time(v)
            elif k != "spacecraftTime" and (svc, subtype) == (3,25):
                self.view.update_system_params(apid, int(reportId), k, v)

    def clear_qtable_callback(self):
        """
        This method clears the table of the main window
        """
        self.view.window.packagesTable.clearContents()
        self.view.window.packagesTable.setRowCount(1)
        self.__is_not_used__()

    def show(self):
        """
        This method calls the .show() method of the view
        """
        self.view.show()

    @staticmethod
    def __is_not_used__():
        pass


class IntegerTableWidgetItem(QtWidgets.QTableWidgetItem):
    """
    This class inherits QTableWidgetItem to be able to
    sort the table by integers
    """
    def __lt__(self, other):
        if isinstance(other, QtWidgets.QTableWidgetItem):
            my_value = int(self.data(QtCore.Qt.EditRole))
            other_value = int(other.data(QtCore.Qt.EditRole))

            return my_value < other_value

        return super().__lt__(other)


class TimeTableWidgetItem(QtWidgets.QTableWidgetItem):
    """
    This class inherits QTableWidgetItem to be able to
    sort the table by time
    """
    def __lt__(self, other):
        if isinstance(other, QtWidgets.QTableWidgetItem):
            import datetime
            my_value = datetime.datetime.strptime(self.data(QtCore.Qt.EditRole), '%H:%M:%S').time()
            other_value = datetime.datetime.strptime(other.data(QtCore.Qt.EditRole), '%H:%M:%S').time()

            return my_value < other_value

        return super().__lt__(other)

