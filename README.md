# Variable Declaration Analyzer

This project provides a C++ program to analyze variable declarations in source code files and generate a report containing information about the expressions which don't have declaration forms.
Input file must contain only valid declarations for C++.

## Introduction

The Variable Declaration Analyzer is a C++ program that parses C++ source code files, identifies variable declarations, and extracts information such as variable type, name, value (if initialized), line number, and position within the line.
The program organizes this information and generates a report in a structured format for further analysis or documentation.

## Features

- Parses C++ source code files.
- Identifies variable declarations and extracts relevant information.
- Handles variable declarations spread across multiple lines.
- Supports various data types specified by C++ keywords.
- Generates a report containing information about each variable.

## How to Use

1. Clone the repository or download the source code files.
2. Ensure you have a C++ compiler installed on your system.
3. Include the `Edit.hpp` header file in your project.
4. You can modify text.txt file to run your own examples
5. Use the `run()` function to analyze variable declarations in your source code files.

Example usage:

```cpp
#include <iostream>
#include "Edit.hpp"
#include <fstream>

int main() {
    std::ifstream read("source_code.cpp");
    if (!read.is_open()) {
        std::cout << "Failed to open file for reading." << std::endl;
        return 1;
    }
    run(read);
    read.close();
    return 0;
}
```
Output must be file like this

![Screenshot from 2024-02-16 01-57-53](https://github.com/AnnaGmboyan/Visual_Compiler_Task1/assets/138877122/0df39c03-165b-4b2b-8855-a92e0fe09d6f)

