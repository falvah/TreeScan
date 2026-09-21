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
        const treescan::ScanResult result = scanner.scan(path);

        std::cout << "Scanning: " << path << "\n\n";

        std::cout << "Files:       "
                  << result.stats.files << '\n';

        std::cout << "Directories: "
                  << result.stats.directories << '\n';

        std::cout << "Total size:  "
                  << result.stats.totalSize
                  << " bytes\n";

        std::cout << "\nFiles:\n";

        for (const auto& file : result.files) {
            std::cout
                << file.name
                << " | "
                << file.extension
                << " | "
                << file.size
                << " bytes\n";
        }
    }
    catch (const std::exception& error) {
        std::cerr << "Error: "
                  << error.what()
                  << '\n';

        return 1;
    }

    return 0;
}
