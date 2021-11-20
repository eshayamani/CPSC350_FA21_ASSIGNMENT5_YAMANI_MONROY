//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 5

#include "Window.h"
#include <iostream>

using namespace std;


Window::Window(){//default constructor
  time = 0;
  OccTime = 0;
}


Window::Window(int t){//overloaded
  time = t;
  Occ = false;
  currently = false;
}


Window::~Window(){//destructor
}


void Window::setWaitTime(int t){ // adds wait time
  time = t;
}


int Window::getWaitTime(){//returns wait time
  return time;
}


bool Window::isOcc(){ //checks if occupied
  return Occ;
}


void Window::windowUnAvailable(){// makes window appear unavailable
  Occ = true;
}

void Window::windowAvailable(){ // makes the window appear available
  Occ = false;
}


void Window::setOccTime(int t){ //adds time when occupied
  OccTime += t;
}


int Window::getOccTime(){ //returns the occupied time
  return OccTime;
}

void Window:: Occupied(){ //sets to occupied in current loop
  currently = true;
}

void Window::notOccupied(){ //sets to unoccupied in current loop
  currently = false;
}

bool Window::getCurrentlyOcc(){// check if currently occupied
  return currently;
}
