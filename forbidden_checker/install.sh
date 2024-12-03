#!/bin/bash

# Create a directory for the script if it doesn't exist
mkdir -p "$HOME/.forbidden_checker"
cd "$HOME/.forbidden_checker" || exit 1

# Download the main script
curl -s -O https://raw.githubusercontent.com/jannco/cpp_modules/main/forbidden_checker/checker_cpp89.py

# Make the script executable
chmod +x checker_cpp89.py

# Add the script to PATH via alias
if ! grep -q 'alias forbidden-checker' "$HOME/.zshrc"; then
	echo 'alias forbidden_checker="python3 $HOME/.forbidden_checker/checker_cpp89.py"' >> "$HOME/.zshrc"
	echo "Installation successful! Restart your terminal or run 'source ~/.zshrc' to activate."
else
	echo "The script is already installed."
fi
