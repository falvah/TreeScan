#pragma once

#include <cstdint>
#include <filesystem>
#include <string>

namespace treescan {

struct FileInfo {
    std::filesystem::path path;
    std::string name;
    std::string extension;
    std::uintmax_t size = 0;
};

}
