#pragma once
#include <iostream>
#include <fstream>
#include <string>
#define PATH "./configs/"
#define MAXCHARS 100
#define EXTENTION ".txt"
#define COMMENTCHAR '#'
using namespace std;

float init_float(std::string name, std::string path, std::string filename);
int init_int(std::string name, std::string path, std::string filename);
std::string init_string(std::string name, std::string path, std::string filename);