#pragma once

#include "../TreesHandlers/BinarySearchTree.h"
#include "../TreesHandlers/BTreeClients.h"
#include "../helpers/clientQueue.h"
#include "../helpers/quickSortHelper.h"
#include "../helpers/salesList.h"
#include "../TreesHandlers/AATree.h"

#include <helpers/citiesList.h>
#include <helpers/helpers.h>

using namespace std;
class modules {
public:

    static bool checkEndOption(const string& endOp){
        return endOp == "Y" || endOp =="y" || endOp=="n" || endOp=="N";
    }

    static void buyModuleMainMenu(BTreeClients &clients, clientQueue &clientsQ, BinarySearchTree aisles) {
        try {
            cout << "Type your client ID" << endl;
            string clientId;
            cin >> clientId;

            if(!clientsQ.isClientIdInList(clientId)) {
                auto client = clients.searchClient(stoi(clientId));

                while (true){
                    string purchaseExitOp = "";
                    cout << "Please select an aisle (numeric code): " << endl;

                    //Prints aisles
                    aisles.printAisleForPurchase();

                    string chosenAisleString;
                    int chosenAisle;
                    cin >> chosenAisleString;
                    chosenAisle = stoi(chosenAisleString);

                    if (aisles.isAisleCodeInTree(chosenAisle)) {
                        auto *selectedAisle = aisles.getNodeByAisleCode(chosenAisle);
                        selectedAisle->incVisits();

                        if (selectedAisle->getProductAisleTreePointer() != nullptr) {
                            cout << "Please select a product for aisle (numeric code): " << selectedAisle->getName() << endl;

                            selectedAisle->getProductAisleTreePointer()->printProductsForPurchaseHelper(selectedAisle->getProductAisleTreePointer()->getAVLRoot());

                            string chosenProdString;
                            int chosenProd;
                            cin >> chosenProdString;
                            chosenProd = stoi(chosenProdString);

                            if (selectedAisle->getProductAisleTreePointer()->isProdCodeOnTree(chosenProd)) {
                                auto *selectedProd = selectedAisle->getProductAisleTreePointer()->getNodeByProdCode(chosenProd);

                                if (selectedProd->getProductAisleBrandTreePointer() != nullptr) {
                                    cout << "Please select a brand for product (numeric code): " << selectedProd->getName() << endl;

                                    selectedProd->getProductAisleBrandTreePointer()->printBrandsForPurchase();

                                    string brandCodeString;
                                    int brandCode;

                                    cin >> brandCodeString;
                                    brandCode = stoi(brandCodeString);

                                    if (selectedProd->getProductAisleBrandTreePointer()->isBrandCodeOnList(brandCode)) {
                                        auto *selectedBrand = selectedProd->getProductAisleBrandTreePointer()->getNodeByBrandCode(brandCode);

                                        cout << "Please type amount to but " << endl;
                                        string amountToBuy;
                                        cin >> amountToBuy;

                                        int intAmountToBuy = stoi(amountToBuy);
                                        if (intAmountToBuy>=0){

                                            if(intAmountToBuy <= selectedBrand->getAmount()){

                                                //Reduces from gondola
                                                selectedBrand->setAmount(selectedBrand->getAmount()-intAmountToBuy);

                                                //Adds client to queue clients
                                                if(!clientsQ.isClientIdInList(clientId)){
                                                    clientsQ.appendAtStart(clientId);
                                                    clientsQ.printList();
                                                }

                                                if(clientsQ.getClientById(clientId)->getFirstClientProd()== nullptr){
                                                    clientsQ.getClientById(clientId)->setFirstClientProd(new clientProductStackNode(to_string(chosenAisle), to_string(chosenProd), to_string(brandCode), intAmountToBuy));
                                                } else {
                                                    clientProductStackNode *aux = clientsQ.getClientById(clientId)->getFirstClientProd();
                                                    while (aux->getNextNode() != nullptr){
                                                        aux = aux->getNextNode();
                                                    }
                                                    aux->setNextNode(new clientProductStackNode(to_string(chosenAisle), to_string(chosenProd), to_string(brandCode), intAmountToBuy));
                                                }

                                                //Adds amounts to reporting usage
                                                selectedProd->setTimesSold(selectedProd->getTimesSold()+intAmountToBuy);

                                                while(!checkEndOption(purchaseExitOp)){
                                                    cout << "Product added to cart. Would you like to keep buying? (Y/N)" << endl;
                                                    cin >> purchaseExitOp;
                                                }
                                                if(purchaseExitOp=="N"||purchaseExitOp=="n"){
                                                    break;
                                                }

                                            } else {
                                                cout << "Not enough amount to buy. Try again" << endl;
                                            }

                                        } else {
                                            cout << "Please select a positive number." << endl;
                                        }

                                    } else {
                                        cout << "ERROR: No such brand on system. Please Try Again." << endl;
                                    }
                                } else {
                                    cout << "ERROR: There are no Brands associated to given Aisle" << endl;
                                }
                            } else {
                                cout << "ERROR: No such product on system. Please Try Again." << endl;
                            }
                        } else {
                            cout << "ERROR: There are no Products associated to given Aisle" << endl;
                        }
                    } else {
                        cout << "ERROR: No such aisle on system. Please Try Again." << endl;
                    }
                }
            } else {
                cout << "ERROR: Client is already on line. " << endl;
            }
        } catch (std::invalid_argument& e){
            cout << "Value is not numeric. Please try again" << endl;
        }
    }


    bool insertAisle(BinarySearchTree &aisles, string newAisleCode, string newAisleName){
        bool result = false;
        try {
            if(!aisles.isAisleCodeInTree(stoi(newAisleCode))){
                aisles.insert(new BSNode(stoi(newAisleCode), newAisleName));
                result = true;
            } else {
                result = false;
                cout << "ERROR: Aisle code is already present on tree. Try Again." << endl;
            }
        } catch (invalid_argument &e) {
            cout << e.what() << endl;
            cout << "Please use numbers" << endl;
            result = false;
        }
        return result;
    }

    bool insertProduct(BinarySearchTree &aisles, string aisleCode, string newProdCode, string newProdName){
        bool result = false;
        try {
            if(aisles.isAisleCodeInTree(stoi(aisleCode))){
                auto *bsNode = aisles.getNodeByAisleCode(stoi(aisleCode));

                if(bsNode->getProductAisleTreePointer()==nullptr){
                    bsNode->setProductAisleTreePointer(new NewAVLTree);
                }

                if(!bsNode->getProductAisleTreePointer()->isProdCodeOnTree(stoi(newProdCode))){
                    bsNode->getProductAisleTreePointer()->insert(stoi(newProdCode), newProdName);
                    result = true;
                } else {
                    result = false;
                    cout << "ERROR: Prod code is already present on tree. Try Again." << endl;
                }
            } else {
                result = false;
                cout << "ERROR: No Aisle code present on tree. Try Again." << endl;
            }
        } catch (invalid_argument &e) {
            cout << e.what() << endl;
            cout << "Please use numbers" << endl;
            result = false;
        } catch(...){
            return false;
        }
        return result;
    }

    bool insertBrand(BinarySearchTree &aisles, string aisleCode, string prodCode, string newBrandCode, string newBrandName, string amount, string price){
        bool result = false;
        try {
            if(aisles.isAisleCodeInTree(stoi(aisleCode))){
                auto *bsNode = aisles.getNodeByAisleCode(stoi(aisleCode));

                if(bsNode->getProductAisleTreePointer()!=nullptr){

                    if(bsNode->getProductAisleTreePointer()->isProdCodeOnTree(stoi(prodCode))){
                        auto *avlNode = bsNode->getProductAisleTreePointer()->getNodeByProdCode(stoi(prodCode));

                        if(avlNode->getProductAisleBrandTreePointer()==nullptr){
                            avlNode->setProductAisleBrandTreePointer(new NewRBTree);
                        }

                        if(!avlNode->getProductAisleBrandTreePointer()->isBrandCodeOnList(stoi(newBrandCode))){
                            avlNode->getProductAisleBrandTreePointer()->insert(stoi(newBrandCode), newBrandName, stoi(amount), stoi(price));
                            result = true;
                        } else {
                            cout << "ERROR: Brand code is already present on tree. Try Again." << endl;
                        }
                    } else {
                        cout << "ERROR: No Prod code present on tree. Try Again." << endl;
                    }

                } else{
                    cout << "Given aisle has no associated products." << endl;
                    return false;
                }

            } else {
                cout << "ERROR: No Aisle code present on tree. Try Again." << endl;
            }
        } catch (invalid_argument &e) {
            cout << e.what() << endl;
            cout << "Please use numbers" << endl;
            result = false;
        } catch (...) {
            return false;
        }
        return result;
    }

    bool insertClient(BTreeClients &clients, string clientId, string name, string email, string cityCode, string phoneNumber){
        bool result = false;
        try {
            if(clients.search(stoi(clientId)) == nullptr){
                clients.insert(stoi(clientId), ClientData(name, cityCode, phoneNumber, email));
                result = true;
            } else {
                cout << "ERROR: Client id present on tree. Try Again." << endl;
            }
        } catch (invalid_argument &e) {
            cout << e.what() << endl;
            cout << "Please use numbers" << endl;
            result = false;
        }
        return result;
    }


    static void insertModule(BinarySearchTree &aisles, BTreeClients &clients) {
        string op;
        while (true){
            cout << "Welcome to Insert menu. Please choose an option" << endl;
            cout << "1) Insert Aisle" << endl;
            cout << "2) Insert Product" << endl;
            cout << "3) Insert Brand" << endl;
            cout << "4) Insert Client" << endl;
            cout << "5) Exit" << endl;
            cin >> op;
            if (op=="1"){
                try{
                    string name;
                    string aisleCodeString;
                    int aisleCode;

                    cout << "You have chosen to insert new Aisle." << endl;
                    cout << "Type new Aisle code (numbers): " << endl;
                    cin >> aisleCodeString;
                    aisleCode = stoi(aisleCodeString); //Throws invalid_argument

                    cout << "Type new Aisle name: " << endl;
                    cin >> name;

                    if(!aisles.isAisleCodeInTree(aisleCode)){
                        aisles.insert(new BSNode(aisleCode, name));
                    } else {
                        cout << "ERROR: Aisle code is already present on tree. Try Again." << endl;
                    }

                } catch (std::invalid_argument& e){
                    cout << "Value is not numeric. Please try again" << endl;
                }

            } else if (op=="2"){
                try{
                    string name;
                    string aisleCodeString;
                    string prodCodeString;
                    int aisleCode;
                    int prodCode;

                    cout << "You have chosen to insert new Product" << endl;
                    cout << "Type Aisle code where to insert: " << endl;
                    cin >> aisleCodeString;
                    aisleCode = stoi(aisleCodeString); //Throws invalid_argument

                    cout << "Type new prod code to insert: " << endl;
                    cin >> prodCodeString;
                    prodCode = stoi(prodCodeString); //Throws invalid_argument

                    cout << "Type new Aisle name: " << endl;
                    cin >> name;

                    if(aisles.isAisleCodeInTree(aisleCode)){
                        auto *bsNode = aisles.getNodeByAisleCode(aisleCode);
                        if(!bsNode->getProductAisleTreePointer()->isProdCodeOnTree(prodCode)){
                            bsNode->getProductAisleTreePointer()->insert(prodCode, name);
                        } else {
                            cout << "ERROR: Prod code is already present on tree. Try Again." << endl;
                        }
                    } else {
                        cout << "ERROR: No Aisle code present on tree. Try Again." << endl;
                    }
                } catch (std::invalid_argument& e) {
                    cout << "Value is not numeric. Please try again" << endl;
                }

            } else if (op=="3"){
                try{
                    string name;
                    string aisleCodeString;
                    string prodCodeString;
                    string brandCodeString;
                    string amountString;
                    string priceString;
                    int aisleCode;
                    int prodCode;
                    int brandCode;
                    int amount;
                    int price;

                    cout << "You have chosen to insert new Product" << endl;
                    cout << "Type Aisle code where to insert: " << endl;
                    cin >> aisleCodeString;
                    aisleCode = stoi(aisleCodeString); //Throws invalid_argument

                    cout << "Type Prod code where to insert: " << endl;
                    cin >> prodCodeString;
                    prodCode = stoi(prodCodeString); //Throws invalid_argument

                    cout << "Type new Brand code where to insert: " << endl;
                    cin >> brandCodeString;
                    brandCode = stoi(brandCodeString); //Throws invalid_argument

                    cout << "Type new Aisle name: " << endl;
                    cin >> name;

                    cout << "Type Amount: " << endl;
                    cin >> amountString;
                    amount = stoi(amountString); //Throws invalid_argument

                    cout << "Type Price: " << endl;
                    cin >> priceString;
                    price = stoi(priceString); //Throws invalid_argument


                    if(aisles.isAisleCodeInTree(aisleCode)){
                        auto *bsNode = aisles.getNodeByAisleCode(aisleCode);
                        if(bsNode->getProductAisleTreePointer()->isProdCodeOnTree(prodCode)){
                            auto *avlNode = bsNode->getProductAisleTreePointer()->getNodeByProdCode(prodCode);
                            if(!avlNode->getProductAisleBrandTreePointer()->isBrandCodeOnList(brandCode)){
                                avlNode->getProductAisleBrandTreePointer()->insert(brandCode, name, amount, price);
                            } else {
                                cout << "ERROR: Brand code is already present on tree. Try Again." << endl;
                            }
                        } else {
                            cout << "ERROR: No Prod code present on tree. Try Again." << endl;
                        }
                    } else {
                        cout << "ERROR: No Aisle code present on tree. Try Again." << endl;
                    }
                } catch (std::invalid_argument& e) {
                    cout << "Value is not numeric. Please try again" << endl;
                }
            } else if(op=="4"){
                try {
                    string clientIdString;
                    string name;
                    string phoneNumber;
                    string email;
                    string cityCode;
                    int clientId;


                    cout << "You have chosen to insert Client." << endl;
                    cout << "Type your id (Numeric): " << endl;
                    cin >> clientIdString;
                    clientId = stoi(clientIdString);

                    cout << "Type new Client name: " << endl;
                    cin >> name;
                    cout << "Type new Client email: " << endl;
                    cin >> email;
                    cout << "Type new Client city code: " << endl;
                    cin >> cityCode;
                    cout << "Type new Client phone Number: " << endl;
                    cin >> phoneNumber;

                    if(clients.search(clientId) == nullptr){
                        clients.insert(clientId, ClientData(name, cityCode, phoneNumber, email));
                    } else {
                        cout << "ERROR: Client id present on tree. Try Again." << endl;
                    }


                }catch (std::invalid_argument& e){
                    cout << "Value is not numeric. Please try again" << endl;
                }

            } else if (op=="5"){
                break;
            }
        }
    }
    static void checkModule(BinarySearchTree &aisles, AATree &inventory, citiesList &cities) {
        string op;
        bool checkExit = false;
        while (!checkExit){
            cout << "Welcome to check modules. Please choose an option: " << endl;
            cout << "1) Check Price" << endl;
            cout << "2) Check product tax" << endl;
            cout << "3) Check product price" << endl;
            cout << "4) Print Cities" << endl;
            cout << "5) Exit" << endl;

            cin >> op;

            if(op=="1"){
                try {
                    cout << "Please select an aisle (numeric code): " << endl;

                    //Prints aisles
                    aisles.printAisleForPurchase();

                    string chosenAisleString;
                    int chosenAisle;
                    cin >> chosenAisleString;
                    chosenAisle = stoi(chosenAisleString);

                    if (aisles.isAisleCodeInTree(chosenAisle)) {
                        auto *selectedAisle = aisles.getNodeByAisleCode(chosenAisle);

                        if (selectedAisle->getProductAisleTreePointer() != nullptr) {
                            cout << "Please select a product for aisle (numeric code): " << selectedAisle->getName() << endl;

                            selectedAisle->getProductAisleTreePointer()->printProductsForPurchaseHelper(selectedAisle->getProductAisleTreePointer()->getAVLRoot());

                            string chosenProdString;
                            int chosenProd;
                            cin >> chosenProdString;
                            chosenProd = stoi(chosenProdString);

                            if (selectedAisle->getProductAisleTreePointer()->isProdCodeOnTree(chosenProd)) {
                                auto *selectedProd = selectedAisle->getProductAisleTreePointer()->getNodeByProdCode(chosenProd);

                                if (selectedProd->getProductAisleBrandTreePointer() != nullptr) {
                                    cout << "Please select a brand for product (numeric code): " << selectedProd->getName() << endl;

                                    selectedProd->getProductAisleBrandTreePointer()->printBrandsForPurchase();

                                    string brandCodeString;
                                    int brandCode;

                                    cin >> brandCodeString;
                                    brandCode = stoi(brandCodeString);

                                    if (selectedProd->getProductAisleBrandTreePointer()->isBrandCodeOnList(brandCode)) {
                                        auto *selectedBrand = selectedProd->getProductAisleBrandTreePointer()->getNodeByBrandCode(brandCode);

                                        cout << "Price: " << selectedBrand->getPrice() << endl;

                                    } else {
                                        cout << "ERROR: No such brand on system. Please Try Again." << endl;
                                    }
                                } else {
                                    cout << "ERROR: There are no Brands associated to given Aisle" << endl;
                                }
                            } else {
                                cout << "ERROR: No such product on system. Please Try Again." << endl;
                            }
                        } else {
                            cout << "ERROR: There are no Products associated to given Aisle" << endl;
                        }
                    } else {
                        cout << "ERROR: No such aisle on system. Please Try Again." << endl;
                    }
                } catch (std::invalid_argument& e){
                    cout << "Value is not numeric. Please try again" << endl;
                }
            } else if (op=="2"){
                try {
                    cout << "Please select an aisle (numeric code): " << endl;

                    //Prints aisles
                    aisles.printAisleForPurchase();

                    string chosenAisleString;
                    int chosenAisle;
                    cin >> chosenAisleString;
                    chosenAisle = stoi(chosenAisleString);

                    if (aisles.isAisleCodeInTree(chosenAisle)) {
                        auto *selectedAisle = aisles.getNodeByAisleCode(chosenAisle);

                        if (selectedAisle->getProductAisleTreePointer() != nullptr) {
                            cout << "Please select a product for aisle (numeric code): " << selectedAisle->getName() << endl;

                            selectedAisle->getProductAisleTreePointer()->printProductsForPurchaseHelper(selectedAisle->getProductAisleTreePointer()->getAVLRoot());

                            string chosenProdString;
                            int chosenProd;
                            cin >> chosenProdString;
                            chosenProd = stoi(chosenProdString);

                            if (selectedAisle->getProductAisleTreePointer()->isProdCodeOnTree(chosenProd)) {
                                auto *selectedProd = selectedAisle->getProductAisleTreePointer()->getNodeByProdCode(chosenProd);

                                if (selectedProd->getProductAisleBrandTreePointer() != nullptr) {
                                    cout << "Please select a brand for product (numeric code): " << selectedProd->getName() << endl;

                                    selectedProd->getProductAisleBrandTreePointer()->printBrandsForPurchase();

                                    string brandCodeString;
                                    int brandCode;

                                    cin >> brandCodeString;
                                    brandCode = stoi(brandCodeString);

                                    if (selectedProd->getProductAisleBrandTreePointer()->isBrandCodeOnList(brandCode)) {
                                        auto *selectedBrand = selectedProd->getProductAisleBrandTreePointer()->getNodeByBrandCode(brandCode);
                                        cout << "Product Price: " << selectedBrand->getPrice() << endl;

                                    } else {
                                        cout << "ERROR: No such brand on system. Please Try Again." << endl;
                                    }
                                } else {
                                    cout << "ERROR: There are no Brands associated to given Aisle" << endl;
                                }
                            } else {
                                cout << "ERROR: No such product on system. Please Try Again." << endl;
                            }
                        } else {
                            cout << "ERROR: There are no Products associated to given Aisle" << endl;
                        }
                    } else {
                        cout << "ERROR: No such aisle on system. Please Try Again." << endl;
                    }
                } catch (std::invalid_argument& e){
                    cout << "Value is not numeric. Please try again" << endl;
                }
            } else if(op == "3"){
                try {
                    cout << "Please select an aisle (numeric code): " << endl;

                    //Prints aisles
                    aisles.printAisleForPurchase();

                    string chosenAisleString;
                    int chosenAisle;
                    cin >> chosenAisleString;
                    chosenAisle = stoi(chosenAisleString);

                    if (aisles.isAisleCodeInTree(chosenAisle)) {
                        auto *selectedAisle = aisles.getNodeByAisleCode(chosenAisle);

                        if (selectedAisle->getProductAisleTreePointer() != nullptr) {
                            cout << "Please select a product for aisle (numeric code): " << selectedAisle->getName() << endl;

                            selectedAisle->getProductAisleTreePointer()->printProductsForPurchaseHelper(selectedAisle->getProductAisleTreePointer()->getAVLRoot());

                            string chosenProdString;
                            int chosenProd;
                            cin >> chosenProdString;
                            chosenProd = stoi(chosenProdString);

                            if (selectedAisle->getProductAisleTreePointer()->isProdCodeOnTree(chosenProd)) {
                                auto *selectedProd = selectedAisle->getProductAisleTreePointer()->getNodeByProdCode(chosenProd);

                                if (selectedProd->getProductAisleBrandTreePointer() != nullptr) {
                                    cout << "Please select a brand for product (numeric code): " << selectedProd->getName() << endl;

                                    selectedProd->getProductAisleBrandTreePointer()->printBrandsForPurchase();

                                    string brandCodeString;
                                    int brandCode;

                                    cin >> brandCodeString;
                                    brandCode = stoi(brandCodeString);

                                    if (selectedProd->getProductAisleBrandTreePointer()->isBrandCodeOnList(brandCode)) {
                                        auto *selectedBrand = selectedProd->getProductAisleBrandTreePointer()->getNodeByBrandCode(brandCode);

                                        cout << "Price: " << selectedBrand->getPrice() << endl;

                                    } else {
                                        cout << "ERROR: No such brand on system. Please Try Again." << endl;
                                    }
                                } else {
                                    cout << "ERROR: There are no Brands associated to given Aisle" << endl;
                                }
                            } else {
                                cout << "ERROR: No such product on system. Please Try Again." << endl;
                            }
                        } else {
                            cout << "ERROR: There are no Products associated to given Aisle" << endl;
                        }
                    } else {
                        cout << "ERROR: No such aisle on system. Please Try Again." << endl;
                    }
                } catch (std::invalid_argument& e){
                    cout << "Value is not numeric. Please try again" << endl;
                }
            } else if (op=="4"){
                cities.printList();
            }else if(op=="5"){
                checkExit= true;
            }
        }
    }
    static void checkGondolass(AATree &inventory, salesList &sales, BinarySearchTree &aisleList) {
        bool endGondolaMenu = false;
        int reStock = 0;
        string stockString;
        while(!endGondolaMenu){
            try{
                cout << "Please type the amount of items you want to re stock: ";
                cin >> stockString;
                reStock = stoi(stockString);
                endGondolaMenu = true;
            } catch (invalid_argument& e){
                cout << endl;
                cout << "That is not a valid number value, please try again" << endl;
            }
        }

        salesNode *aux = sales.getFirstNode();
        int invAmount;
        while (aux!= nullptr){
            try {
                AANode *inventoryItem = inventory.getNodeByAisleProdBrandCode(aux->getAisleCode()+aux->getProdCode()+aux->getBrandCode());
                auto *prodToRestore = aisleList.getNodeByAisleCode(stoi(aux->getAisleCode()))->getProductAisleTreePointer()->getNodeByProdCode(stoi(aux->getProdCode()))->getProductAisleBrandTreePointer()->getNodeByBrandCode(stoi(aux->getBrandCode()));
                if(prodToRestore->getAmount() < 2){
                    invAmount = inventoryItem->getStockAmount();
                    if(invAmount >= reStock){
                        inventoryItem->setStockAmount(invAmount-reStock);
                        prodToRestore->setAmount(prodToRestore->getAmount()+reStock);
                    } else {
                        cout << "There is not enough stock in inventory for re stock for: " << inventory.getNodeByAisleProdBrandCode(aux->getAisleCode()+aux->getProdCode()+aux->getBrandCode())->getName() << endl;
                    }
                }
            } catch (class elementNotFound& e) {
                cout << e.what() << endl;
            }
            aux = aux->getNextNode();
        }
    }

    bool checkGondolas(AATree &inventory, salesList &sales, BinarySearchTree &aisleList, string reStock) {
        bool result = false;
        salesNode *aux = sales.getFirstNode();
        int invAmount;
        while (aux!= nullptr){
            try {
                AANode *inventoryItem = inventory.getNodeByAisleProdBrandCode(aux->getAisleCode()+aux->getProdCode()+aux->getBrandCode());
                auto *prodToRestore = aisleList.getNodeByAisleCode(stoi(aux->getAisleCode()))->getProductAisleTreePointer()->getNodeByProdCode(stoi(aux->getProdCode()))->getProductAisleBrandTreePointer()->getNodeByBrandCode(stoi(aux->getBrandCode()));
                if(prodToRestore->getAmount() < 2){
                    invAmount = inventoryItem->getStockAmount();
                    if(invAmount >= stoi(reStock)){
                        inventoryItem->setStockAmount(invAmount-stoi(reStock));
                        prodToRestore->setAmount(prodToRestore->getAmount()+stoi(reStock));
                        result = true;
                    } else {
                        cout << "There is not enough stock in inventory for re stock for: " << inventory.getNodeByAisleProdBrandCode(aux->getAisleCode()+aux->getProdCode()+aux->getBrandCode())->getName() << endl;
                        result = false;
                    }
                }
            } catch (class elementNotFound& e) {
                cout << e.what() << endl;
            }
            aux = aux->getNextNode();
        }
        return result;
    }

    static bool mostProductPerAisle(const string& path, BinarySearchTree &aisleList, string aisleCode) {
        try {
            int aisleIndex = stoi(aisleCode);

            if(aisleList.isAisleCodeInTree(aisleIndex)){
                BSNode *selectedAisle = aisleList.getNodeByAisleCode(aisleIndex);
                selectedAisle->getProductAisleTreePointer()->generateMostBoughtProd(path, selectedAisle->getData());
                return true;
            } else {
                return false;
            }
        } catch (invalid_argument &e) {
            cout << e.what() << endl;
            cout << "Not a valid option. Try again" << endl;
            return false;
        }

    }

    static bool generateProductsReport(const string& path, BinarySearchTree &aisleList, string aisleCode){
        try {
            int aisleIndex = stoi(aisleCode);

            if(aisleList.isAisleCodeInTree(aisleIndex)){
                auto *selectedAisle = aisleList.getNodeByAisleCode(aisleIndex);
                selectedAisle->getProductAisleTreePointer()->generateProd(path, selectedAisle->getData());
                return true;
            } else {
                return false;
            }
        } catch (invalid_argument &e) {
            cout << "Not a valid option. Try again" << endl;
            return false;
        }
    }

    static bool generateBrandsReport(const string& path, BinarySearchTree aisles, string aisleCode, string prodCode){
        try {
            int chosenAisle;
            chosenAisle = stoi(aisleCode);

            if (aisles.isAisleCodeInTree(chosenAisle)) {
                auto *selectedAisle = aisles.getNodeByAisleCode(chosenAisle);

                if (selectedAisle->getProductAisleTreePointer() != nullptr) {

                    int chosenProd;
                    chosenProd = stoi(prodCode);

                    if (selectedAisle->getProductAisleTreePointer()->isProdCodeOnTree(chosenProd)) {
                        auto *selectedProd = selectedAisle->getProductAisleTreePointer()->getNodeByProdCode(chosenProd);

                        selectedProd->getProductAisleBrandTreePointer()->generateBrand(path, chosenAisle, chosenProd);
                        return true;

                    } else {
                        cout << "ERROR: No such product on system. Please Try Again." << endl;
                        return false;
                    }
                } else {
                    cout << "ERROR: There are no Products associated to given Aisle" << endl;
                    return false;
                }
            } else {
                cout << "ERROR: No such aisle on system. Please Try Again." << endl;
                return false;
            }
        } catch (...){
            cout << "Error" << endl;
            return false;
        }

    }

    static void reportingModuleMainMenu(BinarySearchTree &aisleList, salesList &sales, BTreeClients &clients, AATree &inventory, helper &helpers) {
        string op;
        while(true){
            cout << "Welcome to reporting menu. Please select an option" << endl;
            cout << "1) Most visited aisle" << endl;
            cout << "2) Least visited aisle" << endl;
            cout << "3) Most sold product per aisle" << endl;
            cout << "4) Most sold brand" << endl;
            cout << "5) Most expensive bill" << endl;
            cout << "6) Client who bought the most" << endl;
            cout << "7) Client who bought the least" << endl;
            cout << "8) Client who billed most times" << endl;
            cout << "9) Client who billed the least" << endl;
            cout << "10) Check Aisles" << endl;
            cout << "11) Check Products in Aisle" << endl;
            cout << "12) Check Product Brands" << endl;
            cout << "13) Check clients" << endl;
            cout << "14) Check Inventory" << endl;
            cout << "15) Generate all" << endl;
            cout << "16) Return" << endl;
            cin >> op;

            if(op=="1"){
                aisleList.generateMostVisitedAisleReport("../reports/mostVisitedAisle.txt");
            } else if (op=="2"){
                aisleList.generateLeastVisitedAisleReport("../reports/leastVisitedAisle.txt");
            } else if (op=="3"){
                //mostProductPerAisle("../reports/mostProductsPerAisle.txt", aisleList);
            } else if (op=="4"){
                sales.generateMostSoldBrands("../reports/mostSoldBrand.txt");
            } else if (op=="5"){
                clients.generateMostExpensiveBill("../reports/mostExpensiveBill.txt");
            } else if (op=="6"){
                clients.generateMostExpensiveBill("../reports/clientWhoBoughtTheMost.txt");
            } else if (op=="7"){
                clients.generateLeastExpensiveBill("../reports/clientWhoBoughtTheLeast.txt");
            } else if (op=="8"){
                clients.generateMostBilledClient("../reports/mostBilledClient.txt");
            } else if (op=="9"){
                clients.generateLeastBilledClient("../reports/leastBilledClient.txt");
            } else if (op=="10"){
                aisleList.generateAisles("../reports/aislesList.txt");
            } else if (op=="11"){
                //generateProductsReport("../reports/productsList.txt", aisleList);
            } else if (op=="12"){
                //generateBrandsReport("../reports/brandsList.txt", aisleList);
            } else if (op=="13"){
                clients.generateClients("../reports/clientsList.txt");
            } else if (op=="14"){
                inventory.generateInventory("../reports/inventoryList.txt");
            } else if (op=="15"){
                aisleList.generateMostVisitedAisleReport("../reports/mostVisitedAisle.txt");
                aisleList.generateLeastVisitedAisleReport("../reports/leastVisitedAisle.txt");
                //mostProductPerAisle("../reports/mostProductsPerAisle.txt", aisleList);
                sales.generateMostSoldBrands("../reports/mostSoldBrand.txt");
                clients.generateMostExpensiveBill("../reports/mostExpensiveBill.txt");
                clients.generateMostExpensiveBill("../reports/clientWhoBoughtTheMost.txt");
                clients.generateLeastExpensiveBill("../reports/clientWhoBoughtTheLeast.txt");
                clients.generateLeastBilledClient("../reports/leastBilledClient.txt");
                clients.generateMostBilledClient("../reports/mostBilledClient.txt");
                aisleList.generateAisles("../reports/aislesList.txt");
                //generateProductsReport("../reports/productsList.txt", aisleList);
                //generateBrandsReport("../reports/brandsList.txt", aisleList);
                clients.generateClients("../reports/clientsList.txt");
                inventory.generateInventory("../reports/inventoryList.txt");
            } else if (op=="16"){
                break;
            }
        }
    }

    void billingModule(BinarySearchTree &aisles, clientQueue &clientsQ, BTreeClients &clients, AATree &inventory, salesList &sales) {



        bool billingMenuExit = false;
        string aisleCode;
        string prodCode;
        string brandCode;
        int amount;
        QuickSort quickSort;
        Node *a;

        string clientId;
        string clientName;
        string clientPhone;
        string clientEmail;

        while (!billingMenuExit){
            try {
                cout << "Welcome to billing menu. Please select an option: " << endl;
                cout << "1) Bill first client in line" << endl;
                cout << "2) Return" << endl;

                string op;
                cin >> op;

                if(op=="1"){

                    if(!clientsQ.isEmpty()){
                        clientQueueNode *firstInLine = clientsQ.getLastElement();
                        //clientNode *currentClient = clients.getClientByClientId(firstInLine->getClientId());
                        ClientData currentClient = clients.searchClient(stoi(firstInLine->getClientId()));
                        cout << "Currently billing: " << currentClient.getName() << endl;
                        clientId = firstInLine->getClientId();
                        clientName = currentClient.getName();
                        clientPhone = currentClient.getPhoneNumber();
                        clientEmail = currentClient.getEmail();

                        //PERFORM QUICK SORT ON ITEMS
                        while (firstInLine->getFirstClientProd()!= nullptr){

                            clientProductStackNode *cartProducts = firstInLine->getFirstClientProd();

                            //Deletes tops element of stack
                            if(cartProducts->getNextNode() == nullptr){
                                aisleCode = cartProducts->getAisleCode();
                                prodCode = cartProducts->getProdCode();
                                brandCode = cartProducts->getBrandCode();
                                amount = cartProducts->getAmount();
                                quickSort.push(&a, amount, aisleCode, prodCode, brandCode);
                                firstInLine->setFirstClientProd(nullptr);
                                delete cartProducts;

                            } else {
                                while (cartProducts->getNextNode()->getNextNode() != nullptr){
                                    cartProducts = cartProducts->getNextNode();
                                }
                                aisleCode = cartProducts->getNextNode()->getAisleCode();
                                prodCode = cartProducts->getNextNode()->getProdCode();
                                brandCode = cartProducts->getNextNode()->getBrandCode();
                                amount = cartProducts->getNextNode()->getAmount();
                                quickSort.push(&a, amount, aisleCode, prodCode, brandCode);
                                clientProductStackNode *temp = cartProducts->getNextNode();
                                cartProducts->setNextNode(nullptr);
                                delete temp;
                            }

                        }
                        //Actual quicksort excution
                        quickSort.quickSort(&a);

                        Node *tmp = a;

                        //Billing loop
                        float finalPrice = 0;
                        float priceWithTax = 0;
                        int productPrice = 0;
                        float taxRate;

                        //Outfile prep work
                        ofstream outfile ("../bills/"+clientId+"_Bill.txt");
                        outfile << "Client ID: " << clientId << endl;
                        outfile << "Name: " << clientName << endl;
                        outfile << "Phone Number: " << clientPhone << endl;
                        outfile << "Email: " << clientEmail << endl;
                        outfile << endl;


                        while (tmp!=nullptr){

                            productPrice = aisles.getNodeByAisleCode(stoi(tmp->aisleCode))->getProductAisleTreePointer()->getNodeByProdCode(stoi(tmp->prodCode))->getProductAisleBrandTreePointer()->getNodeByBrandCode(stoi(tmp->brandCode))->getPrice();
                            //productPrice = aisleList.getNodeByAisleCode(tmp->aisleCode)->getProductAisleListPointer()->getNodeByProdCode(tmp->prodCode)->getAisleProductBrandListPointer()->getNodeByBrandCode(tmp->brandCode)->getPrice();
                            if(inventory.isBasicProduct(tmp->aisleCode+tmp->prodCode+tmp->brandCode)){
                                taxRate = this->basicProd;

                            } else {
                                taxRate = this->nonBasicProd;
                            }
                            priceWithTax = ((float)productPrice*taxRate)+(float)productPrice;
                            finalPrice += priceWithTax;


                            //Updates elements in sales list
                            if(!sales.isElementInList(tmp->aisleCode, tmp->prodCode, tmp->brandCode)){
                                sales.appendAtEnd(new salesNode(tmp->aisleCode, tmp->prodCode, tmp->brandCode, tmp->amount));
                            } else {
                                sales.updateElementInList(tmp->aisleCode, tmp->prodCode, tmp->brandCode, tmp->amount);
                            }

                            cout << "Sales list: " << endl;
                            sales.printList();

                            outfile << "Amount: " << tmp->amount << "; ProdCode: " << tmp->prodCode << "; Name: " << aisles.getNodeByAisleCode(stoi(tmp->aisleCode))->getProductAisleTreePointer()->getNodeByProdCode(stoi(tmp->prodCode))->getName() << "; Price: " << productPrice << "; Tax Rate: " << taxRate << "; Total: " << priceWithTax << endl;

                            tmp = tmp->next;
                        }
                        outfile << "Total Final Price: " << finalPrice << endl;
                        outfile << flush;
                        outfile.flush();
                        outfile.close();

                        //Adds spent amount for reports
                        currentClient.setAmountSpent(currentClient.getAmountSpent()+finalPrice);
                        currentClient.incBillingCount();

                        //Delete las client in queue and delete struct helper
                        clientsQ.deleteAtEnd();
                        quickSort.deleteList(&a);
                    } else {
                        cout << "There is no one in line to be billed" << endl;
                    }

                } else if(op=="2"){
                    billingMenuExit = true;
                }
            } catch (class elementNotFound& e){
                cout << "Element nof found error" << endl;
            }

        }
   }


   void modifyModule(BinarySearchTree &aisles, AATree &inventory) {
        string op;
        while (true){
            cout << "Welcome to modify menu. Please choose an option." << endl;
            cout << "1) Modify Price" << endl;
            cout << "2) Modify Tax %" << endl;
            cout << "3) Modify Product status (Basic or Normal)" << endl;
            cout << "4) Exit" << endl;

            cin >> op;

            if(op=="1"){
                try {
                    cout << "Please select an aisle (numeric code): " << endl;

                    //Prints aisles
                    aisles.printAisleForPurchase();

                    string chosenAisleString;
                    int chosenAisle;
                    cin >> chosenAisleString;
                    chosenAisle = stoi(chosenAisleString);

                    if (aisles.isAisleCodeInTree(chosenAisle)) {
                        auto *selectedAisle = aisles.getNodeByAisleCode(chosenAisle);

                        if (selectedAisle->getProductAisleTreePointer() != nullptr) {
                            cout << "Please select a product for aisle (numeric code): " << selectedAisle->getName() << endl;

                            selectedAisle->getProductAisleTreePointer()->printProductsForPurchaseHelper(selectedAisle->getProductAisleTreePointer()->getAVLRoot());

                            string chosenProdString;
                            int chosenProd;
                            cin >> chosenProdString;
                            chosenProd = stoi(chosenProdString);

                            if (selectedAisle->getProductAisleTreePointer()->isProdCodeOnTree(chosenProd)) {
                                auto *selectedProd = selectedAisle->getProductAisleTreePointer()->getNodeByProdCode(chosenProd);

                                if (selectedProd->getProductAisleBrandTreePointer() != nullptr) {
                                    cout << "Please select a brand for product (numeric code): " << selectedProd->getName() << endl;

                                    selectedProd->getProductAisleBrandTreePointer()->printBrandsForPurchase();

                                    string brandCodeString;
                                    int brandCode;

                                    cin >> brandCodeString;
                                    brandCode = stoi(brandCodeString);

                                    if (selectedProd->getProductAisleBrandTreePointer()->isBrandCodeOnList(brandCode)) {
                                        auto *selectedBrand = selectedProd->getProductAisleBrandTreePointer()->getNodeByBrandCode(brandCode);

                                        cout << "Please type new price (numbers):" << endl;
                                        int newPrice = 0;
                                        cin >> newPrice;

                                        selectedBrand->setPrice(newPrice);

                                        cout << "Price successfully changed. " << endl;

                                    } else {
                                        cout << "ERROR: No such brand on system. Please Try Again." << endl;
                                    }
                                } else {
                                    cout << "ERROR: There are no Brands associated to given Aisle" << endl;
                                }
                            } else {
                                cout << "ERROR: No such product on system. Please Try Again." << endl;
                            }
                        } else {
                            cout << "ERROR: There are no Products associated to given Aisle" << endl;
                        }
                    } else {
                        cout << "ERROR: No such aisle on system. Please Try Again." << endl;
                    }
                } catch (std::invalid_argument& e){
                    cout << "Value is not numeric. Please try again" << endl;
                }
            } else if(op=="2"){
                try {
                    while (true){
                        string taxOp;
                        cout << "Please select which tax you'd like to modify: " << endl;
                        cout << "1) Basic Product Tax" << endl;
                        cout << "2) Normal Product Tax" << endl;
                        cout << "3) Return" << endl;

                        cin >> taxOp;

                        if(taxOp=="1"){
                            string newTaxValString;
                            cout << "Please type new tax value in decimals: " << endl;
                            cin >> newTaxValString;
                            this->basicProd = stof(newTaxValString);
                        } else if (taxOp=="2"){
                            string newTaxValString;
                            cout << "Please type new tax value in decimals: " << endl;
                            cin >> newTaxValString;
                            this->nonBasicProd = stof(newTaxValString);
                        } else if (taxOp=="3"){
                            break;
                        }
                    }
                } catch (std::invalid_argument& e){
                    cout << "Value is not numeric. Please try again" << endl;
                }
            } else if(op=="3"){
                try {
                    cout << "Please select an aisle (numeric code): " << endl;

                    //Prints aisles
                    aisles.printAisleForPurchase();

                    string chosenAisleString;
                    int chosenAisle;
                    cin >> chosenAisleString;
                    chosenAisle = stoi(chosenAisleString);

                    if (aisles.isAisleCodeInTree(chosenAisle)) {
                        auto *selectedAisle = aisles.getNodeByAisleCode(chosenAisle);

                        if (selectedAisle->getProductAisleTreePointer() != nullptr) {
                            cout << "Please select a product for aisle (numeric code): " << selectedAisle->getName() << endl;

                            selectedAisle->getProductAisleTreePointer()->printProductsForPurchaseHelper(selectedAisle->getProductAisleTreePointer()->getAVLRoot());

                            string chosenProdString;
                            int chosenProd;
                            cin >> chosenProdString;
                            chosenProd = stoi(chosenProdString);

                            if (selectedAisle->getProductAisleTreePointer()->isProdCodeOnTree(chosenProd)) {
                                auto *selectedProd = selectedAisle->getProductAisleTreePointer()->getNodeByProdCode(chosenProd);

                                if (selectedProd->getProductAisleBrandTreePointer() != nullptr) {
                                    cout << "Please select a brand for product (numeric code): " << selectedProd->getName() << endl;

                                    selectedProd->getProductAisleBrandTreePointer()->printBrandsForPurchase();

                                    string brandCodeString;
                                    int brandCode;

                                    cin >> brandCodeString;
                                    brandCode = stoi(brandCodeString);

                                    if (selectedProd->getProductAisleBrandTreePointer()->isBrandCodeOnList(brandCode)) {

                                        string checkInventoryCode = chosenAisleString;
                                        checkInventoryCode.append(chosenProdString);
                                        checkInventoryCode.append(brandCodeString);

                                        if(inventory.isDataPresent(checkInventoryCode)){
                                            cout << "Please type if is basic prod (Y/N): " << endl;
                                            bool isBasic;
                                            string isBasicString;
                                            cin >> isBasicString;

                                            while(true){
                                                if(isBasicString=="Y" || isBasicString=="y"){
                                                    isBasic = true;
                                                    break;
                                                } else if (isBasicString=="N" || isBasicString=="n"){
                                                    isBasic = false;
                                                    break;
                                                } else {
                                                    cout << "That is not an accepted value. Please try again." << endl;
                                                }
                                            }
                                            inventory.getNodeByAisleProdBrandCode(checkInventoryCode)->setIsBasicProd(isBasic);
                                            cout << "Successfully modified to status of: " << isBasic << endl;
                                        } else {
                                            cout << "ERROR: No such element on inventory on system. Please Try Again." << endl;
                                        }
                                    } else {
                                        cout << "ERROR: No such brand on system. Please Try Again." << endl;
                                    }
                                } else {
                                    cout << "ERROR: There are no Brands associated to given Prod" << endl;
                                }
                            } else {
                                cout << "ERROR: No such product on system. Please Try Again." << endl;
                            }
                        } else {
                            cout << "ERROR: There are no Products associated to given Aisle" << endl;
                        }
                    } else {
                        cout << "ERROR: No such aisle on system. Please Try Again." << endl;
                    }
                } catch (std::invalid_argument& e){
                    cout << "Value is not numeric. Please try again" << endl;
                }
            } else if(op=="4") {
                break;
            }
        }
    }



    //    static void checkPrice(BinarySearchTree)
    static bool validateClient(BTreeClients clients, const string& id) {
        try {
            int numId = stoi(id);
            return clients.search(numId)!=nullptr;

        } catch (std::invalid_argument &e){
            return false;
        }


    }

    bool updateNormalProdTaxRate(string taxRate){
        bool result = false;
        try {
            this->nonBasicProd = stof(taxRate);
            result = true;
        } catch (invalid_argument &e) {
            cout << e.what() << endl;
            cout << "Please use numbers" << endl;
            result = false;
        }
        return result;
    }

    bool updateBasicProdTaxRate(string taxRate){
        bool result = false;
        try {
            this->basicProd = stof(taxRate);
            result = true;
        } catch (invalid_argument &e) {
            cout << e.what() << endl;
            cout << "Please use numbers" << endl;
            result = false;
        }
        return result;
    }

    bool deleteAisle(BinarySearchTree &aisles, string aisleCode){
        bool result = false;
        try {
            if(aisles.isAisleCodeInTree(stoi(aisleCode))){
                aisles.deleteNode(stoi(aisleCode));
                result = true;
            } else {
                cout << "ERROR: No such aisle on system. Please Try Again." << endl;
                result = false;
            }
        } catch (invalid_argument &e) {
            cout << e.what() << endl;
            cout << "Please use numbers" << endl;
            result = false;
        }
        return result;
    }

    bool deleteProduct(BinarySearchTree &aisles, string aisleCode, string prodCode){
        bool result = false;
        try {
            if(aisles.isAisleCodeInTree(stoi(aisleCode))){
                auto *selectedAisle = aisles.getNodeByAisleCode(stoi(aisleCode));

                if(selectedAisle->getProductAisleTreePointer() != nullptr){

                    if (selectedAisle->getProductAisleTreePointer()->isProdCodeOnTree(stoi(prodCode))) {
                        selectedAisle->getProductAisleTreePointer()->deleteNode(stoi(prodCode));
                        result = true;
                    } else {
                        cout << "ERROR: No such product on system. Please Try Again." << endl;
                        result = false;
                    }

                } else {
                    cout << "ERROR: There are no Products associated to given Aisle" << endl;
                    result = false;
                }

            } else {
                cout << "ERROR: No such aisle on system. Please Try Again." << endl;
                result = false;
            }
        } catch (invalid_argument &e) {
            cout << e.what() << endl;
            cout << "Please use numbers" << endl;
            result = false;
        }
        return result;
    }

    bool deleteBrand(BinarySearchTree &aisles, string aisleCode, string prodCode, string brandCode){
        bool result = false;
        try {
            if(aisles.isAisleCodeInTree(stoi(aisleCode))){
                auto *selectedAisle = aisles.getNodeByAisleCode(stoi(aisleCode));

                if(selectedAisle->getProductAisleTreePointer() != nullptr){

                    if (selectedAisle->getProductAisleTreePointer()->isProdCodeOnTree(stoi(prodCode))) {
                        auto *selectedProd = selectedAisle->getProductAisleTreePointer()->getNodeByProdCode(stoi(prodCode));

                        if (selectedProd->getProductAisleBrandTreePointer() != nullptr) {

                            if (selectedProd->getProductAisleBrandTreePointer()->isBrandCodeOnList(stoi(brandCode))) {
                               selectedProd->getProductAisleBrandTreePointer()->deleteByVal(stoi(brandCode));
                               result = true;
                            } else {
                                cout << "ERROR: No such brand on system. Please Try Again." << endl;
                                result = false;
                            }
                        } else {
                            cout << "ERROR: There are no Brands associated to given Prod" << endl;
                            result = false;
                        }
                    } else {
                        cout << "ERROR: No such product on system. Please Try Again." << endl;
                        result = false;
                    }
                } else {
                    cout << "ERROR: There are no Products associated to given Aisle" << endl;
                    result = false;
                }
            } else {
                cout << "ERROR: No such aisle on system. Please Try Again." << endl;
                result = false;
            }
        } catch (invalid_argument &e) {
            cout << e.what() << endl;
            cout << "Please use numbers" << endl;
            result = false;
        }
        return result;
    }

    bool deleteClient(BTreeClients &clients, string clientId){
        bool result = false;
        try {
            if(clients.search(stoi(clientId)) == nullptr){
                clients.remove(stoi(clientId));
                result = true;
            } else {
                cout << "ERROR: Client id present on tree. Try Again." << endl;
            }
        } catch (invalid_argument &e) {
            cout << e.what() << endl;
            cout << "Please use numbers" << endl;
            result = false;
        }
        return result;
    }

    bool bill(BinarySearchTree &aisles, clientQueue &clientsQ, BTreeClients &clients, AATree &inventory, salesList &sales){

        bool result = false;
        string aisleCode;
        string prodCode;
        string brandCode;
        int amount;
        QuickSort quickSort;
        Node *a;

        string clientId;
        string clientName;
        string clientPhone;
        string clientEmail;

        if(!clientsQ.isEmpty()){
            clientQueueNode *firstInLine = clientsQ.getLastElement();
            //clientNode *currentClient = clients.getClientByClientId(firstInLine->getClientId());
            ClientData currentClient = clients.searchClient(stoi(firstInLine->getClientId()));
            cout << "Currently billing: " << currentClient.getName() << endl;
            clientId = firstInLine->getClientId();
            clientName = currentClient.getName();
            clientPhone = currentClient.getPhoneNumber();
            clientEmail = currentClient.getEmail();

            //PERFORM QUICK SORT ON ITEMS
            while (firstInLine->getFirstClientProd()!= nullptr){

                clientProductStackNode *cartProducts = firstInLine->getFirstClientProd();

                //Deletes tops element of stack
                if(cartProducts->getNextNode() == nullptr){
                    aisleCode = cartProducts->getAisleCode();
                    prodCode = cartProducts->getProdCode();
                    brandCode = cartProducts->getBrandCode();
                    amount = cartProducts->getAmount();
                    quickSort.push(&a, amount, aisleCode, prodCode, brandCode);
                    firstInLine->setFirstClientProd(nullptr);
                    delete cartProducts;

                } else {
                    while (cartProducts->getNextNode()->getNextNode() != nullptr){
                        cartProducts = cartProducts->getNextNode();
                    }
                    aisleCode = cartProducts->getNextNode()->getAisleCode();
                    prodCode = cartProducts->getNextNode()->getProdCode();
                    brandCode = cartProducts->getNextNode()->getBrandCode();
                    amount = cartProducts->getNextNode()->getAmount();
                    quickSort.push(&a, amount, aisleCode, prodCode, brandCode);
                    clientProductStackNode *temp = cartProducts->getNextNode();
                    cartProducts->setNextNode(nullptr);
                    delete temp;
                }

            }
            //Actual quicksort excution
            quickSort.quickSort(&a);

            Node *tmp = a;

            //Billing loop
            double finalPrice = 0;
            double priceWithTax = 0;
            int productPrice = 0;
            double taxRate;

            //Outfile prep work
            ofstream outfile ("../bills/"+clientId+"_Bill.txt");
            outfile << "Client ID: " << clientId << endl;
            outfile << "Name: " << clientName << endl;
            outfile << "Phone Number: " << clientPhone << endl;
            outfile << "Email: " << clientEmail << endl;
            outfile << endl;


            while (tmp!=nullptr){

                productPrice = aisles.getNodeByAisleCode(stoi(tmp->aisleCode))->getProductAisleTreePointer()->getNodeByProdCode(stoi(tmp->prodCode))->getProductAisleBrandTreePointer()->getNodeByBrandCode(stoi(tmp->brandCode))->getPrice();
                //productPrice = aisleList.getNodeByAisleCode(tmp->aisleCode)->getProductAisleListPointer()->getNodeByProdCode(tmp->prodCode)->getAisleProductBrandListPointer()->getNodeByBrandCode(tmp->brandCode)->getPrice();
                if(inventory.isBasicProduct(tmp->aisleCode+tmp->prodCode+tmp->brandCode)){
                    taxRate = this->basicProd;

                } else {
                    taxRate = this->nonBasicProd;
                }
                priceWithTax = (productPrice*taxRate)+productPrice;
                finalPrice += priceWithTax;


                //Updates elements in sales list
                if(!sales.isElementInList(tmp->aisleCode, tmp->prodCode, tmp->brandCode)){
                    sales.appendAtEnd(new salesNode(tmp->aisleCode, tmp->prodCode, tmp->brandCode, tmp->amount));
                } else {
                    sales.updateElementInList(tmp->aisleCode, tmp->prodCode, tmp->brandCode, tmp->amount);
                }

                cout << "Sales list: " << endl;
                sales.printList();

                outfile << "Amount: " << tmp->amount << "; ProdCode: " << tmp->prodCode << "; Name: " << aisles.getNodeByAisleCode(stoi(tmp->aisleCode))->getProductAisleTreePointer()->getNodeByProdCode(stoi(tmp->prodCode))->getName() << "; Price: " << productPrice << "; Tax Rate: " << taxRate << "; Total: " << priceWithTax << endl;

                tmp = tmp->next;
            }
            outfile << "Total Final Price: " << finalPrice << endl;
            outfile << flush;
            outfile.flush();
            outfile.close();

            //Adds spent amount for reports
            currentClient.setAmountSpent(currentClient.getAmountSpent()+finalPrice);
            currentClient.incBillingCount();

            //Delete las client in queue and delete struct helper
            clientsQ.deleteAtEnd();
            quickSort.deleteList(&a);
            result = true;
        } else {
            cout << "There is no one in line to be billed" << endl;
            result = false;
        }
        return result;
    }

    bool updateProoductStatus(BinarySearchTree &aisles, AATree &inventory, string aisleCode, string prodCode, string brandCode, string productStatus){
        bool result = false;
        try {
            if (aisles.isAisleCodeInTree(stoi(aisleCode))) {
                auto *selectedAisle = aisles.getNodeByAisleCode(stoi(aisleCode));

                if (selectedAisle->getProductAisleTreePointer() != nullptr) {

                    if (selectedAisle->getProductAisleTreePointer()->isProdCodeOnTree(stoi(prodCode))) {
                        auto *selectedProd = selectedAisle->getProductAisleTreePointer()->getNodeByProdCode(stoi(prodCode));

                        if (selectedProd->getProductAisleBrandTreePointer() != nullptr) {

                            if (selectedProd->getProductAisleBrandTreePointer()->isBrandCodeOnList(stoi(brandCode))) {

                                string checkInventoryCode = aisleCode;
                                checkInventoryCode.append(prodCode);
                                checkInventoryCode.append(brandCode);

                                if(inventory.isDataPresent(checkInventoryCode)){
                                    bool isBasic;

                                    if(productStatus=="1"){
                                        isBasic = true;
                                    } else {
                                        isBasic = false;
                                    }

                                    inventory.getNodeByAisleProdBrandCode(checkInventoryCode)->setIsBasicProd(isBasic);
                                    result = true;
                                } else {
                                    cout << "ERROR: No such element on inventory on system. Please Try Again." << endl;
                                    result = false;
                                }
                            } else {
                                cout << "ERROR: No such brand on system. Please Try Again." << endl;
                                result = false;
                            }
                        } else {
                            cout << "ERROR: There are no Brands associated to given Aisle" << endl;
                            result = false;
                        }
                    } else {
                        cout << "ERROR: No such product on system. Please Try Again." << endl;
                        result = false;
                    }
                } else {
                    cout << "ERROR: There are no Products associated to given Aisle" << endl;
                    result = false;
                }
            } else {
                cout << "ERROR: No such aisle on system. Please Try Again." << endl;
                result = false;
            }
        } catch (invalid_argument &e) {
            cout << e.what() << endl;
            cout << "Please use numbers" << endl;
            result = false;
        }
        return result;
    }

    bool updatePrice(BinarySearchTree &aisles, string aisleCode, string prodCode, string brandCode, string newPrice){
        bool result = false;
        try {
            if (aisles.isAisleCodeInTree(stoi(aisleCode))) {
                auto *selectedAisle = aisles.getNodeByAisleCode(stoi(aisleCode));

                if (selectedAisle->getProductAisleTreePointer() != nullptr) {

                    if (selectedAisle->getProductAisleTreePointer()->isProdCodeOnTree(stoi(prodCode))) {
                        auto *selectedProd = selectedAisle->getProductAisleTreePointer()->getNodeByProdCode(stoi(prodCode));

                        if (selectedProd->getProductAisleBrandTreePointer() != nullptr) {

                            if (selectedProd->getProductAisleBrandTreePointer()->isBrandCodeOnList(stoi(brandCode))) {
                                auto *selectedBrand = selectedProd->getProductAisleBrandTreePointer()->getNodeByBrandCode(stoi(brandCode));
                                selectedBrand->setPrice(stoi(newPrice));
                                result = true;
                            } else {
                                cout << "ERROR: No such brand on system. Please Try Again." << endl;
                                result = false;
                            }
                        } else {
                            cout << "ERROR: There are no Brands associated to given Aisle" << endl;
                            result = false;
                        }
                    } else {
                        cout << "ERROR: No such product on system. Please Try Again." << endl;
                        result = false;
                    }
                } else {
                    cout << "ERROR: There are no Products associated to given Aisle" << endl;
                    result = false;
                }
            } else {
                cout << "ERROR: No such aisle on system. Please Try Again." << endl;
                result = false;
            }
        } catch (invalid_argument &e) {
            cout << e.what() << endl;
            cout << "Please use numbers" << endl;
            result = false;
        }
        return result;
    }

    bool isBasicProd(BinarySearchTree &aisles, AATree &inventory, string aisleCode, string prodCode, string brandCode){
        bool result = false;
        try {
            if (aisles.isAisleCodeInTree(stoi(aisleCode))) {
                auto *selectedAisle = aisles.getNodeByAisleCode(stoi(aisleCode));

                if (selectedAisle->getProductAisleTreePointer() != nullptr) {

                    if (selectedAisle->getProductAisleTreePointer()->isProdCodeOnTree(stoi(prodCode))) {
                        auto *selectedProd = selectedAisle->getProductAisleTreePointer()->getNodeByProdCode(stoi(prodCode));

                        if (selectedProd->getProductAisleBrandTreePointer() != nullptr) {

                            if (selectedProd->getProductAisleBrandTreePointer()->isBrandCodeOnList(stoi(brandCode))) {

                                string checkInventoryCode = aisleCode;
                                checkInventoryCode.append(prodCode);
                                checkInventoryCode.append(brandCode);

                                if(inventory.isDataPresent(checkInventoryCode)){
                                    result = inventory.getNodeByAisleProdBrandCode(checkInventoryCode)->getIsBasicProd();
                                } else {
                                    cout << "ERROR: No such element on inventory on system. Please Try Again." << endl;
                                    result = false;
                                }
                            } else {
                                cout << "ERROR: No such brand on system. Please Try Again." << endl;
                                result = false;
                            }
                        } else {
                            cout << "ERROR: There are no Brands associated to given Aisle" << endl;
                            result = false;
                        }
                    } else {
                        cout << "ERROR: No such product on system. Please Try Again." << endl;
                        result = false;
                    }
                } else {
                    cout << "ERROR: There are no Products associated to given Aisle" << endl;
                    result = false;
                }
            } else {
                cout << "ERROR: No such aisle on system. Please Try Again." << endl;
                result = false;
            }
        } catch (invalid_argument &e) {
            cout << e.what() << endl;
            cout << "Please use numbers" << endl;
            result = false;
        }
        return result;
    }



    static bool executePurchase(BTreeClients &clients, clientQueue &clientsQ, BinarySearchTree &aisleList, const string& aisleCode, const string& prodCode, const string& brandCode, const string& amountToBuy, const string &clientId, const string overrideClientQString) {

        try {
            bool overrideClientQueue = (overrideClientQString=="1");


            if(!clientsQ.isClientIdInList(clientId) || overrideClientQueue){
                auto client = clients.searchClient(stoi(clientId));
                int chosenAisle;
                chosenAisle = stoi(aisleCode);

                if (aisleList.isAisleCodeInTree(chosenAisle)) {
                    auto *selectedAisle = aisleList.getNodeByAisleCode(chosenAisle);

                    if (selectedAisle->getProductAisleTreePointer() != nullptr) {

                        int chosenProd;
                        chosenProd = stoi(prodCode);

                        if (selectedAisle->getProductAisleTreePointer()->isProdCodeOnTree(chosenProd)) {
                            auto *selectedProd = selectedAisle->getProductAisleTreePointer()->getNodeByProdCode(chosenProd);

                            if (selectedProd->getProductAisleBrandTreePointer() != nullptr) {

                                int chosenBrand;
                                chosenBrand = stoi(brandCode);

                                if (selectedProd->getProductAisleBrandTreePointer()->isBrandCodeOnList(chosenBrand)) {
                                    auto *selectedBrand = selectedProd->getProductAisleBrandTreePointer()->getNodeByBrandCode(chosenBrand);

                                    int intAmountToBuy = stoi(amountToBuy);
                                    if (intAmountToBuy>=0){

                                        if(intAmountToBuy <= selectedBrand->getAmount()){

                                            //Reduces from gondola
                                            selectedBrand->setAmount(selectedBrand->getAmount()-intAmountToBuy);

                                            //Adds client to queue clients
                                            if(!clientsQ.isClientIdInList(clientId)){
                                                clientsQ.appendAtStart(clientId);
                                                clientsQ.printList();
                                            }

                                            if(clientsQ.getClientById(clientId)->getFirstClientProd()== nullptr){
                                                clientsQ.getClientById(clientId)->setFirstClientProd(new clientProductStackNode(aisleCode, prodCode, brandCode, intAmountToBuy));
                                            } else {
                                                clientProductStackNode *aux = clientsQ.getClientById(clientId)->getFirstClientProd();
                                                while (aux->getNextNode() != nullptr){
                                                    aux = aux->getNextNode();
                                                }
                                                aux->setNextNode(new clientProductStackNode(aisleCode, prodCode, brandCode, intAmountToBuy));
                                            }

                                            //Adds amounts to reporting usage
                                            selectedProd->setTimesSold(selectedProd->getTimesSold()+intAmountToBuy);
                                            cout << "Purchase succesful" << endl;
                                            return true;
                                        } else {
                                            cout << "Not enough amount to buy. Try again" << endl;
                                            return false;
                                        }

                                    } else {
                                        cout << "Please select a positive number." << endl;
                                        return false;
                                    }
                                } else {
                                    cout << "ERROR: No such brand on system. Please Try Again." << endl;
                                    return false;
                                }
                            } else {
                                cout << "ERROR: There are no Brands associated to given Aisle" << endl;
                                return false;
                            }
                        } else {
                            cout << "ERROR: No such product on system. Please Try Again." << endl;
                            return false;
                        }
                    } else {
                        cout << "ERROR: There are no Products associated to given Aisle" << endl;
                        return false;
                    }
                } else {
                    cout << "ERROR: No such aisle on system. Please Try Again." << endl;
                    return false;
                }
            } else {
                cout << "ERROR: Client is already on line. " << endl;
                return false;
            }
        } catch (invalid_argument& e){
            cout << e.what() << endl;
            cout << "Value is not numeric. Please try again" << endl;
            return false;
        }
    }

    string getClientCart(clientQueue clientsQ, string clientId){
        try {
            string concat;
            if(clientsQ.isClientIdInList(clientId)){
                if(clientsQ.getClientById(clientId)->getFirstClientProd()== nullptr){
                    clientProductStackNode *aux = clientsQ.getClientById(clientId)->getFirstClientProd();
                    while (aux->getNextNode() != nullptr){
                        concat += "Aisle Code: "+aux->getAisleCode() + "; Prod Code: " + aux->getProdCode() + "; Brand Code: " + aux->getBrandCode() + "; Amount: " + to_string(aux->getAmount()) + "\n";
                        aux = aux->getNextNode();
                    }
                    return concat;
                } else {
                    return "Empty";
                }
            } else {
                return "Empty";
            }
        } catch (...) {
            return "Error";
        }
    }

    static string getAisles(BinarySearchTree &aisles) {
        return aisles.getAislesForClient();
    }

    static string getProductsByAisleCode(BinarySearchTree &aisles, const string& aisleCode) {
        try{
            return aisles.getNodeByAisleCode(stoi(aisleCode))->getProductAisleTreePointer()->getProductsForClient();
        } catch (...){
            return "Error";
        }
    }

    static string getBrandsByAisleProdCode(BinarySearchTree &aisles, const string& aisleCode, const string& prodCode) {
        try{
            return aisles.getNodeByAisleCode(stoi(aisleCode))->getProductAisleTreePointer()->getNodeByProdCode(stoi(prodCode))->getProductAisleBrandTreePointer()->getBrandsForClient();
        } catch (...){
            return "Error";
        }
    }

    static string getPriceByAisleProdBrandCode(BinarySearchTree &aisles, const string& aisleCode, const string& prodCode, const string& brandCode) {
        try{
            return to_string(aisles.getNodeByAisleCode(stoi(aisleCode))->getProductAisleTreePointer()->getNodeByProdCode(stoi(prodCode))->getProductAisleBrandTreePointer()->getNodeByBrandCode(stoi(brandCode))->getPrice());
        } catch (...){
            return "Error";
        }
    }

    static string getIsBasicByAisleProdBrandCode(AATree &inv, const string& aisleCode, const string& prodCode, const string& brandCode) {
        try{
            if(inv.getNodeByAisleProdBrandCode(aisleCode+prodCode+brandCode)->getIsBasicProd()){
                return "It is basic prod";
            } else return "It is NOT basic prod";
        } catch (...){
            return "Error";
        }
    }

    string getTaxByAisleProdBrandCode(AATree &inv, const string& aisleCode, const string& prodCode, const string& brandCode) {
        try{
            if(inv.getNodeByAisleProdBrandCode(aisleCode+prodCode+brandCode)->getIsBasicProd()){
                return "Tax: "+to_string(basicProd);
            } else return "Tax: "+to_string(nonBasicProd);
        } catch (...){
            return "Error";
        }
    }


    static bool validateAdmin(BTreeAdmins &admin, const string &adminID){
        try {
            int numId = stoi(adminID);
            return admin.search(numId)!=nullptr;

        } catch (std::invalid_argument &e){
            cout << e.what() << endl;
            return false;
        }
    }

    string getClients(BTreeClients &clients){
        return clients.getClientsForServer();
    }

    string getAdmins(BTreeAdmins &admins){
        return admins.getAdminsForServer();
    }

    bool reloadInventory(AATree &inventory, class helper helper) {
        try{
            //Restart values for inventory
            inventory.clear();
            helper.initInventory(inventory);

            cout << "Inventory restock successful" << endl;
            return true;
        } catch(...){
            return false;
        }
    }

    string getPrimAlgorithm(PrimGraph &primGraph){
        return primGraph.getPrimGraphResult();
    }

    string getPrimWeight(PrimGraph &primGraph){
        return to_string(primGraph.getTotalWeight());
    }

    string getKurskalGraph(KruskalGraph &kruskal){
        return kruskal.getKurskalGraphResult();
    }

    string getKurskalWeight(KruskalGraph &kruskal){
        return to_string(kruskal.getGraphWeight());
    }

    string getDijkstraGraph(DijkstraGraph &dijkstra, vector<vector<neighbor>> &dijkstraAdjList, string fromNode, string toNode){
        string concat = "";
        try {
            vector<double> min_distance;
            vector<int> previous;
            dijkstra.DijkstraComputePaths(stoi(fromNode), dijkstraAdjList, min_distance, previous);
            dijkstra.minDistance = min_distance[stoi(toNode)];
           //cout << dijkstra.minDistance << endl;
            list<int> path = dijkstra.DijkstraGetShortestPathTo(stoi(toNode), previous);

            concat = dijkstra.getPath(path);
            dijkstra.dijkstraPath = concat;
        } catch (invalid_argument &e) {
            concat = "Could not convert number values.";
            cout << e.what() << endl;
        }
        return concat;
    }

    string getDijkstraDistance(DijkstraGraph &dijkstra){
        cout << to_string(dijkstra.getMinDistance()) << endl;
        return to_string(dijkstra.getMinDistance());
    }

    string getArticulationPoints(ArticulationPointGraph &g1){
        g1.AP();
    }

private:
    double basicProd = 0.01;
    double nonBasicProd = 0.13;
};











