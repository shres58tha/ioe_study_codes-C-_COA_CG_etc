#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include "Edge.h"
#include "PriorityQueue.h"

using namespace std;

/*
    Class Graph contains a vector which contains lists of Edge objects which contain the adjacency data of the graph.
    A PriorityQueue object is used to have access to the next shortest link  in the shortest path calculation.
*/

class Graph
{

    public:
        Graph(int v = 0):numVertices(v)
        {
            adjacencyData.reserve(numVertices);
            for(int i = 0; i < numVertices; i++)
            {
                list<Edge> l;
                adjacencyData.push_back(l);
            }
        };

        int getNumOfVertices(){return numVertices;}
        int getNumOfEdges(){return numEdges;}
        bool adjacent(int x, int y);
        void addEdge(int x, int y, double w);
        void deleteEdge(int x, int y);
        vector<Edge> neighbors(int x);
        bool isValidEdge(int x, int y, double w = 0.0);

    private:
        int numVertices, numEdges = 0;
        vector <list<Edge>> adjacencyData;
        PriorityQueue priorityQueue;

};
#endif // GRAPH_H
