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
    QString req = "26";
    emit adminSock.send(req.toUtf8());
}
