#include "Logger.h"

Logger* Logger::instance = nullptr;
Logger::Logger() {
}
Logger::~Logger()
{
}

Logger* Logger::getInstance()
{
	if (instance == nullptr) {
		instance = new Logger();
	}
	return instance;
}
//TODO:: Develop a more robust Logging System
void Logger::printMsg(const char* msg)
{

	std::cout << msg << std::endl;
	/*switch (type) {
	case INFO:
		std::cout <<"INFO: "<< msg << std::endl;
		break;
	case ERROR:
		std::cout <<"ERROR: "<< msg << std::endl;
		break;
	case CRITICAL:
		std::cout << "CRITICAL: "<< msg << std::endl;
		break;*/
}

