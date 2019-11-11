#pragma once
#include "Neighbor.h"

#include <iostream>
#include <vector>
#include <string>
#include <list>

#include <limits> // for numeric_limits

#include <queue>
#include <utility> // for pair
#include <algorithm>
#include <iterator>

using namespace std;


class DijkstraGraph {
public:
    DijkstraGraph()= default;


    typedef vector<vector<neighbor>> adjacency_list_t;
    typedef pair<double, int> weight_vertex_pair_t;

    const double max_weight = std::numeric_limits<double>::infinity();

    void DijkstraComputePaths(int source,
                              const adjacency_list_t &adjacency_list,
                              std::vector<double> &min_distance,
                              std::vector<int> &previous)
    {
        int n = adjacency_list.size();
        min_distance.clear();
        min_distance.resize(n, max_weight);
        min_distance[source] = 0;
        previous.clear();
        previous.resize(n, -1);
        // we use greater instead of less to turn max-heap into min-heap
        std::priority_queue<weight_vertex_pair_t,
                std::vector<weight_vertex_pair_t>,
                std::greater<weight_vertex_pair_t> > vertex_queue;
        vertex_queue.push(std::make_pair(min_distance[source], source));

        while (!vertex_queue.empty())
        {
            double dist = vertex_queue.top().first;
            int u = vertex_queue.top().second;
            vertex_queue.pop();

            // Because we leave old copies of the vertex in the priority queue
            // (with outdated higher distances), we need to ignore it when we come
            // across it again, by checking its distance against the minimum distance
            if (dist > min_distance[u])
                continue;

            // Visit each edge exiting u
            const std::vector<neighbor> &neighbors = adjacency_list[u];
            for (std::vector<neighbor>::const_iterator neighbor_iter = neighbors.begin();
                 neighbor_iter != neighbors.end();
                 neighbor_iter++)
            {
                int v = neighbor_iter->target;
                double weight = neighbor_iter->weight;
                double distance_through_u = dist + weight;
                if (distance_through_u < min_distance[v]) {
                    min_distance[v] = distance_through_u;
                    previous[v] = u;
                    vertex_queue.push(make_pair(min_distance[v], v));

                }

            }
        }
    }


    list<int> DijkstraGetShortestPathTo(
            int vertex, const std::vector<int> &previous)
    {
        list<int> path;
        for ( ; vertex != -1; vertex = previous[vertex])
            path.push_front(vertex);
        return path;
    }
};

//Steps for printing dijkstra

//vector<DijkstraGraph::weight_t> min_distance;
//vector<DijkstraGraph::vertex_t> previous;
//dijkstraGraph.DijkstraComputePaths(16, dijkstraAdjList, min_distance, previous);
//std::cout << "Distance from 0 to 4: " << min_distance[13] << std::endl;
//std::list<DijkstraGraph::vertex_t> path = dijkstraGraph.DijkstraGetShortestPathTo(13, previous);
//std::cout << "Path : ";
//std::copy(path.begin(), path.end(), std::ostream_iterator<DijkstraGraph::vertex_t>(std::cout, " "));
//std::cout << std::endl;
//print(path);
