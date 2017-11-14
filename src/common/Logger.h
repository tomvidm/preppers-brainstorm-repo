#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>


#include "ValueField.h"
#include "DebugLine.h"

namespace common {

    class Logger
    {
    public:
        static Logger* getInstancePtr();
        void log(const std::string& string, LogLevel logLevel = defaultLogLevel);
        void log(const std::vector<ValueField>& valueFields, LogLevel logLevel = defaultLogLevel);
        void log(const common::DebugLine& debugLine);
        void setLogLevel(const LogLevel& logLevel);
    protected:
        Logger();
        //Logger(const Logger& copy);
        ~Logger();
    private:
        void print(const DebugLine& line) const;
        int minLogLevel = 0;
        static Logger* instancePtr;
    };
}

#endif