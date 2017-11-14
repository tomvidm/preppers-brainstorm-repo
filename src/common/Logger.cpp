#include "Logger.h"

namespace common {
    Logger* Logger::instancePtr = nullptr;

    Logger* Logger::getInstancePtr()
    {
        if (instancePtr == nullptr)
        {
            instancePtr = new Logger;
            instancePtr->log("Logger initialized...\n", LOG_DEBUG);
        }

        return instancePtr;
    }

    void Logger::log(const std::string& string, LogLevel logLevel)
    {
        if (static_cast<int>(logLevel) >= minLogLevel)
        {
            DebugLine debugLine(string, logLevel);
            std::cout << debugLine.get();
        }
    }

    void Logger::log(const std::vector<ValueField>& valueFields, LogLevel logLevel)
    {
        if (static_cast<int>(logLevel) >= minLogLevel)
        {
            DebugLine debugLine(logLevel);
            for (auto v : valueFields)
            {
                debugLine.addField(v);
            }
            std::cout << debugLine.get();
        }
    }

    void Logger::log(const common::DebugLine& debugLine)
    {
        if (static_cast<int>(debugLine.getLogLevel()) >= minLogLevel)
        {
            std::cout << debugLine.get();
        }
    }

    void Logger::print(const DebugLine& line) const
    {
        
    }

    void Logger::setLogLevel(const LogLevel& logLevel)
    {
        minLogLevel = static_cast<int>(logLevel);
    }

    Logger::Logger()
    {
        ;
    }

    Logger::~Logger()
    {
        delete instancePtr;
    }
}