#include "reports.h"
#include "ui_reports.h"
#include "menu.h"

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

void Reports::on_reportsBack_clicked()
{
    Menu *menu = new Menu;
    menu->show();
    this->close();
}

