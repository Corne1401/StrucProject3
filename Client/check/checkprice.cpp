#include "checkprice.h"
#include "ui_checkprice.h"

CheckPrice::CheckPrice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckPrice)
{
    ui->setupUi(this);
}

CheckPrice::~CheckPrice()
{
    delete ui;
}
