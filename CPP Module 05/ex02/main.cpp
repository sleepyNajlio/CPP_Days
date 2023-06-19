/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:56:50 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/19 03:18:25 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try {
		Bureaucrat b1("b1", 1);
		ShrubberyCreationForm f1("shrub");
		RobotomyRequestForm f2("f2");
		PresidentialPardonForm f3("f3");
		
		std::cout << b1 << std::endl;
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;
		b1.signForm(f1);
		b1.executeForm(f1);
		b1.signForm(f2);
		b1.executeForm(f2);
		b1.signForm(f3);
		b1.executeForm(f3);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
}