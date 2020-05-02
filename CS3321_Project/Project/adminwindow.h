#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H
#include "addstudent.h"
#include "addclass.h"
#include "addfaculty.h"
#include <QDialog>

#include <QtSql>
#include <QDebug>
#include <QFileInfo>
namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();
    void passLogin(QString, QString);
    void showFaculty();
    void showClasses();
    void removeStudent();
private slots:
    void on_pushButton_loadAdminTable_clicked();

    void on_pushButton_DropCourse_clicked();

    void on_pushButton_AddStudent_clicked();

    void on_pushButton_DropStudent_clicked();


    void on_pushButton_AddCourse_clicked();

    void on_pushButton_AddFaculty_clicked();

private:
    Ui::AdminWindow *ui;
    QSqlDatabase myDB;
    AdminWindow *addminWindow;
    AddStudent *addstudent;
    AddClass *addclass;
    AddFaculty *addfaculty;
};

#endif // ADMINWINDOW_H
