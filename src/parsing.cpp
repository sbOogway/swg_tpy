#include "parsing.hpp"
#include "utils.hpp"

using string_map = std::unordered_map<string, string>;

string_map type_convs = {
    {"str", "std::string"},
    {"list", "std::list"}

};

struct type_assignment {
    string variable_name;
    string variable_type;
    void  *variable_content;
};

int parse_args(int argc, char *argv[]) {
    if (argc != 3) {
        return 1;
    }
    return 0;
}

list<string> parse_file(string file_path) {
    ifstream file(file_path);
    if (!file.is_open()) {
        error("error opening file");
    }
    list<string> lines;
    string line;

    while(getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    return lines;
}

int base_assignment(string line, string _char) {
    size_t found = line.find(_char);
    return found != std::string::npos;
}

int is_assignment(string line) {    
    return base_assignment(line, ASSIGNMENT);
}

string parse_assignment(string line) {
    type_assignment _line; 

}

int is_type_assignment(string line) {
    return base_assignment(line, TYPE_ASSIGNMENT);
}

string parse_type_assignment(string line) {


}

int is_function_declaration(string line) {

}

int is_std_function(string line) {
    
}

string parse_line(string line) {
    if (is_assignment(line)) {
        if (is_type_assignment(line)) {
            string parsed_line = parse_type_assignment(line);

        }

    }

}