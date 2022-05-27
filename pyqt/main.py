from PyQt6.QtWidgets import QApplication, QWidget, QMainWindow
import sys 
# This module provides access to some variables used or maintained by the interpreter and to functions that interact strongly with the interpreter. It is always available.
from PyQt6 import uic


class UI(QMainWindow):
    def __init__(self):
        super().__init__()
        # LOAD UI FILE
        self.ui = uic.loadUi('new.ui', self)
        self.ui.textEdit.textChanged.connect(self.changeText)

    def changeText(self, *args):
	    #print(args)
        self.ui.textBrowser.setText(self.ui.textEdit.toPlainText())

app = QApplication([])
window = UI()
window.show()
sys.exit(app.exec())
