#pragma once

#include <iostream>
#include <list>
using namespace std;

class DFSGraph
{
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:

    string dfsTraveralString;

    string getDfsTraversalString(){
        return this->dfsTraveralString;
    }

    void setEdgesCount(int vertices){
        numVertices = vertices;
        adjLists = new list<int>[vertices];
        visited = new bool[vertices];
    }

    void addEdge(int src, int dest)
    {
        adjLists[src].push_front(dest);
    }
    void DFS(int vertex){
        DFSHelper(vertex, dfsTraveralString);
    }

private:
    void DFSHelper(int vertex, string &concat)
    {
        visited[vertex] = true;
        list<int> adjList = adjLists[vertex];

        //cout << vertex << " ";
        concat += to_string(vertex) +"\n";

        list<int>::iterator i;
        for(i = adjList.begin(); i != adjList.end(); ++i)
            if(!visited[*i])
                DFSHelper(*i, concat);
    }
};







//int main()
//{
//    Graph g(4);
//    g.addEdge(0, 1);
//    g.addEdge(0, 2);
//    g.addEdge(1, 2);
//    g.addEdge(2, 3);
//    g.DFS(2);

//    return 0;
//}
