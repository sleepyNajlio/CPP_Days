/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:30:05 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/18 00:46:13 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), _signed(false), signGrade(150), execGrade(150) 
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : name(name), _signed(false), signGrade(signGrade), execGrade(execGrade)
{
	std::cout << "AForm constructor called" << std::endl;
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
{
	std::cout << "AForm destructor called" << std::endl;
}

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

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > signGrade)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << f.getName() << " form, sign grade " << f.getSignGrade() << ", exec grade " << f.getExecGrade() << ", signed: " << f.getSigned();
	return (out);
}