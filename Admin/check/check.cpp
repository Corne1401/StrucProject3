#include "check.h"
#include "ui_check.h"
#include "menu.h"

Check::Check(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Check)
{
    ui->setupUi(this);
}

Check::~Check()
{
    delete ui;
}

void Check::on_backButton_clicked()
{
    Menu *menu = new Menu;
    menu->show();
    this->close();
