// C++ implementation of finding average path inplementing  Kruskal MST 
#include <bits/stdc++.h>
using namespace std;

class Node {   
    // Class Node for storring information about nodes/edges in the adjacency list of a graph
private:                    // not to be accesed adn modified form outside
        int num; 
        int pathDist; 
        list<Node> edg;	//  Graph represented in edge list with pathDist  
public:
    Node():num(-1),pathDist(INT_MAX) { edg.clear(); };  //if nunber=-1 orpathDist= infinity clear vector  edge by calling member function of vector
    Node(int n, int w=INT_MAX):num(n),pathDist(w) { edg.clear(); };
    ~Node() {};
    Node& operator=(const Node &n);                       //member function declaration
    bool operator == (const Node& n) const;
    void setNodeNum(int n) { num = n; };
    int getNodeNum() { return num; };
    void setEdgPathDist(int w=INT_MAX) { pathDist = w; };
    int getEdgPathDist() { return pathDist; };
    void setEdg(Node N) { edg.push_back(N); };
    list<Node> getEdges() { return edg; };
        
};

Node& Node::operator=(const Node &nd) {                     // overload = operator Node data
    this->num = nd.num;
    this->pathDist = nd.pathDist;
    this->edg = nd.edg;
    return *this;
}

bool Node::operator== (const Node& nd) const {               // == overload (true if two Node have same Node number else false) 
    if (this->num == nd.num) return true;
    return false;
}

ostream &operator<<(ostream &output, Node nd) {              // << overload (print Node)
    if (nd.getEdgPathDist() == INT_MAX)
        output << "(" << nd.getNodeNum() << ")" ;
    else
        output << "(" << nd.getNodeNum() << ":" << nd.getEdgPathDist() << ")";
    return output;
}

ostream &operator<<(ostream &output, list<Node> Lst) {        // << overload (print list<Node>)
    for(list<Node>::iterator i=Lst.begin(); i != Lst.end(); ++i) {
        output << (*i) << " ";
    }
    return output;
}

class Graph {                                               // Graph Class represented as an adjacency list of Nodes
private:
    int numV;			// Number of nodes of the Graph
    int numE;			// Number of edges of the Graph
    list<Node> adjList;		// Adjacency list of nodes representing the Graph
public:
    Graph():numV(0),numE(0) { adjList.clear(); };	          // Create an empty graph
    Graph(int nmVrtx);
    Graph(string filename);
    ~Graph() {};                                            // destructor
    int get_edge_value(int x, int y);
    void set_edge_value(int x, int y, int value);
    bool adjacent(int x, int y);
    list<Node> neighbors(int x);
    int Ver();
    int Edg();
    list<Node> ver();
};

Graph::Graph(int nmVrtx) {
    //Constructor of Graph Class Create an adjacency list with all nodes and number of edges
    numV = nmVrtx;
    numE = 0;
    adjList.clear();
    for(int i=0; i<nmVrtx; ++i) {
        Node newNode(i);
        adjList.push_back(newNode);
    }
}

// Constructor of Graph Class using information from file passed as argument
Graph::Graph(string filename) {
    ifstream file (filename);
    string line;    
    // Initialize an empty graph
    numV = 0;
    numE = 0;
    adjList.clear();
    
    if (file.is_open()) {	// Open file 'filename'
       	// Read the first line of file
        if(getline(file,line)){
            istringstream ss(line);
            ss >> numV;	
            // Assign the number read from file to the number of nodes in the graph (numV)  // chance to catch error here
            numE = 0;
            // Create adjacency list with all nodes and no edges
            adjList.clear();
            for(int i=0; i<numV; ++i) {
                Node newNode(i);
                adjList.push_back(newNode);
            }
        }
        else {
            cout << "Humpty Dumpty sat in the data and crushed it \n Sampledata File doesnot match required format\n";
            file.close();
            exit (1);
        }
        while(getline(file,line)){	// Read one edge line of file
                istringstream ss(line);
                int i,j,cost;
                ss >> i;
                ss >> j;
                ss >> cost;
                    if (i>numV||j>numV){
                        cout << "Humpty  sat in the data and crushed it \n Sampledata File doesnot match required format\n";
                        file.close();
                        exit (1);
                    }   
                set_edge_value(i,j,cost);	// Create the desired edge in the graph
                }
            }   
        file.close();	// Close file 'filename'
}

// Return edge pathDist between two nodes else INT_MAX(infinity) if edge doesn't exist
int Graph::get_edge_value(int x, int y) {
    for(list<Node>::iterator i=adjList.begin(); i != adjList.end(); ++i){
        if ((*i).getNodeNum() == x) {
            list<Node> iEdges = (*i).getEdges();
            for(list<Node>::iterator j=iEdges.begin(); j != iEdges.end(); ++j)
                if ((*j).getNodeNum() == y)
                    return (*j).getEdgPathDist(); 
        }
    }
    return INT_MAX;
}

// Set edge pathDist between two nodes
void Graph::set_edge_value(int x, int y, int value) {
    bool found;
    
    // Add 'y' in the list of 'x' neighbors with edge pathDist (value)(if doesn't exist) else set pathDist (value)
    for(list<Node>::iterator i=adjList.begin(); i != adjList.end(); ++i) {
        if ((*i).getNodeNum() == x) {
            found = false;
            list<Node> iEdges = (*i).getEdges();
            for(list<Node>::iterator j=iEdges.begin(); j != iEdges.end(); ++j){
                if ((*j).getNodeNum() == y) {  
                    (*j).setEdgPathDist(value);
                    found = true;
                }
            }
            if (!found) {
                Node newNodeY(y,value);	
                (*i).setEdg(newNodeY);
            }
        }
        
        // do same with node y as the list is non directional
        if ((*i).getNodeNum() == y) {
            found = false;
            list<Node> iEdges = (*i).getEdges();
            for(list<Node>::iterator j=iEdges.begin(); j != iEdges.end(); ++j){
                if ((*j).getNodeNum() == x) {  
                    (*j).setEdgPathDist(value);
                    found = true;
                }
            }
            if (!found) {
                Node newNodeX(x,value);	
                (*i).setEdg(newNodeX);
            }
        }
    }
    if (!found)
        ++numE;	  	// update the number of edges in the graph
}

// Return true if two nodes are neighbors, false otherwise
bool Graph::adjacent(int x, int y) {
    for(list<Node>::iterator i=adjList.begin(); i != adjList.end(); ++i){
        if ((*i).getNodeNum() == x) {
            list<Node> iEdges = (*i).getEdges();
            for(list<Node>::iterator j=iEdges.begin(); j != iEdges.end(); ++j)
                if ((*j).getNodeNum() == y)
                    return true;
        }
    }
    return false;
}

// Return a list<Node> containing list of neighbors of 'x'
list<Node> Graph::neighbors(int x) {
    list<Node> xEdges;
    for(list<Node>::iterator i=adjList.begin(); i != adjList.end(); ++i){
        if ((*i).getNodeNum() == x)
            xEdges = (*i).getEdges();
    }
    return xEdges;
}

// Return number of nodes in the Graph
int Graph::Ver() {
    return numV;
}

// Return number of edges in the Graph
int Graph::Edg() {
    return numE;
}

// Return a list<Node> containing all nodes in the Graph
list<Node> Graph::ver() {
    list<Node> nodesList;
    for(list<Node>::iterator i=adjList.begin(); i != adjList.end(); ++i) {
        Node newNode((*i).getNodeNum(),(*i).getEdgPathDist());
        nodesList.push_back(newNode);
    }
    return nodesList;
}

// overload operator << to print a graph
ostream &operator<<(ostream &output, Graph g) {
    output << endl;
    output << "   ";
    list<Node> gNodes = g.ver();
    for(list<Node>::iterator i=gNodes.begin(); i != gNodes.end(); ++i){
        if ((*i).getNodeNum() < 10)
            output << "  " << (*i).getNodeNum();
        else
            output << " " << (*i).getNodeNum();
    }
    output << endl;
    for(list<Node>::iterator i=gNodes.begin(); i != gNodes.end(); ++i) {
        if ((*i).getNodeNum() < 10)
            output << "  " << (*i).getNodeNum();
        else
            output << " " << (*i).getNodeNum();
        int shift=0;
        list<Node> iEdges = g.neighbors((*i).getNodeNum());
        for(list<Node>::iterator j=iEdges.begin(); j != iEdges.end(); ++j) {
            int walk=(*j).getNodeNum()-shift;
            for(int k=0; k<walk; ++k) {
                output << "  -";
                shift++;
            }
            if ((*j).getEdgPathDist() < 10)
                output << "  " << (*j).getEdgPathDist();
            else
                output << " " << (*j).getEdgPathDist();
            shift++;
        }
        while (shift<g.Ver()) {
            output << "  -";
            shift++;
        }
        output << endl;
    }
    return output;
}

// Class Edge to store information about edges (source, destination and pathDist)
class Edge {
private:
    int src;	// Source node
    int dst;	// Destination node
    int pathDist;	// WpathDist of the edge between src and dst
public:
    Edge():src(-1),dst(-1),pathDist(INT_MAX) {};
    Edge(int s, int d, int w):src(s),dst(d),pathDist(w) {};
    ~Edge() {};
    Edge& operator=(const Edge &e);
    bool operator== (const Edge& e) const;
    void set(int s, int d, int w) { src=s; dst=d; pathDist=w; };
    void setSrc(int s) { src = s; }; 
    void setDst(int d) { dst = d; }; 
    void setWpathDist(int w) { pathDist = w; }; 
    int getSrc() { return src; }; 
    int getDst() { return dst; }; 
    int getWpathDist() { return pathDist; }; 
};

// = overload
Edge& Edge::operator=(const Edge &e)
{
    this->src = e.src;
    this->dst = e.dst;
    this->pathDist = e.pathDist;
    return *this;
}

// == overload( true if two edges have the same src and dst, false otherwise)
bool Edge::operator== (const Edge& e) const {
    if ((this->src == e.src) && (this->dst == e.dst)) return true;
    return false;
}

// < overload (true if 'e1' pathDist is less then 'e2' pathDist, false otherwise)
bool operator< (Edge& e1, Edge& e2) {
    if (e1.getWpathDist() < e2.getWpathDist()) return true;
    return false;
}

// > overload (true if 'e1' pathDist is greater then 'e2' pathDist, false otherwise)
bool operator> (Edge& e1, Edge& e2) {
    if (e1.getWpathDist() > e2.getWpathDist()) return true;
    return false;
}
// << overload operator to print Edge
ostream &operator<<(ostream &output, Edge e) {
    output << "(" << e.getSrc() << "," << e.getDst() << "," << e.getWpathDist() << ")";
    return output;
}

// << overload operator to print list<Edge>
ostream &operator<<(ostream &output, list<Edge> L) {
    for(list<Edge>::iterator i=L.begin(); i != L.end(); ++i)
        output << (*i) << endl;
    return output;
}

// PriorityQueue Class (Generic) to store ordered elements of any TYPE

template<class TYPE>  //Type specifier
class PriorityQueue {
private:
    list<TYPE> pq;	// List of ordered elements min (higher priority) to max (lower priority)
public:
    PriorityQueue() { pq.clear(); };	// Create an empty list of TYPE
    ~PriorityQueue() {};
    void insert(TYPE e);
    TYPE top();
    int size();
};

// Insert element into priority queue
template<class TYPE>
void PriorityQueue<TYPE>::insert(TYPE e) {
    typename list<TYPE>::iterator found = find(pq.begin(), pq.end(), e);
    if (found == pq.end()) {
        pq.push_back(e);
        pq.sort();
    }
}

// Return the element with higher priority (firts element), removing it from the queue
template<class TYPE>
TYPE PriorityQueue<TYPE>::top() {
    TYPE e;
    if (! pq.empty()) {
        typename list<TYPE>::iterator i=pq.begin();
        e = (*i);
        pq.pop_front();
    }
    return e;
}

// Return the number of elements in the priority queue
template<class TYPE>
int PriorityQueue<TYPE>::size() {
    return pq.size();
}

// overload operator << to print a priority queue
template<class TYPE>
ostream &operator<<(ostream &output, PriorityQueue<TYPE> p) {
    while (p.size() != 0)
        output << p.top() << " ";
    return output;
}

// KruskalMST Class implementation to find a minimum spanning tree in a graph
class KruskalMST{
public:
    KruskalMST() {};
    KruskalMST(Graph g):graph(g) {};
    ~KruskalMST() {};
    list<Edge> tree();
    int cost();    
private:
    Graph graph;	// Graph used by Kruskal's Algorithm
    map<int, int> set;	// Map used to store nodes set
    void makeSet(Node n);
    int findSet(Node n);
    void combineSet(Node u, Node v);
};

// Assign node 'n' to a new set 
void KruskalMST::makeSet(Node n) {
    static int setNumber = 0;
    set[n.getNodeNum()] = setNumber++;
}

// Return set of node 'n' 
int KruskalMST::findSet(Node n) {
    return set[n.getNodeNum()]; 
}

// Move all nodes in same set of node 'v' to set of node 'u' 
void KruskalMST::combineSet(Node u, Node v) {
    int uSet = set[u.getNodeNum()], vSet = set[v.getNodeNum()];
    for (map<int,int>::iterator it=set.begin(); it != set.end(); ++it)
        if (it->second == vSet)
            set[it->first] = uSet;
}

// Return a list<Edge> containing the list of edges in the minimum spanning tree found by Kruskal's Algorithm
list<Edge> KruskalMST::tree() {
    list<Edge> mst;
    PriorityQueue<Edge> p;
    Node selected;
    Edge selectedEdge;
    
    // Add each node of the graph to its own set
    list<Node> allNodes = graph.ver();  
    for(list<Node>::iterator i=allNodes.begin(); i != allNodes.end(); ++i)
        makeSet(*i);
    
    // Insert all edges from the graph into priority queue
    for(list<Node>::iterator i=allNodes.begin(); i != allNodes.end(); ++i) {
        list<Node> iEdges = graph.neighbors((*i).getNodeNum());
        for(list<Node>::iterator j=iEdges.begin(); j != iEdges.end(); ++j) {
            Edge e((*i).getNodeNum(),(*j).getNodeNum(),(*j).getEdgPathDist());
            p.insert(e);
        }
    }
    
    while(p.size() != 0) {
        selectedEdge = p.top();	// Remove the lower edge from the priority queue
        if (findSet(selectedEdge.getSrc()) != findSet(selectedEdge.getDst())) {
            mst.push_back(selectedEdge);	// If src and dst are in different sets, then add this edge to mst
            combineSet(selectedEdge.getSrc(),selectedEdge.getDst());	// Combine both sets into one
        } 
    }
    return mst;
}

// Return the cost of the minimum spanning tree found by Kruskal's Algorithm
int KruskalMST::cost() {
    int mstCost=0;
    list<Edge> mst;
    mst = tree();
    for(list<Edge>::iterator i=mst.begin(); i != mst.end(); ++i)
        mstCost += (*i).getWpathDist();
    return mstCost;
}

// Monte Carlo Class to generate random graph
class MonteCarlo{
public:
    MonteCarlo();
    ~MonteCarlo() {};
    Graph randomGraph(int vert, double density, int minDistEdg, int maxDistEdg);
    void run(Graph g);
private:
};

// Constructor of MonteCarlo Class

MonteCarlo::MonteCarlo(){
    srand(time(NULL)); // Initializes the seed of random number generator
}

// Return a random Graph generated with number of nodes, density and edge pathDist range informed
Graph MonteCarlo::randomGraph(int nmVrtxt, double density, int minDistEdg, int maxDistEdg){
    int randDistEdg;
    
    Graph g(nmVrtxt);
    
    for (int i=0; i<g.Ver(); ++i){
        for (int j=i+1; j<g.Ver(); ++j)
        {
            double p = ((static_cast<double>(rand())) / RAND_MAX);	// Generate random probability
            if (p < density)	// If random probability is less than density, edge (i,j) will be set
            {
                randDistEdg = rand() % (maxDistEdg - minDistEdg) + minDistEdg; // Generate random edge pathDist 
                g.set_edge_value(i,j,randDistEdg);
            }
        }
    }
        return g;
}

// Run a simulation finding Kruskal's MST in a given graph 
void MonteCarlo::run(Graph g){
    static int count=0;
    
    cout << endl << "=== RUNNING SiMULATION " << ++count << " ===" << endl;
    
    // Print out graph information
    double d = static_cast<double>(g.Edg())/((static_cast<double>(g.Ver())*static_cast<double>(g.Ver())-1)/2)*100;	// Calculate real density reached
    cout << "Vertices: " << g.Ver() << endl;
    cout << "Edges: " << g.Edg() << " (density: " << d << "%)" << endl;
    
    cout << "============================" << endl;
    
    KruskalMST kruskal(g);
    cout << "Kruskal MST: " <<endl << kruskal.tree() << endl;
    cout << "Kruskal MST cost: " << kruskal.cost() << endl;
}

// Main Function
int main(){
    MonteCarlo simu;
    
    // Reading the example graph from file and calculating MST cost
    Graph g("sampletestdata");
    simu.run(g);
    
    /*  // commenting block out
    //Generate random graph (10 nodes and 40% density) and calculate MST cost
     Graph g1 = simu.randomGraph(10,0.4,1,10);  // (node, density, min pathDist, max pathDist)
     simu.run(g1);
    //*/
    return 0;  
}


/*********************************************************
 *                      OUTPUT                           *
 *********************************************************
=== RUNNING SiMULATION 1 ===
Vertices: 20
Edges: 172 (density: 86.2155%)
============================
Kruskal MST: 
(1,6,1)
(1,17,1)
(2,9,1)
(3,12,1)
(4,7,1)
(4,8,1)
(5,6,1)
(5,18,1)
(11,12,1)
(11,14,1)
(12,17,1)
(0,2,2)
(4,15,2)
(5,16,2)
(7,10,2)
(15,19,2)
(8,9,3)
(9,12,3)
(9,13,3)

Kruskal MST cost: 30

**********************************************************/
