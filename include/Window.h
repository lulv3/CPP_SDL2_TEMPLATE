#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <string>

class Window
{
public:
    Window(const std::string &title, int width, int height);
    ~Window();

    SDL_Renderer *getRenderer() const;
    void clear() const;
    void update() const;

private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    int m_width;
    int m_height;
};

#endif // WINDOW_H
