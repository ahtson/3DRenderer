#ifndef TYPES_H
#define TYPES_H

#include "Color.h"
#include "Eigen/Dense"
#include <cstddef>
#include <cstdint>
#include <vector>

namespace Types {
using ScreenPixel = Color<uint8_t>;
using FloatPixel = Color<float>;

namespace RenderingPrimitives {
class Vertex {
public:
  Vertex();
  Vertex(float x, float y, float z, Color<float> color);
  Vertex(const Vertex &other);

  Vertex &operator=(const Vertex &other);

  void set_X(float x);
  void set_Y(float y);
  void set_Z(float z);
  void set_position(Eigen::Vector3f position);
  void set_position(float x, float y, float z);
  void set_color(const Color<float> &color);

  float get_X() const;
  float get_Y() const;
  float get_Z() const;

  Eigen::Vector3f get_position() const;
  Color<float> get_color() const;

private:
  Eigen::Vector3f _position;
  Color<float> _color; // Можно бы в принципе использовать Eigen::Vector4f
};

class Primitive {
public:
  virtual ~Primitive() = default;
  virtual const std::vector<Vertex> &get_vertices() const = 0;

protected:
  std::vector<Vertex> _vertices;
};

class Point : public Primitive {
public:
  Point(const Vertex &vertex);
  Point(float x, float y, float z);
  const std::vector<Vertex> &get_vertices() const override;

private:
  Vertex _vertex;
};

class Line : public Primitive {
public:
  Line(const Vertex &start, const Vertex &end);
  const std::vector<Vertex> &get_vertices() const override;

private:
  Vertex _start;
  Vertex _end;
};

class LineStrip : public Primitive {
public:
  LineStrip(const std::vector<Vertex> &vertices);
  const std::vector<Vertex> &get_vertices() const override;

private:
  std::vector<Vertex> vertices;
};

class Triangle : public Primitive {
public:
  Triangle(const Vertex &v1, const Vertex &v2, const Vertex &v3);
  const std::vector<Vertex> &get_vertices() const override;
  Eigen::Vector3f get_normal_vector() const;

private:
  Eigen::Vector3f _normal_vector;

  Vertex _v1;
  Vertex _v2;
  Vertex _v3;
};
} // namespace RenderingPrimitives
} // namespace Types
#endif
