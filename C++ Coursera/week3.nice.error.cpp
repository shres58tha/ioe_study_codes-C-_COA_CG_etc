 
/* Dijkstra's shortest path algorithm
 * Style guide:
    * methods: snake_case
    * variables: camelCase
*/

#include <iostream>
#include <random>
#include <list>
#include <array>

using namespace std;

/* Graph Class
 * INPUTS: 
    * vertices
      * Maximum of 50
    * density
      * Probability and edge exists
    * distance
      * Maximum distance used for the distances
*/

class Graph {

  private:
    const unsigned int vertices;
    const double density;
    const double distance;
    const double maxDistance = 5;
    bool **grph;
    int **distanceGraph;
     
  protected:

  public:
    void get_edge();
    void set_edge();
    
    
  /* Constructors */  
  /* Default */
  Graph()
  :
  vertices(50),
  density(0.5),
  distance(1){
    error_check();
    build_graph();
  }
  
  /* Assignment */
  Graph(const unsigned int v, const double den, const double dis)
  :
  vertices(v),
  density(den),
  distance(dis){
    error_check();
    build_graph();
  }  
  
  /* Copy */
  Graph(const Graph &grph);
  
  /* Move */
  
  /* Destructor */
  ~Graph(){
	  	for(unsigned int i = 0; i < vertices; i++){
	  		delete [] grph[i];
	  		delete [] distanceGraph[i];
	  	}
	  	delete [] grph;
	  	delete [] distanceGraph;
  }
  
  /* Member Functions */

  /* Error checking */
  void error_check(){

    if(vertices > 50 || vertices <= 0){
      cout << "  Vertices out of range" << endl;
      cout << "  Setting vertices = 25 " << endl;
      cout << endl;      
      unsigned int *ptr = const_cast<unsigned int*>(&vertices);
      *ptr = 50; 
    }

    if(density >= 1.0 || density <= 0.0){
      cout << "  Density out of range" << endl;
      cout << "  Setting density = 0.5 " << endl;
      cout << endl;      
      double *ptr = const_cast<double*>(&density);
      *ptr = 0.5; 
    }

    if(distance < 0 || distance > maxDistance){
      cout << "  Distance out of range" << endl;
      cout << "  Setting distance = " << maxDistance << endl;
      cout << endl;      
      double *ptr = const_cast<double*>(&distance);
      *ptr = maxDistance;
    }
  }

  /* generate graph */
  void build_graph(){

    /* allocate 2D array of bool on the heap */
	grph = new bool *[vertices];
	distanceGraph = new int *[vertices];

	for(unsigned int i = 0; i < vertices; i++){
		grph[i] = new bool[vertices];
		distanceGraph[i] = new int[vertices];
	}
	/* random number generator*/
	default_random_engine gen;
	uniform_real_distribution<double> dist(0.1,1.0);

    /* for each row and column*/
	for(unsigned int i = 0; i < vertices; i++){
		for(unsigned int j = i; j < vertices; j++){
			/* diagonal elements == 0 */
			if(i==j){
				grph[i][j]=false;
			}
			/* symmetrical graph X_ij = X_ji */
			else{
				grph[i][j] = grph[j][i] = (dist(gen) < density);
			}
		}
	}
	for(unsigned int i = 0; i < vertices; i++){
		for(unsigned int j = i; j < vertices; j++){
			if (grph[i][j]==true){
				distanceGraph[i][j]= distanceGraph[j][i] = ceil(dist(gen)*10);
			}
		}
	}
}

  /* Check is connected */
  bool is_connected(){

	  /* Set up arrays of bools for open and closed sets */
	  unsigned int open_size = 0;
	  unsigned int closed_size = 0;
	  bool* close = new bool[vertices];
	  bool* open = new bool[vertices];
	  for(unsigned int i = 0; i < vertices; i++){
		  open[i] = close[i] = false;
	  }
	  /* Set node 0 true */
	  open[0]=true;
	  while(closed_size < vertices){
		  /* Add to close */
		  for(unsigned int i = 0; i < vertices; i++){
			  open_size = closed_size;
			  if(open[i] && (close[i]==false)){
				  close[i] = true;
				  closed_size++;
			  }
			  /* Add to open */
			  for(unsigned int j = 0; j < vertices; j++){
				  open[j]= open[j] || grph[i][j];
			  }
		  }
		  /* termination */
		  if(open_size == closed_size) return false; /* Unconnected */
		  if(closed_size == vertices) return true; /* Connected */
	  }
	  /* If exits loop without returning error */
	  cout << "ERROR: Graph::is_connected(), exits control loop" << endl;
	  return false;
  }

  /* Print the graph */
  void print_graph(int flag=0){
	  if (flag==1){
		  cout << " ------------" << endl;
		  	  for(unsigned int i = 0; i < vertices; i++){
		  		  cout << " |";
		  		for(unsigned int j = 0; j < vertices; j++){
		  			cout << " " << distanceGraph[i][j];
		  		}
		  		cout << "|" << endl;
		  	  }
		  	  cout << " ------------" << endl;
	  }
	  else{
	  cout << " ------------" << endl;
	  for(unsigned int i = 0; i < vertices; i++){
		  cout << " |";
		for(unsigned int j = 0; j < vertices; j++){
			cout << " " << grph[i][j];
		}
		cout << "|" << endl;
	  }
	  cout << " ------------" << endl;
	  }
  }

  /* Create map/list of edge distances */
  void build_distance_list(){

  }

  /* Find path - Dijkstras */
  /* Node numbers go 0 -> N-1 */
  int get_shortest_path(unsigned int nodeStart,unsigned int nodeEnd,list<int> path){

	 /* Error check */
	  if(nodeStart < 0 || nodeStart > vertices-1){
		  cout << "ERROR, nodeStart not a legitimate value" << endl;
	  }
	  if(nodeEnd < 0 || nodeEnd > vertices-1){
		  cout << "ERROR, nodeEnd not a legitimate value" << endl;
	  }

	 /* Using vector to store list of unvisited and visited nodes */
	  vector<int> unvisitedSet;
	  vector<int> visitedSet;
	  vector<double> tentativeDistance;

	  double inf = maxDistance*vertices*10;
	  double minDistance;

	  unsigned int currentNode;

	  /* Set all nodes unvisited and set tentative distance = infinity */
	  for(int unsigned i = 0; i < vertices; i++){
		  unvisitedSet.push_back(i);
		  tentativeDistance.push_back(inf);
	  }

	  /* Set tentative distance value of startNode = 0 */
	  tentativeDistance[nodeStart]=0.0;

	  /* While unvisistedSet is not empty */
	  while(!unvisitedSet.empty()){
		  currentNode = nodeStart;

		  /* For current node get neighbours and distances */
		  for(auto j : unvisitedSet){
			  /* if(neighbour and tentativeDistance < distance) -> Update neighbour node*/
			  if (grph[currentNode][j]==true && distanceGraph[currentNode][j] < tentativeDistance[j]){
				  tentativeDistance[j] = tentativeDistance[currentNode]+distanceGraph[currentNode][j];
			  }
		  }

		  /* Remove current node from unvisited set and add to visited set */
		  //auto it = unvisitedSet.begin();
		  //while(it != unvisitedSet.end()){
		  for(auto it = unvisitedSet.begin(); it != unvisitedSet.end(); it++){
			if (*it == currentNode){
				it = unvisitedSet.erase(it);
				visitedSet.push_back(currentNode);
				break;
			}
			it++;
		  }

		  /* Get the next smallest tentative distance */
		  minDistance=inf;
		  for(auto j : unvisitedSet){
			  if(tentativeDistance[j] < minDistance){
				  minDistance = tentativeDistance[j];
				  nodeStart = j;
			  }
		  }

		  /* If destinationNode == visited break and return path*/
		  for(unsigned int x:visitedSet){
			  if(x == nodeEnd){
				  return tentativeDistance[x];
			  }
		  }
	  } /* End while */
	  return 0;
  } /* End shortest Path */

};

int main(int argc, char **argv)
{

  cout << "\nDijkstra's Shortest Path Algorithm\n" << endl;

  int numVertices = 20;
  double density = 0.5;
  double distance = 1;

  Graph obj(numVertices,density,distance);

  if (obj.is_connected()){
	  cout << "Graph is connected" << endl;
  }
  else{
	  cout << "Graph is not connected"<< endl;
  	  cout << "Change density or # of vertices\n" << endl;
  }

  list<int> path;

  cout << "Length of shortest path: " << obj.get_shortest_path(0,numVertices-1,path) << endl;
  cout << "\nProgram Completed\n" << endl;

  return 0;
}
