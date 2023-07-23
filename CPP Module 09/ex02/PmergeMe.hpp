/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:21:35 by nloutfi           #+#    #+#             */
/*   Updated: 2023/07/23 01:33:46 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>


void check_args(int ac, char **av);
void check_dup(int ac, char **av);
int mystoi(std::string str);

// Vector functions
void fill_vector(std::vector<int> &v, int ac, char **av);
void  mergeInsertionSort(std::vector<int> &v);
void merge(std::vector<int> &v, std::vector<int> &left, std::vector<int> &right);

// List functions
void fill_list(std::list<int> &l, int ac, char **av);
void  mergeInsertionSort(std::list<int> &l);
void merge(std::list<int> &l, std::list<int> &left, std::list<int> &right);

template <typename T>
void print_container(T &container)
{
    typename T::iterator it = container.begin();
    typename T::iterator ite = container.end();
    while (it != ite)
    {
        std::cout << *it;
        it++;
        if (it != ite)
            std::cout << " ";
    }
    std::cout << std::endl;
}

