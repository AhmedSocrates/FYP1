#pragma once
#include <GLFW/glfw3.h>
#include <vector>
#include <memory>
#include <string>
#include "Entity.h" // Include our new class

class Engine {
public:
    Engine(int width, int height, const char* title);
    ~Engine();

    bool Initialize();
    void Run();
    void Shutdown();

    // NEW: Memory-safe entity management
    void SpawnEntity(std::string name, float x, float y, float z);
    void ClearEntities();

private:
    GLFWwindow* window;
    int windowWidth;
    int windowHeight;
    const char* windowTitle;

    // NEW: A dynamic list that automatically manages memory for our entities
    std::vector<std::unique_ptr<Entity>> entities;
};