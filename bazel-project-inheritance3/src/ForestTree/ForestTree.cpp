#include "ForestTree.hpp"

ForestTree::ForestTree(std::string _title, int32_t _age, Type _type,size_t _amount):
Tree(_title,_age,_type),
amountOfWood(_amount)
{
}

ForestTree::~ForestTree()
{
}

 void ForestTree::display(std::ostream& out)
{
    out<<"Title: "<<title<<" Age of wood: "<<age;
    switch (type)
    {
    case Type::deciduous:
        out<<" Type: deciduous";
        break;
    case Type::coniferous:
    out<<" Type: coniferous";
    default:
        break;
    }
    out<<" Amount of wood"<<amountOfWood<<'\n';
}