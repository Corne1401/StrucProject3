#ifndef GLOBALTREES_H
#define GLOBALTREES_H

#include "TreesHandlers/BinarySearchTree.h"

#include <helpers/ArticulationPoints.h>
#include <helpers/Dijkstra.h>
#include <helpers/Kruskal.h>
#include <helpers/PrimGraph.h>
#include <helpers/citiesList.h>
#include <helpers/helpers.h>

#include <modules/modules.h>

#include <TreesHandlers/AATree.h>
#include <TreesHandlers/BTreeAdmins.h>
#include <TreesHandlers/BTreeClients.h>
#include <string>

extern int numberOfEdges;
extern int numberOfEdgesArticulationPoint;
extern std::string PATH_TO_REPORTS;

extern helper helpers;

extern citiesList cities;
extern citiesList connectionsList;
extern citiesList articulationPointHelperList;

extern BinarySearchTree aisles;

extern PrimGraph primGraph;
extern struct PrimGraph::Graph* pGraph;

extern KruskalGraph kruskalGraph;

extern ArticulationPointGraph articulationPointGraph;

extern DijkstraGraph dijkstraGraph;
extern vector<vector<neighbor>> dijkstraAdjList;

extern BTreeAdmins admins;
extern BTreeClients clients;

extern AATree inventory;

extern modules modules;

extern salesList sales;

extern clientQueue clientsQ;

#endif // GLOBALTREES_H
