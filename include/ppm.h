#ifndef _PPM_H_
#define _PPM_H_

#include <vector>
#include <string>
#include "geometry.h"

#define PPM_MAGIC_STRING "P6"
#define MAX_COLOR_VALUE 255

size_t xyToIdx(size_t x, size_t y, size_t width);

void ppmWrite(const std::vector<Vec3f> & pixels, size_t width, size_t height, const std::string & filename);

#endif // _PPM_H_
