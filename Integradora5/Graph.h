// Esta clase permite representar grafos dirigidos ponderados
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include "LinkedList.h"
#include "ipAddress.h"
#include "HashTable.h"

class Graph {
  private:
    int numNodes;
    int numEdges;
    // Lista de adyacencia (vector de listas ligadas de pares nodo,peso)
    std::vector<LinkedList<std::pair<int, int>>> adjList;
    // vector de objetos ipAddress para contar los grados (in y out)
    std::vector<ipAddress> ips;
    // Tabla Hash
    HashTable<unsigned int, ipAddress> myHashTable;

    void split(std::string line, std::vector<int> & res);
    unsigned int getIPValue(std::string ipString);
    int binarySearch(ipAddress key);

    std::set<std::string, std::greater<std::string>> direccionesAccesadas;
    

  public:
    Graph();
    ~Graph();
    void loadDirWeightedGraph(std::string inputFile);
    void print();
    void getIpSummary();
    void imprimirinformacionIP();
     


};


#endif // __GRAPH_H_