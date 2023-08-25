#pragma once
#include "raylib.h"

struct Ball
{
    float x;
    float y;
    float heigth;
    float width;
    Color color;
    float speedX;
    float speedY;
};

void DrawBall(Ball& ball);
//void BallMovement(Ball& ball);

