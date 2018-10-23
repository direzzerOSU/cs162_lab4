/*********************************************************************
** Program name: OSU Information System
** Author: Ryan DiRezze
** Date: October 21, 2018
** Description: Integrates all header and implementation files in order
   to create an Information Management System, consisting of buildings
   and people that are managed within this user program, representing
   those people and buildings at the Oregon State University.
*********************************************************************/

#include "menu.hpp"
#include "people.hpp"
#include "university.hpp"
#include "inputValidation.hpp"

int main() {
   srand(time(0));   // initialize the "seed" for randomly generating numbers
   cout << endl;     // create a space between other terminal data & the program

   // initialize variables for the menu (may not include typical start/quit
      // basic menu options due to increased complexity of OSI Information System's menu choices
 
   // standard (start/exit) menu with menu options
   // bool selection = true;     // used to determine whether the program will start or quit (from user input)
   
   // OSU Information System menu
   char menuInput = 'z';   // start with an invalid
   University university = University();

   while(menuInput != 'f') {
      menuInput = 'z';

      // start the menu & acquire user input to determine what the program will do
      OSUISmenu(menuInput);
      
      // prints information about all the buildings
      if(tolower(menuInput) == 'a'){
         cout << "University buildings: " << endl << endl;
         university.printBuildings();

         mainMenuReturn(menuInput);
      }

      // prints information about everybody at the university
      else if(tolower(menuInput) == 'b') {
         cout << "University Students & Instructors: " << endl;
         university.printPeople();

         mainMenuReturn(menuInput);
      }

      // choose a person to "do work" - will open a new menu & the user will
         // select a person from a list of people
      else if(tolower(menuInput) == 'c') {
         cout << "Who would you like to do work?" << endl << endl;
         university.printPeopleIDs();
         int inputID;
         cout << "Please input the person's corresponding ID: ";
         cin >> inputID;

         cout << endl;
         university.printWork(inputID);
         cout << endl;

         mainMenuReturn(menuInput);       
         cout << endl;  
      }

      // add/edit/remove a building to the university
      else if(tolower(menuInput) == 'd') {
         university.updateBuildings();
      }

      // add a person to the university
      else if(tolower(menuInput) == 'e') {
         university.updatePeople();
      }

      // exit the program
      else if(tolower(menuInput) == 'f') {
         // no action required; program escapes 'while' loop to terminate
      }
   }

   return 0;
}
