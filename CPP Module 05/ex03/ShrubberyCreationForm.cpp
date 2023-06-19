/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:53:33 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/19 00:09:56 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	(void)other;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (AForm::getName());
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	// AForm::execute(executor);
	AForm::execCheck(executor);
	std::ofstream file;
	file.open((this->target + "_shrubbery").c_str());
	
	
	file << std::endl;
	file << "                  %%%,%%%%%%%			"<< std::endl;
    file << "               ,'%% \\-*%%%%%%%		"<< std::endl;
    file << "         ;%%%%%*%   _%%%%				"<< std::endl;
    file << "          ,%%%       \\\\(_.*%%%%.		"<< std::endl;
    file << "          % *%%, ,%%%%*(    '	 		"<< std::endl;
    file << "        %^     ,*%%% )\\|,%%*%,_		"<< std::endl;
    file << "             *%    \\/ #).-*%%*			"<< std::endl;
    file << "                 _.) ,/ *%,			"<< std::endl;
    file << "         _________/)#(_____________	"<< std::endl;
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form)
{
	out << "ShrubberyCreationForm " << form.getName() << " is ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getSignGrade() << " to be signed and grade " << form.getExecGrade() << " to be executed" << std::endl;
	return (out);
}