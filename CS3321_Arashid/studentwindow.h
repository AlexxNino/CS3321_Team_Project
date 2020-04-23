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
    void createGlobal(QString, QString);
    void loadcourses();
private slots:
    void on_pushButton_LoadTable_clicked();

private:
    Ui::StudentWindow *ui;
    QSqlDatabase myDB;

};

#endif // STUDENTWINDOW_H
