#include <iostream>

#include "utils.cpp"

int main(int argc, char *argv[]) {
    log_info("starting tpy");
    
    if (argc != 4) {
        error("incorrect usagea");
    }

    exit_success();
}