#pragma once

class BaseBinaryNode {
protected:
    explicit BaseBinaryNode(int data){
        this->leftPointer = nullptr;
        this->rightPointer = nullptr;
        this->data = data;
    }

    BaseBinaryNode *getLeftPointer() const {
        return leftPointer;
    }
    BaseBinaryNode *getRightPointer() const {
        return rightPointer;
    }
    void setLeftPointer(BaseBinaryNode *newLeftPointer) {
        BaseBinaryNode::leftPointer = newLeftPointer;
    }
    void setRightPointer(BaseBinaryNode *newRightPointer) {
        BaseBinaryNode::rightPointer = newRightPointer;
    }
    void setData(int newData) {
        BaseBinaryNode::data = newData;
    }
    int getData() const {
        return data;
    }

private:
    BaseBinaryNode *leftPointer;
    BaseBinaryNode *rightPointer;
    int data;
};
