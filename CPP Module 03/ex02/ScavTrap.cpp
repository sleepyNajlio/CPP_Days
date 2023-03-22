/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scavtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 03:54:57 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/22 04:50:44 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
	std::cout << "ScavTrap Constructor called" << std::endl;
	this->Name = _name;
	this->hit_p = 100;;
	this->energy_p = 50;
	this->damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &other)
{
	if (this != &other)
	{
		std::cout << "ScavTrap assignment operator called" << std::endl;
		this->Name = other.Name;
		this->hit_p = other.hit_p;
		this->energy_p = other.energy_p;
		this->damage = other.damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}
 
void    ScavTrap::attack(const std::string &target)
{
    if (this->energy_p  > 0)
    {
        std::cout << "ScavTrap: " << this->Name << " attacks " << target;
        std::cout << ", causing " << this->damage << " points of damage!" << std::endl;
        this->energy_p--;
    }
    else
        std::cout << "ScavTrap: You don't have enough Energy!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << this->Name << " is now the Gatkeeper" << std::endl;
}
