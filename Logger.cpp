#include "Logger.h"

using namespace std;

Logger* Logger::m_instance = nullptr;
std::fstream Logger::outFile = fstream();

Logger::Logger()
{
    outFile.open(LOG_FILE, ios::out | ios::app);
}

Logger::~Logger()
{
    if (nullptr != m_instance)
    {
        delete m_instance;
    }
    m_instance = nullptr;
    outFile.close();
}

Logger* Logger::instance()
{
    if (nullptr == m_instance)
    {
        m_instance = new Logger();
    }
    return m_instance;
}

std::fstream& Logger::output()
{
    return outFile;
}

void Logger::writeLog(const std::string& msg)
{
    outFile << "[Logger]" << msg;
}
