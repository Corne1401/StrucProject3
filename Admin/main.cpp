#include "mainwindow.h"
#include "globalAdmin.h"
#include "mapgraph.h"
#include <QApplication>
using namespace std;

adminSocket adminSock;
string dataFromServer;

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    adminSock.connectSocket();

    MainWindow w;
    mapGraph m;
//    w.show();
    m.show();
    //y.show();
    return a.exec();
}
