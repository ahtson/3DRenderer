#ifndef CAMERA_H
#define CAMERA_H

#include <Eigen/Core>

class Camera {
public:
  Camera() = default;
  Camera(float z_position);

  float get_z_position() const;
  Eigen::Matrix4f get_projection_matrix() const;

  void set_z_position(float _z_position);

private:
  float _z_position;
  Eigen::Matrix4f _projection_matrix;

  void _calculate_projection_matrix();
};

static const Eigen::Vector3f UP = Eigen::Vector3f(0, 1, 0);

#endif