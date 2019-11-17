#include "brandlist.h"
#include "ui_brandlist.h"
#include "globalAdmin.h"

BrandList::BrandList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BrandList)
{
    ui->setupUi(this);
}

BrandList::~BrandList()
{
    delete ui;
}

void BrandList::on_generate_clicked()
{
    QString request;
    QString req2;
    request = "46;"+ui->aisleCode->text()+";"+ui->prodCode->text()+";"+adminID;
    req2 = "05;"+ui->aisleCode->text()+";"+ui->prodCode->text()+";"+adminID;
    emit adminSock.send(request.toUtf8());
    this->thread()->sleep(1);
    emit adminSock.send(req2.toUtf8());

    this->close();
}
