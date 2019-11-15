#include "check.h"
#include "ui_check.h"
#include "globalClient.h"
#include "menu.h"

#include <mainwindow.h>

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

void Check::on_checkButton_clicked()
{
    QString request;

    if(ui->selectCheck->currentIndex()==0){
        request = "20;"+ui->aisleCode->text()+";"+ui->prodCode->text()+";"+ui->brandCode->text();
        emit clientSock.send(request.toUtf8());
    }
    else if(ui->selectCheck->currentIndex() == 1){
        request = "21;"+ui->aisleCode->text()+";"+ui->prodCode->text()+";"+ui->brandCode->text();
        emit clientSock.send(request.toUtf8());
    }
    else if(ui->selectCheck->currentIndex() == 2){
        request = "22;"+ui->aisleCode->text()+";"+ui->prodCode->text()+";"+ui->brandCode->text();
        emit clientSock.send(request.toUtf8());
    }
}

void Check::on_backButton_clicked()
{
    if(isLogged){
        Menu *menu = new Menu;
        menu->show();
        this->close();
    } else {
        MainWindow *m = new MainWindow;
        m->show();
        this->close();
    }


}
