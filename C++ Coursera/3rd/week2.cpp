// C++ implementation of finding average path by dijkstra's algotithm 

///#include <bits/stdc++.h>
// /*                                                       // using block comment for easy enabling and disabling includes
 
#include <iostream>                                         //for input output  
#include <vector>                                           //vector header
#include <queue>                                            //defines limits macros
#include <ctime>                                            //for time in function for srand
#include <utility>                                          //for pair<type,type> class
#include <climits>                                          // for INT_MAX
// */

using namespace std; 

// Graph = matrix of vector of pairs  (vertex, edge_path) representating it as list
vector<pair<int, int> > graph[1000];                         //alloting space for 100 total pairs

// Function to add edges connecting a pair of vertex(frm)  vertex(to) with edge_path weight 
void addEdge(int frm, int to, int weight)  
{ 
    graph[frm].push_back({ to, weight }); 
} 

// Function to print shortest distance from source 
void printDist(int dist[],int Source, int V) 
{ 
    cout << "Vertex \t\t Distance from "<< Source << endl; 
    for (int i = 0; i < V; i++) { 
        if (dist[i] != INT_MAX){
            cout <<i <<" \t\t " <<dist[i]<<endl; 
        }
        else {
            cout <<i <<" \t\t not connected" <<endl; 
        }
        
    } 
} 


// Function to compute the Shortest Path Function algorithm and returns the result in dist[]
void ShortestPath(int dist[],  int Source, int Vertex)      // arugments ( address of array to store path,  source vertex,  no  of  array)
{ 
    

    // Boolean array to check if vertex is present in queue or not 
    bool inQueue[Vertex + 1] = { false }; 

    // Initialize the distance from source to other vertex as INT_MAX (infinite)
    for (int i = 0; i <= Vertex; i++) {    
        dist[i] = INT_MAX; 
    } 
    
    dist[Source] = 0;                                       // edge_path to self is 0 

    queue<int> q; 
    q.push(Source); 
    inQueue[Source] = true; 

    while (!q.empty()) { 

        // Take the front vertex from Queue 
        int u = q.front(); 
        q.pop(); 
        inQueue[u] = false; 

        // Relaxing all the adjacent edges of vertex taken from the Queue 
        for (int i = 0; i < (int)graph[u].size(); i++) { 

            int v = graph[u][i].first; 
            int weight = graph[u][i].second; 

            if (dist[v] > dist[u] + weight) { 
                dist[v] = dist[u] + weight; 

                // Check if vertex v is in Queue or not if not then push it into the Queue 
                if (!inQueue[v]) { 
                    q.push(v); 
                    inQueue[v] = true; 
                } 
            } 
        } 
    } 

    // Print  result 
    printDist(dist,Source, Vertex); 
   
} 

// main function 
int main() 
{ 
    int Vertex = 50;                                        // totol no of vertex 
    int density = 40;                                       // density in percentage
    int edge_path;                                          // Variable to hold edge path varies from 1 to 10
    srand(time(NULL));
    // Create array dist to store shortest distance 
    int distance[Vertex][Vertex];                           // for storing all  the possible Shortest paths between vertices
    
    // Connect vertex a to b with weight w using density parameter and random path lenght
    for (int i=0;i<Vertex;i++) {                            // using c style counting starting from 0
        for ( int j=0;j<i;j++) {
            if (i==j){
                addEdge(i, j, 0);                           // a node is always connected to self with edge path 0
            }

            else { 
                if (rand()%100<density){
                    edge_path=rand()%10+1;                  // edge_path range from 1 to 10
                    addEdge(i, j, edge_path);
                    addEdge(j, i, edge_path);
                }
            }
        }
    } 
    
    
    for (int i = 0; i < Vertex;i++){                        // where i is the source vertex
        ShortestPath(&distance[i][0], i, Vertex);           // Calling ShortestPath function & prints the avg   
        cout << endl;
    }

    //  calculate the avg distance in graph ignoring the unconnected nodes

{   // setting local scope, might be later made into function
    // use vector to passing 2D matrix be smoothly 
    int sum=0;
    int num = 1;

    for (int i = 0; i < Vertex; i++) { 
        for (int j = 0; j < Vertex; j++) { 
            if (distance[i][j] != INT_MAX){                 // INI_MAX (infinity)
                sum+=distance[i][j];
                num++;
            }
        }
        
    } 
    
    cout << "average edge Distance in the graph is :"<< sum/(double)num <<endl;
}
 

    return 0; 
} 


/*************************************************************************************************
                             * OUTPUT: for graph with vertex 5*
 *************************************************************************************************
 
$ ./a.out 
Vertex 		 Distance from 0
0 		 0
1 		 17
2 		 19
3 		 9
4 		 10

Vertex 		 Distance from 1
0 		 17
1 		 0
2 		 26
3 		 16
4 		 7

Vertex 		 Distance from 2
0 		 19
1 		 26
2 		 0
3 		 10
4 		 19

Vertex 		 Distance from 3
0 		 9
1 		 16
2 		 10
3 		 0
4 		 9

Vertex 		 Distance from 4
0 		 10
1 		 7
2 		 19
3 		 9
4 		 0

average edge Distance in the graph is :10.9231

 *==============================================
 * FOR 50 vertex THE FINAL
 
 $ ./a.out
 ...
 ...
 ...
 ...
 .
 
 * average edge Distance in the graph is :3.7401
 * 
    
 */


/*************************************************************************************************
                                   * DESCRIPTION OF CODE  *
 *************************************************************************************************
 
here the array positioning is done as in c.
ie starts count form 0.
Here graph is initiated as a list using ARRAY of vector of pairs, ie 2D matrix of pairs
addEdge funtion adds the element of ARRAY by pushing parameters passed to it. it takes start node (frm), to node (to) and path lenght as (weight).

function printDist() takes the parameters of Initializd array containing information about path lenght from node (source) to all other node and prints/displays it. improvements can be done here by using vector but array works perfectly without increasing complexity. the path lenght to the disconnected node has value of INT_MAX(infinity). 

ShortestPath() function is the function that computes the path lenght from node to node by use of dijkstra's algorithm. it use a queueto calculate ShortestPath.
inQueue is used to track the vertexs. dist[] array is use to put the calculated path. dist[] is passed by reference hence this information is accesible form the calling funcrion. the array element position also act as the number to destination node. all  dist[] value are initiated as disconnected if INT_MAX except for dist[Source] = 0 where Source is source vertex.

array dist[] stores the shortest distance of all vertex from the source vertex. 

queue is made and push starting source vertex in it.
while queue is not empty, do the following for each 

edge(u, v) in the graph
If d[v] > d[u] + weight of edge(u, v)
d[v] = d[u] + weight of edge(u, v)

If vertex v is not present in Queue, then push the vertex v into the Queue.

main () function :
vertex is no of vertex the graph contains
density is the density of edge in graph in percent
edge_path holds the random value of edge path ranging from 1 to 10
srand (time()); function initializes the random seed for pseudo-random number generator
distance[][] is used to store all the shortest path from one vertex to other. the data indicate path lenght while values of rows and colum indicate the vertex. C numbering convenction is used.
using above information the edge is Initialized randomly

shotrest path function is called using loop for each vertex and data collected in * the rows of matrix distance[]

average edge distance of the whole graph is calculated in main using two for loops and local variables printing the required result.


**************************************************************************************************/
