#include "checkprod.h"
#include "ui_checkprod.h"

CheckProd::CheckProd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckProd)
{
    ui->setupUi(this);
}

CheckProd::~CheckProd()
{
    delete ui;
}
