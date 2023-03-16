/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 05:16:59 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/16 05:56:15 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : b_name(name), weapon_b(NULL)
{
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &w_b)
{
	this->weapon_b = &w_b;
}

void HumanB::attack()
{
	
	std::cout << this->b_name;
	std::cout << " attacks with their ";
	if (weapon_b == NULL)
		std::cout << "invisible weapon" << std::endl;
	else
		std::cout << this->weapon_b->get_type() << std::endl;
}

