#ifndef RENDERER_H
#define RENDERER_H

#include "Camera.h"
#include "Scene.h"
#include "Screen.h"
class Renderer {
public:
  Renderer(Camera &camera, Scene &scene, Screen &screen)
      : _camera(camera), _scene(scene), _screen(screen) {};
  int render();
  void draw_triangle(const Types::RenderingPrimitives::Triangle
                         &triangle); // потом сделать приватным после дебага

private:
  void apply_perspective_projection();
  void clip();
  void rasterize();
  void remove_hidden_faces();

  Camera &_camera;
  Scene &_scene;
  Screen &_screen;
};

#endif