#ifndef STREAMLOGGER_HPP
#define STREAMLOGGER_HPP

#include "ILogger.hpp"
#include <iostream>

class StreamLogger : public ILogger
{
private:
    std::ostream &_stream;

public:
    StreamLogger(std::ostream &stream) : _stream(stream) {}
    virtual ~StreamLogger() {}

    virtual void write(std::string const &message)
    {
        _stream << message << std::endl;
    }
};

#endif