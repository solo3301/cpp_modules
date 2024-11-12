import os
import re
import sys

forbidden_items = [
	r'\bprintf\b', r'\bmalloc\b', r'\bcalloc\b', r'\brealloc\b', r'\bfree\b',
	r'\bvector\b', r'\blist\b', r'\bmap\b', r'\bdeque\b', r'\bstack\b', r'\bqueue\b',
	r'\bset\b', r'\bmultiset\b', r'\bunordered_map\b', r'\bunordered_set\b',
	r'#include <algorithm>', r'#include <boost>', r'\busing namespace\b', r'\bfriend\b',
	r'boost', r'algorithm', r'namespace', r'gsl'
]

def path_checker():
	paths = []
	if len(sys.argv) > 1:
		for i in range(1, min(3, len(sys.argv))):
			path = sys.argv[i]
			if path.startswith('./'):
				paths.append(path)
			else:
				paths.append(f"./{path}")
	else:
		paths.append('./')
	return paths

def check_forbidden_items(file_path):
	found = False
	try:
		with open(file_path, 'r') as file:
			for line_num, line in enumerate(file, 1):
				for forbidden_item in forbidden_items:
					match = re.search(forbidden_item, line)
					if match:
						forbidden_text = match.group(0)
						print(f'File:{file_path}, Line:{line_num}, Forbidden Item: \033[91m{forbidden_text}\033[0m')
						found = True
	except Exception as e:
		print(f"Error reading {file_path}: {e}")
	return found

def main():
	paths = path_checker()
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
