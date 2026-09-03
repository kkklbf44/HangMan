#include "GameSession.hpp"

GameSession::GameSession(const std::string& wordToGuess, int maxAttempts)
    : word_(wordToGuess)
    , attemptsLeft_(maxAttempts)
{
}

bool GameSession::guessLetter(char letter)
{
    bool letterFound = word_.find(letter) != std::string::npos;

    bool alreadyGuessed = guessedLetters_.count(letter) > 0;
    guessedLetters_.insert(letter);

    if (!letterFound && !alreadyGuessed)
    {
        attemptsLeft_--;
    }

    return letterFound;
}

std::string GameSession::getMaskedWord() const
{
    std::string masked;
    for (char letter : word_)
    {
        if (guessedLetters_.count(letter) > 0)
        {
            masked += letter;
        }
        else
        {
            masked += '_';
        }
    }
    return masked;
}

bool GameSession::isWordGuessed() const
{
    return getMaskedWord() == word_;
}

bool GameSession::isFailed() const
{
    return attemptsLeft_ <= 0;
}

int GameSession::getAttemptsLeft() const
{
    return attemptsLeft_;
}

const std::set<char>& GameSession::getGuessedLetters() const
{
    return guessedLetters_;
}
