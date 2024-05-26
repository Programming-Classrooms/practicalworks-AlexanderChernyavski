#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>


bool checkFile(std::ifstream&);
void SpellingAWordByLetter(char, const std::vector<std::string>&) noexcept;
void RemovingAWordByLetter(char,std::vector<std::string>&) noexcept;
void PrintList(std::vector<std::string>) noexcept;