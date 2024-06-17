#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <string>


enum class Type
{
deciduous,
coniferous
};

class Tree
{
protected:
    std::string title;
    int32_t age;
    Type type;

public:
   explicit Tree(std::string,int32_t,Type);

   virtual void display(std::ostream&) = 0;


   std::string GetTitle();
   int32_t GetAge();
};

#endif //Tree_H