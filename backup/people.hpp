/*********************************************************************
** Program name: OSU Information System
** Author: Ryan DiRezze
** Date: October 21, 2018
** Description: Defines the base class, Person, and its derived classes,
   Student and Instructor, which are used to represent people at Oregon
   State University. Each class' functions are also prototyped in this
   header while including any libraries that need to be used for functions
   and code to operate as intended.
*********************************************************************/

#ifndef PEOPLE_H
#define PEOPLE_H

#include<vector>
#include<string>
using std::string;
#include<cstdlib>   // supports the use of srand (in main) and rand() when initializing objects
#include<ctime>
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<cmath>

// defines a base class, representing a person
class Person {
 public:
   Person()
   {  name = ""; age = 0;   };
   virtual void do_work();
   virtual void setRating(float);
   virtual float getRating();
   virtual void randAge();
   virtual std::string getRatingType();
   void setName(std::string);
   std::string getName();
   void setAge(int);
   int getAge();
 protected:
   std::string name = "";
   int age = 0;
};

// defines a derived class, representing a person that is a student
class Student : public Person {
 public:
    Student() : Person()
   {  name = ""; age = 0; gpa = 0.0; };
    void do_work();
    void setRating(float);
    void randRating();
    float getRating();
    void randAge();
    std::string getRatingType();
 private:
    float gpa = -100.0;
};

// defines a derived class, representing a person that is an instructor
class Instructor : public Person {
 public:
    Instructor() : Person()
   {  name = ""; age = 0; rating = 0.0;   };
    void do_work();
    void setRating(float);
    void randRating();
    float getRating();
    void randAge();
    std::string getRatingType();
 private:
    float rating = -100.0;
};

#endif
