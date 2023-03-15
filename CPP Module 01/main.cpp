/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 03:43:29 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/15 23:30:29 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie z1("mok");
    Zombie* z2 = newZombie("hanna");
    
    z1.announce();
    z2->announce();
    randomChump("najlio");
    delete z2;
    return 0;
}