#include "Dictionary.hpp"

#include <cstdlib>
#include <fstream>

bool Dictionary::loadFromFile(const std::string& filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        return false;
    }

    words_.clear();
    std::string line;
    while (std::getline(file, line))
    {
        if (!line.empty())
        {
            words_.push_back(line);
        }
    }

    return !words_.empty();
}

void Dictionary::addWord(const std::string& word)
{
    if (!word.empty())
    {
        words_.push_back(word);
    }
}

std::string Dictionary::getRandomWord() const
{
    if (words_.empty())
    {
        return "";
    }

    size_t index = static_cast<size_t>(std::rand()) % words_.size();
    return words_[index];
}

bool Dictionary::isEmpty() const
{
    return words_.empty();
}

size_t Dictionary::size() const
{
    return words_.size();
}
