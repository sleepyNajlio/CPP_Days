/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:24:31 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/13 03:19:31 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	Contact::set_FirstName(std::string FirstName)
{
	this->FirstName = FirstName;
}

void	Contact::set_LastName(std::string LastName)
{
	this->LastName = LastName;
}

void	Contact::set_NickName(std::string NickName)
{
	this->NickName = NickName;
}

void	Contact::set_PhoneNumber(std::string PhobeNumber)
{
	this->PhoneNumber = PhobeNumber;
}

void	Contact::set_DarkestSecret(std::string DarkestSecret)
{
	this->DarkestSecret = DarkestSecret;
}

std::string	Contact::get_field(int index)
{
	if (index == 0)
		return this->FirstName;
	else if (index == 1)
		return this->LastName;
	else if (index == 2)
		return this->NickName;
	else if (index == 3)
		return this->PhoneNumber;
	else
		return this->DarkestSecret;

}

PhoneBook::PhoneBook()
{
	std::cout << "-------------------------------" << std::endl;
	std::cout << "Welcome to my Awesome PhoneBook" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << "Options: ADD || SEARCH || EXIT" << std::endl;
}

void	PhoneBook::add(int index)
{
	std::string fn, ln, nn, pn, ds;
	while (fn.empty())
	{
		std::cout << "Enter First Name" << std::endl;
		std::getline(std::cin, fn);
		if (std::cin.eof())
			exit(0);	
	}
	this->contacts[index % 8].set_FirstName(fn);
	while (ln.empty())
	{
		std::cout << "Enter Last Name" << std::endl;
		std::getline(std::cin, ln);
		if (std::cin.eof())
			exit(0);
	}
	this->contacts[index % 8].set_LastName(ln);
	while (nn.empty())
	{
		std::cout << "Enter Nick Name" << std::endl;
		std::getline(std::cin, nn);
		if (std::cin.eof())
			exit(0);
	}
	this->contacts[index % 8].set_NickName(nn);
	while (pn.empty())
	{
		std::cout << "Enter Phone Number" << std::endl;
		std::getline(std::cin, pn);
		if (std::cin.eof())
			exit(0);
	}
	this->contacts[index % 8].set_PhoneNumber(pn);
	while (ds.empty())
	{
		std::cout << "Enter Darkest Secret" << std::endl;
		std::getline(std::cin, ds);
		if (std::cin.eof())
			exit(0);
	}
	this->contacts[index % 8].set_DarkestSecret(ds);
}

void	PhoneBook::search()
{
	int i = 0;
	int n = 0;
	std::string temp;
	bool t_bool = 1;

	
	while (i < 8)
	{
		if (this->contacts[i].get_field(0).empty())
			break;
		std::cout << std::setw(10) << "index : " << i << "|";
		if (this->contacts[i].get_field(0).length() > 10)
		{
			temp = this->contacts[i].get_field(0).substr(0, 9);
			std::cout << temp << "." << "|";
		}
		else
			std::cout << std::setw(10) << this->contacts[i].get_field(0)<< "|";
		if (this->contacts[i].get_field(1).length() > 10)
		{
			temp = this->contacts[i].get_field(1).substr(0, 9);
			std::cout << temp << "." << "|";
		}
		else
			std::cout << std::setw(10) << this->contacts[i].get_field(1) << "|";
		if (this->contacts[i].get_field(2).length() > 10)
		{
			temp = this->contacts[i].get_field(2).substr(0, 9);
			std::cout << temp << "." << "|" << std::endl;
		}
		else
			std::cout << std::setw(10) << this->contacts[i].get_field(2) << "|" << std::endl;
		i++;
	}
	if (i == 0)
		return ;
	std::cout << "Enter Selected Index :" << std::endl;
	while(t_bool)
	{
		std::cin >> n;
		if (std::cin.eof())
			exit(0);
		if(std::cin.fail() || n < 0 || n >= i)
		{
			// std::cin.clear();
			// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "wrong index, try again!" << std::endl;
		}
		else
		{
			std::cout << "Your Selected Contact :" << std::endl;
			for (int j = 0; j < 5; j++)
				std::cout << this->contacts[n].get_field(j) << std::endl;
			t_bool = 0;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
	}
}

