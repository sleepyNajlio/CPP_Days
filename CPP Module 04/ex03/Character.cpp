/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 00:49:34 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/24 07:57:11 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : invSize(0)
{
	for (int i = 0; i < 4; i++)
		this->Inventory[i] = NULL;
}

Character::Character(std::string _name) : name(_name), invSize(0)
{
	for (int i = 0; i < 4; i++)
		this->Inventory[i] = NULL;
}

Character::Character(const Character &other)
{
	*this = other;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->name = other.getName();
		this->invSize= other.invSize;
		for (int i = 0 ; i < 4 ; i++)
		{
			if (this->Inventory[i])
				delete this->Inventory[i];
			if (other.Inventory[i])
				this->Inventory[i] = other.Inventory[i]->clone();
			else
				this->Inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < invSize; i++)
		delete this->Inventory[i];
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
	if (this->invSize == 4)
	{
		delete m;
		return ;
	}
	
	this->Inventory[this->invSize] = m;
	this->invSize++;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < this->invSize)
	{
		this->Inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < this->invSize && Inventory[idx])
		this->Inventory[idx]->use(target);
}