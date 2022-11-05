#pragma once
#include <iostream>

class Box {
private:
	int id;
	std::string description;
	int weight;

public:
	Box();
	Box(int id, std::string description, int weight);
	int getId();
	std::string getDescription();
	int getWeight();
};