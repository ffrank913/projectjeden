#include "Window.h"

Window::Window() {
  // *******************************************
  // INIT PROGRAM
  // *******************************************

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  #endif

  m_GlfwWindow = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
  if (m_GlfwWindow == NULL) {
    Log::Error("Failed to create GLFW window");
    glfwTerminate();
    return;
  }
  glfwMakeContextCurrent(m_GlfwWindow);
  glfwSetFramebufferSizeCallback(m_GlfwWindow, framebuffer_size_callback);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    Log::Error("Failed to initialize GLAD");
    return;
  }

  m_Engine = new Engine();
}

Window::~Window()
{
  delete m_GlfwWindow;
  delete m_Engine;
}