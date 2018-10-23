/*********************************************************************
** Program name: OSU Information System
** Author: Ryan DiRezze
** Date: October 21, 2018
** Description: Defines the university and building classes, including
   each class' function prototypes. This file also contains the libraries
   that are used when implementing each class' functions to ensure the 
   code behaves as intended.
*********************************************************************/

#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "people.hpp"
#include<string>
#include<vector>
using std::vector;
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

// defines a building that is a part of OSU
class Building {
 public:
   Building();
   Building(std::string);
   void setName(std::string);
   std::string getName();
   void setSize(int);
   int getSize();
   void setAddress(std::string);
   std::string getAddress();
 private:
   std::string name = "";
   int size = 0;           // initialize to 0 for easy debugging; size of the bldg. in sq. ft.
   std::string address = "";
};

// defines Oregon State University, which includes all buildings, students, and
// instructors
class University {
 public:
   // general functions
   University();
   std::string getName();

   // building functions
   void addDefinedBuilding(std::string, int, std::string);
   void addBuilding();
   void updateBuildings();
   void printBuilding(int);
   void printBuildings();
   void printBuildingIDs();

   // people (students & instructors) functions
   void addPerson(std::string, int, float);  // (not used) must be able to determine whether the person is an instructor/student
   void addPerson();  
   void addDefinedInstructor(std::string, int, float);   // name, age, rating
   void addInstructor(std::string); // name
   void addDefinedStudent(std::string, int, float);      // name, age, GPA
   void addStudent(std::string); //, int iAge, float iRating);
   void updatePeople();
   void printPerson(int);
   void printPeople();
   void printPeopleIDs();
   void printWork(int);
 private:
   std::string name = "Oregon State University";
   std::vector<Building> buildings;
   std::vector<Person*> people;
   int numBuildings = buildings.size();
   int numPeople;
};

#endif
