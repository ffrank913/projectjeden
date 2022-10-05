#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../globals.h"

extern Renderer __renderer = Renderer();

class Renderer {
  public:

    int Init() {

    }

    void Render() {
      

      // render
      // clear
      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      // draw vertices
      glUseProgram(__shaderLoader.GetDefaultShader());
      glBindVertexArray(VAO0);
      glDrawArrays(GL_TRIANGLES, 0, 3);
      glUseProgram(shaderProgram1);
      glBindVertexArray(VAO1);
      glDrawArrays(GL_TRIANGLES, 0, 3);

      
    }

    void RenderTriangle(float _vertices[9]) {
      unsigned int VBO, VAO;
      glGenVertexArrays(1, &VAO);
      glGenBuffers(1, &VBO);
      
      // generate a vertex array and a vertex buffer
      glBindVertexArray(VAO);
      glBindBuffer(GL_ARRAY_BUFFER, VBO);
      glBufferData(GL_ARRAY_BUFFER, sizeof(&_vertices), _vertices, GL_STATIC_DRAW);
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
      glEnableVertexAttribArray(0);

      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      glBindVertexArray(0);
    }

    void RenderElement(float _vertices[], unsigned int _indices[]) {
      unsigned int VBO, VAO, EBO;
      glGenVertexArrays(1, &VAO);
      glGenBuffers(1, &VBO);
      glGenBuffers(1, &EBO);
      
      // generate a vertex array and a vertex buffer
      glBindVertexArray(VAO);
      glBindBuffer(GL_ARRAY_BUFFER, VBO);
      glBufferData(GL_ARRAY_BUFFER, sizeof(&_vertices), _vertices, GL_STATIC_DRAW);

      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(&_indices), _indices, GL_STATIC_DRAW);

      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
      glEnableVertexAttribArray(0);

      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      glBindVertexArray(0);
    }
};