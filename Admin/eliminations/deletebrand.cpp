#include "deletebrand.h"
#include "ui_deletebrand.h"

DeleteBrand::DeleteBrand(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeleteBrand)
{
    ui->setupUi(this);
}

DeleteBrand::~DeleteBrand()
{
    delete ui;
}
