#include "Tree.hpp"

Tree::Tree(std::string _title,int32_t _age,Type _type):
title(_title),
age(_age),
type(_type)

{

}


std::string Tree::GetTitle()
{
    return title;
}


int32_t Tree::GetAge()
{
    return age;
}