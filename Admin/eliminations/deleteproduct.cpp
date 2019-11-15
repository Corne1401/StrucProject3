#include "deleteproduct.h"
#include "ui_deleteproduct.h"
#include "globalAdmin.h"

DeleteProduct::DeleteProduct(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeleteProduct)
{
    ui->setupUi(this);
}

DeleteProduct::~DeleteProduct()
{
    delete ui;
}

void DeleteProduct::on_pushButton_clicked()
{
    QString req = "17;"+ui->aisleCode->text()+
            ";"+ui->productCode->text()+";"+adminID;

    emit adminSock.send(req.toUtf8());
    this->close();
}
