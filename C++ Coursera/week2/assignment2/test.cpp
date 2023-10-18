#include <iostream>
#include <climits>
#include <vector>
#include <cassert>
#include <ctime>
#include <cstdlib>
const int INFINITY = INT_MAX;

extern const int INFINITY;





using namespace std;

Graph::Graph(int verticeNum): verticeNum(verticeNum)
{
	if (verticeNum <= 0)
	{
		this->verticeNum = 0;
		return;
	}

	addmat = vector<vector<int> >(verticeNum, vector<int>(verticeNum));
}

Graph::Graph(int verticeNum, double density):
	edgeNum(0), verticeNum(verticeNum)
{
	if (verticeNum <= 0)
	{
		this->verticeNum = 0;
		return;
	}

	addmat = vector<vector<int> >(verticeNum, vector<int>(verticeNum));

	srand(time(0));
	const int RANGE = 10;
	for (int i=0; i<verticeNum-1; i++)
	{
		for (int j=1; j<verticeNum; j++)
		{
			double prob = (rand() % 100) / 100.0;
			
			if (prob < density)
			{
				int value = rand() % RANGE + 1;
				addEdge(i, j, value);
			}
		}
	}
}

bool graph::adjacent(int x, int y) const
{
	assert(x>=0 && x<verticeNum && y>=0 && y<verticeNum);

	return addmat[x][y] > 0;
}

vector<int> graph::neighbors(int x) const
{
	assert(x>=0 && x<verticeNum);

	vector<int> list;
	for (int i=0; i<verticeNum; i++)
	{
		if (addmat[x][i] > 0)
		{
			list.push_back(i);
		}
	}

	return list;
}

vector<int> graph::getVertices() const
{
	vector<int> vertices;

	for (int i=0; i<verticeNum; i++)
	{
		vertices.push_back(i);
	}

	return vertices;
}

bool graph::addEdge(int x, int y, int value)
{
	assert(x>=0 && x<verticeNum && y>=0 && y<verticeNum);

	if (addmat[x][y] > 0)
		return false;

	addmat[x][y] = value;
	addmat[y][x] = value;

	return true;
}

bool graph::deleteEdge(int x, int y)
{
	assert(x>=0 && x<verticeNum && y>=0 && y<verticeNum);

	if (addmat[x][y] > 0) 
	{
		addmat[x][y] = 0;
		addmat[y][x] = 0;
		return true;
	}

	return false;
}

int graph::getEdgeValue(int x, int y) const
{
	assert(x>=0 && x<verticeNum && y>=0 && y<verticeNum);

	return addmat[x][y];
}

void graph::setEdgeValue(int x, int y, int value)
{
	assert(x>=0 && x<verticeNum && y>=0 && y<verticeNum);

	addmat[x][y] = value;
	addmat[y][x] = value;
}

// implement graph via adjacent matrix
class Graph
{
public:
	Graph() {}

	Graph(int verticeNum);	

	Graph(int verticeNum, double density);

	int getVerticeNum() const { return verticeNum; }

	int getEdgeNum() const { return edgeNum; }
	
	// tests whether there is an edge from node x to node y
	bool adjacent(int x, int y) const;

	// lists all nodes y such that there is an edge from
	// x to y
	std::vector<int> neighbors(int x) const;

	// return all vertices in the graph
	std::vector<int> getVertices() const;

	bool addEdge(int x, int y, int value);

	bool deleteEdge(int x, int y);

	int getEdgeValue(int x, int y) const;

	void setEdgeValue(int x, int y, int value);

private:
	int edgeNum;

	int verticeNum;

	std::vector<std::vector<int> > adMatrix;
};

#include "ShortestPath.h"

using namespace std;

int main()
{
	double densities[3] = {0.2, 0.4, 0.5};
	int verticeNum = 50;
	ShortestPath sp;

	for (int i=0; i<3; i++)
	{
		int sum = 0;
		int count = 0;
		graph graph(verticeNum, densities[i]);

		for (int n=1; n<50; n++)
		{
			int pathSize = sp.pathSize(graph, 0, n);
			if (pathSize != INFINITY)
			{
				sum += pathSize;
				count++;
			}
		}

		cout << "For the graph with density = " << densities[i];
		cout << ", the average path length = " << 
			(static_cast<double>(sum) / count) << endl;
	}

	return 0;
}
