#include "mapgraph.h"
#include "graphresults.h"
#include "ui_mapgraph.h"
#include "globalAdmin.h"

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

void MapGraph::on_primBtn_clicked()
{
    QString req = "26";
    emit adminSock.send(req.toUtf8());
}
