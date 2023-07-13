/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 06:48:00 by nloutfi           #+#    #+#             */
/*   Updated: 2023/07/13 07:35:49 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(MutantStack const & src) : std::stack<T>(src) {}
        virtual ~MutantStack() {}
        MutantStack & operator=(MutantStack const & rhs) { std::stack<T>::operator=(rhs); return *this; }

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin() { return std::stack<T>::c.begin(); }
        iterator end() { return std::stack<T>::c.end(); }
};