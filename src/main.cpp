#include "ball.h"
#include "paddles.h"
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
    std::pair <int, int> scores; 
    scores.first = 0;
    scores.second = 0; 


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

    //Initialise CPUPaddle
    CPUPaddle computerPaddle;
    computerPaddle.x = paddlePadding;
    computerPaddle.y = 0.5 * screenHeight - 0.5 * paddleHeight;
    computerPaddle.width = paddleWidth;
    computerPaddle.height = paddleHeight;

    // Initialise player paddle
    Paddle playerPaddle; 
    playerPaddle.x = screenWidth - paddleWidth - paddlePadding; 
    playerPaddle.y = 0.5 * screenHeight - 0.5 * paddleHeight;
    playerPaddle.width = paddleWidth;
    playerPaddle.height = paddleHeight;


    // Game loop
    while(!WindowShouldClose()) 
    {
        BeginDrawing();

            // Update things
            scores = ball.Update(scores.first, scores.second);
            playerPaddle.Update();
            computerPaddle.Update(ball.y);

            // Check for collisions
            if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{playerPaddle.x, playerPaddle.y, playerPaddle.width, playerPaddle.height}))
            {
                ball.speedX *= -1; 
            }
            if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{computerPaddle.x, computerPaddle.y, computerPaddle.width, computerPaddle.height}))
            {
                ball.speedX *= -1; 
            }

            // Draw things 
            ClearBackground(BLACK);
            ball.Draw();
            computerPaddle.Draw();
            playerPaddle.Draw();
            DrawLine(0.5*screenWidth, screenHeight, 0.5*screenWidth, 0, WHITE);
            DrawText(TextFormat("%i", scores.first), screenWidth/4 - 20, 20, 80, WHITE);
            DrawText(TextFormat("%i", scores.second), 3*screenWidth/4 - 20, 20, 80, WHITE);

        EndDrawing();
    }

    // Close game window and exit
    CloseWindow();
    return 0;
}