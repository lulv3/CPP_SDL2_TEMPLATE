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
    SDL_Window *getWindow() const;

    int getWidth() const;
    int getHeight() const;
    void clear() const;
    void update() const;
    void setBackgroundColor(int r, int g, int b, int a = 255);

private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    int m_width;
    int m_height;

    // background color
    int w_r;
    int w_g;
    int w_b;
};

#endif // WINDOW_H
