#include "Game.h"
#include "Words.h"
#include "Constants.h"

void StartGame(Game& game)
{
    game.word = GetRandomWord();
    game.usedLetters = "";
    game.mistakes = 0;
}

bool Contains(const std::string& text, char letter)
{
    int length = text.length();

    for (int i = 0; i < length; i++)
    {
        if (text[i] == letter) return true;
    }

    return false;
}

void GuessLetter(Game& game, char letter)
{
    if (Contains(game.usedLetters, letter)) return;

    game.usedLetters += letter;

    if (!Contains(game.word, letter)) game.mistakes++;
}

bool IsWordGuessed(const Game& game)
{
    int length = game.word.length();

    for (int i = 0; i < length; i++)
    {
        if (!Contains(game.usedLetters, game.word[i])) return false;
    }

    return true;
}

bool IsGameLost(const Game& game)
{
    return game.mistakes >= maxMistakes;
}

std::string GetMaskedWord(const Game& game)
{
    std::string result = "";
    int length = game.word.length();

    for (int i = 0; i < length; i++)
    {
        if (Contains(game.usedLetters, game.word[i])) result += game.word[i];
        else result += '_';

        result += ' ';
    }

    return result;
}

std::string GetWrongLetters(const Game& game)
{
    std::string result = "";
    int length = game.usedLetters.length();

    for (int i = 0; i < length; i++)
    {
        char letter = game.usedLetters[i];

        if (!Contains(game.word, letter))
        {
            result += letter;
            result += ' ';
        }
    }

    return result;
}
