#define _CRT_SECURE_NO_WARNINGS
#include "config.h"
int init_int(std::string name, std::string path, std::string filename) {
	std::string data;
	char* splitString;

	if (strcmp(path.c_str(), "0") == 0) { // is default path ?
		path = PATH;
	}

	ifstream infile;
	infile.open(path + filename + EXTENTION);

	while (!infile.eof()) {
		getline(infile, data); // get line
		if (data.at(0) == COMMENTCHAR) { // is comment line?

		}// carry on
		else { // not comment line
			splitString = _strdup(data.c_str());
			if (strcmp(name.c_str(), strtok(splitString, ":")) == 0) { // if data in name of variable were looking for
				char* temp = (char*)malloc(sizeof(char) * MAXCHARS);
				bool start = false;
				int x = 0;
				for (int i = 0; i < data.size(); i++) { // pull data from line
					if (start == true) {
						temp[x] = data[i];
						x++;
					}
					if (data[i] == ':') {
						start = true;
					}

				}
				infile.close();
				temp[x] = '\0'; // set line end
				return atoi(temp);
			}
		}

	}
	return NULL;
}

float init_float(std::string name, std::string path, std::string filename) {
	std::string data;
	char* splitString;

	if (strcmp(path.c_str(), "0") == 0) { // is default path ?
		path = PATH;
	}

	ifstream infile;
	infile.open(path + filename + EXTENTION);

	while (!infile.eof()) {
		getline(infile, data); // get line
		if (data.at(0) == COMMENTCHAR) { // is comment line?

		}// carry on
		else { // not comment line
			splitString = _strdup(data.c_str());
			if (strcmp(name.c_str(), strtok(splitString, ":")) == 0) { // if data in name of variable were looking for
				char* temp = (char*)malloc(sizeof(char) * MAXCHARS);
				bool start = false;
				int x = 0;
				for (int i = 0; i < data.size(); i++) { // pull data from line
					if (start == true) {
						temp[x] = data[i];
						x++;
					}
					if (data[i] == ':') {
						start = true;
					}

				}
				infile.close();
				temp[x] = '\0'; // set line end
				return atof(temp);
			}
		}

	}
	return NULL;
}


std::string init_string(std::string name, std::string path, std::string filename) {
	std::string data;
	char* splitString;

	if (strcmp(path.c_str(), "0") == 0) { // is default path ?
		path = PATH;
	}

	ifstream infile;
	infile.open(path + filename + EXTENTION);
	
	while (!infile.eof()) { 
		getline(infile, data); // get line
		if (data.at(0)== COMMENTCHAR) { // is comment line?

		}// carry on
		else { // not comment line
			splitString = _strdup(data.c_str());
			if (strcmp(name.c_str(), strtok(splitString, ":")) == 0) { // if data in name of variable were looking for
				char* temp= (char*)malloc(sizeof(char) * MAXCHARS);
				bool start = false;
				int x = 0;
				for (int i = 0; i < data.size(); i++) { // pull data from line
					if (start == true) {
						temp[x] = data[i];
						x++;
					}
					if (data[i] == ':') {
						start = true;
					}
					
				}
				infile.close();
				temp[x] = '\0'; // set line end
				return temp;
			}
		}
		
	}
	return NULL;
}