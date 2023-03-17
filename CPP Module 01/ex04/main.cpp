/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:23:16 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/17 11:19:07 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

std::string search_n_replace(std::string line, std::string &s1, std::string &s2)
{
	size_t pos = 0;
	
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
	}
	return line;
}

int main(int ac, char **av)
{
	std::string s1;
	std::string s2;
	std::string content;
	std::string line;
	
	if (ac != 4)
		std::cout << "accepted format : ./search_n_replace <filename> <string1> <string2>" << std::endl;
	else
	{
		std::string filename = av[1];
		std::ifstream ifs(filename);
		s1 = av[2];
		s2 = av[3];
		if (!ifs.is_open())
		{
			std::cout << "could not open infile " << av[1] << std::endl;
			exit(1);
		}
		if (s1.empty())
		{
			std::cout << "empty string " << std::endl;
			exit(1);
		}
		while (std::getline(ifs, line))
		{
			line = search_n_replace(line, s1, s2);
			content += line + '\n';
		}
		filename += ".replace";
		std::ofstream ofs(filename);
		ofs << content;
	}
	return (0);
}