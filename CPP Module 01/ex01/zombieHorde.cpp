/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:34:32 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/16 00:25:59 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N <= 0)
        return NULL;
    Zombie* Z_horde = new Zombie[N];
    
    for(int i = 0; i < N; i++)
    {
        Z_horde[i].set_name(name);
    }
    return (Z_horde);
}