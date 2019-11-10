#include <QCoreApplication>
#include "server.h"
#include "globalTrees.h"
#include "helpers/helpers.h"

BinarySearchTree aisles;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    initAisleTree(aisles);

    Server Server;
    Server.StartServer();

    return a.exec();
}
