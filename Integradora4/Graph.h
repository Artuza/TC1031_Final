// Esta clase permite representar grafos dirigidos ponderados
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <utility> 
#include "LinkedList.h"
#include "ipAddress.h"
#include "MaxHeap.h"
#define INF 0x3f3f3f3f

class Graph {
  private:
    int numNodes;
    int numEdges;
    // Lista de adyacencia (vector de listas ligadas de pares nodo,peso)
    std::vector<LinkedList<std::pair<int, int>>> adjList;

    std::vector<std::string> IPad;

    std::map<unsigned int,ipAddress> mapIP;

    // vector de objetos ipAddress para contar los grados (in y out)
    std::vector<ipAddress> ips;

    int binarySearch(ipAddress key);
    void split(std::string line, std::vector<int> & res);
    unsigned int getIPValue(std::string ipString);

    friend std::ostream& operator<<(std::ostream& os, const ipAddress& ip);


    // Maxheap
    MaxHeap<ipAddress> Grados;

    

  public:
    Graph();
    ~Graph();
    void loadGraph(std::string inputFile);
    void print();
    void gIPs();
     


};


#endif // __GRAPH_H_