#include "menu.h"
#include "ui_menu.h"
#include "purchase.h"
#include "globalClient.h"
#include "check/check.h"
#include "reports/reports.h"
#include "graphresults.h"

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
    this->close();
    fromPurchase = true;
    emit clientSock.send("03");
}

void Menu::on_checkBtn_clicked()
{
    Check *check = new Check;
    check->show();
    this->close();
}

void Menu::on_pushButton_clicked()
{
    Reports *rep = new Reports;
    rep->show();
    this->close();
}

void Menu::on_pushButton_2_clicked()
{
    QString req = "50;"+clientId;
    this->close();
    emit clientSock.send(req.toUtf8());
}
