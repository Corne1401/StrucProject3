#include "newclient.h"
#include "ui_newclient.h"
#include "globalAdmin.h"

newClient::newClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newClient)
{
    ui->setupUi(this);
}

newClient::~newClient()
{
    delete ui;
}

void newClient::on_confirmNewClient_clicked()
{
    QString req = "11;"+ ui->newId->text()+
            ";"+ui->newClientName->text()+
            ";"+ui->newEmail->text()+
            ";"+ui->newClientCity->text()+
            ";"+ui->newPhone->text();

    emit adminSock.send(req.toUtf8());
    this->close();
}
