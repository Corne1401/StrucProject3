#include "socketServer.h"
#include <iostream>
using namespace std;

socketServer::socketServer(QObject *parent) : QTcpSocket(parent){
    QThreadPool :: globalInstance()->setMaxThreadCount(5);
}

void socketServer::setServer(qintptr handle){
    socket = new QTcpSocket(this);

    connect(socket,SIGNAL(connected()), this,SLOT(connected()));
    connect(socket,SIGNAL(disconnected()), this,SLOT(disconnected()));
    connect(socket,SIGNAL(readyRead()), this,SLOT(readyRead()));

    socket->setSocketDescriptor(handle);
}

void socketServer::connected(){

}

void socketServer::disconnected(){
    qDebug()<<"Connection ended"<<endl;
}

void socketServer::readyRead(){
    QByteArray data = socket->readAll();
    string dataToStr = data.toStdString();
    string serverKey = dataToStr.substr(0,2);

    if(serverKey=="01")//&& (validacion del server)
    {
        qDebug()<<"admin verified"<<endl;
        socket->write("si se pudo bro \n");
    }
    else if(serverKey=="02")//&&(validacion cliente)
    {
        qDebug()<<"client verified"<<endl;
    }


}
