#include "ball.h"
#include "paddle.h"
#include <iostream>
#include <string>

using namespace std;

int main() 
{
    // Define constants 
    const int screenWidth = 1280;
    const int screenHeight = 800;
    const int paddleWidth = 25;
    const int paddleHeight = 120;
    const int paddlePadding = 25;

    // Initialise game window
    std::cout << "Starting the game" << std::endl;
    InitWindow(screenWidth, screenHeight, "Pong");
    SetTargetFPS(60);

    // Initialise ball
    Ball ball;
    ball.x = 0.5 * screenWidth;
    ball.y = 0.5 * screenHeight;
    ball.radius = 10;
    ball.speedX = 7;
    ball.speedY = 7;

    //Initialise paddles
    Paddle leftPaddle;
    leftPaddle.x = paddlePadding;
    leftPaddle.y = 0.5 * screenHeight - 0.5 * paddleHeight;
    leftPaddle.width = paddleWidth;
    leftPaddle.height = paddleHeight;

    Paddle rightPaddle; 
    rightPaddle.x = screenWidth - paddleWidth - paddlePadding; 
    rightPaddle.y = 0.5 * screenHeight - 0.5 * paddleHeight;
    rightPaddle.width = paddleWidth;
    rightPaddle.height = paddleHeight;


    // Game loop
    while(!WindowShouldClose()) 
    {
        BeginDrawing();

            // Update things
            ball.Update();

            // Draw things 
            ClearBackground(BLACK);
            ball.Draw();
            leftPaddle.Draw();
            rightPaddle.Draw();
            DrawLine(0.5*screenWidth, screenHeight, 0.5*screenWidth, 0, WHITE);
        EndDrawing();
    }

    // Close game window and exit
    CloseWindow();
    return 0;
}