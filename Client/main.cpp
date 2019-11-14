#include "mainwindow.h"
#include "globalClient.h"
#include "mapgraph.h"
#include <QApplication>
using namespace std;

clientSocket clientSock;
string dataFromServer;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    clientSock.connectSocket();

    MainWindow w;
    MapGraph r;
    //w.show();
    r.show();
    return a.exec();
}
