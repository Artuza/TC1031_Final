#ifndef _DLLNODE_H
#define _DLLNODE_H

template <class T>
class DLLNode {
  public:
    T data;
    DLLNode<T> *next;
    DLLNode<T> *prev;

    DLLNode();
    DLLNode(T value);

};

template <class T>
DLLNode<T>::DLLNode() : data{}, next{nullptr}, prev{nullptr} {}

template <class T>
DLLNode<T>::DLLNode(T value) : data{value}, next{nullptr}, prev{nullptr} {}


#endif // _DLLNODE_H


