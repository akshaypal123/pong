#include "raylib.h"
#include <iostream>
#include <string>

using namespace std;

const int screenWidth = 1280;
const int screenHeight = 800;

int main() {
    std::cout << "Starting the game" << std::endl;
    InitWindow(screenWidth, screenHeight, "Pong");

    while(!WindowShouldClose()) {
        BeginDrawing();
            DrawText("Hello World!", 0.5*screenWidth, 0.5*screenHeight, 50, RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}