#pragma once

#include <iostream>
#include "../TreesHandlers/NewAVLTree.h"
#include "BaseBinaryNode.h"

using namespace std;
class BSNode : public BaseBinaryNode {
public:
    explicit BSNode(int aisleCode, string name) : BaseBinaryNode(aisleCode){
        this->name = name;
        this->visits = 0;
        this->productAisleTreePointer = nullptr;
    }

    void setProductAisleTreePointer(NewAVLTree *newProductAisleTreePointer) {
        BSNode::productAisleTreePointer = newProductAisleTreePointer;
    }
    void setName(const string &newName) {
        BSNode::name = newName;
    }
    void BSNodeInsert(BSNode *node) {
        if(node->getData()<getData()){
            if(getLeftPointer() == nullptr){
                setLeftPointer(node);
            }else{
                ((BSNode*) getLeftPointer())->BSNodeInsert(node);
            }
        }else{
            if(getRightPointer() == nullptr){
                setRightPointer(node);
            }else{
                ((BSNode*) getRightPointer())->BSNodeInsert(node);
            }
        }
    }
    void setVisits(int newName) {
        BSNode::visits = newName;
    }
    void incVisits(){
        BSNode::visits++;
    }
    static void inOrder(BSNode *R){
        if(R == nullptr){
            return;
        }else{
            inOrder((BSNode*) R->getLeftPointer());
            cout<< "(" << R->getData()<< ", "<< R->getName() << ")" << " - ";
            inOrder((BSNode*) R->getRightPointer());
        }
    }
    static void fullInorder(BSNode *R) {
        if(R == nullptr){
            return;
        }else{
            fullInorder((BSNode*) R->getLeftPointer());
            cout<< "(" << R->getData()<< ", "<< R->getName() << ")" << " - ";
            if(R->getProductAisleTreePointer()!= nullptr){
                cout << "Second tree inorder for: " << R->getData() << endl;
                R->getProductAisleTreePointer()->fullInorder(R->getProductAisleTreePointer()->getAVLRoot());
                cout << "End of Second Tree Inorder" << endl;
            }
            fullInorder((BSNode*) R->getRightPointer());
        }
    }
    static void printAisleForPurchase(BSNode *R) {
        if(R == nullptr){
            return;
        }else{
            printAisleForPurchase((BSNode*) R->getLeftPointer());
            cout << "Aisle Code: " << R->getData()<< " Name:"<< R->getName() << endl;
            printAisleForPurchase((BSNode*) R->getRightPointer());
        }
    }
    static void getMostVisitedValue(BSNode *R, int &highestValue) {
        if(R == nullptr){
            return;
        }else{
            getMostVisitedValue((BSNode*) R->getLeftPointer(), highestValue);

            if(R->getVisits() >= highestValue){
                highestValue = R->getVisits();
            }

            getMostVisitedValue((BSNode*) R->getRightPointer(), highestValue);
        }
    }
    static void getLeastVisitedValue(BSNode *R, int &lowestValue) {
        if(R == nullptr){
            return;
        }else{
            getLeastVisitedValue((BSNode*) R->getLeftPointer(), lowestValue);

            if(R->getVisits() <= lowestValue){
                lowestValue = R->getVisits();
            }

            getLeastVisitedValue((BSNode*) R->getRightPointer(), lowestValue);
        }
    }
    static void generateAisles(BSNode *R, ofstream &outfile) {
        if(R == nullptr){
            return;
        }else{
            generateAisles((BSNode*) R->getLeftPointer(), outfile);
            outfile << "Aisle Code: " << R->getData() << " Aisle Name: " << R->getName() << " Visits: " << R->getVisits() << endl;
            generateAisles((BSNode*) R->getRightPointer(), outfile);
        }
    }
    static void generateMostVisitedAisleReport(BSNode *R, int highestValue, ofstream &outfile) {
        if(R == nullptr){
            return;
        }else{
            generateMostVisitedAisleReport((BSNode*) R->getLeftPointer(), highestValue, outfile);

            if(R->getVisits() >= highestValue){
                outfile << "Aisle Code: " << R->getData() << " Aisle Name: " << R->getName() << " Visits: " << R->getVisits() << endl;
            }

            generateMostVisitedAisleReport((BSNode*) R->getRightPointer(), highestValue, outfile);
        }
    }
    static void generateLeastVisitedAisleReport(BSNode *R, int highestValue, ofstream &outfile) {
        if(R == nullptr){
            return;
        }else{
            generateMostVisitedAisleReport((BSNode*) R->getLeftPointer(), highestValue, outfile);

            if(R->getVisits() <= highestValue){
                outfile << "Aisle Code: " << R->getData() << " Aisle Name: " << R->getName() << " Visits: " << R->getVisits() << endl;
            }

            generateMostVisitedAisleReport((BSNode*) R->getRightPointer(), highestValue, outfile);
        }
    }
    static bool isAisleCodeInTree(BSNode *R, int i){
        if (R == nullptr){
            return false;
        } else {
            if(R->getData()==i){
                return true;
            } else{
                if (i>R->getData()){
                    return isAisleCodeInTree((BSNode*) R->getRightPointer(), i);
                } else {
                    return isAisleCodeInTree((BSNode*) R->getLeftPointer(), i);
                }
            }
        }
    }
    const string &getName() const {
        return name;
    }
    int getVisits() const {
        return visits;
    }
    using BaseBinaryNode::getData;
    BSNode *getNodeByAisleCode(BSNode *R, int i) {
        if (R == nullptr){
            return nullptr;
        } else {
            if(R->getData()==i){
                return R;
            } else{
                if (i>R->getData()){
                    return getNodeByAisleCode((BSNode*) R->getRightPointer(), i);
                } else {
                    return getNodeByAisleCode((BSNode*) R->getLeftPointer(), i);
                }
            }
        }
    }
    BSNode *minValueNode(BSNode *node){
        BSNode *current = node;

        /* loop down to find the leftmost leaf */
        while (current && current->getLeftPointer() != nullptr) {
            current = (BSNode*) current->getLeftPointer();
        }

        return current;
    }

    BSNode *deleteNode(BSNode *root, int key){
        // base case
        if (root == nullptr) {
            return root;
        }


        if (key < root->getData()) {
            // If the key to be deleted is smaller than the root's key,
            // then it lies in left subtree
            root->setLeftPointer(deleteNode((BSNode *) root->getLeftPointer(), key));
        }
        else if (key > root->getData()) {
            // If the key to be deleted is greater than the root's key,
            // then it lies in right subtree
            root->setRightPointer(deleteNode((BSNode*) root->getRightPointer(), key));
        }
        else{
            // if key is same as root's key, then This is the node
            // to be deleted

            // node with only one child or no child
            if (root->getLeftPointer() == nullptr){
                BSNode *temp = (BSNode*) root->getRightPointer();
                free(root);
                return temp;
            }
            else if (root->getRightPointer() == nullptr){
                BSNode *temp = (BSNode*) root->getLeftPointer();
                free(root);
                return temp;
            }

            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            BSNode *temp = minValueNode((BSNode*) root->getRightPointer());

            // Copy the inorder successor's content to this node
            root->setData(temp->getData());
            root->setName(temp->getName());
            root->setProductAisleTreePointer(temp->getProductAisleTreePointer());

            // Delete the inorder successor
            root->setRightPointer(deleteNode((BSNode*) root->getRightPointer(), temp->getData()));
        }
        return root;
    }
    NewAVLTree *getProductAisleTreePointer() const {
        return productAisleTreePointer;
    }
    static string getAislesForClient(BSNode *R, string &concat) {
        if(R == nullptr){
            return concat;
        }else{
            concat = getAislesForClient((BSNode*) R->getLeftPointer(), concat);
            concat += "Aisle Code: "+ to_string(R->getData()) +" Name:" + R->getName() + "\n";
            concat = getAislesForClient((BSNode*) R->getRightPointer(), concat);
        }
        return concat;
    }



private:
    NewAVLTree *productAisleTreePointer;
    string name;
    int visits;
};
