// C++ implementation of finding average path by dijkstra's algotithm 

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

Node& Node::operator=(const Node &nd) {                     // overload = operator class Node data
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
    string firstline, otherlines;
    regex firstlineformat( "^\\d+$",regex::icase);	// regex that matches with the first line format icase == ignore case
    // \\d matches to numbers char till end of string
    regex otherlinesformat( "^\\s*(\\d+)\\s+(\\d+)\\s+(\\d+)\\s*$",regex::icase);	// regex that matches with edge lines format   \\ s* ignore space or non numerical digits match diigits ignore space match digit ...... alternating
    match_results<string::const_iterator> result;
    
    // Initialize an empty graph
    numV = 0;
    numE = 0;
    adjList.clear();
    
    if (file.is_open()) {	// Open file 'filename'
        getline(file,firstline);	// Read the first line of file
        if (regex_match(firstline, result, firstlineformat)){	// Check if the first line is in the apropriate format (only one number)
            // Create nodes
            numV = stoi(result[0]);	// Assign the number read from file to the number of nodes in the graph (numV)
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
        
        while(getline(file,otherlines)){	// Read one edge line of file
            if (regex_match(otherlines, result, otherlinesformat)) {	// Check if the line is in the apropriate format: i j cost (three numbers)
                int i = stoi(result[1]);
                int j = stoi(result[2]);
                int cost = stoi(result[3]);
                
                    if (i>numV||j>numV){
                        cout << "Humpty Dumpty sat in the data and crushed it \n Sampledata File doesnot match required format\n";
                        file.close();
                        exit (1);
                    }   
                    
                set_edge_value(i,j,cost);	// Create the desired edge in the graph
            }
            else {
                cout << "Humpty Dumpty sat in the data and crushed it \n Sampledata File doesnot match required format\n";
                file.close();
                exit (1);
            }   
        }
        file.close();	// Close file 'filename'
    }
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
        output << (*i) << " ";
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


// PrimMST Class immplementing Prim's Algorithm to find a minimum spanning tree in a graph

class PrimMST
{
public:
    PrimMST() {};
    PrimMST(Graph g):graph(g) {};
    ~PrimMST() {};
    list<Edge> tree();
    int cost();
    
private:
    Graph graph;	// Graph used by Prim's Algorithm
    bool isSrcInSet (Edge e, list<Node> L);
    bool isDstInSet (Edge e, list<Node> L);
    Node getNodeInSet (int num, list<Node> L);
};

// Return true if edges 'e' src is in node list 'L' and false otherwise
bool PrimMST::isSrcInSet (Edge e, list<Node> L) {
    list<Node>::iterator found = find(L.begin(), L.end(), e.getSrc());
    if (found != L.end()) return true;
    return false;
}

// Return true if edges 'e' dst is in node list 'L' and false otherwise
bool PrimMST::isDstInSet (Edge e, list<Node> L) {
    list<Node>::iterator found = find(L.begin(), L.end(), e.getDst());
    if (found != L.end()) return true;
    return false;
}

// Return node with nodeNumber 'num' in node list 'L'
Node PrimMST::getNodeInSet (int num, list<Node> L) {
    Node n(num);
    list<Node>::iterator found = find(L.begin(), L.end(), n);
    if (found != L.end()) return (*found);
    return (Node());
}

// Return a list<Edge> containing the list of edges in the minimum spanning tree found by Prim's Algorithm
list<Edge> PrimMST::tree() {
    list<Edge> mst;
    PriorityQueue<Edge> p;
    Node selected;
    Edge selectedEdge;
    
    // Create selectedNodes empty set
    // Create candidateNodes set containing all nodes
    list<Node> selectedNodes;
    list<Node> candidateNodes = graph.ver();
    
    while (!candidateNodes.empty()) {
        // Add first node from candidateNodes set to selectedNodes set and remove it from candidateNodes
        selected = candidateNodes.front();
        selectedNodes.push_back(selected);
        candidateNodes.remove(selected);
        
        // Insert all edges from first node into priority queue
        list<Node> sEdges = graph.neighbors(selected.getNodeNum());
        for(list<Node>::iterator j=sEdges.begin(); j != sEdges.end(); ++j) {
            Edge e(selected.getNodeNum(),(*j).getNodeNum(),(*j).getEdgPathDist());
            p.insert(e);
        }
        
        while(p.size() != 0) {
            selectedEdge = p.top();	// Remove the lower edge from the priority queue
            if ((isSrcInSet(selectedEdge,selectedNodes)) && (isDstInSet(selectedEdge,candidateNodes))) {
                mst.push_back(selectedEdge);
                // Add selected node to selectedNodes set and remove it from candidateNodes set
                selected = getNodeInSet(selectedEdge.getDst(),candidateNodes);
                selectedNodes.push_back(selected);
                candidateNodes.remove(selected);
                // Insert all edges from dst node into priority queue
                sEdges = graph.neighbors(selected.getNodeNum());
                for(list<Node>::iterator j=sEdges.begin(); j != sEdges.end(); ++j) {
                    Edge e(selected.getNodeNum(),(*j).getNodeNum(),(*j).getEdgPathDist());
                    p.insert(e);
                }
            } 
        }
    }
    
    return mst;
}

// Return the cost of the minimum spanning tree found by Prim's Algorithm
int PrimMST::cost() {
    int mstCost=0;
    list<Edge> mst;
    mst = tree();
    for(list<Edge>::iterator i=mst.begin(); i != mst.end(); ++i)
        mstCost += (*i).getWpathDist();
    return mstCost;
}


// KruskalMST Class
// Implements Kruskal's Algorithm to find a minimum spanning tree in a graph

class KruskalMST
{
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

// Return the set of node 'n' 
int KruskalMST::findSet(Node n) {
    return set[n.getNodeNum()]; 
}

// Move all nodes in the same set of node 'v' to the set of node 'u' 
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


// Monte Carlo Class
// Used to generate random graphs and run simulations 

class MonteCarlo
{
public:
    MonteCarlo();
    ~MonteCarlo() {};
    Graph randomGraph(int vert, double density, int minDistEdge, int maxDistEdge);
    void run(Graph g);
    
private:
};

// Constructor of MonteCarlo Class
// Initializes the seed of random number generator
MonteCarlo::MonteCarlo()
{
    srand(time(NULL));
}

// Return a random Graph generated with number of nodes, density and edge pathDist range informed
Graph MonteCarlo::randomGraph(int nmVrtxt, double density, int minDistEdge, int maxDistEdge)
{
    int randDistEdge;
    
    Graph g(nmVrtxt);
    
    for (int i=0; i<g.Ver(); ++i){
        for (int j=i+1; j<g.Ver(); ++j)
        {
            double p = ((static_cast<double>(rand())) / RAND_MAX);	// Generate random probability
            if (p < density)	// If random probability is less than density, edge (i,j) will be set
            {
                randDistEdge = rand() % (maxDistEdge - minDistEdge) + minDistEdge; // Generate random edge pathDist 
                g.set_edge_value(i,j,randDistEdge);
            }
        }
    }
        return g;
}

// Run a simulation finding the Prim's and Kruskal's MST in a given graph 
void MonteCarlo::run(Graph g)
{
    static int turn=0;
    
    cout << endl << "=== RUNNING SIMULATION No. " << ++turn << " ===" << endl;
    
    // Print out graph information
    double d = static_cast<double>(g.Edg())/((static_cast<double>(g.Ver())*static_cast<double>(g.Ver())-1)/2)*100;	// Calculate real density reached
    cout << "Vertices: " << g.Ver() << endl;
    cout << "Edges: " << g.Edg() << " (density: " << d << "%)" << endl;
    cout << "Nodes: " << g.ver() << endl;
    cout << "Graph: " << g << endl;
    
    PrimMST prim(g);
    cout << "Prim MST: " << prim.tree() << endl;
    cout << "Prim MST cost: " << prim.cost() << endl;
    cout << endl;
    
    KruskalMST kruskal(g);
    cout << "Kruskal MST: " << kruskal.tree() << endl;
    cout << "Kruskal MST cost: " << kruskal.cost() << endl;
}


// Main Function

int main()
{
    MonteCarlo simulation;
    
    // Reading the example graph from file and calculating MST cost
    Graph g("sampletestdata");
    simulation.run(g);
    
    // Generating a rendom graph (10 nodes and 20% density) and calculating MST cost
    // Graph g2 = simulation.randomGraph(10,0.2,1,10);
    // simulation.run(g2);
    
    // Generating a rendom graph (10 nodes and 40% density) and calculating MST cost
    // Graph g3 = simulation.randomGraph(10,0.4,1,10);
    // simulation.run(g3);
    
    return 0;  
}
