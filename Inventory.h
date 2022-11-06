#pragma once
#include "Box.h"
#include <vector>

using std::string;

class Inventory {
private:
	std::vector<Box> boxVector;
	std::vector<string> split(string input);
	const string delimiter = ", ";

public:
	Inventory();
	Inventory operator= (const Inventory inv);
	Box getBox(int id);
	void putBox(Box box);
	string display();
	void save();
	void load();
};

