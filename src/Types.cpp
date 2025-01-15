#include "Types.h"
#include <cmath>
#include <iostream>

namespace Types {
namespace RenderingPrimitives {

Vertex::Vertex() : _position{0, 0, 0} {}

Vertex::Vertex(float x, float y, float z, Color<float> color)
    : _position{x, y, z}, _color(color) {}

Vertex::Vertex(const Vertex &other)
    : _position{other._position}, _color(other._color) {}

Vertex &Vertex::operator=(const Vertex &other) {
  _position = other._position;
  _color = other._color;
  return *this;
}

void Vertex::set_X(float x) { _position(0) = x; }
void Vertex::set_Y(float y) { _position(1) = y; }
void Vertex::set_Z(float z) { _position(2) = z; }
void Vertex::set_position(Eigen::Vector3f position) { _position = position; }
void Vertex::set_position(float x, float y, float z) { _position << x, y, z; }
void Vertex::set_color(const Color<float> &color) { _color = color; }

float Vertex::get_X() const { return _position(0); }
float Vertex::get_Y() const { return _position(1); }
float Vertex::get_Z() const { return _position(2); }

Eigen::Vector3f Vertex::get_position() const { return _position; }

Color<float> Vertex::get_color() const { return _color; }

Point::Point(const Vertex &position) : _vertex(position) {
  _vertices.push_back(_vertex);
}
Point::Point(float x, float y, float z) : _vertex(x, y, z, BLACK.as_float()) {
  _vertices.push_back(_vertex);
}

const std::vector<Vertex> &Point::get_vertices() const { return _vertices; }

Line::Line(const Vertex &start, const Vertex &end) : _start(start), _end(end) {
  _vertices.push_back(_start);
  _vertices.push_back(_end);
}

const std::vector<Vertex> &Line::get_vertices() const { return _vertices; }

Triangle::Triangle(const Vertex &v1, const Vertex &v2, const Vertex &v3)
    : _v1(v1), _v2(v2), _v3(v3) {
  _vertices.push_back(_v1);
  _vertices.push_back(_v2);
  _vertices.push_back(_v3);
}
const std::vector<Vertex> &Triangle::get_vertices() const { return _vertices; }
} // namespace RenderingPrimitives
} // namespace Types