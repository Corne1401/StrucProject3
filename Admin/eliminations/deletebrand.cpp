#include "deletebrand.h"
#include "ui_deletebrand.h"
#include "globalAdmin.h"

DeleteBrand::DeleteBrand(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeleteBrand)
{
    ui->setupUi(this);
}

DeleteBrand::~DeleteBrand()
{
    delete ui;
}

void DeleteBrand::on_deleteBrand_clicked()
{
    QString req = "18;"+ui->aisleCode->text()+
            ";"+ui->productCode->text()+
            ";"+ui->brandCode->text();

    emit adminSock.send(req.toUtf8());
    this->close();
}
