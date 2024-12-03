import os
import re
import sys

forbidden_items = [
	r'\bconstexpr\b', r'\bstatic_assert\b', r'\bnoexcept\b', r'\bdecltype\b', r'\bnullptr\b',
	r'\bthread_local\b', r'\boverride\b', r'\bfinal\b', r'\balignas\b', r'\balignof\b',
	r'\bstd::move\b', r'\bstd::forward\b', r'\bstd::to_string\b', r'\bstd::stoi\b',
	r'\bstd::stol\b', r'\bstd::stoll\b', r'\bstd::stof\b', r'\bstd::stod\b',
	r'\bstd::function\b', r'\bstd::bind\b', r'\bstd::shared_ptr\b', r'\bstd::unique_ptr\b',
	r'\bstd::unordered_map\b', r'\bstd::unordered_set\b', r'\bstd::array\b', r'\bstd::tuple\b',
	r'#\s*include\s*<thread>', r'#\s*include\s*<future>', r'#\s*include\s*<mutex>',
	r'#\s*include\s*<unordered_map>', r'#\s*include\s*<unordered_set>'
]

def remove_comments(line):
	line = re.sub(r'//.*', '', line)
	line = re.sub(r'/\*.*?\*/', '', line, flags=re.DOTALL)
	return line

def check_forbidden_items(file_path):
	found = False
	try:
		with open(file_path, 'r') as file:
			for line_num, line in enumerate(file, 1):
				line = remove_comments(line)
				for forbidden_item in forbidden_items:
					match = re.search(forbidden_item, line)
					if match:
						forbidden_text = match.group(0)
						print(f'File: {file_path}, Line: {line_num}, Forbidden Item: \033[91m{forbidden_text}\033[0m')
						found = True
	except Exception as e:
		print(f"Error reading {file_path}: {e}")
	return found

def main():
	paths = ['./'] if len(sys.argv) == 1 else sys.argv[1:]
	total_found = False

	for directory_path in paths:
		for root, _, files in os.walk(directory_path):
			for file in files:
				if file.endswith(('.cpp', '.hpp', '.h', '.tpp')):
					if check_forbidden_items(os.path.join(root, file)):
						total_found = True

	if not total_found:
		print("\033[32mEverything is [OK]\033[0m")

if __name__ == "__main__":
	main()
