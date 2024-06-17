#include "TreeContainer.hpp"
#include <algorithm>

bool checkFile(std::ifstream &file)
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
        throw std::runtime_error("File is empty!") ;
    }

    return true;
}
Type stringToType(const std::string& treeType) 
{
   if(treeType == "coniferous")
   {
    return Type::coniferous;
   }
   if(treeType == "deciduous")
   {
    return Type::deciduous;
   }
}

TreeContainer::TreeContainer(/* args */)
{
}

TreeContainer::~TreeContainer()
{
}

void TreeContainer::addTree(Tree* tree)
{
    trees.push_back(tree);
}

void TreeContainer::displayTreeInfo()
{
    for(auto& tree : trees)
    {
       tree->display(std::cout);
    }
}



void TreeContainer::readFromFile(const std::string& filename)
{
   std::ifstream out("src/Files/Trees.txt");
   checkFile(out);
   std::string typeOfTree;
   std::string title;
   int32_t age;
   std::string type;
   size_t amountOfW;
   int32_t cropW;
   int32_t averageStorageD;
     std::string line;
   while (!out.eof())
   {
     
    out>>typeOfTree;
    if(typeOfTree == "ForestTree")
    {
        out>>title>>age;
        out>>type;
        if(type=="coniferous"){
            out>>amountOfW;
            trees.push_back(new ForestTree(title,age,Type::coniferous,amountOfW));
        }
        else if(type == "deciduous")
        {
           out>>amountOfW;
            trees.push_back(new ForestTree(title,age,Type::deciduous,amountOfW));
        }
    }
    else if(typeOfTree == "FruitTree")
    {
        out>>title>>age;
        out>>type;
        if(type=="coniferous"){
            out>>cropW>>averageStorageD;
            trees.push_back(new FruitTree(title,age,Type::coniferous,cropW,averageStorageD));
        }
        else if(type == "deciduous")
        {
           out>>cropW>>averageStorageD;
            trees.push_back(new FruitTree(title,age,Type::deciduous,cropW,averageStorageD));
        }
    }
    line="";
   }
}

void TreeContainer::numberOftreesDeciduousConiferous() const {
    size_t counterTypeOfForTrees = 0;
    size_t counterTypeOfFruitTrees = 0;
    for (const auto& tree : trees) {
        if ( dynamic_cast<ForestTree*>(tree) != nullptr) {
            counterTypeOfForTrees++;
        } else if ( dynamic_cast<FruitTree*>(tree) != nullptr) {
            counterTypeOfFruitTrees++;
        }
    }
    
}

void TreeContainer::numberOftreesForestFruit() const
{
    size_t countConiferous {0},countDeciduous{0};
    Type type;
    for (const Tree* tree : trees) {
        if (type == Type::coniferous) {
            countConiferous++;
        }

        if(type == Type::deciduous)
        {
           countDeciduous++;
        }
    }

    std::cout<<"Number of coniferous trees: "<<countConiferous<<"\n";
    std::cout<<"Number of deciduous trees: "<<countDeciduous<<"\n";
}


void TreeContainer::sortTreesNameAge() {
    std::sort(trees.begin(), trees.end(), [](Tree* first, Tree* second) {
        if (first->GetTitle() == second->GetTitle()) {
            return first->GetAge() > second->GetAge();
        }
        return first->GetTitle() < second->GetTitle();
    });
}