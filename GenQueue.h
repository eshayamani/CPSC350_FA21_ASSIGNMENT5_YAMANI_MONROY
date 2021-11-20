//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 5

//TEMPLATE CLASS
//TEMPLATE CLASS

#ifndef GENQUEUE_H
#define GENQUEUE_H

#include <iostream>

using namespace std;

template <class T>

class ListNode{
 public:
   T *data;
   ListNode *next;
   ListNode *prev;


   ListNode();//default constructor
   ListNode(T *d);//overloaded --> dont think i need
   ~ListNode(); // destructor
};

//default constructor
template <class T>
ListNode<T>::ListNode(){}

//overload constructor
template <class T>
ListNode<T>::ListNode(T *d){
  data = d;
  next = NULL;
  prev = NULL;
}

//destructor
template <class T>
ListNode<T>::~ListNode(){
  next = NULL;
  prev = NULL;
}

template <class T>

class GenDoublyLinkedList{
  private:
    ListNode<T> *front; //pointer to the node in the front
    ListNode<T> *back; //pointer to the node in the back
    unsigned int size; //size of the DoublyLinkedList

  public:
    GenDoublyLinkedList(); //constructor
    ~GenDoublyLinkedList(); //destructor

    void insertFront(T *d); //insert node to front
    void insertBack(T *d); //insert node to back
    T* removeFront(); //removes and returns node in the front
    T* removeBack(); //removes and returns node in the back
    T* peek(); //returns the node in the front
    T* deletePos(T *pos); //delete and returns node at certain position
    int find(T *d); //finds and returns the position of a node

    bool isEmpty(); //checks if list is empty
    void printList(); //prints the list
    unsigned int getSize(); //returns the size of list
};

//default constructor
template<class T>
GenDoublyLinkedList<T>::GenDoublyLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

//destructor
template<class T>
GenDoublyLinkedList<T>::~GenDoublyLinkedList(){
  //iterate through the list
  while (front->next != front)
	{
		ListNode<T>* curr = front->next;
		curr->next->prev = front;
		front->next = curr->next;
		delete curr;
	}
	delete front;
}


//inserts a node to the front
template<class T>
void GenDoublyLinkedList<T>::insertFront(T *d){
  ListNode<T> *node = new ListNode<T>(d);

  if(isEmpty()){
    //the list is now empty
    back = node;
  }else{
    //not empty
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}

//removes the node from the front of the list
template<class T>
T* GenDoublyLinkedList<T>::removeFront(){
  T *temp;
  if(isEmpty()){
    cout << "List empty" << endl;
  }else{
    ListNode<T> *ft = front;

    if(front->next == NULL){
      //only one element in the list
      back = NULL;
    }else{
      //more than one element in the list
      front->next->prev = NULL;
    }
    front = front->next;
    temp = ft->data;
    ft->next = NULL;
    delete ft;
    size--;
  }
  return temp;
}

//returns the data stored in the front but doesnt remove
template<class T>
T* GenDoublyLinkedList<T>::peek(){
  if(isEmpty()){
    cout << "Linked List is empty" << endl;
  }else{
    return front->data;
  }
}

//inserts node to the back of the list
template<class T>
void GenDoublyLinkedList<T>::insertBack(T *d){
  ListNode<T> *node = new ListNode<T>(d);

  if(isEmpty()){
    //empty list
    front = node;
  }else{
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

//removes the node at the back of the list
template<class T>
T* GenDoublyLinkedList<T>::removeBack(){
  T *temp = new ListNode<T>;
  if(isEmpty()){
    cout << "List is empty" << endl;
  }else{
    ListNode<T> *bk = back;

    if(front->next == NULL){
      //only one element in the list
      front = NULL;
    }else{
      //more than one element in the list
      back->prev->next = NULL;
    }
    back = back->prev;
    temp = bk->data;
    bk->prev = NULL;
    delete bk;
    size--;

  }
  return temp;
}

//deletes node at a certain position
template<class T>
T* GenDoublyLinkedList<T>::deletePos(T *d){
  if(isEmpty()){
    cout << "List is empty" << endl;
  }else{
    ListNode<T> *curr = front;

    while(curr->data != d){
      curr = curr->next;

      if(curr == NULL){
        return NULL;
      }
      //if we get to this point, we found the node to be removed

      if(curr == front){
        front = curr->next;
      }
      else{
        //its not the front, its in between
        curr->prev->next = curr->next;

      }if(curr == back){
        back = curr->prev;
      }else{
        curr->next->prev = curr->prev;
      }

      curr->next = NULL;
      curr->prev = NULL;
      size--;

    }
    return curr;
  }
}

//finds the position of a data
template<class T>
int GenDoublyLinkedList<T>::find(T *d){
  if(isEmpty()){
    cout << "List is empty" << endl;
  }else{
    int idx = 0;
    ListNode<T> *curr = front;

    while(curr != NULL){
      if(curr->data == d){
        break;
      }else{
        curr = curr->next;
        idx++;
      }
    }

    if(curr == NULL){ //did not find the value we want
      idx = -1;
    }
    return idx;
  }
}

//returns if the list is empty
template<class T>
bool GenDoublyLinkedList<T>::isEmpty(){
  if(size == 0){
    return true;
  }
  else{
    return false;
  }
}

//prints list
template<class T>
void GenDoublyLinkedList<T>::printList(){
  ListNode<T> *curr = front;

  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
}

//returns the size
template<class T>
unsigned int GenDoublyLinkedList<T>::getSize(){
  return size;
}

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

    GenDoublyLinkedList<T> *myQueue; //queue
};


//default constructor
template <class T>
GenQueue<T>::GenQueue(){
  myQueue = new GenDoublyLinkedList<T>();
  front = 0;
  rear = -1;
  numElements = 0;
}

//overload constructor
template<class T>
GenQueue<T>::GenQueue(int maxSize){
  myQueue = new GenDoublyLinkedList<T>();
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
