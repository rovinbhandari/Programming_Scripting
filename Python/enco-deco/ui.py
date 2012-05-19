# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ui.ui'
#
# Created: Tue Mar  8 12:33:51 2011
#      by: PyQt4 UI code generator 4.7.2
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

class Ui_Dialog(object):
    def setupUi(self, Dialog):
        Dialog.setObjectName("Dialog")
        Dialog.resize(579, 612)
        self.plain = QtGui.QTextEdit(Dialog)
        self.plain.setGeometry(QtCore.QRect(40, 20, 501, 211))
        self.plain.setObjectName("plain")
        self.crypted = QtGui.QTextEdit(Dialog)
        self.crypted.setGeometry(QtCore.QRect(40, 250, 501, 221))
        self.crypted.setObjectName("crypted")
        self.enco = QtGui.QPushButton(Dialog)
        self.enco.setGeometry(QtCore.QRect(160, 520, 87, 27))
        self.enco.setObjectName("enco")
        self.deco = QtGui.QPushButton(Dialog)
        self.deco.setGeometry(QtCore.QRect(310, 520, 87, 27))
        self.deco.setObjectName("deco")
        self.clear = QtGui.QPushButton(Dialog)
        self.clear.setGeometry(QtCore.QRect(230, 560, 101, 27))
        self.clear.setObjectName("clear")

        self.retranslateUi(Dialog)
        QtCore.QMetaObject.connectSlotsByName(Dialog)

    def retranslateUi(self, Dialog):
        Dialog.setWindowTitle(QtGui.QApplication.translate("Dialog", "Dialog", None, QtGui.QApplication.UnicodeUTF8))
        self.enco.setText(QtGui.QApplication.translate("Dialog", "enco", None, QtGui.QApplication.UnicodeUTF8))
        self.deco.setText(QtGui.QApplication.translate("Dialog", "deco", None, QtGui.QApplication.UnicodeUTF8))
        self.clear.setText(QtGui.QApplication.translate("Dialog", "clear", None, QtGui.QApplication.UnicodeUTF8))

