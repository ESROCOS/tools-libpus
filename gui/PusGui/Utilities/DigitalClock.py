# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

from PySide2 import QtCore, QtGui, QtWidgets
import time


class DigitalClock(QtWidgets.QLabel):
    def __init__(self, tim, parent=None):
        super().__init__(parent)
        self.tim = tim
        self.setVisible(False)
        timer = QtCore.QTimer(self)
        timer.timeout.connect(self.show_time)
        timer.start(1000)
        self.show_time()

    def show_time(self):
        self.tim += 1
        ltime = time.localtime(self.tim)
        t = QtCore.QTime(ltime.tm_hour, ltime.tm_min, s=ltime.tm_sec)
        text = t.toString('hh:mm:ss')
        self.setText(text)

    def setText(self, tim):
        if type(tim) == int:
            self.tim = tim
        else:
            super().setText(tim)
