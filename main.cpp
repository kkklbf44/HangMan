#include "raylib.h"
#include "Constants.h"
#include "Game.h"
#include "Hangman.h"

int main()
{
    InitWindow(screenWidth, screenHeight, "Hangman");
    SetTargetFPS(60);

    Game game;
    StartGame(game);

    while (!WindowShouldClose())
    {
        bool win = IsWordGuessed(game);
        bool lose = IsGameLost(game);

        if (win || lose)
        {
            if (IsKeyPressed(KEY_ENTER)) StartGame(game);
        }
        else
        {
            int key = GetKeyPressed();

            if (key >= KEY_A && key <= KEY_Z) GuessLetter(game, (char)key);
        }

        BeginDrawing();
        ClearBackground(BLACK);

        DrawHangman(game.mistakes);

        DrawText("HANGMAN", 430, 60, bigFontSize, WHITE);
        DrawText(TextFormat("Mistakes: %d / %d", game.mistakes, maxMistakes), 430, 130, textFontSize, GRAY);
        DrawText("Wrong letters:", 430, 180, textFontSize, GRAY);
        DrawText(GetWrongLetters(game).c_str(), 430, 215, textFontSize, RED);

        std::string masked = GetMaskedWord(game);
        int maskedWidth = MeasureText(masked.c_str(), bigFontSize);
        DrawText(masked.c_str(), screenWidth / 2 - maskedWidth / 2, 440, bigFontSize, WHITE);

        if (win)
        {
            DrawText("YOU WIN!", 430, 280, bigFontSize, GREEN);
            DrawText("Press ENTER to play again", 430, 340, textFontSize, GRAY);
        }

        if (lose)
        {
            DrawText("GAME OVER", 430, 280, bigFontSize, RED);
            DrawText(TextFormat("Word: %s", game.word.c_str()), 430, 340, textFontSize, WHITE);
            DrawText("Press ENTER to play again", 430, 380, textFontSize, GRAY);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
