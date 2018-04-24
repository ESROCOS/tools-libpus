# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'AddTCView.ui'
#
# Created: Tue Apr  3 11:38:38 2018
#      by: pyside-uic 0.2.15 running on PySide 1.2.4
#
# WARNING! All changes made in this file will be lost!

from PySide import QtCore, QtGui

class Ui_AddTCView(object):
    def setupUi(self, AddTCView):
        AddTCView.setObjectName("AddTCView")
        AddTCView.resize(420, 710)
        self.buttonBox = QtGui.QDialogButtonBox(AddTCView)
        self.buttonBox.setGeometry(QtCore.QRect(70, 670, 341, 32))
        self.buttonBox.setOrientation(QtCore.Qt.Horizontal)
        self.buttonBox.setStandardButtons(QtGui.QDialogButtonBox.Cancel|QtGui.QDialogButtonBox.Ok)
        self.buttonBox.setObjectName("buttonBox")
        self.serviceComboBox = QtGui.QComboBox(AddTCView)
        self.serviceComboBox.setGeometry(QtCore.QRect(100, 70, 85, 27))
        self.serviceComboBox.setObjectName("serviceComboBox")
        self.parentTCLbl = QtGui.QLabel(AddTCView)
        self.parentTCLbl.setGeometry(QtCore.QRect(10, 30, 401, 17))
        self.parentTCLbl.setObjectName("parentTCLbl")
        self.pckSecHeaderTextEdit = QtGui.QPlainTextEdit(AddTCView)
        self.pckSecHeaderTextEdit.setGeometry(QtCore.QRect(10, 150, 401, 251))
        self.pckSecHeaderTextEdit.setObjectName("pckSecHeaderTextEdit")
        self.label_2 = QtGui.QLabel(AddTCView)
        self.label_2.setGeometry(QtCore.QRect(10, 75, 121, 17))
        self.label_2.setObjectName("label_2")
        self.label = QtGui.QLabel(AddTCView)
        self.label.setGeometry(QtCore.QRect(10, 10, 401, 21))
        self.label.setObjectName("label")
        self.label_3 = QtGui.QLabel(AddTCView)
        self.label_3.setGeometry(QtCore.QRect(200, 75, 121, 17))
        self.label_3.setObjectName("label_3")
        self.msgComboBox = QtGui.QComboBox(AddTCView)
        self.msgComboBox.setGeometry(QtCore.QRect(330, 70, 85, 27))
        self.msgComboBox.setObjectName("msgComboBox")
        self.pckSecHeaderLbl = QtGui.QLabel(AddTCView)
        self.pckSecHeaderLbl.setGeometry(QtCore.QRect(10, 130, 171, 17))
        self.pckSecHeaderLbl.setObjectName("pckSecHeaderLbl")
        self.srcDataLbl = QtGui.QLabel(AddTCView)
        self.srcDataLbl.setGeometry(QtCore.QRect(10, 410, 171, 17))
        self.srcDataLbl.setObjectName("srcDataLbl")
        self.srcDataTextEdit = QtGui.QPlainTextEdit(AddTCView)
        self.srcDataTextEdit.setGeometry(QtCore.QRect(10, 430, 401, 231))
        self.srcDataTextEdit.setObjectName("srcDataTextEdit")
        self.dateTimeEdit = QtGui.QDateTimeEdit(AddTCView)
        self.dateTimeEdit.setGeometry(QtCore.QRect(100, 100, 131, 27))
        self.dateTimeEdit.setObjectName("dateTimeEdit")
        self.scheduleLbl = QtGui.QLabel(AddTCView)
        self.scheduleLbl.setGeometry(QtCore.QRect(30, 103, 61, 20))
        self.scheduleLbl.setObjectName("scheduleLbl")
        self.eventIdLbl = QtGui.QLabel(AddTCView)
        self.eventIdLbl.setGeometry(QtCore.QRect(35, 103, 61, 17))
        self.eventIdLbl.setObjectName("eventIdLbl")
        self.eventIdLineEdit = QtGui.QLineEdit(AddTCView)
        self.eventIdLineEdit.setGeometry(QtCore.QRect(100, 100, 131, 27))
        self.eventIdLineEdit.setObjectName("eventIdLineEdit")

        self.retranslateUi(AddTCView)
        QtCore.QObject.connect(self.buttonBox, QtCore.SIGNAL("accepted()"), AddTCView.accept)
        QtCore.QObject.connect(self.buttonBox, QtCore.SIGNAL("rejected()"), AddTCView.reject)
        QtCore.QMetaObject.connectSlotsByName(AddTCView)

    def retranslateUi(self, AddTCView):
        AddTCView.setWindowTitle(QtGui.QApplication.translate("AddTCView", "Add Telecommand", None, QtGui.QApplication.UnicodeUTF8))
        self.parentTCLbl.setText(QtGui.QApplication.translate("AddTCView", "st19 telecommand.", None, QtGui.QApplication.UnicodeUTF8))
        self.label_2.setText(QtGui.QApplication.translate("AddTCView", "Service type", None, QtGui.QApplication.UnicodeUTF8))
        self.label.setText(QtGui.QApplication.translate("AddTCView", "Please create the telecommand that you want to add to ", None, QtGui.QApplication.UnicodeUTF8))
        self.label_3.setText(QtGui.QApplication.translate("AddTCView", "Message subtype", None, QtGui.QApplication.UnicodeUTF8))
        self.pckSecHeaderLbl.setText(QtGui.QApplication.translate("AddTCView", "Packet secondary header", None, QtGui.QApplication.UnicodeUTF8))
        self.srcDataLbl.setText(QtGui.QApplication.translate("AddTCView", "Source data", None, QtGui.QApplication.UnicodeUTF8))
        self.scheduleLbl.setText(QtGui.QApplication.translate("AddTCView", "Schedule", None, QtGui.QApplication.UnicodeUTF8))
        self.eventIdLbl.setText(QtGui.QApplication.translate("AddTCView", "Event id", None, QtGui.QApplication.UnicodeUTF8))

