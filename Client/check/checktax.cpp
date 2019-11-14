#include "checktax.h"
#include "ui_checktax.h"

CheckTax::CheckTax(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckTax)
{
    ui->setupUi(this);
}

CheckTax::~CheckTax()
{
    delete ui;
}
