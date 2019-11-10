#include "menu.h"
#include "ui_menu.h"

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

void Menu::on_Reports_2_clicked()
{
    this->close();
}

void Menu::on_Reports_clicked()
{
   Reports *reportWindow = new Reports;
   reportWindow->show();
}
