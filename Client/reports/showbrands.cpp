#include "showbrands.h"
#include "ui_showbrands.h"
#include "globalClient.h"

ShowBrands::ShowBrands(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowBrands)
{
    ui->setupUi(this);
}

ShowBrands::~ShowBrands()
{
    delete ui;
}

void ShowBrands::on_pushButton_clicked()
{
    QString req = "05;"+ui->aisleCode->text()+
            ";"+ui->prodCode->text();

    emit clientSock.send(req.toUtf8());
}
