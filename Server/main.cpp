#include <iostream>
#include <winsock2.h>
#include <thread>
#include "Helpers/ClientListener.h"

using namespace std;

int main() {
    // STRUCTURE
    WSADATA  WinsockData;
    int      iWsaStartup;
    int      iWsaCleanup;

    SOCKET TCPServerSocket;
    int    iCloseSocket;

    struct sockaddr_in TCPServerAdd{};
    struct sockaddr_in TCPClientAdd{};
    int iTCPClientAdd = sizeof(TCPClientAdd);

    int iBind;
    int iListen;

    SOCKET sAcceptSocket;

    int iSend;
    char SenderBuffer[4096] = "hello from server";
    int iSenderBuffer = sizeof(SenderBuffer)+1;

    int  iRecv;
    char RecvBuffer[4096];
    int  iRecvBuffer = sizeof(RecvBuffer)+1;

    iWsaStartup = WSAStartup(MAKEWORD(2,2), &WinsockData);

    if(iWsaStartup != 0){
        cout<<"WSAStartup Failed"<<endl;
    }
    cout<<"WSAStartUp success"<<endl;

    TCPServerAdd.sin_family = AF_INET;
    TCPServerAdd.sin_addr.s_addr = inet_addr("127.0.0.1");
    TCPServerAdd.sin_port = htons(8000);

    //Socket creation
    TCPServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(TCPServerSocket == INVALID_SOCKET){
        cout<<"Faild socket creation"<<WSAGetLastError()<<endl;
    }
    cout<<"Successful socket creation";

    //Bind
    iBind = bind(TCPServerSocket, (SOCKADDR*)&TCPServerAdd, sizeof(TCPServerAdd));
    if(iBind == SOCKET_ERROR){
        cout<<"Failed bind"<<endl;
    }
    cout<<"Successful bind"<<endl;

    //Thread for clients
    thread CLIENT_JOINER(clientListener);
    CLIENT_JOINER.detach();



    return 0;
}