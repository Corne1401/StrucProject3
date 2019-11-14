#include "check.h"
#include "ui_check.h"

Check::Check(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Check)
{
    ui->setupUi(this);
}

Check::~Check()
{
    delete ui;
}
