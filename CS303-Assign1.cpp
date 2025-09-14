// CS303-Assign1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "array_manager.h"
#include "error_handler.h"
#include <iostream>

int main() {
    try {
        int capacity = 100;
        int* arr = new int[capacity];
        int size = 0;
        //Read data from file
        std::string filename;
        std::cout << "Enter input filename: ";
        std::cin >> filename;
        if (!readFromFile(filename, arr, size, capacity)) {
            delete[] arr;
            return 1;
        }
        displayArray(arr, size);
        int choice;
        do {
            std::cout << "\n--- Array Management Menu ---" << std::endl;
            std::cout << "1. Find integer" << std::endl;
            std::cout << "2. Modify value at index" << std::endl;
            std::cout << "3. Add new integer" << std::endl;
            std::cout << "4. Remove integer at index" << std::endl;
            std::cout << "5. Display array" << std::endl;
            std::cout << "6. Exit" << std::endl;
            std::cout << "Enter choice: ";
            std::cin >> choice;

            // Add input validation after reading choice:
            if (std::cin.fail()) {
                std::cout << "Invalid input! Clearing buffer..." << std::endl;
                std::cin.clear();                // Clear error flag
                std::cin.ignore(10000, '\n');    // Clear buffer
                choice = 0;                      // Set to invalid choice
            }

            switch (choice) {
            case 1: {
                int target;
                std::cout << "Enter integer to find: ";
                std::cin >> target;

                if (std::cin.fail()) {
                    std::cout << "Invalid input! Clearing buffer..." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    break;
                }

                int index = findInteger(arr, size, target);
                if (index != -1) {
                    std::cout << "Integer " << target << " found at index " << index << std::endl;
                }
                else {
                    std::cout << "Integer " << target << " not found in array" << std::endl;
                }
                break;
            }
            case 2: {
                int index, newValue;
                std::cout << "Enter index to modify: ";
                std::cin >> index;

                if (std::cin.fail()) {
                    std::cout << "Invalid input! Clearing buffer..." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    break;
                }

                std::cout << "Enter new value: ";
                std::cin >> newValue;

                if (std::cin.fail()) {
                    std::cout << "Invalid input! Clearing buffer..." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    break;
                }

                std::pair<int, int> result = modifyValue(arr, size, index, newValue);
                if (result.first != -1) {
                    std::cout << "Old value: " << result.first << std::endl;
                    std::cout << "New value: " << result.second << std::endl;
                }
                break;
            }
            case 3: {
                int value;
                std::cout << "Enter integer to add: ";
                std::cin >> value;

                // Add validation here too to prevent the overflow issue:
                if (std::cin.fail()) {
                    std::cout << "Invalid input! Clearing buffer..." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    break;  // Exit this case instead of trying to add garbage
                }

                addInteger(arr, size, capacity, value);
                break;
            }
            case 4: {
                int index;
                std::cout << "Enter index to remove: ";
                std::cin >> index;

                if (std::cin.fail()) {
                    std::cout << "Invalid input! Clearing buffer..." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    break;
                }

                removeInteger(arr, size, index);
                break;
            }
            case 5: {
                displayArray(arr, size);
                break;
            }
            case 6: {
                std::cout << "Exiting program..." << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
            }
        } while (choice != 6);
        //Clean up
        delete[] arr;
        return 0;
    }
    catch (...) {
        handleGeneralError("main");
        return 1;
    }
}