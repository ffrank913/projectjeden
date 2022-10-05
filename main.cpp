#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "./src/engine/globals.h"

#include <iostream>

const char *vertexShaderSource = 
  "#version 330 core\n"
  "layout (location = 0) in vec3 aPos;\n"
  "void main()\n"
  "{\n"
  "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
  "}\0";

const char *fragmentShader0Source = 
  "#version 330 core\n"
  "out vec4 FragColor;\n"
  "void main()\n"
  "{\n"
      "FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
  "}\0";

const char *fragmentShader1Source = 
  "#version 330 core\n"
  "out vec4 FragColor;\n"
  "void main()\n"
  "{\n"
      "FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
  "}\0";

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      glfwSetWindowShouldClose(window, true);
    }
}

int main()
{
  
  

  // *******************************************
  // VERTEX BUFFER OBJECT & VERTEX ARRAY OBJECT
  // *******************************************

  float vertices0[] = {
    0.5f, 0.5f, 0.0f,  // top right
    0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
  };
  float vertices1[] = {
    -0.5f, 0.5f, 0.0f,   // top left 
    0.5f, 0.5f, 0.0f,  // top right
    -0.5f, -0.5f, 0.0f,  // bottom left
  };

  __renderer.RenderTriangle(vertices0);
  __renderer.RenderTriangle(vertices1);



  // // unsigned int indices[] = {
  // //   0, 1, 3,
  // //   1, 2, 3,
  // // };

  // // allocate buffers in memory
  // unsigned int VBO0, VBO1;
  // unsigned int VAO0, VAO1;
  // glGenVertexArrays(1, &VAO0);
  // glGenVertexArrays(1, &VAO1);
  // glGenBuffers(1, &VBO0);
  // glGenBuffers(1, &VBO1);
  // // unsigned int EBO;
  
  // // generate a vertex array and a vertex buffer
  // glBindVertexArray(VAO0);
  // glBindBuffer(GL_ARRAY_BUFFER, VBO0);
  // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices0), vertices0, GL_STATIC_DRAW);
  // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  // glEnableVertexAttribArray(0);

  // glBindVertexArray(VAO1);
  // glBindBuffer(GL_ARRAY_BUFFER, VBO1);
  // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
  // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  // glEnableVertexAttribArray(0);
  // // glGenBuffers(1, &EBO);

  // // bind vertex array object first

  // // bind the created buffers
  // // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

  // // send data to buffer
  // // GL_STREAM_DRAW: the data is set only once and used by the GPU at most a few times.
  // // GL_STATIC_DRAW: the data is set only once and used many times.
  // // GL_DYNAMIC_DRAW: the data is changed a lot and used many times.
  // // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


  // // *******************************************
  // // VERTEX DATA ATTRIBUTES
  // // *******************************************
  
  // // set how openGL has to interpret the buffer data
  // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

  // // enable vertex attribute
  // glEnableVertexAttribArray(0);

  // glBindBuffer(GL_ARRAY_BUFFER, 0); 
  // glBindVertexArray(0);

  __window.StartRenderLoop();

  return 0;
} 