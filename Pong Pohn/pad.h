#pragma once
#include "raylib.h"

struct Pad
{
    float x;
    float y;
    float width;
    float heigth;
    Color color;
    float speedY;
    int points;
};

void DrawPad(Pad& player);