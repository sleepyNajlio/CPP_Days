/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 01:19:59 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/22 01:36:37 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    // ClapTrap c;
    ClapTrap war("maximus");
    
    war.attack("commodus");
    war.attack("commodus");
    war.attack("commodus");
    war.attack("commodus");
    war.attack("commodus");
    war.beRepaired(10);
    war.beRepaired(10);
    war.beRepaired(10);
    war.beRepaired(10);
    war.beRepaired(10);
    war.beRepaired(10);
    // war.takeDamage(10);
    // war.takeDamage(10);
    // war.takeDamage(10);
    war.beRepaired(10);
}