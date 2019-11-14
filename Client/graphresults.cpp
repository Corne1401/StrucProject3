#include "graphresults.h"
#include "ui_graphresults.h"

GraphResults::GraphResults(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphResults)
{
    ui->setupUi(this);
}

GraphResults::~GraphResults()
{
    delete ui;
}
