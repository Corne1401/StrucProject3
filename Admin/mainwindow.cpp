#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminSocket.h"

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
    if(ui->lineEdit->text() == "1"){
        emit send(QString::fromStdString("01").toUtf8());
        this->thread()->sleep(1);

        Menu *menuWindow = new Menu;
        menuWindow->show();
    }
    else{
        QMessageBox idNotFound;
        idNotFound.setText("Id not Found");
        idNotFound.exec();
    }

}
