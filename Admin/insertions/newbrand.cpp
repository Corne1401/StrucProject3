#include "newbrand.h"
#include "ui_newbrand.h"

newBrand::newBrand(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newBrand)
{
    ui->setupUi(this);
}

newBrand::~newBrand()
{
    delete ui;
}
