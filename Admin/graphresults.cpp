#include "graphresults.h"
#include "ui_graphresults.h"

graphResults::graphResults(QString data, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::graphResults)
{
    ui->setupUi(this);
    this->data = data;
    ui->textEdit->setText(data);
}

graphResults::~graphResults()
{
    delete ui;
}
