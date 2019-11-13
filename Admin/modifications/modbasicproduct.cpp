#include "modbasicproduct.h"
#include "ui_modbasicproduct.h"

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
