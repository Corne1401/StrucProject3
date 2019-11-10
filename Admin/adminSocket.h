#ifndef ADMINSOCKET_H
#define ADMINSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QThread>

class adminSocket : public QThread{
    Q_OBJECT
public:
    adminSocket(QObject *parent = nullptr);
    void connectSocket();
    QTcpSocket *adminSock;
public slots:
    void connected();
    void disconnected();
    void readyRead();
    void send(QByteArray data);
};


#endif // ADMINSOCKET_H
