#include "generateall.h"
#include "ui_generateall.h"
<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
#include "globalAdmin.h"
>>>>>>> Stashed changes
=======
#include "globalAdmin.h"
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
=======
>>>>>>> Stashed changes

void GenerateAll::on_pushButton_clicked()
{
    QString req = "49;"+ui->aisleCode->text()+";"+ui->prodCode->text();
    emit adminSock.send(req.toUtf8());
    this->close();
}
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
