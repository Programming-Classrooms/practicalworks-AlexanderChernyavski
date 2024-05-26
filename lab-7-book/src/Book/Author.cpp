#include "Book.hpp"


bool Book::Author::operator==(const Author &other) const
{
    return surname == other.surname && name == other.name && fathername == other.fathername;
}

bool Book::Author::operator<(const Author &other) const
{
    if (surname != other.surname)
        return surname < other.surname;
    if (name != other.name)
        return name < other.name;
    return fathername < other.fathername;
}