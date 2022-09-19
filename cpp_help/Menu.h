#pragma once
/*
* To use this menu create a file, or pass in a vector
* In the program use getMenuOption that returns a string then use if(menuIs(menuOption,start)) do start
*/
using namespace std;
#include<iostream>
#include<filesystem>
#include<vector>
#include <fstream>
#define FILENAME "Menu"
#define PATH "./Menus/"
#define EXTENTION ".txt"
string getMenuOption(std::vector<std::string> options);
string getMenuOption(std::string filename, std::string path);
void createMenuFile();
bool menuIs(std::string, std::string);