#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include "adminwindow.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_pushButton_Login_clicked();

private:
    Ui::LoginWindow *ui;
    AdminWindow *adminwindow;
};
#endif // LOGINWINDOW_H
