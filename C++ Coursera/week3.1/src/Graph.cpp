#include "Graph.h"
#include "Edge.h"
#include <iostream>

using namespace std;

/*
    adjacent function goes through the adjacency data of the graph and
    checks whether there is an edge between two nodes.
*/
bool Graph::adjacent(int x, int y)
{
    for(auto it = adjacencyData.at(x).begin(); it != adjacencyData.at(x).end(); it++)
    {
        if(it->getSecondNode() == y)
        {
            return true;
        }
    }

    return false;
}

/*
    neighbors function goes through the adjacency data of the graph and
    returns a vector including the Edges connecting the given node with all its neighbors.
*/
vector<Edge> Graph::neighbors(int x)
{
    vector<Edge> neighbors;
    for (auto it = adjacencyData.at(x).begin(); it != adjacencyData.at(x).end(); it++)
    {
        neighbors.push_back(*it);
    }
    cout << endl;

    return neighbors;

}

/*
    Adds a single edge between two nodes of the graph.
    However it updates the adjacency data for both nodes (x,y indexes).
*/
void Graph::addEdge(int x, int y, double w)
{
    if(!isValidEdge(x,y,w))
    {
        return;
    }

    if(x == y)
    {
        cout << "Error adding edge. Edges between the same node are not allowed." << endl;
        return;
    }

    if(adjacent(x,y))
    {
        cout << "Edge between " << x << " and " << y << " already exists." << endl;
        return;
    }

    Edge ex(x,y,w);
    adjacencyData.at(x).push_back(ex);
    Edge ey(y,x,w);
    adjacencyData.at(y).push_back(ey);
    numEdges++;

}

/*
    Deletes a single edge between two nodes of the graph.
    However it updates the adjacency data for both nodes (x,y indexes).
*/
void Graph::deleteEdge(int x, int y)
{
    if(!isValidEdge(x,y))
    {
        return;
    }

    if(!adjacent(x,y))
    {
        cout << "Edge between " << x << " and " << y << " does not exist" << endl;
    }
    else
    {
       for(auto it = adjacencyData.at(x).begin(); it != adjacencyData.at(x).end(); it++)
       {
           if(it->getSecondNode() == y)
           {
               adjacencyData.at(x).erase(it);
               break;
           }
       }

       for(auto it = adjacencyData.at(y).begin(); it != adjacencyData.at(y).end(); it++)
       {
           if(it->getSecondNode() == x)
           {
               adjacencyData.at(y).erase(it);
               break;
           }
       }

       numEdges--;
    }
}

/*
    isValidEdge function checks whether all the data of the Edge (node indexes and weight) have acceptable values.
*/
bool Graph::isValidEdge(int x, int y, double w)
{
    if(w < 0)
    {
        cout << "Error: Negative edge weights are not allowed. " << endl;
        return false;
    }

    if(x < 0 || y < 0)
    {
        cout << "Error: Negative numbers for Node indexes are not allowed. " << endl;
        return false;
    }

    if(x >= getNumOfVertices() || y >= getNumOfVertices())
    {
        cout << "Error: Node index must be less than the total number of nodes in the Graph. " << endl;
        cout << "Tried to process edge (" << x << "," << y << ") , while the total number of nodes is " << getNumOfVertices() << endl;
        return false;
    }

    return true;
}
