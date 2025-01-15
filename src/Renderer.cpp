#include "Renderer.h"
#include <iostream>

void Renderer::draw_triangle(
    const Types::RenderingPrimitives::Triangle &triangle) {
  const std::vector<Types::RenderingPrimitives::Vertex> &vertices =
      triangle.get_vertices();
  if (vertices.size() != 3) {
    return;
  }

  Color<float> color0 = vertices[0].get_color();
  Color<float> color1 = vertices[1].get_color();
  Color<float> color2 = vertices[2].get_color();

  Eigen::Vector3f v0 = vertices[0].get_position();
  Eigen::Vector3f v1 = vertices[1].get_position();
  Eigen::Vector3f v2 = vertices[2].get_position();

  unsigned int min_X = std::max(0U, static_cast<unsigned int>(std::floor(
                                        std::min({v0.x(), v1.x(), v2.x()}))));
  unsigned int min_Y = std::max(0U, static_cast<unsigned int>(std::floor(
                                        std::min({v0.y(), v1.y(), v2.y()}))));
  unsigned int max_X = std::min(
      _screen.get_width() - 1,
      static_cast<unsigned int>(std::ceil(std::max({v0.x(), v1.x(), v2.x()}))));
  unsigned int max_Y = std::min(
      _screen.get_height() - 1,
      static_cast<unsigned int>(std::ceil(std::max({v0.y(), v1.y(), v2.y()}))));

  auto edge_function = [](const Eigen::Vector3f &v0, const Eigen::Vector3f &v1,
                          const Eigen::Vector3f &v2) {
    return (v2.x() - v0.x()) * (v1.y() - v0.y()) -
           (v2.y() - v0.y()) * (v1.x() - v0.x());
  };

  float signed_area = edge_function(v0, v1, v2);

  if (signed_area <= 1e-6) { // надо будет вынести в отдельную константу
    return;
  }

  for (int y = min_Y; y <= max_Y; ++y) {
    for (int x = min_X; x <= max_X; ++x) {
      Eigen::Vector3f p(x + 0.5f, y + 0.5f, 0.0f);

      float w0 = edge_function(v1, v2, p);
      float w1 = edge_function(v2, v0, p);
      float w2 = edge_function(v0, v1, p);

      if (w0 >= 0 && w1 >= 0 && w2 >= 0) {
        w0 /= signed_area;
        w1 /= signed_area;
        w2 /= signed_area;

        float z = w0 * v0.z() + w1 * v1.z() + w2 * v2.z();
        Types::ScreenPixel pixel_color =
            (color0.scale(w0) + color1.scale(w1) + color2.scale(w2))
                .as_integer();
        _screen.set_pixel(x, y, z, pixel_color);
      }
    }
  }
}