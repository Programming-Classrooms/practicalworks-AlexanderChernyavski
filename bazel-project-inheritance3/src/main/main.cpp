#include "src/Tree/Tree.hpp"
#include "src/ForestTree/ForestTree.hpp"
#include "src/TreeContainer/TreeContainer.hpp"
#include "src/FruitTree/FruitTree.hpp"



int main() {
	try {
		TreeContainer trees;
		trees.readFromFile("src/Files/Trees.txt");
		trees.displayTreeInfo();
		 
	}

	catch (std::invalid_argument e)
	{
		std::cerr << e.what();
	}
	return 0;
}
