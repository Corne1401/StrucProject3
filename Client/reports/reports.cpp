#include "reports.h"
#include "ui_reports.h"
#include "menu.h"
#include "globalClient.h"
#include "reports/showprod.h"
#include "reports/showbrands.h"

Reports::Reports(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Reports)
{
    ui->setupUi(this);
}

Reports::~Reports()
{
    delete ui;
}

void Reports::on_aislesBtn_clicked()
{
    QString req = "03";
    emit clientSock.send(req.toUtf8());

}

void Reports::on_prodBtn_clicked()
{
    ShowProd *showProd = new ShowProd;
    showProd->show();
}

void Reports::on_brandsBtn_clicked()
{
    ShowBrands *showBrand = new ShowBrands;
    showBrand->show();
}

void Reports::on_backBtn_clicked()
{
    Menu *menu = new Menu;
    menu->show();
    this->close();
}
