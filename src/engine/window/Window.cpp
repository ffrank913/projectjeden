#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../globals.h"

#include <iostream>

extern Window __window = Window();

void onFramebufferResize(GLFWwindow* _window, int _width, int _height) {
  glViewport(0, 0, _width, _height);
}

class Window {
  public:
    int Init() {
      glfwInit();
      glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
      glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
      #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
      #endif

      __glfwWindow = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
      if (__glfwWindow == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
      }
      glfwMakeContextCurrent(__glfwWindow);
      glfwSetFramebufferSizeCallback(__glfwWindow, onFramebufferResize);

      if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
      }

      // *******************************************
      // RENDERER
      // *******************************************

      __renderer.Init();
    }

    int StartRenderLoop() {
      while(!glfwWindowShouldClose(__glfwWindow)) {
        Render();
      }

      StopRenderLoop();
    }

    int Render() {
      // *******************************************
      // RENDER LOOP
      // *******************************************
        
      // handle input
      processInput(_window);

      __renderer.Render();


      // events and buffer swaps
      glfwSwapBuffers(_window);
      glfwPollEvents();   
      
      return 0;
    }

    int StopRenderLoop() {
      // *******************************************
      // TERMINATE PROGRAM
      // *******************************************

      // deallocate resources
      // glDeleteVertexArrays(1, &VAO);
      // glDeleteBuffers(1, &VBO);
      // glDeleteBuffers(1, &EBO);
      // glDeleteProgram(shaderProgram0);

      glfwTerminate();
    }

  private:
    GLFWwindow* __glfwWindow;
};