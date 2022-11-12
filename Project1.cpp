// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Box.h"
#include "Inventory.h"

using std::cout;
using std::cin;
using std::endl;


string convertToString(char* a)
{
    string s(a);
    return s;
}

int main()
{
    int action;
    bool exit = false;

    int id, quantity;
    string description;

    Inventory inventory;
    while (!exit) {
        cout << "Hello, welcome to the inventory system. Respond with the number to perform the action:" << endl;
        cout << "1 - Load existing inventory." << endl;
        cout << "2 - Create new inventory." << endl;
        cout << "3 - Add a box to an inventory. Creates new inventory if one doesn't exist." << endl;
        cout << "4 - Display current inventory and the boxes in it." << endl;
        cout << "5 - Save inventory to hard drive. Overwrites any existing saved inventory." << endl;
        cout << "0 - Exit" << endl;
        cout << endl;
        cout << "Action: ";
        cin >> action;

        // In the case that input isn't a number
        while (!cin) {
            cin.clear();
            cin.ignore();
            cout << "You didn't enter a valid action" << endl;
            cout << endl;
            cout << "Action: ";
            cin >> action;
        }

        switch (action) {
        case 1:
            inventory.load();
            cout << "Current inventory loaded: " << endl;
            cout << endl;
            inventory.display();
            break;
        case 2:
            inventory = Inventory();
            cout << "New inventory created." << endl;
            cout << endl;
            break;
        case 3:
            cout << "Let's make a new box" << endl;

            cout << "Set ID: ";
            cin >> id;

            while (!cin) {
                cin.clear();
                cin.ignore();
                cout << "You didn't enter a ID" << endl;
                cout << endl;
                cout << "ID: ";
                cin >> id;
            }

            cin.ignore();

            cout << "Set description: ";
            std::getline(cin, description);

            cout << "Set quantity: ";
            cin >> quantity;
            while (!cin) {
                cin.clear();
                cin.ignore();
                cout << "You didn't enter a quantity" << endl;
                cout << endl;
                cout << "ID: ";
                cin >> quantity;
            }

            inventory.putBox(Box(id, description, quantity));
            inventory.display();

            break;
        case 4:
            inventory.display();
            break;
        case 5:
            inventory.save();
            break;
        case 0:
            exit = true;
            break;
        }
        cout << endl;
    }

    return 0;
}

