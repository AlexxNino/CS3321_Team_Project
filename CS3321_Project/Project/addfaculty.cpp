#include "addfaculty.h"
#include "ui_addfaculty.h"
#include <QMessageBox>
AddFaculty::AddFaculty(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFaculty)
{
    ui->setupUi(this);
}

AddFaculty::~AddFaculty()
{
    delete ui;
}

void AddFaculty::on_pushButton_clicked()
{
    QString InstructorID, Username, Password, FirstName, LastName, Gender, Department;

    InstructorID = ui->lineEdit_InstructorID->text();
    Username = ui->lineEdit_Username->text();
    Password = ui->lineEdit_Password->text();
    FirstName  = ui->lineEdit_FirstName->text();
    LastName = ui->lineEdit_LastName->text();
    Gender  = ui->lineEdit_Gender->text();
    Department = ui->lineEdit_Department->text();

    QSqlQuery qry;
    qry.prepare("INSERT INTO course_instructor values (:InstructorID, :Username, :Password, :FirstName, :LastName, :Gender, :Department)");
    qry.bindValue(":InstructorID", InstructorID);
    qry.bindValue(":Username", Username);
    qry.bindValue(":Password", Password);
    qry.bindValue(":FirstName", FirstName);
    qry.bindValue(":LastName", LastName);
    qry.bindValue(":Gender", Gender);
    qry.bindValue(":Department", Department);


    if(qry.exec( ))
    {
        QMessageBox::information(this,tr("Save"), tr("Saved"));

    }
    else
    {
        QMessageBox::information(this,tr("Save"), tr("Failed"));
    }
}
