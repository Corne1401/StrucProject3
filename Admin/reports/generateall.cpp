#include "generateall.h"
#include "ui_generateall.h"
#include "globalAdmin.h"


GenerateAll::GenerateAll(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GenerateAll)
{
    ui->setupUi(this);
}

GenerateAll::~GenerateAll()
{
    delete ui;
}

void GenerateAll::on_pushButton_clicked()
{
    QString req = "49;"+ui->aisleCode->text()+";"+ui->prodCode->text()+";"+adminID;
    emit adminSock.send(req.toUtf8());
    this->close();
}
