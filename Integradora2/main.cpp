/** 
* Nombre del alumno:
* Arturo Azael Godinez Rodriguez A01641179
* Xavier Barrera A01702869
* Jorge Emiliano Pomar A01709338
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
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

#include "DLLNode.h"
#include "DLinkedList.h"
#include "Registro.h"  
#include "Bitacora.h"



//Main
int main () {

//Se abre la bitacora llamada "bitacora.txt"
  Bitacora miBitacora("bitacora.txt");

unsigned int comparaciones, swaps = 0;
  
  // Utilizacion de algoritmos de ordenamiento para ordenar el vector. Método Quick Sort
  miBitacora.quickSort(comparaciones, swaps);
  miBitacora.printQuickSort(comparaciones, swaps);

  // Creación de 2da bitácora para aplicar el Merge Sort
  Bitacora miBitacora2("bitacora.txt");

  // Método Merge Sort
  unsigned int comparaciones2 = 0;
  miBitacora2.mergeSort(comparaciones2);
  miBitacora2.printMergeSort(comparaciones2);
  
   std::string mes, dia, hora, minutos, segundos;

  std::cout<< "Instrucciones: "<<std::endl;
  std::cout << "-Ingrese las dos fechas de búsqueda en formato: Mes Dia Hora Minuto Segundos. "<< std::endl <<"-(Coloca los ceros cuando solo sea un digito 01-09 y no ingreses ningun doble punto en la hora, separalos con espacios)." << std::endl<<std::endl;
  std::cout << "Ingrese fecha 1: " << std::endl;
  std::cout << "Ejemplo: Jun 13 01 25 12" << std::endl;
  std::string fecha_str;
  std::getline(std::cin, fecha_str);
  std::istringstream iss(fecha_str);
  std::string mes1, dia1, hora1, minutos1, segundos1;
  iss >> mes1 >> dia1 >> hora1 >> minutos1 >> segundos1;
  Registro key1(mes1, dia1, hora1, minutos1, segundos1, "", "", "");

  std::cout <<std::endl<< "Ingrese fecha 2: " << std::endl;
  std::cout << "Ejemplo: Sep 23 12 58 18" << std::endl;
  std::getline(std::cin, fecha_str);
  std::istringstream iss2(fecha_str);
  std::string mes2, dia2, hora2, minutos2, segundos2;
  iss2 >> mes2 >> dia2 >> hora2 >> minutos2 >> segundos2;
  Registro key2(mes2, dia2, hora2, minutos2, segundos2, "", "", "");
  
  // Algoritmo de Busqueda 
  miBitacora.realizarBusqueda(key1, key2);
  
}
