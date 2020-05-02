#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

#include <QDialog>

namespace Ui {
class AddStudent;
}

class AddStudent : public QDialog
{
    Q_OBJECT

public:
    explicit AddStudent(QWidget *parent = nullptr);
    ~AddStudent();

private slots:
    void on_pushButton_Save_clicked();

private:
    Ui::AddStudent *ui;
    QSqlDatabase myDB;

};

#endif // ADDSTUDENT_H
