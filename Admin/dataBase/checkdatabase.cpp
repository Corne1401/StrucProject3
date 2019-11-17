#include "checkdatabase.h"
#include "ui_checkdatabase.h"
#include "menu.h"
#include "globalAdmin.h"
#include "dataBase/checkprod.h"
#include "dataBase/checkbrand.h"

checkDataBase::checkDataBase(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::checkDataBase)
{
    ui->setupUi(this);
}

checkDataBase::~checkDataBase()
{
    delete ui;
}


void checkDataBase::on_checkAisles_clicked()
{
    QString req = "03;"+adminID;
    emit adminSock.send(req.toUtf8());
}

void checkDataBase::on_checkBrands_clicked()
{
    CheckBrand *brand = new CheckBrand;
    brand->show();


}

void checkDataBase::on_checkProd_clicked()
{
    CheckProd *prod = new CheckProd;
    prod->show();
}

void checkDataBase::on_backBtn_clicked()
{
    Menu *menu = new Menu;
    menu->show();
    this->close();
}
