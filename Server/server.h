#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QThreadPool>
#include <QDebug>
#include "socketServer.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void StartServer();
    QList <socketServer *> socketList;


protected:
    void incomingConnection( qintptr handle );

signals:

public slots:

private:
    QThreadPool *pool;
};

#endif // MYSERVER_H
