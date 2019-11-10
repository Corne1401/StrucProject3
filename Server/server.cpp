#include "server.h"
#include <iostream>
using namespace std;
Server::Server(QObject *parent) :
    QTcpServer(parent)
{
    pool = new QThreadPool(this);
    pool->setMaxThreadCount(5);
}

void Server::StartServer()
{
    if(this->listen(QHostAddress::Any, 8080))
    {
        qDebug() << "Server started";
    }
    else
    {
        qDebug() << "Server did not start!";
    }
}

void Server::incomingConnection(qintptr handle)
{
    socketServer *server = new socketServer();
    server->setServer(handle);
    this->socketList.append(server);
    cout<<"dele bimba";
}
