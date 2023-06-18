/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:48:45 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/18 00:57:30 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm: public AForm
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		virtual ~ShrubberyCreationForm();
		std::string getTarget() const;
		virtual void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &f);