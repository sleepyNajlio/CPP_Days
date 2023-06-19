/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:30:05 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/19 03:10:11 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), _signed(false), signGrade(150), execGrade(150) 
{}

AForm::AForm(std::string name, int signGrade, int execGrade) : name(name), _signed(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), _signed(other._signed), signGrade(other.signGrade), execGrade(other.execGrade)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "AForm assignation operator called" << std::endl;
	_signed = other._signed;
	return (*this);
}

AForm::~AForm()
{}

std::string AForm::getName() const
{
	return (name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getSignGrade() const
{
	return (signGrade);
}

int AForm::getExecGrade() const
{
	return (execGrade);
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > signGrade)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void	AForm::execCheck(Bureaucrat const &executor) const
{
	if (!_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > execGrade)
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << "AForm " << f.getName() << " is ";
	if (f.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << f.getSignGrade()<< " to be signed and grade " << f.getExecGrade() << " to be executed" << std::endl;
	return (out);
}