#include "treescan/Scanner.hpp"

#include <stdexcept>
#include <system_error>

namespace treescan {

ScanStats Scanner::scan(const std::filesystem::path& path) const {
    if (!std::filesystem::exists(path)) {
        throw std::runtime_error("Path does not exist");
    }

    if (!std::filesystem::is_directory(path)) {
        throw std::runtime_error("Path is not a directory");
    }

    ScanStats stats;

    const auto options =
        std::filesystem::directory_options::skip_permission_denied;

    for (const auto& entry :
         std::filesystem::recursive_directory_iterator(path, options)) {

        std::error_code error;

        if (entry.is_directory(error)) {
            ++stats.directories;
            continue;
        }

        if (entry.is_regular_file(error)) {
            ++stats.files;

            const auto size = entry.file_size(error);

            if (!error) {
                stats.totalSize += size;
            }
        }
    }

    return stats;
}

}
