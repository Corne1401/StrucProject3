#include "newbrand.h"
#include "ui_newbrand.h"
#include "globalAdmin.h"

newBrand::newBrand(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newBrand)
{
    ui->setupUi(this);
}

newBrand::~newBrand()
{
    delete ui;
}

void newBrand::on_confirmNewBrand_clicked()
{
    QString req = "10;"+ui->aisleCode_2->text()+
            ";"+ui->productCode->text()+
            ";"+ui->newBrandCode->text()+
            ";"+ui->newBrandName->text()+";"+adminID;
    emit adminSock.send(req.toUtf8());
    this->close();
}
