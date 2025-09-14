#include "array_manager.h"
#include "error_handler.h"
#include <iostream>
#include <fstream>

//Function to read data from input file
bool readFromFile(const std::string& filename, int*& arr, int& size, int capacity) {
    try {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::ios_base::failure("Could not open file: " + filename);
        }

        //Enable exception on badbit
        file.exceptions(std::ifstream::badbit); 

        int value;
        //Reset size
        size = 0; 

        while (file >> value && size < capacity) {
            arr[size++] = value;
        }

        if (file.bad()) {
            throw std::ios_base::failure("Error reading from file: " + filename);
        }

        file.close();
        std::cout << "Successfully read " << size << " integers from " << filename << std::endl;
        return true;
    }
    catch (...) {
        handleFileError("readFromFile", "Failed to read file: " + filename);
        return false;
    }
}