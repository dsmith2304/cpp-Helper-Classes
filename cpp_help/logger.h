#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include<iostream>
#include <chrono>
#include <filesystem>
using namespace std;

#define RELEASEMODE false;
#define LOGSPATH "./Logs/"
#define LOGEXTENSION ".txt"

void writeLog(std::string msg, int Severity, bool releaseWrite, std::string logName);
void analyzeLog(std::string logName);