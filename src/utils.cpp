#include <iostream>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <string>

#define OPEN_LOG    "["
#define CLOSE_LOG   "]"

#define OPEN_MSG    "-> "
#define CLOSE_MSG   " <-"

#define SPACE       " "

#define RED         "\x1b[31m"
#define GREEN       "\x1b[32m"
#define YELLOW      "\x1b[33m"
#define RESET       "\x1b[0m"

using std::string;

string usage ="usage:\n    tpy <src.py> -o <output>\n";

string base_wrap(string content, string begin, string end) {
    return begin + content + end;    
}

string get_current_time() {
    auto now = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(now);
    string result = string(std::ctime(&current_time));
    return  result.erase(result.size()-1);
}

void base_log(string level, string msg, string color, int std_err) {
    string log = OPEN_LOG + base_wrap(get_current_time(), YELLOW, RESET) + CLOSE_LOG + SPACE +
    base_wrap(level, OPEN_LOG + color, RESET) + CLOSE_LOG + SPACE +
    base_wrap(msg, OPEN_MSG, CLOSE_MSG);
    if (std_err) {
        std::cerr << log << std::endl;
        return;
    }
    std::cout <<  log << std::endl;
}

void log_info(string msg) {
    base_log("INFO", msg, GREEN, 0);
}

void log_err(string msg) {
    base_log("ERRR", msg, RED, 1);
}

void error(string msg) {
    log_err(msg);
    std::cerr << usage << std::endl;
    exit(EXIT_FAILURE);
}

void exit_success() {
    log_info("exiting tpy succesfully");
    exit(EXIT_SUCCESS);
}