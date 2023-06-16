#include "Graph.h"

Graph::Graph() {
  numNodes = 0;
  numEdges = 0;
  adjList.clear();
  ips.clear();
}

Graph::~Graph() {
  adjList.clear();
  ips.clear();
}
//Complejidad: O(n)
void Graph::split(std::string line, std::vector<int> & res) {
    size_t strPos = line.find(" ");
    size_t lastPos = 0;
    while (strPos != std::string::npos) {
      res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
      lastPos = strPos + 1;
      strPos = line.find(" ", lastPos);
    }
    res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}

//Complejidad: O(log n)
int Graph::binarySearch(ipAddress key) {
  int low = 0;
  int high = ips.size() - 1;
  int mid = 0;
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (key == ips[mid])
      return mid;
    else if (key < ips[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}

//Complejidad: O(1)
unsigned int Graph::getIPValue(std::string ipString) {
  // Convertir IP
  int posInit = 0;
  int posFound = 0;
  std::string splitted;
  std::vector<std::string> results;   
  while(posFound >= 0) {
    posFound = ipString.find(".", posInit);
    splitted = ipString.substr(posInit, posFound - posInit);
    posInit = posFound + 1;
    results.push_back(splitted);
  }
  int partA = std::stoi(results[0]);
  int partB = std::stoi(results[1]);
  int partC = std::stoi(results[2]);
  int partD = std::stoi(results[3]);
  return (partA*(pow(256,3)) + partB*(pow(256,2)) + partC*(pow(256,1)) + partD);
}
//Complejidad: O(V + E)
void Graph::print() {
  std::cout << "numNode: " << numNodes << std::endl;
  std::cout << "numEdges: " << numEdges << std::endl;
  std::cout << "Adjacency List" << std::endl;
  for (int nodeU = 1; nodeU <= numNodes; nodeU++) {
    std::cout << "vertex " << nodeU << ": ";
    NodeLinkedList<std::pair<int, int>> *ptr = adjList[nodeU].getHead();
    while (ptr != nullptr) {
      std::pair<int, int> par = ptr->data;
      std::cout << "{" << par.first << "," << par.second << "} ";
      ptr = ptr->next;
    }
    std::cout << std::endl;
  }
}

//Complejidad: O((V + E) log V)
void Graph::loadDirWeightedGraph(std::string inputFile) {
  std::string line, ip1, ip2, peso;
  int i = 0;
  std::ifstream file(inputFile);
  if (!file.good()) {
    file.close();
    throw std::invalid_argument("File not found");
  }
  else {
    // (V log V) + (E log V)
    while(std::getline(file,line)) { 
      if (i == 0) {
        std::cout<<"---------------------------------------------------"<<std::endl;
        std::cout << "(Numero de IPs, Numero de incidencias): " << line << std::endl;
        std::cout<<"---------------------------------------------------"<<std::endl<<std::endl;
        std::vector<int> res;
        split(line, res);
        numNodes = res[0];
        numEdges = res[1];
        std::cout << "numNodes " << numNodes << std::endl;
        std::cout << "numEdges " << numEdges << std::endl;
        // Reservar memoria para los renglones de la lista de adyacencia (renglon 0 no utilizado) 
        adjList.resize(numNodes+1);
        // Declara una lista vacia para cada renglon y la almacena en el vector
        for (int k = 1; k <= numNodes; k++) {
          LinkedList<std::pair<int,int>> tmpList; // en ponderado lista de pares
          adjList[k] = tmpList; 
        }
      }
      else if (i > 0 && i <= numNodes) {
        ipAddress tmpIP(line, i);
        ips.push_back(tmpIP);
        if (i == numNodes) {
          std::sort(ips.begin(), ips.end());
        }
      } 
      else if (i > numNodes) {
        std::size_t found = line.find(":", 15);
        ip1 = line.substr(15, found-15);
        std::size_t found2 = line.find(" ", found+1);
        std::size_t found3 = line.find(":", found2+1);
        ip2 = line.substr(found2, found3-found2);
        std::size_t found4 = line.find(" ", found3+1);
        std::size_t found5 = line.find(" ", found4+1);
        peso = line.substr(found4, found5-found4);
        // Crear arista ip1 a ip2 con un peso
        int pos1 = binarySearch(ipAddress(ip1, 0));
        int nodoU = ips[pos1].getIpIndex();
        int pos2 = binarySearch(ipAddress(ip2, 0));
        int nodoV = ips[pos2].getIpIndex();
        adjList[nodoU].addLast({nodoV, stoi(peso)});
        ips[pos1].addToDegreeOut();
        ips[pos2].addToDegreeIn();
      }
      i++;
    }
    file.close();
    // Fijar maxSize para la tabla hash 
    // hay 13370 ips --- primo mas cercano
    //myHashTable.setMaxSize(13799); // 38842
    //myHashTable.setMaxSize(38933); // 3309
     //myHashTable.setMaxSize(77866);//1139
    myHashTable.setMaxSize(155771);//645
    // Inserta los datos en la tabla hash
    for (int j = 0; j < ips.size(); j++) {
      //std::cout << ips[j].getIpValue() << " " << ips[j].getIp() << " " << ips[j].getIpIndex() << " " << ips[j].getDegreeOut() << " " << ips[j].getDegreeIn() << std::endl;
      unsigned int key = ips[j].getIpValue();
      ipAddress data = ips[j];
      myHashTable.add(key, data);
    }
      std::cout << "El numero total de colisiones es: " << myHashTable.getColisiones() << std::endl;
      

    
    //myHashTable.print();
    // llave: ips[j].getIpValue()
    // data: ips[j]
    // add(llave, data);
    }
  }
  
    // busqueda
    //convertir la ip dada por el usuario de string a decimal
    // unsigned int valorDec = getIPValue("1.1.1.1");
    // ipAddress data  = myHashTable.getDataAt(myHashTable.find(valorDec))

//Complejidad: O(1) 
void Graph::getIpSummary(){
  std::cout << "getIpSummary - colisiones es: " << myHashTable.getColisiones() << std::endl;
  std::string tmpIp;
  std::cout<<"Dime la IP que desea buscar: ";
  std::cin>>tmpIp;
  unsigned int valorDec = getIPValue(tmpIp);
  int index = myHashTable.find(valorDec);
  ipAddress data  = myHashTable.getDataAt(index);
  std::cout << data.getIp() << std::endl;
}