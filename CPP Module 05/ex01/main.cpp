/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 05:42:54 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/15 20:49:20 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat b("Meow", 11);
		Form f("Form1", 10, 2);
		std::cout << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
		f.beSigned(b);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}