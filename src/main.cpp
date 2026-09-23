#include "treescan/Scanner.hpp"
#include "treescan/Utils.hpp"

#include <algorithm>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc != 2 && argc != 4) {
        std::cerr
            << "Usage:\n"
            << "  treescan <directory>\n"
            << "  treescan <directory> --largest <count>\n";

        return 1;
    }

    const std::filesystem::path path = argv[1];

    bool showLargest = false;
    std::size_t largestCount = 0;

    if (argc == 4) {
        const std::string option = argv[2];

        if (option != "--largest") {
            std::cerr << "Unknown option: " << option << '\n';
            return 1;
        }

        try {
            largestCount = std::stoull(argv[3]);
        }
        catch (const std::exception&) {
            std::cerr << "Invalid number: " << argv[3] << '\n';
            return 1;
        }

        if (largestCount == 0) {
            std::cerr << "Count must be greater than 0\n";
            return 1;
        }

        showLargest = true;
    }

    treescan::Scanner scanner;

    try {
        const treescan::ScanResult result = scanner.scan(path);

        std::cout << "Scanning: " << path << "\n\n";

        std::cout
            << "Files:       "
            << result.stats.files
            << '\n';

        std::cout
            << "Directories: "
            << result.stats.directories
            << '\n';

        std::cout
            << "Total size:  "
            << treescan::formatSize(result.stats.totalSize)
            << '\n';

        if (showLargest) {
            std::vector<treescan::FileInfo> files = result.files;

            std::sort(
                files.begin(),
                files.end(),
                [](const treescan::FileInfo& first,
                   const treescan::FileInfo& second) {
                    return first.size > second.size;
                }
            );

            const std::size_t count =
                std::min(largestCount, files.size());

            std::cout << "\nLargest files:\n\n";

            for (std::size_t i = 0; i < count; ++i) {
                const auto& file = files[i];

                std::cout
                    << i + 1
                    << ". "
                    << file.name
                    << " | "
                    << treescan::formatSize(file.size)
                    << '\n';

                std::cout
                    << "   "
                    << file.path
                    << '\n';
            }
        }
    }
    catch (const std::exception& error) {
        std::cerr
            << "Error: "
            << error.what()
            << '\n';

        return 1;
    }

    return 0;
}

