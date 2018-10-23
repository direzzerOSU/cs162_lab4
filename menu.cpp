/*********************************************************************
** Program name: OSU Information System
** Author: Ryan DiRezze
** Date: October 21, 2018
** Description: Implements all functions that are required to create
   the user-interface menu of the Information Management System, which
   users use in order to navigate around the system and perform various
   transactions.
*********************************************************************/

#include "menu.hpp"
#include "inputValidation.hpp"


// the main/primary menu that issues arrive at after starting the program;
// this menu allows the user to navigate to various areas of the program
// to perform different transactions and view different data.
void OSUISmenu(char& option) {
   // introduction
   string program_name = "OSU Information System";
   cout << "Hello! Welcome to the " << program_name << "!" << endl << endl;

   while(tolower(option) != 'a' && tolower(option) != 'b' && tolower(option) != 'c' && tolower(option) != 'd' && tolower(option) != 'e' && tolower(option) != 'f') {
      // menu prompt with an initial message after selecting to "begin" the program
      cout << "Please select an option from the following menu choices:" << endl;
      cout << "Input the option's corresponding letter to make a selection..." << endl << endl;
      
      // menu choices
      cout << "    a. Print information about all the buildings" << endl;
      cout << "    b. Print information about everybody at the university" << endl;
      cout << "    c. Choose a person to do work" << endl;  // would trigger another menu to print with a list of all the 
                                                            // people's names; the user would then select the person that 
                                                            // he/she would like to "do work"
      cout << "    d. Manage buildings at the university (add/edit/remove)" << endl;
      cout << "    e. Manage people at the university (add/edit/remove)" << endl;
      cout << "    f. Exit the program" << endl << endl;
      
      cin >> option;

      charValidation(option);

      cout << endl;

      if(tolower(option) != 'a' && tolower(option) != 'b' && tolower(option) != 'c' && tolower(option) != 'd' && tolower(option) != 'e' && tolower(option) != 'f') {
         cout << "Uh oh! It looks like you didn't input a valid menu option... Please try again." << endl << endl;
      }
   }
}

// a small prompt that asks the user if he/she would like to return to the main
// menu; this was intended to appear after the user performs some transaction
void mainMenuReturn(char& option) {
   option = 'n';
   while(tolower(option) == 'n') {
      cout << "Do you want to return to the main menu? (Y/N): ";
      cin >> option;
      validYesNo(option);

      if(tolower(option) == 'y') {
         option = 'z';       // let the program escape the 'while loop' & return to the menu
      }
      
      else if(tolower(option) == 'n') {
         cout << "Do you want to exit the program? (Y/N): ";
         cin >> option;
         validYesNo(option);
         
         // escape the 'while loop' & quit the program
         if(tolower(option) == 'y') {
            option = 'f';
            cout << endl;     // add a line & space for aesthetics
         }
         
         // do nothing and let the program run back through the 'while loop'
         else if(tolower(option) == 'n') {
            //option = 'n'
         }
      }
   }
}

// main menu function, which is NOT used in this program (OSU Information
// System)
void menu(bool& result){
   // introduction
   string program_name = "OSU Information System";
   cout << "Hello! Welcome to the " << program_name << ":" << endl;

   // user input to start the program or quit
   cout << "Please select an option from below:" << endl;
   cout << "   a. Start " << program_name << endl;
   cout << "   b. Quit" << endl << endl;
   char selection = ' ';
   cout << "Selection: ";
   cin >> selection;
   cout << endl;

   // input validation until the user selects a valid option
   while(tolower(selection) != 'a' && tolower(selection) != 'b'){
      cout << "Uh oh... That's not a valid option. Please try again." << endl;
      cout << "Selection: ";
      cin >> selection;
   }

   if(tolower(selection == 'a')){
      result = true;
   }
   else{
      cout << "Ending program..." << endl;
      result = false;
   }
}
