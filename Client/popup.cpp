#include "popup.h"
#include "ui_popup.h"
#include "globalClient.h"
#include "purchase.h"
#include "menu.h"

PopUp::PopUp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PopUp)
{
    ui->setupUi(this);
}

PopUp::~PopUp()
{
    delete ui;
}

void PopUp::on_yesBtn_clicked()
{
    overWriteQueue = "1";
    purchase *pur = new purchase;
    pur->show();
    this->close();
}

void PopUp::on_noBtn_clicked()
{
    Menu *m = new Menu;
    overWriteQueue = "0";
    this->close();
    m->show();
}
