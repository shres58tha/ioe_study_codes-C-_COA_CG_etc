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
    for (int i = 0; i <= Vertex; i++) {    dist[i] = INT_MAX; 
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
 

    return 0; 
} 
