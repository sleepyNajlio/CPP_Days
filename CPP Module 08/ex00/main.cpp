/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 05:42:18 by nloutfi           #+#    #+#             */
/*   Updated: 2023/07/13 05:42:35 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    try
    {
        std::cout << easyfind(v, 2) << std::endl;
        std::cout << easyfind(v, 4) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Not found" << std::endl;
    }
    return 0;
}