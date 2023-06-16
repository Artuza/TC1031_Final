/** 
* Nombres de los integrantes:
* Arturo Azael Godinez Rodriguez A01641179
* Jorge Emiliano Pomar A01709338
* Xavier Barrera A01702869
* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp 
* Ejecucion con valgrind:
*    nix-env -iA nixpkgs.valgrind
*    valgrind --leak-check=full ./main
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main
**/

#include "Registro.h"
#include "Bitacora.h"
#include "MaxHeap.h"
#include "IP.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>


int main() {

  // Llamar mi Bitacora para pasar los datos de el archivo de texto de string a valores numericos y guardarlos en un vector
  Bitacora miBitacora("bitacoraHeap.txt");

  miBitacora.heapSort();
  miBitacora.printHeapSort();

  miBitacora.contIpRep();

  
 
}