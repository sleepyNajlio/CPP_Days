/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:59:35 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/13 03:16:24 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;
	public:
		void	set_FirstName(std::string FirstName);
		void	set_LastName(std::string LastName);
		void	set_NickName(std::string NickName);
		void	set_PhoneNumber(std::string PhobeNumber);
		void	set_DarkestSecret(std::string FirstName);
		std::string get_field(int index);
};

class PhoneBook 
{
	private:
		Contact contacts[8];
	public:
		PhoneBook();
		void add(int index);
		void search();
};