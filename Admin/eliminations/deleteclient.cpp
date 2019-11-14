#include "deleteclient.h"
#include "ui_deleteclient.h"
#include "globalAdmin.h"

DeleteClient::DeleteClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeleteClient)
{
    ui->setupUi(this);
}

DeleteClient::~DeleteClient()
{
    delete ui;
}

void DeleteClient::on_pushButton_clicked()
{
    QString req = "19;"+ui->clientID->text();

    emit adminSock.send(req.toUtf8());
    this->close();
}
