#ifndef TEACHERWINDOW_H
#define TEACHERWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "addgrades.h"
namespace Ui {
class TeacherWindow;
}

class TeacherWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TeacherWindow(QWidget *parent = nullptr);
    ~TeacherWindow();
    void PassLogin(QString, QString);
    void showStudents();
    void showInfo();
    void showGrades();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_AddGrades_clicked();

private:
    Ui::TeacherWindow *ui;
    AddGrades *addgrades;
};

#endif // TEACHERWINDOW_H
