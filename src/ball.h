#include "raylib.h"
#include <utility>

class Ball 
{
    public:
        float x, y;
        int speedX, speedY;
        int radius;
    
    void Draw() 
    {
        DrawCircle(x, y, radius, WHITE);
    }

    std::pair<int, int> Update(int cpuScore, int playerScore)
    {
        x += speedX;
        y += speedY;

        if (y + radius >= GetScreenHeight() || y - radius <= 0)
        {
            speedY = -1*speedY;
        }
        if (x + radius >= GetScreenWidth())
        {
            cpuScore++;
            ResetBall();
        }
        
        if(x - radius <= 0) 
        {
            playerScore++;
            ResetBall();
        }

        return std::make_pair(cpuScore, playerScore);
    }

    void ResetBall()
    {
        x = GetScreenWidth()*0.5;
        y = GetScreenHeight()*0.5; 

        int speedChoices[2] = {-1,1};
        speedX *= speedChoices[GetRandomValue(0,1)];
        speedY *= speedChoices[GetRandomValue(0,1)];
    }
};