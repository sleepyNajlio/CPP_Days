/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 01:19:59 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/22 19:04:10 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap frag("ezio");
    FragTrap fr(frag);
    FragTrap f("desmond");

    fr = f;
    fr.highFiveGuys();
    frag.attack("desmond");
    frag.takeDamage(70);
    frag.beRepaired(10);
    frag.takeDamage(50);
    frag.beRepaired(10);
    fr.takeDamage(100);
    
    return 0;
}