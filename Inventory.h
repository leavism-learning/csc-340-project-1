#pragma once
#include "Box.h"
#include <vector>

using std::string;

class Inventory {
private:
	std::vector<Box> boxVector;
	const string delimiter = ", ";
	const int numWidth = 6;
	const int stringWidth = 20;
	std::vector<string> split(string input);
	template<typename T> void printTable(T t, const int& width);


public:
	Inventory();
	Inventory operator= (const Inventory inv);
	Box getBox(int id);
	void putBox(Box box);
	void display();
	void save();
	void load();

};

