#include "Game.h"

Game::Game() : m_window("SDL Game", 800, 600), mIsRunning(false)
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
    SDL_Quit();
}

void Game::run()
{
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
    }
}

void Game::update()
{
    // Update game logic
}

void Game::render()
{
    // Clear the screen
    SDL_SetRenderDrawColor(m_window.getRenderer(), 0, 0, 0, 255);
    SDL_RenderClear(m_window.getRenderer());

    // Render game objects here

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
