/*********************************************************************
** Program name: OSU Information System
** Author: Ryan DiRezze
** Date: October 21, 2018
** Description: Defines the functions, which are used to navigate the
   Information Management System, including each function's prototype
   and required libraries to ensure the menu's implementation of code
   behaves as intended.
*********************************************************************/

#ifndef MENU_H
#define MENU_H

#include<fstream>
using std::ifstream;
using std::ofstream;
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string>
using std::string;

// function prototype for the program's menu
void menu(bool&);
void OSUISmenu(char&);
void mainMenuReturn(char&);

#endif
