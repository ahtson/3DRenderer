#ifndef OBJECT_H
#define OBJECT_H

#include "Eigen/Core"
#include "Types.h"

// тут будет класс Object -- что-то типа контейнера с треугольниками (?)

class Object {
public:
private:
  Eigen::Vector3f _position; // координаты в World space (?)
  std::vector<Types::RenderingPrimitives::Triangle> _triangles;
};

#endif