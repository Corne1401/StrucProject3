#include "newaisle.h"
#include "ui_newaisle.h"

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
