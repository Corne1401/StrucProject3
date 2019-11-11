#pragma once

#include <string>
#include <utility>
#include "BaseBinaryNode.h"

using namespace std;
class AANode {
public:
    explicit AANode(string key, int aisleCode, int prodCode, int brandCode, int stockAmount, bool isBasicProd, const string& name){
        this->key = std::move(key);
        this->aisleCode = aisleCode;
        this->prodCode = prodCode;
        this->brandCode = brandCode;
        this->stockAmount = stockAmount;
        this->isBasicProd = isBasicProd;
        this->name = name;
        this->count = 0;
        this->level = 1;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;

    }

    int getCount() const {
        return count;
    }

    void setCount(int count) {
        AANode::count = count;
    }

    int getLevel() const {
        return level;
    }

    void setLevel(int level) {
        AANode::level = level;
    }

    string getKey() const {
        return key;
    }

    void setKey(int key) {
        AANode::key = key;
    }

    int getProdCode() const {
        return prodCode;
    }

    void setProdCode(int prodCode) {
        AANode::prodCode = prodCode;
    }

    int getBrandCode() const {
        return brandCode;
    }

    void setBrandCode(int brandCode) {
        AANode::brandCode = brandCode;
    }

    int getStockAmount() const {
        return stockAmount;
    }

    void setStockAmount(int stockAmount) {
        AANode::stockAmount = stockAmount;
    }

    bool getIsBasicProd() const {
        return isBasicProd;
    }

    void setIsBasicProd(bool isBasicProd) {
        AANode::isBasicProd = isBasicProd;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        AANode::name = name;
    }

    AANode *getRight() const {
        return right;
    }

    void setRight(AANode *right) {
        AANode::right = right;
    }

    AANode *getLeft() const {
        return left;
    }

    void setLeft(AANode *left) {
        AANode::left = left;
    }

    AANode *getParent() const {
        return parent;
    }

    void setParent(AANode *parent) {
        AANode::parent = parent;
    }

    static bool isCodeInTree(AANode *R, string i) {
        if (R == nullptr){
            return false;
        } else {
            if(R->getKey()==i){
                return true;
            } else{
                if (i>R->getKey()){
                    return isCodeInTree(R->getRight(), i);
                } else {
                    return isCodeInTree(R->getLeft(), i);
                }
            }
        }
    }

    void setKey(const string &key) {
        AANode::key = key;
    }

    static AANode *getNodeByAisleProdBrandCodeHelper(AANode *R, string i){
        if (R == nullptr){
            return R;
        } else {
            if(R->getKey()==i){
                return R;
            } else{
                if (i>R->getKey()){
                    return getNodeByAisleProdBrandCodeHelper(R->getRight(), i);
                } else {
                    return getNodeByAisleProdBrandCodeHelper(R->getLeft(), i);
                }
            }
        }
    }
    static bool isBasicProductHelper(AANode *R, string i) {
        return getNodeByAisleProdBrandCodeHelper(R, i)->getIsBasicProd();
    }


private:
    int count, level;
    string key;
    int aisleCode;
    int prodCode;
    int brandCode;
    int stockAmount;
    bool isBasicProd;
    string name;
    AANode *right;
    AANode *left;
    AANode *parent;
};
