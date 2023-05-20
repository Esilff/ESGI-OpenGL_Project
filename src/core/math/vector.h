#ifndef VECTOR_H
#define VECTOR_H

struct Vector {
    float x, y, z;

    Vector();
    Vector(float x, float y, float z);

    Vector& operator=(const Vector& vector);

    Vector& operator+=(const Vector& rhs);

    Vector& operator-=(const Vector& rhs);

    Vector& operator*=(const Vector& rhs);

    Vector operator+(const Vector& rhs) const;

    Vector operator-(const Vector& rhs) const;

    Vector operator*(const Vector& rhs) const;
};


#endif //VECTOR_H
