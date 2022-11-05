#include "Box.h"

Box::Box() {}

Box::Box(int id, std::string description, int weight) {
	this->id = id;
	this->description = description;
	this->weight = weight;
};

int Box::getId() {
	return this->id;
}

std::string Box::getDescription() {
	return this->description;
}

int Box::getWeight() {
	return this->weight;
}
