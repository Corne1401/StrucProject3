#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QDebug>
#include "mythread.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = nullptr);
    void StartServer();


protected:
    void incomingConnection(int socketDescriptor);

};

#endif // MYSERVER_H
