#include "pricemod.h"
#include "ui_modprice.h"
#include "globalAdmin.h"

priceMod::priceMod(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::priceMod)
{
    ui->setupUi(this);
}

priceMod::~priceMod()
{
    delete ui;
}

void priceMod::on_modPriceConfirm_clicked()
{
    QString req = "12;"+ui->aisleCode->text()+
            ";"+ui->prodCode->text()+
            ";"+ui->brandCode->text()+
            ";"+ui->newPrice->text()+";"+adminID;

    emit adminSock.send(req.toUtf8());
    this->close();
}
