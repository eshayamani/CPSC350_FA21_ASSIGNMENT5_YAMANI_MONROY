//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 5

#ifndef LISTINTERFACE_H
#define LISTINTERFACE_H

template <class T>
class ListInterface {
public:
  virtual ~ListInterface();

  // adds to the back
  virtual void append(T d) const = 0;
  // adds to the back
  virtual void prepend(T d) const = 0;
  // inserts after a certain position
  virtual void insertAfter(T d, int i) const = 0;
  //removes variable
  virtual T remove() const = 0;
  //searches for a certain value
  virtual int search(T value) const = 0;
  //print function
  virtual void print() const = 0;
  //reverse print function
  virtual void printReverse() const = 0;
  //sort all the values
  virtual void sort() const = 0;
  //checks if it is empty
  virtual bool isEmpty() const = 0;
  //returns the length
  virtual unsigned int getLength() const = 0;

};

template<class T>
ListInterface<T>::~ListInterface() = default;


#endif
