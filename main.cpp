//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 5

#include "Registrar.h"
#include <iostream>

using namespace std;

int main (int argc, char **argv){
  if(argc == 1){ // checks command line
    cout << "ERROR: please enter the file you want checked after ./assignment5.out" << endl;
    return 0;
  }

  string file = argv[1];
  Registrar* s = new Registrar(); //make registrar object
  s->simulation(file); // run the simulation given the input file

}
