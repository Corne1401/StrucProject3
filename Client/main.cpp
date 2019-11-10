#include "mainwindow.h"
#include "globalClient.h"
#include <QApplication>

clientSocket clientSock;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    clientSock.connectSocket();

    MainWindow w;
    w.show();
    return a.exec();
}
