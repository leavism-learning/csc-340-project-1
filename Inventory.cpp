#include "Inventory.h"
#include "Box.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using std::string;
using std::to_string;
using std::ofstream;
using std::ios;
using std::ifstream;

// Default constructor
Inventory::Inventory() {}

Inventory Inventory::operator =(const Inventory inv) {
	this->boxVector = inv.boxVector;
	return *this;
}

void Inventory::putBox(Box input_box) {
	boxVector.push_back(input_box);
}

Box Inventory::getBox(int id) {
	Box result;

	// Iterate through vector of Boxes to find the param id
	for (int index = 0; index < boxVector.size(); index++) {
		if (boxVector.at(index).getId() == id) {
			result = boxVector.at(index);
			index = boxVector.size();
		}
	}
	return result;
}

string Inventory::display() {
	string result = "";
	string spaces = "      ";

	for (int index = 0; index < boxVector.size(); index++) {
		Box current = boxVector.at(index);
		result +=  to_string(current.getId()) + spaces 
			+ current.getDescription() + spaces
			+ to_string(current.getWeight()) + "\n";
	}

	return result;
}

void Inventory::save() {
	ofstream file;
	// TODO Change write permissions
	file.open("inventory.txt", ios::out | ios::app);

	Box first = boxVector.at(0);

	if (file.is_open()) {
		for (int index = 0; index < boxVector.size(); index++) {
			Box current = boxVector.at(index);
			file << current.getId() << this->delimiter
				<< current.getDescription() << this->delimiter
				<< current.getWeight() << std::endl;
		}
	}
	file.close();
}

void Inventory::load() {
	if (!boxVector.empty()) {
		return;
	}

	ifstream file;
	file.open("inventory.txt", ios::in);
	string line;
	Box newBox;
	std::vector<string> values;

	if (file.is_open()) {
		while (getline(file, line)) {
			values =  this->split(line);
			newBox = Box(stoi(values.at(0)), values.at(1), stoi(values.at(2)));
			this->putBox(newBox);
		}
	}
	file.close();
}

// Helper split() function to keep load() clean
std::vector<string> Inventory::split(string input) {
	std::vector<string> result;

	int last = 0;
	int next = 0;
	while ((next = input.find(this->delimiter, last)) != string::npos) { 
		result.push_back(input.substr(last, next - last));
		last = next + 1;
	}
	result.push_back(input.substr(last));
	return result;
}
