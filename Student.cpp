//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 5

#include "Student.h"
#include <iostream>

using namespace std;


Student::Student(){//default
  time = 0;
  waitTime = 0;
}


Student::Student(int t){ // overloaded
  time = t;
  waitTime = 0;
}


Student::~Student(){//destructor
}


void Student::setTime(int timeToAdd){ // adds to student wait time
  waitTime += timeToAdd;
}


int Student::getTime(){//retrns the tick when the student entered the Q(line)
  return time;
}


int Student::getWaitTime(){//returns wait time
  return waitTime;
}
