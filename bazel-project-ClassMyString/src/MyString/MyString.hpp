#ifndef MYSTRING_HPP
#define MYSTRING_HPP
#include <iostream>
#include <cstring>

class String
{
private:
	size_t len;
	char* str;
public:
	String(const char* = nullptr);
	String(const String&);

	String& operator+(const String&);
	String& operator = ( const String&);
	String& operator += (const String&);
	bool operator == (const String&) const;
	bool operator != (const String&) const;

	bool is_empty() const;
	const char* getStr() const;
	size_t getLength() const;


	void append(const char* s);
	void clear();
	void print() const;
	friend std::ostream& operator << (std::ostream&, const String&);

	~String();
};
#endif