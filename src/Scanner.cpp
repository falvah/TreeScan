#include "treescan/Scanner.hpp"

#include <stdexcept>
#include <system_error>

namespace treescan {

ScanResult Scanner::scan(const std::filesystem::path& path) const {
    if (!std::filesystem::exists(path)) {
        throw std::runtime_error("Path does not exist");
    }

    if (!std::filesystem::is_directory(path)) {
        throw std::runtime_error("Path is not a directory");
    }

    ScanResult result;

    const auto options =
        std::filesystem::directory_options::skip_permission_denied;

    for (const auto& entry :
         std::filesystem::recursive_directory_iterator(path, options)) {

        std::error_code error;

        if (entry.is_directory(error)) {
            ++result.stats.directories;
            continue;
        }

        if (!entry.is_regular_file(error)) {
            continue;
        }

        const auto size = entry.file_size(error);

        if (error) {
            continue;
        }

        FileInfo file;

        file.path = entry.path();
        file.name = entry.path().filename().string();
        file.extension = entry.path().extension().string();
        file.size = size;

        result.files.push_back(file);

        ++result.stats.files;
        result.stats.totalSize += size;
    }

    return result;
}

}
