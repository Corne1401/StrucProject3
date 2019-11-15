#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminSocket.h"
#include "globalAdmin.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, SIGNAL(send(QByteArray)),&adminSock,SLOT(send(QByteArray)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    QString id = "01;";
    id = id + ui->lineEdit->text();
    adminID = ui->lineEdit->text();
    emit send(id.toUtf8());

}
