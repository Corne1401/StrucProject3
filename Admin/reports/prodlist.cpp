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
    QString req2;
    request = "45;"+ui->aisleCode->text()+";"+adminID;
    req2 = "04;"+ui->aisleCode->text()+";"+adminID;

    emit adminSock.send(request.toUtf8());
    this->thread()->sleep(1);
    emit adminSock.send(req2.toUtf8());
    this->close();
}
