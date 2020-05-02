#ifndef ADDCLASS_H
#define ADDCLASS_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class AddClass;
}

class AddClass : public QDialog
{
    Q_OBJECT

public:
    explicit AddClass(QWidget *parent = nullptr);
    ~AddClass();

private slots:
    void on_pushButtonSave_clicked();

private:
    Ui::AddClass *ui;
    QSqlDatabase myDB;
};

#endif // ADDCLASS_H
