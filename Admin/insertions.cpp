#include "insertions.h"
#include "ui_insertions.h"
#include "menu.h"

insertions::insertions(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::insertions)
{
    ui->setupUi(this);
}

insertions::~insertions()
{
    delete ui;
}

void insertions::on_insertBack_clicked()
{
    Menu *menu = new Menu;
    menu->show();
    this->close();
}
