#include "./window/Window.cpp" 

class Engine {
  public: 
    void Init() {
      // *******************************************
      // INIT PROGRAM
      // *******************************************

      __window.Init();

      // *******************************************
      // SHADERS
      // *******************************************

      __shaderLoader.Init();

    }
}