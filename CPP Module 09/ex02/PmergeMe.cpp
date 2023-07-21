/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:21:46 by nloutfi           #+#    #+#             */
/*   Updated: 2023/07/21 02:46:35 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int mystoi(std::string str)
{
    int num;
    std::stringstream ss(str);
    ss >> num;
    return (num);
}

void check_dup(int ac, char **av)
{
    std::vector<int> v;
    for (int i = 1; i < ac; i++)
    {
        std::string str = av[i];
        int num = mystoi(str);
        if (std::find(v.begin(), v.end(), num) != v.end())
        {
            std::cout << "Duplicate argument" << std::endl;
            exit(1);
        }
        v.push_back(num);
    }
}

void check_args(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        std::string str = av[i];
        for (unsigned long j = 0; j < str.size(); j++)
        {
            if (j == 0 && (str[j] == '-' || str[j] == '+'))
                continue;
            if (!std::isdigit(str[j]))
            {
                std::cout << "Invalid argument" << std::endl;
                exit(1);
            }
        }
    }
    check_dup(ac, av);
}

// Vector functions

void fill_vector(std::vector<int> &v, int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        std::string str = av[i];
        int num = std::stoi(str);
        v.push_back(num);
    }
}

void merge_sort(std::vector<int> &v)
{
    if (v.size() <= 1)
        return;
    std::vector<int> left;
    std::vector<int> right;
    int middle = (int)v.size() / 2;
    for (int i = 0; i < middle; i++)
        left.push_back(v[i]);
    for (int i = middle; i < (int)v.size(); i++)
        right.push_back(v[i]);
    merge_sort(left);
    merge_sort(right);
    merge(v, left, right);
}

void merge(std::vector<int> &v, std::vector<int> &left, std::vector<int> &right)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < (int)left.size() && j < (int)right.size())
    {
        if (left[i] < right[j])
            v[k++] = left[i++];
        else
            v[k++] = right[j++];
    }
    while (i < (int)left.size())
        v[k++] = left[i++];
    while (j < (int)right.size())
        v[k++] = right[j++];
}

// List functions
void fill_list(std::list<int> &l, int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        std::string str = av[i];
        int num = mystoi(str);
        l.push_back(num);
    }
}

void merge_sort(std::list<int> &l)
{
    if (l.size() <= 1)
        return;
    std::list<int> left;
    std::list<int> right;
    int middle = (int)l.size() / 2;
    int i = 0;
    while (i < middle)
    {
        left.push_back(l.front());
        l.pop_front();
        i++;
    }
    while (l.size())
    {
        right.push_back(l.front());
        l.pop_front();
    }
    // std::cout << "size: " << l.size() << std::endl;
    // std::cout << "left: ";
    // print_container(left);
    // std::cout << std::endl << "right: ";
    // print_container(right);
    merge_sort(left);
    merge_sort(right);
    merge(l, left, right);
}

void merge(std::list<int> &l, std::list<int> &left, std::list<int> &right)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < (int)left.size() && j < (int)right.size())
    {
        if (left.front() < right.front())
        {
            l.push_back(left.front());
            left.pop_front();
        }
        else
        {
            l.push_back(right.front());
            right.pop_front();
        }
        k++;
    }
    while (i < (int)left.size())
    {
        l.push_back(left.front());
        left.pop_front();
        k++;
    }
    while (j < (int)right.size())
    {
        l.push_back(right.front());
        right.pop_front();
        k++;
    }
}

