#pragma once

#include <string>
#include <vector>

// Хранит список слов для игры и умеет выбирать случайное слово.
class Dictionary
{
public:
    Dictionary() = default;

    // Загружает слова из текстового файла (одно слово на строку).
    // Возвращает true, если удалось загрузить хотя бы одно слово.
    bool loadFromFile(const std::string& filePath);

    // Добавляет слово в словарь напрямую (например, для тестов).
    void addWord(const std::string& word);

    // Возвращает случайное слово из словаря.
    std::string getRandomWord() const;

    bool isEmpty() const;
    size_t size() const;

private:
    std::vector<std::string> words_;
};
