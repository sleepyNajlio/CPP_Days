/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:10:56 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/18 00:04:06 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl H1;
	
	std::cout << "DEBUG" << std::endl;
	H1.complain("DEBUG");
	std::cout << "INFO" << std::endl;
	H1.complain("INFO");
	std::cout << "WARNING" << std::endl;
	H1.complain("WARNING");
	std::cout << "ERROR" << std::endl;
	H1.complain("ERROR");
}