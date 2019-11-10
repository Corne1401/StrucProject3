#include "clientSocket.h"
#include <iostream>
using namespace std;

clientSocket::clientSocket(QObject *parent):QThread(parent){};

void clientSocket::connectSocket(){
    clientSock = new QTcpSocket(this);
    clientSock->connectToHost("localhost",8080);

    if(clientSock->waitForConnected(3000)){
        connect(this->clientSock,SIGNAL(connected()), this,SLOT(connected()));
        connect(this->clientSock,SIGNAL(disconnected()), this,SLOT(disconnected()));
        connect(this->clientSock,SIGNAL(readyRead()), this,SLOT(readyRead()));
    }
}
void clientSocket :: connected(){
    cout<<"Connection done"<<endl;
}
void clientSocket::disconnected(){
    cout<<"Socket disconnected"<<endl;
}

void clientSocket::readyRead(){
    QByteArray data = clientSock->readAll();
    string dataToString = data.toStdString();
    cout<<dataToString<<endl;



}
void clientSocket::send(QByteArray data){
    this->clientSock->write(data);
}
