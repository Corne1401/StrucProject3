#include <QCoreApplication>
#include "server.h"
#include "globalTrees.h"
#include "helpers/helpers.h"

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

void print(std::list<int> const &list){
    for (auto v : list)
        std::cout << v << "\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    initAisleTree(aisles);
    initAislesProductTree(aisles);
    initAislesProductBrandTree(aisles);
    initCitiesList(cities);
    initClients(clients);
    initAdmins(admins);
    initInventory(inventory);

    numberOfEdges = determineConnectionsNodes(connectionsList, cities, "Conexiones");
    numberOfEdgesArticulationPoint = determineConnectionsNodes(articulationPointHelperList, cities, "Ptos de articulacion");
    dijkstraAdjList.resize(numberOfEdgesArticulationPoint);

    pGraph = primGraph.createGraph(numberOfEdges);
    kruskalGraph.setEdgesCount(numberOfEdges);
    articulationPointGraph.setEdgesCount(numberOfEdgesArticulationPoint);

    initGraph(cities, pGraph, primGraph, connectionsList, kruskalGraph, dijkstraAdjList);

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
    inventory.print();


    Server Server;
    Server.StartServer();

    return a.exec();
}
