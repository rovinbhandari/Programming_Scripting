#!/usr/bin/python

import sys
import string
from PyQt4 import QtCore,QtGui
from login_ui import Ui_MainWindow

class StartQT4(QtGui.QMainWindow):
    def __init__(self, parent=None):
        QtGui.QWidget.__init__(self, parent)
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        
        # slots and signals
	QtCore.QObject.connect(self.ui.ok, QtCore.SIGNAL("clicked()"), self.login)
	QtCore.QObject.connect(self.ui.clear, QtCore.SIGNAL("clicked()"), self.clear_fields)
    
    def login(self):
	quid = self.ui.username.text()
	uid = str(quid)
	qpwd = self.ui.password.text()
	pwd = str(qpwd)
	u = False
	p = False
	f1 = open("uids")
	f2 = open("pwds")
	uids = f1.read().split(None)
	pwds = f2.read().split(None)
	#print uids
	#print pwds
	for user in uids:
		if uid == user:
			u = True
	for passwd in pwds:
		if passwd == pwd:
			p = True
	if u == True and p == True:
		self.ui.message.setPlainText('success')
	else:
		self.ui.message.setPlainText('epic fail')
	f1.close()
	f2.close()
		
    def clear_fields(self):
    	self.ui.username.setText('')
    	self.ui.password.setText('')
	self.ui.message.setPlainText('')

if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    myapp = StartQT4()
    myapp.show()
    sys.exit(app.exec_())

