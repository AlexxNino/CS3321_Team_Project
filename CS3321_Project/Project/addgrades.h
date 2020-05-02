#ifndef ADDGRADES_H
#define ADDGRADES_H
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QDialog>

namespace Ui {
class AddGrades;
}

class AddGrades : public QDialog
{
    Q_OBJECT

public:
    explicit AddGrades(QWidget *parent = nullptr);
    ~AddGrades();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddGrades *ui;
    QSqlDatabase myDB;
};

#endif // ADDGRADES_H
