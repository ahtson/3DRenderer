#ifndef COLOR_H
#define COLOR_H

#include <algorithm>
#include <cstdint>
#include <type_traits>

template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T> ||
                                                  std::is_same_v<T, uint8_t>>>
class Color {
public:
  constexpr Color() : _red(0), _green(0), _blue(0), _alpha(255) {}
  constexpr Color(T red, T green, T blue, T alpha)
      : _red(red), _green(green), _blue(blue), _alpha(alpha) {}
  constexpr Color(const Color &other)
      : _red(other._red), _green(other._green), _blue(other._blue),
        _alpha(other._alpha) {}

  void set_red(T red) { _red = red; }
  void set_green(T green) { _green = green; }
  void set_blue(T blue) { _blue = blue; }
  void set_alpha(T alpha) { _alpha = alpha; }

  void set_color(T red, T green, T blue, T alpha) {
    set_red(red);
    set_green(green);
    set_blue(blue);
    set_alpha(alpha);
  }

  Color &operator=(const Color &other) {
    set_color(other.get_red(), other.get_green(), other.get_blue(),
              other.get_alpha());
    return *this;
  }

  T get_red() const { return _red; }
  T get_green() const { return _green; }
  T get_blue() const { return _blue; }
  T get_alpha() const { return _alpha; }

  Color operator+(const Color &other) const {
    return Color(_red + other.get_red(), _green + other.get_green(),
                 _blue + other.get_blue(), std::max(_alpha, other.get_alpha()));
  }
  Color operator-(const Color &other) const {
    return Color(_red - other.get_red(), _green - other.get_green(),
                 _blue - other.get_blue(), std::max(_alpha, other.get_alpha()));
  }

  Color &operator+=(const Color &other) {
    set_color(_red + other.get_red(), _green + other.get_green(),
              _blue + other.get_blue(), std::max(_alpha, other.get_alpha()));
    return *this;
  }
  Color &operator-=(const Color &other) {
    set_color(_red - other.get_red(), _green - other.get_green(),
              _blue - other.get_blue(), std::max(_alpha, other.get_alpha()));
    return *this;
  }

  template <typename U = T,
            typename = std::enable_if_t<std::is_floating_point_v<U>>>
  Color scale(const U scalar) const {
    return Color(_red * scalar, _green * scalar, _blue * scalar, _alpha);
  }
  template <typename U = T,
            typename = std::enable_if_t<std::is_floating_point_v<U>>>
  Color operator/(const U scalar) const {
    return Color(_red / scalar, _green / scalar, _blue / scalar, _alpha);
  }
  template <typename U = T,
            typename = std::enable_if_t<std::is_floating_point_v<U>>>
  Color &operator*=(const U scalar) {
    set_color(_red * scalar, _green * scalar, _blue * scalar, _alpha);
    return *this;
  }
  template <typename U = T,
            typename = std::enable_if_t<std::is_floating_point_v<U>>>
  Color &operator/=(const U scalar) {
    set_color(_red / scalar, _green / scalar, _blue / scalar, _alpha);
    return *this;
  };

  template <typename U = T>
  typename std::enable_if<std::is_same<U, uint8_t>::value, Color<float>>::type
  as_float() const {
    return Color<float>(static_cast<float>(_red) / 255.0f,
                        static_cast<float>(_green) / 255.0f,
                        static_cast<float>(_blue) / 255.0f,
                        static_cast<float>(_alpha) / 255.0f);
  };

  template <typename U = T>
  typename std::enable_if<std::is_floating_point<U>::value,
                          Color<uint8_t>>::type
  as_integer() const {
    return Color<uint8_t>(
        static_cast<uint8_t>(std::min(255.0f, std::max(0.0f, _red * 255.0f))),
        static_cast<uint8_t>(std::min(255.0f, std::max(0.0f, _blue * 255.0f))),
        static_cast<uint8_t>(std::min(255.0f, std::max(0.0f, _green * 255.0f))),
        static_cast<uint8_t>(
            std::min(255.0f, std::max(0.0f, _alpha * 255.0f))));
  };

private:
  T _red;
  T _green;
  T _blue;
  T _alpha;
};

static constexpr Color<uint8_t> WHITE = Color<uint8_t>(255, 255, 255, 255);
static constexpr Color<uint8_t> BLACK = Color<uint8_t>(0, 0, 0, 255);
static constexpr Color<uint8_t> GRAY = Color<uint8_t>(128, 128, 128, 255);
static constexpr Color<uint8_t> RED = Color<uint8_t>(255, 0, 0, 255);
static constexpr Color<uint8_t> GREEN = Color<uint8_t>(0, 255, 0, 255);
static constexpr Color<uint8_t> BLUE = Color<uint8_t>(0, 0, 255, 255);
static constexpr Color<uint8_t> YELLOW = Color<uint8_t>(255, 255, 0, 255);
static constexpr Color<uint8_t> CYAN = Color<uint8_t>(0, 255, 255, 255);
static constexpr Color<uint8_t> MAGENTA = Color<uint8_t>(255, 0, 255, 255);

using ScreenPixel = Color<uint8_t>;
using FloatPixel = Color<float>;

#endif