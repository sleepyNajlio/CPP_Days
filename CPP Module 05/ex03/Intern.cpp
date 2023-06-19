/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 03:27:55 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/19 03:32:47 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	if (formName == "robotomy request")
		return (new RobotomyRequestForm(target));
	else if (formName == "presidential pardon")
		return (new PresidentialPardonForm(target));
	else if (formName == "shrubbery creation")
		return (new ShrubberyCreationForm(target));
	else
	{
		std::cout << "Form " << formName << " not found" << std::endl;
		return (NULL);
	}
}
