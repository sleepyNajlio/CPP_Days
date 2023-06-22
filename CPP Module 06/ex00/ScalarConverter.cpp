/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:51:16 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/22 22:21:29 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

Scalar::Scalar()
{
}

Scalar::Scalar(Scalar const & other)
{
	*this = other;
}

Scalar::~Scalar()
{
}

Scalar & Scalar::operator=(Scalar const & other)
{
	(void)other;
	return (*this);
}

int	check_pseudo(std::string str)
{
	if (str == "nan")
	{
		std::cout<<"char: impossible"<<std::endl; 
		std::cout<<"int: impossible"<<std::endl; 
		std::cout<<"float: nanf"<<std::endl; 
		std::cout<<"double: nan"<<std::endl;
		return (1);
	}
	else if (str == "+inf" || str == "-inf")
	{
		std::cout<<"char: impossible"<<std::endl; 
		std::cout<<"int: impossible"<<std::endl; 
		std::cout<<"float: "<<str<<std::endl; 
		std::cout<<"double: "<<str<<std::endl;
		return (1);
	}
	return (0);
}


void	check_str(std::string str)
{
	int i = 0;
	if ( (str.find_first_of(".") != str.find_last_of("."))) // if there is more than one dot
		throw std::exception();
	if (str[0] == '-' || str[0] == '+')
		i++;
	for (; i < (int)str.length(); i++)
	{
		if (!isdigit(str[i]) && str[i] != 'f' && str[i] != '.')
			throw std::exception();
		else if (str[i] == 'f')
			break;
	}
	if (str[i] == 'f' && str[i+1] != '\0')
		throw std::exception();
}

void	get_char(std::string str)
{

	try
	{
		if (str.size() == 1 && !isdigit(str[0]))
		{
			char a = static_cast<char>(str[0]);
			std::cout<<"char: '"<<a<<"'"<<std::endl;
			return ;
		}
		int c = static_cast<int>(std::stoi(str));
		if ((c < 32 && c >= 0) || c == 127)
			std::cout<<"char: Non displayable"<<std::endl;
		else if (c > 127 || c < 0)
			throw std::exception();
		else
		{
			char a = static_cast<char>(c);
			std::cout<<"char: '"<<a<<"'"<<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		if (str.length() == 1)
			std::cout<<"char: '"<<str[0]<<"'"<<std::endl;
		else
			std::cout<<"char: impossible"<<std::endl;
	}
}

void	get_int(std::string str)
{
	try
	{
		check_str(str);
		int i = static_cast<int>(std::stoi(str));
		std::cout<<"int: "<<i<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout<<"int: impossible"<<std::endl;
	}
}

void	get_float(std::string str)
{
	try
	{
		check_str(str);
		float f = static_cast<float>(std::stof(str));
		std::cout<<"float: "<<f<<"f"<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout<<"float: impossible"<<std::endl;
	}
}

void	get_double(std::string str)
{
	try
	{
		check_str(str);
		double d = static_cast<double>(std::stod(str));
		std::cout<<"double: "<<d<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout<<"double: impossible"<<std::endl;
	}
}

void	Scalar::convert(std::string str)
{
	if (check_pseudo(str))
		return ;
	std::cout.setf(std::ios::fixed);
	std::cout.precision(1);
	get_char(str);
	
	get_int(str);
	get_float(str);
	get_double(str);
}
