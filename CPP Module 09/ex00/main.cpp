/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 03:11:30 by nloutfi           #+#    #+#             */
/*   Updated: 2023/07/16 06:13:23 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << av[0] << ": wrong number of arguments" << std::endl;
        return (1);
    }
    std::ifstream infile(av[1]);
    if (!infile.is_open())
    {
        std::cout << av[0] << ": cannot open file" << std::endl;
        return (1);
    }
    BitcoinExchange btc;
    btc.exchange(infile);
    
}
