#include "modifications.h"
#include "ui_modifications.h"
#include "menu.h"

Modifications::Modifications(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Modifications)
{
    ui->setupUi(this);
}

Modifications::~Modifications()
{
    delete ui;
}

void Modifications::on_backButton_clicked()
{
    Menu *menu = new Menu;
    menu->show();
    this->close();
}
