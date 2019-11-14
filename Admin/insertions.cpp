#include "insertions.h"
#include "ui_insertions.h"
#include "menu.h"
#include "insertions/newbrand.h"
#include "insertions/newaisle.h"
#include "insertions/newproduct.h"
#include "insertions/newclient.h"

insertions::insertions(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::insertions)
{
    ui->setupUi(this);
}

insertions::~insertions()
{
    delete ui;
}

void insertions::on_insertBack_clicked()
{
    Menu *menu = new Menu;
    menu->show();
    this->close();
}

void insertions::on_insertBrand_clicked()
{
    newBrand *brand = new newBrand;
    brand->show();
}

void insertions::on_insertAisle_clicked()
{
    newAisle *aisle = new newAisle;
    aisle->show();
}

void insertions::on_insertProduct_clicked()
{
    newProduct *prod = new newProduct;
    prod->show();
}

void insertions::on_insertClient_clicked()
{
    newClient *client = new newClient;
    client->show();
}
