#include "modbasicproduct.h"
#include "ui_modbasicproduct.h"
#include "globalAdmin.h"

modBasicProduct::modBasicProduct(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::modBasicProduct)
{
    ui->setupUi(this);
}

modBasicProduct::~modBasicProduct()
{
    delete ui;
}

void modBasicProduct::on_pushButton_clicked()
{
    QString req;

    if(ui->checkBox->isChecked()){
        req = "15;"+ui->aisleCode->text()+
                ";"+ui->prodCode->text()+
                ";"+ui->brandCode->text()+";1";
        emit adminSock.send(req.toUtf8());

    } else {
        req = "15;"+ui->aisleCode->text()+
                ";"+ui->prodCode->text()+
                ";"+ui->brandCode->text()+";0";
        emit adminSock.send(req.toUtf8());
    }

    this->close();

}
