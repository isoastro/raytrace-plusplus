#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include <array>

template <typename T, size_t DIM>
struct Vec : public std::array<T, DIM> {
    T dot(const Vec<T, DIM> & rhs) {
        T retval = T();
        for (size_t i = 0; i < DIM; i++) {
            retval += this->operator[](i) * rhs[i];
        }
        return retval;
    }

    Vec<T, DIM> operator+=(const Vec<T, DIM> & rhs) {
        for (size_t i = 0; i < DIM; i++) {
            this->operator[](i) += rhs[i];
        }
        return *this;
    }

    friend Vec<T, DIM> operator+(Vec<T, DIM> lhs, const Vec<T, DIM> & rhs) {
        lhs += rhs;
        return lhs;
    }

    Vec<T, DIM> operator-=(const Vec<T, DIM> & rhs) {
        for (size_t i = 0; i < DIM; i++) {
            this->operator[](i) -= rhs[i];
        }
        return *this;
    }

    friend Vec<T, DIM> operator-(Vec<T, DIM> lhs, const Vec<T, DIM> & rhs) {
        lhs -= rhs;
        return lhs;
    }
};

using Vec3f = Vec<float, 3>;

struct Sphere {
    Vec3f center;
    float radius;

    Sphere(const Vec3f & c, float r) : center(c), radius(r) {}
    bool intersect(const Vec3f & origin, const Vec3f & direction, float * t0) const;
};

#endif // _GEOMETRY_H_
