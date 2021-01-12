#include "catch2/catch.hpp"
#include "geometry.h"
#include "ppm.h"

TEST_CASE("Make gradient", "[ppm]") {
    const size_t width = 1024;
    const size_t height = 768;

    std::vector<Vec3f> pixels(width * height);
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            auto idx = xyToIdx(j, i, width);
            Vec3f pixel = {
                static_cast<float>(i) / static_cast<float>(height),
                static_cast<float>(j) / static_cast<float>(width),
                0.0f
            };
            pixels[idx] = pixel;
        }
    }

    ppmWrite(pixels, width, height, "gradient.ppm");
    REQUIRE(1 == 1); // Needs human interaction to verify
}