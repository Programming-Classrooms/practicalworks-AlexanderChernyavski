#include "FruitTree.hpp"

FruitTree::FruitTree(std::string _title,int32_t _age,Type _type,int32_t cropW,int32_t average):
Tree(_title,_age,_type),
cropWeight(cropW),
averageStorageDuration(average)
{
}

FruitTree::~FruitTree()
{
}


void FruitTree::display(std::ostream& out)
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
    out<<" Crop weight"<<cropWeight<<" Average Storage Duration: "<<averageStorageDuration<<'\n';
}