//
// Created by sebas on 9/11/2019.
//

#pragma once

#include <string>
#include "clientProductStackNode.h"

using namespace std;
class clientQueueNode{
public:

    explicit clientQueueNode(const string &clientId){
        this->clientId = clientId;
        this->nextNode = nullptr;
        this->firstClientProd = nullptr;
    }

    explicit clientQueueNode(const string &clientId, clientQueueNode *nextNode){
        this->clientId = clientId;
        this->nextNode = nextNode;
        this->firstClientProd = nullptr;
    }

    const string &getClientId() const {
        return clientId;
    }
    void setClientId(const string &newClientId) {
        clientQueueNode::clientId = newClientId;
    }
    clientProductStackNode *getFirstClientProd() const {
        return firstClientProd;
    }
    void setFirstClientProd(clientProductStackNode *newFirstClientProd) {
        clientQueueNode::firstClientProd = newFirstClientProd;
    }

    clientQueueNode *getNextNode() const {
        return nextNode;
    }

    void setNextNode(clientQueueNode *newNextNode) {
        clientQueueNode::nextNode = newNextNode;
    }

private:
    string clientId;
    clientProductStackNode *firstClientProd;
    clientQueueNode *nextNode;
};
