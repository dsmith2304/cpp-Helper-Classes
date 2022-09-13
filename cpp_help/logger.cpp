
#include "logger.h"

void writeLog(std::string msg, int Severity, bool releaseWrite, std::string logName) {
	bool temp = RELEASEMODE;

	// Dont write if in release mode and log doesnt get logged in release
	if (releaseWrite == false && temp == true) {
		return;
	}

	// if folder doesnt exist create it
	if (!std::filesystem::exists(LOGSPATH)) {
		std::filesystem::create_directory(LOGSPATH);
	}

	//curent date time
	auto now = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(now);

	// append log
	ofstream outfile;
	outfile.open(LOGSPATH + logName + LOGEXTENSION, std::ios::app);
	outfile << msg << ":\t Severity :" << Severity << "\t" << std::ctime(&end_time);
	outfile.close();
}


void analyzeLog(std::string logName) {
	std::string line;
	char* splitString;

	vector<std::string> messages;
	vector<int> messageCount;


	ifstream input_file(LOGSPATH+ logName+LOGEXTENSION);

	if (!input_file.is_open()) {
		writeLog("Error opening log " + logName, 2, false, "logger");
	}

	getline(input_file, line);
	while (!input_file.eof()) {
	 splitString = _strdup(line.c_str());

	 auto pos = find(messages.begin(), messages.end(), strtok(splitString, ":"));
	 
	 if (pos == messages.end()) {
		 messages.push_back(strtok(splitString, ":"));
		 messageCount.push_back(1);
	 }
	 else {
		 int index = std::distance(messages.begin(), pos);
		 messageCount.at(index)++;
	 }
	
	 getline(input_file, line);
	}


	for (int i = 0; i < messages.size(); i++) {
		cout << messages.at(i) << " " << messageCount.at(i);;

	}
}