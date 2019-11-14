#include "menu.h"
#include "modifications.h"
#include "reports.h"
#include "check/check.h"
#include "restock/restock.h"
#include "insertions.h"
#include "eliminations.h"
#include "ui_menu.h"
#include "mapgraph.h"
#include "globalAdmin.h"

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


void Menu::on_menuBack_clicked()
{
    this->close();
}
void Menu::on_modifyButton_clicked()
{
    Modifications *modMenu = new Modifications;
    modMenu->show();
    this->close();
}
void Menu::on_reportButton_clicked()
{
    Reports *getReport = new Reports;
    getReport->show();
    this->close();
}
void Menu::on_checkButton_clicked()
{
    Check *checkMenu = new Check;
    checkMenu->show();
    this->close();
}

void Menu::on_billingButton_clicked()
{
    QString req = "23";
    emit adminSock.send(req.toUtf8());
    // emit code to generate files
}

void Menu::on_restockButton_clicked()
{
    ReStock *restockMenu = new ReStock;
    restockMenu->show();
    this->close();
}
void Menu::on_insertButton_clicked()
{
    insertions *insertMenu = new insertions;
    insertMenu->show();
    this->close();
}
void Menu::on_deleteButton_clicked()
{
    eliminations *elimMenu = new eliminations;
    elimMenu->show();
    this->close();
}

void Menu::on_chainReports_clicked()
{
    mapGraph *map = new mapGraph;
    map->show();
}

void Menu::on_checkInventory_clicked()
{
    QString req = "25";
    emit adminSock.send(req.toUtf8());
}
