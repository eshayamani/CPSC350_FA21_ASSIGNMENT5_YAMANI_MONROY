//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 5

#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
using namespace std;

class Window{
  public:

    Window();
    Window(int i);
    ~Window();

    //GETTERS
    int getOccTime(); //returns the Occ time
    int getWaitTime(); //returns the waittime
    bool getCurrentlyOcc(); //returns true or false
    //SETTERS
    void setOccTime(int o); //adds Occ time
    void setWaitTime(int t); //adds the waittime

    bool isOcc(); //checks to see if window is occupied
    void Occupied(); //Occ during current round
    void notOccupied(); //if not Occ during current round
    void windowUnAvailable(); //updates if the window is Occ
    void windowAvailable(); //updates if the window is avaliable





  private:
    int time;
    bool Occ;
    int OccTime;
    bool currently;

};

#endif
