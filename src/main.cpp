#include "Engine.h"

int main() {
    Engine agenticEngine(800, 600, "Agentic Engine - AI Viewport");

    if (agenticEngine.Initialize()) {
        
        // Spawn some entities to test heap allocation
        agenticEngine.SpawnEntity("Tent_1", 10.0f, 0.0f, 5.0f);
        agenticEngine.SpawnEntity("Campfire", 12.0f, 0.0f, 6.0f);
        agenticEngine.SpawnEntity("Tree_Pine", -5.0f, 0.0f, 10.0f);

        // Run the engine (this blocks until you close the window)
        agenticEngine.Run();
    }

    // When agenticEngine goes out of scope here, its destructor runs, 
    // which automatically deletes the window AND safely frees all entity memory!
    return 0;
}