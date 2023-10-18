#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cmath>

double probability(){ return 1.0*rand()/RAND_MAX;}


using namespace std;
//class that has make_graph as constructor
class Graph{
   public:
      Graph(int s, double density);
      void print_graph();
   private:
      int size;
      vector<vector<bool> > g1; //A vector of vectors of bools
      //Think of a vector as a first in, last out Data Structure
};


//make_graph altered to work in c++
Graph::Graph(int s, double density){
   this->size = s;
   for (int i = 0; i < s; ++i){
        // We push a new vector of bool onto the initial vector s times
        // The * is there to dereference the new vector that we insert
        this->g1.push_back( *( new vector<bool>() ) );
        for (int j = 0; j < s; ++j){
            //then, on each of those vectors, we push a default "false" s times
            this->g1.at(i).push_back(false);
        }
   }
   //Don't have to change this part much
   for (int i = 0; i < s; ++i){
      for (int j = 0; j < s; ++j){
        if (probability()< density) this->g1[i][j] = true;
      }
   }
}

//simple conversion, just needed 'this'
void Graph::print_graph(){
cout << "graph size " << this->size << "\n";
   for(int i = 0; i < this->size; ++i){
      for (int j = 0; j < this->size; ++j){
         cout << this->g1[i][j] << "\t";
      }
      cout << "\n";
   }
}

int main(){
    srand(time(0));
    cout << "Test simple graph generation\n";
    Graph* test1 = new Graph(10, 0.7);
    test1->print_graph();
    cout << "\nEND of TEST 1\n\n";
    Graph* test2 = new Graph(50, 0.4);
    test2->print_graph();
    cout << "\nEND of TEST 2\n\n";
    return 0;
}
