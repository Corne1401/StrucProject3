#include "newaisle.h"
#include "ui_newaisle.h"
#include "globalAdmin.h"

newAisle::newAisle(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newAisle)
{
    ui->setupUi(this);
}

newAisle::~newAisle()
{
    delete ui;
}

void newAisle::on_newAisleConfirm_clicked()
{
    QString req = "08;"+ui->newCode->text()+
            ";"+ui->newName->text();
    emit adminSock.send(req.toUtf8());
    this->close();
}
