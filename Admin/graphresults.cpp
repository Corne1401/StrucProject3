#include "graphresults.h"
#include "ui_graphresults.h"

GraphResults::GraphResults(QString data, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphResults)
{
    ui->setupUi(this);
    this->data = data;
    ui->textEdit->setText(data);
}

GraphResults::~GraphResults()
{
    delete ui;
}
