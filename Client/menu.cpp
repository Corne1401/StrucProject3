#include "menu.h"
#include "ui_menu.h"
#include "check/check.h"
#include "reports/reports.h"

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
