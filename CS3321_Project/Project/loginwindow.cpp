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
    myDB.setDatabaseName("C:\\Users\\Alex Nino\\Desktop\\CS3321_Team_Project\\lmsDB.db");

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





    // student window login
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
         if(count<1)
         {
           //  QMessageBox::information(this, "Login", "Password wrong");
         }
         if(count>1)
         {
            QMessageBox::information(this, "Login", "dupplicate");

         }

    }


    //admin window login
    QSqlQuery qry2;
    if(qry2.exec("select * from admin where username ='"+username+"' and password = '"+password+ "'"))
    {
        int count2 = 0;
        while(qry2.next())
        {
            count2++;
        }
        if(count2==1)
        {
            QMessageBox::information(this, "Login", "Password correct");
            hide();
            adminwindow = new AdminWindow(this);
            adminwindow->passLogin(username, password);
            adminwindow->show();

        }



    }
    //teacher window login
    QSqlQuery qry3;
    if(qry3.exec("select * from course_instructor where username ='"+username+"' and password = '"+password+ "'"))
    {
        int count3 = 0;
        while(qry3.next())
        {
            count3++;
        }
        if(count3==1)
        {
            QMessageBox::information(this, "Login", "Password correct");
            hide();
            teacherwindow = new TeacherWindow(this);
            teacherwindow->PassLogin(username, password);
            teacherwindow->show();

        }



    }

}
