#pragma once

// An AVL tree node
#include <string>
#include "../TreesHandlers/NewRBTree.h"

using namespace std;
class NewAVLNode{

public:
    explicit NewAVLNode(int key, string name){
        this->key = key;
        this->name = move(name);
        this->height = 1;
        this->left = nullptr;
        this->right = nullptr;
        this->timesSold = 0;
        this->productAisleBrandTreePointer = nullptr;
    }

    int getKey() const {
        return key;
    }

    void setKey(int newKey) {
        NewAVLNode::key = newKey;
    }

    NewAVLNode *getLeftPointer() const {
        return left;
    }

    void setLeftPointer(NewAVLNode *newLeft) {
        NewAVLNode::left = newLeft;
    }

    NewAVLNode *getRightPointer() const {
        return right;
    }

    void setRightPointer(NewAVLNode *newRight) {
        NewAVLNode::right = newRight;
    }

    int getHeight() const {
        return height;
    }

    void setHeight(int newHeight) {
        NewAVLNode::height = newHeight;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &newName) {
        NewAVLNode::name = newName;
    }

    int getTimesSold() const {
        return timesSold;
    }

    void setTimesSold(int newTimesSold) {
        NewAVLNode::timesSold = newTimesSold;
    }

    NewRBTree *getProductAisleBrandTreePointer() const {
        return productAisleBrandTreePointer;
    }

    void setProductAisleBrandTreePointer(NewRBTree *newProductAisleBrandTreePointer) {
        NewAVLNode::productAisleBrandTreePointer = newProductAisleBrandTreePointer;
    }

    bool isProdCodeInTree(NewAVLNode *R, int i) {
        if (R == nullptr){
            return false;
        } else {
            if(R->key==i){
                return true;
            } else{
                if (i>R->key){
                    return isProdCodeInTree((NewAVLNode*) R->getRightPointer(), i);
                } else {
                    return isProdCodeInTree((NewAVLNode*) R->getLeftPointer(), i);
                }
            }
        }
    }

    NewAVLNode *getNodeByProdCode(NewAVLNode *R, int i){
        if (R == nullptr){
            return R;
        } else {
            if(R->key==i){
                return R;
            } else{
                if (i>R->key){
                    return getNodeByProdCode((NewAVLNode*) R->getRightPointer(), i);
                } else {
                    return getNodeByProdCode((NewAVLNode*) R->getLeftPointer(), i);
                }
            }
        }
    }

    static void getMostBoughtValue(NewAVLNode *R, int &highestValue){
        if(R == nullptr){
            return;
        }else{
            getMostBoughtValue((NewAVLNode*) R->getLeftPointer(), highestValue);

            if(R->getTimesSold() >= highestValue){
                highestValue = R->getTimesSold();
            }

            getMostBoughtValue((NewAVLNode*) R->getRightPointer(), highestValue);
        }
    }

    static void generateMostBoughtProd(NewAVLNode *R, int highestValue, ofstream &outfile){
        if(R == nullptr){
            return;
        }else{
            generateMostBoughtProd((NewAVLNode*) R->getLeftPointer(), highestValue, outfile);

            if(R->getTimesSold() <= highestValue){
                outfile << "Prod Code: " << R->key << " Prod Name: " << R->getName() << " Times bought: " << R->getTimesSold() << endl;
            }

            generateMostBoughtProd((NewAVLNode*) R->getRightPointer(), highestValue, outfile);
        }
    }

    static void generateProductsList(NewAVLNode *R, ofstream &outfile) {
        if(R == nullptr){
            return;
        }else{
            generateProductsList((NewAVLNode*) R->getLeftPointer(), outfile);
            outfile << "Prod Code: " << R->key << " Prod Name: " << R->getName() << " Times bought: " << R->getTimesSold() << endl;
            generateProductsList((NewAVLNode*) R->getRightPointer(), outfile);
        }
    }

private:
    int key;
    NewAVLNode *left;
    NewAVLNode *right;
    int height;
    string name;
    int timesSold;
    NewRBTree *productAisleBrandTreePointer;

    friend class NewAVLTree;

};
