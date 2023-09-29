#include <iostream>

#include "utils.hpp"
#include "parsing.hpp"
#include <ctime>

int main(int argc, char *argv[]) {
    log_info("starting tpy");
    
    if (parse_args(argc, argv)) {
        usage();
        error("error parsing args");
    }

    std::string src  = argv[1];
    std::string dest = argv[2];

    std::list<std::string> file_lines = parse_file(src);

    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);

    for (const auto& str : file_lines) {
        std::cout << str << std::endl;
    }

    ofstream output(dest + ".cpp", std::ios::out | std::ios::trunc);

    if (!output.is_open()) {
        error("error opening output file");
    }

    log_info("writing transpiled code to file " + dest + ".cpp");
    
    output << "#include <iostream>\nint main(int argc, char *argv[]){\n" << "\tprintf(\"slime\\n\");" << "\n}" << std::endl;

    output.close();

    log_info("writed transpiled code to file" + dest + ".cpp");

    log_info("compiling transpiled code to executable " + dest);

    int _error = system("g++ test/test.cpp -o test/test");

    if (_error) {
        error("error compiling transpiled code");
    }

    log_info("compiled transpiled code to executable " + dest);

    exit_success();
}