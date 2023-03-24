/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 04:02:18 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/24 17:35:30 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource() : invSize(0)
{
	for (int i = 0; i < 4; i++)
		this->InvMateria[i] = NULL;
}


MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		this->invSize= other.invSize;
		for (int i = 0 ; i < 4 ; i++)
		{
			if (this->InvMateria[i])
				delete this->InvMateria[i];
			if (other.InvMateria[i])
				this->InvMateria[i] = other.InvMateria[i]->clone();
			else
				this->InvMateria[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < invSize; i++)
		delete this->InvMateria[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (this->invSize == 4)
	{
		if (m)
			delete m;
		return;
	}
	if (m)
	{
		this->InvMateria[this->invSize] = m->clone();
		delete m;
		this->invSize++;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0; i < this->invSize; i++)
	{
		if (this->InvMateria[i]->getType() == type)
			return this->InvMateria[i]->clone();
	}
	return 0;
}
