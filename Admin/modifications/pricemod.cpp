#include "pricemod.h"
#include "ui_modprice.h"

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
