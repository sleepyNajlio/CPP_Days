/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 05:05:42 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/15 18:34:51 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Form.hpp"

class Form;

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
		void signForm(Form &f);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);