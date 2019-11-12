//
// Created by sebas on 9/15/2019.
//

#pragma once

#include <iostream>
#include <fstream>
#include "salesNode.h"
#include "exceptionsHandler.h"

class salesList{
public:

    explicit salesList(){firstNode = aux = nullptr;}
    void appendAtEnd(salesNode *newSalesNode) {
        if (firstNode == nullptr){
            firstNode = newSalesNode;
        } else {
            aux = firstNode;
            while (aux->getNextNode() != nullptr){
                next();
            }
            aux->setNextNode(newSalesNode);
        }

    }

    void generateMostSoldBrands(const string& path) {
        ofstream outfile (path);
        outfile << "Most sold brands report. " << endl;

        aux = firstNode;
        int highestSold = 0;
        while (aux!= nullptr) {
            if (aux->getAmountSold()>=highestSold) {
                highestSold = aux->getAmountSold();
            }
            next();
        }

        aux = firstNode;
        while (aux!= nullptr) {
            if (aux->getAmountSold()==highestSold) {
                outfile << "Aisle Code: " << aux->getAisleCode() << " Prod Code: " << aux->getProdCode() << " Brand Code: " << aux->getBrandCode() << "Amount sold: " << aux->getAmountSold() << endl;
            }
            next();
        }
        outfile.flush();
        outfile.close();
        cout << "Report generated successfully..." << endl;
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
            cout << "[" << aux->getAisleCode() << ", " << aux->getProdCode() << ", " << aux->getBrandCode() << ", " << aux->getAmountSold() << "]" << endl;
            next();
        }
    }

    bool isEmpty() {
        return firstNode == nullptr;
    }

    bool isElementInList(const string &aisleCode, const string &prodCode, const string &brandCode){
        aux = firstNode;
        bool found = false;
        while (aux!= nullptr){
            if(aux->getAisleCode()==aisleCode && aux->getProdCode() == prodCode && aux->getBrandCode() == brandCode){
                found = true;
                break;
            }
            next();
        }
        return found;
    }

    void updateElementInList(const string& aisleCode, const string& prodCode, const string& brandCode, int amountSoldToAdd) {
        aux = firstNode;
        if(aux!= nullptr){
            while(aux->getNextNode()!=firstNode){
                if(aux->getAisleCode() == aisleCode && aux->getProdCode() == prodCode && aux->getBrandCode() == brandCode){
                    int val = aux->getAmountSold();
                    aux->setAmountSold(val+amountSoldToAdd);
                }
                next();
            }
            if(aux->getAisleCode() == aisleCode && aux->getProdCode() == prodCode && aux->getBrandCode() == brandCode){
                int val = aux->getAmountSold();
                aux->setAmountSold(val+amountSoldToAdd);
            }
        } else {
            throw elementNotFound;
        }
    }

    salesNode *getElementInList(const string &aisleCode, const string &prodCode, const string &brandCode) {
        aux = firstNode;
        bool found = false;
        while (aux!= nullptr){
            if(aux->getAisleCode()==aisleCode && aux->getProdCode() == prodCode && aux->getBrandCode() == brandCode){
                return aux;
            }
            next();
        }
        return nullptr;
    }

private:
    salesNode *firstNode;
public:
    salesNode *getFirstNode() const {
        return firstNode;
    }

private:
    salesNode *aux;

};
