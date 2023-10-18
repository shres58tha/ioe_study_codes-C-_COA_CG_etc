//for compliting this assignme nt i had refferenced to greekforce's program and followed the same method

#include <vector>
#include <cassert>
#include <ctime>
#include <cstdlib>

#include "Graph.h"

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
