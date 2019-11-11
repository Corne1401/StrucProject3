#ifndef GLOBALTREES_H
#define GLOBALTREES_H

#include "TreesHandlers/BinarySearchTree.h"

#include <helpers/ArticulationPoints.h>
#include <helpers/Dijkstra.h>
#include <helpers/Kruskal.h>
#include <helpers/PrimGraph.h>
#include <helpers/citiesList.h>

extern int numberOfEdges;
extern int numberOfEdgesArticulationPoint;

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

#endif // GLOBALTREES_H
