#include "utils.hpp"

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

static string _usage = "usage:\n    tpy <src.py> <output>\n";

string base_wrap(string content, string begin, string end) {
    return begin + content + end;    
}

string get_current_time() {
    auto current_time_point = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(current_time_point);
    struct std::tm *time_info = std::localtime(&current_time);
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(
        current_time_point.time_since_epoch()
    ).count() % 1000;
    std::ostringstream oss;
    oss << std::put_time(time_info, "%Y-%m-%d %H:%M:%S.") << std::setfill('0') << std::setw(3) << milliseconds;
    return oss.str();
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

void usage() {
    log_err(_usage);
}

void error(string msg) {
    log_err(msg);
    exit(EXIT_FAILURE);
}

void exit_success() {
    log_info("exiting tpy succesfully");
    exit(EXIT_SUCCESS);
}