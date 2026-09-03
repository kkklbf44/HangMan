#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Dictionary.hpp"
#include "GameSession.hpp"

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Dictionary dictionary;
    if (!dictionary.loadFromFile("data/words.txt"))
    {
        std::cerr << "Failed to load word list from data/words.txt\n";
        return 1;
    }

    GameSession session(dictionary.getRandomWord());

    std::cout << "Welcome to Hangman!\n";

    while (!session.isWordGuessed() && !session.isFailed())
    {
        std::cout << "\nWord: " << session.getMaskedWord() << '\n';
        std::cout << "Attempts left: " << session.getAttemptsLeft() << '\n';
        std::cout << "Guess a letter: ";

        char letter = '\0';
        std::cin >> letter;
        letter = static_cast<char>(std::tolower(static_cast<unsigned char>(letter)));

        if (session.guessLetter(letter))
        {
            std::cout << "Correct!\n";
        }
        else
        {
            std::cout << "Wrong.\n";
        }
    }

    if (session.isWordGuessed())
    {
        std::cout << "\nYou win! The word was: " << session.getMaskedWord() << '\n';
    }
    else
    {
        std::cout << "\nYou lose!\n";
    }

    return 0;
}
