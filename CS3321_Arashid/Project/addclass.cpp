#include "addclass.h"
#include "ui_addclass.h"
#include <QMessageBox>

AddClass::AddClass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClass)
{
    ui->setupUi(this);
}

AddClass::~AddClass()
{
    delete ui;
}

void AddClass::on_pushButtonSave_clicked()
{
    QString courseID, instructorID, subjectID, CourseName, CourseDescription, Term, Time, Duration;

    courseID = ui->lineEdit_CourseID->text();
    instructorID = ui->lineEdit_Instructor->text();
    subjectID = ui->lineEdit_SubjectID->text();
    CourseName  = ui->lineEdit_CourseName->text();
    CourseDescription = ui->lineEdit_Term->text();
    Term = ui->lineEdit_Term->text();
    Time = ui->lineEdit_Time->text();
    Duration = ui->lineEdit_Duration->text();

    QSqlQuery qry;
    qry.prepare("INSERT INTO courses values (:CourseID, :InstructorID, :SubjectID, :CourseName, :CourseDescription, :Term, :Time, :Duration)");
    qry.bindValue(":CourseID", courseID);
    qry.bindValue(":InstructorID", instructorID);
    qry.bindValue(":SubjectID", subjectID);
    qry.bindValue(":CourseName", CourseName);
    qry.bindValue(":CourseDescription", CourseDescription);
    qry.bindValue(":Term", Term);
    qry.bindValue(":Time", Time);
    qry.bindValue(":Duration", Duration);


    if(qry.exec( ))
    {
        QMessageBox::information(this,tr("Save"), tr("Saved"));

    }
    else
    {
        QMessageBox::information(this,tr("Save"), tr("Failed"));
    }
}
