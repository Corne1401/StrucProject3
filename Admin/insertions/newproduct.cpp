#include "newproduct.h"
#include "ui_newproduct.h"
#include "globalAdmin.h"

newProduct::newProduct(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newProduct)
{
    ui->setupUi(this);
}

newProduct::~newProduct()
{
    delete ui;
}

void newProduct::on_newProductConfirm_clicked()
{
    QString req = "09;"+ui->aisleCode->text()+
            ";"+ui->newProdCode->text()+
            ";"+ui->newName->text();

    emit adminSock.send(req.toUtf8());
    this->close();
}
