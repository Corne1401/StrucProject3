#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QThread>

class clientSocket : public QThread{
    Q_OBJECT
public:
    clientSocket(QObject *parent = nullptr);
    void connectSocket();
    QTcpSocket *clientSock;

public slots:
    void connected();
    void disconnected();
    void readyRead();
    void send(QByteArray data);

};

#endif // CLIENTSOCKET_H
