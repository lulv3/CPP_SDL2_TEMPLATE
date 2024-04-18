#include "ImGuiExample.h"

ImGuiExample::ImGuiExample() : m_checkbox(false), m_slider(0.0f), guiSize(ImVec2(385, 445)), width(380), height(180) {}

ImGuiExample::~ImGuiExample() {}

void ImGuiExample::Init(SDL_Window *window, SDL_Renderer *renderer)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);

    ImGui::StyleColorsDark();
}

void ImGuiExample::Shutdown()
{
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}

void ImGuiExample::handleEvents(SDL_Event e)
{
    ImGui_ImplSDL2_ProcessEvent(&e);
}

void ImGuiExample::render()
{
    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
    ImGui::Begin("ImGui Example");

    // Hier könntest du die hinzugefügten ImGui-Elemente rendern
    // Beispiel:

    ImGui::Text("Width: %d, Height: %d", width, height);
    ImGui::Button("Example Button", ImVec2(110, 25));
    ImGui::Checkbox("ImGui Sizable?", &m_checkbox);
    ImGui::SliderFloat("Example Slider", &m_slider, 0.0f, 1.0f);
    ImGui::ColorPicker3("Background Color", (float *)&color);
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    if (!m_checkbox)
    {
        ImGui::SetWindowSize(ImVec2(385, 445));
    }

    getSize();

    ImGui::End();
    ImGui::Render();

    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
}
void ImGuiExample::getSize()
{
    guiSize = ImGui::GetWindowSize();
    width = static_cast<int>(guiSize.x);
    height = static_cast<int>(guiSize.y);
}
int ImGuiExample::getRColor()
{
    return (int)(color.x * 255.0f);
}
int ImGuiExample::getGColor()
{
    return (int)(color.y * 255.0f);
}
int ImGuiExample::getBColor()
{
    return (int)(color.z * 255.0f);
}
