#include "mapgraph.h"
#include "graphresults.h"
#include "ui_mapgraph.h"
#include "globalClient.h"

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
    emit clientSock.send(req.toUtf8());
}
