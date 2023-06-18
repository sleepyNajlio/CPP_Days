/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:05:21 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/18 00:29:17 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string name;
		bool _signed;
		int signGrade;
		int execGrade;
	public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
		std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(Bureaucrat &b);
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

std::ostream &operator<<(std::ostream &out, const Form &f);