#include "error_handler.h"
#include "array_manager.h"
#include <iostream>

//Function 1: Check if integer exists and return index
int findInteger(int* arr, int size, int target) {
    try {
        if (arr == nullptr) {
            throw std::invalid_argument("Null array pointer");
        }

        for (int i = 0; i < size; i++) {
            if (arr[i] == target) {
                return i; // Return index where number is found
            }
        }
        return -1; // Return -1 if not found
    }
    catch (...) {
        handleGeneralError("findInteger");
        return -1;
    }
}

//Function 2: Modify values at given index
std::pair<int, int> modifyValue(int* arr, int size, int index, int newValue) {
    try {
        if (arr == nullptr) {
            throw std::invalid_argument("Null array pointer");
        }

        if (index < 0 || index >= size) {
            handleIndexError("modifyValue", index, size);
            return std::make_pair(-1, -1);
        }

        int oldValue = arr[index];
        arr[index] = newValue;
        return std::make_pair(oldValue, newValue);
    }
    catch (...) {
        handleGeneralError("modifyValue");
        return std::make_pair(-1, -1);
    }
}

//Function 3: Add new integer to end of array
bool addInteger(int*& arr, int& size, int& capacity, int value) {
    try {
        if (arr == nullptr) {
            throw std::invalid_argument("Null array pointer");
        }

        if (size >= capacity) {
            // Try to resize array
            resizeArray(arr, capacity);
        }

        arr[size] = value;
        size++;
        std::cout << "Added " << value << " at index " << (size - 1) << std::endl;
        return true;
    }
    catch (...) {
        handleGeneralError("addInteger");
        return false;
    }
}

//Function 4: Remove integers at given index
bool removeInteger(int* arr, int& size, int index) {
    try {
        if (arr == nullptr) {
            throw std::invalid_argument("Null array pointer");
        }

        if (index < 0 || index >= size) {
            handleIndexError("removeInteger", index, size);
            return false;
        }

        int removedValue = arr[index];

        //Shift all elements after the removed index to the left
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
        std::cout << "Removed " << removedValue << " from index " << index << std::endl;
        return true;
    }
    catch (...) {
        handleGeneralError("removeInteger");
        return false;
    }
}



//Utility function to resize array
void resizeArray(int*& arr, int& capacity) {
    try {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];

        //Copy old elements
        for (int i = 0; i < capacity; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        capacity = newCapacity;

        std::cout << "Array resized to capacity: " << capacity << std::endl;
    }
    catch (...) {
        handleMemoryError("resizeArray");
    }
}


//Helper function to display array contents
void displayArray(int* arr, int size) {
    try {
        if (arr == nullptr) {
            std::cout << "Array is null" << std::endl;
            return;
        }

        std::cout << "Array contents: ";
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Array size: " << size << std::endl;
    }
    catch (...) {
        handleGeneralError("displayArray");
    }
}