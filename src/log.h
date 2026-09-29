#include <iostream>
#include <fstream>
#include <chrono>
#include <format>

#include "const.h"

#ifndef _LOG_H_
#define _LOG_H_

class Log{

private:
    std::ofstream log_file;

public:

    Log(){
        log_file.open(PATH_TO_LOG);
    }
    ~Log(){
        log_file.close();
    }

    void write(const char* message) {

        auto now = std::chrono::system_clock::now();
        std::string formatted_time = std::format("{0:%F_%T}", now);
        log_file << formatted_time << ": " << message << std::endl;

    }
};

#endif