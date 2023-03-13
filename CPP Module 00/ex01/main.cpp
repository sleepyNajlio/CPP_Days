/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 23:26:24 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/13 02:51:18 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::string	str;
	PhoneBook	Phone_b;
	int			index;
	
	index = 0;
	while (1)
	{
		std::cout << "Enter Your Command :" << std::endl;
		std::getline(std::cin, str);
		if (std::cin.eof())
			exit(0);
		if (str == "EXIT")
		{
			std::cout << "Goodbye" << std::endl;
			exit(0);
		}
		else if (str == "ADD")
		{
			Phone_b.add(index);
			if (index == 8)
				index = 0;
			index++;
		}
		else if (str == "SEARCH")
			Phone_b.search();
			
	}
}