#pragma once

#include <string>

struct Game
{
    std::string word;
    std::string usedLetters;
    int mistakes;
};

void StartGame(Game& game);

bool Contains(const std::string& text, char letter);

void GuessLetter(Game& game, char letter);

bool IsWordGuessed(const Game& game);

bool IsGameLost(const Game& game);

std::string GetMaskedWord(const Game& game);

std::string GetWrongLetters(const Game& game);
