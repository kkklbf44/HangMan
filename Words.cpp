#include "Words.h"

#include "raylib.h"

const int wordCount = 19;

const std::string words[wordCount] =
{
    "PROGRAM",
    "COMPUTER",
    "KEYBOARD",
    "MONITOR",
    "FUNCTION",
    "VARIABLE",
    "MIREA",
    "RTU",
    "VEGA",
    "TANYA",
    "ZHUKOVA",
    "SIXSEVEN",
    "CHERNOUSOV",
    "COMPILER",
    "POINTER",
    "LIBRARY",
    "WINDOW",
    "STUDENT",
    "GAME"
};

std::string GetRandomWord()
{
    return words[GetRandomValue(0, wordCount - 1)];
}
