# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'CodeView.ui'
#
# Created: Tue Apr  3 11:38:39 2018
#      by: pyside-uic 0.2.15 running on PySide 1.2.4
#
# WARNING! All changes made in this file will be lost!

from PySide import QtCore, QtGui

class Ui_CodeView(object):
    def setupUi(self, CodeView):
        CodeView.setObjectName("CodeView")
        CodeView.resize(412, 377)
        self.buttonBox = QtGui.QDialogButtonBox(CodeView)
        self.buttonBox.setGeometry(QtCore.QRect(10, 340, 391, 32))
        self.buttonBox.setOrientation(QtCore.Qt.Horizontal)
        self.buttonBox.setStandardButtons(QtGui.QDialogButtonBox.Cancel|QtGui.QDialogButtonBox.Ok)
        self.buttonBox.setObjectName("buttonBox")
        self.obcpCodeTextEdit = QtGui.QPlainTextEdit(CodeView)
        self.obcpCodeTextEdit.setGeometry(QtCore.QRect(10, 60, 391, 271))
        self.obcpCodeTextEdit.setObjectName("obcpCodeTextEdit")
        self.obcpIdLbl = QtGui.QLabel(CodeView)
        self.obcpIdLbl.setGeometry(QtCore.QRect(10, 20, 68, 17))
        self.obcpIdLbl.setObjectName("obcpIdLbl")
        self.obcpIdValue = QtGui.QLineEdit(CodeView)
        self.obcpIdValue.setGeometry(QtCore.QRect(80, 15, 321, 27))
        self.obcpIdValue.setObjectName("obcpIdValue")

        self.retranslateUi(CodeView)
        QtCore.QObject.connect(self.buttonBox, QtCore.SIGNAL("accepted()"), CodeView.accept)
        QtCore.QObject.connect(self.buttonBox, QtCore.SIGNAL("rejected()"), CodeView.reject)
        QtCore.QMetaObject.connectSlotsByName(CodeView)

    def retranslateUi(self, CodeView):
        CodeView.setWindowTitle(QtGui.QApplication.translate("CodeView", "Code", None, QtGui.QApplication.UnicodeUTF8))
        self.obcpIdLbl.setText(QtGui.QApplication.translate("CodeView", "Obcp id:", None, QtGui.QApplication.UnicodeUTF8))

