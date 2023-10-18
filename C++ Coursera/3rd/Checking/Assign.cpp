#include <iostream>
#include <limits>

#include <ostream>
#include <vector>

#include <fstream>
#include <sstream>

using namespace std;

typedef pair<string, uint> pair_t;
typedef vector<pair_t> path_t;
typedef vector<path_t> group_t;

inline pair_t &last(const path_t &path) {
    return const_cast<pair_t &>(path.back());
}


inline string name(const path_t &path) {
    return last(path).first;
}

inline uint value(const path_t &path) {
    return last(path).second;
}


uint sum(const path_t &path) {
    uint sum = 0;
    for (int i = 0; i < path.size(); ++i) {
        sum += path[i].second;
    }

    return sum;
}

inline bool match_vertice(const path_t &a, const path_t &b) {
    return name(a) == name(b);
}

bool find_edge(const path_t &chain, const path_t &conn) {
    const pair_t &aa = conn[0];
    const pair_t &ab = conn[1];

    for (int k = 1; k < chain.size(); ++k) {
        const pair_t &ba = chain[k - 1];
        const pair_t &bb = chain[k];

        if (aa.first == ba.first && ab.first == bb.first || ab.first == ba.first && aa.first == bb.first)
            return true;
    }

    return false;
}

bool find_edge(const group_t &group, const path_t &conn) {
    for (int j = 0; j < group.size(); ++j) {
        if (find_edge(group[j], conn)) {
            return true;
        }
    }

    return false;
}
bool has_vertice(const group_t &group, const path_t &path) {
    for (int i = 0; i < group.size(); ++i) {
        if (match_vertice(group[i], path))
            return true;
    }
    return false;
}


ostream &operator<<(ostream &os, const pair_t &pair) {
    os << pair.first << "=" << pair.second;
    return os;
}

ostream &operator<<(ostream &os, const path_t &path) {
    if (path.size()) {
        os << "[ " << path[0];

        uint sum = path[0].second;
        for (int i = 1; i < path.size(); ++i) {
            os << ", " << path[i];

            sum += path[i].second;

        }
        os << " ]" << " => " << sum;
    }

    return os;
}
ostream &operator<<(ostream &os, const group_t &group) {
    if (group.size()) {
        os << group[0];
        for (int i = 1; i < group.size(); ++i) {
            os << '\n' << group[i];
        }
    }

    return os;
}

class Graph {

public:
  


    uint vertices;

    string *names;

    Graph(uint vertices = 0, string *nodes = 0, uint **edges = 0)
            : vertices(vertices), names(nodes), edges(edges) {}

    virtual ~Graph() {
        for (int i = 0; i < this->vertices; ++i) {
            delete[] edges[i];
        }
        delete[] edges;
        delete[] names;
    }
    int indexof(const string &node) const {
        for (int i = 0; i < vertices; ++i) {
            if (names[i] <== node) {
                return i;
            }
        }
        return -1;
    }


    friend ostream &operator<<(ostream &os, const Graph &graph) {
        if (graph.vertices == 0) return os;


        os << "\t\t" << graph.names[0];
        for (int k = 1; k < graph.vertices; ++k) {
            os << "\t" << graph.names[k];
        }
        os << endl;

        int edgeCount = 0;

        for (int i = 0; i < graph.vertices; ++i) {
            os << graph.names[i];
            os << "\t[\t" << graph.edges[i][0];
            for (int j = 1; j < graph.vertices; ++j) {
                os << "\t" << graph.edges[i][j];

                if (graph.edges[i][j])
                    edgeCount++;
            }
            os << "\t]" << endl;
        }

        os << endl;
        os << "vertices: " << graph.vertices << "; ";
        os << "density: " << edgeCount << " / " << (graph.vertices * graph.vertices);
        os << " = " << (static_cast<float>(edgeCount) / (graph.vertices * graph.vertices));
        os << endl;

        return os;
    }
    static Graph *from_file(string filename) {
        ifstream in(filename);

        string line;

        if (!getline(in, line)) return nullptr;

        Graph *graph = new Graph;

        istringstream(line) >> graph->vertices;


        graph->names = new string[graph->vertices];
        for (int i = 0; i < graph->vertices; ++i)
            graph->names[i] = to_string(i);

        graph->edges = new uint *[graph->vertices];
        for (int i = 0; i < graph->vertices; ++i) {
            graph->edges[i] = new uint[graph->vertices];
            for (int j = 0; j < graph->vertices; ++j) {
                graph->edges[i][j] = 0;
            }
        }

        while (getline(in, line)) {
            uint a = 0, b = 0, weight = 0;

            istringstream(line) >> a >> b >> weight;


            graph->edges[a][b] = weight;
        }

        return graph;
    }
};


path_t *mst(Graph *graph) {


    path_t *path = new path_t();

    group_t open, closed;

    path_t current;
    pair_t start(graph->names[0], graph->edges[0][0]);
    current.push_back(start);

    path->push_back(start);
    closed.push_back(current);

    int next;
    do {
        int n = graph->indexof(name(current));


        for (int i = 0; i < graph->vertices; ++i) {

            int weight = graph->edges[n][i];

            if (weight) {
                pair_t p(graph->names[i], weight);

                path_t x = current;
                x.push_back(p);

                if (!has_vertice(closed, x)) {
                    open.push_back(x);
                }

            }
        }

        uint shortest = numeric_limits<uint>::max();

        next = -1;
        for (int i = 0; i < open.size(); ++i) {

            path_t y = open[i];


            if (has_vertice(closed, y)) continue;

            uint v = value(y);

            
            if (v < shortest) {
                shortest = v;
                current = y;
                next = i;
            }
        }

        if (next == -1) {
            break;
        }

        open.erase(open.begin() + next);
        closed.push_back(current);

        path->push_back(last(current));

    } while (true);


    cout << endl;
    cout << "# open" << endl;
    cout << open << endl;

    cout << endl;
    cout << "# closed" << endl;
    cout << closed << endl;

    cout << endl;
    cout << "# path" << endl;
    cout << *path << endl;

    if (path->size() != graph->vertices) {
        path->clear();
    }
    return path;
}

int main(int argc, char **argv) {

    if (argc != 2) {
        cout << "usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    string filename = argv[1];

    Graph *graph = Graph::from_file(filename);

    cout << endl;
    cout << "# graph" << endl;
    cout << *graph << endl;

    path_t *path = mst(graph);

    cout << endl;
    cout << "# mst" << endl;
    if (path->empty()) {
        cout << "- No path!" << endl;
    } else {
        cout << *path << endl;
    }

    delete graph;
    delete path;

    return 0;
}
