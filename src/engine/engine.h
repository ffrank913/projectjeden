#pragma once

#include <ctime>
#include <glfw3.h>

#include "renderer.h"
#include "input.h"

class Engine {
public:
  Engine();
  ~Engine();
  void Update();

private:
  Renderer* m_Renderer;
  Input* m_Input;

};