#include "functions.hpp"

bool checkFile(std::ifstream &file)
{
    if (!file.good())
    {
        throw std::invalid_argument("File not found ! ");
    }

    if (!file)
    {
        throw std::ios_base::failure("Error reading file!");
    }

    if (file.peek() == EOF)
    {
        throw std::runtime_error("File is empty!");
    }

    return true;
}

void SpellingAWordByLetter(char letter, const std::vector<std::string> &list) noexcept
{
    for (const auto &word : list)
    {
        if (word[0] == letter)
        {
            std::cout << word << std::endl;
        }
    }
}

void RemovingAWordByLetter(char letter, std::vector<std::string> &list) noexcept
{
    list.erase(
        std::remove_if(list.begin(), list.end(), [letter](const std::string &word)
                       { return word[0] == letter; }),
        list.end());
}

void PrintList(std::vector<std::string> list) noexcept
{
    for (const auto &word : list)
    {
        std::cout << word << '\n';
    }
}