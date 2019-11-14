#include "clientSocket.h"
#include "graphresults.h"
#include "helpers/helpers.h"
#include "unloggedMenu/unloggedmenu.h"
#include "menu.h"
#include "purchase.h"
#include "globalClient.h"
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
    vector<string> dataFromServer = helper::split(dataToString,";");


    cout<<"<------DATA------>"<<endl;
    cout<<dataToString<<endl;
    cout<<">----------------<"<<endl;

    if(dataFromServer[0]=="01"){
        if(dataFromServer[1]=="1"){
            Menu *menu = new Menu;
            menu->show();
        }else if(dataFromServer[1]=="0"){
            UnloggedMenu *uMenu = new UnloggedMenu;
            uMenu->show();
        }
    }
    else if(dataFromServer[0]=="03" && fromPurchase){
        purchase p;
        p.setAislesForComboBox(dataFromServer[1]);
        p.show();
    }

}
void clientSocket::send(QByteArray data){
    this->clientSock->write(data);
}
