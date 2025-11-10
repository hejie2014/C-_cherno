#include <iostream>
//#include "log.h"

//#define log(x) std::cout << x << std::endl;
class Log
{
public:
	const int logLevelError = 0;
	const int logLevelWarning = 1;
	const int logLevelInfo = 2;
private:
	int m_logLevel = logLevelInfo;
public:
	void setLevel(int level)
	{
		m_logLevel = level;
	}
	void warn(const char* message)
	{
		if (m_logLevel >= logLevelWarning)
		{
			std::cout << "[WARNING]: " << message << std::endl;
		}
	}
	void error(const char* message)
	{	
		if (m_logLevel >= logLevelError)
		{
			std::cout << "[ERROR]: " << message << std::endl;
		}
	}
	void info(const char* message)
	{
		if (m_logLevel >= logLevelInfo)
		{
			std::cout << "[INFO]: " << message << std::endl;
		}
	}

};


int main()
{  
	
	Log log;
	log.setLevel(log.logLevelWarning);
	log.warn("This is a warning");
	log.error("This is an error");
	log.info("This is an info");
	
	//std::cin.get();

}