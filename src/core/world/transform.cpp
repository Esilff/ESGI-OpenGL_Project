#include "transform.h"

Transform::Transform() {
    position = Vector(0,0,0);
    rotation = Quaternion();
    scale = Vector(1,1,1);
}

Vector Transform::forward() const {
    return rotation * Vector{ 0, 0, 1 };
}

Vector Transform::right() const {
    return rotation * Vector{ 1, 0, 0 };
}

Vector Transform::up() const {
    return rotation * Vector{ 0, 1, 0 };
}

Vector Transform::localToWorld(const Vector& p) const {
    return (rotation * Vector{ p.x * scale.x, p.y * scale.y, p.z * scale.z }) + position;
}

Vector Transform::worldToLocal(const Vector& p) const {
    return -rotation * (Vector{ p.x / scale.x, p.y / scale.y, p.z / scale.z } - position);
}

float* Transform::translationMatrix() {
    return new float[16]{1,0,0,position.x,0,1,0,position.y,0,0,1,position.z,0,0,0,1};
}

float* Transform::scaleMatrix() {
    return new float[16] {
        scale.x,0,0,0,
        0, scale.y,0,0,
        0,0,scale.z,0,
        0,0,0,1
    };
}