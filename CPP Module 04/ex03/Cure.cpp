/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 00:43:56 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/24 06:52:10 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &other) : AMateria(other)
{
}

Cure &Cure::operator=(const Cure &other)
{
	(void) other;
	return *this;
}

Cure::~Cure()
{
}

AMateria *Cure::clone() const
{
	AMateria *mat = new Cure();
	return mat;
}

void Cure::use(ICharacter& target)
{
	ICharacter *NC = 0;
	if (&target != NC)
		std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}