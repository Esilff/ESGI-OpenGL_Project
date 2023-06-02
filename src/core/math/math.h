#ifndef MATH_H
#define MATH_H

#include <iostream>
#include <cmath>

struct Vector2;

struct Transform;

struct Vector {
    float x, y, z;

    Vector();
    Vector(float _x, float _y, float _z = 0);

    Vector operator*(const float& s) const;
    friend Vector operator*(float s, const Vector& v) {
        return v * s;
    }
    Vector operator/(const float& s) const;
    friend Vector operator/(float s, const Vector& v) {
        return v / s;
    }
    Vector operator+(const Vector& v) const;
    Vector operator-(const Vector& v) const;
    Vector operator-() const;

    void operator*=(const float& s);
    void operator/=(const float& s);
    void operator+=(const Vector& v);
    void operator-=(const Vector& v);

    float magnitude() const;
    Vector normalize() const;

    operator Vector2() const;

    static Vector cross(const Vector& u, const Vector& v);
    static float dot(const Vector& u, const Vector& v);
    static float angle(const Vector& u, const Vector& v);

    friend std::ostream& operator<<(std::ostream& os, const Vector& v)
    {
        os << '(' << v.x << ", " << v.y << ", " << v.z << ')';
        return os;
    }
};

struct Vector2 {
    float x, y;

    Vector2();
    Vector2(float _x, float _y);

    Vector2 operator*(const float& s) const;
    friend Vector2 operator*(float s, const Vector2& v) {
        return v * s;
    }
    Vector2 operator/(const float& s) const;
    friend Vector2 operator/(float s, const Vector2& v) {
        return v / s;
    }
    Vector2 operator+(const Vector2& v) const;
    Vector2 operator-(const Vector2& v) const;
    Vector2 operator-() const;

    void operator*=(const float& s);
    void operator/=(const float& s);
    void operator+=(const Vector2& v);
    void operator-=(const Vector2& v);

    float magnitude() const;
    Vector2 normalize() const;

    operator Vector() const;

    static float dot(const Vector2& u, const Vector2& v);
    static float angle(const Vector2& u, const Vector2& v);

    friend std::ostream& operator<<(std::ostream& os, const Vector2& v)
    {
        os << '(' << v.x << ", " << v.y << ')';
        return os;
    }
};

struct Quaternion {
    float x, y, z, w;

    Quaternion();
    Quaternion(float _w, float _x, float _y, float _z);

    Quaternion operator-() const;
    Quaternion operator*(const Quaternion& q) const;
    Vector operator*(const Vector& v) const;

    void operator*=(const Quaternion& q);

    float magnitude() const;
    Quaternion normalize() const;
    Vector toEuler() const;


    static Quaternion euler(const Vector& euler);
    static Quaternion euler(float x, float y, float z);
    static Quaternion matrixToQuaternion(const float* matrix);

    friend std::ostream& operator<<(std::ostream& os, const Quaternion& v)
    {
        os << '(' << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ')';
        return os;
    }
};

struct Matrix {
    float* matrix;

    void operator+(const Matrix& matrix);
    void operator-(const Matrix& matrix);
    void operator/(const Matrix& matrix);
    void operator*(float constant);
    Matrix operator*(const Matrix& mat);

    static float* quaternionToMatrix(const Quaternion& quat) {
        float *matrix = new float[16];


        float x = quat.x;
        float y = quat.y;
        float z = quat.z;
        float w = quat.w;

        matrix[0] = 1 - 2 * (y * y + z * z);
        matrix[1] = 2 * (x * y - w * z);
        matrix[2] = 2 * (x * z + w * y);
        matrix[3] = 0;

        matrix[4] = 2 * (x * y + w * z);
        matrix[5] = 1 - 2 * (x * x + z * z);
        matrix[6] = 2 * (y * z - w * x);
        matrix[7] = 0;

        matrix[8] = 2 * (x * z - w * y);
        matrix[9] = 2 * (y * z + w * x);
        matrix[10] = 1 - 2 * (x * x + y * y);
        matrix[11] = 0;

        matrix[12] = 0;
        matrix[13] = 0;
        matrix[14] = 0;
        matrix[15] = 1;

        return matrix;
    }



    static float* identity() {
        float* matrix = new float[16];
        for (int i = 0; i < 16; i++) {
            matrix[i] = 0;
        }
        matrix[0] = 1;
        matrix[5] = 1;
        matrix[10] = 1;
        matrix[15] = 1;
        return matrix;
    }

public:
    static float* projectionMatrix(float fov, float aspectRatio, float nearPlane, float farPlane) {
        float* matrix = new float[16];

        float tanHalfFov = std::tan(fov/2.0f);
        float frustumLength = farPlane - nearPlane;

        // Calculate the matrix components
        matrix[0] = 1.0f / (aspectRatio * tanHalfFov);
        matrix[1] = 0.0f;
        matrix[2] = 0.0f;
        matrix[3] = 0.0f;

        matrix[4] = 0.0f;
        matrix[5] = 1.0f / tanHalfFov;
        matrix[6] = 0.0f;
        matrix[7] = 0.0f;

        matrix[8] = 0.0f;
        matrix[9] = 0.0f;
        matrix[10] = -(farPlane + nearPlane) / frustumLength;
        matrix[11] = -1.0f;

        matrix[12] = 0.0f;
        matrix[13] = 0.0f;
        matrix[14] = -(2.0f * farPlane * nearPlane) / frustumLength;
        matrix[15] = 0.0f;

        return matrix;
    }

    static float* viewMatrix(const Vector& position, const Vector& target, const Vector& up) {
        Vector forward = (target - position).normalize();
        Vector right = Vector::cross(up, forward).normalize();
        Vector newUp = Vector::cross(forward, right).normalize();

        float* viewMatrix = new float[16];

        viewMatrix[0] = right.x;
        viewMatrix[4] = right.y;
        viewMatrix[8] = right.z;
        viewMatrix[12] = -Vector::dot(right, position);

        viewMatrix[1] = newUp.x;
        viewMatrix[5] = newUp.y;
        viewMatrix[9] = newUp.z;
        viewMatrix[13] = -Vector::dot(newUp, position);

        viewMatrix[2] = -forward.x;
        viewMatrix[6] = -forward.y;
        viewMatrix[10] = -forward.z;
        viewMatrix[14] = Vector::dot(forward, position);

        viewMatrix[3] = 0.0f;
        viewMatrix[7] = 0.0f;
        viewMatrix[11] = 0.0f;
        viewMatrix[15] = 1.0f;

        return viewMatrix;
    }

    static float* modelMatrix(float* translation, float* rotation, float* scale) {
        Matrix translate;
        translate.matrix = translation;
        Matrix rotate;
        rotate.matrix = rotation;
        Matrix scaling;
        scaling.matrix = scale;
        Matrix model = translate * rotate;
        return model.matrix;
    }
    Matrix();

};

#endif