/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 05:42:54 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/15 16:43:14 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat b("Min", 3);
		Bureaucrat c("Max", 150);
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}