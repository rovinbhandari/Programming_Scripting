#!/usr/bin/python

import sys
from ui import Ui_Dialog
from PyQt4 import QtCore, QtGui

class StartQT4(QtGui.QMainWindow):
    enc_type = 'hex'
    
    def __init__(self, parent = None):
        QtGui.QWidget.__init__(self, parent)
        self.ui = Ui_Dialog()
        self.ui.setupUi(self)
        
        #Defining the slots and signals
	QtCore.QObject.connect(self.ui.enco, QtCore.SIGNAL("clicked()"), self.encode)
	QtCore.QObject.connect(self.ui.deco, QtCore.SIGNAL("clicked()"), self.decode)
    	QtCore.QObject.connect(self.ui.clear, QtCore.SIGNAL("clicked()"), self.clearall)
    	
    def encode(self):
    	qs = self.ui.plain.toPlainText()
    	s = str(qs)
    	t = s.encode(self.enc_type, 'strict')
	#t = s.upper()
	self.ui.crypted.setText(t)
	
    def clearall(self):
    	self.ui.plain.setText('')
    	self.ui.crypted.setText('')
    
    def decode(self):
    	qt = self.ui.crypted.toPlainText()
    	t = str(qt)
    	s = t.decode(self.enc_type, 'strict')
    	#s = t.lower()
	self.ui.plain.setText(s)

if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    myapp = StartQT4()
    myapp.show()
    sys.exit(app.exec_())

