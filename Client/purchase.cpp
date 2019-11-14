#include "purchase.h"
#include "ui_purchase.h"
#include "globalClient.h"
#include "popup.h"
#include <sstream>
#include <iostream>

purchase::purchase(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::purchase)
{
    ui->setupUi(this);
}

purchase::~purchase()
{
    delete ui;
}



void purchase::on_purchase_2_clicked()
{
    //pasillo
    //prod
    //marca
    //cantidad
    //id

    QString req = "35;"+ui->aisles->text()+";"+
            ui->products->text()+";"+
            ui->brands->text()+";"+
            ui->amount->text()+";"+
            clientId+";"+overWriteQueue;
    emit clientSock.send(req.toUtf8());

    overWriteQueue = "1";

    PopUp *popUp = new PopUp;
    popUp->show();

}
