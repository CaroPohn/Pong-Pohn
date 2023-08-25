#include "pad.h"

void DrawPad(Pad& player)
{
    DrawRectangle(player.x, player.y, player.width, player.heigth, player.color);
}