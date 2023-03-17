#include "vrpathreg.h"

#include <iostream>

int AddExternalDriver(const std::string &driver_path) {
    if (!RegisterDriverWithRuntime(driver_path)) {
        return -1;
    }

    return 0;
}

int RemoveExternalDriver(const std::string &driver_path) {
    if (!RemoveDriverFromRuntime(driver_path)) {
        return -1;
    }

    return 0;
}

void PrintHelp() {
    std::cout << "Commands:" << std::endl;
    std::cout << "adddriver \"<path>\" - Adds an external driver. Ensure path in quotes" << std::endl;
    std::cout << "removedriver \"<path>\" - Removes an external driver. Ensure path in quotes" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        PrintHelp();

        return -2;
    }

    const std::string command = argv[1];

    if (command == "adddriver") {
        if (argc != 3) {
            return -2;
        }

        return AddExternalDriver(argv[2]);
    } else if (command == "removedriver") {
        if (argc != 3) {
            return -2;
        }

        return RemoveExternalDriver(argv[2]);
    } else {
        PrintHelp();
    }

    return 0;
}
