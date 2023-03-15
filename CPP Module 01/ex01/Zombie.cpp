/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:09:03 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/16 00:07:18 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "default constructor called" << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << this->name << " constructed" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->name << " destroyed" << std::endl;
}

void    Zombie::announce()
{
    std::cout << this->name << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::set_name(std::string name)
{
    this->name = name;
}