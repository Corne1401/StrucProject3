#include "pricemod.h"
#include "ui_pricemod.h"

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
