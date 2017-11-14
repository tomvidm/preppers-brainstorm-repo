#ifndef DEBUGLINE_H
#define DEBUGLINE_H

#include <vector>
#include <string>

#include "ValueField.h"

namespace common {
    typedef unsigned int uint;

    enum LogLevel
    {
        LOG_VERBOSE = 0,
        LOG_DEBUG = 1,
        LOG_WARNING = 2,
        LOG_ERROR = 3,
        LOG_FATAL = 4
    };

    const LogLevel defaultLogLevel = LogLevel::LOG_VERBOSE;

    std::string logLevelToString(LogLevel logLevel);

    class DebugLine
    {
    public:
        DebugLine(LogLevel logLevel = defaultLogLevel);
        DebugLine(std::string str, LogLevel logLevel = defaultLogLevel);

        void clear();
        virtual void set(std::string str);
        virtual void addField(ValueField &field);
        virtual std::string get() const;
        LogLevel getLogLevel() const;
    protected:    
        LogLevel logLevel_;
        uint timestamp_;
        std::vector<ValueField> fields;
    };
}

#endif