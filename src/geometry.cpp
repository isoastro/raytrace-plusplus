#include <cmath>
#include "geometry.h"

bool Sphere::intersect(const Vec3f & origin, const Vec3f & direction, float *t0) const {
    auto L = center - origin;
    float tca = L.dot(direction);
    float d2 = L.dot(L) - tca * tca;
    if (d2 > radius * radius) {
        return false;
    }
    float thc = std::sqrt(radius * radius - d2);
    *t0 = tca - thc;
    float t1 = tca + thc;
    if (*t0 < 0) {
        *t0 = t1;
    }
    if (*t0 < 0) {
        return false;
    }
    return true;
}