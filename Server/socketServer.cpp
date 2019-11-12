#include "socketServer.h"
#include "globalTrees.h"
#include "helpers/stringSpliter.h"
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
    stringList holder = splitString(";", dataToStr);
    string serverKey = holder.getByIndex(0);
    holder.print();

    // "6875"

    if(serverKey=="01")//&& (validacion del server)
    {
        if(modules.validateAdmin(admins,holder.getByIndex(1))){
            qDebug()<<"yes pez \n";
            socket->write("01");
        }
        else{
            qDebug()<<"Id no valido";
        }

    }
    else if(serverKey=="02")//&&(validacion cliente)
    {
        if(modules.validateClient(clients,holder.getByIndex(1))){
            qDebug()<<"client verifie \n";
            socket->write("01");
        }

    }


}
