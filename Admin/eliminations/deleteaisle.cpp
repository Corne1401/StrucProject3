#include "deleteaisle.h"
#include "ui_deleteaisle.h"

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
