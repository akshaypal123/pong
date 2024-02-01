#include "raylib.h"
#include <iostream>
#include <string>

using namespace std;

const int screenWidth = 1280;
const int screenHeight = 800;
const int paddleWidth = 25;
const int paddleHeight = 120;
const int paddlePadding = 25;


int main() 
{
    
    std::cout << "Starting the game" << std::endl;
    InitWindow(screenWidth, screenHeight, "Pong");
    SetTargetFPS(60);

    while(!WindowShouldClose()) 
    {
        BeginDrawing();
            DrawCircle(0.5*screenWidth, 0.5*screenHeight, 10, WHITE);
            DrawRectangle(paddlePadding, 0.5*screenHeight - 0.5*paddleHeight, paddleWidth, paddleHeight, WHITE);
            DrawRectangle(screenWidth - paddleWidth - paddlePadding, 0.5*screenHeight - 0.5*paddleHeight, paddleWidth, paddleHeight, WHITE);
            DrawLine(0.5*screenWidth, screenHeight, 0.5*screenWidth, 0, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}