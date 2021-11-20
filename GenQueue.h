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


   ListNode();//default
   ListNode(T *d);//overloaded --> dont think i need
   ~ListNode(); // destructor
};


template <class T>
ListNode<T>::ListNode(){
  //default
}


template <class T>
ListNode<T>::ListNode(T *d){ //overloaded
  data = d;
  next = NULL;
  prev = NULL;
}


template <class T>
ListNode<T>::~ListNode(){//destructor
  next = NULL;
  prev = NULL;
}

template <class T>

class GenDoublyLinkedList{
  private:
    ListNode<T> *front; //pointer to front node
    ListNode<T> *back; //pointer to back node
    unsigned int size; //size

  public:
    GenDoublyLinkedList(); //constructor
    ~GenDoublyLinkedList(); //destructor

    void insertFront(T *d); //insert to front
    void insertBack(T *d); //insert to back
    T* removeFront(); //removes and returns front
    T* removeBack(); //removes and returns  back
    T* peek(); //returns the front w/o deleting
    T* deletePos(T *pos); //delete and returns at certain position
    int find(T *d); //finds and returns the position of specific node

    bool isEmpty(); //checks if empty
    void printList(); //prints out list
    unsigned int getSize(); //returns size
};


template<class T>
GenDoublyLinkedList<T>::GenDoublyLinkedList(){//default
  size = 0;
  front = NULL;
  back = NULL;
}


template<class T>
GenDoublyLinkedList<T>::~GenDoublyLinkedList(){ // destructor
  //iterates through the list
  while (front->next != front)
	{
		ListNode<T>* curr = front->next;
		curr->next->prev = front;
		front->next = curr->next;
		delete curr;
	}
	delete front;
}



template<class T>
void GenDoublyLinkedList<T>::insertFront(T *d){// inserts to the front
  ListNode<T> *node = new ListNode<T>(d);

  if(isEmpty()){
    //when list is empty
    back = node;
  }
  else{
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}


template<class T>
T* GenDoublyLinkedList<T>::removeFront(){//removes from the front
  T *temp;
  if(isEmpty()){
    //when list is empty
    cout << "List empty" << endl;
  }
  else{
    ListNode<T> *current = front;

    if(front->next == NULL){
      //when just one
      back = NULL;
    }
    else{
      front->next->prev = NULL;
    }
    front = front->next;
    temp = current->data;
    current->next = NULL;
    delete current;
    size--;
  }
  return temp;
}


template<class T>
T* GenDoublyLinkedList<T>::peek(){//returns front without deleting
  if(isEmpty()){
    //when empty
    cout << "Linked List is empty" << endl;
  }else{
    return front->data;
  }
}


template<class T>
void GenDoublyLinkedList<T>::insertBack(T *d){//inserts to back
  ListNode<T> *node = new ListNode<T>(d);

  if(isEmpty()){
    //when empty
    front = node;
  }else{
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}


template<class T>
T* GenDoublyLinkedList<T>::removeBack(){ // removes back
  T *temp = new ListNode<T>;
  if(isEmpty()){
    //when list is empty
    cout << "List is empty" << endl;
  }
  else{
    ListNode<T> *current = back;

    if(front->next == NULL){
      //only one thing in list
      front = NULL;
    }
    else{

      back->prev->next = NULL;
    }
    back = back->prev;
    temp = current->data;
    current->prev = NULL;
    delete current;
    size--;

  }
  return temp;
}


template<class T>
T* GenDoublyLinkedList<T>::deletePos(T *d){ // deletes at current pos
  if(isEmpty()){
    //when list is empty
    cout << "List is empty" << endl;
  }else{
    ListNode<T> *curr = front;

    while(curr->data != d){
      curr = curr->next;

      if(curr == NULL){
        return NULL;
      }
      //found thing to remove

      if(curr == front){
        front = curr->next;
      }
      else{
        //when in b/w
        curr->prev->next = curr->next;

      }
      if(curr == back){
        back = curr->prev;
      }
      else{
        curr->next->prev = curr->prev;
      }

      curr->next = NULL;
      curr->prev = NULL;
      size--;

    }
    return curr;
  }
}


template<class T>
int GenDoublyLinkedList<T>::find(T *d){ // finds pos
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

    if(curr == NULL){ //not found
      idx = -1;
    }
    return idx;
  }
}


template<class T>
bool GenDoublyLinkedList<T>::isEmpty(){// when list is empty
  if(size == 0){
    return true;
  }
  else{
    return false;
  }
}


template<class T>
void GenDoublyLinkedList<T>::printList(){ // prints list
  ListNode<T> *curr = front;

  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
}


template<class T>
unsigned int GenDoublyLinkedList<T>::getSize(){ // returns size
  return size;
}

template <class T>

class GenQueue{
  public:
    GenQueue(); //default
    GenQueue(int maxSize); //overloaded
    ~GenQueue(); //destructor


    void insert(T *d); //inserts to back of Q
    T* remove(); //removes from front of Q
    T* peek(); //returns front w/o deleting
    bool isEmpty(); //returns if empty
    int getSize(); //returns size
    int front;
    int rear;
    int numElements; //stuff in Q

    GenDoublyLinkedList<T> *myQueue; //Q
};



template <class T>
GenQueue<T>::GenQueue(){ // default
  myQueue = new GenDoublyLinkedList<T>();
  front = 0;
  rear = -1;
  numElements = 0;
}


template<class T>
GenQueue<T>::GenQueue(int maxSize){ //overloaded
  myQueue = new GenDoublyLinkedList<T>();
  front = 0;
  rear = -1;
  numElements = 0;
}


template<class T>
GenQueue<T>::~GenQueue(){//destructor
  delete [] myQueue;
}


template<class T>
void GenQueue<T>::insert(T *d){ // insert to Q
  myQueue->insertBack(d);
  numElements++;
}


template<class T>
T* GenQueue<T>::remove(){//removes from Q
  numElements--;
  return myQueue->removeFront();
}


template<class T>
T* GenQueue<T>::peek(){//returns front without deleting
  return myQueue->peek();
}


template<class T>
bool GenQueue<T>::isEmpty(){ // checks if empty
  if(numElements == 0){
    return true;
  }else{
    return false;
  }
}

template<class T>
int GenQueue<T>::getSize(){ //returns size
  return numElements;
}

#endif
