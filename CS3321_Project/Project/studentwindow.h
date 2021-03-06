#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class StudentWindow;
}

class StudentWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StudentWindow(QWidget *parent = nullptr);
    ~StudentWindow();
    void get_semester_gpa();
    void createGlobal(QString, QString);
    void loadcourses();
    void loadAllClasses();
    void addClass(QString);
    void dropClass(QString);
    void loadStudent();
    void loadGrades();


private slots:
    void on_pushButton_LoadTable_clicked();
    void on_pushButton_Add_clicked();   //add course
    void on_pushButton_Drop_clicked();  //drop course

private:
    Ui::StudentWindow *ui;
    QSqlDatabase myDB;

};

#endif // STUDENTWINDOW_H
