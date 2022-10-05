#include "./state/state.cpp";

class Game {
  public: 
    GameState m_State;
    bool m_Keys[1024];
    unsigned int m_Width, m_Height;

    Game(unsigned int _width, unsigned int _height);
    ~Game();

    void Init();

    void Tick(float _deltaTime);
    void Render();
};