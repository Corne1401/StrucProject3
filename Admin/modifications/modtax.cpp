#include "modtax.h"
#include "ui_modtax.h"
#include "globalAdmin.h"

ModTax::ModTax(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ModTax)
{
    ui->setupUi(this);
}

ModTax::~ModTax()
{
    delete ui;
}

void ModTax::on_confirmNewTax_clicked()
{
    QString req;

    if(ui->isBasic->isChecked()){
        req = "13;"+ui->newTax->text();
        emit adminSock.send(req.toUtf8());
    } else if(ui->isNormal->isChecked()){
        req = "14;"+ui->newTax->text();
        emit adminSock.send(req.toUtf8());
    }

    this->close();


}
