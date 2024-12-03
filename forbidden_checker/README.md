# forbidden_checker

Here’s the README translated into English:

Forbidden Items Checker

This script scans .cpp, .hpp, .h, and .tpp files in specified directories for forbidden constructs and headers, which are configurable in the forbidden_items list.

Features

	•	Detects modern C++ constructs (C++11/14/17) that may be disallowed in your project.
	•	Removes comments before scanning to avoid false positives.
	•	Supports recursive directory scanning.
	•	Outputs colored messages: red for errors, green for success.

Installation

To install the script automatically, use the following curl command:

bash <(curl -s https://raw.githubusercontent.com/<your-username>/<repository-name>/main/install.sh)

This script will download the necessary file and make it executable.

Usage

Scan the current directory:

python3 checker.py

Scan a specific directory:

python3 checker.py path/to/directory

Example output:

File: ./example.cpp, Line: 42, Forbidden Item: constexpr
File: ./header.hpp, Line: 13, Forbidden Item: #include <unordered_map>

If no issues are found:

Everything is [OK]

Requirements

	•	Python 3.6 or newer.

Embedded install.sh Script:

#!/bin/bash

# Create a directory for the script if it doesn't exist
mkdir -p "$HOME/.forbidden_checker"
cd "$HOME/.forbidden_checker" || exit 1

# Download the main script
curl -s -O https://raw.githubusercontent.com/<your-username>/<repository-name>/main/checker.py

# Make the script executable
chmod +x checker.py

# Add the script to PATH via alias
if ! grep -q 'alias forbidden-checker' "$HOME/.bashrc"; then
  echo 'alias forbidden-checker="python3 $HOME/.forbidden_checker/checker.py"' >> "$HOME/.bashrc"
  echo "Installation successful! Restart your terminal or run 'source ~/.bashrc' to activate."
else
  echo "The script is already installed."
fi

Replace <your-username> and <repository-name> with your GitHub username and repository name before publishing.
