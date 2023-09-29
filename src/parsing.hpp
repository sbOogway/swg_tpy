#ifndef PARSING_H
#define PARSING_H

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <unordered_map>

#define ASSIGNMENT      "="
#define TYPE_ASSIGNMENT ":"
#define TAB             "   "

using std::list, std::string, std::ifstream, std::ofstream, std::getline;

int parse_args(int argc, char *argv[]);
list<string> parse_file(string file_path);
string parse_line(string line);
int base_assignment(string line, string _char);
int is_assignment(string line);
string parse_assignment(string line);
int is_type_assignment(string line);
string parse_type_assignment(string line);
int is_function_declaration(string line);
int is_std_function(string line);


#endif // PARSING_H
