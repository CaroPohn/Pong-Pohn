#include "raylib.h"
#include "game.h"
#include <iostream>

using namespace std;

void Init(Pad& player1, Pad& player2, Ball& ball)
{
    const int screenWidth = 1200;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "Pong Pohn");

    player1.x = (float)screenWidth / 8 - 60;
    player1.y = 100.0f;
    player1.width = 15.0f;
    player1.heigth = 110.0f;
    player1.color = WHITE;
    player1.speedY = 800.0f;
    player1.points = 0;

    player2.x = (float)screenWidth / 8 * 7 + 60;
    player2.y = 100.0f;
    player2.width = 15.0f;
    player2.heigth = 110.0f;
    player2.color = WHITE;
    player2.speedY = 800.0f;
    player2.points = 0;

    ball.x = (float)screenWidth / 2;
    ball.y = (float)screenHeight / 2;
    ball.heigth = 24;
    ball.width = 24;
    ball.color = PINK;
    ball.speedX = 400.0f;
    ball.speedY = 400.0f;
}

void CheckInput(Pad& player1, Pad& player2)
{
    if (IsKeyDown(KEY_W)) player1.y -= player1.speedY * GetFrameTime();
    if (IsKeyDown(KEY_S)) player1.y += player1.speedY * GetFrameTime();

    if (IsKeyDown(KEY_UP)) player2.y -= player2.speedY * GetFrameTime();
    if (IsKeyDown(KEY_DOWN)) player2.y += player2.speedY * GetFrameTime();
}

void Update(Ball& ball, Pad& player1, Pad& player2)
{
    ball.x += ball.speedX * GetFrameTime();
    ball.y += ball.speedY * GetFrameTime();

    BallScreenCollision(ball, player1, player2);
    BallPadCollision(player1, ball);
    BallPadCollision(player2, ball);
    PadScreenCollision(player1);
    PadScreenCollision(player2);
}

void Drawing(Pad& player1, Pad& player2, Ball& ball)
{
    BeginDrawing();

    ClearBackground(BLACK);

    DrawRectangle(600, 0, 3, 900, WHITE);
    DrawPad(player1);
    DrawPad(player2);

    DrawBall(ball);

    DrawText(TextFormat("%i", player1.points), GetScreenWidth() / 4 - 20, 20, 80, WHITE);
    DrawText(TextFormat("%i", player2.points), 3 * GetScreenWidth() / 4 - 20, 20, 80, WHITE);

    EndDrawing();
}

void BallPadCollision(Pad player, Ball& ball) // Separar la colision del movimiento 
{
    bool collision = false;

    float playerRightEdge = player.x + player.width;
    float playerLeftEdge = player.x; 
    float playerTopEdge = player.y + player.heigth;
    float playerBottomEdge = player.y;

    float ballRightEdge = ball.x + ball.width;
    float ballLeftEdge = ball.x;
    float ballTopEdge = ball.y + ball.heigth; 
    float ballBottomEdge = ball.y; 
    
    //antes iria un if que sea t o f respecto a si hay colision o no
    if (playerRightEdge >= ballLeftEdge && //se puede separar en varios if 
        playerLeftEdge <= ballRightEdge &&
        playerTopEdge >= ballBottomEdge &&
        playerBottomEdge <= ballTopEdge)
    {

        ball.speedX *= -1;
    }
}

void BallScreenCollision(Ball& ball, Pad& player1, Pad& player2) 
{
    if (ball.y + ball.heigth / 2 >= GetScreenHeight() || ball.y - ball.heigth / 2 <= 0)
    {
        ball.speedY *= -1;
    }

    if (ball.x + ball.width / 2 >= GetScreenWidth())
    {
        player1.points++;
        ResetBall(ball);
    }
    
    if (ball.x - ball.width / 2 <= 0)
    {
        player2.points++;
        ResetBall(ball);
    }
}

void PadScreenCollision(Pad& player)
{
    if (player.y <= 0)
    {
        player.y = 0;
    }

    if (player.y + player.heigth >= GetScreenHeight())
    {
        player.y = GetScreenHeight() - player.heigth;
    }
}

void ResetBall(Ball& ball)
{
    ball.x = GetScreenWidth() / 2;
    ball.y = GetScreenHeight() / 2;
}

void Close()
{
    CloseWindow();
}

void RunGame()
{
    Pad player1;
    Pad player2;
    Ball ball;

    //Inicializacion
    Init(player1, player2, ball); 

    while (!WindowShouldClose()) 
    {
        //Input
        CheckInput(player1, player2); 

        //Update
        Update(ball, player1, player2);

        //Dibujo
        Drawing(player1, player2, ball); 

    }
    //Cierre
    Close();
}