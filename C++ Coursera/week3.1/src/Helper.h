#ifndef HELPER_H
#define HELPER_H

#include <time.h>
#include "Graph.h"

/*
    randomGraphGenerator helper function builds a random Graph with the given edge density and distance range
*/

Graph randomGraphGenerator(int numNodes, double edgeDensity, double distanceRange)
{
    Graph g(numNodes);
    srand(time(NULL));

    for(int i = 0; i < numNodes; i++)
    {
        for(int j = i+1; j < numNodes; j++)
        {
            double randomDensity = static_cast<double>(rand())/(static_cast<double>(RAND_MAX));
            if(randomDensity < edgeDensity)
            {
                double randomWeight = static_cast<double>(rand())/(static_cast<double>(RAND_MAX));
                randomWeight = randomWeight*(distanceRange - 1.0) + 1.0;
                g.addEdge(i,j,randomWeight);
            }
        }
    }

    return g;
}

#endif
