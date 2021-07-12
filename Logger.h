#ifndef LOGGER_H
#define LOGGER_h

#include <iostream>
#include <fstream>

#define LOG_FILE "log.txt"
#define DEBUG(str) Logger::instance()->writeLog(str)
#define LOG Logger::instance()->output() << "[" << __FUNCTION__ << "][" << __LINE__ << "] "

class Logger
{
    static Logger* m_instance;
    static std::fstream outFile;
public:
    static Logger* instance();
    ~Logger();
    static std::fstream& output();
    static void writeLog(const std::string& msg);
private:
    Logger();
    Logger(const Logger& _other) = delete;
    void operator= (const Logger& _other) = delete;
};



#endif // LOGGER_H
