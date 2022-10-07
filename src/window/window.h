#pragma once

#include <iostream>
#include <glfw3.h>
#include <glad.h>
#include "log.h"
#include "engine.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}

class Window {
public:
  Window();
  ~Window();

private:
  GLFWwindow* m_GlfwWindow;
  Engine* m_Engine;
};