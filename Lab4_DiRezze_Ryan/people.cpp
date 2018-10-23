/*********************************************************************
** Program name: OSU Information System
** Author: Ryan DiRezze
** Date: October 21, 2018
** Description: Implements a variety of functions for the "Person" base
   class and its derived classes, Student and Instructor. These functions
   primarily relate to creating and updating attributes of people within
   the OSU Information System.
*********************************************************************/

#include "people.hpp"

// returns a person's name
std::string Person::getName() {
   return name;
}

// returns a person's age
int Person::getAge() {
   return age;
}

// pure virtual function that isn't used with the base class
void Person::do_work() {
   cout << "N/A" << endl;
}

// prints the number of hours a student object did homework
void Student::do_work() {
   int x = (rand() % 61);
   cout << getName() << " did " << x << " hours of homework." << endl;  
}

// prints the number of hours an instructor object graded papers
void Instructor::do_work() {
   int x = (rand() % 61);
   cout << getName() << " graded papers for " << x << " hours." << endl;
}

// a pure virtual function because the person base class doesn't have
// a rating/gpa
void Person::setRating(float input) {
   cout << "N/A" << endl;
}

// a pure virtual function because the person base class doesn't have
// a rating/gpa
float Person::getRating() {
   return 0;
}

// returns a student's GPA
float Student::getRating() {
   return gpa;
}

// returns the rating of an instructor
float Instructor::getRating() {
   return rating;
}

// updates a person's name
void Person::setName(std::string input) {
   this->name = input;
}

// updates a person's age
void Person::setAge(int input) {
   this->age = input;
}

// updates an instructor's rating
void Instructor::setRating(float input) {
   while(input > 5.0 || input < 0.0) {
      cout << "Whoops! An instructor's rating has to be between 0.0 and 5.0... Please try again: " << endl;
      cin >> input;
   }
   this->rating = input;
}

// randomly generates a rating value for an instructor from 0.0 - 5.0
void Instructor::randRating() {
   float temp = -5.0;
   while(temp > 5.0 || temp < 0.0) {
      temp = ((static_cast <float> (rand())) / (static_cast <float> (RAND_MAX/5.0)));
   }
   temp *= 10;
   temp = static_cast<int>(temp);
   temp = static_cast<float>(temp)/10.0;
   this->rating = temp;
}

// sets a student's GPA value
void Student::setRating(float input) {
   while(input > 5.0 || input < 0.0) {
      cout << "Whoops! A student's GPA has to be between 0.0 and 4.0... Please try again: " << endl;
      cin >> input;
   }
   this->gpa = input;
}

// randomly generates a value for a student's GPA from 0.0 - 4.0
void Student::randRating() {
   float temp = -4.0;
   while(temp > 4.0 || temp < 0.0) {
      temp = ((static_cast <float> (rand())) / (static_cast <float> (RAND_MAX/4.0)));
   }
   temp *= 10;
   temp = static_cast<int>(temp);
   temp = static_cast<float>(temp)/10;
   this->gpa = temp;
}

// pure virtual function because the age functions vary based on the derived
// class(es)
void Person::randAge() {
   this->age = 0;
}

// randomly generates and sets a student's age
void Student::randAge() {
   int randomAge = 0;
   while(randomAge > 50 || randomAge < 17) {
      randomAge = rand() % 51;   // students' ages will range from: 17 - 50 (inclusive)
   }
   
   this->age = randomAge;
}

// randomly generates and sets an instructor's age
void Instructor::randAge() {
   int randomAge = 0;
   while(randomAge > 70 || randomAge < 25) {
      randomAge = rand() % 71;    // instructors' ages will range from: 25 - 70 (inclusive)
   }

   this->age = randomAge;
}

// pure virtual function because a base class object doesn't have a rating/GPA
std::string Person::getRatingType() {
   return "N/A";
}

// returns the "rating" type of an instructor: "Rating"
std::string Instructor::getRatingType() {
   return "Rating";
}

// returns the "rating" type of a student: "GPA"
std::string Student::getRatingType() {
   return "GPA";
}
