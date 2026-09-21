#pragma once

#include <cstdint>
#include <filesystem>

namespace treescan {

struct ScanStats {
    std::uint64_t files = 0;
    std::uint64_t directories = 0;
    std::uintmax_t totalSize = 0;
};

class Scanner {
public:
    ScanStats scan(const std::filesystem::path& path) const;
};

}
