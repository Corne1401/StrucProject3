#pragma once

#include "../nodeTypes/BSNode.h"

class BinarySearchTree {
public:
    explicit BinarySearchTree(){root= nullptr;highestVisitedValue=lowestVisitedValue=0;}


    BSNode *getRoot() const {
        return root;
    }
    BSNode *getNodeByAisleCode(int aisleCode) {
        return root->getNodeByAisleCode(root, aisleCode);
    }
    void insert(BSNode *node){
        if(isEmpty()){
            root = node;
        }else{
            root->BSNodeInsert(node);
        }
    }
    void inOrder() {
        BSNode::inOrder(root);
    }
    void fullInOrder(){
        BSNode::fullInorder(root);
    }
    void printAisleForPurchase() {
        BSNode::printAisleForPurchase(root);
    }
    bool isEmpty() {
        return root == nullptr;
    }
    bool isAisleCodeInTree(int aisleCode) {
        return root->isAisleCodeInTree(root, aisleCode);
    }
    void generateAisles(string path) {
        ofstream outfile (path);
        outfile << "Aisles List. " << endl;
        BSNode::generateAisles(root, outfile);

        outfile.flags();
        outfile.close();
        cout << "Report generated successfully..." << endl;
    }
    void generateMostVisitedAisleReport(string path) {
        ofstream outfile (path);
        outfile << "Most visited aisle report. " << endl;
        BSNode::getMostVisitedValue(root, highestVisitedValue);
        BSNode::generateMostVisitedAisleReport(root, highestVisitedValue, outfile);

        outfile.flags();
        outfile.close();
        cout << "Report generated successfully..." << endl;
    }
    void generateLeastVisitedAisleReport(string path) {
        ofstream outfile (path);
        outfile << "Least visited aisle report. " << endl;
        lowestVisitedValue = root->getVisits();
        BSNode::getLeastVisitedValue(root, lowestVisitedValue);
        BSNode::generateLeastVisitedAisleReport(root, lowestVisitedValue, outfile);

        outfile.flags();
        outfile.close();
        cout << "Report generated successfully..." << endl;
    }
    string getAislesForClient() {
        string concat;
        return BSNode::getAislesForClient(root, concat);
    }


    int highestVisitedValue;
    int lowestVisitedValue;

    void deleteAisle(int aisleCode) {
        root = root->deleteNode(root, aisleCode);
    }

    void setRoot(BSNode *newRoot) {
        BinarySearchTree::root = newRoot;
    }

private:
    BSNode *root;
};
