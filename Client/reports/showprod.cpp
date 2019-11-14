#include "showprod.h"
#include "ui_showprod.h"
#include "globalClient.h"

ShowProd::ShowProd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowProd)
{
    ui->setupUi(this);
}

ShowProd::~ShowProd()
{
    delete ui;
}

void ShowProd::on_pushButton_clicked()
{
    QString req = "04;"+ui->aisleCode->text();
    emit clientSock.send(req.toUtf8());
}
