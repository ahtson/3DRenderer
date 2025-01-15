#ifndef CAMERA_H
#define CAMERA_H

#include "Eigen/Dense"

class Camera {
public:
  Camera() = default;
  Camera(const Eigen::Vector3f &position, const Eigen::Vector3f &target,
         const Eigen::Vector3f &up, float fov, float aspect, float near,
         float far);
  Camera(const Eigen::Vector3f &position, const Eigen::Matrix3f &orientation,
         float width, float height, float near, float far);
  Camera(const Camera &other);

  Camera &operator=(const Camera &other);

  float get_posx() const;
  float get_posy() const;
  float get_posz() const;

  Eigen::Matrix3f get_orientation() const;
  Eigen::Matrix4f get_view_matrix() const;
  Eigen::Matrix4f get_projection_matrix() const;

  void set_position(Eigen::Vector3f position);
  void set_orientation(Eigen::Matrix3f);
  void set_view_matrix(const Eigen::Vector3f &target);
  void set_projection_matrix();

private:
  Eigen::Vector3f _position;

  float _near;
  float _far;

  float _width;
  float _height;
  float _depth;

  float _fov;
  float _aspect;

  Eigen::Matrix3f _orientation;
  Eigen::Matrix4f _view_matrix;
  Eigen::Matrix4f _projection_matrix;
};

static const Eigen::Vector3f UP = Eigen::Vector3f(0, 1, 0);

#endif