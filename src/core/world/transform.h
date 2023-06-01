//
// Created by Esilff on 01/06/2023.
//

#ifndef TRANSFORM_H
#define TRANSFORM_H


#include "../math/math.h"


struct Vector;
struct Quaternion;

struct Transform {
    Vector position, scale{ 1, 1, 1 };
    Quaternion rotation;

    Vector forward() const;
    Vector right() const;
    Vector up() const;
    Vector localToWorld(const Vector& p) const;
    Vector worldToLocal(const Vector& p) const;

    float* translationMatrix();
    float* scaleMatrix();

public:
    Transform();

    float* getModelMatrix() {
        return Matrix().modelMatrix(translationMatrix(), Matrix().quaternionToMatrix(rotation), scaleMatrix());
    }
};

#endif //ESGI_OPENGL_TRANSFORM_H
