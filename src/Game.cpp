#include "Game.h"

Game::Game() : m_window("SDL Game", 800, 600), mIsRunning(false), m_imgui(std::unique_ptr<ImGuiExample>(new ImGuiExample()))
{
    // Initialize game
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        mIsRunning = false;
    }

    mIsRunning = true;
}

Game::~Game()
{
    // Clean up game
    m_imgui->Shutdown(); // Shutdown ImGui-Example
    SDL_Quit();
}

void Game::init()
{
    // init ImGui-Example
    m_imgui->Init(m_window.getWindow(), m_window.getRenderer());
}
void Game::run()
{
    init();
    // Main loop
    while (mIsRunning)
    {
        handleEvents();
        update();
        render();

        // Update screen
        m_window.update();
        SDL_Delay(1000 / FPS);
    }
}

void Game::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            mIsRunning = false;
            break;

        case SDL_KEYDOWN:
            handleKeyDownEvent(event.key);
            break;
        case SDL_KEYUP:
            handleKeyUpEvent(event.key);
            break;
            // Add more event handling here if needed
        }
        // Handle ImGui events
        m_imgui->handleEvents(event);

        // Update Background Color
        int r = m_imgui->getRColor();
        int g = m_imgui->getGColor();
        int b = m_imgui->getBColor();

        m_window.setBackgroundColor(r, g, b);
    }
}

void Game::update()
{
    // Update game logic
}

void Game::render()
{
    // Clear the screen
    m_window.clear();

    // Render game objects here

    // Render ImGui-Example
    m_imgui->render();

    // Update the screen
    SDL_RenderPresent(m_window.getRenderer());
}

void Game::handleKeyDownEvent(const SDL_KeyboardEvent &keyEvent)
{
    // Handle key down events
}

void Game::handleKeyUpEvent(const SDL_KeyboardEvent &keyEvent)
{
    // Handle key up events
}
