#pragma once

#include <iostream>
#include "citiesNode.h"

class citiesList{
public:
    explicit citiesList(){firstNode = aux = nullptr;}
    void next();
    void printList();
    int listSize();
    void appendAtEnd(citiesNode *newCitiesNode);
    bool isElementInList(const string &cityCode);

    citiesNode *getFirstNode() const;

    citiesNode *getAux() const;

    void setAux(citiesNode *aux);

    citiesNode *getElementInList(const string &cityCode);

private:
    citiesNode *firstNode;
    citiesNode *aux;
};

citiesNode *citiesList::getAux() const {
    return aux;
}

void citiesList::setAux(citiesNode *aux) {
    citiesList::aux = aux;
}

citiesNode *citiesList::getFirstNode() const {
    return firstNode;
}

void citiesList::next(){
    aux = aux->getNextNode();
}

void citiesList::printList() {
    aux = firstNode;
    while (aux!=nullptr){
        cout << "[" << aux->getCityCode() << ", " << aux->getCityName() << "]" << endl;
        next();
    }
}

int citiesList::listSize() {
    aux = firstNode;
    int count = 0;
    while (aux!=nullptr){
        count++;
        next();
    }
    return count;
}

void citiesList::appendAtEnd(citiesNode *newCitiesNode) {
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

bool citiesList::isElementInList(const string& cityCode){
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

citiesNode *citiesList::getElementInList(const string &cityCode) {
    aux = firstNode;
    while (aux!= nullptr){
        if(aux->getCityCode()==cityCode){
            return aux;
        }
        next();
    }
    return nullptr;
}