/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:21:42 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/18 00:46:44 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class AForm {
	private:
		std::string name;
		bool _signed;
		int signGrade;
		int execGrade;
	public:
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw() {
					return ("Form is not signed");
				};
		};
		
		virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &f);