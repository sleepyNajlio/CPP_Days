/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:08:47 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/22 04:48:18 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string _name)
{
    std::cout << "ClapTrap Constructor called" << std::endl;
    this->Name = _name;
    this->hit_p = 10;
    this->energy_p = 10;
    this->damage = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        std::cout << "ClapTrap assignment operator called" << std::endl;
        this->Name = other.Name;
        this->hit_p = other.hit_p;
        this->energy_p = other.energy_p;
        this->damage = other.damage;
    }
    return (*this);
}

void    ClapTrap::attack(const std::string &target)
{
    if (this->energy_p  > 0)
    {
        std::cout << "ClapTrap " << this->Name << " attacks " << target;
        std::cout << ", causing " << this->damage << " points of damage!" << std::endl;
        this->energy_p--;
    }
    else
        std::cout << "ClapTrap: You don't have enough Energy!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_p > 0)
    {
        this->hit_p = this->hit_p - amount;
        if (this->hit_p <= 0)
            std::cout << this->Name << " died \n";
        else
            std::cout << this->Name << " took " << amount << " of damage \n";
    }
    else
        std::cout << this->Name << " is dead already \n";
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energy_p <= 0)
        std::cout << "You don't have enough Energy!" << std::endl;
    else if (this->hit_p <= 0)
        std::cout << this->Name << " is dead :( \n";
    else
    {
        this->hit_p = this->hit_p + amount;
        std::cout << this->Name << " healed " << amount << std::endl;
        this->energy_p--;
    }
}