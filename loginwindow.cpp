#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "adminwindow.h"
#include "studentwindow.h"
#include <QMessageBox>
LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    myDB=QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName("C:/Users/Adnan/Desktop/lmsDB.db");

    if(!myDB.open())
        ui->label_Status->setText("Failed to open DB");
    else
        ui->label_Status->setText("DB open...");

}

LoginWindow::~LoginWindow()
{
    delete ui;
}





void LoginWindow::on_pushButton_Login_clicked()
{


    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();


    if(username == "admin" && password == "password")
    {
        QMessageBox::information(this, "Login", "Password correct");
        hide();
        adminwindow = new AdminWindow(this);
        adminwindow->show();

    }
    QSqlQuery qry;
    if(qry.exec("select * from students where username ='"+username+"' and password = '"+password+ "'"))
    {
         int count = 0;
         while(qry.next())
         {
             count++;
         }
         if(count==1)
         {
             QMessageBox::information(this, "Login", "Password correct");
             hide();
             studentwindow = new StudentWindow(this);
             //call function to take the entered username and password so it can be used for studentwindow
             studentwindow->createGlobal(username, password);
             studentwindow->show();
         }





// ISSUE WITH ADMIN LOGIN
//         if(count<1)
//         {
//             QMessageBox::information(this, "Login", "Password wrong");
//
//         }
//         if(count>1)
//         {
//             QMessageBox::information(this, "Login", "dupplicate");
//
//         }
//
//    }
//    else
//    {
//        QMessageBox::warning(this, "Login", "Password incorrect");
    }
}
