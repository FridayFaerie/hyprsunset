#pragma once

#include <format>
#include <fstream>
#include <string>
#include <iostream>

enum LogLevel {
    NONE = -1,
    LOG  = 0,
    WARN,
    ERR,
    CRIT,
    INFO,
    TRACE
};

namespace Debug {
    inline bool trace = false;

    template <typename... Args>
    void log(LogLevel level, std::format_string<Args...> fmt, Args&&... args) {
        if (!trace && (level == LOG || level == INFO))
            return;

        switch (level) {
            case NONE: break;
            case LOG: std::cout << "[LOG] "; break;
            case WARN: std::cout << "[WARN] "; break;
            case ERR: std::cout << "[ERR] "; break;
            case CRIT: std::cout << "[CRIT] "; break;
            case INFO: std::cout << "[INFO] "; break;
            case TRACE: std::cout << "[TRACE] "; break;
        }

        std::cout << std::vformat(fmt.get(), std::make_format_args(args...)) << std::endl; // flush cuz systemd etc
    }
}; // namespace Debug
