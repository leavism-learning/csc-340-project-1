// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Box.h"
#include "Inventory.h"

using std::cout;
using std::cin;

int main()
{
    Inventory test = Inventory();

    test.load();
    cout << test.display();


    return 0;
}
