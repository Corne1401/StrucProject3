#pragma once

#include <iostream>
#include "citiesNode.h"

class citiesList{
public:
    explicit citiesList(){firstNode = aux = nullptr;}
    void next(){
        aux = aux->getNextNode();
    }
    void printList() {
        aux = firstNode;
        while (aux!=nullptr){
            cout << "[" << aux->getCityCode() << ", " << aux->getCityName() << "]" << endl;
            next();
        }
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
    void appendAtEnd(citiesNode *newCitiesNode) {
        if (firstNode == nullptr){
            firstNode = newCitiesNode;
        } else {
            aux = firstNode;
            while (aux->getNextNode() != nullptr){
                next();
            }
            aux->setNextNode(newCitiesNode);
        }

    }
    bool isElementInList(const string &cityCode){
        aux = firstNode;
        bool found = false;
        while (aux!= nullptr){
            if(aux->getCityCode() == cityCode){
                found = true;
                break;
            }
            next();
        }
        return found;
    }

    citiesNode *getFirstNode() const {
        return firstNode;
    }

    citiesNode *getAux() const {
        return aux;
    }

    void setAux(citiesNode *aux) {
        citiesList::aux = aux;
    }

    citiesNode *getElementInList(const string &cityCode) {
        aux = firstNode;
        while (aux!= nullptr){
            if(aux->getCityCode()==cityCode){
                return aux;
            }
            next();
        }
        return nullptr;
    }

private:
    citiesNode *firstNode;
    citiesNode *aux;
};
