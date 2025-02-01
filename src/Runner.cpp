#include "Runner.h"
#include "Color.h"
#include <iostream>

void Runner::run() {
  Screen screen(800, 600);
  Camera camera(5.0);
  Scene scene;
  Renderer::Renderer renderer(camera, scene, screen);

  const unsigned int width = screen.get_width();
  const unsigned int height = screen.get_height();
  sf::RenderWindow window(sf::VideoMode(width, height), "Triangle. Wow!");

  std::vector<sf::Uint8> sfml_buffer = screen.get_SFML_buffer();
  sf::Texture texture;
  if (!texture.create(width, height)) {
    return;
  }
  sf::Sprite sprite(texture);
  window.setFramerateLimit(60);

  renderer.render();
  sfml_buffer = screen.get_SFML_buffer();

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    texture.update(sfml_buffer.data());
    sprite.setTexture(texture);
    window.clear();
    window.draw(sprite);
    window.display();
  }
}