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

bool compareCourse(const Student &a, const Student &b)
{
    if (a.course < b.course)
    {
        return true;
    }
    else if (a.course > b.course)
    {
        return false;
    }
    else
    {
        if (a.group < b.group)
        {
            return true;
        }
        else if (a.group > b.group)
        {
            return false;
        }
        else
        {
            return a.name < b.name;
        }
    }
}