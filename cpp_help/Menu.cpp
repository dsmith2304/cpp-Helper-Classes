#include "Menu.h"
std::string getMenuOption(std::vector<std::string> options) {
	int input = -1;
	system("cls");
	while (input <= 0 && input > options.size()) {
		for (int i = 1; i < options.size()+1; i++) {
			std::cout << i << "." << options.at(i-1) << "\n";
		}
		std::cout << options.size() + 1 << "." << "Exit\n";
		std::cout << "Enter :";
		cin >> input;
		system("cls");
	}
	if (input > options.size()) {
		return "exit";
	}
	else {
		return options.at(input-1);
	}
}
/// <summary>
/// set path to "0" to get default path "./Menus/
/// </summary>
/// <param name="filename"></param>
/// <param name="path"></param> 
/// <returns></returns>
std::string getMenuOption(std::string filename, std::string path) {
	if (strcmp(path.c_str(), "0") == 0) {
		path = PATH;
	}
	ifstream infile;
	std::vector<string> options;
	infile.open(path + filename + EXTENTION);
	std::string input;
	while (!infile.eof()) {
		getline(infile, input);
		options.push_back(input);
	}
	infile.close();
	return getMenuOption(options);
}

void createMenuFile() {
	system("cls");
	std::cout << "Enter file name :";
	string filename;
	cin >> filename;
	std::cout << "Enter path name ['0' for default] :";
	string path;
	cin >> path;
	int iteration = 0;
	if (strcmp(path.c_str(), "0") == 1) {
		if (!std::filesystem::exists(path)) {
			std::filesystem::create_directory(path);
		}
	}
	else {
		if (!std::filesystem::exists(PATH)) {
			std::filesystem::create_directory(PATH);
			
		}
		path = PATH;
	}
	ofstream outfile;
	outfile.open(path + filename + EXTENTION, std::ios::out);

	std::string input = "";
	system("cls");
	while (strcmp(input.c_str(), "0") != 0) {
		std::cout << "Enter menu options for menu " << filename << "\n";
		std::cout << "Enter 0 to exit\n";
		std::cout << "Enter :";
		cin >> input;
		if (strcmp(input.c_str(), "0") != 0){
			if (iteration != 0) {
				outfile << "\n" << input;
			}
			else {
				outfile << input;
			}
			iteration++;
		}
		system("cls");
	}
	outfile.close();
}

bool menuIs(std::string one, std::string two) {

	if (strcmp(one.c_str(), two.c_str()) == 0) {
		return true;
	}
	else {
		return false;
	}
}