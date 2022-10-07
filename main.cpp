#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "src/engine/log/log.h"
#include "src/window/window.h"

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
  Window w;
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

  GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }



  // *******************************************
  // VERTEX SHADER
  // *******************************************

  // create vertex shader
  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);

  // set shader source
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);

  // compile shader
  glCompileShader(vertexShader);

  // check for compile errors
  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if(!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
  }



  // *******************************************
  // FRAGMENT SHADER
  // *******************************************

  unsigned int fragmentShader0;
  fragmentShader0 = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader0, 1, &fragmentShader0Source, NULL);
  glCompileShader(fragmentShader0);
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if(!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
  }
  unsigned int fragmentShader1;
  fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader1, 1, &fragmentShader1Source, NULL);
  glCompileShader(fragmentShader1);
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if(!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
  }



  // *******************************************
  // SHADER PROGRAM
  // *******************************************

  // create shader program
  unsigned int shaderProgram0;
  shaderProgram0 = glCreateProgram();

  // attach previously created shaders to program
  glAttachShader(shaderProgram0, vertexShader);
  glAttachShader(shaderProgram0, fragmentShader0);
  glLinkProgram(shaderProgram0);

    // check for linking errors
  glGetProgramiv(shaderProgram0, GL_LINK_STATUS, &success);
  if(!success) {
    glGetProgramInfoLog(shaderProgram0, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::LINKING::COMPILATION_FAILED\n" << infoLog << std::endl;
  }
  
  // create shader program
  unsigned int shaderProgram1;
  shaderProgram1 = glCreateProgram();

  // attach previously created shaders to program
  glAttachShader(shaderProgram1, vertexShader);
  glAttachShader(shaderProgram1, fragmentShader1);
  glLinkProgram(shaderProgram1);

  // check for linking errors
  glGetProgramiv(shaderProgram1, GL_LINK_STATUS, &success);
  if(!success) {
    glGetProgramInfoLog(shaderProgram1, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::LINKING::COMPILATION_FAILED\n" << infoLog << std::endl;
  }

  // delete shaders after linking them, not needed anymore
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader0);
  glDeleteShader(fragmentShader1);



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
  // unsigned int indices[] = {
  //   0, 1, 3,
  //   1, 2, 3,
  // };

  // allocate buffers in memory
  unsigned int VBO0, VBO1;
  unsigned int VAO0, VAO1;
  glGenVertexArrays(1, &VAO0);
  glGenVertexArrays(1, &VAO1);
  glGenBuffers(1, &VBO0);
  glGenBuffers(1, &VBO1);
  // unsigned int EBO;
  
  // generate a vertex array and a vertex buffer
  glBindVertexArray(VAO0);
  glBindBuffer(GL_ARRAY_BUFFER, VBO0);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices0), vertices0, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glBindVertexArray(VAO1);
  glBindBuffer(GL_ARRAY_BUFFER, VBO1);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  // glGenBuffers(1, &EBO);

  // bind vertex array object first

  // bind the created buffers
  // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

  // send data to buffer
  // GL_STREAM_DRAW: the data is set only once and used by the GPU at most a few times.
  // GL_STATIC_DRAW: the data is set only once and used many times.
  // GL_DYNAMIC_DRAW: the data is changed a lot and used many times.
  // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


  // *******************************************
  // VERTEX DATA ATTRIBUTES
  // *******************************************
  
  // set how openGL has to interpret the buffer data
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

  // enable vertex attribute
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0); 
  glBindVertexArray(0);


  // *******************************************
  // RENDER LOOP
  // *******************************************
  while(!glfwWindowShouldClose(window)) {
    
    // handle input
    processInput(window);

    // render
    // clear
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // draw vertices
    glUseProgram(shaderProgram0);
    glBindVertexArray(VAO0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glUseProgram(shaderProgram1);
    glBindVertexArray(VAO1);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // events and buffer swaps
    glfwSwapBuffers(window);
    glfwPollEvents();    
  }



  // *******************************************
  // TERMINATE PROGRAM
  // *******************************************

  // deallocate resources
  // glDeleteVertexArrays(1, &VAO);
  // glDeleteBuffers(1, &VBO);
  // glDeleteBuffers(1, &EBO);
  glDeleteProgram(shaderProgram0);

  glfwTerminate();
  return 0;
} 