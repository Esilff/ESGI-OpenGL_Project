//
// Created by Esilff on 01/06/2023.
//

#include "Camera.h"

Camera::Camera() {
    target = transform.forward();
    fov = 90;
    aspectRatio = 16/9;
    nearPlane= 0.01;
    farPlane = 1000;
}

float *Camera::getViewMatrix() const  {
    return Matrix().viewMatrix(transform.position, target, transform.up());
}

float *Camera::getProjectionMatrix() const {
    return Matrix().projectionMatrix(fov, aspectRatio, nearPlane, farPlane);
}

void Camera::Move(Vector movement) {
    transform.position+= movement;
}

void Camera::Rotate(Vector rotation) {
    transform.rotation *= Quaternion().euler(rotation.x, rotation.y, rotation.z);
}

void Camera::setFov(float newFov) {
    fov = newFov;
}

void Camera::setNearPlane(float newNearPlane) {
    nearPlane = newNearPlane;
}

void Camera::setFarPlane(float newFarPlane) {
    farPlane = newFarPlane;
}

void Camera::setAspectRatio(float newAr) {
    aspectRatio = newAr;
}