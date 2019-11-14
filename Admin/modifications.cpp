#include "modifications.h"
#include "ui_modifications.h"
#include "menu.h"
#include "modifications/pricemod.h"
#include "modifications/modtax.h"
#include "modifications/modbasicproduct.h"

Modifications::Modifications(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Modifications)
{
    ui->setupUi(this);
}

Modifications::~Modifications()
{
    delete ui;
}

void Modifications::on_backButton_clicked()
{
    Menu *menu = new Menu;
    menu->show();
    this->close();
}



void Modifications::on_modPrice_clicked()
{
    priceMod *modifyPrice = new priceMod;
    modifyPrice->show();

}



void Modifications::on_modtax_clicked()
{
    ModTax *tax = new ModTax;
    tax->show();

}

void Modifications::on_modProd_clicked()
{
    modBasicProduct *modProd = new modBasicProduct;
    modProd->show();

}
