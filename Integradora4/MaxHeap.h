#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_

#include <vector>
#include <iostream>
#include <stdexcept>

template <class T>
class MaxHeap {
  private:
    // contiene los elementos del heap
    std::vector<T> data;
    // capacidad maxima del heap
    int maxSize;
    // tamano actual del heap
    int currentSize;

    int parent(int k);
    int left(int k);
    int right(int k);

  public:
    MaxHeap(int maxCapacity);
    MaxHeap();
    ~MaxHeap();
    bool isEmpty();
    int getMaxCapacity();
    int getCurrentSize();
    void setCapacity(int _maxSize);
    void printHeap();
    void push(T key);
    T getTop();
    void pop();
};


template <class T>
MaxHeap<T>::MaxHeap(int maxCapacity) {
  maxSize = maxCapacity;
  currentSize = 0;
  data.resize(maxSize);
}

template <class T>
MaxHeap<T>::MaxHeap() {
  maxSize = 0;
  currentSize = 0;
  data.resize(maxSize);
}

template <class T>
MaxHeap<T>::~MaxHeap() {
  maxSize = 0;
  currentSize = 0;
  data.clear();
}

template <class T>
bool MaxHeap<T>::isEmpty() {
  return (currentSize <= 0);
}

template <class T>
int MaxHeap<T>::getMaxCapacity() {
  return maxSize;
}

template <class T>
int MaxHeap<T>::getCurrentSize() {
  return currentSize;
}
 
template <class T>
void MaxHeap<T>::setCapacity(int _maxSize) {
  maxSize = _maxSize;
  currentSize = 0;
  data.resize(maxSize);
}

template <class T>
void MaxHeap<T>::printHeap() {
std::cout << "Contenido del maxheap:" << std::endl;
  for (int i = 0; i < currentSize; i++) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
}
  
template <class T>
int MaxHeap<T>::parent(int k) {
  return (k-1)/2;
}

template <class T>
int MaxHeap<T>::left(int k) {
  return (2*k + 1);
}

template <class T>
int MaxHeap<T>::right(int k) {
  return (2*k + 2);
}

template <class T>
void MaxHeap<T>::push(T key) {
  if (currentSize == maxSize) {
    throw std::out_of_range("Overflow: no se puede insertar la llave");
  }
  // Insertamos la nueva llave al final del vector
  int k = currentSize;
  data[k] = key;
  currentSize++;
  // Reparar las propiedades del maxheap si son violadas
  while (k != 0 && data[parent(k)] < data[k]) {
    std::swap(data[k], data[parent(k)]);
    k = parent(k);
  }
}

template <class T>
T MaxHeap<T>::getTop() {
  if (isEmpty()) {
    throw std::out_of_range("El heap esta vacio");
    return {};
  }
  return data[0];
}




#endif  // _MAXHEAP_H_

