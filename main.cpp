#include "Graph.hpp"

using namespace std;

int main() {
  Graph G(10);
  G.addEdge(0,9);
  G.addEdge(4, 2);

  G.print();

  int edges = G.numEdges();

  cout << endl;
  cout << "El número de aristas es: " << edges << endl;
}
