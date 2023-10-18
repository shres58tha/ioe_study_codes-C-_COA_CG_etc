#include "ShortestPathAlgorithm.h"

/*
    run function implements the Dijkstra algorithm.
    It creates the priority queue and adds all the nodes,
    and then it calculates and returns the length of the
    shortest path between src and dst nodes.

*/

double ShortestPathAlgorithm::run(int src, int dst)
{
    for(int i = 0; i < graph.getNumOfVertices(); i++)
    {
        if(i == src)
        {
            QueueElement queueElement(i,UNDEFINED,0);
            priorityQueue.addElement(queueElement);
            continue;
        }

        QueueElement queueElement(i);
        priorityQueue.addElement(queueElement);
    }

    while(!priorityQueue.isEmpty())
    {
        QueueElement currentNode = priorityQueue.top();
        vector<Edge> neighbours = graph.neighbors(currentNode.getNode());

        for (auto it = neighbours.begin(); it != neighbours.end(); it++)
        {
            if(priorityQueue.getElement(it->getSecondNode())->isProcessed())
            {
                continue;
            }

            double length = currentNode.getPriority() + it->getWeight();

            if (length < priorityQueue.getElement(it->getSecondNode())->getPriority())
            {
                priorityQueue.getElement(it->getSecondNode())->setPriority(length);
                priorityQueue.getElement(it->getSecondNode())->setPreviousNode(currentNode.getNode());
            }
        }

        priorityQueue.getElement(currentNode.getNode())->setProcessed();
        priorityQueue.decrSize();

    }

    return priorityQueue.getElement(dst)->getPriority();
}
