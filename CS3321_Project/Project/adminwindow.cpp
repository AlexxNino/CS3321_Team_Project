#include "adminwindow.h"
#include "addstudent.h"
#include "ui_adminwindow.h"

QString passUsername = NULL;
QString passPassword = NULL;

AdminWindow::AdminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::passLogin(QString username1, QString password1)
{
    username1 = passUsername;
    password1 = passPassword;
}

void AdminWindow::showFaculty()
{
    QSqlQueryModel *modal2 = new QSqlQueryModel();
    QSqlQuery qry2;


    qry2.prepare("select * from course_instructor");
    qry2.exec();
    modal2->setQuery(qry2);
    ui->tableView_2->setModel(modal2);
}

void AdminWindow::showClasses()
{
    QSqlQueryModel *modal3 = new QSqlQueryModel();
    QSqlQuery qry3;


    qry3.prepare("select * from courses");
    qry3.exec();
    modal3->setQuery(qry3);
    ui->tableView_3->setModel(modal3);
}

void AdminWindow::on_pushButton_loadAdminTable_clicked()
{

    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery qry;
    QString username1, password1;

    qry.prepare("select * from students ");
    qry.exec();
    modal->setQuery(qry);
    ui->tableView->setModel(modal);
    showFaculty();
    showClasses();

    qDebug()<<(modal->rowCount());



}

void AdminWindow::on_pushButton_DropCourse_clicked()
{

}

void AdminWindow::on_pushButton_AddStudent_clicked()
{
    addstudent = new AddStudent(this);
    addstudent -> show();
}

void removeStudent()
{

}

void AdminWindow::on_pushButton_DropStudent_clicked()
{
    QModelIndexList indexes = ui->tableView->selectionModel()->selectedRows();
    QSqlQueryModel *modal7 = new QSqlQueryModel();

    while (!indexes.isEmpty()) {
        modal7->removeRows(indexes.last().row(), 1);
        indexes.removeLast();
    }
}

void AdminWindow::on_pushButton_AddCourse_clicked()
{
    addclass = new AddClass(this);
    addclass -> show();
}

void AdminWindow::on_pushButton_AddFaculty_clicked()
{
    addfaculty = new AddFaculty(this);
    addfaculty -> show();
}
