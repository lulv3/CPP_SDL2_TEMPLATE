#ifndef GAME_H
#define GAME_H

#include "Window.h"

static int FPS = 120;

class Game
{
public:
    Game();
    ~Game();

    void run();
    void update();
    void render();
    void handleEvents();

    // Template Events
    void handleKeyDownEvent(const SDL_KeyboardEvent &keyEvent);
    void handleKeyUpEvent(const SDL_KeyboardEvent &keyEvent);

private:
    bool mIsRunning;
    Window m_window;
    // Add other game-specific members here
};

#endif // GAME_H
