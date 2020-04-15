#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "adminwindow.h"
#include <QMessageBox>
LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();

    if(username == "admin" && password == "password")
    {
        QMessageBox::information(this, "Login", "Password correct");
        hide();
        adminwindow = new AdminWindow(this);
        adminwindow->show();

    }
    else
    {
        QMessageBox::warning(this, "Login", "Password incorrect");
    }
}
