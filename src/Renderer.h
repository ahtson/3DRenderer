#ifndef RENDERER_H
#define RENDERER_H

#include "Camera.h"
#include "Scene.h"
#include "Screen.h"

namespace Renderer {
class Renderer {
public:
  Renderer(Camera &camera, Scene &scene, Screen &screen)
      : _camera(camera), _scene(scene), _screen(screen) {};
  int render();
  void draw_triangle(const Types::RenderingPrimitives::Triangle
                         &triangle); // потом сделать приватным после дебага
  Types::RenderingPrimitives::Vertex
  apply_perspective_projection(const Types::RenderingPrimitives::Vertex) const;

private:
  Camera &_camera;
  Scene &_scene;
  Screen &_screen;
};
}; // namespace Renderer

#endif
