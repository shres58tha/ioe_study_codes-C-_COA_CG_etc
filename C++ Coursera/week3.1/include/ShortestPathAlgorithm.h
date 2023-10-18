#ifndef SHORTESTPATHALGORITHM_H
#define SHORTESTPATHALGORITHM_H

#include "PriorityQueue.h"
#include "QueueElement.h"
#include "Graph.h"

/*
    ShortestPathAlgorithm class takes a Graph object as an argument, and performs Dijkstra's
    shortest path calculation for given source and destination nodes.
    For this calculation it uses a priority queue.
*/

class ShortestPathAlgorithm
{
    public:
        ShortestPathAlgorithm(Graph g):graph(g){};
        double run(int src, int dst);

    private:
        Graph graph;
        PriorityQueue priorityQueue;
        int sourceNode, destinationNode;

};

#endif // SHORTESTPATHALGORITHM_H
