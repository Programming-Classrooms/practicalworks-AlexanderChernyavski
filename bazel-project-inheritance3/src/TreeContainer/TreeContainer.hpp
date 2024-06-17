#ifndef TREECONTAINER_HPP
#define TREECONTAINER_HPP
#include "src/Tree/Tree.hpp"
#include "src/ForestTree/ForestTree.hpp"
#include "src/FruitTree/FruitTree.hpp"
#include <vector>
#include <fstream>


class TreeContainer
{
private:
std::vector<Tree*> trees;
public:

    TreeContainer(/* args */);
    ~TreeContainer();

    void addTree(Tree*);
    void displayTreeInfo();
    void readFromFile(const std::string&);
    void numberOftreesDeciduousConiferous() const;
    void numberOftreesForestFruit() const;
    void sortTreesNameAge();
};


#endif