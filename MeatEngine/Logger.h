#pragma once
#include <iostream>
enum msgType {
	INFO,
	ERR,
	CRITICAL
};

class Logger {
private:
	Logger();
	~Logger();
	msgType type;
	static Logger* instance;
public:
	static Logger* getInstance();
	void printMsg(const char* msg);
};

