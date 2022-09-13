#include "logger.h"

void main() {
	writeLog("Error write failed", 4, false, "test");
	analyzeLog("test");
}