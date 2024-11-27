/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:52:47 by yadereve          #+#    #+#             */
/*   Updated: 2024/11/27 13:11:57 by yadereve         ###   ########.fr       */
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
