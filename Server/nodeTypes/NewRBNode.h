#pragma once

#include <string>
#include <fstream>
using namespace std;

enum COLOR {RED, BLACK};

class NewRBNode{
public:
    int val;
    COLOR color;
    NewRBNode *left, *right, *parent;

    explicit NewRBNode(int val, string name, int amount, int price) {
        parent = left = right = nullptr;
        this->val = val;
        this->name = std::move(name);
        this->amount = amount;
        this->price = price;
        this->timesSold = 0;
        // Node is created during insertion
        // Node is red at insertion
        color = RED;
    }

    // returns pointer to uncle
    NewRBNode *uncle() {
        // If no parent or grandparent, then no uncle
        if (parent == nullptr or parent->parent == nullptr)
            return nullptr;

        if (parent->isOnLeft())
            // uncle on right
            return parent->parent->right;
        else
            // uncle on left
            return parent->parent->left;
    }

    // check if node is left child of parent
    bool isOnLeft() { return this == parent->left; }

    // returns pointer to sibling
    NewRBNode *sibling() {
        // sibling null if no parent
        if (parent == nullptr)
            return nullptr;

        if (isOnLeft())
            return parent->right;

        return parent->left;
    }

    // moves node down and moves given node in its place
    void moveDown(NewRBNode *nParent) {
        if (parent != nullptr) {
            if (isOnLeft()) {
                parent->left = nParent;
            } else {
                parent->right = nParent;
            }
        }
        nParent->parent = parent;
        parent = nParent;
    }

    bool hasRedChild() {
        return (left != nullptr and left->color == RED) or
               (right != nullptr and right->color == RED);
    }

    const string &getName() const;

    void setName(const string &name);

    int getAmount() const;

    void setAmount(int amount);

    int getPrice() const;

    void setPrice(int price);

    int getTimesSold() const;

    void setTimesSold(int timesSold);

    NewRBNode *getLeftPointer() const;

    void setLeftPointer(NewRBNode *left);

    NewRBNode *getRightPointer() const;

    void setRightPointer(NewRBNode *right);

    bool isBrandCodeOnList(NewRBNode *R, int i);

    NewRBNode *getBrandNode(NewRBNode *R, int i);

    void generateBrand(NewRBNode *R, ofstream &outfile);

    string getBrandsForClient(NewRBNode *R, string &concat);

private:
    string name;
    int amount;
    int price;
    int timesSold;



    friend class NewRBTree;
};

NewRBNode *NewRBNode::getLeftPointer() const {
    return left;
}

void NewRBNode::setLeftPointer(NewRBNode *left) {
    NewRBNode::left = left;
}

NewRBNode *NewRBNode::getRightPointer() const {
    return right;
}

void NewRBNode::setRightPointer(NewRBNode *right) {
    NewRBNode::right = right;
}

const string &NewRBNode::getName() const {
    return name;
}

void NewRBNode::setName(const string &name) {
    NewRBNode::name = name;
}

int NewRBNode::getAmount() const {
    return amount;
}

void NewRBNode::setAmount(int amount) {
    NewRBNode::amount = amount;
}

int NewRBNode::getPrice() const {
    return price;
}

void NewRBNode::setPrice(int price) {
    NewRBNode::price = price;
}

int NewRBNode::getTimesSold() const {
    return timesSold;
}

void NewRBNode::setTimesSold(int timesSold) {
    NewRBNode::timesSold = timesSold;
}

bool NewRBNode::isBrandCodeOnList(NewRBNode *R, int i) {
    if (R == nullptr){
        return false;
    } else {
        if(R->val==i){
            return true;
        } else{
            if (i>R->val){
                return isBrandCodeOnList((NewRBNode*) R->getRightPointer(), i);
            } else {
                return isBrandCodeOnList((NewRBNode*) R->getLeftPointer(), i);
            }
        }
    }
}

NewRBNode *NewRBNode::getBrandNode(NewRBNode *R, int i){
    if (R == nullptr){
        return R;
    } else {
        if(R->val==i){
            return R;
        } else{
            if (i>R->val){
                return getBrandNode((NewRBNode*) R->getRightPointer(), i);
            } else {
                return getBrandNode((NewRBNode*) R->getLeftPointer(), i);
            }
        }
    }
}

void NewRBNode::generateBrand(NewRBNode *R, ofstream &outfile) {
    if (R == nullptr)
        return;

    generateBrand((NewRBNode*) R->getLeftPointer(), outfile);
    outfile << "Brand Code: " << R->val << ", Brand Name: " << R->getName() << endl;
    generateBrand((NewRBNode*) R->getRightPointer(), outfile);
}

string NewRBNode::getBrandsForClient(NewRBNode *R, string &concat) {
    if (R == nullptr){
        return concat;
    } else {
        concat = getBrandsForClient((NewRBNode*) R->getLeftPointer(), concat);
        concat += "Brand Code: " + to_string(R->val) + ", Brand Name: " + R->getName() + ", Amount: " + to_string(R->getAmount()) + "\n";
        concat = getBrandsForClient((NewRBNode*) R->getRightPointer(), concat);
    }
    return concat;
}