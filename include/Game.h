#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "ImGuiExample.h"
#include <memory>

static int FPS = 120;

class Game
{
public:
    Game();
    ~Game();

    void init();
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

    // ImGui-Example
    std::unique_ptr<ImGuiExample> m_imgui;
    // Add other game-specific members here
};

#endif // GAME_H
