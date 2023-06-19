/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:56:50 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/19 03:41:45 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try {
		Bureaucrat b1("b1", 1);
		AForm *f;
		Intern i;
		
		f = i.makeForm("shrubbery creation", "shrub");
		std::cout << *f << std::endl;
		if (f)
		{
			b1.signForm(*f);
			b1.executeForm(*f);
		}
		delete f;
		
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
}