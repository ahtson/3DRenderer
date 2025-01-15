#include "Types.h"

class Rasterizer {
public:
  Rasterizer() = default;
  Rasterizer(const Rasterizer &other);
  Rasterizer &operator=(const Rasterizer &other);

  void rasterize(const Types::RenderingPrimitives::Primitive &primitive);
  void clear();

  const std::vector<Types::ScreenPixel> &get_framebuffer() const;
};