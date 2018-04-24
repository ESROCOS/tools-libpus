from PySide.QtCore import QObject, Signal, Slot
from PySide.QtCore import QThread, QWaitCondition, QMutex, QTimer

from . import PacketTranslator, MakoTranslate, Database
from .TestTags import TestTags
from Model.FilterModel import FilterModel

import json, sys, os
lib_path = os.path.join('/home/esrocos/esrocos-ws-pus/tools-libpus/debug/pylib')
sys.path.append(lib_path)
import pusbinding as pb


class AddTableSignal(QObject):
    """
    This class overrides a QObject to be
    able to emit custom signals
    """
    signal = Signal(dict)

    def __init__(self):
        QObject.__init__(self)

    def throw(self, elem):
        """
        This method emits the signal object defined
        inside the class
        :param elem: The element that will be emited with
        the signal
        """
        self.signal.emit(elem)


class FilterTableSignal(QObject):
    """
    This class overrides a QObject to be
    able to emit custom signals
    """
    signal = Signal(dict)

    def __init__(self):
        QObject.__init__(self)

    def throw(self, elem):
        """
        This method emits the signal object defined
        inside the class
        :param elem: The element that will be emited with
        the signal
        """
        self.signal.emit(elem)


class PusThread(QThread):
    """
    This class overrides a QThread object to be able to
    define custom safe threads with custom signals. This
    class is used to be able to make a simulation of a connection
    with the robot where the packets arrives with an interval
    between them without blocking the rest of the functionality
    of the application. The simulation is done by reading the
    packets from a json file.

    """
    def __init__(self, controller, model):
        """
        This is the constructor of the class
        :param file: The json file where the packets are defined
        :param model: The model of the application
        """
        QThread.__init__(self)
        self.model = model
        self.controller = controller
        self.add_table_signal = AddTableSignal()
        self.add_table_signal.signal.connect(self.model.add)
        self.filter_table_signal = AddTableSignal()
        self.filter_table_signal.signal.connect(self.controller.open_filter_callback)
        self.json_file = None
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.update_packets)
        self.json_file_loaded = QWaitCondition()
        self.mutex = QMutex()

    def run(self):
        """
        This method runs the thread reading from
        the json defined and making an sleep of T
        seconds between packet and packet according
        to the interval defined in the json file.
        """

        self.timer.start(1000)

        while True:
            self.mutex.lock()
            self.json_file_loaded.wait(self.mutex)
            file = self.json_file
            self.mutex.unlock()

            pt = PacketTranslator()
            mt = MakoTranslate()
            if file is not None:
                with open(file) as jfile:
                    jsondata = mt.replace(jfile.read())
                    activities = json.loads(jsondata)[TestTags.ACTIVITIES_TAG]
                    for activity in activities:
                        interval = activity[TestTags.INTERVAL_TAG]
                        self.sleep(interval)
                        if TestTags.PACKET_TAG in activity:
                            packet = pt.json2packet(activity[TestTags.PACKET_TAG])
                            pb.pus_notify_sendPacket(packet)
                            self.add_table_signal.throw(packet)
                        elif TestTags.ACTIONS_TAG in activity:
                            if activity[TestTags.ACTIONS_TAG] == TestTags.SAVEDB_TAG:
                                file = activity[TestTags.PARAMS_TAG]

                                d = Database(file)
                                d.create_dump_table()
                                packages = [tuple(e[1:-1]) for e in self.model.table]

                                d.insert_db("INSERT INTO packages VALUES(?,?,?,?,?,?,?,?,?,?)", packages)

                            elif activity[TestTags.ACTIONS_TAG] == TestTags.SETFILTER_TAG:
                                filter_ = FilterModel()
                                type_ = activity[TestTags.PARAMS_TAG]["type"]
                                svc = activity[TestTags.PARAMS_TAG]["svc"]
                                msg = activity[TestTags.PARAMS_TAG]["msg"]
                                filter_.set_filter_options(type_, svc, msg)
                                filter_index = self.model.set_filter(filter_.get_filter_options())
                                self.filter_table_signal.throw(filter_index)
            self.mutex.lock()
            self.json_file = None
            self.mutex.unlock()

    def update_packets(self):
        for _ in range(3):
            packet = pb.pusPacket_t()
            if pb.pusError_t.PUS_NO_ERROR == pb.pus_notify_readTm(packet):  # Comprobar si null
                self.add_table_signal.throw(packet)

    def load_test(self, json_file):
        self.mutex.lock()
        self.json_file = json_file
        if json_file is not None:
            self.json_file_loaded.wakeAll()
        self.mutex.unlock()
