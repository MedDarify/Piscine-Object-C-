#ifndef DATEHEADERDECORATOR_HPP
#define DATEHEADERDECORATOR_HPP

#include "LoggerDecorator.hpp"
#include <string>
#include <ctime> // For time()

class DateHeaderDecorator : public LoggerDecorator
{
public:
    DateHeaderDecorator(ILogger *logger) : LoggerDecorator(logger) {}
    virtual ~DateHeaderDecorator() {}

    std::string getCurrentDate()
    {
        std::time_t now = std::time(0);
        char buffer[80];
        std::strftime(buffer, 80, "[%Y-%m-%d %H:%M:%S] ", std::localtime(&now));
        return std::string(buffer);
    }

    virtual void write(std::string const &message)
    {
        std::string fullMessage = getCurrentDate() + message;
        _wrappedLogger->write(fullMessage);
    }
};

#endif