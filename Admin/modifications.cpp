#include "modifications.h"
#include "ui_modifications.h"

Modifications::Modifications(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Modifications)
{
    ui->setupUi(this);
}

Modifications::~Modifications()
{
    delete ui;
}
