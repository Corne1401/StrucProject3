#include "deleteproduct.h"
#include "ui_deleteproduct.h"

DeleteProduct::DeleteProduct(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeleteProduct)
{
    ui->setupUi(this);
}

DeleteProduct::~DeleteProduct()
{
    delete ui;
}
