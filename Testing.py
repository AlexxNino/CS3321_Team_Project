user='root'
password='++++++++++++++++++++++++++!'  #CHANGE THIS
host='ANMACAIR.local'
database='Test'



import sys
from PyQt5 import QtCore, QtWidgets
from PyQt5.QtWidgets import QMainWindow, QWidget, QLabel, QLineEdit
from PyQt5.QtWidgets import QPushButton
from PyQt5.QtCore import QSize    
import mysql.connector

mydb = mysql.connector.connect(
  host=host,
  user=user,
  passwd=password,
  database='sys'  #specify database 
)

#mycursor.execute("CREATE TABLE Courses (CRN INT(5))")
#mycursor.execute("CREATE TABLE Courses (CRN INT(5),Course_Name VARCHAR(45))")gl
#val=''


class MainWindow(QMainWindow):
    def __init__(self):
        QMainWindow.__init__(self)

        self.setMinimumSize(QSize(320, 140))    
        self.setWindowTitle("Testing Py connector and buttons") 

        self.nameLabel = QLabel(self)
        self.nameLabel.setText('CRN:')
        self.line = QLineEdit(self)

        self.line.move(80, 20)
        self.line.resize(200, 32)
        self.nameLabel.move(20, 20)

        pybutton = QPushButton('Add Course', self)
        pybutton.clicked.connect(self.clickMethod)
        pybutton.resize(200,32)
        pybutton.move(80, 60)        

    def clickMethod(self):
        print('Test line edit input = ' + self.line.text())
        #global val
        val = (self.line.text())
        mycursor = mydb.cursor()
        sql = "INSERT INTO Courses (CRN) VALUES ('%s')"
        mycursor.execute(sql, val)
        #Something is wrong here


mydb.commit()

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    mainWin = MainWindow()
    mainWin.show()
    sys.exit( app.exec_() )
