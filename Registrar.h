//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 5

#ifndef REGISTRAR_H
#define REGISTRAR_H

#include "GenQueue.h"
#include "Student.h"
#include "Window.h"
#include <iostream>
#include <fstream>

using namespace std;

class Registrar{
  public:
    Registrar(); //constructor
    ~Registrar(); //destructor

    void simulation(string file); //runs simulation based on the given file
    void calculations(); //does calculations to be output to terminal

  private:
    GenQueue<Student> *myQueue; //Q
    int windowSize; //number of windows (first line of the input file)
    int studentSize; //number of students who go to registar
    int time; //tick when student entered
    int windowTime; //time needed at which window for each student
    int students; //number of students who come at each step
    Student *arrStudent[500]; //array of student wait times (assuming less than 500 students)
    int studentCount; //helps keeps track of students
    Window *arrWindow[500]; //array of window times
    int studentTime; //to add time to students
    int windowCount; //counts occupied windows
};

#endif
