#include <QCoreApplication>
#include "server.h"
#include "globalTrees.h"


BinarySearchTree aisles;
citiesList cities;
citiesList connectionsList;
citiesList articulationPointHelperList;
AATree inventory;
BTreeClients clients;
BTreeAdmins admins;
PrimGraph primGraph;
PrimGraph::Graph* pGraph;
KruskalGraph kruskalGraph;
ArticulationPointGraph articulationPointGraph;
DijkstraGraph dijkstraGraph;
int numberOfEdges;
int numberOfEdgesArticulationPoint;
vector<vector<neighbor>> dijkstraAdjList;
helper helpers;
salesList sales;
clientQueue clientsQ;
class modules modules;
string PATH_TO_REPORTS = "C:\\GitHub_Projects\\StrucProject3\\Server\\reports\\";

void print(std::list<int> const &list){
    for (auto v : list)
        std::cout << v << "\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    helpers.initAisleTree(aisles);
    helpers.initAislesProductTree(aisles);
    helpers.initAislesProductBrandTree(aisles);
    helpers.initCitiesList(cities);
    helpers.initClients(clients);
    helpers.initAdmins(admins);
    helpers.initInventory(inventory);

    numberOfEdges = helpers.determineConnectionsNodes(connectionsList, cities, "Conexiones");
    numberOfEdgesArticulationPoint = helpers.determineConnectionsNodes(articulationPointHelperList, cities, "Ptos de articulacion");
    dijkstraAdjList.resize(numberOfEdgesArticulationPoint);

    pGraph = primGraph.createGraph(numberOfEdges);
    kruskalGraph.setEdgesCount(numberOfEdges);
    articulationPointGraph.setEdgesCount(numberOfEdgesArticulationPoint);

    helpers.initGraph(cities, pGraph, primGraph, connectionsList, kruskalGraph, dijkstraAdjList);

//    cout << "Edges of MST are \n";
//    int mst_wt = kruskalGraph.kruskalMST();

//    cout << "\nWeight of MST is " << mst_wt << endl;

//    vector<double> min_distance;
//    vector<int> previous;
//    dijkstraGraph.DijkstraComputePaths(16, dijkstraAdjList, min_distance, previous);
//    std::cout << "Distance from 0 to 4: " << min_distance[13] << std::endl;
//    std::list<int> path = dijkstraGraph.DijkstraGetShortestPathTo(13, previous);
//    std::cout << "Path : ";
//    std::copy(path.begin(), path.end(), std::ostream_iterator<int>(std::cout, " "));
//    std::cout << std::endl;
//    print(path);

//    admins.traverse();

      //cout << modules.getClients(clients) << endl;
    //clients.traverse();

    inventory.print();

    Server Server;
    Server.StartServer();

    return a.exec();
}
