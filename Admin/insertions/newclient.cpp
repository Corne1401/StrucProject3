#include "newclient.h"
#include "ui_newclient.h"

newClient::newClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newClient)
{
    ui->setupUi(this);
}

newClient::~newClient()
{
    delete ui;
}
