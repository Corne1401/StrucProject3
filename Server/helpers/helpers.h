#pragma once

#include <fstream>
#include "../TreesHandlers/BinarySearchTree.h"
#include "../TreesHandlers/BTreeClients.h"
#include "../TreesHandlers/BTreeAdmins.h"
#include "../TreesHandlers/AATree.h"
#include "citiesList.h"
#include "PrimGraph.h"
#include "Kruskal.h"
#include "Dijkstra.h"
#include "ArticulationPoints.h"


using namespace std;
class helper{
public:

    string PATH_TO_FILES = "C:\\GitHub_Projects\\StrucProject3\\Server\\data\\";

    explicit helper(){}

    /**
     * Splits file contents into formats to be inserted in doubleListAisle list
     * @param aisles Is the given list object where to be inserted
     * @param fullString Is the txt full line string to be segmented
     * @param delimiter Is the character to be used as cut of string
     * **/
    void splitIntoAisleTree(BinarySearchTree &aisles, const string& fullString, char delimiter){

        string data1;
        string data2;
        int dataCount = 0;
        for (auto x : fullString) {
            switch (dataCount) {
                case 0:
                    if (x == delimiter) {
                        //cout << data1 << endl;
                        dataCount++;
                    } else {
                        data1 += x;
                    }
                    break;
                case 1:
                    if (x == delimiter) {
                        //cout << data2 << endl;
                        dataCount++;
                    } else {
                        data2 += x;
                    }
                    break;
                default:
                    dataCount = 0;
                    data1 = "";
                    data2 = "";
                    break;
            }
        }
        try {

            int data1Num = stoi(data1);
            if (!aisles.isAisleCodeInTree(data1Num)) {
                aisles.insert(new BSNode(data1Num, data2));
            }

        }catch (std::invalid_argument& e) {
            cout << "******************************************************************************************************" << endl;
            cout << "Number values could not be converted to integer for ids: " << data1 << endl;
            cout << "******************************************************************************************************" << endl;
        }

    }

    /**
     *
     * Splits file contents into formats to be inserted in doubleListAisle list
     * @param aislesProds Is the given list object where to be inserted
     * @param fullString Is the txt full line string to be segmented
     * @param delimiter Is the character to be used as cut of string
     *
     * **/
    void splitIntoListAisleProduct(BinarySearchTree &aislesProds, const string& fullString, char delimiter){
        string data1;
        string data2;
        string data3;
        int dataCount = 0;
        for (auto x : fullString){
            switch(dataCount){
                case 0:
                    if(x==delimiter){
                        //cout << data1 << endl;
                        dataCount++;
                    } else {
                        data1+=x;
                    }
                    break;
                case 1:
                    if(x==delimiter){
                        //cout << data2 << endl;
                        dataCount++;
                    } else {
                        data2+=x;
                    }
                    break;
                case 2:
                    if(x==delimiter){
                        //cout << data3 << endl;
                        dataCount++;
                    } else {
                        data3+=x;
                    }
                    break;
                default:
                    dataCount=0;
                    data1 = "";
                    data2 = "";
                    data3 = "";
                    break;
            }
        }

        try{
            int data1Int = stoi(data1);
            int data2Int = stoi(data2);
            if(aislesProds.isAisleCodeInTree(data1Int)){
                //If aisle code does exists then proceed
                BSNode *aisleNode = aislesProds.getNodeByAisleCode(data1Int);
                if(aisleNode->getProductAisleTreePointer() == nullptr){
                    aisleNode->setProductAisleTreePointer(new NewAVLTree());
                    aisleNode->getProductAisleTreePointer()->insert(data2Int, data3);

                } else {
                    if(!aisleNode->getProductAisleTreePointer()->isProdCodeOnTree(data2Int)){
                        aisleNode->getProductAisleTreePointer()->insert(data2Int, data3);
                    }
                }
            }
        }catch (std::invalid_argument& e) {
            cout << "******************************************************************************************************" << endl;
            cout << "Number values could not be converted to integer for ids: " << data1 << data2 << endl;
            cout << "******************************************************************************************************" << endl;
        }

    }

    /**
     * Splits file contents into formats to be inserted in doubleListAisle list
     * @param aisles Is the given list object where to be inserted
     * @param fullString Is the txt full line string to be segmented
     * @param delimiter Is the character to be used as cut of string
     * **/
    void splitIntoListAisleProductBrand(BinarySearchTree &aisles, const string& fullString, char delimiter){
        string data1;
        string data2;
        string data3;
        string data4;
        string data5;
        string data6;
        int dataCount = 0;
        for (auto x : fullString){
            switch(dataCount){
                case 0:
                    if(x==delimiter){
                        //cout << data1 << endl;
                        dataCount++;
                    } else {
                        data1+=x;
                    }
                    break;
                case 1:
                    if(x==delimiter){
                        //cout << data2 << endl;
                        dataCount++;
                    } else {
                        data2+=x;
                    }
                    break;
                case 2:
                    if(x==delimiter){
                        //cout << data3 << endl;
                        dataCount++;
                    } else {
                        data3+=x;
                    }
                    break;
                case 3:
                    if(x==delimiter){
                        //cout << data3 << endl;
                        dataCount++;
                    } else {
                        data4+=x;
                    }
                    break;
                case 4:
                    if(x==delimiter){
                        //cout << data3 << endl;
                        dataCount++;
                    } else {
                        data5+=x;
                    }
                    break;
                case 5:
                    if(x==delimiter){
                        //cout << data3 << endl;
                        dataCount++;
                    } else {
                        data6+=x;
                    }
                    break;
                default:
                    dataCount=0;
                    data1 = "";
                    data2 = "";
                    data3 = "";
                    data4 = "";
                    data5 = "";
                    data6 = "";
                    break;
            }
        }
        try{
            int data1Num = stoi(data1);
            int data2Num = stoi(data2);
            int data3Num = stoi(data3);
            int data5Num = stoi(data5);
            int data6Num = stoi(data6);



            if(aisles.isAisleCodeInTree(data1Num)){
                //If aisle code does exists then proceed

                BSNode *aisleNode = aisles.getNodeByAisleCode(data1Num);
                if(aisleNode->getProductAisleTreePointer()->isProdCodeOnTree(data2Num)){
                    NewAVLNode *prodNode = aisleNode->getProductAisleTreePointer()->getNodeByProdCode(data2Num);

                    if(prodNode->getProductAisleBrandTreePointer() == nullptr){
                        prodNode->setProductAisleBrandTreePointer(new NewRBTree);
                        prodNode->getProductAisleBrandTreePointer()->insert(data3Num, data4, data5Num, data6Num);

                    } else {
                        if (!prodNode->getProductAisleBrandTreePointer()->isBrandCodeOnList(data3Num)){
                            prodNode->getProductAisleBrandTreePointer()->insert(data3Num, data4, data5Num, data6Num);
                        }
                    }

                }

            }

        } catch(std::invalid_argument& e){
            cout << "******************************************************************************************************" << endl;
            cout << "Number values could not be converted to integer for ids: " << data1 << ";" << data2 << ";" << data3 << endl;
            cout << "Provided numbers are: " << data4 << " and " << data5 << endl;
            cout << "******************************************************************************************************" << endl;
        }
    }

    /**
     * Splits file contents into formats to be inserted in clientList list
     * @param clients is the clientList object where to insert
     * @param fullString is the string with the data to be segmented
     * @param delimiter Is the character to be used as cut of string
     * **/
    void splitIntoClients(BTreeClients &clients, const string& fullString, char delimiter){
        string data1;
        string data2;
        string data3;
        string data4;
        string data5;
        int dataCount = 0;
        for (auto x : fullString){
            switch(dataCount){
                case 0:
                    if(x==delimiter){
                        //cout << data1 << endl;
                        dataCount++;
                    } else {
                        data1+=x;
                    }
                    break;
                case 1:
                    if(x==delimiter){
                        //cout << data2 << endl;
                        dataCount++;
                    } else {
                        data2+=x;
                    }
                    break;
                case 2:
                    if(x==delimiter){
                        //cout << data3 << endl;
                        dataCount++;
                    } else {
                        data3+=x;
                    }
                    break;
                case 3:
                    if(x==delimiter){
                        //cout << data3 << endl;
                        dataCount++;
                    } else {
                        data4+=x;
                    }
                    break;
                case 4:
                    if(x==delimiter){
                        //cout << data3 << endl;
                        dataCount++;
                    } else {
                        data5+=x;
                    }
                    break;
                default:
                    dataCount=0;
                    data1 = "";
                    data2 = "";
                    data3 = "";
                    data4 = "";
                    data5 = "";
                    break;
            }
        }
        try {
            int data1Num = stoi(data1);
            if(clients.search(data1Num) == nullptr){
                //If client ID is NOT repeated, the insert
                clients.insert(data1Num, ClientData(data2, data3, data4, data5));
            }
        } catch (std::invalid_argument& e){
            cout << "******************************************************************************************************" << endl;
            cout << "Number values could not be converted to integer for ids: " << data1 << ";" << data2 << ";" << data3 << ";" << data4 << endl;
            cout << "Provided numbers are: " << data1<< endl;
            cout << "******************************************************************************************************" << endl;
        }
    }

    /**
     * Splits file contents into formats to be inserted in clientList list
     * @param admins is the clientList object where to insert
     * @param fullString is the string with the data to be segmented
     * @param delimiter Is the character to be used as cut of string
     * **/
    void splitIntoAdmins(BTreeAdmins &admins, const string& fullString, char delimiter){
        string data1;
        string data2;
        int dataCount = 0;
        for (auto x : fullString){
            switch(dataCount){
                case 0:
                    if(x==delimiter){
                        //cout << data1 << endl;
                        dataCount++;
                    } else {
                        data1+=x;
                    }
                    break;
                case 1:
                    if(x==delimiter){
                        //cout << data2 << endl;
                        dataCount++;
                    } else {
                        data2+=x;
                    }
                    break;
                default:
                    dataCount=0;
                    data1 = "";
                    data2 = "";
                    break;
            }
        }
        try {
            int data1Num = stoi(data1);
            if(admins.search(data1Num) == nullptr){
                //If client ID is NOT repeated, the insert
                admins.insert(data1Num, AdminData(data2));
            }
        } catch (std::invalid_argument& e){
            cout << "******************************************************************************************************" << endl;
            cout << "Number values could not be converted to integer for ids: " << data1 << ";" << data2 << endl;
            cout << "Provided numbers are: " << data1<< endl;
            cout << "******************************************************************************************************" << endl;
        }

    }

    /**
     * Splits file contents into formats to be inserted in clientList list
     * @param inventory is the clientList object where to insert
     * @param fullString is the string with the data to be segmented
     * @param delimiter Is the character to be used as cut of string
     * **/
    void splitIntoInventory(AATree &inventory, const string& fullString, char delimiter){
        string data1;
        string data2;
        string data3;
        string data4;
        string data5;
        string data6;
        int dataCount = 0;
        for (auto x : fullString){
            switch(dataCount){
                case 0:
                    if(x==delimiter){
                        //cout << data1 << endl;
                        dataCount++;
                    } else {
                        data1+=x;
                    }
                    break;
                case 1:
                    if(x==delimiter){
                        //cout << data2 << endl;
                        dataCount++;
                    } else {
                        data2+=x;
                    }
                    break;
                case 2:
                    if(x==delimiter){
                        //cout << data3 << endl;
                        dataCount++;
                    } else {
                        data3+=x;
                    }
                    break;
                case 3:
                    if(x==delimiter){
                        //cout << data3 << endl;
                        dataCount++;
                    } else {
                        data4+=x;
                    }
                    break;
                case 4:
                    if(x==delimiter){
                        //cout << data3 << endl;
                        dataCount++;
                    } else {
                        data5+=x;
                    }
                    break;
                case 5:
                    if(x==delimiter){
                        //cout << data3 << endl;
                        dataCount++;
                    } else {
                        data6+=x;
                    }
                    break;
                default:
                    dataCount=0;
                    data1 = "";
                    data2 = "";
                    data3 = "";
                    data4 = "";
                    data5 = "";
                    data6 = "";
                    break;
            }
        }
        try{
            int data1Num = stoi(data1);
            int data2Num = stoi(data2);
            int data3Num = stoi(data3);
            int data5Num = stoi(data5);
            int data6Num = stoi(data6);

            if (!inventory.isDataPresent(data1+data2+data3)){
                inventory.lookup(new AANode(data1+data2+data3, data1Num, data2Num, data3Num, data5Num, data6Num, data4));
            }

        } catch (std::invalid_argument& e){
            cout << "******************************************************************************************************" << endl;
            cout << "Number values could not be converted to integer for ids: " << data1 << ";" << data2 << ";" << data3 << ";" << data4 << ";" << data5 << ";" << data6 << endl;
            cout << "Provided numbers are: " << data1 << ";" << data2 << ";" << data3 << ";" << data5 << ";" << data6 << endl;
            cout << "******************************************************************************************************" << endl;
        }
    }

    void splitIntoCitiesList(citiesList &cities, const string& fullString, char delimiter) {
        string data1;
        string data2;
        string data3;
        string data4;
        string data5;
        string data6;
        int dataCount = 0;
        for (auto x : fullString){
            switch(dataCount){
                case 0:
                    if(x==delimiter || x==':'){
                        //cout << data1 << endl;
                        dataCount++;
                    } else {
                        data1+=x;
                    }
                    break;
                case 1:
                    if(x==delimiter || x==':'){
                        //cout << data2 << endl;
                        dataCount++;
                    } else {
                        data2+=x;
                    }
                    break;
                default:
                    dataCount=0;
                    data1 = "";
                    data2 = "";
            }
        }
        if (!cities.isElementInList(data1)){
            cities.appendAtEnd(new citiesNode(data1, data2));
        }


    }

    /**
     * Initializes a list with values from file
     * @param aisles By reference. Is the list to be initiliazed
     * **/
    void initAisleTree(BinarySearchTree &aisles){
        string line;
        ifstream arch1(PATH_TO_FILES+"Pasillos.txt");

        while (getline(arch1, line)) {
            if(!line.empty()){
                splitIntoAisleTree(aisles, line, ';');
            }
        }
        arch1.close();
    }


    /**
     * Initializes a list with values from file
     * @param aisles By reference. Is the list to be initiliazed
     * **/
    void initCitiesList(citiesList &cities){
        string line;
        ifstream arch1(PATH_TO_FILES+"Ciudades.txt");

        while (getline(arch1, line)) {
            if(!line.empty()){
                splitIntoCitiesList(cities, line, ';');
            }
        }
        arch1.close();
    }



    /**
     * Initializes a list with values from file
     * @param aisleList is the aisleList value to check for IDs
     * **/
    void initAislesProductTree(BinarySearchTree &aisles){
        string line;
        ifstream arch1(PATH_TO_FILES+"ProductosPasillos.txt");

        while (getline(arch1, line)) {
            if(!line.empty()){
                splitIntoListAisleProduct(aisles, line, ';');
            }
        }
        arch1.close();

    }

    /**
     * Initializes a list with values from file
     * @param aisles is the aisleList value to check for IDs
     * **/
    void initAislesProductBrandTree(BinarySearchTree &aisles){
        string line;
        ifstream arch1(PATH_TO_FILES+"MarcasProductos.txt");

        while (getline(arch1, line)) {
            if(!line.empty()){
                splitIntoListAisleProductBrand(aisles, line, ';');
            }
        }
        arch1.close();
    }

    /**
     * Initializes a list with values from file
     * @param clients is the clientList value to check for IDs
     * **/
    void initClients(BTreeClients &clients){
        string line;
        ifstream arch1(PATH_TO_FILES+"Clientes.txt");

        while (getline(arch1, line)) {
            if(!line.empty()){
                splitIntoClients(clients, line, ';');
            }
        }
        arch1.close();
    }

    /**
     * Initializes a list with values from file
     * @param admins is the clientList value to check for IDs
     * **/
    void initAdmins(BTreeAdmins &admins){
        string line;
        ifstream arch1(PATH_TO_FILES+"Administradores.txt");

        while (getline(arch1, line)) {
            if(!line.empty()){
                splitIntoAdmins(admins, line, ';');
            }
        }
        arch1.close();
    }

    /**
     * Initializes a list with values from file
     * @param inventory is the clientList value to check for IDs
     * **/
    void initInventory(AATree &inventory){
        string line;
        ifstream arch1(PATH_TO_FILES+"Inventario.txt");

        while (getline(arch1, line)) {
            if(!line.empty()){
                splitIntoInventory(inventory, line, ';');
            }
        }
        arch1.close();
    }



    void test(citiesList &city){
        city.appendAtEnd(new citiesNode("Hola", "Mundo"));
    }


    int** create2DArray(unsigned height, unsigned width){
        int** array2D = 0;
        array2D = new int*[height];

        for (int h = 0; h < height; h++)
        {
            array2D[h] = new int[width];

            for (int w = 0; w < width; w++){
                // fill in some initial values
                // (filling in zeros would be more logic, but this is just for the example)
                array2D[h][w] = 0;
            }
        }
        return array2D;
    }


    int determineConnectionsNodes(citiesList &helperCitiesList, class citiesList &citiesList, const string& file){
        string line;
        ifstream arch1(PATH_TO_FILES+file+".txt");

        while (getline(arch1, line)) {
            if(!line.empty()){
                string data1;
                string data2;
                string data3;
                int dataCount = 0;
                for (auto x : line){
                    switch(dataCount){
                        case 0:
                            if(x==';' || x==':'){
                                //cout << data1 << endl;
                                dataCount++;
                            } else {
                                data1+=x;
                            }
                            break;
                        case 1:
                            if(x==';' || x==':'){
                                //cout << data2 << endl;
                                dataCount++;
                            } else {
                                data2+=x;
                            }
                            break;
                        case 2:
                            if(x==';' || x==':'){
                                //cout << data2 << endl;
                                dataCount++;
                            } else {
                                data3+=x;
                            }
                            break;
                        default:
                            dataCount=0;
                            data1 = "";
                            data2 = "";
                            data3 = "";
                            break;
                    }
                }
                try{
                    if(citiesList.isElementInList(data1)){
                        if(!helperCitiesList.isElementInList(data1)){
                            helperCitiesList.appendAtEnd(new citiesNode(data1, ""));
                        }
                    }

                    if(citiesList.isElementInList(data2)){
                        if(!helperCitiesList.isElementInList(data2)){
                            helperCitiesList.appendAtEnd(new citiesNode(data2, ""));
                        }
                    }
                } catch (invalid_argument &e){
                    cout << e.what() << endl;
                }
            }
        }
        arch1.close();
        //cout << helperCitiesList.listSize() << endl;
        return helperCitiesList.listSize();
    }


    /**
     * Initializes a list with values from file
     * @param citiesList is the clientList value to check for IDs
     * **/
    void initGraph(citiesList &citiesList, PrimGraph::Graph* &graph, PrimGraph &primGraph, class citiesList &connectionsList, struct KruskalGraph &g, vector<vector<neighbor>> &dijkstraAdjList){
        map<int, int> citiesMap;
        map<int, int> indexToCity;
        class citiesList list2;

        connectionsList.setAux(connectionsList.getFirstNode());
        int count = 0;
        while (connectionsList.getAux()!= nullptr){
            int cityCode = stoi(connectionsList.getAux()->getCityCode());
            citiesMap.insert(make_pair<int,int>(reinterpret_cast<int &&>(cityCode), reinterpret_cast<int &&>(count)));
            indexToCity.insert(make_pair<int,int>(reinterpret_cast<int &&>(count), reinterpret_cast<int &&>(cityCode)));
            connectionsList.next();
            count++;
        }
        //cout << "Cities Map: " << endl;
        //cout << indexToCity.at(16) << endl;
        //cout << citiesMap.size() << endl;

        string line;
        ifstream arch1(PATH_TO_FILES+"Conexiones.txt");

        while (getline(arch1, line)) {
            if(!line.empty()){


                string data1;
                string data2;
                string data3;
                int dataCount = 0;
                for (auto x : line){
                    switch(dataCount){
                        case 0:
                            if(x==';' || x==':'){
                                //cout << data1 << endl;
                                dataCount++;
                            } else {
                                data1+=x;
                            }
                            break;
                        case 1:
                            if(x==';' || x==':'){
                                //cout << data2 << endl;
                                dataCount++;
                            } else {
                                data2+=x;
                            }
                            break;
                        case 2:
                            if(x==';' || x==':'){
                                //cout << data2 << endl;
                                dataCount++;
                            } else {
                                data3+=x;
                            }
                            break;
                        default:
                            dataCount=0;
                            data1 = "";
                            data2 = "";
                            data3 = "";
                            break;
                    }
                }
                try{
                    if(list2.isElementInList(data1)){
                        if(list2.getElementInList(data1)->getCityName()!=data2){
                            if(citiesList.isElementInList(data1) && citiesList.isElementInList(data2)){
                                //cout << citiesMap.at(stoi(data1)) << ", " << citiesMap.at(stoi(data2)) << ", " << data3 << endl;
                                primGraph.addEdge(graph, citiesMap.at(stoi(data1)), citiesMap.at(stoi(data2)), stoi(data3));
                                g.addEdge(citiesMap.at(stoi(data1)), citiesMap.at(stoi(data2)), stoi(data3));
                                // remember to insert edges both ways for an undirected graph dijkstra
                                dijkstraAdjList[citiesMap.at(stoi(data1))].push_back(neighbor(citiesMap.at(stoi(data2)), stoi(data3)));
                                dijkstraAdjList[citiesMap.at(stoi(data2))].push_back(neighbor(citiesMap.at(stoi(data1)), stoi(data3)));
                                list2.appendAtEnd(new citiesNode(data1, data2));
                            }
                        }
                    } else {
                        if(citiesList.isElementInList(data1) && citiesList.isElementInList(data2)){
                            //cout << citiesMap.at(stoi(data1)) << ", " << citiesMap.at(stoi(data2)) << ", " << data3 << endl;
                            primGraph.addEdge(graph, citiesMap.at(stoi(data1)), citiesMap.at(stoi(data2)), stoi(data3));
                            g.addEdge(citiesMap.at(stoi(data1)), citiesMap.at(stoi(data2)), stoi(data3));
                            // remember to insert edges both ways for an undirected graph dijkstra
                            dijkstraAdjList[citiesMap.at(stoi(data1))].push_back(neighbor(citiesMap.at(stoi(data2)), stoi(data3)));
                            dijkstraAdjList[citiesMap.at(stoi(data2))].push_back(neighbor(citiesMap.at(stoi(data1)), stoi(data3)));
                            list2.appendAtEnd(new citiesNode(data1, data2));
                        }
                    }


                } catch (invalid_argument &e){
                    cout << e.what() << endl;
                }
            }
        }
        arch1.close();
        //cout << list2.listSize() << endl;
    }

    /**
     * Initializes a list with values from file
     * @param citiesList is the clientList value to check for IDs
     * **/
    void initArticulationPoints(citiesList &citiesList, class citiesList &connectionsList, ArticulationPointGraph &g1){
        map<int, int> citiesMap;
        map<int, int> indexToCity;
        class citiesList list2;

        connectionsList.setAux(connectionsList.getFirstNode());
        int count = 0;
        while (connectionsList.getAux()!= nullptr){
            int cityCode = stoi(connectionsList.getAux()->getCityCode());
            citiesMap.insert(make_pair<int,int>(reinterpret_cast<int &&>(cityCode), reinterpret_cast<int &&>(count)));
            indexToCity.insert(make_pair<int,int>(reinterpret_cast<int &&>(count), reinterpret_cast<int &&>(cityCode)));
            connectionsList.next();
            count++;
        }
        //cout << "Cities Map: " << endl;
        //cout << indexToCity.at(16) << endl;

        string line;
        ifstream arch1(PATH_TO_FILES+"Ptos de articulacion.txt");

        while (getline(arch1, line)) {
            if(!line.empty()){


                string data1;
                string data2;
                string data3;
                int dataCount = 0;
                for (auto x : line){
                    switch(dataCount){
                        case 0:
                            if(x==';' || x==':'){
                                //cout << data1 << endl;
                                dataCount++;
                            } else {
                                data1+=x;
                            }
                            break;
                        case 1:
                            if(x==';' || x==':'){
                                //cout << data2 << endl;
                                dataCount++;
                            } else {
                                data2+=x;
                            }
                            break;
                        case 2:
                            if(x==';' || x==':'){
                                //cout << data2 << endl;
                                dataCount++;
                            } else {
                                data3+=x;
                            }
                            break;
                        default:
                            dataCount=0;
                            data1 = "";
                            data2 = "";
                            data3 = "";
                            break;
                    }
                }
                try{
                    if(list2.isElementInList(data1)){
                        if(list2.getElementInList(data1)->getCityName()!=data2){
                            if(citiesList.isElementInList(data1) && citiesList.isElementInList(data2)){
                                cout << citiesMap.at(stoi(data1)) << ", " << citiesMap.at(stoi(data2)) << ", " << data3 << endl;
                                g1.addEd(citiesMap.at(stoi(data1)), citiesMap.at(stoi(data2)));
                                list2.appendAtEnd(new citiesNode(data1, data2));
                            }
                        }
                    } else {
                        if(citiesList.isElementInList(data1) && citiesList.isElementInList(data2)){
                            cout << citiesMap.at(stoi(data1)) << ", " << citiesMap.at(stoi(data2)) << ", " << data3 << endl;
                            g1.addEd(citiesMap.at(stoi(data1)), citiesMap.at(stoi(data2)));
                            list2.appendAtEnd(new citiesNode(data1, data2));
                        }
                    }


                } catch (invalid_argument &e){
                    cout << e.what() << endl;
                }
            }
        }
        arch1.close();
        //cout << list2.listSize() << endl;
    }

    void reloadInventory(AATree &inventory) {
        //Restart values for inventory
        inventory.clear();
        initInventory(inventory);
        cout << "Inventory restock successful" << endl;
    }

    vector<string> split(string str, string token){
        vector<string>result;
        while(str.size()){
            int index = str.find(token);
            if(index!=string::npos){
                result.push_back(str.substr(0,index));
                str = str.substr(index+token.size());
                if(str.size()==0)result.push_back(str);
            }else{
                result.push_back(str);
                str = "";
            }
        }
        return result;
    }

};
