#include "deleteaisle.h"
#include "ui_deleteaisle.h"
#include "globalAdmin.h"

deleteAisle::deleteAisle(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::deleteAisle)
{
    ui->setupUi(this);
}

deleteAisle::~deleteAisle()
{
    delete ui;
}

void deleteAisle::on_pushButton_clicked()
{
    QString req = "16;"+ui->aisleToDelete->text();
    emit adminSock.send(req.toUtf8());
    this->close();
}
