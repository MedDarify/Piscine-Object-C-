#ifndef CONSTANTHEADERDECORATOR_HPP
#define CONSTANTHEADERDECORATOR_HPP

#include "LoggerDecorator.hpp"
#include <string>

class ConstantHeaderDecorator : public LoggerDecorator
{
private:
    std::string _header;

public:
    ConstantHeaderDecorator(ILogger *logger, std::string const &header)
        : LoggerDecorator(logger), _header(header) {}

    virtual ~ConstantHeaderDecorator() {}

    virtual void write(std::string const &message)
    {
        std::string fullMessage = _header + message;
        _wrappedLogger->write(fullMessage);
    }
};

#endif