#include "treescan/Scanner.hpp"

#include <filesystem>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: treescan <directory>\n";
        return 1;
    }

    const std::filesystem::path path = argv[1];

    treescan::Scanner scanner;

    try {
        const treescan::ScanStats stats = scanner.scan(path);

        std::cout << "Scanning: " << path << "\n\n";

        std::cout << "Files:       "
                  << stats.files << '\n';

        std::cout << "Directories: "
                  << stats.directories << '\n';

        std::cout << "Total size:  "
                  << stats.totalSize
                  << " bytes\n";
    }
    catch (const std::exception& error) {
        std::cerr << "Error: "
                  << error.what()
                  << '\n';

        return 1;
    }

    return 0;
}
