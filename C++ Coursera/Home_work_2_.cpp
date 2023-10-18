#include <bits/stdc++.h>

using namespace std;

class graph
{
private:
    const unsigned int v_;
    unsigned int e_;
    vector<double> adj_;

protected:
    unsigned int index_for(unsigned int x, unsigned int y) const {
        if (x >= v_ || y >= v_)
            throw invalid_argument("Index out of bounds!");
        return x * v_ + y;
    }

public:
    graph(unsigned int v): v_(v), e_(0), adj_(v * v, 0) {}
    unsigned int V() const { return v_; }
    unsigned int E() const { return e_; }
    bool adjacent(unsigned int x, unsigned int y) const {
        return adj_[index_for(x, y)] > 0;
    }
    vector<unsigned int> neighbors(unsigned int x) const {
        vector<unsigned int> result;
        for (int i = 0; i < v_; ++i)
            if (adjacent(x, i))
                result.push_back(i);
        return result;
    }

    // Add edge from node x to node y
    void add_edge(unsigned int x, unsigned int y, double weight) {
        if (weight < 0)
            throw invalid_argument("Weight of an edge can not be negative!");
        if (adj_[index_for(x, y)] == 0)
            ++e_;
        adj_[index_for(x, y)] = weight;
        adj_[index_for(y, x)] = weight;
    }

    // Remove edge from node x to node y
    void remove_edge(unsigned int x, unsigned int y) {
        adj_[index_for(x, y)] = 0;
        adj_[index_for(y, x)] = 0;
        --e_;
    }

    double get_edge_value(unsigned int x, unsigned int y) {
        return adj_[index_for(x, y)];
    }
};


class ShortestPath {
public:

    ShortestPath(graph g, unsigned int source = 0):
        g_(g),
        dist_(g.V(), numeric_limits<double>::max()),
        source_(source) {
        compute();
    }
    double operator[](int idx) const {
        return dist_[idx];
    }
protected:
    void compute() {
        priority_queue<DistNode, vector<DistNode>, less<DistNode>> nodes;

        nodes.push(make_tuple(0, source_));

        while (!nodes.empty()) {
            double d;
            unsigned int n;
            tie(d, n) = nodes.top();
            nodes.pop();
            if (d < dist_[n])
                dist_[n] = d;

            for (const auto& w: g_.neighbors(n)) {
                auto new_dist = dist_[n] + g_.get_edge_value(n, w);
                if (new_dist < dist_[w]) {
                    dist_[w] = new_dist;
                    nodes.push(make_tuple(new_dist, w));
                 }}}}
private:
    graph g_;
    vector<double> dist_;
    unsigned int source_;
    using DistNode = tuple<double, unsigned int>;
};

class S{
public:
    S(int num = 50, double density = 0.2,
              double distance_min = 1, double distance_max = 10,
              int times = 50):
        num(num),
        den(density),
        random_generator_(time(NULL)),
        distance_distribution_(distance_min, distance_max),
        existence_distribution_(0.0, 1.0) {
        double sum_avg_dist = 0;
        for (int i = 0; i < times; ++i) {
            sum_avg_dist += run_simulation();
        }
        avg = sum_avg_dist / times;
        }
    double average_distance() const {
        return avg;
    }
protected:
    double run_simulation() {
        graph g = generate_graph();
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
    graph generate_graph() {
        graph g(num);
        for (int i = 0; i < num- 1; ++i)
            for (int j = i + 1; j < num; ++j)
                if (existence_distribution_(random_generator_) < den)
                    g.add_edge(i, j, distance_distribution_(random_generator_));

        return g;
    }
private:
    double avg;
    int num;
    double den;
    mt19937 random_generator_;
    uniform_real_distribution<double> distance_distribution_;
    uniform_real_distribution<double> existence_distribution_;
};

int main()
{
    cout << "Monte Carlo simulation that calculates the average shortest path in a graph: \n" << endl;

    S sim20;
    cout << "For 20% density: "<< sim20.average_distance()<<" is the average distance" << endl;

    S sim40(50, 0.4);
    cout << "For 40% density: "<< sim40.average_distance()<<" is the average distance" << endl;

    return 0;
}
