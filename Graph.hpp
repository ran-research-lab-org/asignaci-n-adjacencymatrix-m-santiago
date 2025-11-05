// Michelle A. Santiago 
// 801 - 23 - 5483

#include <iostream>
#include <vector>
#include <stdexcept>
#include <map>

using namespace std;

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    // Crea un vector de 2D n x n
    Graph(int n) : numVertices(n), adjMatrix(n, std::vector<int>(n, 0)) {}

    // Add a vertex from node u to node v
    void addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjMatrix[u][v] = 1;
        } else {
            std::out_of_range("Vertice fuera de rango");
        }
    }

    // Imprime la matriz de adyacencias
    void print() const {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // Implementar!! 
    // Devuelve la cantidad de aristas
    int numEdges() const {

        // en los grafos dirigidos, las aristas son representadas por 1
        // debido a esto, tengo que contar las incidencias de 1

        int edges = 0;

        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
               if (adjMatrix[i][j] == 1) edges++;
            }
        }

        return edges;
    }

    // Completa esta función
    // Devuelve el in-degree de un vertice
    int inDegree(int u) const {

        int inDegree = 0;

        // en los grafos dirigidos el in-degree es el número de aristas que 'entran' a un vértice
        // en la matriz, esto se ve por medio de las columnas, no las filas
        // por ende, si quiero saber el 'in-degree' de un vértice, tengo que moverme hacia abajo

        if (u < 0 || u >= numVertices)
            throw std::out_of_range("Vertice fuera de rango");
        else {
            for (int j = 0; j < numVertices; ++j) {
                if (adjMatrix[u][j] == 1) inDegree++;
            }
            
        }
        return inDegree;
    }

    // Completa esta función
    // Devuelve cierto si u es el nodo con mayor inDegree.
    // En caso de que haya varios nodos que tengan el mayor inDegree,
    // devuelve true si u es uno de ellos
    bool isInfluencer(int u) {

        multimap<int, int> D;
        auto it = D.begin();

        int degree = 0;

        if (u < 0 || u >= numVertices)
            throw std::out_of_range("Vertice fuera de rango");
        else {
            for (int i = 0; i < numVertices; ++i) {

                for (int j = 0; j < numVertices; ++j) {
                    if (adjMatrix[i][j] == 1) ++degree;
                }
                cout << "the degree for " << i << " is: " << degree << endl;
                D.insert({degree, i});
                degree = 0;
            }  
            auto itr = D.end();
            itr--;
            int first = itr->second;

            for (const auto& pair : D) {
                cout << "key: " << pair.first << ", value: " << pair.second << endl;
            }

            // auto range = D.equal_range(first);
            // for (auto it = range.first; it != range.second; ++it) {
            //     cout << "esto es it->second: " << it->second << endl;
            //     if (it->second == u) return true;
    
            // }    
            return false;
        }
    }
};

