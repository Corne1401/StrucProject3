#include "restock.h"
#include "ui_restock.h"
#include "menu.h"
#include "globalAdmin.h"

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

void ReStock::on_restockButton_clicked()
{
    QString req = "24;"+ui->restockAmount->text()+";"+adminID;
    emit adminSock.send(req.toUtf8());

    Menu *menu = new Menu;
    menu->show();
    this->close();
}
