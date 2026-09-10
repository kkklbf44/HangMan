#include "Hangman.h"

#include "raylib.h"

void DrawHangman(int mistakes)
{
    DrawLine(80, 420, 260, 420, WHITE);
    DrawLine(170, 420, 170, 100, WHITE);
    DrawLine(170, 100, 300, 100, WHITE);
    DrawLine(300, 100, 300, 150, WHITE);

    if (mistakes >= 1) DrawCircleLines(300, 180, 30, WHITE);
    if (mistakes >= 2) DrawLine(300, 210, 300, 310, WHITE);
    if (mistakes >= 3) DrawLine(300, 235, 255, 275, WHITE);
    if (mistakes >= 4) DrawLine(300, 235, 345, 275, WHITE);
    if (mistakes >= 5) DrawLine(300, 310, 265, 375, WHITE);
    if (mistakes >= 6) DrawLine(300, 310, 335, 375, WHITE);
}
