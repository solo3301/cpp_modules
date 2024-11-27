/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:52:47 by yadereve          #+#    #+#             */
/*   Updated: 2024/11/27 11:49:08 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FileReplacer.hpp"

FileReplacer::FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2)
	: filename(filename), s1(s1), s2(s2) { }

bool FileReplacer::checkArguments()
{
	if (s1.empty())
	{
		std::cout << "Error: s1 cannot be empty" << std::endl;
		return false;
	}
	if (s2.empty())
	{
		std::cout << "Error: s2 cannot be empty" << std::endl;
		return false;
	}
	return true;
}

/*
	sources/FileReplacer.cpp:35:17: error: no viable conversion from 'std::string' (aka 'basic_string<char>') to 'const char *'
        inputfile.open(filename);
                       ^~~~~~~~
/usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../../include/c++/12/fstream:663:24: note: passing argument to parameter '__s' here
      open(const char* __s, ios_base::openmode __mode = ios_base::in)
                       ^
sources/FileReplacer.cpp:41:18: error: no viable conversion from 'basic_string<char>' to 'const char *'
        outputfile.open(filename + ".replace");
                        ^~~~~~~~~~~~~~~~~~~~~
/usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../../include/c++/12/fstream:926:24: note: passing argument to parameter '__s' here
      open(const char* __s, ios_base::openmode __mode = ios_base::out)
                       ^
2 errors generated.
 */

/*
	Solution:

You can convert a std::string to const char* by using the c_str() member function, which returns a C-style string (const char*) from a std::string.
Fix:

    For inputfile.open(filename);: You need to call filename.c_str() to convert filename (which is a std::string) to const char*.

inputfile.open(filename.c_str());

For outputfile.open(filename + ".replace");: Similarly, you need to convert the concatenated result filename + ".replace" to const char*.

    outputfile.open((filename + ".replace").c_str());

Updated Code:

inputfile.open(filename.c_str());  // Convert std::string to const char*
outputfile.open((filename + ".replace").c_str());  // Convert the concatenated string to const char*

This should resolve the error you're seeing, as the std::fstream::open() function will now receive a const char* argument.
Explanation:

    c_str(): This function returns a pointer to the underlying character array (a const char*) of a std::string. It is necessary because some older C++ functions, including fstream::open, expect C-style strings rather than std::string objects.
*/

bool FileReplacer::openFiles()
{
	inputfile.open(filename.c_str());
	if (!inputfile.is_open())
	{
		std::cout << "Error: Cannot open input file " << filename << std::endl;
		return false;
	}
	outputfile.open((filename + ".replace").c_str());
	if (!outputfile.is_open())
	{
		std::cout << "Error: Cannot create output file " << filename + ".replace" << std::endl;
		return false;
	}
	return true;
}

std::string FileReplacer::replaceString(const std::string& line)
{
	std::string result = line;
	size_t pos = 0;

	while ((pos = result.find(s1, pos)) != std::string::npos)
	{
		result.erase(pos, s1.length());
		result.insert(pos, s2);
		pos += s2.length();
	}
	return result;
}

void FileReplacer::processFile()
{
	std::string line;
	while (std::getline(inputfile, line))
		outputfile << FileReplacer::replaceString(line) << std::endl;
}

void FileReplacer::closeFiles()
{
	inputfile.close();
	outputfile.close();
}
