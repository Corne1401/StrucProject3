#include "mainwindow.h"
#include "globalClient.h"
#include "mapgraph.h"
#include <QApplication>
using namespace std;

clientSocket clientSock;
string dataFromServer;
bool fromPurchase = false;
QString overWriteQueue = "0";
QString clientId;
bool isLogged = false;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    clientSock.connectSocket();

    MainWindow w;
    MapGraph r;

    w.show();
    return a.exec();
}

