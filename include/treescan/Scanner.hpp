#pragma once

#include "treescan/FileInfo.hpp"

#include <cstdint>
#include <filesystem>
#include <vector>

namespace treescan {

struct ScanStats {
    std::uint64_t files = 0;
    std::uint64_t directories = 0;
    std::uintmax_t totalSize = 0;
};

struct ScanResult {
    ScanStats stats;
    std::vector<FileInfo> files;
};

class Scanner {
public:
    ScanResult scan(const std::filesystem::path& path) const;
};

}
