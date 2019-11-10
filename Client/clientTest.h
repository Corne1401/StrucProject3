#ifndef CLIENTTEST_H
#define CLIENTTEST_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QThread>
#include <QThreadPool>
#include <iostream>

class client: public QThread
{
    Q_OBJECT
public:
    client(QObject *parent = nullptr);
    void connectSocket();

public slots:
    void connected();
    void disconnected();
    void readyRead();
    void send(QByteArray data);
private:
    QTcpSocket *clientSock;



};

#endif // CLIENTTEST_H
