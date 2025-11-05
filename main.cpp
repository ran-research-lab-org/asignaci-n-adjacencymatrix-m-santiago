// Michelle A. Santiago
// 801 - 23 - 5483

#include "Graph.hpp"
#include <map>

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

  bool influencer = G.isInfluencer(4);

  cout << endl;
  cout << "El número de aristas es: " << edges << endl;

  cout << endl;
  cout << "El in-degree del vértice 4 es: " << degree << endl;

  cout << endl;
  cout << "El in-degree de 4 es el mayor. Esto es: " << influencer << endl;
}
