#include "checkprod.h"
#include "ui_checkprod.h"
#include "adminSocket.h"
#include "globalAdmin.h"

CheckProd::CheckProd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckProd)
{
    ui->setupUi(this);
}

CheckProd::~CheckProd()
{
    delete ui;
}

void CheckProd::on_pushButton_clicked()
{
    QString req = "04;"+ui->aisleCode->text()+";"+adminID;
    emit adminSock.send(req.toUtf8());
}

