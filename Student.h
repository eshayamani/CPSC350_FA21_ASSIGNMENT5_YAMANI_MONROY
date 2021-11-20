//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 5

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student{
  public:
      Student();
      Student(int time);
      ~Student();

      //GETTERS
      int getTime();
      int getWaitTime();
      //SETTERS
      void setTime(int t);

  private:
      int waitTime;
      int time;

};

#endif
