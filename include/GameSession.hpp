#pragma once

#include <set>
#include <string>

// Хранит состояние одной партии: загаданное слово, открытые буквы
// и количество оставшихся попыток.
class GameSession
{
public:
    explicit GameSession(const std::string& wordToGuess, int maxAttempts = 6);

    // Пробует открыть букву. Возвращает true, если буква есть в слове.
    bool guessLetter(char letter);

    // Слово, где открытые буквы показаны, а скрытые заменены на '_'.
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
