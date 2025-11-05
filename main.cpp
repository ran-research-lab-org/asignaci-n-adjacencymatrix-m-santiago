#include "Graph.hpp"

using namespace std;

int main() {
  Graph G(10);
  G.addEdge(0, 9);
  G.addEdge(4, 2);
  G.addEdge(4, 5);
  G.addEdge(4, 9);

  G.print();

  int edges = G.numEdges();

  int degree = G.inDegree(4);

  cout << endl;
  cout << "El número de aristas es: " << edges << endl;

  cout << endl;
  cout << "El in-degree del vértice 4 es: " << degree << endl;
}
