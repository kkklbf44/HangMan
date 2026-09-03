#pragma once

#include <set>
#include <string>

class GameSession
{
public:
    explicit GameSession(const std::string& wordToGuess, int maxAttempts = 6);

    bool guessLetter(char letter);

    std::string getMaskedWord() const;

    bool isWordGuessed() const;
    bool isFailed() const;

    int getAttemptsLeft() const;
    const std::set<char>& getGuessedLetters() const;

private:
    std::string word_;
    std::set<char> guessedLetters_;
    int attemptsLeft_;
};
