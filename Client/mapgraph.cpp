#include "mapgraph.h"
#include "ui_mapgraph.h"

MapGraph::MapGraph(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MapGraph)
{
    ui->setupUi(this);
}

MapGraph::~MapGraph()
{
    delete ui;
}
