/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:51:44 by yadereve          #+#    #+#             */
/*   Updated: 2024/11/27 07:05:29 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FileReplacer.hpp"

int main(int ac, char *av[])
{
	if (ac != 4)
	{
		std::cout << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
		std::string filename = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3];
	FileReplacer replacer(filename, s1, s2);
	if (!replacer.checkArguments())
		return 1;
	if (!replacer.openFiles())
		return 1;
	replacer.processFile();
	replacer.closeFiles();
	std::cout << "The replacement is complete. Saved in the file " << filename + ".replace" << std::endl;
	return 0;
}
