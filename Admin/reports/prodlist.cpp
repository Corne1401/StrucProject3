#include "prodlist.h"
#include "ui_prodlist.h"
#include "globalAdmin.h"

ProdList::ProdList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProdList)
{
    ui->setupUi(this);
}

ProdList::~ProdList()
{
    delete ui;
}

void ProdList::on_generate_clicked()
{
    QString request;
    request = "45;"+ui->aisleCode->text();
    emit adminSock.send(request.toUtf8());
    this->close();
}
