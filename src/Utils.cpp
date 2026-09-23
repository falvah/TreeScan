#include "treescan/Utils.hpp"

#include <iomanip>
#include <sstream>

namespace treescan {

std::string formatSize(std::uintmax_t bytes) {
    const char* units[] = {
        "B",
        "KB",
        "MB",
        "GB",
        "TB"
    };

    double size = static_cast<double>(bytes);
    int unit = 0;

    while (size >= 1024.0 && unit < 4) {
        size /= 1024.0;
        ++unit;
    }

    std::ostringstream output;

    output << std::fixed
           << std::setprecision(2)
           << size
           << ' '
           << units[unit];

    return output.str();
}

}
