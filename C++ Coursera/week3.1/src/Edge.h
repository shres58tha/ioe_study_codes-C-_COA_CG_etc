#ifndef EDGE_H
#define EDGE_H

/*
    Edge class represent an edge of the graph and it includes the indexes of the connecting nodes and its weight.
*/

class Edge
{
    public:
        Edge(int i,int j,double w):first(i),second(j),weight(w){};
        int getFirstNode(){return first;}
        int getSecondNode(){return second;}
        double getWeight(){return weight;}

    private:
        int first, second;
        double weight;
};

#endif
