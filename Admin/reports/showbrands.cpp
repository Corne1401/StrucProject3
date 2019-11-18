#include "showbrands.h"
#include "ui_showbrands.h"

ShowBrands::ShowBrands(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowBrands)
{
    ui->setupUi(this);
}

ShowBrands::~ShowBrands()
{
    delete ui;
}
