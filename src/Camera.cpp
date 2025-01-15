#include "Camera.h"

Camera::Camera(const Eigen::Vector3f &position, const Eigen::Vector3f &target,
               const Eigen::Vector3f &up, float fov, float aspect, float near,
               float far)
    : _position(position), _near(near), _far(far), _depth(near - far),
      _fov(fov), _aspect(aspect), _height(2 * near * tan(fov / 2)),
      _width(aspect * _height) {
  set_view_matrix(target);
  set_projection_matrix();
}

Camera::Camera(const Eigen::Vector3f &position,
               const Eigen::Matrix3f &orientation, float width, float height,
               float near, float far)
    : _position(position), _orientation(orientation), _width(width),
      _height(height), _near(near), _far(far), _depth(height - far),
      _aspect(width / height), _fov(2 * atan(height / (2 * near))) {
  // set_view_matrix();
  set_projection_matrix();
}

Camera::Camera(const Camera &other)
    : _position{other._position}, _orientation{other._orientation},
      _view_matrix{other._view_matrix},
      _projection_matrix{other._projection_matrix}, _width(other._width),
      _height(other._height), _depth(other._depth), _aspect(other._aspect),
      _fov(other._fov), _near(other._near), _far(other._far) {}

Camera &Camera::operator=(const Camera &other) {
  _position = other._position;
  _orientation = other._orientation;
  _view_matrix = other._view_matrix;
  _projection_matrix = other._projection_matrix;
  return *this;
}

float Camera::get_posx() const { return _position(0); }
float Camera::get_posy() const { return _position(1); }
float Camera::get_posz() const { return _position(2); }

Eigen::Matrix3f Camera::get_orientation() const { return _orientation; }
Eigen::Matrix4f Camera::get_view_matrix() const { return _view_matrix; }
Eigen::Matrix4f Camera::get_projection_matrix() const {
  return _projection_matrix;
}

void Camera::set_position(Eigen::Vector3f position) { _position = position; }
void Camera::set_orientation(Eigen::Matrix3f orientation) {
  _orientation = orientation;
}
void Camera::set_view_matrix(const Eigen::Vector3f &target) {
  Eigen::Vector3f forward = (target - _position).normalized();
  Eigen::Vector3f right = forward.cross(UP).normalized();
  Eigen::Vector3f camera_up;
}
void Camera::set_projection_matrix() {
  _projection_matrix.setZero();
  _projection_matrix(0, 0) = 2 * _near / _width;
  _projection_matrix(1, 1) = 2 * _near / _height;
  _projection_matrix(2, 2) = -(_far + _near) / _depth;
  _projection_matrix(3, 2) = -1;
  _projection_matrix(0, 3);
}

/*
void Camera::set_projection_matrix(Eigen::Matrix4f projection_matrix) {
  _projection_matrix = projection_matrix;
}
*/
