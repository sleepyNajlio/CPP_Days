/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 04:28:54 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/16 05:30:56 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w) : name(name), weapon_a(w)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << this->weapon_a.get_type() << std::endl;
}