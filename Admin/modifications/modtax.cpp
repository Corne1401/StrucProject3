#include "modtax.h"
#include "ui_modtax.h"

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
