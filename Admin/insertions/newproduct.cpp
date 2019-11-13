#include "newproduct.h"
#include "ui_newproduct.h"

newProduct::newProduct(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newProduct)
{
    ui->setupUi(this);
}

newProduct::~newProduct()
{
    delete ui;
}
