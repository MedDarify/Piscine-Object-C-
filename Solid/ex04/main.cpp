#include "ILogger.hpp"
#include "StreamLogger.hpp"
#include "FileLogger.hpp"
#include "ConstantHeaderDecorator.hpp"
#include "DateHeaderDecorator.hpp"

#include <iostream>
#include <vector>
#include <string>

int main() {
    StreamLogger consoleLogger(std::cout);
    FileLogger   fileLogger("app.log");


    ConstantHeaderDecorator consoleWarning(&consoleLogger, "[WARNING]: ");
    DateHeaderDecorator     fileLoggerWithDate(&fileLogger);
    DateHeaderDecorator     consoleLoggerWithDate(&consoleLogger);

    std::vector<std::string> messages;
    messages.push_back("Application started.");
    messages.push_back("User performed an action.");
    messages.push_back("An error occurred.");
    messages.push_back("Application shutting down.");

    std::vector<ILogger*> loggers;
    loggers.push_back(&consoleLogger);        
    loggers.push_back(&fileLoggerWithDate);    
    loggers.push_back(&consoleWarning);       
    loggers.push_back(&consoleLoggerWithDate); 

    for (size_t i = 0; i < messages.size(); ++i) {
        std::cout << "\n--- Logging message: '" << messages[i] << "' ---" << std::endl;
        for (size_t j = 0; j < loggers.size(); ++j) {
            loggers[j]->write(messages[i]);
        }
    }
    return 0;
}