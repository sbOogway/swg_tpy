#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <algorithm>
#include <string>
#include <sstream>

std::string base_wrap(std::string content, std::string begin, std::string end);
std::string get_current_time();
void base_log(std::string level, std::string msg, std::string color, int std_err);
void log_info(std::string msg);
void log_err(std::string msg);
void error(std::string msg);
void exit_success();
void usage();

#endif // UTILS_H
