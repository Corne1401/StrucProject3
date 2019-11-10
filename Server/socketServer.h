#ifndef SOCKETSTRUCTURE_H
#define SOCKETSTRUCTURE_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QThreadPool>
#include <string>
using namespace std;

class socketServer : public QTcpSocket{
    Q_OBJECT
public:
    socketServer(QObject *parent = nullptr);
    void setServer(qintptr handle);
    void adminAccss(string id);
    void clientAccss(string id);
    QTcpSocket *socket;


public slots:
    void connected();
    void disconnected();
    void readyRead();
};

#endif // SOCKETSTRUCTURE_H
