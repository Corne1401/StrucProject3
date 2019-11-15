#include "check.h"
#include "ui_check.h"
#include "menu.h"
#include "globalAdmin.h"
#include <iostream>
using namespace std;

Check::Check(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Check)
{
    ui->setupUi(this);
}

Check::~Check()
{
    delete ui;
}

void Check::on_backButton_clicked()
{
    Menu *menu = new Menu;
    menu->show();
    this->close();
}

void Check::on_checkButton_clicked()
{
    QString request;

    if(ui->selectCheck->currentIndex()==0){
        request = "20;"+ui->aisleCode->text()+";"+ui->prodCode->text()+";"+ui->brandCode->text()+";"+adminID;
        emit adminSock.send(request.toUtf8());
    }
    else if(ui->selectCheck->currentIndex() == 1){
        request = "21;"+ui->aisleCode->text()+";"+ui->prodCode->text()+";"+ui->brandCode->text()+";"+adminID;
        emit adminSock.send(request.toUtf8());
    }
    else if(ui->selectCheck->currentIndex() == 2){
        request = "22;"+ui->aisleCode->text()+";"+ui->prodCode->text()+";"+ui->brandCode->text()+";"+adminID;
        emit adminSock.send(request.toUtf8());
    }

}
