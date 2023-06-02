#include "math.h"
#include <cmath>
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433057270365759591953092186117381932611793105118548074462379962749567351885752724891227938183011949129833673362440656643086021394946395224737190702179860943702770539217176293176752384674818467669405132000568127145263560827785771342757789609173637178721468440901224953430146549585371050792279689258923542019956112129021960864034418159813629774771309960518707211349999998372978049951059731732816096318595024459455346908302642522308253344685035261931188171010003137838752886587533208381420617177669147303598253490428755468731159562863882353787593751957781857780532171226806613001927876611195909216420198938095257201065485863278865936153381827968230301952035301852968995773622599413891249721775283479131515574857242454150695950829533116861727855889075098381754637464939319255060400927701671139009848824012858361603563707660104710181942955596198946767837449448255379774726847104047534646208046684259069491293313677028989

Vector::Vector() : x(0), y(0), z(0) {}

Vector::Vector(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

Vector Vector::operator*(const float& s) const {
    return {x * s, y * s, z * s};
}

Vector Vector::operator/(const float& s) const {
    return {x / s, y / s, z / s};
}

Vector Vector::operator+(const Vector& v) const {
    return {x + v.x, y + v.y, z + v.z};
}

Vector Vector::operator-(const Vector& v) const {
    return {x - v.x, y - v.y, z - v.z};
}

Vector Vector::operator-() const {
    return {-x, -y, -z};
}

void Vector::operator*=(const float& s) {
    (*this) = (*this) * s;
}

void Vector::operator/=(const float& s) {
    (*this) = (*this) / s;
}

void Vector::operator+=(const Vector& v) {
    (*this) = (*this) + v;
}

void Vector::operator-=(const Vector& v) {
    (*this) = (*this) - v;
}

float Vector::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}

Vector Vector::normalize() const {
    return (*this) / magnitude();
}

Vector::operator Vector2() const {
    return {x, y};
}

Vector Vector::cross(const Vector& u, const Vector& v) {
    return {
            u.y * v.z - u.z * v.y,
            u.z * v.x - u.x * v.z,
            u.x * v.y - u.y * v.x
    };
}

float Vector::dot(const Vector& u, const Vector& v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

float Vector::angle(const Vector& u, const Vector& v) {
    return std::acos(std::max(-1.0, std::min((double)dot(u, v) / (u.magnitude() * v.magnitude()), 1.0)));
}

Vector2::Vector2() : x(0), y(0) {}

Vector2::Vector2(float _x, float _y) : x(_x), y(_y) {}

Vector2 Vector2::operator*(const float& s) const {
    return {x * s, y * s};
}

Vector2 Vector2::operator/(const float& s) const {
    return {x / s, y / s};
}

Vector2 Vector2::operator+(const Vector2& v) const {
    return {x + v.x, y + v.y};
}

Vector2 Vector2::operator-(const Vector2& v) const {
    return {x - v.x, y - v.y};
}

Vector2 Vector2::operator-() const {
    return {-x, -y};
}

void Vector2::operator*=(const float& s) {
    (*this) = (*this) * s;
}

void Vector2::operator/=(const float& s) {
    (*this) = (*this) / s;
}

void Vector2::operator+=(const Vector2& v) {
    (*this) = (*this) + v;
}

void Vector2::operator-=(const Vector2& v) {
    (*this) = (*this) - v;
}

float Vector2::magnitude() const {
    return std::sqrt(x * x + y * y);
}

Vector2 Vector2::normalize() const {
    return (*this) / magnitude();
}

Vector2::operator Vector() const {
    return Vector(x, y);
}

float Vector2::dot(const Vector2& u, const Vector2& v) {
    return u.x * v.x + u.y * v.y;
}

float Vector2::angle(const Vector2& u, const Vector2& v) {
    return std::acos(std::max(-1.0, std::min((double)dot(u, v) / (u.magnitude() * v.magnitude()), 1.0)));
}

Quaternion::Quaternion() : w(1), x(0), y(0), z(0) {}

Quaternion::Quaternion(float _w, float _x, float _y, float _z)
        : w(_w), x(_x), y(_y), z(_z) {}

float Quaternion::magnitude() const {
    return std::sqrt(w * w + x * x + y * y + z * z);
}

Quaternion Quaternion::normalize() const {
    float m = magnitude();
    return { w / m, x / m, y / m, z / m };
}

Quaternion Quaternion::operator-() const {
    return { w, -x, -y, -z };
}

Quaternion Quaternion::operator*(const Quaternion& q) const {
    return {
            w * q.w - x * q.x - y * q.y - z * q.z,
            w * q.x + x * q.w + y * q.z - z * q.y,
            w * q.y - x * q.z + y * q.w + z * q.x,
            w * q.z + x * q.y - y * q.x + z * q.w
    };
}

Vector Quaternion::operator*(const Vector& v) const {
    Vector u(x, y, z);
    Vector t = Vector::cross(u, v) * 2;
    return v + t * w + Vector::cross(u, t);
}

void Quaternion::operator*=(const Quaternion& q) {
    (*this) = (*this) * q;
}

Quaternion Quaternion::euler(const Vector& euler) {
    return Quaternion::euler(euler.x, euler.y, euler.z);
}

Quaternion Quaternion::euler(float x, float y, float z) {
    float c1 = cos(x / 2);
    float c2 = cos(y / 2);
    float c3 = cos(z / 2);
    float s1 = sin(x / 2);
    float s2 = sin(y / 2);
    float s3 = sin(z / 2);

    return {
            c1 * c2 * c3 - s1 * s2 * s3,
            s1 * c2 * c3 + c1 * s2 * s3,
            c1 * s2 * c3 + s1 * c2 * s3,
            c1 * c2 * s3 - s1 * s2 * c3
    };
}

Vector Quaternion::toEuler() const {
    float sqw = w * w;
    float sqx = x * x;
    float sqy = y * y;
    float sqz = z * z;
    float unit = sqx + sqy + sqz + sqw;
    float test = x * y + z * w;

    Vector euler;

    if (test > 0.4999 * unit) {
        euler.y = 2 * atan2(x, w);
        euler.z = PI / 2;
        euler.x = 0;
        return euler;
    }

    if (test < -0.4999 * unit) {
        euler.y = -2 * atan2(x, w);
        euler.z = -PI / 2;
        euler.x = 0;
        return euler;
    }

    euler.y = atan2(2 * y * w - 2 * x * z, sqx - sqy - sqz + sqw);
    euler.z = asin(2 * test / unit);
    euler.x = atan2(2 * x * w - 2 * y * z, -sqx + sqy - sqz + sqw);

    return euler;
}


Quaternion Quaternion::matrixToQuaternion(const float* matrix) {
    Quaternion quaternion;

    float trace = matrix[0] + matrix[5] + matrix[10];
    float w, x, y, z;

    if (trace > 0) {
        float S = sqrt(trace + 1.0f) * 2.0f;
        w = 0.25f * S;
        x = (matrix[9] - matrix[6]) / S;
        y = (matrix[2] - matrix[8]) / S;
        z = (matrix[4] - matrix[1]) / S;
    } else if ((matrix[0] > matrix[5]) && (matrix[0] > matrix[10])) {
        float S = sqrt(1.0f + matrix[0] - matrix[5] - matrix[10]) * 2.0f;
        w = (matrix[9] - matrix[6]) / S;
        x = 0.25f * S;
        y = (matrix[1] + matrix[4]) / S;
        z = (matrix[2] + matrix[8]) / S;
    } else if (matrix[5] > matrix[10]) {
        float S = sqrt(1.0f + matrix[5] - matrix[0] - matrix[10]) * 2.0f;
        w = (matrix[2] - matrix[8]) / S;
        x = (matrix[1] + matrix[4]) / S;
        y = 0.25f * S;
        z = (matrix[6] + matrix[9]) / S;
    } else {
        float S = sqrt(1.0f + matrix[10] - matrix[0] - matrix[5]) * 2.0f;
        w = (matrix[4] - matrix[1]) / S;
        x = (matrix[2] + matrix[8]) / S;
        y = (matrix[6] + matrix[9]) / S;
        z = 0.25f * S;
    }

    quaternion.w = w;
    quaternion.x = x;
    quaternion.y = y;
    quaternion.z = z;

    return quaternion;
}


Matrix::Matrix() {
    matrix = new float[16];
    for (short i = 0; i < 16; i++) {
        matrix[i] = 0.0f;
    }
}

void Matrix::operator+(const Matrix& other) {
    for (short i = 0; i < 16; i++) {
        matrix[i] += other.matrix[i];
    }
}

void Matrix::operator-(const Matrix& other) {
    for (short i = 0; i < 16; i++) {
        matrix[i] -= other.matrix[i];
    }
}

void Matrix::operator*(float constant) {
    for (short i = 0; i < 16; i++) {
        matrix[i] *= constant;
    }
}

Matrix Matrix::operator*(const Matrix& other) {
    Matrix result;

    for (short i = 0; i < 4; i++) {
        for (short j = 0; j < 4; j++) {
            float sum = 0.0f;
            for (short k = 0; k < 4; k++) {
                sum += other.matrix[i * 4 + k] * matrix[k * 4 + j];
            }
            result.matrix[i * 4 + j] = sum;
        }
    }

    return result;
}



