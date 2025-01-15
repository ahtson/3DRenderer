#include "Screen.h"

Screen::Screen(unsigned int width, unsigned int height)
    : _width(width), _height(height), _zbuffer(width * height),
      _pixel_buffer(width * height) {
  std::fill(_zbuffer.begin(), _zbuffer.end(),
            std::numeric_limits<float>::infinity());
  std::fill(_pixel_buffer.begin(), _pixel_buffer.end(), Types::ScreenPixel());
}

unsigned int Screen::get_width() const { return _width; }
unsigned int Screen::get_height() const { return _height; }

void Screen::set_width(unsigned int width) { _width = width; }
void Screen::set_height(unsigned int height) { _height = height; }

void Screen::clear() {
  _pixel_buffer.clear();
  _pixel_buffer.resize(_width * _height, Types::ScreenPixel());
}

int Screen::set_pixel(unsigned int x, unsigned int y, unsigned int z,
                      Types::ScreenPixel pixel) {
  size_t index = x + y * _width;
  if (index >= _pixel_buffer.size()) {
    return 0;
  }
  if (z < _zbuffer[index]) {
    _zbuffer[index] = z;
    _pixel_buffer[index] = pixel;
  }
  return 1;
}

std::vector<sf::Uint8> Screen::get_SFML_buffer() const {
  std::vector<sf::Uint8> SFML_buffer(_pixel_buffer.size() * 4);
  for (unsigned int i = 0; i < _pixel_buffer.size(); ++i) {
    const ScreenPixel pixel = _pixel_buffer[i];
    SFML_buffer[i * 4 + 0] = pixel.get_red();
    SFML_buffer[i * 4 + 1] = pixel.get_green();
    SFML_buffer[i * 4 + 2] = pixel.get_blue();
    SFML_buffer[i * 4 + 3] = pixel.get_alpha();
  }
  return SFML_buffer;
}