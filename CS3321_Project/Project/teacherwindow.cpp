#include "teacherwindow.h"
#include "ui_teacherwindow.h"
#include <QMessageBox>
#include "loginwindow.h"
TeacherWindow::TeacherWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeacherWindow)
{
    ui->setupUi(this);
}
QString PassUsername = NULL;
QString PassPassword = NULL;

void TeacherWindow::PassLogin(QString UserName, QString PassWord)
{

    PassUsername = UserName;
    PassPassword = PassWord;
}
TeacherWindow::~TeacherWindow()
{
    delete ui;
}

void TeacherWindow::showInfo()
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery qry;


    qry.prepare("select * from course_instructor where username ='"+PassUsername+"' and password = '"+PassPassword+ "'");
    qry.exec();
    modal->setQuery(qry);
    ui->tableView->setModel(modal);

    qDebug()<<(modal->rowCount());
}

void TeacherWindow::showStudents()
{
    QSqlQueryModel *modal2 = new QSqlQueryModel();
    QSqlQuery qry2;


    qry2.prepare("select * from student_course_enrollment where course_id = (select course_id from courses where instructor_id = (select instructor_id from course_instructor where username = '"+PassUsername+"' and password = '"+PassPassword+"'))");
    qry2.exec();
    modal2->setQuery(qry2);
    ui->tableView_2->setModel(modal2);

    qDebug()<<(modal2->rowCount());
}

void TeacherWindow::showGrades()
{
    QSqlQueryModel *modal3 = new QSqlQueryModel();
    QSqlQuery qry3;


    qry3.prepare("select * from student_grade where registration_id = (select registration_id from student_course_enrollment where course_id = (select course_id from courses where instructor_id = (select instructor_id from course_instructor where username = '"+PassUsername+"' and password = '"+PassPassword+"')))");
    qry3.exec();
    modal3->setQuery(qry3);
    ui->tableView_3->setModel(modal3);

    qDebug()<<(modal3->rowCount());
}

void TeacherWindow::on_pushButton_clicked()
{
    showInfo();
    showStudents();
    showGrades();
}

void TeacherWindow::on_pushButton_AddGrades_clicked()
{
    addgrades = new AddGrades(this);
    addgrades -> show();
}
