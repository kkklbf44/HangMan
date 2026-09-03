#pragma once

#include <string>
#include <vector>

class Dictionary
{
public:
    Dictionary() = default;

    bool loadFromFile(const std::string& filePath);

    void addWord(const std::string& word);

    std::string getRandomWord() const;

    bool isEmpty() const;
    size_t size() const;

private:
    std::vector<std::string> words_;
};
