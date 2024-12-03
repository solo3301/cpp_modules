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
