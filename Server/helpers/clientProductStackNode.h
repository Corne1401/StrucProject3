//
// Created by sebas on 9/11/2019.
//

#pragma once

#include <string>

using namespace std;
class clientProductStackNode{
public:
    clientProductStackNode(const string &aisleCode, const string &prodCode, const string &brandCode, int amount){
        this->aisleCode = aisleCode;
        this->prodCode = prodCode;
        this->brandCode = brandCode;
        this->amount = amount;
        this->nextNode = nullptr;
    }

    const string &getAisleCode() const {
        return aisleCode;
    }

    void setAisleCode(const string &newAisleCode) {
        clientProductStackNode::aisleCode = newAisleCode;
    }

    const string &getProdCode() const {
        return prodCode;
    }

    void setProdCode(const string &newProdCode) {
        clientProductStackNode::prodCode = newProdCode;
    }

    const string &getBrandCode() const {
        return brandCode;
    }

    void setBrandCode(const string &newBrandCode) {
        clientProductStackNode::brandCode = newBrandCode;
    }

    int getAmount() const {
        return amount;
    }

    void setAmount(int newAmount) {
        clientProductStackNode::amount = newAmount;
    }

    clientProductStackNode *getNextNode() const {
        return nextNode;
    }

    void setNextNode(clientProductStackNode *newNextNode) {
        clientProductStackNode::nextNode = newNextNode;
    }

private:
    string aisleCode;
    string prodCode;
    string brandCode;
    int amount;

    clientProductStackNode *nextNode;
};
