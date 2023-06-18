/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 05:12:46 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/18 00:42:21 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	this->name = name;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this->name << " Bureaucrat destructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	this->name = other.getName();
	this->grade = other.getGrade();
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (out);
}

void	Bureaucrat::signForm(Form &f)
{
	if (f.getSigned() == true)
	{
		std::cout << this->name << " cannot sign " << f.getName() << " because it's already signed" << std::endl;
		return ;
	}
	if (this->grade > f.getSignGrade())
	{
		std::cout << this->name << " cannot sign " << f.getName() << " because his grade is too low" << std::endl;
		return ;
	}
	f.beSigned(*this);
}

