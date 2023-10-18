// C++ implementation of finding average path by dijkstra's algotithm 

///#include <bits/stdc++.h>
// /*                                                       // using block comment for easy enabling and disabling includes
 
#include <iostream>                                         //for input output  
#include <vector>                                           //vector header
#include <queue>                                            //defines limits macros
#include <ctime>                                            //for time in function for srand
#include <utility>                                          //for pair<type,type> class
#include <climits>                                          // for INT_MAX
#include <cmath>                                            // for INFINITY
// */

using namespace std; 


class Graph{
    /*public:
        Graph(int num, float density); // num gets number of nodes, density of edges in percentage
        void print_graph();
    */
    private:
    
        unsigned int ver; //number of vertices in the graph
        unsigned int edg;       // the number of edges in the graph  path to self is not included in count 

        
    protected:
        bool CheckBoundary(unsigned int x)const {
            if (x >= ver)
                throw invalid_argument("Index out of bounds!");
        }
        
        bool CheckBoundary(unsigned int x, unsigned int y)const {
            if (x >= ver || y >= ver)
                throw invalid_argument("Index out of bounds!");
        }
        
    public:
        
        vector<vector<float> > graph;       // graph[1st node][ 2nd node] contains edge_distance
        
        Graph(){
           ver=0;
           edg=0;
        }
        
        Graph(unsigned int size){    //size= no of total nodes in graph
            ver=size;
            edg=0;
            for (unsigned int i = 0; i < ver; i++){
                // We push a new vector of float onto the initial vector ver times
                // The * is there to dereference the new vector that we insert
                graph.push_back( *( new vector<float>() ) );
                for (unsigned int j = 0; j < ver; ++j){
                    //then, on each of those vectors, we push a default "INT_MAX(infinity)" ver times  
                    if (i==j)
                        graph.at(i).push_back(0); // the vertex/node is always connected to itself
                        //graph[i][j]=0;  
                    else
                        graph.at(i).push_back(INFINITY);  //vertexes/ nodes not connected
                }
            }
        }
        //void addVertex();
        
        write it
        **********************************************************
        
        
        unsigned int Vertex () const {return ver; } //returns the number of vertices in the graph
        
        unsigned int Edge () const {return edg; } // returns the number of edges in the graph
        
        bool Adjacent  (unsigned int x, unsigned int y){ //checks if x and y share an edge
            CheckBoundary(x,y);
            return  graph[x][y]!= INFINITY ;
        }//*/
            
        vector<unsigned int> Neighbors(unsigned int x)  { //lists all nodes y sharing edge with x 
            CheckBoundary(x);
            vector<unsigned int> result;
            for (unsigned int i = 0; i < ver; i++)
                if (Adjacent(x, i)==true)
                    result.push_back(i);
            return result;
        }
            
        void AddEdge (unsigned int x, unsigned int y, double weight) {
            CheckBoundary(x,y);
            if (weight<0 || weight == INFINITY) 
                throw invalid_argument("Weight(path lenght) of an edge can't be negative or infinite");
                
            if (x!=y){
                edg++;              //increment count of the edg 
                graph[x][y]=weight; // the graph is undirected
                graph[y][x]=weight;
            }
                    
        }
            
        void RemoveEdge (unsigned int x, unsigned int y) {
            CheckBoundary(x,y);
            if (x==y) 
                throw invalid_argument("path to the self cannnot be removed");
                
            if (x!=y){
                edg--;  //decrement count of the edg
                graph[x][y]=INFINITY; // the graph is undirected
                graph[y][x]=INFINITY; // edge set to infinity ie not connected
            }
                    
        }
        
        double GetEdgeValue( unsigned int x, unsigned int y){  //returns the value associated to the edge (x,y).
            CheckBoundary(x,y);
            return graph[x][y];
        }    
        
        void SetEdgeValue( unsigned int x, unsigned int y, double weight){  //returns the value associated to the edge (x,y).
            CheckBoundary(x,y); 
            // fix it
            // not connected already edg++
            // connected edg unchanged
            // weight val infinity edg --
            // check x==y weight 0
            if (weight<0 || weight ==INFINITY) 
                throw invalid_argument("Weight(path lenght) of an edge can't be negative or infinite");
            
            graph[x][y]=weight;
        } 
        void printGraph();
    };

        // Function to add edges connecting a pair of vertex(frm)  vertex(to) with edge_path weight 

        void Graph::printGraph(){  // node name // print node name formatting
            cout << "graph size " << this->ver << "\n";
                for(unsigned int i = 0; i < this->ver; ++i){
                    for (unsigned int j = 0; j < this->ver; ++j){
                cout << this->graph[i][j] << "\t";
            }
            cout << "\n";
        }
    }



// Function to compute the Shortest Path Function algorithm and returns the result in dist[]
void ShortestPath(float dist[],  int Source, int Vertex)      // arugments ( address of array to store path,  source vertex,  no  of  array)
{ 
    // make dist[] into vector for enabling the checking or testing memory overflow
    Graph g;

    // Boolean array to check if vertex is present in queue or not 
    bool inQueue[Vertex + 1] = { false }; 
    
    // Initialize the distance from source to other vertex as INT_MAX (infinite)
    for (int i = 0; i <= Vertex; i++) {    
        dist[i] = INFINITY; 
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
        for (int i = 0; i < Vertex; i++) { 

            int v = i; 
            float weight = g.graph[u][i];     // calling and ascessing method for members of function Graph g

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
    
    //Graph g;  declaration is not done here so all below is invalid
    
    //make graph initilization class
    
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
