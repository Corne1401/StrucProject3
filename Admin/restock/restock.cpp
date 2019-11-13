#include "restock.h"
#include "ui_restock.h"
#include "menu.h"

ReStock::ReStock(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReStock)
{
    ui->setupUi(this);
}

ReStock::~ReStock()
{
    delete ui;
}

void ReStock::on_backButton_clicked()
{
    Menu *menu = new Menu;
    menu->show();
    this->close();
}
