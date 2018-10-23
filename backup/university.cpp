/*********************************************************************
** Program name: OSU Information System
** Author: Ryan DiRezze
** Date: October 21, 2018
** Description: Implements the university and building classes, including
   the functions within each class. These functions allow the user to
   add/edit/remove buildings, and perform major transactions or view
   data from the Information Management System, which consists of data
   representing people and buildings at Oregon State University.
*********************************************************************/

#include "university.hpp"
#include "inputValidation.hpp"

// constructor to initialize the core object that is used to store, edit, view,
// and delete data that relates to OSU
University::University() {
   //name = "Oregon State University";    // commented out because this is defined within the class (on the header)

   // initialize the university with the required number of each data object
   
   // (2) buildings
   addDefinedBuilding("Kelley Engineering Center", 152166, "110 SW Park Terrace, Corvallis, OR 97331");
   addDefinedBuilding("The Valley Library", 333920, "201 SW Waldo PL, Corvallis, OR 97331");

   // (1) instructor
   addInstructor("Samantha Alvarado");

   // (1) student
   addStudent("Ryan DiRezze");
}

// constructor that initializes a new building
Building::Building() {
   name = "";
   size = 0;
   address = "";
}

// initializes a new building with a specific name
Building::Building(std::string bldgName) {
   name = bldgName;
}

// updates the name of an existing building
void Building::setName(std::string input) {
   name = input;
}

// retrieves the name of an existing building
std::string Building::getName() {
   return name;
}

// updates the size of an existing building
void Building::setSize(int input) {
   size = input;
}

// returns the size of an existing building
int Building::getSize() {
   return size;
}

// updates the address of an existing building
void Building::setAddress(std::string input) {
   address = input;
}

// returns a building's address
std::string Building::getAddress() {
   return address;
}

// a function that opens a new menu prompt that allows the user to update 1+
// buildings within the Information System
void University::updateBuildings() {
   cout << getName() << " currently has " << buildings.size() << " buildings..." << endl;
   cout << "What would you like to do?" << endl;

   cout << "Choices: " << endl;
   cout << "   a. Add building" << endl;
   cout << "   b. Update/Edit building" << endl;
   cout << "   c. Remove building" << endl;
   cout << "   d. Cancel" << endl;

   char input;
   bool sameBuilding = true;   // used for updating >1 data attribute for a building at a time

   cin >> input;

   charValidation(input);

   // add a building by accepting user inputs
   if(tolower(input) == 'a') {
      // add a building
      cout << endl << "Adding a building..." << endl << endl;
      addBuilding();
      cout << endl << "Building added..." << endl << endl;
   }

   // update/edit buildings
   else if(tolower(input) == 'b') {
      cout << endl << "You've chosen to edit and update existing buildings..." << endl;
      int buildingSelection = -10;  // initialized to -10 for easy "bug" fixing

      while(tolower(input) == 'b') {
         cout << endl << "List of buildings: " << endl << endl;
         printBuildingIDs();
         cout << "Please select the building's corresponding number that you'd like to edit..." << endl;

         // user selects the building that he/she would like to edit and update
         cout << "What building would you like to edit and update?: ";
         cin >> buildingSelection;

         // validate user's input is a valid building number
         while(buildingSelection > buildings.size()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            cout << "You did not select a valid option for editing a building attribute...\n  Please enter a valid option: ";
            cin >> buildingSelection;
            cout << endl;
         }

         sameBuilding = true;

         // continue prompting the user to update data attributes on the same
         // building until the user tells the program otherwise
         while(sameBuilding == true) {
            // ask for the data element that the user would like to update
            //    update that data element with a "setter"
            cout << endl << "What would you like to edit on the building?" << endl;
            cout << "   a. Name" << endl;
            cout << "   b. Size (in square feet)" << endl;
            cout << "   c. Address" << endl;
            cout << "   d. Cancel" << endl;
            char buildingAttribute;
            cout << endl << "Selection: ";
            cin >> buildingAttribute;

            // input validation
            validBldgChoice(buildingAttribute);

            // update the building's name
            if(tolower(buildingAttribute) == 'a') {
               cout << endl << "Updated name: ";
               std::string newName = "";
               getline(cin.ignore(), newName);
               buildings[(buildingSelection-1)].setName(newName);
            }

            // update the building's size
            else if(tolower(buildingAttribute) == 'b') {
               cout << endl << "Updated size (in sq. ft.): ";
               int newSize = -10;
               cin >> newSize;
               buildings[(buildingSelection-1)].setSize(newSize);
            }

            // update the building's address
            else if(tolower(buildingAttribute) == 'c') {
               cout << endl << "Updated address: ";
               std::string newAddress = "";
               getline(cin.ignore(), newAddress);
               buildings[(buildingSelection-1)].setAddress(newAddress);
            }
            else if(tolower(buildingAttribute) == 'd') {
               sameBuilding = false;   // break the "same building" loop; return to select a building (loop)
            }
            
            // catch others | 'bug' "catcher"
            else {
               cout << "Uh oh... There's a 'bug'; inputValidation didn't work as intended." << endl;
               cout << "   This 'bug' occurred when trying to update a building's name/size/address..." << endl;
            }

            // print building & its data attributes to show a successful update to attribute values
            if(tolower(buildingAttribute) == 'a' || tolower(buildingAttribute) == 'b' || tolower(buildingAttribute) == 'c') {
               cout << endl << "Building #" << buildingSelection << " updated..." << endl;
               printBuilding(buildingSelection);

               // ask the user if he/she would like to update another attribute
               cout << endl << "Would you like to update another data attribute on building #" << buildingSelection << "? (Y/N): " << endl;
               char select = 'z';
               cin >> select;
               validYesNo(select);

               if(tolower(select) == 'n') {
                  sameBuilding = false;      // break the loop to prompt for another building
               }
            }
         }
         
         // ask the user if he/she would like to update another building
         cout << endl << "Would you like to update another building? (Y/N): " << endl;
         char repeat = 'z';
         cin >> repeat;
         validYesNo(repeat);

         if(tolower(repeat) == 'y') {
            // do nothing; 'while loop' will prompt for another building
         }
         else if(tolower(repeat) == 'n') {
            cout << endl;           // add a line gap for aesthetics
            input = 'z';            // breaks the loop for editing/updating buildings
         }
      // bring the user back to the main menu
      }
   }
   else if(tolower(input) == 'c') {
      // remove a building
      cout << endl << "Which building would you like to remove?" << endl << endl;
      printBuildingIDs();
      int ID;
      cout << "Building #: ";
      cin >> ID;
      intValidation(ID);

      buildings.erase(buildings.begin()+ID-1);

      cout << endl;     // add a space for aesthetics
   }
   else if(tolower(input) == 'd') {
      cout << endl;  // add a line gap for aesthetics
      // do nothing; let the function complete & return to the menu
   }
}

// returns the name of the university object, which is: Oregon State University
std::string University::getName() {
   return name;
}

// prints a specific building within the information system, which uses an
// "offset" to account for the vector's starting position of "0" instead of
// "1", which is the first building's ID
void University::printBuilding(int number) {
   cout << buildings[number-1].getName() << endl;
   cout << buildings[number-1].getSize() << endl;
   cout << buildings[number-1].getAddress() << endl;
}

// print the core data attributes for all OSU buildings within the system
void University::printBuildings() {
   for(int n=0; n<buildings.size(); n++) {
      cout << buildings[n].getName() << endl;
      cout << buildings[n].getSize() << endl;
      cout << buildings[n].getAddress() << endl << endl;
   }
}

// prints the core data attributes (& a corresponding ID) for all OSU
// buildings; the ID is used to select a specific building within the system
void University::printBuildingIDs() {
   for(int n=0; n<buildings.size(); n++) {
      cout << "Building # " << n+1 << ": " << endl;
      cout << buildings[n].getName() << endl;
      cout << buildings[n].getSize() << endl;
      cout << buildings[n].getAddress() << endl << endl;
   }
}

// function that opens a prompt for various pieces of information, which the
// user enters, to create a new building
void University::addBuilding() {
   cout << "Please enter the name, size (in sq. ft.) and address of the building that you'd like to add:" << endl;
   Building b1 = Building();

   cout << endl << "Building name: ";
   std::string bName;
   getline(cin.ignore(), bName);
   //cin >> bName;
   b1.setName(bName);

   cout << endl << "Building size (in sq. ft.): ";
   int bSize;
   cin >> bSize;
   b1.setSize(bSize);

   cout << endl << "Building address: ";
   std::string bAddress;
   getline(cin.ignore(), bAddress);
   //cin >> bAddress;
   b1.setAddress(bAddress);

   buildings.insert(buildings.end(), b1);
}

// adds a new building with all "core" data attribtues as function parameters
void University::addDefinedBuilding(std::string bName, int bSize, std::string bAddress) {
   Building b1 = Building();

   b1.setName(bName);
   b1.setSize(bSize);
   b1.setAddress(bAddress);

   buildings.insert(buildings.begin(), b1);
}

// adds a new OSU instructor with a specific name and randomized age & rating
void University::addInstructor(std::string name) {
   Instructor* i1 = new Instructor();
   i1->setName(name);
   i1->randAge();
   i1->randRating();

   people.insert(people.end(), i1);
}

// adds a new OSU student with a specific name and randomized age & gpa
void University::addStudent(std::string name) {
   Student* s1 = new Student();
   s1->setName(name);
   s1->randAge();
   s1->randRating();

   people.insert(people.end(), s1);
}

// prints all people within the system (students & instructors)
void University::printPeople() {
   for(int n=0; n<people.size(); n++) {
      cout << "Name: " << people[n]->getName() << endl;
      cout << "Age: " << people[n]->getAge() << endl;
      cout << people[n]->getRatingType() << ": " << people[n]->getRating() << endl << endl;
   }
}

// prints all people within the system (students & instructors); also assigns
// a specific ID to each person for use when the user wants to access
// a specific person within the system
void University::printPeopleIDs() {
   for(int n=0; n<people.size(); n++) {
      cout << "ID #: " << n+1 << endl;
      cout << "Name: " << people[n]->getName() << endl;
      cout << "Age: " << people[n]->getAge() << endl;
      cout << people[n]->getRatingType() << ": " << people[n]->getRating() << endl << endl;
   }
}

// prints a message for a specific person that must do work
void University::printWork(int n) {
   people[n-1]->do_work();
}

// creates a new instructor within the system that has all "core" data
// attributes as function parameters
void University::addDefinedInstructor(std::string iname, int iage, float irating) {
   Instructor* i1 = new Instructor();
   i1->setName(iname);
   i1->setAge(iage);
   i1->setRating(irating);

   people.insert(people.end(), i1);
}

// creates a new student within the system that has all "core" data
// attributes as function parameters
void University::addDefinedStudent(std::string sname, int sage, float srating) {
   Student* s = new Student();
   s->setName(sname);
   s->setAge(sage);
   s->setRating(srating);

   people.insert(people.end(), s);
}

// prompt for the system's user to navigate and add/edit/remove people from the
// system
void University::updatePeople() {
   cout << getName() << " currently has " << people.size() << " people..." << endl;
   cout << "What would you like to do?" << endl;

   cout << "Choices: " << endl;
   cout << "   a. Add person" << endl;
   cout << "   b. Update/Edit person" << endl;
   cout << "   c. Remove person" << endl;
   cout << "   d. Cancel" << endl;

   char input;
   bool samePerson = true;   // used for updating >1 data attribute for a person at a time

   cin >> input;

   charValidation(input);

   // add a person by accepting user inputs
   if(tolower(input) == 'a') {
      // add a person
      cout << endl << "Adding a person..." << endl << endl;
      addPerson();
      cout << endl << "Person added..." << endl << endl;
   }

   // update/edit people
   else if(tolower(input) == 'b') {
      cout << endl << "You've chosen to edit and update existing people..." << endl;
      int personSelection = -10;  // initialized to -10 for easy "bug" fixing

      while(tolower(input) == 'b') {
         cout << endl << "List of people: " << endl << endl;
         printPeopleIDs();
         cout << "Please select the person's corresponding number that you'd like to edit..." << endl;

         // user selects the person that he/she would like to edit and update
         cout << "What person would you like to edit and update?: ";
         cin >> personSelection;

         // validate user's input is a valid person number
         while(personSelection > people.size()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            cout << "You did not select a valid option for editing a person's attribute...\n  Please enter a valid option: ";
            cin >> personSelection;
            cout << endl;
         }

         samePerson = true;

         // continue prompting the user to update data attributes on the same
         // person until the user tells the program otherwise
         while(samePerson == true) {
            // ask for the data element that the user would like to update
            //    update that data element with a "setter"
            cout << endl << "What would you like to edit for this person?" << endl;
            cout << "   a. Name" << endl;
            cout << "   b. Age" << endl;
            cout << "   c. Rating/GPA" << endl;
            cout << "   d. Cancel" << endl;
            char personAttribute;
            cout << endl << "Selection: ";
            cin >> personAttribute;

            // input validation
            validBldgChoice(personAttribute);

            // update the person's name
            if(tolower(personAttribute) == 'a') {
               cout << endl << "Updated name: ";
               std::string newName = "";
               getline(cin.ignore(), newName);
               people[(personSelection-1)]->setName(newName);
            }

            // update the person's size
            else if(tolower(personAttribute) == 'b') {
               cout << endl << "Updated age: ";
               int newAge = -10;
               cin >> newAge;
               people[(personSelection-1)]->setAge(newAge);
            }

            // update the person's rating/GPA
            else if(tolower(personAttribute) == 'c') {
               cout << endl << "Updated " << people[(personSelection-1)]->getRatingType() << ": ";
               float newRating = 0.0;
               cin >> newRating;
               floatValidation(newRating);
//               getline(cin.ignore(), newrating);
               people[(personSelection-1)]->setRating(newRating);
            }
            else if(tolower(personAttribute) == 'd') {
               samePerson = false;   // break the "same person" loop; return to select a person (loop)
            }
            
            // catch others | 'bug' "catcher"
            else {
               cout << "Uh oh... There's a 'bug'; inputValidation didn't work as intended." << endl;
               cout << "   This 'bug' occurred when trying to update a person's name/age/rating/GPA..." << endl;
            }

            // print person & his/her data attributes to show a successful update to attribute values
            if(tolower(personAttribute) == 'a' || tolower(personAttribute) == 'b' || tolower(personAttribute) == 'c') {
               cout << endl << "ID #" << personSelection << " updated..." << endl;
               printPerson(personSelection);

               // ask the user if he/she would like to update another attribute
               cout << endl << "Would you like to update another data attribute on ID #" << personSelection << "? (Y/N): " << endl;
               char select = 'z';
               cin >> select;
               validYesNo(select);

               if(tolower(select) == 'n') {
                  samePerson = false;      // break the loop to prompt for another person
               }
            }
         }
         
         // ask the user if he/she would like to update another person
         cout << endl << "Would you like to update another person? (Y/N): " << endl;
         char repeat = 'z';
         cin >> repeat;
         validYesNo(repeat);

         if(tolower(repeat) == 'y') {
            // do nothing; 'while loop' will prompt for another person
         }
         else if(tolower(repeat) == 'n') {
            cout << endl;           // add a line gap for aesthetics
            input = 'z';            // breaks the loop for editing/updating people
         }
      // bring the user back to the main menu
      }
   }
   else if(tolower(input) == 'c') {
      // remove a person
      cout << endl << "Which person would you like to remove?" << endl << endl;
      printPeopleIDs();
      int ID;
      cout << "ID #: ";
      cin >> ID;
      intValidation(ID);

      people.erase(people.begin()+ID-1);

      cout << endl;     // add a space for aesthetics
   }
   else if(tolower(input) == 'd') {
      cout << endl;  // add a line gap for aesthetics
      // do nothing; let the function complete & return to the menu
   }

}

// adds a new person based on various user-entered data attributes, which are
// requested within this function
void University::addPerson() {
   cout << "Is this person an instructor or a student?" << endl;
   cout << "   a. Instructor" << endl;
   cout << "   b. Student" << endl;

   char input = 'z';
   cin >> input;
   cout << endl;     // for aesthetics
   validTypeChoice(input);

   // add an instructor
   if(tolower(input) == 'a') {
      cout << "Please enter the name, age, and rating of the instructor that you'd like to add..." << endl;

      cout << endl << "Instructor's name: ";
      std::string iName;
      getline(cin.ignore(), iName);

      cout << endl << "Instructor's age: ";
      int iAge;
      cin >> iAge;

      cout << endl << "Instructor's rating: ";
      float iRating;
      cin >> iRating;

      addDefinedInstructor(iName, iAge, iRating);
   }

   // add a student
   else if(tolower(input) == 'b') {
      cout << "Please enter the name, age, and rating of the student that you'd like to add..." << endl;

      cout << endl << "Student's name: ";
      std::string sName;
      getline(cin.ignore(), sName);

      cout << endl << "Student's age: ";
      int sAge;
      cin >> sAge;

      cout << endl << "Student's rating: ";
      float sRating;
      cin >> sRating;

      addDefinedStudent(sName, sAge, sRating);
   }
}

// prints the "core" data attributes of a specific person, which uses the
// person's ID as a means to specify that object
void University::printPerson(int ID) {
   cout << people[ID-1]->getName() << endl;
   cout << people[ID-1]->getAge() << endl;
   cout << people[ID-1]->getRating() << endl;
}
