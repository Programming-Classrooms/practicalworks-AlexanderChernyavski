#ifndef FORESTTREE_HPP
#define FORESTTREE_HPP
#include "src/Tree/Tree.hpp"

class ForestTree:public Tree
{
protected:
    size_t amountOfWood;

public:
    ForestTree(std::string,int32_t,Type, size_t);
    ~ForestTree();
    void display(std::ostream&) override;
};
#endif