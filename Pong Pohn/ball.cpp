#include "ball.h"

void DrawBall(Ball& ball)
{
    Vector2 ballPos = { ball.x, ball.y };

    DrawRectangle(ball.x, ball.y, ball.width, ball.heigth, ball.color);
}

//void BallMovement(Ball& ball)
//{
//    ball.x += ball.speedX * GetFrameTime();
//    ball.y += ball.speedY * GetFrameTime(); 
//}