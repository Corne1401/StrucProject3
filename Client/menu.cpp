#include "menu.h"
#include "ui_menu.h"
#include "purchase.h"
#include "globalClient.h"

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_3_clicked()
{
    fromPurchase = true;
    emit clientSock.send("03");

}
