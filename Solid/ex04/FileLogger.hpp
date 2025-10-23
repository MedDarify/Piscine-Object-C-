#ifndef FILELOGGER_HPP
#define FILELOGGER_HPP

#include "ILogger.hpp"
#include <fstream>
#include <string>
#include <iostream>

class FileLogger : public ILogger
{
private:
    std::ofstream _file;
    std::string _filename;

public:
    FileLogger(std::string const &filename) : _filename(filename)
    {
        _file.open(_filename.c_str(), std::ios::out | std::ios::app);
        if (!_file.is_open())
            std::cerr << "Error: Could not open log file " << _filename << std::endl;
    }

    virtual ~FileLogger()
    {
        if (_file.is_open())
            _file.close();
    }

    virtual void write(std::string const &message)
    {
        if (_file.is_open())
            _file << message << std::endl;
    }
};

#endif