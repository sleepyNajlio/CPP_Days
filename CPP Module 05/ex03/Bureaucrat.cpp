/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:36:31 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/19 03:05:48 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::incrementGrade()
{
	if (grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}

void	Bureaucrat::signForm(AForm &f)
{
	if (f.getSigned() == true)
	{
		std::cout << this->name << " cannot sign " << f.getName() << " because it's already signed" << std::endl;
	}
	else if (this->grade > f.getSignGrade())
	{
		std::cout << this->name << " cannot sign " << f.getName() << " because his grade is too low" << std::endl;
	}
	f.beSigned(*this);
	std::cout << this->name << " signs " << f.getName() << std::endl;
}

void	Bureaucrat::executeForm(AForm const & form)
{
	if (form.getSigned() == false)
	{
		std::cout << this->name << " cannot execute " << form.getName() << " because it's not signed" << std::endl;
	}
	else if (this->grade > form.getExecGrade())
	{
		std::cout << this->name << " cannot execute " << form.getName() << " because his grade is too low" << std::endl;
	}
	form.execute(*this);
}

