/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:16:41 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/18 17:54:23 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"



Form::Form(): name("default"), signGrade(150), execGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade): name(name), signGrade(signGrade), execGrade(execGrade)
{
	std::cout << "Form constructor called" << std::endl;
	this->name = name;
	this->_signed = false;
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
{
	*this = other;
}

Form	&Form::operator=(const Form &other)
{
	std::cout << "Form assignment operator called" << std::endl;
	this->name = other.getName();
	this->_signed = other.getSigned();
	this->signGrade = other.getSignGrade();
	this->execGrade = other.getExecGrade();
	return (*this);
}

Form::~Form()
{
	std::cout << this->name << " Form destructor called" << std::endl;
}

std::string	Form::getName() const
{
	return (this->name);
}

bool	Form::getSigned() const
{
	return (this->_signed);
}

int	Form::getSignGrade() const
{
	return (this->signGrade);
}

int	Form::getExecGrade() const
{
	return (this->execGrade);
}

void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getSignGrade()<< " to be signed and grade " << form.getExecGrade() << " to be executed" << std::endl;
	return (out);
}
