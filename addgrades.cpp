#include "addgrades.h"
#include "ui_addgrades.h"
#include <QMessageBox>

AddGrades::AddGrades(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGrades)
{
    ui->setupUi(this);
}

AddGrades::~AddGrades()
{
    delete ui;
}

void AddGrades::on_pushButton_clicked()
{
    QString RegistraionID, ExamName, TestResults, Date, Comments;

    RegistraionID = ui->lineEdit_RegistraionID->text();
    ExamName = ui->lineEdit_ExamName->text();
    TestResults = ui->lineEdit_TestResults->text();
    Date  = ui->lineEdit_Date->text();
    Comments = ui->lineEdit_Comments->text();


    QSqlQuery qry;
    qry.prepare("INSERT INTO student_grade values (:RegistraionID, :ExamName, :TestResults, :Date, :Comments)");
    qry.bindValue(":RegistraionID", RegistraionID);
    qry.bindValue(":ExamName", ExamName);
    qry.bindValue(":TestResults", TestResults);
    qry.bindValue(":Date", Date);
    qry.bindValue(":Comments", Comments);


    if(qry.exec( ))
    {
        QMessageBox::information(this,tr("Save"), tr("Saved"));

    }
    else
    {
        QMessageBox::information(this,tr("Save"), tr("Failed"));
    }
}
