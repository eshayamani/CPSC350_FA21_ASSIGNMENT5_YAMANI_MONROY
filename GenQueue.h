//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 5

#ifndef GENQUEUE_H
#define GENQUEUE_H

#include "DoublyLinkedList.h"

template <class T>

class GenQueue{
  public:
    GenQueue(); //default constructor
    GenQueue(int maxSize); //overload constructor
    ~GenQueue(); //destructor

    //core functions
    void insert(T *d); //inserts element to queue to the back
    T* remove(); //removes element from the front

    //aux functions
    T* peek(); //returns the element in the front
    bool isEmpty(); //returns if the queue is empty
    int getSize(); //returns size of the queue

    //var
    int front; //aka front
    int rear; //aka tail
    int numElements; //number of elements in the queue

    DoublyLinkedList<T> *myQueue; //queue
};


//default constructor
template <class T>
GenQueue<T>::GenQueue(){
  myQueue = new DoublyLinkedList<T>();
  front = 0;
  rear = -1;
  numElements = 0;
}

//overload constructor
template<class T>
GenQueue<T>::GenQueue(int maxSize){
  myQueue = new DoublyLinkedList<T>();
  front = 0;
  rear = -1;
  numElements = 0;
}

//destructor
template<class T>
GenQueue<T>::~GenQueue(){
  delete [] myQueue;
}

//inserting element into the queue
template<class T>
void GenQueue<T>::insert(T *d){

  myQueue->insertBack(d);
  numElements++;
}

//removing element from the queue
template<class T>
T* GenQueue<T>::remove(){

  numElements--;
  return myQueue->removeFront();
}

//returning the first element in the queue but does not remove
template<class T>
T* GenQueue<T>::peek(){
  return myQueue->peek();
}

//returns is the queue is empty
template<class T>
bool GenQueue<T>::isEmpty(){
  if(numElements == 0){
    return true;
  }else{
    return false;
  }
}

//returns the size of the queue
template<class T>
int GenQueue<T>::getSize(){
  return numElements;
}


#endif
