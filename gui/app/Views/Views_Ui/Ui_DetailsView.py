# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'DetailsView.ui'
#
# Created: Tue Apr  3 11:38:39 2018
#      by: pyside-uic 0.2.15 running on PySide 1.2.4
#
# WARNING! All changes made in this file will be lost!

from PySide import QtCore, QtGui

class Ui_DetailsView(object):
    def setupUi(self, DetailsView):
        DetailsView.setObjectName("DetailsView")
        DetailsView.resize(563, 689)
        self.informationLabel = QtGui.QLabel(DetailsView)
        self.informationLabel.setGeometry(QtCore.QRect(10, 20, 91, 17))
        self.informationLabel.setObjectName("informationLabel")
        self.informationValueLabel = QtGui.QTextEdit(DetailsView)
        self.informationValueLabel.setGeometry(QtCore.QRect(10, 40, 541, 641))
        self.informationValueLabel.setObjectName("informationValueLabel")

        self.retranslateUi(DetailsView)
        QtCore.QMetaObject.connectSlotsByName(DetailsView)

    def retranslateUi(self, DetailsView):
        DetailsView.setWindowTitle(QtGui.QApplication.translate("DetailsView", "More details", None, QtGui.QApplication.UnicodeUTF8))
        self.informationLabel.setText(QtGui.QApplication.translate("DetailsView", "Details:", None, QtGui.QApplication.UnicodeUTF8))

