#include "mainwindow.h"
#include "globalClient.h"
#include <QApplication>
using namespace std;

clientSocket clientSock;
string dataFromServer;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    clientSock.connectSocket();

    MainWindow w;
    w.show();
    return a.exec();
}
