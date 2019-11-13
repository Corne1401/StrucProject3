#include "socketServer.h"
#include "globalTrees.h"
#include "helpers/stringSpliter.h"
#include <iostream>

using namespace std;

socketServer::socketServer(QObject *parent) : QTcpSocket(parent){
    QThreadPool :: globalInstance()->setMaxThreadCount(5);
}

void socketServer::setServer(qintptr handle){
    socket = new QTcpSocket(this);

    connect(socket,SIGNAL(connected()), this,SLOT(connected()));
    connect(socket,SIGNAL(disconnected()), this,SLOT(disconnected()));
    connect(socket,SIGNAL(readyRead()), this,SLOT(readyRead()));

    socket->setSocketDescriptor(handle);
}

void socketServer::connected(){

}

void socketServer::disconnected(){
    qDebug()<<"Connection ended"<<endl;
}

void socketServer::readyRead(){
    QByteArray data = socket->readAll();
    string dataToStr = data.toStdString();

    vector<string> holder = helpers.split(dataToStr, ";");


    if(holder[0]=="01"){ //validate Admin
        if(modules.validateAdmin(admins, holder[1])){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }

    }
    else if(holder[0]=="02"){ //validate Client
        if(modules.validateClient(clients, holder[1])){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="03"){ //Send Aisles
        socket->write(QByteArray::fromStdString(holder[0]+";"+modules.getAisles(aisles)));
    }
    else if(holder[0]=="04"){ //Send Products
        //holder[1]=prodCode
        socket->write(QByteArray::fromStdString(holder[0]+";"+modules.getProductsByAisleCode(aisles, holder[1])));
    }
    else if(holder[0]=="05") { //Send Brands
        //holder[1]=prodCode
        //holder[2]=brandCode
        socket->write(QByteArray::fromStdString(holder[0]+";"+modules.getBrandsByAisleProdCode(aisles, holder[1], holder[2])));
    }
    else if(holder[0]=="06"){//Send Clients
        socket->write(QByteArray::fromStdString(holder[0]+";"+modules.getClients(clients)));
    }
    else if(holder[0]=="07"){//Send Admins
        socket->write(QByteArray::fromStdString(holder[0]+";"+modules.getAdmins(admins)));
    }
    else if(holder[0]=="08"){//Insert Aisle
        //holder[1]==newAisleCode
        //holder[2]==newAisleName
        if(modules.insertAisle(aisles, holder[1], holder[2])){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="09"){//Insert Product
        //holder[1]==aisleCode
        //holder[2]==newProdCode
        //holder[3]==newProdName
        if(modules.insertProduct(aisles, holder[1], holder[2], holder[3])){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="10"){//Insert Brand
        //holder[1]==aisleCode
        //holder[2]==prodCode
        //holder[3]==newBrandCode
        //holder[4]==newBrandName
        //holder[5]==amount
        //holder[6]==price
        if(modules.insertBrand(aisles, holder[1], holder[2], holder[3], holder[4], holder[5], holder[6])){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="11"){//Insert Client
        //holder[1]==clientId
        //holder[2]==name
        //holder[3]==email
        //holder[4]==cityCode
        //holder[5]==phoneNumber
        if(modules.insertClient(clients, holder[1], holder[2], holder[3], holder[4], holder[5])){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="12"){//Update Price
        //holder[1]==aisleCode
        //holder[2]==prodCode
        //holder[3]==brandCode
        //holder[4]==price
        if(modules.updatePrice(aisles, holder[1], holder[2], holder[3], holder[4])){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="13"){//Update Tax Rate
        //holder[1]==taxRate
        if(modules.updateBasicProdTaxRate(holder[1])){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="14"){//Update Tax Rate
        //holder[1]==taxRate
        if(modules.updateNormalProdTaxRate(holder[1])){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="15"){//Update Basic Status
        //holder[1]==aisleCode
        //holder[2]==prodCode
        //holder[3]==brandCode
        //holder[4]==status
        if(modules.updateProoductStatus(aisles, inventory, holder[1], holder[2], holder[3], holder[4])){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="16"){//Delete Aisle
        //holder[1]==aisleCode
        if(modules.deleteAisle(aisles, holder[1])){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="17"){//Delete Prod
        //holder[1]==aisleCode
        //holder[2]==prodCode
        if(modules.deleteProduct(aisles, holder[1], holder[2])){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="18"){//Delete Brand
        //holder[1]==aisleCode
        //holder[2]==prodCode
        //holder[3]==brandCode
        if(modules.deleteBrand(aisles, holder[1], holder[2], holder[3])){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="19"){//Delete Client
        //holder[1]==clientId
        if(modules.deleteClient(clients, holder[1])){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="20"){//Get Price
        //holder[1]==aisleCode
        //holder[2]==prodCode
        //holder[3]==brandCode
        socket->write(QByteArray::fromStdString(holder[0]+";"+modules.getPriceByAisleProdBrandCode(aisles, holder[1], holder[2], holder[3])));
    }
    else if(holder[0]=="21"){ //Get isBasic
        //holder[1]==aisleCode
        //holder[2]==prodCode
        //holder[3]==brandCode
        if(modules.isBasicProd(aisles, inventory, holder[1], holder[2], holder[3])){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="22"){ //Get taxRate
        //holder[1]==aisleCode
        //holder[2]==prodCode
        //holder[3]==brandCode
        socket->write(QByteArray::fromStdString(holder[0]+";"+modules.getTaxByAisleProdBrandCode(inventory, holder[1], holder[2], holder[3])));
    }
    else if(holder[0]=="23"){ //Bill
        if(modules.bill(aisles, clientsQ,clients,inventory,sales)){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="24"){ //Check Gondolas
        //holder[1]==reStock
        if(modules.checkGondolas(inventory, sales, aisles, holder[1])){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="25"){ //Check Inventory
        modules.reloadInventory(inventory,helpers);
    }
    else if(holder[0]=="26"){ //Prim Graph
        socket->write(QByteArray::fromStdString(holder[0]+";"+modules.getPrimAlgorithm(primGraph, pGraph)));
    }
    else if(holder[0]=="27"){ //Prim Weight
        socket->write(QByteArray::fromStdString(holder[0]+";"+modules.getPrimWeight(primGraph)));
    }
    else if(holder[0]=="28"){ //Kusrkal Graph
        socket->write(QByteArray::fromStdString(holder[0]+";"+modules.getKurskalGraph(kruskalGraph)));
    }
    else if(holder[0]=="29"){ //Kusrkal Weight
        socket->write(QByteArray::fromStdString(holder[0]+";"+modules.getKurskalWeight(kruskalGraph)));
    }
    else if(holder[0]=="30"){ //Dijktra Graph
        socket->write(QByteArray::fromStdString(holder[0]+";"+modules.getDijkstraGraph(dijkstraGraph, dijkstraAdjList, holder[1], holder[2])));
    }
    else if(holder[0]=="31"){ //Dijktra Distance
        socket->write(QByteArray::fromStdString(holder[0]+";"+modules.getDijkstraDistance(dijkstraGraph)));
    }
    else if(holder[0]=="32"){ //Get Articulation Points
        socket->write(QByteArray::fromStdString(holder[0]+";"+modules.getArticulationPoints(articulationPointGraph)));
    }
    else if(holder[0]=="33"){ //Get Depth First Search (profundidad)
        //TODO
    }
    else if(holder[0]=="34"){ //Get Breadth First Search (anchura)
        //TODO
    }
    else if(holder[0]=="35"){ //Execute Purchase
        if(modules.executePurchase(clients, clientsQ, aisles, holder[1], holder[2], holder[3], holder[4], holder[5])){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="36"){ //mostVisitedAisle
        if(aisles.generateMostVisitedAisleReport(PATH_TO_REPORTS+"mostVisitedAisle.txt")){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="37"){ //leastVisitedAisle
        if(aisles.generateLeastVisitedAisleReport(PATH_TO_REPORTS+"leastVisitedAisle.txt")){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="38"){ //mostProductsPerAisle
        //holder[1]==aisleCode
        if(modules.mostProductPerAisle(PATH_TO_REPORTS+"mostProductsPerAisle.txt", aisles, holder[1])){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="39"){ //mostSoldBrand
        if(sales.generateMostSoldBrands(PATH_TO_REPORTS+"mostSoldBrand.txt")){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="40"){ //mostExpensiveBill && ClientWhoBoughtTheMost
        if(clients.generateMostExpensiveBill(PATH_TO_REPORTS+"mostExpensiveBill(ClientWhoBoughtTheMost).txt")){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="41"){ //clientWhoBoughtTheLeast
        if(clients.generateLeastExpensiveBill(PATH_TO_REPORTS+"clientWhoBoughtTheLeast.txt")){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="42"){ //mostBilledClient
        if(clients.generateMostBilledClient(PATH_TO_REPORTS+"mostBilledClient.txt")){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="43"){ //mostBilledClient
        if(clients.generateLeastBilledClient(PATH_TO_REPORTS+"leastBilledClient.txt")){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="44"){ //aislesList
        if(aisles.generateAisles(PATH_TO_REPORTS+"aislesList.txt")){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="45"){ //productsList
        //holder[1]==aisleCode
        if(modules.generateProductsReport(PATH_TO_REPORTS+"productsList.txt", aisles, holder[1])){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="46"){ //brandsList
        //holder[1]==aisleCode
        //holder[2]==prodCode
        if(modules.generateBrandsReport(PATH_TO_REPORTS+"brandsList.txt", aisles, holder[1], holder[2])){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="47"){ //clientsList
        if(clients.generateClients(PATH_TO_REPORTS+"clientsList.txt")){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="48"){ //inventoryList
        if(inventory.generateInventory(PATH_TO_REPORTS+"clientsList.txt")){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
    else if(holder[0]=="49"){ //GENERATE ALL REPORTS
        //holder[1]==aisleCode
        //holder[2]==prodCode
        if(aisles.generateMostVisitedAisleReport(PATH_TO_REPORTS+"mostVisitedAisle.txt")
                && aisles.generateLeastVisitedAisleReport(PATH_TO_REPORTS+"leastVisitedAisle.txt")
                && modules.mostProductPerAisle(PATH_TO_REPORTS+"mostProductsPerAisle.txt", aisles, holder[1])
                && sales.generateMostSoldBrands(PATH_TO_REPORTS+"mostSoldBrand.txt")
                && clients.generateMostExpensiveBill(PATH_TO_REPORTS+"mostExpensiveBill(ClientWhoBoughtTheMost).txt")
                && clients.generateLeastExpensiveBill(PATH_TO_REPORTS+"clientWhoBoughtTheLeast.txt")
                && clients.generateMostBilledClient(PATH_TO_REPORTS+"mostBilledClient.txt")
                && clients.generateLeastBilledClient(PATH_TO_REPORTS+"leastBilledClient.txt")
                && aisles.generateAisles(PATH_TO_REPORTS+"aislesList.txt")
                && modules.generateProductsReport(PATH_TO_REPORTS+"productsList.txt", aisles, holder[1])
                && modules.generateBrandsReport(PATH_TO_REPORTS+"brandsList.txt", aisles, holder[1], holder[2])
                && clients.generateClients(PATH_TO_REPORTS+"clientsList.txt")
                && inventory.generateInventory(PATH_TO_REPORTS+"clientsList.txt")){
            socket->write(QByteArray::fromStdString(holder[0]+";1"));
        } else {
            socket->write(QByteArray::fromStdString(holder[0]+";0"));
        }
    }
}
