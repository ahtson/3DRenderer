#ifndef SCREEN_H
#define SCREEN_H

#include "Types.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Screen {
public:
  Screen(unsigned int width, unsigned int height);

  unsigned int get_width() const;
  unsigned int get_height() const;

  void set_width(unsigned int width);
  void set_height(unsigned int height);

  void clear();
  int set_pixel(unsigned int x, unsigned int y, unsigned int z,
                Types::ScreenPixel pixel); // returns non-zero value if
                                           // pixel is successfully set
  std::vector<sf::Uint8> get_SFML_buffer() const;

private:
  unsigned int _width;
  unsigned int _height;
  std::vector<Types::ScreenPixel> _pixel_buffer;
  std::vector<float> _zbuffer;
};

#endif