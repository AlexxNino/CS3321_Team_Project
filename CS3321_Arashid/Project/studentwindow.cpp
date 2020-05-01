#include "loginwindow.h"
#include "studentwindow.h"
#include "ui_studentwindow.h"
#include <QMessageBox>
#include <QSqlError>
#include <QWidget>
//#include <QMouseEvent>

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
    //this was wrong..FIXED?
    //qry2.prepare("select * from courses where course_id = (select course_id from student_course_enrollment where student_id = (select student_id from students where username = '"+Global_Username+"' and password = '"+Global_Password+"'))");
    qry2.prepare("select * from student_course_enrollment where student_id = (select student_id from students where username = '"+Global_Username+"' and password = '"+Global_Password+"')");
    qry2.exec();
    modal2->setQuery(qry2);
    ui->tableView_2->setModel(modal2);

    //qDebug()<<(modal2->rowCount());

}

void StudentWindow::loadAllClasses()
{

    QSqlQueryModel *modal4 = new QSqlQueryModel();
    QSqlQuery qry4;

    //query was wrong and not showing anything when no classes enrolled(FIXED)
    qry4.prepare("select * from courses WHERE course_id in (SELECT course_id FROM courses EXCEPT SELECT course_id FROM student_course_enrollment WHERE student_id = (select student_id from students where username = '"+Global_Username+"' and password = '"+Global_Password+"'))");
    qry4.exec();

    modal4->setQuery(qry4);
    ui->tableView_3->setModel(modal4);
    qDebug()<< qry4.lastError();
    qDebug()<<(modal4->rowCount());
}

void StudentWindow::loadStudent() //display student info
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery qry;


    qry.prepare("select * from students where username ='"+Global_Username+"' and password = '"+Global_Password+ "'");
    qry.exec();
    modal->setQuery(qry);
    ui->tableView->setModel(modal);

    //qDebug()<<(modal->rowCount());
}

void StudentWindow::on_pushButton_LoadTable_clicked()
{
    get_semester_gpa();

    loadStudent();
    loadcourses();
    loadAllClasses();
    loadGrades();


}

void StudentWindow::addClass(QString)
{
    //Dont need this anymore
}

void StudentWindow::loadGrades()//displays all grades from user
{

    QSqlQuery qry6;
    QSqlQueryModel *modal6 = new QSqlQueryModel();
    qry6.prepare("select * from student_grade where registration_id = (select registration_id from student_course_enrollment where student_id = (select student_id from students where username = '"+Global_Username+"' and password = '"+Global_Password+"'))");
    qry6.exec();
    modal6->setQuery(qry6);
    ui->tableView_4->setModel(modal6);


}







void StudentWindow::on_pushButton_Add_clicked()
{

    QString course_ID = ui->lineEdit_Add->text();
    //qDebug()<<course_ID;
    QSqlQuery qry5,qryAddClass;
    QSqlQueryModel *modal8 = new QSqlQueryModel();
    //qry5.prepare("select course_id from courses where course_id = (select course_id from student_course_enrollment where course_id = '"+course_ID+"' ))");
    qry5.exec("select course_id from student_course_enrollment where course_id = '"+course_ID+"' AND student_id = ((SELECT student_id from students where (username = '"+Global_Username+"' AND password = '"+Global_Password+"')))");

    modal8->setQuery(qry5);
    //qDebug()<<(modal8->rowCount());


    if(modal8->rowCount() == 0)
         {

            qryAddClass.exec("INSERT INTO student_course_enrollment(student_id,course_id,date_of_enrollment,date_of_completion) VALUES ((SELECT student_id from students where (username = '"+Global_Username+"' AND password = '"+Global_Password+"')),'"+course_ID+"','01/13/2020','05/07/2020');");
            QMessageBox::information(this, "Class", "Class enrolled!");
             //This will update the tables after new inputs
             loadcourses();
             loadAllClasses();

         }
    if(modal8->rowCount() >= 1)
         {
            QMessageBox::information(this, "Class", "already enrolled");

         }






}
void StudentWindow::on_pushButton_Drop_clicked(){
    QSqlQuery qry_drop;
    QString course_ID_drop = ui->lineEdit_Drop->text();

    //This deletes the course
    qry_drop.exec("DELETE from student_course_enrollment where course_id = '"+course_ID_drop+"' and student_id = (SELECT student_id from students where username = '"+Global_Username+"' AND password = '"+Global_Password+"') ");
    //This deletes the grades associated with the course above
    qry_drop.exec("DELETE FROM student_grade where registration_id = (select registration_id from student_enrollment where course_id = '"+course_ID_drop+"' )");

    //update tables
    loadcourses();
    loadAllClasses();


}

    //GPA ONLY GETS TOTAL/OVERALL GPA RIGHT NOW, ALSO ITS A LITTLE OFF BECUASE TEST RESULTS ARE INTEGER TYPE.
void StudentWindow::get_semester_gpa(){

    QSqlQuery qry_gpa;
    QSqlQuery qry_Check;
    QSqlQueryModel *modal9 = new QSqlQueryModel();

    qry_Check.exec("select test_results from student_grade where registration_id = (select registration_id from student_course_enrollment where student_id = (SELECT student_id from students where (username = '"+Global_Username+"' AND password = '"+Global_Password+"') ))");
    modal9->setQuery(qry_Check);


    //Checks if any grades are input, if none then gpa = 0
    if(modal9->rowCount() == 0){

        qry_gpa.exec("update students set gpa = 0 where student_id = (SELECT student_id from students where username = '"+Global_Username+"' AND password = '"+Global_Password+"')");

    }
    //else calc gpa
    else
    {
        qry_gpa.exec("update students set gpa = (SELECT (avg(test_results)/100) *4 from student_grade) where student_id = (SELECT student_id from students where (username = '"+Global_Username+"' AND password = '"+Global_Password+"') )");

    }

    qDebug()<<(modal9->rowCount());



    //This only returns the overall GPA, need to input more grades from past semesters to get "current semester GPA" like requested.

    //This one will be for semester gpa
    //qry_gpa.exec("update students set gpa = (SELECT (avg(test_results)/100) *4 from student_grade) where student_id = (SELECT student_id from students where (username = '"+Global_Username+"' AND password = '"+Global_Password+"')) AND student_id = () ");

    // check if its working
    //qDebug()<< qry_gpa.lastError();
}

