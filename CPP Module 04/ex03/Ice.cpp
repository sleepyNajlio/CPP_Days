/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 00:43:02 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/24 06:51:54 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &other) : AMateria(other)
{
}

Ice &Ice::operator=(const Ice &other)
{
	(void) other;
	return *this;
}

Ice::~Ice()
{
}

AMateria *Ice::clone() const
{
	AMateria *mat = new Ice();
	return mat;
}

void Ice::use(ICharacter& target)
{
	ICharacter *NC = 0;
	if (&target != NC)
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
