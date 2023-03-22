/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:15:32 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/22 18:59:11 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
    std::cout << "FragTrap Constructor called" << std::endl;
    this->hit_p = 100;
    this->energy_p = 100;
    this->damage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator = (const FragTrap &other)
{
    if (this != &other)
    {
        std::cout << "FragTrap assignment called" << std::endl;
        this->Name = other.Name;
        this->hit_p = other.hit_p;
        this->energy_p = other.energy_p;
        this->damage = other.damage;
    }
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFiveGuys()
{
    std::cout << "Give me a High Five ^_^ " << std::endl;
}