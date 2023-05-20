#include "vector.h"

Vector::Vector() : x(0), y(0), z(0) {}

Vector::Vector(float x, float y, float z) : x(x), y(y), z(z) {}

Vector& Vector::operator=(const Vector& vector) {
    if (this != &vector) {
        x = vector.x;
        y = vector.y;
        z = vector.z;
    }
    return *this;
}

Vector& Vector::operator+=(const Vector& rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}

Vector& Vector::operator*=(const Vector& rhs) {
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    return *this;
}

Vector Vector::operator+(const Vector& rhs) const {
    return Vector(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector Vector::operator-(const Vector& rhs) const {
    return Vector(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vector Vector::operator*(const Vector& rhs) const {
    return Vector(x * rhs.x, y * rhs.y, z * rhs.z);
}

