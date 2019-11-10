#include "mainwindow.h"
#include "globalAdmin.h"
#include <QApplication>

adminSocket adminSock;

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    adminSock.connectSocket();

    MainWindow w;
    w.show();
    return a.exec();
}
