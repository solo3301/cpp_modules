#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <iostream>
#include <fstream>	// fstream::open / fstream::close
#include <cstdio>	// EOF

class FileReplacer
{
private:
	std::string filename;
	std::string s1;
	std::string s2;
	std::ifstream inputfile;
	std::ofstream outputfile;

public:
	FileReplacer(const std::string &filename, const std::string &s1, const std::string &s2);
	bool checkArguments();
	bool openFiles();
	void processFile();
	void closeFiles();
	std::string replaceString(const std::string& line);
};

#endif
