import sys
from PyQt4 import QtCore,QtGui
from editor import Ui_MainWindow

class StartQT4(QtGui.QMainWindow):
    def __init__(self, parent=None):
        QtGui.QWidget.__init__(self, parent)
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        
        #Here we define the slots and signals
	QtCore.QObject.connect(self.ui.pushButton,QtCore.SIGNAL("clicked()"), self.text_add)
	QtCore.QObject.connect(self.ui.pushButton_2,QtCore.SIGNAL("clicked()"), self.text_clear)
    
    def text_add(self):
	self.ui.textEdit.setText('aaaaaaaaaa')
	
    def text_clear(self):
    	self.ui.textEdit.setText('OK')


if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    myapp = StartQT4()
    myapp.show()
    sys.exit(app.exec_())

