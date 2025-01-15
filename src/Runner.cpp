#include "Runner.h"
#include "Color.h"
#include <iostream>

void Runner::run() {
  Screen screen(800, 600);
  Camera camera;
  Scene scene;
  Renderer renderer(camera, scene, screen);

  const unsigned int width = screen.get_width();
  const unsigned int height = screen.get_height();
  sf::RenderWindow window(sf::VideoMode(width, height), "A triangle! Wowie!");

  Types::RenderingPrimitives::Triangle triangle(
      Types::RenderingPrimitives::Vertex(200, 150, 0.5, RED.as_float()),
      Types::RenderingPrimitives::Vertex(400, 450, 0.5, GREEN.as_float()),
      Types::RenderingPrimitives::Vertex(600, 150, 0.5, BLUE.as_float()));

  renderer.draw_triangle(triangle);
  std::vector<sf::Uint8> sfml_buffer = screen.get_SFML_buffer();
  sf::Texture texture;
  if (!texture.create(width, height)) {
    return;
  }
  sf::Sprite sprite(texture);
  window.setFramerateLimit(60);
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    texture.update(sfml_buffer.data());
    window.clear();
    window.draw(sprite);
    window.display();
  }
}