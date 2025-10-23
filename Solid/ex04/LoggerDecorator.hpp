#ifndef LOGGERDECORATOR_HPP
#define LOGGERDECORATOR_HPP

#include "ILogger.hpp"

class LoggerDecorator : public ILogger
{
protected:
    ILogger *_wrappedLogger;

public:
    LoggerDecorator(ILogger *logger) : _wrappedLogger(logger) {}

    virtual ~LoggerDecorator() {}

    virtual void write(std::string const &message)
    {
        _wrappedLogger->write(message);
    }
};

#endif