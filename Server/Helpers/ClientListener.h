#pragma once

#include <winsock2.h>
#include <thread>

using namespace std;

void clientListener(SOCKET client, sockaddr_in &TCPClientAdd, int &iTCPClientAdd){
    int servListen = listen(client, 5);
    if(servListen == SOCKET_ERROR){
        cout<<"Failed listen"<<endl;
    }
    cout<<"Successful listen"<<endl;

    while(true){
        SOCKET servAcceptSock;
        servAcceptSock = accept(client, (SOCKADDR*)&TCPClientAdd, &iTCPClientAdd);

        if(servAcceptSock == INVALID_SOCKET){
            cout<<"Conection failed"<<endl;
        }
        else{
            //Client Handler Thread
        }

    }
}
