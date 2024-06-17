#include<iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <string>
#include <iterator>


bool checkFile(std::ofstream& file)
{
	if (!file.good())
	{
		throw std::invalid_argument("File not found ! ");
	}

	if (!file)
	{
		throw std::ios_base::failure("Error reading file!");
	}

	return true;
}

int main()
{
	try {
		std::set<std::string> fisherman1{ "lococ","fugu","kosatka" };
		std::set<std::string> fisherman2{ "okyn","lococ","karas","ryba" };
		std::set<std::string> fisherman3{ "ryba","karas","pirania" };
		std::set<std::string> fishInTheLake{ "akyla","lococ","fugu","kosatka" ,"okyn","ryba","karas","pirania","zolotaya_rybka","govoryachaya_ryba" };
		std::set<std::string> caughtFish;
		std::set<std::string> NotCaughtFish;
		std::set_union(fisherman1.begin(), fisherman1.end(), fisherman2.begin(), fisherman2.end(), std::inserter(caughtFish, caughtFish.begin()));
		std::set_union(caughtFish.begin(), caughtFish.end(), fisherman3.begin(), fisherman3.end(), std::inserter(caughtFish, caughtFish.begin()));
		std::set_symmetric_difference(caughtFish.begin(), caughtFish.end(), fishInTheLake.begin(), fishInTheLake.end(), std::inserter(NotCaughtFish, NotCaughtFish.begin()));
		std::ofstream fin("src/Files/ProRyb.txt");
		checkFile(fin);
		std::ostream_iterator<std::string> output(fin, "\t");
		fin << "Fisherman1:" << '\n';
		std::copy(fisherman1.begin(), fisherman1.end(), output);
		fin << '\n' << "Fisherman2:" << '\n';
		std::copy(fisherman2.begin(), fisherman2.end(), output);
		fin << '\n' << "Fisherman3:" << '\n';
		std::copy(fisherman3.begin(), fisherman3.end(), output);
		fin << '\n' << "All fish int the lake" << '\n';
		std::copy(fishInTheLake.begin(), fishInTheLake.end(), output);
		fin << '\n' << "Fish not caught" << '\n';
		std::copy(NotCaughtFish.begin(), NotCaughtFish.end(), output);
		fin.close();
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << e.what();
	}
	return 0;
}