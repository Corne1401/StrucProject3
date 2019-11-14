#include "eliminations.h"
#include "ui_eliminations.h"
#include "menu.h"
#include "eliminations/deleteaisle.h"
#include "eliminations/deleteproduct.h"
#include "eliminations/deletebrand.h"
#include "eliminations/deleteclient.h"

eliminations::eliminations(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eliminations)
{
    ui->setupUi(this);
}

eliminations::~eliminations()
{
    delete ui;
}

void eliminations::on_deleteBack_clicked()
{
    Menu *menu = new Menu;
    menu->show();
    this->close();
}

void eliminations::on_deleteAisleButton_clicked()
{
    deleteAisle *delAisle = new deleteAisle;
    delAisle->show();
}

void eliminations::on_deleteProductButton_clicked()
{
    DeleteProduct *delProd = new DeleteProduct;
    delProd->show();
}

void eliminations::on_deleteBrandButton_clicked()
{
    DeleteBrand *delBrand = new DeleteBrand;
    delBrand->show();
}

void eliminations::on_deleteClientButton_clicked()
{
    DeleteClient *delClient = new DeleteClient;
    delClient->show();
}
