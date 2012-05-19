#!/usr/bin/python

# simple.py

import sys
from PyQt4 import QtGui

app = QtGui.QApplication(sys.argv)

widget = QtGui.QWidget()
widget.resize(2000, 150)
widget.setWindowTitle('Just a try')
widget.show()

sys.exit(app.exec_())

