#ifndef GLOBALCLIENT_H
#define GLOBALCLIENT_H

#include "clientSocket.h"
using namespace std;

extern clientSocket clientSock;
extern string dataFromServer;

extern bool fromPurchase;

extern QString overWriteQueue;
extern QString clientId;

#endif // GLOBALCLIENT_H
