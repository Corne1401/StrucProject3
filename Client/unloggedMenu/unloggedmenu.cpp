#include "unloggedmenu.h"
#include "ui_unloggedmenu.h"

UnloggedMenu::UnloggedMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UnloggedMenu)
{
    ui->setupUi(this);
}

UnloggedMenu::~UnloggedMenu()
{
    delete ui;
}
