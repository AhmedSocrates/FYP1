#include "Engine.h"
#include <iostream>

Engine::Engine(int width, int height, const char* title) 
    : windowWidth(width), windowHeight(height), windowTitle(title), window(nullptr) {}

Engine::~Engine() {
    // When the engine is destroyed, ensure we shutdown cleanly
    Shutdown();
}

bool Engine::Initialize() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);
    std::cout << "Engine Initialized Successfully!" << std::endl;
    return true;
}

void Engine::Run() {
    std::cout << "Starting Engine Loop..." << std::endl;
    
    // Setup time tracking before the loop starts
    float lastTime = glfwGetTime();

    while (!glfwWindowShouldClose(window)) {
        // 1. Calculate Delta Time (Time elapsed since last frame)
        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        // 2. Clear the screen
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 3. Update & Render Loop
        for (const auto& entity : entities) {
            
            // LOGIC: Update the entity's position using our safe Delta Time
            entity->Update(deltaTime);
            
            // RENDER: Draw the container at the newly updated coordinates
            glPushMatrix();
            glTranslatef(entity->GetX() / 20.0f, entity->GetY() / 20.0f, 0.0f); 

            glBegin(GL_QUADS);
                glColor3f(0.0f, 0.8f, 0.5f); // AI Neon Green
                glVertex2f(-0.05f, -0.05f);
                glVertex2f( 0.05f, -0.05f);
                glVertex2f( 0.05f,  0.05f);
                glVertex2f(-0.05f,  0.05f);
            glEnd();
            
            glPopMatrix();
        }

        // 4. Push the painted frame to the screen
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Engine::Shutdown() {
    // 1. Safely free all our entity memory BEFORE closing the window
    ClearEntities();

    // 2. Destroy the window and terminate OpenGL
    if (window) {
        glfwDestroyWindow(window);
        window = nullptr;
    }
    glfwTerminate();
    std::cout << "Engine Shutdown cleanly." << std::endl;
}

void Engine::SpawnEntity(std::string name, float x, float y, float z) {
    // Safely allocate memory on the Heap and assign it to our smart pointer vector
    entities.push_back(std::make_unique<Entity>(name, x, y, z));
}

void Engine::ClearEntities() {
    // Clearing the vector automatically triggers the destructor of every unique_ptr inside it
    entities.clear(); 
}