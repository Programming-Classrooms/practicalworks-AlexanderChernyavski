#include "../MyString/MyString.hpp"

int main()
{
    // Using the constructor 
    String str1("Hello, "); 
    String str2("World!"); 
 
    // Using the copy constructor 
    String str3 = str1; 
 
    // Using the concatenation operator 
    String str4 = str1 + str2; 
 
    // Using the assignment operator 
    str1 = str2; 
 
    // Using the concatenation and assignment operator 
    str1 += str2; 
 
    // Using the equality operator 
    bool isEqual = (str1 == str2); 
 
    // Using the inequality operator 
    bool isNotEqual = (str1 != str2); 
 
    // Checking if the string is empty 
    bool isEmpty = str1.is_empty(); 
 
    // Getting the string 
    const char* str = str1.getStr(); 
 
    // Getting the length of the string 
    size_t length = str1.getLength(); 
 
    // Using the output stream operator 
    std::cout << str1 << std::endl; 
 
    // Appending a string 
    str1.append(" More text"); 
 
    // Clearing the string 
    str1.clear(); 
 
    // Printing the string 
    str1.print(); 
 
    return 0; 
};
