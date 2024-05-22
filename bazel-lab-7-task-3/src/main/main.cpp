#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

bool checkFile(std::ifstream& file) 
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

int main() {
    try{
    std::map<std::string, int> wordCount;
    std::ifstream file("src/Files/file.txt");
    checkFile(file);
    std::string word;

    while (file >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        wordCount[word]++;
    }

    for (const auto& pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }
    }
    
    catch(std::invalid_argument& e)
    {
        std::cerr<<e.what();
    }
    return 0;
}
