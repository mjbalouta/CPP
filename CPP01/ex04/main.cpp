/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:17:04 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/09 11:26:08 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#define RESET "\033[0m"
#define PURPLE "\e[0;35m"
#define YELLOW "\e[0;33m"

std::string replaceLine(std::string line, std::string s2, std::string s1)
{
	size_t pos = 0;
	std::string result;
	size_t found = 0;
	
	while ((found = line.find(s1, pos)) != std::string::npos)
	{
		result += line.substr(pos, found - pos); //copy everything before the found
		result += s2; //concatenate previous copied and s2
		pos = found + s1.length(); //move pos to the found position + the length of s2
	}
	result += line.substr(pos); //copy from the last pos (when there is no match left in that line)

	return (result);
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Error: not enough parameters."
		<< std::endl << "How to use: program filename letter to be replace letter to replace it with." << std::endl;
		return (1);
	}
	
	//ifstream accepts a char *, so i can just use av[1] here
	std::ifstream infile(av[1]);
	if (!infile)
	{
		std::cerr << "Error opening the file." << std::endl;
		return (1);
	}
	
	//here i have to convert av[1] to a std::string in order to concatenate
	//and then c_str converts it back to a const char *
	//or i could just use (std::string(av[1])) inside the () of ofstream
	std::string filename = av[1];
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile)
	{
		std::cerr << "Error creating the file." << std::endl;
		return (1);
	}

	std::string line; //to store the lines read from getline()
	std::string s1 = av[2];
	std::string s2 = av[3];
	while(std::getline(infile, line))
	{
		line = replaceLine(line, s2, s1);
		outfile << line << std::endl;
	}
	return (0);
}