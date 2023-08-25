#pragma once
#include "raylib.h"
#include "pad.h"
#include "ball.h"

void Init(Pad& player1, Pad& player2, Ball& ball);
void CheckInput(Pad& player1, Pad& player2);
void Drawing(Pad& player1, Pad& player2, Ball& ball);
void Update(Ball& ball, Pad& player1, Pad& player2);
void BallScreenCollision(Ball& ball, Pad& player1, Pad& player2);
void BallPadCollision(Pad player, Ball& ball);
void PadScreenCollision(Pad& player);
void ResetBall(Ball& ball);
void Close();
void RunGame();
