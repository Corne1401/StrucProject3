#include "adminSocket.h"
#include "globalAdmin.h"
#include <iostream>

#include "mainwindow.h"
#include "menu.h"
#include "helpers.h"


using namespace std;

adminSocket::adminSocket(QObject *parent):QThread(parent){};

void adminSocket::connectSocket(){
    adminSock = new QTcpSocket(this);
    adminSock->connectToHost("192.168.100.5",8080);

    if(adminSock->waitForConnected(3000)){
        connect(this->adminSock,SIGNAL(connected()), this,SLOT(connected()));
        connect(this->adminSock,SIGNAL(disconnected()), this,SLOT(disconnected()));
        connect(this->adminSock,SIGNAL(readyRead()), this,SLOT(readyRead()));
    }
}
void adminSocket :: connected(){
    cout<<"Connection done"<<endl;
}
void adminSocket::disconnected(){
    cout<<"Socket disconnected"<<endl;
}

void adminSocket::readyRead(){
    QByteArray data = adminSock->readAll();
    string dataToString = data.toStdString();
    vector<string> dataFromServer =helper::split(dataToString,";");


    cout<<"<------DATA------>"<<endl;
    cout<<dataToString<<endl;
    cout<<">----------------<"<<endl;
    if(dataFromServer[0] == "01" && dataFromServer[1]=="1"){
        Menu *menu = new Menu;
        menu->show();
<<<<<<< Updated upstream
=======
    } else if(dataFromServer[0]=="26"){
        graphResults *g = new graphResults(QString::fromStdString(dataFromServer[1]+"\n"+dataFromServer[2]));
<<<<<<< Updated upstream
=======
        g->show();
    } else if(dataFromServer[0]=="28"){
        graphResults *g = new graphResults(QString::fromStdString(dataFromServer[1]+"\n"+dataFromServer[2]));
        g->show();
    } else if(dataFromServer[0]=="30"){
        graphResults *g = new graphResults(QString::fromStdString(dataFromServer[1]+"\n"+dataFromServer[2]));
        g->show();
    } else if(dataFromServer[0]=="32"){
        graphResults *g = new graphResults(QString::fromStdString(dataFromServer[1]+"\n"+dataFromServer[2]));
>>>>>>> Stashed changes
        g->show();
    } else if(dataFromServer[0]=="28"){
        graphResults *g = new graphResults(QString::fromStdString(dataFromServer[1]+"\n"+dataFromServer[2]));
        g->show();
    } else if(dataFromServer[0]=="30"){
        graphResults *g = new graphResults(QString::fromStdString(dataFromServer[1]+"\n"+dataFromServer[2]));
        g->show();
    } else if(dataFromServer[0]=="32"){
        graphResults *g = new graphResults(QString::fromStdString(dataFromServer[1]+"\n"+dataFromServer[2]));
        g->show();
>>>>>>> Stashed changes
    }


}
void adminSocket::send(QByteArray data){
    this->adminSock->write(data);
}
