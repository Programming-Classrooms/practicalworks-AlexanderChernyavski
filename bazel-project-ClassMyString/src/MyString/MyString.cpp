#define _CRT_SECURE_NO_WARNINGS
#include "MyString.hpp"


String::String(const char* ptr) : len(strlen(ptr)), str(new char[len + 1])
{
	strcpy(str, ptr);
}

String::String(const String& t) : len(strlen(t.str)), str(new char[len + 1])
{
	strcpy(str, t.str);
}

String& String::operator+(const String& rhs)
{
	size_t newLen = len + rhs.len;
	char* newStr = new char[newLen + 1];
	strcpy(newStr, str);
	strcat(newStr, rhs.str);
	delete[] str;
	str = newStr;
	len = newLen;
	return *this;
}

String& String::operator = ( const String& t)
{
	len = std::move(t.len);
	delete[] str;
	str = new char[len + 1];
	strcpy(str, t.str);
	return (*this);
}

String& String::operator += (const String& t)
{
	size_t newLen = len + t.len;
	char* newStr = new char[newLen + 1];
	strcpy(newStr, str);
	strcat(newStr, t.str);
	delete[] str;
	str = newStr;
	len = newLen;
	return *this;
}

bool String::operator == (const String& t) const
{
	return !strcmp(str, t.str);
}

bool String::operator != (const String& t) const
{
	return !(operator == (t));
}

bool String::is_empty() const
{
	return str == 0 || str[0] == '\0';
}

const char* String::getStr() const
{
	return str;
}

size_t String::getLength() const
{
	return len;
}

std::ostream& operator << (std::ostream& os, const String& s)
{
	os << s.str;
	return os;
}

// Метод для добавления строки
void String::append(const char* rhs)
{
	size_t newLength = len + strlen(rhs);
        char* newStr = new char[newLength + 1];
        strcpy(newStr, str);
        strcat(newStr, rhs);

        delete[] str;
        str = newStr;
        len = newLength;
}

// Метод для очистки строки
    void String::clear() {
        delete[] str;
        str = nullptr;
        len = 0;
    }


String::~String()
{
	len = 0;
	delete[] str;
	str = 0;
}


// Метод для вывода строки
    void String::print() const {
        std::cout << str;
    }