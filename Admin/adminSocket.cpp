#include "adminSocket.h"
#include "globalAdmin.h"
#include <iostream>

#include "mainwindow.h"
#include "menu.h"
#include "helpers.h"
#include "graphresults.h"

#include <QMessageBox>


using namespace std;

adminSocket::adminSocket(QObject *parent):QThread(parent){};

void adminSocket::connectSocket(){
    adminSock = new QTcpSocket(this);
    adminSock->connectToHost("192.168.86.196",8080);

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
    } else if(dataFromServer[0]=="20"){
        QMessageBox answ;
        string temp = dataFromServer[1];
        QString qtemp = QString::fromUtf8(temp.c_str());
        answ.setText(qtemp);
        answ.exec();

    } else if(dataFromServer[0]=="21"){
        QMessageBox answ;
        if(dataFromServer[1]=="1"){
            answ.setText("Is Basic");
        } else if(dataFromServer[1]=="0"){
            answ.setText("Is Normal");
        }
        answ.exec();

    } else if(dataFromServer[0]=="22"){

        QMessageBox answ;
        string temp = dataFromServer[1];

        QString qtemp = QString::fromUtf8(temp.c_str());
        answ.setText(qtemp);
        answ.exec();
    } else if(dataFromServer[0]=="23"){
        QMessageBox answ;
        string temp = dataFromServer[1];

        if(temp=="1"){
            string clientName = dataFromServer[2];
            string clientID = dataFromServer[3];
            string showMsg = "Billed Client ID: "+clientID+", name: "+clientName;

            QString qtemp = QString::fromUtf8(showMsg.c_str());
            answ.setText(qtemp);
            answ.exec();

        }else{
            string showMsg = "Could not complete billing.";
            QString qtemp = QString::fromUtf8(showMsg.c_str());
            answ.setText(qtemp);
            answ.exec();
        }
    } else if(dataFromServer[0]=="26"){
        graphResults *g = new graphResults(QString::fromStdString(dataFromServer[1]+"\n"+dataFromServer[2]));
        g->show();
    } else if(dataFromServer[0]=="28"){
        graphResults *g = new graphResults(QString::fromStdString(dataFromServer[1]+"\n"+dataFromServer[2]));
        g->show();
    } else if(dataFromServer[0]=="30"){
        graphResults *g = new graphResults(QString::fromStdString(dataFromServer[1]+"\n"+dataFromServer[2]));
        g->show();
    } else if(dataFromServer[0]=="32"){
        graphResults *g = new graphResults(QString::fromStdString(dataFromServer[1]));
        g->show();
    } else if(dataFromServer[0]=="33"){
        graphResults *g = new graphResults(QString::fromStdString(dataFromServer[1]));
        g->show();
    } else if(dataFromServer[0]=="34"){
        graphResults *g = new graphResults(QString::fromStdString(dataFromServer[1]));
        g->show();
    }


}
void adminSocket::send(QByteArray data){
    this->adminSock->write(data);
}
