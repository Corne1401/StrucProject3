#include "checkbrand.h"
#include "ui_checkbrand.h"
#include "globalAdmin.h"

CheckBrand::CheckBrand(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckBrand)
{
    ui->setupUi(this);
}

CheckBrand::~CheckBrand()
{
    delete ui;
}

void CheckBrand::on_pushButton_clicked()
{
    QString req = "05;"+ui->aisleCode->text()+
            ";"+ui->prodCode->text()+
            ";"+adminID;

    emit adminSock.send(req.toUtf8());
}


