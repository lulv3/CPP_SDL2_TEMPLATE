#include "Window.h"

Window::Window(const std::string &title, int width, int height)
    : m_width(width), m_height(height), w_r(0), w_g(0), w_b(0)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        exit(-1);
    }

    // Create window
    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!m_window)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        SDL_Quit();
        exit(-1);
    }

    // Create renderer
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!m_renderer)
    {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        exit(-1);
    }
}

Window::~Window()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

SDL_Renderer *Window::getRenderer() const
{
    return m_renderer;
}
SDL_Window *Window::getWindow() const
{
    return m_window;
}

int Window::getWidth() const
{
    int width, height;
    SDL_GetWindowSize(m_window, &width, &height);
    return width;
}

int Window::getHeight() const
{
    int width, height;
    SDL_GetWindowSize(m_window, &width, &height);
    return height;
}
void Window::setBackgroundColor(int r, int g, int b, int a)
{
    w_r = r;
    w_g = g;
    w_b = b;
}
void Window::clear() const
{
    SDL_SetRenderDrawColor(m_renderer, w_r, w_g, w_b, 255);
    SDL_RenderClear(m_renderer);
}

void Window::update() const
{
    SDL_RenderPresent(m_renderer);
}
