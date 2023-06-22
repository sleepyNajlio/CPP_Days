/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:35:02 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/21 22:56:01 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>

int check_pseudo(std::string str)
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

int invalid_input(std::string str)
{
    int f = 0;
    int p = 0;
    int d = 0;
    if (str.size() != 1)
    {
        for(int i = 0; i < (int)str.size(); i++)
        {
            if (str[i] == 'f')
            {
                if (i != (int)str.size() - 1)
                    f++;
                f++;
            }
            if (str[i] == '.')
                p++;
            if (!isdigit(str[i]) && str[i] != 'f' && str[i] != '.' && str[0] != '-' && str[0] != '+')
                d++;
        }
        if (f > 1 || d != 0 || p > 1)
        {
            std::cout<<"char: impossible"<<std::endl; 
            std::cout<<"int: impossible"<<std::endl; 
            std::cout<<"float: impossible"<<std::endl; 
            std::cout<<"double: impossible"<<std::endl;
            return (1);
        }
    }
    return (0);
}

void    _char(std::string str)
{
    if (isprint(str[0]))
        std::cout << "char: '" << str[0] << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(str[0]) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
}

int     is_str_digit(std::string str)
{
    int i = 0;
    if (str[0] == '-' || str[0] == '+')
        i++;
    while (i < (int)str.size())
    {
        if (!isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

void    _numbers(double d)
{
    if (int(d) > 127 || int(d) < 0)
        std::cout << "char: impossible" << std::endl;
    else if (isprint((char)(d)))
        std::cout << "char: '" << (char)(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if ((int)d > std::numeric_limits<int>::max() ||(int)d < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    if ((float)d > std::numeric_limits<float>::max() || (float)d < std::numeric_limits<float>::min())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    if ((double)d > std::numeric_limits<double>::max() || (double)d < std::numeric_limits<double>::min())
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(d) << std::endl;
}

int main(int ac , char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./convert [string]" << std::endl;
        return (1);
    }
    std::cout.setf(std::ios::fixed); // or std::cout.setf(std::ios::showpoint);
    std::cout.precision(1);
    std::string s = av[1];
    double d = strtof(av[1], NULL);
    if (check_pseudo(s) || invalid_input(s))
        return (0);
    if (s.size() == 1 && !isdigit(s[0]))
        _char(s);
    else if (s.find('f', 0) != std::string::npos 
        || s.find('.', 0) != std::string::npos || is_str_digit(s))
        _numbers(d);
    return (0);
}