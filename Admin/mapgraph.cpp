#include "mapgraph.h"
#include "globalAdmin.h"
#include "ui_mapgraph.h"

mapGraph::mapGraph(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mapGraph)
{
    ui->setupUi(this);
}

mapGraph::~mapGraph()
{
    delete ui;
}

void mapGraph::on_primBtn_clicked()
{
    QString req = "26;"+adminID;
    emit adminSock.send(req.toUtf8());
}

void mapGraph::on_kurskalBtn_clicked()
{
    QString req = "28;"+adminID;
    emit adminSock.send(req.toUtf8());
}

void mapGraph::on_dijkstraBtn_clicked()
{
    QString req = "30;"+adminID;
    emit adminSock.send(req.toUtf8());
}

void mapGraph::on_articulationBtn_clicked()
{
    QString req = "32;"+adminID;
    emit adminSock.send(req.toUtf8());
}

void mapGraph::on_DFSBtn_clicked()
{
    QString req = "33;"+adminID;
    emit adminSock.send(req.toUtf8());
}

void mapGraph::on_BFSBtn_clicked()
{
    QString req = "34;"+adminID;
    emit adminSock.send(req.toUtf8());
}
