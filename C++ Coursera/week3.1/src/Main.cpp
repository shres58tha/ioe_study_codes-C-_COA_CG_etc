#include <iostream>file:///home/shr/Desktop/cpract/C++/week3.1/include/Graph.h

#include "../include/Graph.h"
#include "../include/ShortestPathAlgorithm.h"
#include "../include/Helper.h"

using namespace std;

/*
    main() function creates two random 50-node graphs with different densities and
    calculates the average shortest path for each of them.
*/

int main()
{
    double averagePathLength1 = 0, averagePathLength2 = 0;
    Graph g1 = randomGraphGenerator(50,0.2,10);
    Graph g2 = randomGraphGenerator(50,0.4,10);

    ShortestPathAlgorithm dijkstra1(g1);
    ShortestPathAlgorithm dijkstra2(g2);

    for(int i = 1; i < 50; i++)
    {
        averagePathLength1 += dijkstra1.run(0,i);
        averagePathLength2 += dijkstra2.run(0,i);
    }

    cout << "Results:" << endl;
    cout << "========" << endl;
    cout << "Average Shortest Path Length for 20% density is: " << averagePathLength1/49 << endl;
    cout << "Average Shortest Path Length for 40% density is: " << averagePathLength2/49 << endl;

    return 0;
}





