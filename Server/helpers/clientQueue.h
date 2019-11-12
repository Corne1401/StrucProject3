//
// Created by sebas on 9/11/2019.
//

#pragma once

#include <iostream>
#include "clientQueueNode.h"

class clientQueue{
public:
    clientQueue(){firstNode = aux = nullptr;}
    void appendAtStart(clientQueueNode *newClientQueueNode) {
        if(firstNode == nullptr){
            firstNode = newClientQueueNode;
        } else {
            clientQueueNode *temp = newClientQueueNode;
            temp->setNextNode(firstNode->getNextNode());

        }
    }
    void appendAtStart(string clientId) {
        if(firstNode == nullptr){
            firstNode = new clientQueueNode(clientId);
        } else {
            firstNode = new clientQueueNode(clientId, firstNode);
        }
    }
    void deleteAtEnd() {
        aux = firstNode;
        if (!isEmpty()){
            if (firstNode->getNextNode() == nullptr) {
                firstNode = nullptr;
            } else {
                while (aux->getNextNode()->getNextNode() != nullptr) {
                    next();
                }
                clientQueueNode *temp = aux->getNextNode();
                aux->setNextNode(nullptr);
                delete temp;
            }
        }
    }
    void next(){
        aux = aux->getNextNode();
    }
    int listSize() {
        aux = firstNode;
        int count = 0;
        while (aux!=nullptr){
            count++;
            next();
        }
        return count;
    }
    void printList() {
        aux = firstNode;
        while (aux!=nullptr){
            cout << "[" << aux->getClientId() << "]" << endl;
            next();
        }
    }
    bool isEmpty() {
        return firstNode == nullptr;
    }
    bool isClientIdInList(const string& clientId) {
        aux = firstNode;
        bool found = false;
        while(aux != nullptr){
            if(aux->getClientId() == clientId){
                found= true;
                break;
            }
            next();
        }
        return found;
    }
    clientQueueNode *getClientById(const string& clientId) {
        aux = firstNode;
        while(aux != nullptr){
            if(aux->getClientId() == clientId){
                return aux;
            }
            next();
        }
        return nullptr;
    }
    clientQueueNode *getLastElement(){
        aux = firstNode;
        while(aux->getNextNode() != nullptr){
            next();
        }
        return aux;
    }

    clientQueueNode *getFirstNode() const {
        return firstNode;
    }

private:
    clientQueueNode *aux;
    clientQueueNode *firstNode;
};
