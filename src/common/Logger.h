#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>


#include "ValueField.h"
#include "DebugLine.h"

/*
    Forget about std::cout!
    Meet the logger, which lets you hide std::cout behind an interface that
    also lets you say "log("some message", LogLevel::LOG_DEBUG)" and control whether
    or not it is shown depending on the log level.

    This class is a singleton and should always be accessed through the static
    method getInstancePtr().

    common::Logger* logger = common::Logger::getInstancePtr();
    logger->log("Snoop Doggo");
    logger->log({common::ValueField(2), common::ValueField(" bad 4 skool")});
*/

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