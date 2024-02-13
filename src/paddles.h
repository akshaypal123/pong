#ifndef PADDLES_H
#define PADDLES_H

#include "raylib.h"

class Paddle 
{

    protected:
        void LimitMovement()
        {
            if(y <= 0)
            {
                y = 0; 
            }

            if(y + height >= GetScreenHeight())
            {
                y = GetScreenHeight() - height; 
            }
        }
    public:
        float x, y;
        float width, height;
        int speed = 6; 

        void Draw()
        {
            DrawRectangle(x, y, width, height, WHITE);
        }

        void Update()
        {       
            
            if(IsKeyDown(KEY_UP)) 
            {
                // To move up we want to decrease the y coordinate, hence the minus sign 
                y = y - speed;
            }
            if(IsKeyDown(KEY_DOWN))
            {
                y = y + speed;
            }
            LimitMovement();

        }

};

class CPUPaddle: public Paddle 
{
    public:
    void Update(int ball_y)
    {
        if(y + 0.5*height > ball_y)
        {
            y = y + speed;
        }
        if(y + 0.5*height < ball_y)
        {
            y = y - speed;
        }
        LimitMovement();
    }
};

#endif /* PADDLES_H */