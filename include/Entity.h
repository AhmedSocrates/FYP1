#pragma once
#include <string>
#include <iostream>

class Entity {
public:
    // We added a simple default velocity to make them drift
    Entity(std::string name, float x, float y, float z) 
        : name(name), posX(x), posY(y), posZ(z), velX(2.0f), velY(1.0f) {
        std::cout << "[MEMORY ALLOCATED] Entity Created: " << name << "\n";
    }

    ~Entity() {
        std::cout << "[MEMORY FREED] Entity Destroyed: " << name << "\n";
    }

    // NEW: The logic loop for the entity
    void Update(float deltaTime) {
        // Move the entity based on time, not frame rate!
        posX += velX * deltaTime;
        posY += velY * deltaTime;

        // Simple boundary check: if it drifts too far right, wrap it back to the left
        if (posX > 20.0f) posX = -20.0f;
        if (posY > 15.0f) posY = -15.0f;
    }

    std::string GetName() const { return name; }
    float GetX() const { return posX; }
    float GetY() const { return posY; }
    float GetZ() const { return posZ; }

private:
    std::string name;
    float posX, posY, posZ;
    float velX, velY; // NEW: Speed of the entity
};