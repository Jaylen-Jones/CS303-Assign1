#include "error_handler.h"
#include "array_manager.h"

#include <iostream>


void handleFileError(const std::string& function_name, const std::string& details) {
    try {
        throw; //Re-throw the current exception to identify it
    }
	//To catch file I/O related errors
    catch (const std::ios_base::failure& e) {
        std::cerr << "File I/O error in " << function_name << ": " << e.what() << std::endl;
        if (!details.empty()) {
            std::cerr << "Details: " << details << std::endl;
        }
        abort();
    }
}

//To handle memory allocation errors
void handleMemoryError(const std::string& function_name) {
    try {
        throw; //Re-throw to identify the exception
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed in " << function_name << ": " << e.what() << std::endl;
        abort();
    }
}
//to catch index out of bounds errors
void handleIndexError(const std::string& function_name, int index, int size) {
    std::cerr << "Index error in " << function_name << ": ";
    std::cerr << "Index " << index << " is out of bounds (size: " << size << ")" << std::endl;
}

//To handle any other general errors
void handleGeneralError(const std::string& function_name) {
    try {
        throw; //Re-throw to identify the exception
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception in " << function_name << ": " << e.what() << std::endl;
        abort();
    }
    catch (...) {
        std::cerr << "Undefined exception occurred in " << function_name << std::endl;
        abort();
    }
}

