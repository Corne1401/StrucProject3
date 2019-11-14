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
    request = "46;"+ui->aisleCode->text()+";"+ui->prodCode->text();
    emit adminSock.send(request.toUtf8());
    this->close();
}
