/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 01:19:59 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/22 04:52:06 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    // ClapTrap c;
    ScavTrap scav("akali");
    
    scav.attack("annie");
    scav.beRepaired(10);
    scav.guardGate();
    scav.takeDamage(100);
    scav.beRepaired(100);
    scav.takeDamage(10);
    
    return 0;
}