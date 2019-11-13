#include "eliminations.h"
#include "ui_eliminations.h"
#include "menu.h"

eliminations::eliminations(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eliminations)
{
    ui->setupUi(this);
}

eliminations::~eliminations()
{
    delete ui;
}

void eliminations::on_deleteBack_clicked()
{
    Menu *menu = new Menu;
    menu->show();
    this->close();
}
