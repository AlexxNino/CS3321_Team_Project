#ifndef ADDFACULTY_H
#define ADDFACULTY_H
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QDialog>

namespace Ui {
class AddFaculty;
}

class AddFaculty : public QDialog
{
    Q_OBJECT

public:
    explicit AddFaculty(QWidget *parent = nullptr);
    ~AddFaculty();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddFaculty *ui;
    QSqlDatabase myDB;
};

#endif // ADDFACULTY_H
