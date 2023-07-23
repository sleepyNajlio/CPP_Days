/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:42:37 by nloutfi           #+#    #+#             */
/*   Updated: 2023/07/23 01:53:31 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "usage: ./a.out number1 number2 number3..." << std::endl;
        return (1);
    }
    check_args(ac, av);

    // vector version
    std::vector<int> v;
    fill_vector(v, ac, av);
    std::cout << "Before: ";
    print_container(v);    
    clock_t start = clock();
    mergeInsertionSort(v);
    clock_t end = clock();
    double time_spent_v = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    
    // list version
    std::list<int> l;
    fill_list(l, ac, av);
    std::cout << std::endl;
    start = clock();
    mergeInsertionSort(l);
    end = clock();
    double time_spent_l = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "After: ";
    print_container(l);
    std::cout << "Time to process a range of " << (int)v.size() << " elements with std::vector : " << time_spent_v << " us" << std::endl;
    std::cout << "Time to process a range of " << (int)v.size() << " elements with std::list : " << time_spent_l << " us" << std::endl;
    return (0);
}