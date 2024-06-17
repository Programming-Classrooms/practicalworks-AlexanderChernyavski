#ifndef FRUITTREE_HPP
#define FRUITTREE_HPP
#include "src/Tree/Tree.hpp"

class FruitTree:public Tree
{
private:
   int32_t cropWeight;
   int32_t averageStorageDuration;
public:
    FruitTree(std::string,int32_t,Type,int32_t,int32_t);
    ~FruitTree();

    void display(std::ostream&) override;
};


#endif