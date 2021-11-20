//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 5

#include "Registrar.h"
#include <fstream>
#include <iostream>

using namespace std;


Registrar::Registrar(){//default constructor
  myQueue = new GenQueue<Student>(); // initialize the Q
  //set defaults:
  windowSize = 0;
  studentSize = -1;
  time = 0;
  windowTime = 0;
  students = 0;
  studentCount = 0;
  studentTime = 0;
  windowCount = 0;
}


Registrar::~Registrar(){//destructor
  delete myQueue;
}


void Registrar::simulation(string file){ //simulation runs the registrar

  int step = 0; //starts off at 0 and outerloop runs through 5 steps
  string line; //to keep track of what line is being read
  int capacity = 1; //keeps track if there's a correct number of students created
  Student *tempStudent = new Student(); //temp student
  int tickTime = -1; //the first time in the file variable
  int step4Windows[windowSize]; //to keep track of how many windows were Occ
  int step4W = -1; //num windows during step 4
  int startTick = 0; //variable to keep track of the start time at each tick

  ifstream infile(file); //opens up the file from command line

  //big OUTER loop
  while(getline(infile, line)){

//STEP 0 ---------------------------------------------
    if(step == 0){//gets the number of windows
      windowSize = stoi(line); // numWindows

      //array of windows from file
      for(int i = 0; i < windowSize; i++){
        arrWindow[i] = new Window();
      }

      step = 1; // go to the next step 1
      continue;

    //time that student arrives at registar
    }
//STEP 1 ---------------------------------------------
    if(step == 1){ //get the tick aka time students entered
      time = stoi(line);
      step = 2; // next step 2
      continue;

    //creating the correct number of student objects
    }
//STEP 2 ---------------------------------------------
    if(step == 2){// gets number of students who entered the registrar
      students = stoi(line);
      studentCount += students;
      step = 3; // next step 3
      continue;

    }
//STEP 3 ---------------------------------------------
    if(step == 3){ // create the students and push them onto the Q
      windowTime = stoi(line);
      //create student
      Student *s = new Student(windowTime);

      //inserts student into the Q
      myQueue->insert(s);

      //keep reading file to get all of the students times
      if(capacity < students){ // capacity is the max numStudents
        capacity++;
        continue;


      }
      else if(capacity == students){ // once it reaches the cap nex
        step = 4; // next step 4
        capacity = 1; // reset the cap for the next step
      }
    }


//STEP 4 ---------------------------------------------
    if(step == 4){ //students entering and leaving the window
      tickTime++;
      if(tickTime == 0){
        for(int i = 0; i < windowSize; i++){
          arrWindow[i]->setWaitTime(time);
        }
        startTick = time;
      }
      else{
        for(int i = 0; i < windowSize; i++){

          if(arrWindow[i]->isOcc() == false){
            arrWindow[i]->setWaitTime(time);
          }
        }
      }

      while(capacity <= students){ // assigns students to a window
        if(myQueue->isEmpty()){
          break; //break when the Q is empty
        }
        else if(myQueue->isEmpty() == false){ // when Q has students
          tempStudent = myQueue->remove(); //removes the top student from Q
          studentSize++;
          capacity++;
          //WHEN WINDOWS ARE FULL::
          if(windowCount == windowSize){ //full
            int w = 0; //keeps track of the window
            int occTime[windowSize]; //array of occupied time for the windows

            //pushes occupied times to occTime array (does calc to get student time)
            for(int i = 0; i < windowSize; i++){
              if(tickTime == 0){
                occTime[i] = arrWindow[i]->getOccTime();
              }else if(arrWindow[i]->getCurrentlyOcc() == true){
                occTime[i] = (arrWindow[i]->getOccTime() + time) - startTick;
              }else if(arrWindow[i]->getCurrentlyOcc() == false){
                occTime[i] = (arrWindow[i]->getOccTime() - time) + startTick;
              }
            }

            studentTime = occTime[0];//student time is occTime - current time

            //finds the shortest studentTime in window
            for(int i = 1; i < windowSize; i++){
              if(occTime[i] < studentTime){
                studentTime = occTime[i];
                w = i;
              }
            }

            if(studentTime < 0){
              studentTime = 0;
            }

            //adds wait time to student
            tempStudent->setTime(studentTime);

            //adds occupied time to window
            arrWindow[w]->setOccTime(tempStudent->getTime());
            arrWindow[w]->Occupied();

            //tempStudent is pushed onto the array
            arrStudent[studentSize] = tempStudent;
          }

          //iterates through the windows
          for(int i = 0; i < windowSize; i++){

            //when window isnt occupied
            if(arrWindow[i]->isOcc() == false){
              arrWindow[i]->Occupied();
              step4W++;
              step4Windows[step4W] = i;   //array to keep track of what windows are occupied in this step
              tempStudent->setTime(0);//gives 0 wait time to students w no wait time
              arrStudent[studentSize] = tempStudent; // adds the temp to regular array of students

              //the window is now unavailable
              arrWindow[i]->windowUnAvailable();

              // pushes occupied time to window
              arrWindow[i]->setOccTime(tempStudent->getTime());

              windowCount++;
              break;


            }
            if(arrWindow[i]->getOccTime() - time <= 0){ // window is available
              arrWindow[i]->windowAvailable(); // makes the window available
              windowCount--;
            }
          }

          if(capacity >= students){
            step = 5;// next step 5
          }
        }
      }

    }
//STEP 5 ---------------------------------------------
    if(step == 5){ // sets up for next loop and resets everything to go back to set 1
      step = 1;
      capacity = 1;
      step4W = -1;

      for(int i = 0; i < windowSize; i++){

        if(arrWindow[i]->isOcc() == false){
          arrWindow[i]->setWaitTime(time);
        }

        arrWindow[i]->notOccupied();
        //if the window is still avaliable, add the time of wait time
      }
      for(int i = 0; i < windowSize; i++){
        step4Windows[i] = -1;
      }
      continue;
    }
  }
//ERROR HANDLING ---------------------------------------------
  if(capacity != 1){
    cout << endl;
    cout << "ERROR: File formatted incorrectly. Unable to read" << endl;
    cout << endl;
    return;
  }

  calculations();// stats time!
}



void Registrar::calculations(){//preforms caluclations for the beautiful output

//STUDENT MEAN-------------------------------------

  float waitTimeSum = 0;
  float meanNum = 0;

  //gets the sum of wait time and the num to divide by at the end
  for(int i = 0; i < studentCount; i++){
    waitTimeSum += arrStudent[i]->getWaitTime();
    meanNum++;
  }

  waitTimeSum = waitTimeSum/meanNum;

  cout << "\nStudent Wait Time Stats"<<endl;
  for(int i = 0; i < studentCount; i++){
    cout<<"Value: "<<arrStudent[i]->getWaitTime()<<" ";
  }
  cout<<endl;
  cout << "The mean of student wait times is: " << waitTimeSum << endl;

//STUDENT MEDIAN-------------------------------------

  float median = 0.0f;
  int medianPos;
  int medianArr[studentCount]; //wait times in order

  //adds wait times to array
  for(int i = 0 ; i < studentCount; i++){
    medianArr[i] = arrStudent[i]->getWaitTime();
  }

  //putting the array in order
  for(int i = 0; i < studentCount; i++ ){
    for(int j = i + 1; j < studentCount ; j++){
      if(medianArr[i] < medianArr[j]){
        median = medianArr[i];
        medianArr[i] = medianArr[j];
        medianArr[j] = median;
      }
    }
  }

  studentSize++;

  //checks to see if uneven
  medianPos = studentSize%2;

  //if its an uneven list
  if(medianPos == 1){
    medianPos = (studentSize/2);
    cout << "The median for student wait time is: " << medianArr[medianPos] << endl;
  }
  else{
    medianPos = (studentSize/2);
    median = ((medianArr[medianPos + 1] + medianArr[medianPos]) /2);
    cout << "The median for student watitime: " << median << endl;
  }

//STUDENT LONGEST STUDENT WAIT TIME (already in order)-------------------------------------

  cout << "The longest Student Wait Time: " << medianArr[0] << endl;

//STUDENTS OVER 10 MINUTES-------------------------------------

  int student10 = 0;
  //iterates and checks each wait time if wait time is overs 10
  for(int i = 0 ; i < studentCount ; i++){
    if (medianArr[i] >= 10){
      student10++;
    }
	}
  cout << "The number of Student Wait Time over 10 minutes: " << student10 << endl;

//WINDOW MEAN-------------------------------------

  int meanWindow[windowSize];
  float windowSum = 0.0;

  //iterates and gets the wait times
  for(int i = 0; i < windowSize; i++){
    meanWindow[i] = arrWindow[i]->getWaitTime();
  }
  //getes the sum
  for(int i = 0; i < windowSize; i++){
    windowSum += meanWindow[i];
  }

  float windowMean = windowSum / windowSize; // calculates average

  cout << "\nWindow Idle Time Stats"<<endl;
  cout << "The mean window idle time is: " << windowMean << endl;

//WINDOW LONGEST TIME------------------------------------

  int tempWindow = 0;

  //puts the window idle time array in order
  for(int i = 0; i < windowSize; i++ ){
    for(int j = i + 1; j < windowSize; j++){
      if(meanWindow[i] < meanWindow[j]){
        tempWindow = meanWindow[i];
        meanWindow[i] = meanWindow[j];
        meanWindow[j] = tempWindow;
      }
    }
  }

  cout << "The longest window idle time is: " << meanWindow[0] << endl;

//WINDOWS OVER 5 MINUTES-------------------------------------

  int window5 = 0;
  //iterates and checks if window is over 5 minutes
  for(int i = 0 ; i < windowSize; i++){
    if (meanWindow[i] >= 5){
      window5++;
    }
	}
  cout << "The number of Window Wait Time over 5 minutes: " << window5 << endl;
  cout << endl;

}
