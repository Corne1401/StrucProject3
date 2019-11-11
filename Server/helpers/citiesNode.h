#pragma once

#include <string>
#include <utility>

using namespace std;
class citiesNode {
public:
    explicit citiesNode(string cityCode, string cityName){
        this->cityCode = std::move(cityCode);
        this->cityName = std::move(cityName);
        this->nextNode = nullptr;
    }

    const string &getCityCode() const {
        return cityCode;
    }

    void setCityCode(const string &newCityCode) {
        citiesNode::cityCode = newCityCode;
    }

    const string &getCityName() const {
        return cityName;
    }

    void setCityName(const string &newCityName) {
        citiesNode::cityName = newCityName;
    }

    citiesNode *getNextNode() const {
        return nextNode;
    }

    void setNextNode(citiesNode *newNextNode) {
        citiesNode::nextNode = newNextNode;
    }

private:
    string cityCode;
    string cityName;
    citiesNode *nextNode;
};
