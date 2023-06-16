#include "Bitacora.h"

//Constructor
Bitacora::Bitacora() {

}

//Agregando metodos de graph para cargar los archivos
Bitacora::Bitacora(std::string fileName) {
  graph.loadDirWeightedGraph(fileName);
  graph.getIpSummary();
  //graph.print();
}

//Destructor
Bitacora::~Bitacora() {

}

