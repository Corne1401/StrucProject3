#include "mostprodaisle.h"
#include "ui_mostprodaisle.h"
#include "globalAdmin.h"

MostProdAisle::MostProdAisle(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MostProdAisle)
{
    ui->setupUi(this);
}

MostProdAisle::~MostProdAisle()
{
    delete ui;
}




void MostProdAisle::on_generateButton_clicked()
{
    QString request;
    request = "38;"+ui->aisleCode->text();
    emit adminSock.send(request.toUtf8());
    this->close();
}
