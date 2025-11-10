#include <iostream>

class Log
{
public:
	enum Level
	{
		LevelError = 0,
		LevelWarning,
		LevelInfo
	};
private:
	Level m_logLevel = LevelInfo;
public:
	void setLevel(Level level)
	{
		m_logLevel = level;
	}
	void warn(const char* message)
	{
		if (m_logLevel >= LevelWarning)
		{
			std::cout << "[WARNING]: " << message << std::endl;
		}
	}
	void error(const char* message)
	{
		if (m_logLevel >= LevelError)
		{
			std::cout << "[ERROR]: " << message << std::endl;
		}
	}
	void info(const char* message)
	{
		if (m_logLevel >= LevelInfo)
		{
			std::cout << "[INFO]: " << message << std::endl;
		}
	}

};

void func()
{

}
int main()
{

	Log log;
	log.setLevel(Log::LevelError);
	log.warn("This is a warning");
	log.error("This is an error");
	log.info("This is an info");

	//std::cin.get();

}