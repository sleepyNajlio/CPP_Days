/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:26:42 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/18 00:28:55 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &f);
		void executeForm(AForm const &form);
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw() {
					return ("Grade is too high");
				};
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw() {
					return ("Grade is too low");
				};
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);