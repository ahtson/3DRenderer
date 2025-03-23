#ifndef RUNNER_H
#define RUNNER_H

#include "Renderer.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Runner {
public:
  Runner() = default;
  ~Runner() = default;
  void run();

private:
  bool is_running = true;
  int argc;
  char **argv;
};

#endif