#include "addstudent.h"
#include "ui_addstudent.h"
#include <QMessageBox>
AddStudent::AddStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStudent)
{

    ui->setupUi(this);
}

AddStudent::~AddStudent()
{
    delete ui;
}

void AddStudent::on_pushButton_Save_clicked()
{
    QString first_name, username, password, last_name, GPA, registration_date, student_id, last_login;

    student_id = ui->lineEdit_StudentID->text();
    registration_date = ui->lineEdit_2_RegistrationDate->text();
    username = ui->lineEdit_UserName->text();
    password = ui->lineEdit_Password->text();
    first_name = ui->lineEdit_FirstName->text();
    last_name = ui->lineEdit_LastName->text();
    GPA = ui->lineEdit_Gpa->text();
    last_login = ui->lineEdit_lastLogin->text();

    QSqlQuery qry;
    qry.prepare("INSERT INTO students values (:id, :reg, :username, :password, :first, :last, :login, :gpa)");
    qry.bindValue(":id", student_id);
    qry.bindValue(":reg", registration_date);
    qry.bindValue(":username", username);
    qry.bindValue(":password", password);
    qry.bindValue(":first", first_name);
    qry.bindValue(":last", last_name);
    qry.bindValue(":login", last_login);
    qry.bindValue(":gpa", GPA);


    if(qry.exec( ))
    {
        QMessageBox::information(this,tr("Save"), tr("Saved"));

    }
    else
    {
        QMessageBox::information(this,tr("Save"), tr("Failed"));
    }
}
