#include "raylib.h"

class Paddle 
{
    public:
        float x, y;
        float width, height;
        int speed; 

        void Draw()
        {
            DrawRectangle(x, y, width, height, WHITE);
        }

};