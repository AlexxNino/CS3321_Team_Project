#include "loginwindow.h"
#include "studentwindow.h"
#include "ui_studentwindow.h"
#include <QMessageBox>
QString Global_Username = NULL;
QString Global_Password = NULL;

StudentWindow::StudentWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentWindow)
{
    ui->setupUi(this);

}

StudentWindow::~StudentWindow()
{
    delete ui;
}

void StudentWindow::createGlobal(QString username1, QString password1)
{
   //pull username and password from login window.cpp and store it as a new variable that would be used down bellow


    Global_Username = username1;
    Global_Password = password1;


}

void StudentWindow::loadcourses()
{

    QSqlQueryModel *modal2 = new QSqlQueryModel();
    QSqlQuery qry2;
    qry2.prepare("select * from courses where course_id = (select course_id from student_course_enrollment where student_id = (select student_id from students where username = '"+Global_Username+"' and password = '"+Global_Password+"'))");
    qry2.exec();
    modal2->setQuery(qry2);
    ui->tableView_2->setModel(modal2);

    qDebug()<<(modal2->rowCount());

}

void StudentWindow::loadAllClasses()
{
    QSqlQueryModel *modal4 = new QSqlQueryModel();
    QSqlQuery qry4;
    qry4.prepare("select * from courses where course_id != (select course_id from student_course_enrollment where student_id = (select student_id from students where username = '"+Global_Username+"' and password = '"+Global_Password+"'))");
    qry4.exec();
    modal4->setQuery(qry4);
    ui->tableView_3->setModel(modal4);

    qDebug()<<(modal4->rowCount());
}

void StudentWindow::loadStudent()
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery qry;


    qry.prepare("select * from students where username ='"+Global_Username+"' and password = '"+Global_Password+ "'");
    qry.exec();
    modal->setQuery(qry);
    ui->tableView->setModel(modal);

    qDebug()<<(modal->rowCount());
}

void StudentWindow::on_pushButton_LoadTable_clicked()
{

    loadStudent();
    loadcourses();
    loadAllClasses();
    loadGrades();
}

void StudentWindow::addClass(QString)
{

}

void StudentWindow::loadGrades()
{
    QSqlQuery qry6;
    QSqlQueryModel *modal6 = new QSqlQueryModel();
    qry6.prepare("select * from student_grade where registration_id = (select registration_id from student_course_enrollment where student_id = (select student_id from students where username = '"+Global_Username+"' and password = '"+Global_Password+"'))");
    qry6.exec();
    modal6->setQuery(qry6);
    ui->tableView_4->setModel(modal6);

    qDebug()<<(modal6->rowCount());

}

void StudentWindow::on_pushButton_Add_clicked()
{

    QString course_ID = ui->lineEdit_Add->text();
    QSqlQuery qry5;
    qry5.prepare("select course_id from courses where course_id = (select course_id from student_course_enrollment where course_id = '"+course_ID+"' ))");
    {
         int count = 0;
         while(qry5.next())
         {
             count++;
         }
         if(count==1)
         {
             QMessageBox::information(this, "Class", "Enrolled please refresh");


         }
    if(count > 1)
         {
            QMessageBox::information(this, "Class", "already enrolled");

         }
    if(count < 1)
        {
            QMessageBox::information(this, "Class", "doesnt exist");

        }


   }
}


