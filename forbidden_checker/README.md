# Forbidden Items Checker

This script scans .cpp, .hpp, .h, and .tpp files in specified directories for forbidden constructs and headers, which are configurable in the forbidden_items list.

Features

	•	Detects modern C++ constructs (C++11/14/17) that may be disallowed in your project.
	•	Removes comments before scanning to avoid false positives.
	•	Supports recursive directory scanning.
	•	Outputs colored messages: red for errors, green for success.

## Installation

To install the script automatically, use the following curl command:

	bash <(curl -s https://raw.githubusercontent.com/jannco/cpp_modules/refs/heads/main/forbidden_checker/main/install.sh)

This script will download the necessary file and make it executable.

# Usage

### Scan the current directory:

	forbidden_checker

### Scan a specific directory:

	forbidden_checker path/to/directory

### Example output:

	File: ./example.cpp, Line: 42, Forbidden Item: constexpr
	File: ./header.hpp, Line: 13, Forbidden Item: #include <unordered_map>

###If no issues are found:

	Everything is [OK]

# Requirements

	•	Python 3 or newer.

