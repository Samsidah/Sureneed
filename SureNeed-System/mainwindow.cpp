#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnLogin_clicked()
{
    QString admin = ui->txtAdmin->text();
    QString username = ui->txtUsername->text();
    QString password = ui->txtPassword->text();

    if (admin=="admin1" && username=="sureneedbms@gmail.com" && password=="bmsadmin1")
    {
        home = new Home (this);
        home -> show();
    }
    else {
        QMessageBox::warning(this, "Login", "Incorrect inputs, please try again.");
    }
}

