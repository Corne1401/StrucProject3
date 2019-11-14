#include "mainwindow.h"
#include "globalAdmin.h"
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
    w.show();
<<<<<<< Updated upstream
=======


>>>>>>> Stashed changes
    return a.exec();
}
