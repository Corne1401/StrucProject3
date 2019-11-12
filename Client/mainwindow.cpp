#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clientSocket.h"
#include "globalClient.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, SIGNAL(send(QByteArray)),&clientSock,SLOT(send(QByteArray)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString id = "02;" + ui->editId->text();
    emit send(id.toUtf8());

}
