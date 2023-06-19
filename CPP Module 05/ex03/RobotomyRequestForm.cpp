/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:43:54 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/19 03:17:49 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	(void)other;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}


std::string RobotomyRequestForm::getTarget() const
{
	return (AForm::getName());
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execCheck(executor);
	int random = rand() % 2;
	
	std::cout << "* drilling noises *" << std::endl;
	if (random)
		std::cout << "successfully robotomized " << this->target << std::endl;
	else
		std::cout << "failed to robotomize " << this->target << std::endl;
}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &form)
{
	out << "RobotomyRequestForm " << form.getName() << " is ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getSignGrade()<< " to be signed and grade " << form.getExecGrade() << " to be executed" << std::endl;
	return (out);
}
