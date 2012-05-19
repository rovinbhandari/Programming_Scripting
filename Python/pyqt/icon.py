#!/usr/bin/python

# icon.py

import sys
from PyQt4 import QtGui


class Icon(QtGui.QWidget):
    def __init__(self, parent=None):
        QtGui.QWidget.__init__(self, parent)

        self.setGeometry(300, 300, 250, 150)
        self.setWindowTitle('Window with an icon')
        self.setWindowIcon(QtGui.QIcon('python.png'))

app = QtGui.QApplication(sys.argv)
icon = Icon()
icon.show()
sys.exit(app.exec_())


