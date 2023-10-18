 

// Note: This should be compiled with C++11 enable!

#include <exception>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <random>
#include <tuple>

#include <ctime>

using namespace std;

class Graph
{
public:
    /// Initialize a graph with v vertices. Use an 1-dimension array with v*v
    /// places to store the adjacency matrix.
    ///
    /// @param v number of vertices
    Graph(unsigned int v): v_(v), e_(0), adj_(v * v, 0) {}

    /// @return number of vertices in the graph
    unsigned int V() const { return v_; }

    /// @return number of edges in the graph
    unsigned int E() const { return e_; }

    /// @return true if there is an edge from node x to node y
    bool adjacent(unsigned int x, unsigned int y) const {
        return adj_[index_for(x, y)] > 0;
    }

    /// @return list of all nodes y that connected to node x
    vector<unsigned int> neighbors(unsigned int x) const {
        vector<unsigned int> result;
        for (int i = 0; i < v_; ++i)
            if (adjacent(x, i))
                result.push_back(i);

        return result;
    }

    /// Add an edge from node x to node y
    void add_edge(unsigned int x, unsigned int y, double weight) {
        if (weight < 0)
            throw invalid_argument("Weight of an edge can not be negative!");
        if (adj_[index_for(x, y)] == 0)
            ++e_;

        adj_[index_for(x, y)] = weight;
        adj_[index_for(y, x)] = weight;
    }

    /// Remove the edge from node x to node y
    void remove_edge(unsigned int x, unsigned int y) {
        adj_[index_for(x, y)] = 0;
        adj_[index_for(y, x)] = 0;
        --e_;
    }

    /// @return the value of the edge from x to y
    double get_edge_value(unsigned int x, unsigned int y) {
        return adj_[index_for(x, y)];
    }

protected:
    /// @return Convert index of 2-dimension array to a 1-dimension array
    unsigned int index_for(unsigned int x, unsigned int y) const {
        if (x >= v_ || y >= v_)
            throw invalid_argument("Index out of bounds!");

        return x * v_ + y;
    }

private:
    const unsigned int v_;
    unsigned int e_;
    vector<double> adj_;
};


class ShortestPath {
public:
    /// This class compute the shortest path for the given graph g
    /// from the start node source to all other nodes.
    ///
    /// @param g the given graph
    /// @param source the start node
    ShortestPath(Graph g, unsigned int source = 0):
        g_(g),
        dist_(g.V(), numeric_limits<double>::max()),
        source_(source) {
        compute();
    }

    /// @return the distance from the source node to the node idx
    double operator[](int idx) const {
        return dist_[idx];
    }
protected:
    /// Compute the shortest path from the given start node to all other
    /// nodes with the Dijkstra algorithms.
    /// See:
    /// - http://en.wikipedia.org/wiki/Dijkstra's_algorithm#Pseudocode
    /// - https://github.com/networkx/networkx/blob/master/networkx/algorithms/shortest_paths/weighted.py#L248
    void compute() {
        // queue of the next node to visit
        // each elements is a tuple of the distance to the node and the node's id
        // this priority queue is sorted with the minimum distance at the top
        priority_queue<DistNode, vector<DistNode>, less<DistNode>> nodes;

        // start the queue with the source node,
        // the distance to itself is 0
        nodes.push(make_tuple(0, source_));

        while (!nodes.empty()) {
            // extract the next node and distance from the queue
            double d;
            unsigned int n;
            tie(d, n) = nodes.top();
            nodes.pop();

            // update the distance array and find the next nodes to visit
            if (d < dist_[n])
                dist_[n] = d;

            for (const auto& w: g_.neighbors(n)) {
                auto new_dist = dist_[n] + g_.get_edge_value(n, w);
                if (new_dist < dist_[w]) {
                    dist_[w] = new_dist;
                    nodes.push(make_tuple(new_dist, w));
                }
            }
        }
    }

private:
    Graph g_;

    // Store the final distance from the source node
    vector<double> dist_;

    unsigned int source_;

    // Tuple type to store the distance from the source node to a node and that node's id
    using DistNode = tuple<double, unsigned int>;
};


class Simulator {
public:
    /// Create a simulator with the given parameter
    ///
    /// @param num number of vertices in a graph
    /// @param density of the generated graph
    /// @param distance_min
    /// @param distance_max
    /// @param times number of times to run the simulation
    Simulator(int num = 50, double density = 0.2,
              double distance_min = 1, double distance_max = 10,
              int times = 50):
        num_(num),
        den_(density),
        random_generator_(time(NULL)),
        distance_distribution_(distance_min, distance_max),
        existence_distribution_(0.0, 1.0) {
        double sum_avg_dist = 0;
        for (int i = 0; i < times; ++i) {
            sum_avg_dist += run_simulation();
        }
        avg_ = sum_avg_dist / times;
    }

    /// @return the average distance of the shortest path
    double average_distance() const {
        return avg_;
    }

protected:
    /// Generate a graph and run the simulation.
    /// @return the average shortest path of the generated graph
    double run_simulation() {
        Graph g = generate_graph();
        ShortestPath sp(g, 0);
        int count = 0;
        double sum = 0;

        for (int i = 1; i < g.V(); ++i)
            if (sp[i] < numeric_limits<double>::max()) {
                ++count;
                sum += sp[i];
            }

        return sum / count;
    }

    /// @return a generated graph with given parameter
    Graph generate_graph() {
        Graph g(num_);
        for (int i = 0; i < num_ - 1; ++i)
            for (int j = i + 1; j < num_; ++j)
                if (existence_distribution_(random_generator_) < den_)
                    g.add_edge(i, j, distance_distribution_(random_generator_));

        return g;
    }

private:
    double avg_;
    int num_;
    double den_;
    mt19937 random_generator_;
    uniform_real_distribution<double> distance_distribution_;
    uniform_real_distribution<double> existence_distribution_;
};


int main()
{
    cout << "Starting..." << endl;

    Simulator sim20;
    cout << "Density 20%: average distance is "
         << sim20.average_distance() << endl;

    Simulator sim40(50, 0.4);
    cout << "Density 40%: average distance is "
         << sim40.average_distance() << endl;

    return 0;
}


/*
 Graph.scala
class Graph(val V: Int) {
  private var e = 0;
  private val adj = Array.fill[Double](V * V)(0)
  
  def E = e;

  def apply(x: Int) = for (y <- 0 until V if isAdjacent(x, y)) yield y

  def apply(x: Int, y: Int) = adj(indexFor(x, y))

  def isAdjacent(x: Int, y: Int) = adj(indexFor(x, y)) > 0

  def addEdge(x: Int, y: Int, cost: Double) {
    if (cost <= 0) return
    if (adj(indexFor(x, y)) == 0) e += 1
    adj(indexFor(x, y)) = cost
    adj(indexFor(y, x)) = cost
  }

  def removeEdge(x: Int, y: Int) {
    adj(indexFor(x, y)) = 0
    adj(indexFor(y, x)) = 0
    e -= 1
  }

  def indexFor(x: Int, y: Int) =
    if (x < 0 || x >= V || y < 0 || y >= V) throw new Exception("Index out of Bounds!")
    else x * V + y
}

class ShortestPath(val g: Graph, val source: Int = 0) {
  import scala.collection.mutable.PriorityQueue
  private val dist = Array.fill[Double](g.V)(Double.MaxValue)
  private val pq = new PriorityQueue[(Double, Int)]()
  pq += ((0, 0))
  while (!pq.isEmpty) {
    val (d, n) = pq.dequeue()
    if (d < dist(n)) dist(n) = d
    g(n).foreach { w =>
      val new_d = g(n, w) + dist(n)
      if (new_d < dist(w)) {
        dist(w) = new_d
        pq += ((new_d, w))
      }
    }
  }

  def apply(x: Int) = dist(x)
}

object Graph {
  def main(args: Array[String]) {
    val g = new Graph(4)
    g.addEdge(0, 1, 3.0)
    g.addEdge(0, 2, 1)
    g.addEdge(1, 2, 1)
    g.addEdge(1, 3, 2.5)

    val sp = new ShortestPath(g)
    for (i <- 0 to 3) { println(sp(i)) }
  }
}
*/
