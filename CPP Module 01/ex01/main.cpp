/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:42:13 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/16 00:33:17 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <limits>

int main()
{
    Zombie *z_h;
    
    z_h = zombieHorde(10, "harry");
    if (!z_h)
        return 0;
    for (int i = 0; i < 10; i++)
        z_h[i].announce();
    delete[] z_h;
    return 0;
}