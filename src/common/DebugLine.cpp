#include "DebugLine.h"

namespace common {
    std::string logLevelToString(LogLevel logLevel)
    {
        switch(logLevel)
        {
            case LOG_VERBOSE:
                return "VERBOSE\t- ";
            case LOG_DEBUG:
                return "DEBUG\t- ";
            case LOG_WARNING:
                return "WARNING\t- ";
            case LOG_ERROR:
                return "ERROR\t- ";
            case LOG_FATAL:
                return "FATAL\t- ";
            default:
                return "log!?!?\t- ";
        }
    }

    DebugLine::DebugLine(LogLevel logLevel)
    {
        logLevel_ = logLevel;
    }

    DebugLine::DebugLine(std::string str, LogLevel logLevel)
    {
        logLevel_ = logLevel;
        fields.push_back(ValueField(str));
    }

    void DebugLine::clear()
    {
        fields.clear();
    }

    void DebugLine::set(std::string str)
    {
        fields.push_back(ValueField(str));
    }

    void DebugLine::addField(ValueField& field)
    {
        fields.push_back(field);
    }

    std::string DebugLine::get() const 
    {
        std::string result = logLevelToString(logLevel_);
        for (auto v : fields)
        {
            result = result + v.get();
        }
        return result;
    }

    LogLevel DebugLine::getLogLevel() const
    {
        return logLevel_;
    }
}