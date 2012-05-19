#!/usr/bin/python

import sys
from ui import Ui_Dialog
from PyQt4 import QtCore, QtGui

class StartQT4(QtGui.QMainWindow):
    
    def __init__(self, parent = None):
        QtGui.QWidget.__init__(self, parent)
        self.ui = Ui_Dialog()
        self.ui.setupUi(self)
        
        #Defining the slots and signals
	QtCore.QObject.connect(self.ui.enco, QtCore.SIGNAL("clicked()"), self.encode)
	QtCore.QObject.connect(self.ui.deco, QtCore.SIGNAL("clicked()"), self.decode)
    	QtCore.QObject.connect(self.ui.clear, QtCore.SIGNAL("clicked()"), self.clearall)
    	
    def encode(self):
    		
    def clearall(self):
    	
    def decode(self):
    	
if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    myapp = StartQT4()
    myapp.show()
    sys.exit(app.exec_())

