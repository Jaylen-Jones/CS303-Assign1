#ifndef ARRAY_MANAGER_H
#define ARRAY_MANAGER_H

#include <string>
#include <utility>

//Array operations
int findInteger(int* arr, int size, int target);
std::pair<int, int> modifyValue(int* arr, int size, int index, int newValue);
bool addInteger(int*& arr, int& size, int& capacity, int value);
bool removeInteger(int* arr, int& size, int index);

//File operations  
bool readFromFile(const std::string& filename, int*& arr, int& size, int capacity);

//Utility functions
void displayArray(int* arr, int size);
void resizeArray(int*& arr, int& capacity);

#endif

