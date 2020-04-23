#include "loginwindow.h"
#include "studentwindow.h"
#include "ui_studentwindow.h"
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

void StudentWindow::on_pushButton_LoadTable_clicked()
{


    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery qry;
    QString username1, password1;

    qry.prepare("select * from students where username ='"+Global_Username+"' and password = '"+Global_Password+ "'");
    qry.exec();
    modal->setQuery(qry);
    ui->tableView->setModel(modal);

    qDebug()<<(modal->rowCount());
    loadcourses();

}
