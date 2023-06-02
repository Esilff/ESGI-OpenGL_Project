//
// Created by Esilff on 01/06/2023.
//

#ifndef CAMERA_H
#define CAMERA_H

#include "../math/math.h"
#include "transform.h"


struct Vector;
struct Quaternion;

class Camera {
    Transform transform;
    Vector target;
    float fov;
    float aspectRatio;
    float nearPlane;
    float farPlane;

public:

    Camera();

    float* getViewMatrix() const;

    float* getProjectionMatrix() const;

    void Move(Vector movement);

    void Rotate(Vector rotation);

    void setFov(float newFov);

    void setNearPlane(float newNearPlane);

    void setFarPlane(float newFarPlane);

    void setAspectRatio(float newAr);
};


#endif //ESGI_OPENGL_CAMERA_H
