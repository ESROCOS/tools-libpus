# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'FilterView.ui'
#
# Created: Tue Apr  3 11:38:39 2018
#      by: pyside-uic 0.2.15 running on PySide 1.2.4
#
# WARNING! All changes made in this file will be lost!

from PySide import QtCore, QtGui

class Ui_FilterView(object):
    def setupUi(self, FilterView):
        FilterView.setObjectName("FilterView")
        FilterView.resize(330, 169)
        self.label_3 = QtGui.QLabel(FilterView)
        self.label_3.setGeometry(QtCore.QRect(200, 75, 71, 17))
        self.label_3.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_3.setObjectName("label_3")
        self.label_2 = QtGui.QLabel(FilterView)
        self.label_2.setGeometry(QtCore.QRect(10, 105, 81, 20))
        self.label_2.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_2.setObjectName("label_2")
        self.typeabel = QtGui.QLabel(FilterView)
        self.typeabel.setGeometry(QtCore.QRect(10, 15, 41, 17))
        self.typeabel.setObjectName("typeabel")
        self.statusLabel = QtGui.QLabel(FilterView)
        self.statusLabel.setGeometry(QtCore.QRect(180, 15, 51, 17))
        self.statusLabel.setObjectName("statusLabel")
        self.label_4 = QtGui.QLabel(FilterView)
        self.label_4.setGeometry(QtCore.QRect(190, 105, 81, 20))
        self.label_4.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_4.setObjectName("label_4")
        self.msgIdLineEdit = QtGui.QLineEdit(FilterView)
        self.msgIdLineEdit.setGeometry(QtCore.QRect(100, 100, 31, 27))
        self.msgIdLineEdit.setObjectName("msgIdLineEdit")
        self.dstLineEdit = QtGui.QLineEdit(FilterView)
        self.dstLineEdit.setGeometry(QtCore.QRect(280, 100, 31, 27))
        self.dstLineEdit.setObjectName("dstLineEdit")
        self.label = QtGui.QLabel(FilterView)
        self.label.setGeometry(QtCore.QRect(20, 75, 71, 17))
        self.label.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label.setObjectName("label")
        self.serviceIdLineEdit = QtGui.QLineEdit(FilterView)
        self.serviceIdLineEdit.setGeometry(QtCore.QRect(100, 70, 31, 27))
        self.serviceIdLineEdit.setObjectName("serviceIdLineEdit")
        self.typeComboBox = QtGui.QComboBox(FilterView)
        self.typeComboBox.setGeometry(QtCore.QRect(10, 35, 141, 27))
        self.typeComboBox.setObjectName("typeComboBox")
        self.typeComboBox.addItem("")
        self.typeComboBox.addItem("")
        self.typeComboBox.addItem("")
        self.statusComboBox = QtGui.QComboBox(FilterView)
        self.statusComboBox.setGeometry(QtCore.QRect(180, 35, 141, 27))
        self.statusComboBox.setObjectName("statusComboBox")
        self.statusComboBox.addItem("")
        self.statusComboBox.addItem("")
        self.statusComboBox.addItem("")
        self.srcLineEdit = QtGui.QLineEdit(FilterView)
        self.srcLineEdit.setGeometry(QtCore.QRect(280, 70, 31, 27))
        self.srcLineEdit.setObjectName("srcLineEdit")
        self.okButton = QtGui.QPushButton(FilterView)
        self.okButton.setGeometry(QtCore.QRect(270, 140, 51, 27))
        self.okButton.setStyleSheet("")
        self.okButton.setObjectName("okButton")
        self.cancelButton = QtGui.QPushButton(FilterView)
        self.cancelButton.setGeometry(QtCore.QRect(190, 140, 71, 27))
        self.cancelButton.setObjectName("cancelButton")

        self.retranslateUi(FilterView)
        QtCore.QMetaObject.connectSlotsByName(FilterView)

    def retranslateUi(self, FilterView):
        FilterView.setWindowTitle(QtGui.QApplication.translate("FilterView", "Create filter", None, QtGui.QApplication.UnicodeUTF8))
        self.label_3.setText(QtGui.QApplication.translate("FilterView", "Source", None, QtGui.QApplication.UnicodeUTF8))
        self.label_2.setText(QtGui.QApplication.translate("FilterView", "Message id", None, QtGui.QApplication.UnicodeUTF8))
        self.typeabel.setText(QtGui.QApplication.translate("FilterView", "Type", None, QtGui.QApplication.UnicodeUTF8))
        self.statusLabel.setText(QtGui.QApplication.translate("FilterView", "Status", None, QtGui.QApplication.UnicodeUTF8))
        self.label_4.setText(QtGui.QApplication.translate("FilterView", "Destination", None, QtGui.QApplication.UnicodeUTF8))
        self.label.setText(QtGui.QApplication.translate("FilterView", "Service id", None, QtGui.QApplication.UnicodeUTF8))
        self.typeComboBox.setItemText(0, QtGui.QApplication.translate("FilterView", "All", None, QtGui.QApplication.UnicodeUTF8))
        self.typeComboBox.setItemText(1, QtGui.QApplication.translate("FilterView", "Telecommand", None, QtGui.QApplication.UnicodeUTF8))
        self.typeComboBox.setItemText(2, QtGui.QApplication.translate("FilterView", "Telemetry", None, QtGui.QApplication.UnicodeUTF8))
        self.statusComboBox.setItemText(0, QtGui.QApplication.translate("FilterView", "All", None, QtGui.QApplication.UnicodeUTF8))
        self.statusComboBox.setItemText(1, QtGui.QApplication.translate("FilterView", "OK", None, QtGui.QApplication.UnicodeUTF8))
        self.statusComboBox.setItemText(2, QtGui.QApplication.translate("FilterView", "ERROR", None, QtGui.QApplication.UnicodeUTF8))
        self.okButton.setText(QtGui.QApplication.translate("FilterView", "OK", None, QtGui.QApplication.UnicodeUTF8))
        self.cancelButton.setText(QtGui.QApplication.translate("FilterView", "Cancel", None, QtGui.QApplication.UnicodeUTF8))

