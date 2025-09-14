#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <string>

//Error handling functions
void handleFileError(const std::string& function_name, const std::string& details = "");
void handleMemoryError(const std::string& function_name);
void handleIndexError(const std::string& function_name, int index, int size);
void handleGeneralError(const std::string& function_name);

#endif
