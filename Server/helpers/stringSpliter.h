#ifndef STRINGSPLITER_H
#define STRINGSPLITER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class node{
public:
    explicit node(string data){
        this->data = data;
        this->nextNode = nullptr;
        this->lastNode = nullptr;
    }
private:
    string data;
    node *nextNode;
    node *lastNode;
    friend class stringList;
};

class stringList{
public:
    stringList(){
        this->actual = nullptr;
        this->first = nullptr;
    }
    bool isEmpty(){
        return first==nullptr;
    }
    void insert(string data){
        if(isEmpty()){
            first = new node(data);
            first->nextNode = first;
            first->lastNode = first;
        }
        else {
            node *newNode = new node(data);
            newNode->lastNode = first->nextNode->lastNode;
            newNode->nextNode = first->lastNode->nextNode;
            first->lastNode->nextNode = newNode;
            first->lastNode = newNode;
        }
    }

    int len(){
        int counter=0;
        node *aux;
        aux = first;

        while (aux->nextNode != first){
            counter++;
        }
        counter++;
        return counter;
    }

    string getByIndex(int index){
            node *aux;
            aux = first;
            for (int counter = 0; counter < index; counter++) {
                aux = aux->nextNode;
            }
            return aux->data;
    }
    void print(){
        node *aux;
        aux = first;
        while(aux->nextNode!=first){
            cout<<aux->data<<"->";
            aux= aux->nextNode;
        }
        cout<<aux->data<<endl;
    }
private:
    node *actual;
    node *first;
};

stringList splitString(string delimiter, string phrase){

    stringList holder;
    size_t position = 0;
    string token;

    while ((position = phrase.find(delimiter)) != string::npos){
        token = phrase.substr(0, position);
        holder.insert(token);
        phrase.erase(0,position+delimiter.length());
    }
    holder.insert(phrase);
    return holder;
}


#endif // STRINGSPLITER_H
