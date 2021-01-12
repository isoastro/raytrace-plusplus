#include <fstream>
#include "ppm.h"

size_t xyToIdx(size_t x, size_t y, size_t width) {
    return y * width + x;
}

// TODO: Make this take other input types for `pixels`
void ppmWrite(const std::vector<Vec3f> & pixels, size_t width, size_t height, const std::string & filename) {
    if (pixels.size() != width * height) {
        return;
    }

    std::ofstream o(filename);
    if (!o.is_open()) {
        return;
    }

    // PPM files start with a magic string and some whitespace
    o << PPM_MAGIC_STRING << "\n";

    // Dump the width and height (as ASCII), plus some whitespace
    o << width << "\t";
    o << height << "\t";

    // Maximum color value
    o << MAX_COLOR_VALUE << "\n";

    // Raster of <height> rows, each of <width> RGB triplets
    for (const auto & pixel : pixels) {
        for (const auto & color : pixel) {
            // Convert float to [0, MAX]
            auto clamped = std::max(0.0f, std::min(1.0f, color));
            o << static_cast<unsigned char>(MAX_COLOR_VALUE * clamped);
        }
    }

    o.close();
}


