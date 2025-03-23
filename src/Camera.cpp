#include "Camera.h"

Camera::Camera(float z_position) : _z_position(z_position) {
  _projection_matrix = Eigen::Matrix4f::Identity();
  _projection_matrix(3, 2) = -1.0f / _z_position;
}

float Camera::get_z_position() const { return _z_position; }

void Camera::set_z_position(float z_position) {
  _z_position = z_position;
  _calculate_projection_matrix();
}

void Camera::_calculate_projection_matrix() {
  _projection_matrix(3, 2) = -1.0f / _z_position;
}

Eigen::Matrix4f Camera::get_projection_matrix() const {
  return _projection_matrix;
}